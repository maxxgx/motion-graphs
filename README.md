# motion-graphs
Human motion synthesis from motion capture data ([CMU](http://mocap.cs.cmu.edu)) in OpenGL Core.

# How to build and run
The code is derived from the [LearnOpenGL](https://github.com/JoeyDeVries/LearnOpenGL) repository, and share much of the basic structure.
## Mac OS X
Building on Mac OS X is fairly simple:
```
brew install cmake assimp glm glfw glew
cd MotionGraphs
mkdir build
cd build
cmake ../.
make -j8
```
## Linux (Ubuntu)
Install, if you haven't already, CMake, Git, and GCC as root:
```
sudo apt-get install g++ cmake git
```
And then get the required packages:
```
sudo apt-get install libsoil-dev libglm-dev libassimp-dev libglew-dev libglfw3-dev libxinerama-dev libxcursor-dev  libxi-dev
``` 
Create the build directory inside the project and navigate to it:
```
cd MotionGraphs/
mkdir build
cd build/
```
Run CMake and compile:
```
cmake ..
make
```
Finally:
```
./main
```
## Windows
Currently, only Visual Studio 17 is supported. Change branch to dev-vs to access the working VS solution:
```
git checkout dev-vs
```
To setup the VS solution, add the following in project properties:
- (Project Master Settings > VC++ Directories)
```
.\includes\
```
- (C/C++ -> General -> Additional Include Directories)
```
.\includes\
.\includes\learnopengl
```
- (C/C++ -> Preprocess Definitions):
```
GLFW_INCLUDE_NONE
```
