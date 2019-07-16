#include "../headers/blending.h"


namespace blending {
    vector<PointCloud*> getCumulativePC(Animation *anim, Skeleton *sk, int k)
    {
        vector<PointCloud*> cloud_total;
        int num_frames = anim->getNumberOfFrames();
        cloud_total.reserve(num_frames);
        // Pose starts at 1
        for (int i = 0; i < num_frames; i++) {
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
        vector<PointCloud*> cloud_a_total = getCumulativePC(anim_a, sk, k);
        vector<PointCloud*> cloud_b_total = getCumulativePC(anim_b, sk, k);
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
        distance_mat.reserve(num_frames_a*num_frames_b);
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
            // cout << "progress = " << progress << endl;
        }

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


    Animation* blend(Animation *anim_a, Animation *anim_b, int Ai, int Bj, int k)
    {
        
    }
}