#include "../headers/blending.h"


namespace blending {
    vector<PointCloud*> getCumulativePC(Animation *anim, Skeleton *sk, int k)
    {
        vector<PointCloud*> cloud_total;
        int num_frames = anim->getNumberOfFrames();
        cloud_total.reserve(num_frames);
        // Pose starts at 1
        for (int i = 1; i < num_frames+1; i++) {
            Pose* pose = anim->getPoseAt(i);
            cloud_total.push_back( sk->getGlobalPointCloud(pose) );
        }
        int v_size = cloud_total.size();
        int index = 0;
        auto iter = cloud_total;

        auto cumulative_pc = [&] (PointCloud* val) {
                if(index + k < v_size) {
                    for (int i=index+1; i < index + k +1 ; i++) {
                        val->addPointCloud(iter[i]);
                    }
                }
                    else
                        val = NULL;
                    index++;
                    return val;
            };
        
        cout << "Applying transform and rotation on PC |" << anim<<endl;
        std::transform(cloud_total.begin(), cloud_total.end(), cloud_total.begin(), cumulative_pc);
        rotate(cloud_total.rbegin(), cloud_total.rbegin() + k/2, cloud_total.rend());
        return cloud_total;
    }


    pair<vector<float>, pair<float,float>> compute_distance_matrix(Animation *anim_a, Animation *anim_b, Skeleton *sk, int k, float *progress)
    {
        cout << "Calculating distance matrix" << endl;
        const int num_frames_a = anim_a->getNumberOfFrames();
        const int num_frames_b = anim_b->getNumberOfFrames();
        double t = glfwGetTime();
        vector<PointCloud*> cloud_a_total = getCumulativePC(anim_a, sk, 2*k);
        vector<PointCloud*> cloud_b_total = getCumulativePC(anim_b, sk, 2*k);
        t = glfwGetTime() - t;

        // for (int i = v_size -1; i >= 0; i--) {
        //     if(i - k + 1 >= 0){
        //         for (int j = i - 1; j > i - k; j--) {
        //             cloud_b_total[i]->addPointCloud(cloud_b_total[j]);
        //         }
        //     } else 
        //         cloud_b_total[i] = NULL;
        // }
        // PCs_a = cloud_a_total;
        // PCs_b = cloud_b_total;

        vector<float> distance_mat;
        // distance_mat.reserve(num_frames_a*num_frames_b);
        pair<int, int> min_dist_frames = {-1,-1};
        pair<float, float> range = {std::numeric_limits<float>::infinity(),-1};

        for (int i = 0; i < num_frames_a; i++) {
            PointCloud* cloud_a = cloud_a_total[i];

            for (int j = 0; j < num_frames_b; j++) {
                PointCloud* cloud_b = cloud_b_total[j];
                float distance = -1.f; // default distance == -1
                if (cloud_a != NULL && cloud_b != NULL) {
                    distance = cloud_a->computeDistance(cloud_b);
                    // cout << "assigning " << i << " - " << j << "dist = " << distance << endl;
                    if (distance != -1.f && distance < range.first) {
                        range.first = distance;
                        min_dist_frames = { i,j };
                    }
                    if (distance > range.second) {
                        range.second = distance;
                    }
                }
                //cout << "| @"<<i<<"," <<j<<"\td="<<distance<<"\t"; 
                distance_mat.push_back(distance);
            }
            *progress = (float)i/(float)num_frames_a;
            cout << "i = "<< i <<endl;
        }

        for (auto c_a:cloud_a_total) delete c_a;
        for (auto c_b:cloud_b_total) delete c_b;

        cout << distance_mat.size() << "== size of mat row" << endl;

        cout << "range: " << range.first << " to " << range.second << endl;

        cout << "Min distance at frames " << min_dist_frames.first << " - " << min_dist_frames.second << endl;
        return {distance_mat, range};
    }

    bool is_local_minima(vector<float> D, int h, int w, int index) 
    {
        // function<int(int)> getColInd = [&](int i) {return i%w;};
        // function<int(int)> getRowInd = [&](int i) {return ceil(i/w);};
        // function<int(int,int)> toMatInd = [&](int r, int c) { return r*w + c;};

        // cout << "i = " << index << " | [" << getRowInd(index) << "][" << getColInd(index) << "]"<< endl; 

        if (D[index] < 0.f) {
            return false;
        }

        bool peak = true;

        int c = index%w;
        int r = ceil(index/w);

        int local_grid = 3;

        for (int i=0, ir = r-1; i < local_grid; i++, ir++) {
            for (int j=0, jc = c-1; j < local_grid; j++, jc++) {
                if ( !(ir == r && jc == c) && ir >= 0 && ir < h && jc >= 0 && jc < w) { // valid
                    peak &= D[index] <= D[ir*w + jc];
                }
            }
        }

        // if (c == 0 && w > c+1) {
        //     peak = peak && D[index] <= D[r*w + c + 1];
        // }

        // if (c == w-1) {
        //     peak = peak && D[index] <= D[r*w + c - 1];
        // }

        // if ( c > 0 && c < w-1) {
        //     peak = peak && D[index] <= D[r*w + c - 1] && D[index] <= D[r*w + c + 1];
        // }
        
        // if (r == 0 && h > r+1) {
        //     peak = peak && D[index] <= D[(r+1)*w + c];
        // }
        // if (r == h-1) {
        //     peak = peak && D[index] <= D[(r-1)*w + c];
        // }

        // if ( r > 0 && r < h-1) {
        //     peak = peak && D[index] <= D[(r-1)*w + c] && D[index] <= D[(r+1)*w + c];
        // }

        return peak;
    }

    vector<int> find_local_minima(vector<float> D, int w, int h)
    {
        vector<int> minimas;
        for (int i = 0; i < h*w; i++) {
            if (is_local_minima(D, h, w, i)) {
                minimas.push_back(i);
            }
        }
        return minimas;
    }


    Pose* blend_pose(Pose* a, Pose* b, float t)
    {
        if (a == NULL && b != NULL) return b;
        if (b == NULL && a != NULL) return a;
        if (a == NULL && b == NULL) return NULL;
        Pose* blend = new Pose(a->getPoseFrame());
        blend->root_pos = glm::mix(a->getRootPos(), b->getRootPos(), t);
        for (auto name_quat: a->getAllPoses()) {
            glm::quat b_quat = b->getBoneTrans(name_quat.first);
            blend->addSingle(name_quat.first, glm::slerp(name_quat.second, b_quat, t));
        }

        return blend;
    }

    float continuity(float t, float k)
    {
        return 2 * pow((( (float)t+1.f)/(float)k), 3) - 3 * pow((( (float)t+1.f)/(float)k), 2) + 1;
    }

    Animation* blend_anim(Animation *anim_a, Animation *anim_b, int Ai, int Bj, int k)
    {
        if ( (Ai-k < 1 && Ai + k > anim_a->getNumberOfFrames() ) && (Bj-k < 1 && Bj + k > anim_b->getNumberOfFrames() )) {
            cout << "Cannot make transition between frames Ai = " << Ai<<", Bj = " << Bj <<endl;
            return NULL;
        }
        vector<Pose*> pre_Ai = anim_a->getPosesInRange(0, Ai-k-1);
        vector<Pose*> after_Bj = anim_b->getPosesInRange(Bj+k+1, anim_b->getNumberOfFrames());

        vector<Pose*> inside_k;
        inside_k.reserve(k);

        // Blending Ai-k with Bj-k to Ai+k with Bj+k
        for (int a = Ai-k, b = Bj-k, t = 0; a <= Ai+k, b <= Bj+k; a++, b++, t++) {
            float cont = continuity((float)t, (float)k*2 +1);
            cout << "Blending: blend frame Ai = " << a << " with Bj = " << b << ", t = " << (float)t/(float)(k-1) << endl;
            cout << " || Blending: blend frame Ai = " << a << " with Bj = " << b << ", t = " << cont << endl;
            Pose* blended_pose = blend_pose(anim_b->getPoseAt(b), anim_a->getPoseAt(a), cont);
            inside_k.emplace_back(blended_pose);
        }

        pre_Ai.insert(pre_Ai.end(), inside_k.begin(), inside_k.end());
        pre_Ai.insert(pre_Ai.end(), after_Bj.begin(), after_Bj.end());

        Animation* blend = new Animation(pre_Ai);

        cout << "Blended: new anim size is " << blend->getNumberOfFrames() << endl;

        return blend;
    }
}