#include "../headers/Animation.h"

Animation::Animation(Skeleton* sk, char* amc_filename)
{
	//initialize first pose at index 0 (frame 1)

	bool started = false; //for skipping the first few lines of header stuff

	Pose* pose = new Pose(1);

	string line;
	ifstream myfile(amc_filename);
	int c = 0;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			/*	Loading data	*/
			//cout << "loading line : " << line << "\n";
			vector<string> toks = strSplit(line, ' ');
			
			long p_frame = is_new_frame(line);
			if (p_frame > -1) {
				//push the frame
				if (started) {
					//cout << "--- adding pose #" << p_frame << "\n";
					c++;
					this->poses.push_back(pose);
					pose = new Pose(p_frame);
				}
				else {
					started = true;
				}
			}
			if (started && p_frame == -1) //if started and current line is not frame number
			{
				vector<float> t;
				for (int i = 1; i < toks.size(); i++) {
					t.push_back(stod(toks.at(i)));
				}
				string bone_name = toks.at(0);
				Bone * bone_ = sk->getByName(bone_name);
				pose->addTransf(bone_name, t, bone_->dof[0], bone_->dof[1], bone_->dof[2]);
			}
		}
		//adding last frame/pose
		if (started)
			this->poses.push_back(pose);
		myfile.close();
	}
	else std::cout << "Unable to open file";

	std::cout << "\nAnimation: added "<< c <<  " poses\n";
}

Animation::Animation(vector<Pose*> ps)
{
	this->poses = ps;
}

void Animation::addPoses(vector<Pose*> ps) 
{
	this->poses.insert(this->poses.end(), ps.begin(), ps.end());
}

Pose* Animation::getPoseAt(long frame)
{
	frame--; // poses start from [0], frames starts from 1
	this->currentFrame = frame;
	if (this->poses.size() > frame && frame > 0) {
		return this->poses.at(frame);
	}
	else 
		return NULL;
}

Pose* Animation::getNextPose()
{
	if (currentFrame > poses.size() - 1)
		return NULL;
	else {
		//cout << "--- Returning pose at frame " << currentFrame << "\n";
		Pose* p = this->poses.at(currentFrame);
		this->currentFrame++;
		return p;
	}
}

vector<Pose*> Animation::getPosesInRange(unsigned long start, unsigned long end)
{
	vector<Pose*> ps;
	if (start >= 0 && start <= this->poses.size() && end >= 0 && end <= this->poses.size()) {
		for(int i = start; i <= end; i++) {
			ps.push_back(this->getPoseAt(i));
		}		
	} else {
		cout << "Animation::getPosesInRange: range error -> start = " 
		<< start << ", end = " << end << ", size = " << this->poses.size() << endl;
	}
	return ps;
}

long Animation::getCurrentFrame()
{
	return this->currentFrame;
}

long Animation::getNumberOfFrames() 
{
	return this->poses.size();
}

void Animation::setFrame(long frame)
{
	if (frame > 0 && frame < this->poses.size())
		this->currentFrame = frame;
}

bool Animation::isOver()
{
	return currentFrame > this->poses.size() - 1;
}

void Animation::reset()
{
	this->currentFrame = 1;
}

Animation::~Animation() 
{

}