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

#include <iostream>

#include <learnopengl/Camera.h> // custom camera.h
#include <learnopengl/shader.h>
#ifdef _WIN32 || _WIN64
	#include <learnopengl/Model.h>
#else
	#include <learnopengl/model.h>
#endif
#include <learnopengl/filesystem.h>
#include <string.h>

#include "../headers/CubeCore.h"
#include "../headers/Skeleton.h"
#include "../headers/Animation.h"
#include "../headers/Bone.h"
#include "../headers/PointLight.h"
#include "../headers/PointCloud.h"

#define ROOT_DIR FileSystem::getRoot()

#define FPS 120
// settings
struct screen_size {
	unsigned int width = 1600, height = 1000;
	unsigned int posX = 0, posY = 0;
} init_window, curr_window, fullscreen_window, region_a, region_b;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_movement(GLFWwindow* window, double xpos, double ypos);
void mouse_scroll(GLFWwindow* window, double xoffset, double yoffset);
void keyboardInput(GLFWwindow *window);
Animation* get_anim(string amc);
void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, screen_size window_region);


// Camera
Camera camera(glm::vec3(0.0f, 1.4f, 2.f));
float lastX = init_window.width / 2.0f;
float lastY = init_window.height / 2.0f;
bool firstMouse = true;

// Lights
PointLight lamp = PointLight();

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;
long num_frames = 0;
float agg_fps, agg_anim_time, agg_input_time, agg_render_time = 0.f; // for benchmarking

// Controls
bool play = false;
bool is_full_screen = false;
bool lock_view = false;
bool show_cloud = false;

float scale = 0.056444f; //inches to meters

int skip_frame = 1;
int k = 40;

// Animation & skeleton
string res_path = ROOT_DIR + "/resources/";
string file_asf = res_path + "mocap/02/02.asf";
string file_amc = res_path + "mocap/02/02_0";
//string file_asf = res_path + "mocap/14/14.asf";
//string file_amc = res_path + "mocap/14/14_0";
map<string, Animation*> anim_cache;

// Loading mocap data: skeleton from .asf and animation (poses) from .amc
Skeleton* sk = new Skeleton((char*)file_asf.c_str(), scale);
string anim_a = (file_amc + "1.amc");
string anim_b = (file_amc + "3.amc");

int main()
{
	/** GLFW initialization **/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif

	GLFWvidmode *primary_mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	fullscreen_window.width = primary_mode->width; 
	fullscreen_window.height = primary_mode-> height;
	curr_window.width = fullscreen_window.width * .75f;
	curr_window.height = fullscreen_window.height * .75f;
	init_window = curr_window;
	cout << "Screen size: " << fullscreen_window.width << "x" << fullscreen_window.height << endl;
	cout << "Init window size: " << init_window.width << "x" << init_window.height << endl;
	region_a.width = curr_window.width / 2;
	region_a.height = curr_window.height;
	region_b.width = curr_window.width / 2;
	region_b.height = curr_window.height;
	region_b.posX = curr_window.width/2;

	/** GLFW window **/
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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/** GLFW capture mouse **/
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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
#endif
	Model sphere(FileSystem::getPath("resources/objects/sphere/sphere.obj"));
	Model cylinder(FileSystem::getPath("resources/objects/cylinder/cylinder.obj"));
	Model plane(FileSystem::getPath("resources/objects/plane/plane.obj"));
	Model monkey(FileSystem::getPath("resources/objects/monkey/monkey.obj"));
	CubeCore cube = CubeCore();

	// Lights buffers
	lamp.setBuffers();

	// Add first anim to cache 
	get_anim(anim_a);
	get_anim(anim_b);
	sk->apply_pose(NULL);
	cube.setBuffers();

	// Set shader to use
	diffShader.use();

	// Calculating distance matrix
	cout << "Calculating distance matrix" << endl;
	int num_frames_a = get_anim(anim_a)->getNumberOfFrames();
	int num_frames_b = get_anim(anim_b)->getNumberOfFrames();
	for (int i = 1; i < num_frames_a; i++) {
		for (int j = 1; j < num_frames_b; j++) {
			float distance = -1.f;
			if (i+k-1 <= num_frames_a && j-k+1 > 0) {
				vector<Pose*> poses_a = get_anim(anim_a)->getPosesInRange(i, i+k-1);
				cout<<"malaka" << endl;
				vector<Pose*> poses_b = get_anim(anim_b)->getPosesInRange(j-k+1, j);
				cout << "size of poses_a = " << poses_a.size() << ", poses_b =" << poses_b.size();
				cout<<"malaka2" << endl;
				PointCloud* cloud_a = sk->getGlobalWindowPointCloud(poses_a);
				cout<<"malaka3" << endl;
				PointCloud* cloud_b = sk->getGlobalWindowPointCloud(poses_b);
				cout<<"malaka4" << endl;
				distance = cloud_a->computeDistance(cloud_b);
			}
			cout << "| @"<<i<<"," <<j<<"\td="<<distance<<"\t"; 
		}
		cout <<endl;
	}
	

	/** render loop **/
	while (!glfwWindowShouldClose(window))
	{
		// frame time
		num_frames++;
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		float last_fps = 1.f / deltaTime;
		agg_fps += last_fps;

		Animation* anim = get_anim(anim_a);
		// Update animation 
		if (play)
		{
			if (anim->isOver()) {
				anim->reset();
				sk->resetAll();
			}
			int frame = anim->getCurrentFrame();
			sk->apply_pose(anim->getPoseAt(frame + skip_frame));
			for (int i = 0; i < skip_frame; i++) {
				anim->getNextPose();
			}
		}
		float pose_time = glfwGetTime() - currentFrame;
		agg_anim_time += pose_time;

		// input
		// -----
		float input_start_time = glfwGetTime();
		keyboardInput(window);
		float input_time = (glfwGetTime() - input_start_time);
		agg_input_time += input_time;

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

		glViewport(region_a.posX, region_a.posY, region_a.width, region_a.height);
		draw(plane, sphere, cylinder, cube, diffShader, lampShader, region_a);

		anim = get_anim(anim_b);
		// Update animation 
		if (play)
		{
			if (anim->isOver()) {
				anim->reset();
				sk->resetAll();
			}
			int frame = anim->getCurrentFrame();
			sk->apply_pose(anim->getPoseAt(frame + skip_frame));
			for (int i = 0; i < skip_frame; i++) {
				anim->getNextPose();
			}
		}
		glViewport(region_b.posX, region_b.posY, region_b.width, region_b.height);
		draw(plane, sphere, cylinder, cube, diffShader, lampShader, region_b);

		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		//-------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

		// wait for sync
		while (glfwGetTime() - currentFrame < 1.f / FPS) { ; }
	}

	// de-allocation
	cube.~CubeCore();
	sk->~Skeleton();
	// anim->~Animation();

	// end glfw
	glfwTerminate();
	return 0;
}

void draw(Model plane, Model sphere, Model cylinder, CubeCore cube, Shader diffShader, Shader lampShader, screen_size window_region)
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
	if (lock_view) {
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
		if (show_cloud) 
		{
			diffShader.setVec3("objectColor", .8f, 0.8f, 0.8f);
			for (auto p : bone->getLocalPointCloud()->points) {
				model = glm::scale(bone->getLocalPointCloud()->getPointMat(p), glm::vec3(0.01f));
				diffShader.setMat4("model", model);
				// sphere.Draw(diffShader);
				glBindVertexArray(cube.VAO);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
		}			
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
	agg_render_time += render_time;
	/** END RENDERING **/
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void keyboardInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		cout << endl << "==========\tPerformance report:\t==========" << endl << endl;
		cout << "\tAVG FPS: " << agg_fps / num_frames << endl;
		cout << "\tAVG anim update time = " << agg_anim_time / num_frames * 1000.f << endl;
		cout << "\tAVG input time = " << agg_input_time / num_frames * 1000.f << endl;
		cout << "\tAVG render time = " << agg_render_time / num_frames * 1000.f << endl;
		cout << endl << "==================================================" << endl;
		cout << agg_fps / num_frames << endl
			<< agg_anim_time / num_frames * 1000.f << endl
			<< agg_input_time / num_frames * 1000.f << endl
			<< agg_render_time / num_frames * 1000.f << endl;
		cout << endl << "lamp pos = " << lamp.Position.x << ", " << lamp.Position.y <<
			", " << lamp.Position.z;
		glfwSetWindowShouldClose(window, true);
	}

	// TOGGLE: Play button
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		play = !play;
		std::cout << "Play" << "\n";
	}
	// TOGGLE: Fullscreen
	if ((glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS))
	{
		is_full_screen = !is_full_screen;
		if (is_full_screen) {
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
		lock_view = !lock_view;
	// TOGGLE: show cloud point
	if ((glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS))
		show_cloud = !show_cloud;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);

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

	// Switching animation 01-09
	// if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
	// 	change_anim(file_amc + "1.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
	// 	// amc = file_amc + "3.amc"; //demo
	// 	change_anim(file_amc + "2.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
	// 	change_anim(file_amc + "3.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
	// 	change_anim(file_amc + "4.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
	// 	// amc = res_path + "mocap/14/14_06.amc"; //demo
	// 	change_anim(file_amc + "5.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
	// 	change_anim(file_amc + "6.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {
	// 	change_anim(file_amc + "7.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) {
	// 	change_anim(file_amc + "8.amc");
	// }
	// if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) {
	// 	change_anim(file_amc + "9.amc");		
	// }
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
	region_a.width = curr_window.width / 2;
	region_a.height = curr_window.height;
	region_b.width = curr_window.width / 2;
	region_b.height = curr_window.height;
	region_b.posX = curr_window.width/2;
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

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: called when mouse wheel is used
void mouse_scroll(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}