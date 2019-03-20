#include "Character.hpp"
#include <Library/Skeleton.hpp>

namespace Character {

Vector3f rotate_by_yaw(Vector3f const &in, float const yaw) {
	float c = cosf(yaw);
	float s = sinf(yaw);
	return make_vector< float >(s * in.z + c * in.x, 0, c * in.z - s * in.x);
}

void Control::clear() {
	desired_velocity = make_vector< float >(0.0f, 0.0f, 0.0f);
	desired_turning = 0;
	jump = false;
}

void Control::apply_to(State &state, float timestep) const {
	state.position += rotate_by_yaw(desired_velocity * timestep, state.orientation);
	state.orientation += desired_turning * timestep;
	state.jumpping = jump;
}

void State::clear() {
	jumpping = false;
	position = make_vector< float >(0.0f, 0.0f, 0.0f);
	orientation = 0;
}

void State::apply_to(Pose &pose) const {
	Quatf rot = rotation(orientation, make_vector(0.0f, 1.0f, 0.0f));
	pose.root_position = rotate(pose.root_position, rot) + position;
	pose.root_orientation = multiply(rot, pose.root_orientation);
}

void StateDelta::clear() {
	position = make_vector< float >(0.0f, 0.0f, 0.0f);
	orientation = 0;
	landed = jumpped = false;
}

void StateDelta::apply_to(State &state) const {
	if (landed) state.jumpping = false;
	if (jumpped) state.jumpping = true;
	state.position += rotate_by_yaw(position, state.orientation);
	state.orientation += orientation;
}

void Angles::clear(unsigned int DOF, Library::Skeleton const *skel) {
	angles.clear();
	angles.resize(DOF, 0.0);
	skeleton = skel;
}

void Angles::to_pose(Pose &to) const {
	assert(skeleton);
	skeleton->build_pose(&(angles[0]), to);
}

void Pose::clear(unsigned int bones) {
	root_position = make_vector(0.0f,0.0f,0.0f);
	root_orientation.clear();

	bone_orientations.resize(bones);

	skeleton = NULL;	

	for (unsigned int i = 0; i < bones; ++i) {
		bone_orientations[i].clear();
	}
}

void Pose::to_angles(Angles &into) const {
	assert(skeleton);
	into.clear(skeleton->frame_size, skeleton);
	skeleton->get_angles(*this, &into.angles[0]);
}

Pose &Pose::operator=(Pose const &other) {
	root_position = other.root_position;
	root_orientation = other.root_orientation;
	bone_orientations = other.bone_orientations;
	skeleton = other.skeleton;
	return *this;
}

}
