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
	bool show_window_cloud = false;
	bool disable_floor_tiles = false;

    bool show_selected_frames = false;
	bool show_bone_segment = true;
	bool show_joints = true;

	bool show_GUI = true;

	bool show_mograph_path = true;
	bool show_mograph_trav = true;

	bool lock_skeleton = false;

    bool mouse_btn2_pressed = false;

	bool update_texture = false;

	bool compute_running = false, compute_mograph = false;

	// COntrols
	bool move_character = false;
	int current_frame_a = 1, current_frame_b = 1, current_frame_r = 1;
	float speed = 1.f;
	
	float point_cloud_size = 0.005f;

	float threshold = 1000.0f;
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

void draw_skeleton(Skeleton *sk, Model sphere, Model cylinder, Shader diffShader, PointCloud* PC);
void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, 
		screen_size window_region, PointCloud* PC);
void plot_line_between_p1_p2(glm::vec3 p1, glm::vec3 p2, Model line, Shader shader, float thickness);
void plot_motion_graph(mograph::MotionGraph* graph, vector<pair<mograph::Vertex*, mograph::Edge>> graph_traversal, 
		Model quad_mesh, Model line, Shader shader, float offset_x, float offset_y, float scale);

pair<vector<float>, pair<float,float>> get_distance_matrix();
mograph::MotionGraph* get_motion_graph();


// Camera
Camera camera(glm::vec3(0.0f, 1.4f, 2.f));
float lastX = init_window.width / 2.0f;
float lastY = init_window.height / 2.0f;
bool firstMouse = true;

// Lights
PointLight lamp = PointLight();

// Floor tiles pre-computed matrices
vector<glm::mat4> tiles_mat;
int grid_size = 25;
float tile_scale = 0.5f;
float tile_offset = 2.f;


float scale = 0.056444f; //inches to meters

int skip_frame = 1;
int k = 40;
float progress = 0.f;
float progress_mograph = 0.f;

const float sk_offset_any_dir = 0.1f;
const glm::vec3 sk_offset_left = glm::vec3(13.0f, 0.0f, 0.0f);
const glm::vec3 sk_offset_right = glm::vec3(-13.0f, 0.0f, 0.0f);

// Animation & skeleton
string res_path = ROOT_DIR + "/resources/";
string file_asf = res_path + "mocap/16/16.asf";
string file_amc = res_path + "mocap/16/16_";
//string file_asf = res_path + "mocap/14/14.asf";
//string file_amc = res_path + "mocap/14/14_0";
map<string, Animation*> anim_cache;
vector<pair<string,Animation*>> anim_list;
map<string, bool> anim_list_in_graph;

// Loading mocap data: skeleton from .asf and animation (poses) from .amc
Skeleton* sk = new Skeleton((char*)file_asf.c_str(), scale);
string anim_a = (file_amc + "51.amc");
string anim_b = (file_amc + "54.amc");
PointCloud* PCs_a;
PointCloud* PCs_b;
vector<unique_ptr<Skeleton>> sk_frames;

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
	// anim_list.push_back(make_pair(anim_a, get_anim(anim_a)));
	// anim_list.push_back(make_pair(anim_b, get_anim(anim_b)));
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
	// Texture for the graph plot
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferPlot);
	unsigned int texturePlotBuffer;
	glGenTextures(1, &texturePlotBuffer);
	glBindTexture(GL_TEXTURE_2D, texturePlotBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fullscreen_window.width, fullscreen_window.height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texturePlotBuffer, 0);
    
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
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

	//Floor tile mat computation
	glm::mat4 model = glm::mat4(1.0f);
	
	model = glm::scale(model, glm::vec3(tile_scale, 1.f, tile_scale));
	model = glm::translate(model, glm::vec3(-grid_size * tile_offset / 2, 0.f, -grid_size * tile_offset / 2));
	tiles_mat.reserve(grid_size*grid_size);

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			if ((i + j) % 2 == 0) 
				diffShader.setVec3("objectColor", 1.f, 1.f, 1.f);
			else 
				diffShader.setVec3("objectColor", 0.7f, 0.7f, 0.7f);
			model = glm::translate(model, glm::vec3(tile_offset, 0.f, 0.f));
			// model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
			tiles_mat.push_back(model);
		}
		model = glm::translate(model, glm::vec3(-tile_offset*grid_size, 0.f, tile_offset));
	}

	
    // Vars
    static pair<int,int> selected_frames = {0,0};
	static pair<int, int> min_dist_frames = {2,2};
	static pair<float, float> dist_mat_range = {-1,-1};
    static vector<float> dist_mat;
    future<pair<vector<float>, pair<float,float>>> ftr;
	map<string, vector<string>> dir_files = get_dirs_files(res_path + "mocap/");
	map<string, vector<string>> dir_asf, dir_amc;
	for (auto p:dir_files) {
		for (string f:p.second) {
			// cout << f << endl;
			if (f.find(".asf") != std::string::npos)
				dir_asf[p.first].push_back(f);
			else if (f.find(".amc") != std::string::npos)
				dir_amc[p.first].push_back(f);
		}
	}
	string labeled = res_path + "mocap/" + "labeled/";
	vector<string> files_to_add = {
		labeled + "run_stop_16_08",
		labeled + "walk_16_15",
		labeled + "sneak_17_03",
		labeled + "duck_slow_127_31",
		labeled + "jump_up_down_49_03",
		labeled + "jump_one_leg_49_03",
		};
	for (string &f:files_to_add) {
		anim_list.push_back(make_pair(f + ".amc", get_anim(f + ".amc")));
	}


	future<mograph::MotionGraph*> ftr_mograph;
	Animation* anim_r = NULL;
	mograph::MotionGraph* motion_graph = NULL; 
	vector<pair<mograph::Vertex*, mograph::Edge>> graph_traversal;
	map<int, int> mograph_frame_to_edge;
	int graph_traversal_index = 0;


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
        // ImGui::ShowDemoWindow();
		
		{
			ImGui::Begin("Options");
			static string last_asf = file_asf;
			ImGui::BulletText( ("Skelton: " + file_asf.substr(file_asf.find_last_of("/"))).c_str());
			ImGui::SameLine();
			GUI::imgui_file_selector("Select skeleton", dir_asf, string(res_path + "mocap/"), &file_asf);
			if (last_asf != file_asf) {
				delete sk;
				sk = new Skeleton((char*)file_asf.c_str(), scale);
				last_asf = file_asf;
			}

			ImGui::Checkbox("Show GUI", &states.show_GUI);
			ImGui::Checkbox("Show floor tiles", &states.disable_floor_tiles);
			ImGui::Checkbox("Show pose point cloud", &states.show_cloud);
			ImGui::Checkbox("Show full point cloud", &states.show_window_cloud);
			if (states.show_cloud || states.show_window_cloud) {
				static float step = 0.001f;
				ImGui::SameLine();
				if (ImGui::ArrowButton("##CP_up_size", ImGuiDir_Up)) { states.point_cloud_size += step; }
				ImGui::SameLine();
				if (ImGui::ArrowButton("##CP_down_size", ImGuiDir_Down)) { if (states.point_cloud_size > 0) states.point_cloud_size -= step; }
			}
			ImGui::Checkbox("Show skeleton joints", &states.show_joints);
			ImGui::Checkbox("Show skeleton bone segments", &states.show_bone_segment);
			ImGui::Text("");
			ImGui::Checkbox("Move character mode (WASD)", &states.move_character);
			ImGui::Checkbox("Lock skeleton in place", &states.lock_skeleton);
			ImGui::Text("");
			ImGui::Checkbox("Show motion graph path", &states.show_mograph_path);
			ImGui::Checkbox("Show motion graph current edge", &states.show_mograph_trav);
			ImGui::End();
		}

		if (states.show_GUI)
		{
			ImGui::Begin("Visualisation");

			ImGui::Separator();
			ImGui::PushStyleColor(ImGuiCol_Button, !states.compute_running ? GUI::color_green : GUI::color_red);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, !states.compute_running ? GUI::color_green_h : GUI::color_red_h);
			if (ImGui::Button("Compute distance matrix") && !states.compute_running) {
				ftr = std::async(get_distance_matrix);
				states.compute_running = true;
				states.show_selected_frames=false;
			}
			ImGui::PopStyleColor(2);
			ImGui::SameLine();ImGui::Text("\t\t");ImGui::SameLine();

			//TODO BLEND is broken... disable for now
			if (ImGui::Button("BLEND") && false) {
				Animation* cp_a = new Animation(*get_anim(anim_a));
				Animation* cp_b = new Animation(*get_anim(anim_b));
				cp_b->normalise(cp_a->getPoseAt(states.current_frame_a), states.current_frame_b);
				vector<Pose*> pre_Ai = cp_a->getPosesInRange(0, states.current_frame_a-k-1);
				vector<Pose*> after_Bj = cp_b->getPosesInRange(states.current_frame_b+k+1, get_anim(anim_b)->getNumberOfFrames());

				Animation* blend = blending::blend_anim(cp_a, cp_b, states.current_frame_a, states.current_frame_b, k);
				vector<Pose*> blend_poses = blend->getPosesInRange(1, blend->getNumberOfFrames());
				pre_Ai.insert(pre_Ai.end(), blend_poses.begin(), blend_poses.end());
				pre_Ai.insert(pre_Ai.end(), after_Bj.begin(), after_Bj.end());
				anim_r = new Animation(pre_Ai);
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
			int anim_r_size = anim_r == NULL ? 0:anim_r->getNumberOfFrames();
			GUI::showDistanceMatrix(anim_a_size, anim_b_size, dist_mat, selected_frames, &states.show_selected_frames, &states.update_texture);
			ImGui::Separator();
			ImGui::ShowMetricsWindow();
			
			GUI::showBasicControls(&states.play, &states.split_screen, &states.exit, &anim_a, &anim_b, &states.current_frame_a, &states.current_frame_b, &states.current_frame_r, 
				anim_a_size, anim_b_size, anim_r_size, &states.speed, dir_amc, res_path + "mocap/");

			if (ImGui::TreeNode("Clone motion"))
			{
				static int skip_frames = 1;
				ImGui::PushButtonRepeat(true);
				ImGui::Text("Skip: %d frames", skip_frames);
				ImGui::SameLine();
				if (ImGui::ArrowButton("skip_frame_down", ImGuiDir_Left)) skip_frames = skip_frames > 0 ? --skip_frames : 0;
				ImGui::SameLine();
				if (ImGui::ArrowButton("skip_frame_up", ImGuiDir_Right)) ++skip_frames;

				ImGui::Text("Skeleton offset: x = %.2f, y = %.2f, z = %.2f", sk->root_offset.x, sk->root_offset.y, sk->root_offset.z);
				ImGui::SameLine();
				if (ImGui::ArrowButton("offset_left", ImGuiDir_Up)) {
					sk->root_offset += sk_offset_left;
				}
				ImGui::SameLine();
				if (ImGui::ArrowButton("off_set_right", ImGuiDir_Down)) {
					sk->root_offset += sk_offset_right;
				}
				ImGui::SameLine();
				if (ImGui::Button("Reset offset")) {
					sk->root_offset = glm::vec3(0.f);
				}

				if (ImGui::Button("Snap skeleton pose")) {
					bool play_temp = states.play;
					states.play = true;
					update(get_anim(anim_a), &states.current_frame_a, selected_frames.first);
					update(anim_r, &states.current_frame_r, 1);
					sk_frames.push_back(make_unique<Skeleton>(*sk));

					for (int i=0; i < skip_frames; i++) {
						update(get_anim(anim_a), &states.current_frame_a, selected_frames.first);
						update(anim_r, &states.current_frame_r, 1);
					}
					states.play = play_temp;
				}
				ImGui::SameLine();
				if (sk_frames.size() > 0 && ImGui::Button("Pop snap")) {
					sk_frames.pop_back();
				}
				ImGui::PopButtonRepeat();
				if (ImGui::Button("Clear Snap")) {
					sk_frames.clear();
				}
				ImGui::TreePop();
			}

			ImGui::End(); //last END

			{
				static string motion_to_add, last_motion_to_add;
				GUI::showMotionList(anim_list, dir_files, res_path + "mocap/", &motion_to_add, anim_list_in_graph);
				if (last_motion_to_add != motion_to_add) {
					anim_list.push_back(make_pair(motion_to_add, get_anim(motion_to_add)));
					last_motion_to_add = motion_to_add;
					anim_list_in_graph[motion_to_add] = false;
				}
				ImGui::Begin("Motion graph");
				ImGui::DragFloat("Threshold", &states.threshold);
				if (states.threshold < 0) states.threshold = 0.0f;
				static int e = 0;
				ImGui::RadioButton("Greedy search", &e, 0); ImGui::SameLine();
				ImGui::RadioButton("Sequential graph walk", &e, 1);

				ImGui::PushStyleColor(ImGuiCol_Button, GUI::color_red);
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, GUI::color_red_h);
				if (ImGui::Button("Compute motion graph") && !states.compute_mograph) {
					// ftr_mograph = std::async(get_motion_graph);
					// states.compute_mograph = true;
					motion_graph = new mograph::MotionGraph(anim_list, sk, k, &progress_mograph);
					if (e == 1) graph_traversal = motion_graph->traverse_sequential(anim_list, states.threshold);
					else  graph_traversal = motion_graph->traverse_min_rand(states.threshold);

					motion_graph->set_head(graph_traversal.at(graph_traversal_index));
					mograph_frame_to_edge.clear();
					if (graph_traversal.size() > 0) {
						anim_r = motion_graph->edge2anim(graph_traversal, &mograph_frame_to_edge);
					}
					states.split_screen = false;
					for (auto &a:anim_list) {
						anim_list_in_graph[a.first] = true;
					}
				}
				ImGui::PopStyleColor(2);
				ImGui::PushStyleColor(ImGuiCol_Button, GUI::color_green);
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, GUI::color_green_h);
				if (motion_graph != nullptr) {
					ImGui::SameLine();
					if (ImGui::Button("Traversal")) {
						graph_traversal_index = 0;
						graph_traversal.clear();
						switch (e)
						{
						case 1:
							graph_traversal = motion_graph->traverse_sequential(anim_list, states.threshold);
							break;
						default:
							graph_traversal = motion_graph->traverse_min_rand(states.threshold);
							break;
						}
						if (graph_traversal.size() > 0) {
							motion_graph->set_head(graph_traversal.at(graph_traversal_index));
							mograph_frame_to_edge.clear();
							anim_r = motion_graph->edge2anim(graph_traversal, &mograph_frame_to_edge);
						}
					}
				}
				if (motion_graph != NULL && ImGui::Button("Update motion graph") ) {
					ImGui::SameLine();
					motion_graph->update_motions(anim_list, sk, &progress_mograph);
					for (auto &a:anim_list) {
						anim_list_in_graph[a.first] = true;
					}
				}
				ImGui::PopStyleColor(2);

				if (motion_graph != NULL && ImGui::TreeNode("Graph metrics")) {
					mograph::metrics met = motion_graph->get_metrics();

					ImGui::Text("Distance: sum = %.2f, max = %.2f, min = %.2f,  avg = %.2f",
						met.sum, met.max, met.min, met.avg);
					ImGui::Text("\nEdge info: ");
					ImGui::Text("\t-max edges per vertex: %d", met.max_num_edges);
					ImGui::Text("\t-min edges per vertex: %d", met.min_num_edges);
					ImGui::Text("\t-avg edges per vertex: %.2f", met.avg_num_edge_per_vertex);
					ImGui::Text("Total: %d vertices and %d edges\n", met.num_vertex, met.num_tot_edges);
					ImGui::TreePop();
				}

				if (graph_traversal.size() > 0 && ImGui::TreeNode("Traversal path")) {
					float sum = 0.0f;
					int edges = 0, c = 0;
					for (auto p : graph_traversal) {
						string src = p.first->get_name().substr(p.first->get_name().find_last_of("/"));
						string tar = p.second.get_target()->get_name().substr(p.second.get_target()->get_name().find_last_of("/"));
						string str = std::to_string(c) + ") " + src + " -> " + tar + " | distance = " + std::to_string(p.second.get_weight());
						ImGui::Text(str.c_str());
						if (p.second.get_weight() != -1.f) {
							sum += p.second.get_weight();
							edges++;
						}
						c++;
					}
					ImGui::Text("Total cost: %.2f | AVG: %.2f", sum, sum/edges);
					ImGui::TreePop();
				}
				// Only tries to retrieve the return value of the thread compute, if it is has started.
				// if (states.compute_mograph) {
				// 	auto status = ftr_mograph.wait_for(0ms);
				// 	if(status == std::future_status::ready){
				// 		if (ftr_mograph.valid()) {
				// 			motion_graph = ftr_mograph.get();
				// 			anim_r = motion_graph->get_current_motion();
				// 			states.compute_mograph = false;
				// 		}
				// 	}
				// }
				// ImGui::SameLine();
				// ImGui::ProgressBar(progress_mograph >= 0.98 ? 1.0f : progress_mograph, ImVec2(0.0f,0.0f));
				static float off_x = 0.f;
				static float off_y = 0.f;
				static float scale = 2.f;
				glBindFramebuffer(GL_FRAMEBUFFER, framebufferPlot);
				glDisable(GL_DEPTH_TEST);
				// 2D texture for drawing the graph
				glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

				glViewport(fullscreen_window.posX, fullscreen_window.posY, fullscreen_window.width, fullscreen_window.height);

				plot_motion_graph(motion_graph, graph_traversal, plane, cylinder, basicShader, off_x, off_y, scale);
				ImTextureID my_tex_id = (void*)(intptr_t)texturePlotBuffer;
				static float zoom = 0.5f;
				ImGui::SliderFloat("Zoom", &zoom, 0.1f, 5.0f);
				ImGui::SliderFloat("Scale", &scale, 1.f, 10.0f);
				ImGui::DragFloat("translate x", &off_x);
				ImGui::DragFloat("translate y", &off_y);
				ImGui::Image(my_tex_id, ImVec2(curr_window.width*zoom, curr_window.height*zoom), 
				ImVec2(0,0), ImVec2(1,1));	

				ImGui::End();
			}

		}
		// End UI

		// input
		// -----
		float input_start_time = glfwGetTime();
		keyboardInput(window);
		float input_time = (glfwGetTime() - input_start_time);
		timings.agg_input += input_time;


		// Rendering
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // background
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
		else { 
			// switch the dummy to display the current edge
			if (graph_traversal.size() > 0 && motion_graph != NULL) {
				graph_traversal_index = mograph_frame_to_edge[states.current_frame_r];
				// cout << "graph index =" << graph_traversal_index << ", size() = " << graph_traversal.size() << endl;
				motion_graph->set_head(graph_traversal.at(graph_traversal_index));
			}
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

		if (timings.dt_update >= states.speed) timings.dt_update = 0.f;
		// End Rendering

		glBindFramebuffer(GL_FRAMEBUFFER, 0); // change framebuffer to default one
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

	if (states.show_window_cloud && *current_frame - k > 0 && *current_frame + k < anim->getNumberOfFrames()) {
		PCs_a = sk->getGlobalWindowPointCloud(anim->getPosesInRange(*current_frame - k, *current_frame + k));
		// PCs_a = sk->getGlobalPointCloud(anim->getPoseAt(*current_frame));
		PCs_b = PCs_a;
	}

	if (states.lock_skeleton)
		sk->apply_pose_locked(anim->getPoseAt(*current_frame));
	else	
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

void draw_skeleton(Skeleton *skeleton, Model sphere, Model cylinder, Shader diffShader, PointCloud* PC)
{
	vector<float> col_root = {1.0f, 0.1f, 0.1f};
	vector<float> col_bone = {0.6f, 0.6f, 0.6f};
	vector<float> col_bone_highlight = {0.31f, 0.31f, .6f};
	vector<float> col_joint = {0.31f, 1.f, 0.31f};
	vector<float> col_joint_highlight = {0.31f, 0.31f, 1.f};
	// if (skeleton != sk) {
	// 	vector<float> mono = {0.6f, 0.6f, 0.6f};
	// 	col_root = mono;
	// 	col_bone = mono;
	// 	col_bone_highlight = mono;
	// 	// col_joint = mono;
	// 	// col_joint_highlight = mono;
	// }
	glm::mat4 model = glm::mat4();
	// render Skeleton, root first
	float render_scale = .02f;
	model = glm::scale(skeleton->getJointMat(), glm::vec3(render_scale));
	diffShader.setVec3("objectColor", col_root.at(0), col_root.at(1), col_root.at(2));
	diffShader.setMat4("model", model);
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	sphere.Draw(diffShader);

	for (Bone* bone : skeleton->getAllBones())
	{
		diffShader.setVec3("objectColor",col_joint.at(0), col_joint.at(1), col_joint.at(2));

		bool highlight = !strcmp(bone->name.c_str(), "rtibia") || !strcmp(bone->name.c_str(), "ltibia")
			|| !strcmp(bone->name.c_str(), "rradius") || !strcmp(bone->name.c_str(), "lradius")
			|| !strcmp(bone->name.c_str(), "rclavicle") || !strcmp(bone->name.c_str(), "lclavicle")
			//|| !strcmp(bone->name.c_str(), "rhumerus") || !strcmp(bone->name.c_str(), "lhumerus")
		|| !strcmp(bone->name.c_str(), "lowerback");
		if (highlight) {
			diffShader.setVec3("objectColor", col_joint_highlight.at(0), col_joint_highlight.at(1), col_joint_highlight.at(2));
		}
		// calculate the model matrix for each object and pass it to shader before drawing
		model = glm::scale(bone->getJointMat(), glm::vec3(render_scale));
		diffShader.setMat4("model", model);
		if (states.show_joints) sphere.Draw(diffShader);

		// Draw segment
		diffShader.setVec3("objectColor", col_bone.at(0), col_bone.at(1), col_bone.at(2));
		if (highlight) {
			diffShader.setVec3("objectColor",col_bone_highlight.at(0), col_bone_highlight.at(1), col_bone_highlight.at(2));
		}
		model = glm::scale(bone->getSegMat(), glm::vec3(render_scale));
		diffShader.setMat4("model", model);
		if (states.show_bone_segment) cylinder.Draw(diffShader);

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
		if (states.show_cloud) 
		{
			diffShader.setVec3("objectColor", .8f, 0.8f, 0.8f);
			vector<glm::vec3>& points = bone->getLocalPointCloud()->points;
			// cout << "bone " << bone->name << ", pc size: " << points.size() << endl;
			for (auto p : points) {
				model = glm::scale(bone->getLocalPointCloud()->getPointMat(p), glm::vec3(states.point_cloud_size));
				diffShader.setMat4("model", model);
				sphere.Draw(diffShader);
			}
		}
	}

	if (states.show_window_cloud && PC != nullptr) {
		diffShader.setVec3("objectColor", .8f, 0.8f, 0.8f);
		vector<glm::vec3>& points = PC->points;
		for (auto p : points) {
			model = glm::scale(PC->getPointMat(p), glm::vec3(states.point_cloud_size));
			diffShader.setMat4("model", model);
			sphere.Draw(diffShader);
		}
	}
}

void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, 
		screen_size window_region, PointCloud*PC)
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

	glm::mat4 model = glm::mat4(1.0f);
	diffShader.setVec3("objectColor", .95f, 0.95f, 0.95f);
	// floor
	// int grid_size = 20;
	static float tile_scale = 0.5f;
	static float tile_offset = 2.f;
	model = glm::mat4(1.0f);
	if (!states.disable_floor_tiles) {
		// model = glm::scale(model, glm::vec3(tile_scale, 1.f, tile_scale));
		// model = glm::translate(model, glm::vec3(-grid_size * tile_offset / 2, 0.f, -grid_size * tile_offset / 2));
		// for (int i = 0; i < grid_size; i++) {
		// 	for (int j = 0; j < grid_size; j++) {
		// 		if ((i + j) % 2 == 0) 
		// 			diffShader.setVec3("objectColor", 1.f, 1.f, 1.f);
		// 		else 
		// 			diffShader.setVec3("objectColor", 0.7f, 0.7f, 0.7f);
		// 		model = glm::translate(model, glm::vec3(tile_offset, 0.f, 0.f));
		// 		diffShader.setMat4("model", model);
		// 		plane.Draw(diffShader);			
		// 	}
		// 	model = glm::translate(model, glm::vec3(-tile_offset*grid_size, 0.f, tile_offset));
		// }
		for (int i = 0; i < grid_size; i++) {
			for (int j = 0; j < grid_size; j++) {
				if ((i + j) % 2 == 0) 
					diffShader.setVec3("objectColor", 1.f, 1.f, 1.f);
				else 
					diffShader.setVec3("objectColor", 0.7f, 0.7f, 0.7f);
				diffShader.setMat4("model", tiles_mat.at(i*grid_size+j));
				plane.Draw(diffShader);			
			}
		}
	} else {
		model = glm::scale(model, glm::vec3(tile_scale*grid_size, 1.f, tile_scale*grid_size));
		diffShader.setMat4("model", model);
		plane.Draw(diffShader);	
	}

	draw_skeleton(sk, sphere, cylinder, diffShader, PC);
	for (auto &s:sk_frames) {
		draw_skeleton(s.get(), sphere, cylinder, diffShader, nullptr);
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

void plot_line_between_p1_p2(glm::vec3 p1, glm::vec3 p2, Model line, Shader shader, float thickness)
{
	glm::vec3 diff = p1-p2; // vec between p1 and p2
	glm::vec3 v = glm::vec3(0.f, 1.f, 0.f); // initial axis of objection
	
	glm::vec3 rot_ax = glm::cross(v, diff);
	float len = glm::sqrt(glm::dot(diff, diff)); //length of vector diff
	//rotation angle to align object with vector diff
	float angle = glm::acos(glm::dot(v, diff) / len);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, p1);
	model = glm::translate(model, -diff / 2.f);
	// model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
	model = glm::rotate(model, angle, rot_ax );
	model = glm::scale(model, glm::vec3(thickness, len/2, thickness));
	shader.setMat4("model", model);
	line.Draw(shader);
}

void plot_mograph_edge(mograph::Vertex* src, mograph::Edge edge, map<string, int> v_idx, Model line, Shader shader, 
		float thickness, float offset_x, float offset_y, float vertex_offset_h, float padding_top, float padding_left, float scale)
		// mograph::Edge* head_edge = graph->get_head().second;
		// float A = head_edge->get_frames().first;
		// float B = head_edge->get_frames().second;
		// float A_scaled = A * scale * 2;
		// float B_scaled = B * scale * 2;  
		// if (graph->get_head().first == head_edge->get_target()) {
		// 	A_scaled = A == 1 ? A_scaled : (A-k) * scale * 2;
		// 	B_scaled = B == head_edge->get_target()->get_anim()->getNumberOfFrames() ? B_scaled : (B+k) * scale * 2;
		// }

		// float tar_h_offset_1 = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[graph->get_head().first];
		// float tar_h_offset_2 = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[head_edge->get_target()];
		// float x_pos_1 = offset_x+scale/2 + padding_left;
		// float x_pos_2 = offset_x+scale/2 + padding_left;
		// glm::vec3 p1 = glm::vec3(x_pos_1 + (float)A_scaled, tar_h_offset_1, 1.f);
		// glm::vec3 p2 = glm::vec3(x_pos_2 + (float)B_scaled, tar_h_offset_2, 1.f);
		// plot_line_between_p1_p2(p1, p2, line, shader, scale_line_thick/2);
{
	float A = edge.get_frames().first;
	float B = edge.get_frames().second;
	float A_scaled = A * scale * 2;
	float B_scaled = B * scale * 2;

	if (src == edge.get_target()) {
			A_scaled = A == 1 ? A_scaled : (A-k) * scale * 2;
			B_scaled = B == edge.get_target()->get_anim()->getNumberOfFrames() ? B_scaled : (B+k) * scale * 2;
	}

	float tar_h_offset_1 = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[src->get_name()];
	float tar_h_offset_2 = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[edge.get_target()->get_name()];
	float x_pos_1 = offset_x+scale/2 + padding_left;
	float x_pos_2 = offset_x+scale/2 + padding_left;
	glm::vec3 p1 = glm::vec3(x_pos_1 + (float)A_scaled, tar_h_offset_1, 1.f);
	glm::vec3 p2 = glm::vec3(x_pos_2 + (float)B_scaled, tar_h_offset_2, 1.f);
		plot_line_between_p1_p2(p1, p2, line, shader, thickness/2);
}

void plot_motion_graph(mograph::MotionGraph* graph, vector<pair<mograph::Vertex*, mograph::Edge>> graph_traversal, 
		Model quad_mesh, Model line, Shader shader, float offset_x, float offset_y, float scale)
{
	if (graph == NULL) return;

	shader.use();
	// Same projection for every draw call
	glm::mat4 projection = glm::ortho(0.0f, (float)fullscreen_window.width, 0.0f, (float)fullscreen_window.height, 0.0f, 1000000.f);
	shader.setMat4("projection", projection);

		// shader.setVec3("objectColor", .05f, 0.95f, 0.95f);
		// glm::mat4 model = glm::mat4(1.0f);
		// model = glm::translate(model, glm::vec3(offset_x, offset_y, 0));
		// model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
		// model = glm::scale(model, glm::vec3(scale, scale , scale));
		// shader.setMat4("model", model);
		// quad_mesh.Draw(shader);
	
	map<string, int> v_idx;
	int idx = 0;
	for (auto &s:anim_list) {
		for (auto &p:graph->get_graph()) {
			if(p.first->get_name() == s.first) {
				v_idx[s.first] = idx; idx++;
				break;
			}
		}
	}
	// store the vertex plot index
	for (auto v_es:graph->get_graph()) { 
		if (v_idx.count(v_es.first->get_name()) == 0) {
			v_idx[v_es.first->get_name()] = idx; idx++; 
		}
	}
	

	int padding_left = 200, padding_top = 200;
	float vertex_offset_h = 200*scale;
	float scale_line_thick = 5*scale, scale_line_narrow = scale_line_thick/5, scale_point = 10*scale;
	for (auto v_es:graph->get_graph()) // v_es -> pair<Vertex*, vector<Edges>>
	// for (int i = 0 ; i < 5; i++)
	{
		mograph::Vertex* v = v_es.first;
		// Draw vertex => motion line
		shader.setVec3("objectColor", .6f, 0.6f, 0.6f);
		int length_half = v->get_anim()->getNumberOfFrames() * scale;
		float x_pos = offset_x+scale/2 + padding_left + length_half;
		float y_pos = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[v->get_name()];
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(x_pos, y_pos, 0));
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
		model = glm::scale(model, glm::vec3(length_half, 1.f , scale_line_thick));
		// model = glm::translate(model, glm::vec3(offset_x, offset_y, 0));
		// model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
		// model = glm::scale(model, glm::vec3(scale, scale , scale));
		shader.setMat4("model", model);
		quad_mesh.Draw(shader);
		// cout << "drawing vertex " << v->get_name() << " | x = " << x_pos << ", y = " << y_pos << endl;

		shader.setVec3("objectColor",1.f, 0.05f, 0.05f);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(x_pos - length_half, y_pos, 0));
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
		model = glm::scale(model, glm::vec3(scale_point/5, 1.f,  scale_line_thick));
		shader.setMat4("model", model);
		quad_mesh.Draw(shader);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(x_pos + length_half, y_pos, 0));
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
		model = glm::scale(model, glm::vec3(scale_point/5, 1.f, scale_line_thick));
		shader.setMat4("model", model);
		quad_mesh.Draw(shader);

		// Draw the local minimas points on the animation line
		for (mograph::Edge e:v_es.second) {
			// skip if not in threshold
			if (e.get_weight() > states.threshold) 
				continue;

			shader.setVec3("objectColor", .75f, 0.75f, 0.75f);
			// Drawing the bars on the animation line
			int A = e.get_frames().first * scale * 2;
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(x_pos - length_half + A, y_pos, 0));
			model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f) );
			model = glm::scale(model, glm::vec3(scale_point/5, 1.f, scale_point));
			shader.setMat4("model", model);
			quad_mesh.Draw(shader);
			
			// Drawing the lines connecting the bars | from botton vertex to top vertex
			if (v_idx[v->get_name()] > 0) {
				shader.setVec3("objectColor", .6f, 0.6f, 0.6f);
				int B = e.get_frames().second * scale * 2;
				float tar_h = offset_y+scale/2 + padding_top + vertex_offset_h * v_idx[e.get_target()->get_name()];
				glm::vec3 p1 = glm::vec3(x_pos - length_half + (float)B, tar_h, 1.f);
				glm::vec3 p2 = glm::vec3(x_pos - length_half + (float)A, y_pos, 1.f);
				plot_line_between_p1_p2(p1, p2, line, shader, scale_line_narrow);	
			}
		}
	}
	if (states.show_mograph_path) {
		for (auto e:graph_traversal) {
			shader.setVec3("objectColor", .05f, 0.75f, 0.05f);
			plot_mograph_edge(e.first, e.second, v_idx, line, shader, scale_line_thick/1.1f, offset_x, offset_y, vertex_offset_h, padding_top, padding_left, scale);
		}
	}
	// Draw the current edge
	if (states.show_mograph_trav) {
		shader.setVec3("objectColor", .05f, 0.05f, 0.75f);
		plot_mograph_edge(graph->get_head().first, *graph->get_head().second, v_idx, line, shader, scale_line_thick/1.5f, offset_x, offset_y, vertex_offset_h, padding_top, padding_left, scale);
	}
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

	if (!states.move_character) {
		// WASD movement for camera
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
	}
	else {
	// WASD movement for camera
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			sk->root_offset += glm::vec3(sk_offset_any_dir, 0.0f, 0.0f);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			sk->root_offset += glm::vec3(-sk_offset_any_dir, 0.0f, 0.0f);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			sk->root_offset += glm::vec3(0.0f, 0.0f, -sk_offset_any_dir);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			sk->root_offset += glm::vec3(0.0f, 0.0f, sk_offset_any_dir);
	}

	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		states.show_GUI = !states.show_GUI;

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
		// anim_list.push_back({ amc, an });
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

mograph::MotionGraph* get_motion_graph()
{
	mograph::MotionGraph* m = new mograph::MotionGraph(anim_list, sk, k, &progress_mograph);
	return m;
}