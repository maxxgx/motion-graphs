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

#include "../headers/CubeCore.h"
#include "../headers/Skeleton.h"
#include "../headers/Animation.h"
#include "../headers/Bone.h"
#include "../headers/PointLight.h"

#define ROOT_DIR std::filesystem::current_path().string()

#define FPS 120

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 2000;
const unsigned int SCR_HEIGHT = 1200;

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Lights
PointLight lamp = PointLight();

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// Controls
bool play = false;
bool lock_view = true;

float scale = 0.25f;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile our shader zprogram
	// ------------------------------------
	Shader ourShader("shaders/basic_lighting.vs", "shaders/basic_lighting.fs");
	Shader lampShader("shaders/lamp.vs", "shaders/lamp.fs");

	// load .obj 3D models
	Model sphere(ROOT_DIR.append("\\res\\planet\\planet.obj"));
	Model cylinder(ROOT_DIR.append("\\res\\cylinder\\cylinder.obj"));
	Model plane(ROOT_DIR.append("\\res\\plane\\plane.obj"));
	Model monkey(ROOT_DIR.append("\\res\\monkey\\monkey.obj"));
	
	// Lights buffers
	lamp.setBuffers();

	// Loading mocap data: skeleton from .asf and animation (poses) from .amc
	// ----------
	Skeleton* sk = new Skeleton((char*)"res/mocap/05/05.asf", scale);

	cout << sk->getName();
	vector<Bone*> s = sk->getAllBones();

	for (Bone *b : s) {
		cout << b->getName();
		while (b->parent != NULL) {
			b = b->parent;
			cout << " --> " << b->getName();
		}
		cout << "\n";
	}


	Animation* anim = new Animation((char*)"res/mocap/05/05_01.amc");
	sk->apply_pose(anim->getNextPose());
	CubeCore cube = CubeCore();
	cube.setBuffers();


	// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	// -------------------------------------------------------------------------------------------
	ourShader.use();


	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		cout << "FPS : " << 1 / deltaTime << endl;

		// Update animation
		if (play)
		{
			if (anim->isOver()) {
				anim->reset();
				sk->resetAll();
			}
			sk->apply_pose(anim->getNextPose());
		}

		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!


		// activate shader
		ourShader.use();
		ourShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
		ourShader.setVec3("lightPos", lamp.Position);
		ourShader.setVec3("viewPos", camera.Position);

		// pass projection matrix to shader (note that in this case it could change every frame)
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		// camera/view transformation
		if (!lock_view) {
			ourShader.setMat4("view", glm::lookAt(camera.Position, sk->getPos(), camera.Up));
		}
		else {
			ourShader.setMat4("view", camera.GetViewMatrix());
		}

		// floor
		ourShader.setVec3("objectColor", .9f, 0.9f, 0.9f);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(50.f, 0.001f, 50.f));
		ourShader.setMat4("model", model);
		//glBindVertexArray(cube.VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		plane.Draw(ourShader);


		// render Skeleton, root first
		float render_scale = .15f;
		model = glm::scale(sk->getJointMat(), glm::vec3(render_scale));
		ourShader.setVec3("objectColor", 1.0f, 0.1f, 0.1f);
		ourShader.setMat4("model", model);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		sphere.Draw(ourShader);

		for (Bone* bone : sk->getAllBones())
		{
			ourShader.setVec3("objectColor", 0.31f, 1.f, 0.31f);
			// calculate the model matrix for each object and pass it to shader before drawing
			model = glm::scale(bone->getJointMat(), glm::vec3(render_scale));
			ourShader.setMat4("model", model);
			//if (bone->getName()._Starts_with("head"))
			//{
			//	model = glm::scale(model, glm::vec3(render_scale > 1 ? render_scale: 1 * 5));
			//	ourShader.setMat4("model", model);
			//	monkey.Draw(ourShader);
			//}
			//else
			//	sphere.Draw(ourShader);
			monkey.Draw(ourShader);

			// Draw segment
			ourShader.setVec3("objectColor", .6f, 0.6f, 0.6f);
			model = glm::scale(bone->getSegMat(), glm::vec3(render_scale));
			ourShader.setMat4("model", model);
			//glBindVertexArray(cube.VAO);
			//glDrawArrays(GL_TRIANGLES, 0, 36);
			cylinder.Draw(ourShader);
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

		float draw_time = glfwGetTime() - currentFrame;
		//cout << "Draw time (ms) = " << draw_time * 1000.f << endl;
		while (glfwGetTime() - lastFrame < 1.f / FPS) { ; } // wait for sync

		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		//-------------------------------------------------------------------------------

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	cube.~CubeCore();
	sk->~Skeleton();

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

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
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
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

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}