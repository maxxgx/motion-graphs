#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Shader.h>
#include <Camera.h>
#include "../headers/CubeCore.h"
#include "../headers/Skeleton.h"
#include "../headers/Animation.h"
#include "../headers/Bone.h"

#include <iostream>

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

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// Controls
bool play = false;
bool lock_view = true;

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
	Shader ourShader("shaders/basic.vs", "shaders/basic.fs");

	// Loading mocap data: skeleton from .asf and animation (poses) from .amc
	// ----------
	Skeleton* sk = new Skeleton((char*)"res/mocap/05/05.asf", 1);

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

		// render Skeleton, root first
		cube.setBuffers();
		glBindVertexArray(cube.VAO);

		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::translate(model, sk->getPos());
		/*model = glm::rotate(model, (GLfloat)axis[0], glm::vec3(this->copy_axis[0], 0.0f, 0.0f));
		model = glm::rotate(model, (GLfloat)axis[1], glm::vec3(0.0f, this->copy_axis[1], 0.0f));
		model = glm::rotate(model, (GLfloat)axis[2], glm::vec3(0.0f, 0.0f, this->copy_axis[2]));*/
		float scale = 0.1f;
		//model = glm::scale(model, glm::vec3(scale));
		ourShader.setMat4("model", sk->getTransMat());
		glDrawArrays(GL_TRIANGLES, 0, 36);

		for (Bone* bone : sk->getAllBones())
		{
			// calculate the model matrix for each object and pass it to shader before drawing

			ourShader.setMat4("model", bone->getTransMat());
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		
		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		//-------------------------------------------------------------------------------

		//root
		//model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
		//ourShader.setMat4("model", model);
		//glDrawArrays(GL_TRIANGLES, 0, 36);

		//float len = 2.51848f;
		////lhipjoint
		//model = glm::mat4(1.0f);
		//model = glm::translate(model, glm::vec3(0.653368 * len, -0.678499 * len, 0.335782 * len));
		//ourShader.setMat4("model", model);
		//glDrawArrays(GL_TRIANGLES, 0, 36);

		////rhipjoint
		//len = 2.48149;
		//model = glm::mat4(1.0f);
		//model = glm::translate(model, glm::vec3(-0.640058 *len,-0.688614 *len,0.340788*len));
		//ourShader.setMat4("model", model);
		//glDrawArrays(GL_TRIANGLES, 0, 36);

		////lowerback
		//len = 2.10809f;
		//model = glm::mat4(1.0f);
		//model = glm::translate(model, glm::vec3(0.0149039*len, 0.998517*len, -0.0523597*len));
		//ourShader.setMat4("model", model);
		//glDrawArrays(GL_TRIANGLES, 0, 36);

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