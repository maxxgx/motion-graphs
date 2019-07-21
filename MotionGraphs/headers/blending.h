#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>
#include <functional>
#include <math.h>

#include "PointCloud.h"
#include "Skeleton.h"
#include "Animation.h"

using namespace std;

/**
 * Contains various functions for blending two motions.
 */
namespace blending {
    /**
     * Returns cumulative PointCloud (sum of individual PC over window k) for each frame
     * 
     * @param  {Animation*} anim      : 
     * @param  {Skeleton*} sk         : 
     * @param  {int} k                : 
     * @return {vector<PointCloud>*}  : 
     */
    vector<PointCloud*> getCumulativePC(Animation *anim, Skeleton *sk, int k);

    /**
     * Computes the distance matrix between two motions (A and B), given a skeleton and window size k.
     * 
     * @param  {Animation*} anim_a    : 
     * @param  {Animation*} anim_b    : 
     * @param  {Skeleton*} sk         : 
     * @param  {int} k                : 
     * @param  {float} progress       : 
     * @return {pair<vector<float>,}  : 
     */
    pair<vector<float>, pair<float,float>> compute_distance_matrix(Animation *anim_a, Animation *anim_b, Skeleton *sk, int k, float *progress);

    /**
     * Checks if the element in index is local minima (Von Neumann neighborhood).
     * 
     * @param  {vector<float>} D : the matrix as 1D vector
     * @param  {int} w           : width of the matrix
     * @param  {int} h           : height of the matrix
     * @param  {int} index       : 
     * @return {bool}            : whether item at index is local minima
     */
    bool is_local_minima(vector<float> D, int h, int w, int index);

    /**
     * Find local minima of the a matrix (represented by a 1D vector)
     * 
     * @param  {vector<float>} D : distance vector
     * @param  {int} w           : width of the matrix
     * @param  {int} h           : height of the matrix
     * @return {vector<int>}     : list of index that are local minima.
     */
    vector<int> find_local_minima(vector<float> D, int w, int h);

    /**
     * Blends pose A with pose B. Linear interpolation of root position and slerp of rotations.
     * 
     * @param  {Pose*} a : pose A.
     * @param  {Pose*} b : pose B.
     * @return {Pose*}   : the interpolated pose.
     */
    Pose* blend_pose(Pose* a, Pose* b, float t);

    /**
     * Blends motion A to motion B, interpolation between frames Ai-k to Ai+k with Bj-k to Bj+k.
     * 
     * @param  {Animation*} anim_a : motion A
     * @param  {Animation*} anim_b : motion B
     * @param  {int} Ai            : selected frame from motion A
     * @param  {int} Bj            : selected frame from motion B
     * @param  {int} k             : window size
     * @return {Animation*}        : blended animation of A and B
     */
    Animation* blend_anim(Animation *anim_a, Animation *anim_b, int Ai, int Bj, int k);
}
