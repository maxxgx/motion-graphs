# Introduction
This project implements motion graphs. A technique for human motion synthesis from motion capture data.
It is developed using OpenGL Core, and uses the [CMU](http://mocap.cs.cmu.edu) mocap data.

If you want to learn more, please refer to my [dissertation](https://sudohead.github.io/posts/2019_motion_synthesis/msc_dissertation.pdf).

# Controls and shortcuts
- **camera**: hold left mouse button
- **move**: W, A, S, D.
- **fly up, down**: E, Q.
- **hide GUI**: U.
- **show pointcloud**: C.
- **play animation**: space bar.

# How to build and run
The code is derived from the [LearnOpenGL](https://github.com/JoeyDeVries/LearnOpenGL) repository, and share much of the basic structure. Use Linux for better performance.
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
Run the executable:
```
./bin/main/main
```
## Linux (Ubuntu, also works under WSLg)
Install, if you haven't already, CMake, Git, and GCC as root:
```
sudo apt-get install g++ cmake git
```
And then get the required packages:
```
sudo apt-get install libsoil-dev libglm-dev libassimp-dev libglew-dev libglfw3-dev libxinerama-dev libxcursor-dev  libxi-dev libxxf86vm-dev
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
Currently, windows is not fully supported. However, an early demo version can be accessed with Visual Studio 17. Change branch to dev-vs to access the working VS solution:
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
