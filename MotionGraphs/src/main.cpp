#ifdef _WIN32 || _WIN64 // windows glad.h order is different?
    #include <GLFW/glfw3.h>
    #include <glad/glad.h>
#else
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <learnopengl/Camera.h> // custom camera.h
#include <learnopengl/shader.h>
#ifdef _WIN32 || _WIN64
	#include <learnopengl/Model.h>
#else
	#include <learnopengl/model.h>
#endif
#include <learnopengl/filesystem.h>

#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits>
#include <thread>
#include <future>
// Dear ImGui static library
#include "../includes/imgui/imgui.h"
#include "../includes/imgui/imgui_impl_glfw.h"
#include "../includes/imgui/imgui_impl_opengl3.h"

#include "../headers/CubeCore.h"
#include "../headers/Skeleton.h"
#include "../headers/Animation.h"
#include "../headers/Bone.h"
#include "../headers/PointLight.h"
#include "../headers/PointCloud.h"
#include "../headers/Gui.h"
#include "../headers/blending.h"

#define ROOT_DIR FileSystem::getRoot()

#define FPS 120
// settings
struct screen_size {
	unsigned int width = 1600, height = 1000;
	unsigned int posX = 0, posY = 0;
} init_window, curr_window, fullscreen_window, region_a, region_b;

// states (feature on off)
struct controls {
    // Flags
    bool play = false;
	bool exit=false;
    bool is_full_screen = true;
	bool split_screen = true;
    bool lock_view = false;
    bool show_cloud = false;

    bool show_selected_frames = false;

    bool mouse_btn2_pressed = false;

	bool update_texture = false;

	bool compute_running = false;

	// COntrols
	int current_frame_a = 1, current_frame_b = 1, current_frame_r = 1;
	float speed = 1.f;
} states;

// timing
struct times {
    float delta_time = 0.0f;	// time between current frame and last frame
    float last_frame = 0.0f;
    long num_frames = 0;
    float agg_fps, agg_anim, agg_input, agg_render = 0.f; // for benchmarking

	float dt_update = 0.0f; // for updating animation
} timings;

// INPUT CALLBACKS
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_movement(GLFWwindow* window, double xpos, double ypos);
void mouse_scroll(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void keyboardInput(GLFWwindow *window);

// IMGUI
map<string, vector<string>> get_dirs_files(string root);

// CUSTOM
Animation* get_anim(string amc);

void update(Animation* anim, int *current_frame, int selected_frame);

void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, 
		screen_size window_region, vector<PointCloud*> PC);

pair<vector<float>, pair<float,float>> get_distance_matrix();


// Camera
Camera camera(glm::vec3(0.0f, 1.4f, 2.f));
float lastX = init_window.width / 2.0f;
float lastY = init_window.height / 2.0f;
bool firstMouse = true;

// Lights
PointLight lamp = PointLight();


float scale = 0.056444f; //inches to meters

int skip_frame = 1;
int k = 40;
float progress = 0;

// Animation & skeleton
string res_path = ROOT_DIR + "/resources/";
string file_asf = res_path + "mocap/02/02.asf";
string file_amc = res_path + "mocap/02/02_0";
//string file_asf = res_path + "mocap/14/14.asf";
//string file_amc = res_path + "mocap/14/14_0";
map<string, Animation*> anim_cache;

// Loading mocap data: skeleton from .asf and animation (poses) from .amc
Skeleton* sk = new Skeleton((char*)file_asf.c_str(), scale);
string anim_a = (file_amc + "3.amc");
string anim_b = (file_amc + "1.amc");
vector<PointCloud*> PCs_a;
vector<PointCloud*> PCs_b;

int main()
{
	/* Just trying some code in debug */
	// #ifdef DEBUG
	// get_distance_matrix();
	// get_anim(anim_a);
	// get_anim(anim_b);
	// mograph::MotionGraph* motion_graph = new mograph::MotionGraph(anim_cache, sk, k, &progress);
	// Animation* anim_r = motion_graph->get_current_motion();
	// #endif
	/** GLFW initialization **/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const char* glsl_version = "#version 330";
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif

	/** GLFW window **/
	GLFWvidmode *primary_mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	fullscreen_window.width = primary_mode->width; 
	fullscreen_window.height = primary_mode-> height;
	curr_window.width = fullscreen_window.width;
	curr_window.height = fullscreen_window.height;
	init_window = curr_window;
	cout << "Screen size: " << fullscreen_window.width << "x" << fullscreen_window.height << endl;
	cout << "Init window size: " << init_window.width << "x" << init_window.height << endl;
	region_a.width = curr_window.width / 2;
	region_a.height = curr_window.height;
	region_b.width = curr_window.width / 2;
	region_b.height = curr_window.height;
	region_b.posX = curr_window.width/2;

	GLFWwindow* window = glfwCreateWindow(curr_window.width, curr_window.height, "Mocap", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetScrollCallback(window, mouse_scroll);
	glfwSetCursorPosCallback(window, mouse_movement);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/** GLFW capture mouse **/
	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	/** GLAD: loads the correct opengl functions **/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Disable v-sync
	glfwSwapInterval(0);

	/** configure global opengl state **/
	glEnable(GL_DEPTH_TEST);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'misc/fonts/README.txt' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    // io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("../resources/fonts/Cousine-Regular.ttf", 20.0f);
	io.Fonts->AddFontFromFileTTF("../resources/fonts/Cousine-Regular.ttf", 26.0f);
    io.Fonts->AddFontFromFileTTF("../resources/fonts/Roboto-Medium.ttf", 32.0f);
    io.Fonts->AddFontFromFileTTF("../resources/fonts/DroidSans.ttf", 32.0f);
    io.Fonts->AddFontFromFileTTF("../resources/fonts/ProggyTiny.ttf", 20.0f);
	
	/** build and compile shaders + load .obj 3D models**/
#ifdef _WIN32 || _WIN64
	Shader diffShader("shaders/basic_lighting.vs", "shaders/basic_lighting.fs");
	Shader lampShader("shaders/lamp.vs", "shaders/lamp.fs");
	//string r = (string)ROOT_DIR;
//      Model sphere(r.append("\\res\\sphere\\sphere.obj"));
//      Model cylinder(r.append("\\res\\cylinder\\cylinder.obj"));
//      Model plane(r.append("\\res\\plane\\plane.obj"));
//      Model monkey(r.append("\\res\\monkey\\monkey.obj"));
#else
	Shader diffShader((ROOT_DIR + "/shaders/basic_lighting.vs").c_str(), (ROOT_DIR + "/shaders/basic_lighting.fs").c_str());
	Shader lampShader((ROOT_DIR + "/shaders/lamp.vs").c_str(), (ROOT_DIR + "/shaders/lamp.fs").c_str());
	Shader screenShader((ROOT_DIR + "/shaders/screen.vs").c_str(), (ROOT_DIR + "/shaders/screen.fs").c_str());
	Shader basicShader((ROOT_DIR + "/shaders/basic.vs").c_str(), (ROOT_DIR + "/shaders/basic.fs").c_str());
#endif
	Model sphere(FileSystem::getPath("resources/objects/sphere/sphere.obj"));
	Model cylinder(FileSystem::getPath("resources/objects/cylinder/cylinder.obj"));
	Model plane(FileSystem::getPath("resources/objects/plane/plane.obj"));
	Model monkey(FileSystem::getPath("resources/objects/monkey/monkey.obj"));
	CubeCore cube = CubeCore();

	float quadVer[] = {
		//pos 	//texcord
		-1.0f, 	1.0f, 0.0, 1.0f,
		-1.0f, -1.0f, 0.0, 0.0f,
		 1.0f, -1.0f, 1.0, 0.0f,

		-1.0f,  1.0f, 0.0, 1.0f,
		 1.0f, -1.0f, 1.0, 0.0f,
		 1.0f,  1.0f, 1.0, 1.0f,
	};
	// screen quad VAO
    unsigned int quadVAO, quadVBO;
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVer), &quadVer, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

	// Lights buffers
	lamp.setBuffers();

	// Add first anim to cache 
	get_anim(anim_a);
	get_anim(anim_b);
	cube.setBuffers();

	// Set shader to use
	diffShader.use();

	screenShader.use();
    screenShader.setInt("screenTexture", 0);

    // framebuffer configuration
    // -------------------------
    unsigned int framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	// create the framebuffer for plotting
	unsigned int framebufferPlot;
    glGenFramebuffers(1, &framebufferPlot);

    // create a color attachment texture
    unsigned int textureMainBuffer;
    glGenTextures(1, &textureMainBuffer);
    glBindTexture(GL_TEXTURE_2D, textureMainBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, curr_window.width, curr_window.height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureMainBuffer, 0);
    // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, curr_window.width, curr_window.height); // use a single renderbuffer object for both a depth AND stencil buffer.
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); // now actually attach it
    // now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

	
    // Vars
    static pair<int,int> selected_frames = {0,0};
	static pair<int, int> min_dist_frames = {2,2};
	static pair<float, float> dist_mat_range = {-1,-1};
    static vector<float> dist_mat;
    future<pair<vector<float>, pair<float,float>>> ftr;
	map<string, vector<string>> dir_files = get_dirs_files(res_path + "mocap/");
	Animation* anim_r = NULL;
	mograph::MotionGraph* motion_graph = NULL; 


	/** render loop **/
	while (!glfwWindowShouldClose(window) && !states.exit)
	{
		// frame time
		timings.num_frames++;
		float currentFrame = glfwGetTime();
		timings.delta_time = currentFrame - timings.last_frame;
		timings.last_frame = currentFrame;
		float last_fps = 1.f / timings.delta_time;
		timings.agg_fps += last_fps;

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        ImGui::Begin("Vis");

		ImGui::PushStyleColor(ImGuiCol_Button, !states.compute_running ? GUI::color_green : GUI::color_red);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, !states.compute_running ? GUI::color_green_h : GUI::color_red_h);
		if (ImGui::Button("Compute distance matrix") && !states.compute_running) {
			ftr = std::async(get_distance_matrix);
			states.compute_running = true;
			states.show_selected_frames=false;
		}
		ImGui::PopStyleColor(2);
		ImGui::Text("\t\t");
		if (ImGui::Button("BLEND") ) {
			anim_r = blending::blend_anim(get_anim(anim_a), get_anim(anim_b), states.current_frame_a, states.current_frame_b, k);
		}
		// Only tries to retrieve the return value of the thread compute, if it is has started.
		if (states.compute_running) {
			auto status = ftr.wait_for(0ms);
			if(status == std::future_status::ready){
				if (ftr.valid()) {
					pair<vector<float>, pair<float, float>> dist_mat_res = ftr.get();
					dist_mat = dist_mat_res.first;
					dist_mat_range = dist_mat_res.second;
					// cout << "dist_mat_res.first.size() = " << dist_mat_res.first.size() << endl;
					states.compute_running = false;
						states.update_texture = true;
				}
			}
		}
		ImGui::Text("range distance %.3f to %.3f", dist_mat_range.first, dist_mat_range.second);

		ImGui::ProgressBar(progress >= 0.98 ? 1.0f : progress, ImVec2(0.0f,0.0f));
		int anim_a_size = get_anim(anim_a)->getNumberOfFrames();
		int anim_b_size = get_anim(anim_b)->getNumberOfFrames();
        GUI::showDistanceMatrix(anim_a_size, anim_b_size, dist_mat, selected_frames, &states.show_selected_frames, &states.update_texture);
        ImGui::Separator();
		ImGui::ShowMetricsWindow();
		if (ImGui::Button("Compute motion graph")) {
			motion_graph = new mograph::MotionGraph(anim_cache, sk, k, &progress);
			anim_r = motion_graph->get_current_motion();
		}
		GUI::showGraphWindow(NULL);
		
		GUI::showBasicControls(&states.play, &states.split_screen, &states.exit, &anim_a, &anim_b, &states.current_frame_a, &states.current_frame_b, &states.current_frame_r, 
			anim_a_size, anim_b_size, &states.speed, dir_files, res_path + "mocap/");

        ImGui::End(); //last END

		// input
		// -----
		float input_start_time = glfwGetTime();
		keyboardInput(window);
		float input_time = (glfwGetTime() - input_start_time);
		timings.agg_input += input_time;


		// Rendering
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

		timings.dt_update += timings.delta_time;
		if (states.split_screen) {
			glViewport(region_a.posX, region_a.posY, region_a.width, region_a.height);
			// Update motion A and render
			update(get_anim(anim_a), &states.current_frame_a, selected_frames.first);
			draw(plane, sphere, cylinder, cube, diffShader, lampShader, region_a, PCs_a);
			
			// Update motion B and render
			glViewport(region_b.posX, region_b.posY, region_b.width, region_b.height);
			update(get_anim(anim_b), &states.current_frame_b, selected_frames.second);
			draw(plane, sphere, cylinder, cube, diffShader, lampShader, region_b, PCs_b);
		}
		else if (motion_graph != NULL) {
			glViewport(curr_window.posX, curr_window.posY, curr_window.width, curr_window.height);
			if (anim_r->getCurrentFrame() + 1 >= anim_r->getNumberOfFrames()) {
				update(anim_r, &states.current_frame_r, 1);
				motion_graph->move_to_next();
				anim_r = motion_graph->get_current_motion();
			} else 
				update(anim_r, &states.current_frame_r, 1);
			cout << "update, frame = " << states.current_frame_r << endl;
			draw(plane, sphere, cylinder, cube, diffShader, lampShader, curr_window, PCs_a);
		}
		else { 
			// Show only the result of the blending
			glViewport(curr_window.posX, curr_window.posY, curr_window.width, curr_window.height);
			update(anim_r, &states.current_frame_r, 1);
			draw(plane, sphere, cylinder, cube, diffShader, lampShader, curr_window, PCs_a);
		}

		 // now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
        // clear all relevant buffers
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessery actually, since we won't be able to see behind the quad anyways)
        glClear(GL_COLOR_BUFFER_BIT);
		glViewport(fullscreen_window.posX, fullscreen_window.posY, fullscreen_window.width, fullscreen_window.height);

        screenShader.use();
        glBindVertexArray(quadVAO);
        glBindTexture(GL_TEXTURE_2D, textureMainBuffer);	// use the color attachment texture as the texture of the quad plane
        glDrawArrays(GL_TRIANGLES, 0, 6);
		{
			ImGui::Begin("CACCA");
			static unsigned int texturePlotBuffer;
			
			static bool show = false;
			static float off_x = 0.f;
			static float off_y = 0.f;
			static float scale = 1.f;
			show = true;
			if(ImGui::Button("Update")) {
				glBindFramebuffer(GL_FRAMEBUFFER, framebufferPlot);
				
				glGenTextures(1, &texturePlotBuffer);
				glBindTexture(GL_TEXTURE_2D, texturePlotBuffer);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fullscreen_window.width, fullscreen_window.height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texturePlotBuffer, 0);

        		glDisable(GL_DEPTH_TEST);
				// 2D texture for drawing the graph
				glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

    			glViewport(fullscreen_window.posX, fullscreen_window.posY, fullscreen_window.width, fullscreen_window.height);

				basicShader.use();
				basicShader.setVec3("objectColor", .05f, 0.95f, 0.95f);
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(off_x, off_y, 0));
				model = glm::scale(model, glm::vec3(scale, scale , scale));
				basicShader.setMat4("model", model);
				// pass projection matrix to shader (note that in this case it could change every frame)
				glm::mat4 projection = glm::ortho(0.0f, (float)fullscreen_window.width, 0.0f, (float)fullscreen_window.height, 0.0f, 1000000.f);
				diffShader.setMat4("projection", projection);

				cube.setBuffers();
				glDrawArrays(GL_TRIANGLES, 0, 36);

				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}
			if (show) {
				ImTextureID my_tex_id = (void*)(intptr_t)texturePlotBuffer;
				static float zoom = 0.5f;
				ImGui::SliderFloat("Zoom", &zoom, 0.1f, 5.0f);
				ImGui::SliderFloat("Scale", &scale, 1.f, 10000.0f);
				ImGui::SliderFloat("translate x", &off_x, 0.f, (float)fullscreen_window.width);
				ImGui::SliderFloat("translate y", &off_y, 0.f, (float)fullscreen_window.height);
				ImGui::Image(my_tex_id, ImVec2(curr_window.width*zoom, curr_window.height*zoom), 
				ImVec2(0,0), ImVec2(1,-1));				
			}

			ImGui::End();
		}

		if (timings.dt_update >= states.speed) timings.dt_update = 0.f;
		// End Rendering

		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		//-------------------------------------------------------------------------------
		glfwPollEvents();
        glViewport(curr_window.posX, curr_window.posY, curr_window.width, curr_window.height);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		// wait for sync
		while (glfwGetTime() - currentFrame < 1.f / FPS) { ; }
	}

	// de-allocation
	cube.~CubeCore();
	delete sk;
	for (auto anim: anim_cache) {delete anim.second;};
	delete anim_r;
	

	// end glfw and ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
	return 0;
}

void update(Animation* anim, int *current_frame, int selected_frame)
{
	if (states.compute_running || anim == NULL) 
		return;

	// Update animation 
	if (states.show_selected_frames){
		states.play = false;
		*current_frame = selected_frame;
	}

	// delta time for smooth update at variable speeds
	// float dt = timings.dt_update*states.speed;
	
	// ImGui::Text("Dt = %f", dt);
	// Pose dt_pose = *blending::blend_pose(anim->getPoseAt(*current_frame), anim->getPoseAt(*current_frame+1), dt);
	// sk->apply_pose(&dt_pose);
	sk->apply_pose(anim->getPoseAt(*current_frame));

	if (states.play)
	{
		// for (int i = 0; i < skip_frame; i++) {
			// *current_frame = dt >= 0.99f ? 1 : 0;

		// }
		*current_frame += 1;
	}

	if (anim->isOver()) {
		anim->reset();
		sk->resetAll();
		*current_frame = 1;
	}
}

void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, 
		screen_size window_region, vector<PointCloud*> PC)
{
	/** Start Rendering **/
	float render_start_time = glfwGetTime();

	// activate shader
	diffShader.use();
	diffShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
	diffShader.setVec3("lightPos", lamp.Position);
	diffShader.setVec3("viewPos", camera.Position);

	// pass projection matrix to shader (note that in this case it could change every frame)
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)window_region.width / (float)window_region.height, 0.1f, 100.0f);
	diffShader.setMat4("projection", projection);

	// camera/view transformation
	if (states.lock_view) {
		diffShader.setMat4("view", glm::lookAt(camera.Position, sk->getPos(), camera.Up));
	}
	else {
		diffShader.setMat4("view", camera.GetViewMatrix());
	}

	// floor
	diffShader.setVec3("objectColor", .95f, 0.95f, 0.95f);
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(50.f, 0.001f, 50.f));
	diffShader.setMat4("model", model);
	//glBindVertexArray(cube.VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	plane.Draw(diffShader);


	// render Skeleton, root first
	float render_scale = .02f;
	model = glm::scale(sk->getJointMat(), glm::vec3(render_scale));
	diffShader.setVec3("objectColor", 1.0f, 0.1f, 0.1f);
	diffShader.setMat4("model", model);
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	sphere.Draw(diffShader);

	for (Bone* bone : sk->getAllBones())
	{
		diffShader.setVec3("objectColor", 0.31f, 1.f, 0.31f);

		bool highlight = !strcmp(bone->name.c_str(), "rtibia") || !strcmp(bone->name.c_str(), "ltibia")
			|| !strcmp(bone->name.c_str(), "rradius") || !strcmp(bone->name.c_str(), "lradius")
			|| !strcmp(bone->name.c_str(), "rclavicle") || !strcmp(bone->name.c_str(), "lclavicle")
			//|| !strcmp(bone->name.c_str(), "rhumerus") || !strcmp(bone->name.c_str(), "lhumerus")
		|| !strcmp(bone->name.c_str(), "lowerback");
		if (highlight) {
			diffShader.setVec3("objectColor", 0.31f, 0.31f, 1.f);
		}
		// calculate the model matrix for each object and pass it to shader before drawing
		model = glm::scale(bone->getJointMat(), glm::vec3(render_scale));
		diffShader.setMat4("model", model);
		sphere.Draw(diffShader);

		// Draw segment
		diffShader.setVec3("objectColor", .6f, 0.6f, 0.6f);
		if (highlight) {
			diffShader.setVec3("objectColor", 0.31f, 0.31f, .6f);
		}
		model = glm::scale(bone->getSegMat(), glm::vec3(render_scale));
		diffShader.setMat4("model", model);
		cylinder.Draw(diffShader);

		//Cloud point guideline
		/*diffShader.setVec3("objectColor", 0.41f, 0.41f, .6f);
		model = glm::scale(bone->cp_planez, glm::vec3(render_scale));
		diffShader.setMat4("model", bone->cp_planez);
		glBindVertexArray(cube.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		diffShader.setVec3("objectColor", 6.0f, 0.41f, 0.41f);
		model = glm::scale(bone->cp_planex, glm::vec3(render_scale));
		diffShader.setMat4("model", bone->cp_planex);
		glBindVertexArray(cube.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);*/

		//Cloud points
		// if (states.show_cloud && PC.size() > frame) 
		// {
		// 	PointCloud* w_pc = PC[frame]; // window frame
		// 	diffShader.setVec3("objectColor", .8f, 0.8f, 0.8f);
		// 	for (auto p : w_pc->points) {
		// 		model = glm::scale(bone->getLocalPointCloud()->getPointMat(p), glm::vec3(0.01f));
		// 		diffShader.setMat4("model", model);
		// 		// sphere.Draw(diffShader);
		// 		glBindVertexArray(cube.VAO);
		// 		glDrawArrays(GL_TRIANGLES, 0, 36);
		// 	}
		// }			
	}

	// Draw Lights
	lampShader.use();
	lampShader.setMat4("projection", projection);
	lampShader.setMat4("view", camera.GetViewMatrix());
	model = glm::mat4(1.0f);
	model = glm::translate(model, lamp.Position);
	model = glm::scale(model, glm::vec3(0.1f)); // a smaller cube
	lampShader.setMat4("model", model);

	glBindVertexArray(lamp.VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	float render_time = glfwGetTime() - render_start_time;
	timings.agg_render += render_time;
	/** END RENDERING **/
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void keyboardInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		cout << endl << "==========\tPerformance report:\t==========" << endl << endl;
		cout << "\tAVG FPS: " << timings.agg_fps / timings.num_frames << endl;
		cout << "\tAVG anim update time = " << timings.agg_anim / timings.num_frames * 1000.f << endl;
		cout << "\tAVG input time = " << timings.agg_input / timings.num_frames * 1000.f << endl;
		cout << "\tAVG render time = " << timings.agg_render / timings.num_frames * 1000.f << endl;
		cout << endl << "==================================================" << endl;
		cout << timings.agg_fps / timings.num_frames << endl
			<< timings.agg_anim / timings.num_frames * 1000.f << endl
			<< timings.agg_input / timings.num_frames * 1000.f << endl
			<< timings.agg_render / timings.num_frames * 1000.f << endl;
		cout << endl << "lamp pos = " << lamp.Position.x << ", " << lamp.Position.y <<
			", " << lamp.Position.z;
		glfwSetWindowShouldClose(window, true);
	}

	// TOGGLE: Play button
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		states.play = !states.play;
		std::cout << "Play" << "\n";
	}
	// TOGGLE: Fullscreen
	if ((glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS))
	{
		states.is_full_screen = !states.is_full_screen;
		if (states.is_full_screen) {
			glfwSetWindowSize(window, fullscreen_window.width, fullscreen_window.height);
			// upper left corner
			glfwSetWindowPos(window, 0, 0);
			curr_window.width = fullscreen_window.width;
			curr_window.height = fullscreen_window.height;
		}
		else {
			glfwSetWindowSize(window, init_window.width, init_window.height);
			glfwSetWindowPos(window, 0, 0);
			curr_window.width = init_window.width;
			curr_window.height = init_window.height;
		}
		region_a.width = curr_window.width / 2;
		region_a.height = curr_window.height;
		region_b.width = curr_window.width / 2;
		region_b.height = curr_window.height;
		region_b.posX = curr_window.width/2;
		glViewport(0, 0, curr_window.width, curr_window.height);
	}
	// TOGGLE: lock view
	if ((glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS))
		states.lock_view = !states.lock_view;
	// TOGGLE: show cloud point
	if ((glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS))
		states.show_cloud = !states.show_cloud;

	// WASD movement
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, timings.delta_time);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, timings.delta_time);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, timings.delta_time);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, timings.delta_time);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, timings.delta_time);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, timings.delta_time);

	// Lights control
	float light_offset = 1.f;
	if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS)
		lamp.Position += glm::vec3(0.f, light_offset, 0.f);
	if (glfwGetKey(window, GLFW_KEY_KP_5) == GLFW_PRESS)
		lamp.Position += glm::vec3(0.f, -light_offset, 0.f);
	if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
		lamp.Position += glm::vec3(-light_offset, 0.f, 0.f);
	if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
		lamp.Position += glm::vec3(light_offset, 0.f, 0.f);
	if (glfwGetKey(window, GLFW_KEY_KP_7) == GLFW_PRESS)
		lamp.Position += glm::vec3(0.f, 0.f, -light_offset);
	if (glfwGetKey(window, GLFW_KEY_KP_9) == GLFW_PRESS)
		lamp.Position += glm::vec3(0.f, 0.f, light_offset);
}

// Get the animation from the cache, adds it if not present
Animation* get_anim(string amc)
{
	if (!anim_cache.count(amc)) // if animation is NOT in cache exits
	{
		Animation* an = new Animation(sk, (char*)(amc).c_str());
		anim_cache.insert({ amc, an }); // insert only if not present
	}
	return anim_cache[amc];
}

// glfw: called when window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
	curr_window.width = width;
	curr_window.height = height;
	region_a.width = width / 2;
	region_a.height = height;
	region_b.width = width / 2;
	region_b.height = height;
	region_b.posX = width/2;

	cout << "new width = " << width << " | region a w = " << region_a.width << ", region b w = " << region_b.width <<endl;
}


// glfw: called when mouse moves
void mouse_movement(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastY = ypos;
    lastX = xpos;
    if (states.mouse_btn2_pressed) {
        camera.ProcessMouseMovement(xoffset, yoffset);
    }
}

// glfw: called when mouse wheel is used
void mouse_scroll(GLFWwindow* window, double xoffset, double yoffset)
{
	// camera.ProcessMouseScroll(yoffset);
	// ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

// glfw: called when mouse button is used
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    // Mouse button 2 pressed == move camera
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        if (action == GLFW_PRESS)
            states.mouse_btn2_pressed = true;
        else if (action == GLFW_RELEASE)
            states.mouse_btn2_pressed = false;
    }
}


map<string, vector<string>> get_dirs_files(string root)
{
	map<string, vector<string>> res;
	vector<string> sorted_dirs = FileSystem::getDirs(root);
	std::sort(sorted_dirs.begin(), sorted_dirs.end());
	for (string dirs : sorted_dirs) {
		vector<string> sorted_files = FileSystem::getFiles(root + dirs + "/");
		std::sort(sorted_files.begin(), sorted_files.end());
		res[dirs] = sorted_files;
	}
	return res;
}


pair<vector<float>, pair<float,float>> get_distance_matrix()
{
	return blending::compute_distance_matrix(get_anim(anim_a), get_anim(anim_b), sk, k, &progress);
}