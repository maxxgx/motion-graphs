#include "../headers/Gui.h"

using namespace std;

namespace GUI{

	void showDistanceMatrix(int anim_a_size, int anim_b_size, vector<float> dist_mat, 
		function<float(float,float,float)> normalise, std::pair<int,int> &selected_frames, bool *show_selected_frames, bool *update_texture)
	{
		static float threshold = 0.5f;
		static float last_threshold = threshold;
		ImGui::DragFloat("Threshold", &threshold);
		threshold = threshold >= 0.f ? threshold : 0.f;
		if (ImGui::TreeNode("Distance matrix"))
		{
			ImGuiIO& io = ImGui::GetIO();
			ImGui::TextWrapped("Hover to zoom!");
			
			// std::copy(dist_mat.begin(), dist_mat.end(), back_inserter(dist_mat_norm));
			// transform(dist_mat_norm.begin(), dist_mat_norm.end(), dist_mat_norm.begin(), [&](float val) {return normalise(val,0,0.5);});

			float my_tex_h = anim_a_size;
			float my_tex_w = anim_b_size;

			float minima_color [] = {0.1, 0.8, 0.1};
			static vector<float> dist_mat_norm;
			if (dist_mat_norm.size() != my_tex_h * my_tex_w * 3 || *update_texture || last_threshold != threshold) {
				last_threshold = threshold;
				*update_texture = false;
				dist_mat_norm.clear();
				dist_mat_norm.reserve(my_tex_h*my_tex_w*3);
				for (int i = 0; i < my_tex_h * my_tex_w; i++) {
					if (i < dist_mat.size()) {
						float v = normalise(dist_mat[i], 0.f, threshold);
						if (dist_mat[i] >= 0 && dist_mat[i] <= threshold && blending::is_local_minima(dist_mat, my_tex_h, my_tex_w, i)){
							dist_mat_norm.emplace_back(minima_color[0]);
							dist_mat_norm.emplace_back(minima_color[1]);
							dist_mat_norm.emplace_back(minima_color[2]);
						} else {
							dist_mat_norm.emplace_back(v);
							dist_mat_norm.emplace_back(v);
							dist_mat_norm.emplace_back(v);
						}
					}
					else {
						dist_mat_norm.emplace_back(0.f);
						dist_mat_norm.emplace_back(0.f);
						dist_mat_norm.emplace_back(0.f);
					}
				}
			}

			GLuint tex, tex_marked;
			glEnable(GL_TEXTURE_2D);
			glGenTextures(1,&tex);
			glBindTexture(GL_TEXTURE_2D, tex);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
			glTexImage2D(GL_TEXTURE_2D, 0 ,GL_RGB, my_tex_w, my_tex_h,0,GL_RGB,GL_FLOAT, &dist_mat_norm[0]);

			static float tex_scale = 1.f;
			float region_sz = 32.0f;

			ImTextureID my_tex_id = (void*)(intptr_t)tex;
			ImGui::Text("%.0fx%.0f", my_tex_h, my_tex_w);
			ImGui::Text("size of dist_mat_norm = %d", dist_mat_norm.size());
			ImGui::Text("Region size: %.f", region_sz);
			ImVec2 pos = ImGui::GetCursorScreenPos();

			my_tex_h *= tex_scale;
			my_tex_w *= tex_scale;
			
			ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), ImVec2(0,0), ImVec2(1,1), ImVec4(1.0f,1.0f,1.0f,1.0f), ImVec4(1.0f,1.0f,1.0f,0.5f));
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				float region_x = io.MousePos.x - pos.x - region_sz * 0.5f; 
				if (region_x < 0.0f) region_x = 0.0f; 
				else if (region_x > my_tex_w - region_sz) region_x = my_tex_w - region_sz;
				float region_y = io.MousePos.y - pos.y - region_sz * 0.5f;
				if (region_y < 0.0f) region_y = 0.0f; 
				else if (region_y > my_tex_h - region_sz) region_y = my_tex_h - region_sz;
				float zoom = 6.0f;
				int selected_px_x = (io.MousePos.x - pos.x)/tex_scale;
				int selected_px_y = (io.MousePos.y - pos.y)/tex_scale;
				selected_frames = make_pair(selected_px_y, selected_px_x);
				if(selected_px_x < 0) selected_px_x = 0; else if(selected_px_x > anim_b_size) selected_px_x = anim_b_size;
				if(selected_px_y < 0) selected_px_y = 0; else if(selected_px_y > anim_a_size) selected_px_y = anim_a_size;
				ImGui::Text("Selected: (%d, %d)", selected_px_x, selected_px_y);
				int index = selected_frames.first * anim_b_size + selected_frames.second;
				if ( dist_mat.size() > index) {
					float dist = dist_mat.at(index);
					ImGui::Text("Distance: %f", dist);
				}
				ImVec2 uv0 = ImVec2((region_x) / my_tex_w, (region_y) / my_tex_h);
				ImVec2 uv1 = ImVec2((region_x + region_sz) / my_tex_w, (region_y + region_sz) / my_tex_h);
				ImGui::Image(my_tex_id, ImVec2(region_sz * zoom, region_sz * zoom), uv0, uv1, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(1.0f, 1.0f, 1.0f, 0.5f));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox("Show selected_frames", show_selected_frames);
			ImGui::SliderFloat("Zoom", &tex_scale, 1.f, 10.f);
			ImGui::TreePop();
		}
	}

	void imgui_file_selector(string name,  map<string, vector<string>> dir_nfiles, string root, string *filename) 
	{
		if (ImGui::Button(name.c_str()))
			ImGui::OpenPopup(("my_file_popup" + name).c_str());
		if (ImGui::BeginPopup(("my_file_popup" + name).c_str()))
		{
			for (auto df : dir_nfiles) {
				if(ImGui::BeginMenu(df.first.c_str())) // add files to dir
				{
					for (string file : df.second) {
						if (ImGui::MenuItem(file.c_str()) ) {
							*filename = root + df.first + "/" + file;
						}
					}
					ImGui::EndMenu();
				}
			}
			ImGui::EndPopup();
		}    
	}

	void showBasicControls(bool *play, bool *split_screen, bool *exit, string *anim_a, string *anim_b, 
        int *frame_a, int *frame_b, int *frame_r, int num_frames_a, int num_frames_b, float *speed, 
		map<string, vector<string>> dir_nfiles, string root)
	{
		ImGui::Begin("ControlsA");

		static string btn_text = "Play";
		btn_text = *play ? "STOP" : "PLAY";

		ImGui::PushStyleColor(ImGuiCol_Button, !*play ? color_green : color_red);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, !*play ? color_green_h : color_red_h);
		if (ImGui::Button(btn_text.c_str()) ) *play = !*play;
		ImGui::PopStyleColor(2);

		ImGui::Separator();
		if (ImGui::RadioButton("Split screen", *split_screen)) *split_screen = !*split_screen;
		
        ImGui::Separator();

		string name_anim_a = anim_a->substr(anim_a->find_last_of("/"));
		string name_anim_b = anim_b->substr(anim_b->find_last_of("/"));
		if (*split_screen) {
			ImGui::BulletText( ("Motion A: " + name_anim_a).c_str());
			ImGui::SameLine();
			imgui_file_selector("Select motion A", dir_nfiles, root, anim_a);
			ImGui::SliderInt("Frame A", frame_a, 1, num_frames_a, "%d");

			ImGui::Separator();
			ImGui::BulletText( ("Motion B: " + name_anim_b).c_str());
			ImGui::SameLine();
			imgui_file_selector("Select motion B", dir_nfiles, root, anim_b);
			ImGui::SliderInt("Frame B", frame_b, 1, num_frames_b, "%d");
		} else {
			ImGui::Separator();
			ImGui::BulletText( ("Motion A -> B: (" + name_anim_a + ", " + name_anim_b).c_str());
			ImGui::SliderInt("Frame", frame_r, 1, num_frames_b + num_frames_a, "%d");
		}

        ImGui::Separator();

		if (ImGui::Button("Exit"))
			*exit = true; //exit gameloop

		ImGui::End();
	}
}


// if(ImGui::TreeNode("------")) {
//             /* - This button starts an async thread to do the distance matrix computation
//                - When computation is done, the value is retrivied */
//             static int btn_size = 10;
// 			static int lines = 10;
//             ImGui::SliderInt("Lines", &lines, 1, 300);
// 			ImGui::SliderInt("Button size", &btn_size, 1, 50);
//             ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3.0f);
//             ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2.0f, 1.0f));
//             ImGui::BeginChild("scrolling", ImVec2(0, ImGui::GetFrameHeightWithSpacing() * lines), true, ImGuiWindowFlags_HorizontalScrollbar);
//             pair<int,int> hoovered = {0,0};
//             for (int line = 0; line < get_anim(anim_a)->getNumberOfFrames() && dist_mat.size() > 0; line++)
//             {
//                 // Display random stuff (for the sake of this trivial demo we are using basic Button+SameLine. If you want to create your own time line for a real application you may be better off
//                 // manipulating the cursor position yourself, aka using SetCursorPos/SetCursorScreenPos to position the widgets yourself. You may also want to use the lower-level ImDrawList API)
//                 for (int n = 0; n < get_anim(anim_b)->getNumberOfFrames(); n++)
//                 {
//                     if (n > 0) ImGui::SameLine();
//                     ImGui::PushID(n*line);
//                     float hue = n*0.05f;
// 					float dist = dist_mat.at(line * get_anim(anim_a)->getNumberOfFrames() + n);
// 					float normalised_val = normalise(dist, dist_mat_range.first, 0.5);
// 					// float normalised_val = dist_mat_norm.at(line * get_anim(anim_a)->getNumberOfFrames() + n);
// 					ImVec4 btn_color = ImVec4(normalised_val, normalised_val, normalised_val, 1.f);
//                     ImGui::PushStyleColor(ImGuiCol_Button, btn_color);
//                     ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f));
//                     ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f));
//                     char num_buf[16];
//                     sprintf(num_buf, "");
//                     if (ImGui::Button((const char*)num_buf, ImVec2( btn_size, btn_size)) ) {
//                         selected_frames = {line, n};
//                         states.show_selected_frames = true;
//                     }  
//                     if (ImGui::IsItemHovered()) {
//                         hoovered = {line, n};
//                         selected_frames = {line + 1, n + 1};
// 						cout << "hovering: " << line+1 << "-" << n+1 << endl;
//                     }
//                     ImGui::PopStyleColor(3);
//                     ImGui::PopID();
//                 }
//             }
//             float scroll_x = ImGui::GetScrollX();
//             float scroll_max_x = ImGui::GetScrollMaxX();
//             ImGui::EndChild();
//             ImGui::PopStyleVar(2);
//             float scroll_x_delta = 0.0f;
//             ImGui::SmallButton("<<"); if (ImGui::IsItemActive()) { scroll_x_delta = -ImGui::GetIO().DeltaTime * 1000.0f; } ImGui::SameLine();
//             ImGui::Text("Scroll from code"); ImGui::SameLine();
//             ImGui::SmallButton(">>"); if (ImGui::IsItemActive()) { scroll_x_delta = +ImGui::GetIO().DeltaTime * 1000.0f; } ImGui::SameLine();
//             ImGui::Text("%.0f/%.0f", scroll_x, scroll_max_x);
//             if (scroll_x_delta != 0.0f)
//             {
//                 ImGui::BeginChild("scrolling"); // Demonstrate a trick: you can use Begin to set yourself in the context of another window (here we are already out of your child window)
//                 ImGui::SetScrollX(ImGui::GetScrollX() + scroll_x_delta);
//                 ImGui::EndChild();
//             }
//             ImGui::Spacing();
            

//             ImGui::TreePop();
//         }