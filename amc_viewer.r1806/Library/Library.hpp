#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Skeleton.hpp"

#include <Character/Character.hpp>

#include <string>
#include <set>

namespace Library {
	using std::string;
	using std::set;

	enum {
		LeftFootPlant = 1 << 0,
		RightFootPlant = 1 << 1,
		JumpStart = 1 << 2,
		JumpEnd = 1 << 3,
		Walk = 1 << 4,
		Run = 1 << 5,
	};

	typedef int Annotation;

	const unsigned int AnnotationCount = 6;

	//list of strings containing the names of the
	//annotations above.
	extern char *AnnotationNames[AnnotationCount];

	//list of colors associated with the annotations above.
	extern Vector3f AnnotationColors[AnnotationCount];

	//each motion provides a bare interface to many frames of poses:
	// (each pose annotated with a convenient state vector as well!)
	class Motion {
	public:
		//void get_state(unsigned int frame, Character::State &into) const;
		void get_angles(unsigned int frame, Character::Angles &into) const;
		void get_pose(unsigned int frame, Character::Pose &into) const;
		//call get_pose then call get_local_root on it.
		void get_local_pose(unsigned int frame, Character::Pose &into) const;
		//delta is aggregate control over frame_from to frame_to -- also
		//the change in smooth root position.
		void get_delta(unsigned int frame_from, unsigned int frame_to, Character::StateDelta &into) const;
		//store local-frame root into a character pose:
		void get_local_root(unsigned int frame, Character::Pose &override) const;
		//... or just into some variables:
		void get_local_root(unsigned int frame, Vector3f &position, Quatf &orientation) const;
		//fetch evident control at frame:
		void get_control(unsigned int frame, Character::Control &into) const;
		//or just a reference to it:
		Character::Control const &get_control(unsigned int frame) const;

		float get_distance_to_floor(unsigned int frame) const;

		int get_annotation(unsigned int frame) const;
		void add_annotation(unsigned int frame, Annotation annotation);
		void clear_annotation(unsigned int frame, Annotation annotation);
		bool save_annotations() const;
		bool load_annotations();

		// load motion data into memory sometime after motion is inited
		bool load();
		void unload(); //note: your reference may become INVALID after calling this!

		unsigned int frames() const; //length in timesteps.
		float length() const; //length in time.
		//not for modification by library users!
		Library::Skeleton const *skeleton;
		vector< double > data;

		//actually calculate control_data and local_root.
		void calculate_control_data();

		//for each frame, an 'evident control' may be computed.
		vector< Character::Control > control_data;

		//as can an offset from the 'evident control' path.
		//(this allows characters to be slightly slopped from
		// strict pelvis-forward paths.)
		// - this may be used instead of the absolute roots.
		class RootInfo {
			public:
				Vector3f position;
				Quatf orientation;
		};
		//local root position relative to smoothed global root:
		vector< RootInfo > local_root;
		class SmoothRootInfo {
		public:
			Vector3f position;
			float orientation;
		};
		//smoothed global root position:
		vector< SmoothRootInfo > smooth_root;

		//store the minimum distance from any bone to the floor.
		vector< float > distance_to_floor;
	
		string filename;
		unsigned int subject;
		vector< int > annotations; // int bitset per frame
		bool loaded;
	};


	//read in the library
	// - expects directories with one more dirs and/or one .asf, many .amc's
	void init(string base_path = "data", bool lazy = false);

	// recursively add all .afs/.amc's starting at base_path. Called by init.
	void directory_recursion(string base_path);

	//access some list of motions:
	unsigned int motion_count();
	Motion const &motion(unsigned int index);
	Motion       &motion_nonconst(unsigned int index);

	//in case you want to cache data:
	extern unsigned int signature;
};
#endif //LIBRARY_HPP
