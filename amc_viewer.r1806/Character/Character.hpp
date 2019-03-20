#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Vector/Vector.hpp>
#include <Vector/Quat.hpp>
#include <vector>

namespace Library {
	class Skeleton;
}

//Important character data:
namespace Character {

using std::vector;

class State;

//Control is input that affects state
class Control {
public:
	void clear();
	//move state as per this control
	void apply_to(State &state, float timestep) const;
	//both relative to the body frame.
	Vector3f desired_velocity; //rate & direction of movement (z-forward)
	float desired_turning; //rate & direction of turning (around y)
	bool jump; //should the character be jumping?
};

class Pose;
//State is high-level data about a character
class State {
public:
	void clear();
	void apply_to(Pose &pose) const; //stick state data into pose -- that is, add to root position and orientation.
	bool jumpping; //is the character jumpping?
	Vector3f position;
	float orientation; //yaw
};


//state delta is aggregated (non-instantaneous) control.
class StateDelta {
public:
	void clear();
	void apply_to(State &to) const;
	Vector3f position; //(z-forward; z,x only)
	float orientation; //(yaw around y axis)
	bool landed; //did we land?
	bool jumpped; //did we jump?
};

class Pose;

//Angles is a joint-angles precursor to Pose
//(though, to be fair, the first three things in angles are
// actually root position, but let's not stress too much.)
class Angles {
public:
	void clear(unsigned int DOF = 0, Library::Skeleton const *skel = NULL);
	void to_pose(Pose &into) const;
	vector< double > angles;
	Library::Skeleton const *skeleton;
};

//Pose is limb positions and such.
class Pose {
public:
	void clear(unsigned int bones = 0);
	void to_angles(Angles &into) const;
	Pose &operator=(Pose const &other);
	Vector3f root_position;
	Quatf root_orientation;
	vector< Quatf > bone_orientations;
	Library::Skeleton const *skeleton;
};

}

#endif //CHARACTER_HPP
