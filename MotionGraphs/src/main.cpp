#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include <Shader.h>
#include <Camera.h>
#include <Model.h>
#include <filesystem>
#include <string.h>

#include "../headers/CubeCore.h"
#include "../headers/Skeleton.h"
#include "../headers/Animation.h"
#include "../headers/Bone.h"
#include "../headers/PointLight.h"

#define ROOT_DIR std::filesystem::current_path().string()

#define FPS 120

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_movement(GLFWwindow* window, double xpos, double ypos);
void mouse_scroll(GLFWwindow* window, double xoffset, double yoffset);
void keyboardInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 2000;
const unsigned int SCR_HEIGHT = 1200;

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 8.f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Lights
PointLight lamp = PointLight();

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;
long num_frames = 0;
float agg_fps, agg_anim_time, agg_input_time, agg_render_time = 0.f; // for benchmarking

// Controls
bool play = true;
bool lock_view = true;

float scale = 0.25f;

int skip_frame = 1;

// Animation & skeleton
string file_asf = "res/mocap/02/02.asf";
string file_amc = "res/mocap/02/02_0";
Animation* anim = new Animation((char*)(file_amc + "1.amc").c_str());

int main()
{
	/** GLFW initialization **/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/** GLFW window **/
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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

	/** configure global opengl state **/
	glEnable(GL_DEPTH_TEST);

	/** build and compile shaders **/
	Shader diffShader("shaders/basic_lighting.vs", "shaders/basic_lighting.fs");
	Shader lampShader("shaders/lamp.vs", "shaders/lamp.fs");

	/** load .obj 3D models **/
	Model sphere(ROOT_DIR.append("\\res\\sphere\\sphere.obj"));
	Model cylinder(ROOT_DIR.append("\\res\\cylinder\\cylinder.obj"));
	Model plane(ROOT_DIR.append("\\res\\plane\\plane.obj"));
	Model monkey(ROOT_DIR.append("\\res\\monkey\\monkey.obj"));
	
	// Lights buffers
	lamp.setBuffers();

	// Loading mocap data: skeleton from .asf and animation (poses) from .amc
	Skeleton* sk = new Skeleton((char*)file_asf.c_str(), scale);

	cout << sk->getName();
	vector<Bone*> s = sk->getAllBones();

	// print hierarchy
	//for (Bone *b : s) {
	//	cout << b->getName();
	//	while (b->parent != NULL) {
	//		b = b->parent;
	//		cout << " --> " << b->getName();
	//	}
	//	cout << "\n";
	//}

	sk->apply_pose(anim->getNextPose());
	CubeCore cube = CubeCore();
	cube.setBuffers();

	// Set shader to use
	diffShader.use();

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
		cout << "FPS : " << 1 / deltaTime << endl;


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
		cout << "	Anim update time = " << pose_time * 1000.f << " ms" << endl;

		// input
		// -----
		float input_start_time = glfwGetTime();
		keyboardInput(window);
		float input_time = (glfwGetTime() - input_start_time);
		agg_input_time += input_time;
		cout << "	Input time = " << input_time * 1000 << " ms" << endl;

		/** Start Rendering **/
		float render_start_time = glfwGetTime();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!


		// activate shader
		diffShader.use();
		diffShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
		diffShader.setVec3("lightPos", lamp.Position);
		diffShader.setVec3("viewPos", camera.Position);

		// pass projection matrix to shader (note that in this case it could change every frame)
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		diffShader.setMat4("projection", projection);

		// camera/view transformation
		if (!lock_view) {
			diffShader.setMat4("view", glm::lookAt(camera.Position, sk->getPos(), camera.Up));
		}
		else {
			diffShader.setMat4("view", camera.GetViewMatrix());
		}

		// floor
		diffShader.setVec3("objectColor", .9f, 0.9f, 0.9f);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(50.f, 0.001f, 50.f));
		diffShader.setMat4("model", model);
		//glBindVertexArray(cube.VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		plane.Draw(diffShader);


		// render Skeleton, root first
		float render_scale = .08f;
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
			//if (bone->getName()._Starts_with("head"))
			//{
			//	model = glm::scale(model, glm::vec3(render_scale > 1 ? render_scale: 1 * 5));
			//	ourShader.setMat4("model", model);
			//	monkey.Draw(ourShader);
			//}
			//else
			sphere.Draw(diffShader);
			//monkey.Draw(ourShader);

			// Draw segment
			diffShader.setVec3("objectColor", .6f, 0.6f, 0.6f);
			if (highlight) {
				diffShader.setVec3("objectColor", 0.31f, 0.31f, .6f);
			}
			model = glm::scale(bone->getSegMat(), glm::vec3(render_scale));
			diffShader.setMat4("model", model);
			//glBindVertexArray(cube.VAO);
			//glDrawArrays(GL_TRIANGLES, 0, 36);
			cylinder.Draw(diffShader);
		}

		// Draw Lights
		lampShader.use();
		lampShader.setMat4("projection", projection);
		lampShader.setMat4("view", camera.GetViewMatrix());
		model = glm::mat4(1.0f);
		model = glm::translate(model, lamp.Position);
		model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
		lampShader.setMat4("model", model);

		glBindVertexArray(lamp.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		float render_time = glfwGetTime() - render_start_time;
		agg_render_time += render_time;
		cout << "	render time = " << render_time * 1000 << " ms" << endl;
		/** END RENDERING **/

		float draw_time = glfwGetTime() - currentFrame;
		cout << "	Draw time = " << draw_time * 1000.f << " ms" << endl << endl;
		while (glfwGetTime() - currentFrame < 1.f / FPS) { ; } // wait for sync

		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		//-------------------------------------------------------------------------------

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// de-allocation
	cube.~CubeCore();
	sk->~Skeleton();

	// end glfw
	glfwTerminate();
	return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void keyboardInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
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
		glfwSetWindowShouldClose(window, true);
	}

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

	// Play button
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		play = !play;
		std::cout << "Play" << "\n";
	}

	// Switching animation 01-09
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "1.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "2.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "3.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "4.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "5.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "6.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "7.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "8.amc").c_str());
	if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
		anim = new Animation((char*)(file_amc + "9.amc").c_str());
}

// glfw: called when window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
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