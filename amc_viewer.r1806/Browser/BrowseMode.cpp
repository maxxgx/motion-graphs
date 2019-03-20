#include "BrowseMode.hpp"

#include <Character/Draw.hpp>
#include <Character/pose_utils.hpp>
#include <Library/Library.hpp>
#include <Character/skin_utils.hpp>

#include <Graphics/Graphics.hpp>
#include <Graphics/Font.hpp>
#include <Vector/VectorGL.hpp>

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using std::string;

using std::ostringstream;

using std::cout;
using std::cerr;
using std::endl;

using std::ofstream;

BrowseMode::BrowseMode() {
	camera = make_vector(10.0f, 10.0f, 10.0f);
	target = make_vector(0.0f, 0.0f, 0.0f);
	track = false;
	current_pose.clear();
	current_motion = 0;
	time = 0.0f;
	play_speed = 1.0f;
}

BrowseMode::~BrowseMode() {
}

void BrowseMode::update(float const elapsed_time) {
	assert(current_motion < Library::motion_count());
	Library::Motion const &motion = Library::motion(current_motion);
	if (motion.frames() == 0) {
		cerr << "Motion from " << motion.filename << " has zero frames." << endl;
		return;
	}
	time = fmodf(elapsed_time * play_speed + time, motion.length());
	unsigned int frame = (unsigned int)(time / motion.skeleton->timestep);
	if (frame >= motion.frames()) frame = motion.frames() - 1;

	motion.get_pose(frame, current_pose);

	if (track) {
		Vector3f delta = current_pose.root_position - target;
		target += delta;
		camera += delta;
	}
}

void BrowseMode::handle_event(SDL_Event const &event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_TAB) {
		track = !track;
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		quit_flag = true;
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_PAGEUP) {
		current_motion += 1;
		if (current_motion >= Library::motion_count()) {
			current_motion = 0;
		}
		time = 0.0f;
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_PAGEDOWN) {
		current_motion -= 1;
		if (current_motion >= Library::motion_count()) {
			current_motion = Library::motion_count() - 1;
		}
		time = 0.0f;
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
		if (play_speed == 1.0f) play_speed = 0.1f;
		else if (play_speed == 0.1f) play_speed = 0.0f;
		else play_speed = 1.0f;
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
		for (unsigned int m = 0; m < Library::motion_count(); ++m) {
			Library::Motion const &motion = Library::motion(m);
			cout << "Dumpping '" << motion.filename + ".global" << "'" << endl;
			ofstream out((motion.filename + ".global").c_str());
			out << "\"position.x\", \"position.z\", \"position.yaw\", \"root.x\", \"root.y\", \"root.z\"";
			for (unsigned int b = 0; b < motion.skeleton->bones.size(); ++b) {
				out << ", ";
				out << '"' << motion.skeleton->bones[b].name << ".x" << '"';
				out << ", ";
				out << '"' << motion.skeleton->bones[b].name << ".y" << '"';
				out << ", ";
				out << '"' << motion.skeleton->bones[b].name << ".z" << '"';
			}
			out << endl;
			for (unsigned int f = 0; f < motion.frames(); ++f) {
				Character::WorldBones w;
				Character::Pose p;
				motion.get_local_pose(f, p);
				Character::get_world_bones(p, w);
				{
					Character::StateDelta delta;
					motion.get_delta(0, f, delta);
					out << delta.position.x << ", " << delta.position.z << ", " << delta.orientation << ", " << p.root_position.x << ", " << p.root_position.y << ", " << p.root_position.z;
				}
				for (unsigned int b = 0; b < w.tips.size(); ++b) {
					for (unsigned int c = 0; c < 3; ++c) {
						out << ", ";
						out << w.tips[b].c[c];
					}
				}
				out << endl;
			}
		}
	}

	//rotate view:
	if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT))) {
		Vector3f vec = camera - target;
		float len = length(vec);
		float theta_yaw = atan2(vec.z, vec.x);
		float theta_pitch = atan2(vec.y, sqrt(vec.x * vec.x + vec.z * vec.z));
		theta_yaw += event.motion.xrel / float(Graphics::screen_x) / len * 100;
		theta_pitch += event.motion.yrel / float(Graphics::screen_x) / len * 100;
		if (theta_pitch > 0.4 * M_PI) theta_pitch = 0.4 * M_PI;
		if (theta_pitch <-0.4 * M_PI) theta_pitch =-0.4 * M_PI;

		camera = make_vector(cosf(theta_yaw)*cosf(theta_pitch),sinf(theta_pitch),sinf(theta_yaw)*cosf(theta_pitch)) * len + target;
	}
	//pan view:
	if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE))) {
		Vector3f to = normalize(camera - target);
		Vector3f right = normalize(cross_product(to, make_vector< float >(0,1,0)));
		Vector3f up = -cross_product(to, right);
		float len = length(camera - target);
		camera += right * event.motion.xrel / float(Graphics::screen_x) * len;
		camera += up * event.motion.yrel / float(Graphics::screen_x) * len;
		target += right * event.motion.xrel / float(Graphics::screen_x) * len;
		target += up * event.motion.yrel / float(Graphics::screen_x) * len;
	}
	//zoom view:
	if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT))) {
		Vector3f vec = camera - target;
		float len = length(vec);
		len *= pow(2, event.motion.yrel / float(Graphics::screen_x) * 10);
		if (len < 1) len = 1;
		if (len > 100) len = 100;
		camera = normalize(camera - target) * len + target;
	}
}

void BrowseMode::draw() {
const int FloorSize = 100;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluPerspective(60.0, Graphics::aspect(), 0.1, 10.0 * FloorSize);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	{
		float y = camera.y;
		if (y < 0.1f) y = 0.1f;
		gluLookAt(camera.x, y, camera.z, target.x, target.y, target.z, 0, 1, 0);
	}


	for (unsigned int pass = 0; pass <= 2; ++pass) {
		static Vector4f l = make_vector(0.0f, float(FloorSize), 0.0f, 1.0f);
		static Vector4f amb = make_vector(0.1f, 0.1f, 0.1f, 1.0f);
		static Vector4f dif = make_vector(1.0f, 1.0f, 1.0f, 1.0f);
		static Vector4f zero = make_vector(0.0f, 0.0f, 0.0f, 0.0f);
		glLightfv(GL_LIGHT0, GL_AMBIENT, amb.c);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif.c);
		glLightfv(GL_LIGHT0, GL_POSITION, l.c);
		if (pass == 0) { //reflections.
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_LIGHTING);
			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_LIGHT0);
			l.y *= -1;
			glLightfv(GL_LIGHT0, GL_POSITION, l.c);
			l.y *= -1;
			glPushMatrix();
			glScaled(1.0f,-1.0f, 1.0f); //flip over the floor.
		} else if (pass == 1) {
			//shadows.
			glDisable(GL_DEPTH_TEST);
			glEnable(GL_STENCIL_TEST);
			glStencilFunc(GL_ALWAYS, 1, 0xff);
			glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
			glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
			glPushMatrix();
			double mat[16] = {
				l.y,	0,	0,	0, //x multiplies this
				0,	0,	0,	-1, //y multiplies this
				0,	0,	l.y,	0, //z multiplies this
				-l.x*l.y,	0,	-l.z*l.y,	l.y
			};
			glMultMatrixd(mat);
		} else if (pass == 2) {
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_LIGHTING);
		}
		//state can be used to translate and rotate the character
		//to an arbitrary position, but we don't need that.
		Character::State null;
		null.clear();
		static bool cant_load_skin = false; //Huge hack: only check for skin file once.
		if (!skin.skin_buffer && !cant_load_skin) {
			load("player.skin", current_pose.skeleton, skin);
			if (!skin.skin_buffer) {
				cerr << "Looks like you don't have a player.skin file, so you get cylinders instead." << endl;
				cant_load_skin = true;
			}
		}
		if (skin.skin_buffer && pass == 2) {
			skin.calculate(current_pose, null);
			skin.draw();
		} else {
			Character::draw(current_pose, null, pass == 2, pass != 1);
		}
		if (pass == 0) { //cleanup post-reflections.
			glPopMatrix();
			glDisable(GL_LIGHTING);

			//overwrite anything sticking through the floor:
			glDepthFunc(GL_GEQUAL);
			glBegin(GL_QUADS);
			glColor3f(0,0,0);
			glVertex3f(-FloorSize,0,-FloorSize);
			glVertex3f(-FloorSize,0, FloorSize);
			glVertex3f( FloorSize,0, FloorSize);
			glVertex3f( FloorSize,0,-FloorSize);
			glEnd();
			glDepthFunc(GL_LESS);

			glDisable(GL_DEPTH_TEST);

		} else if (pass == 1) {
			glPopMatrix();

			//Now to deal with shadows.
			glEnable(GL_STENCIL_TEST);
			glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
			glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

			//draw the floor:
			glEnable(GL_LIGHTING);
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
			for (int floor_pass = 0; floor_pass < 2; ++floor_pass) {
				if (floor_pass == 0) {
					glLightfv(GL_LIGHT0, GL_AMBIENT, amb.c);
					glLightfv(GL_LIGHT0, GL_DIFFUSE, zero.c);
					glStencilFunc(GL_EQUAL, 1, 0xff);
				} else if (floor_pass == 1) {
					glLightfv(GL_LIGHT0, GL_AMBIENT, amb.c);
					glLightfv(GL_LIGHT0, GL_DIFFUSE, dif.c);
					glStencilFunc(GL_NOTEQUAL, 1, 0xff);
				}
				glNormal3f(0,1,0);
				glPushMatrix();
				glScalef(FloorSize / 10.0f, 1.0f, FloorSize / 10.0f);
				glBegin(GL_QUADS);
				for (int x = -10; x < 10; ++x) {
					for (int z = -10; z <= 10; ++z) {
						if ((x & 1) ^ (z & 1)) {
							glColor4f(0.5, 0.5, 0.5, 0.1);
						} else {
							glColor4f(0.9, 0.9, 0.9, 0.3);
						}
						glVertex3f(x,0,z);
						glVertex3f(x+1,0,z);
						glVertex3f(x+1,0,z+1);
						glVertex3f(x,0,z+1);
					}
				}
				glEnd();
				glPopMatrix();
			}
			glDisable(GL_BLEND);
			glDisable(GL_LIGHTING);
			glDisable(GL_STENCIL_TEST);
		} else if (pass == 2) {
			glDisable(GL_LIGHTING);
			glDisable(GL_DEPTH_TEST);
		}
	}
	glDisable(GL_DEPTH_TEST);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	//--- now some info overlay ---
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glScaled(1.0 / Graphics::aspect(), 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	{
		Graphics::FontRef gentium = Graphics::get_font("gentium.txf");
		ostringstream info1, info2, info3, info4;
		Library::Motion const &motion = Library::motion(current_motion);
		info1 << "Motion: " << motion.filename;
		info2 << "Skeleton: " << motion.skeleton->filename;
		info3 << "Frame " << (unsigned int)(time / motion.skeleton->timestep) << " of " << motion.frames() << " (" << 1.0f / motion.skeleton->timestep << " fps)";
		info4 << play_speed << "x speed";
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor3f(1.0f, 1.0f, 1.0f);
		Vector2f pos = make_vector(-(float)Graphics::aspect(), 1.0f);
		const float height = 0.07f;
		pos.y -= height;
		gentium.ref->draw(info1.str(), pos, height);
		pos.y -= height;
		gentium.ref->draw(info2.str(), pos, height);
		pos.y -= height;
		gentium.ref->draw(info3.str(), pos, height);
		pos.y -= height;
		gentium.ref->draw(info4.str(), pos, height);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	Graphics::gl_errors("BrowseMode::draw");
}
