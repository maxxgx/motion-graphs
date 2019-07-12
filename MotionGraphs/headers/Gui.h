#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#ifdef _WIN32 || _WIN64 // windows glad.h order is different?
    #include <GLFW/glfw3.h>
    #include <glad/glad.h>
#else
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
#endif

// Dear ImGui static library
#include "../includes/imgui/imgui.h"
#include "../includes/imgui/imgui_impl_glfw.h"
#include "../includes/imgui/imgui_impl_opengl3.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>


void showGui();

void showDistanceMatrix(int anim_a_size, int anim_b_size, 
    std::vector<float> dist_mat, std::function<float(float,float,float)> normalise, 
    std::pair<int,int> &selected_frames, bool *show_selected_frames);

#endif