#pragma once

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

#include "blending.h"
#include "MotionGraph.h"

#include <string.h>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <limits>

namespace GUI {
    static ImVec4 color_green = (ImVec4)ImColor::HSV(0.3333f, 0.7500f, 0.7843f), color_green_h = (ImVec4)ImColor::HSV(0.3333f, 0.7727f, 0.8627f);
	static ImVec4 color_red = (ImVec4)ImColor::HSV(0.0f, 0.7500f, 0.7843f), color_red_h = (ImVec4)ImColor::HSV(0.f, 0.7727f, 0.8627f);

    void showDistanceMatrix(
        int anim_a_size, 
        int anim_b_size, 
        std::vector<float> dist_mat,
        std::pair<int,int> &selected_frames, 
        bool *show_selected_frames, 
        bool *update_texture);

    void showBasicControls(
        bool *play, 
        bool *split_screen, 
        bool *exit, 
        string *anim_a, 
        string *anim_b, 
        int *frame_a, 
        int *frame_b, 
        int *frame_r, 
        int num_frames_a, 
        int num_frames_b, 
        int num_frames_r, 
        float *speed, 
        map<string, vector<string>> dir_nfiles, 
        string root);

    void showMotionList(vector<pair<string,Animation*>>& anim_cache, map<string, vector<string>> dir_nfiles, string root, string *anim);
}
