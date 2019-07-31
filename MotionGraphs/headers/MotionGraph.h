#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>

#include "Animation.h"
#include "blending.h"
#include "Utils.h"

using namespace std;

namespace mograph {
    class Vertex {
    public:
        Vertex(string name, Animation* motion, string action = "Undefined");
        Animation* get_anim();
        string get_name();
        string get_action();

    private:
        string v_name;
        string v_action;
        Animation* anim;
    };

    class Edge {
    public:
        Edge(Vertex* target, int i, int j, float d);
        ~Edge() {
            // delete motion;
        }

        virtual Vertex* get_target();
        float get_weight();
        Animation get_motion(Vertex* src);
        pair<int,int> get_frames();

        bool operator < (const Edge& e) const {
            return this->weight< e.weight;
        }

    private:
        Vertex* target;
        int frame_i, frame_j;
        float weight;
        // Animation* motion; // either a transition between motion or piece of original clip
    };

    class MotionGraph {
    public:
        MotionGraph(vector<pair<string,Animation*>> anim_list, Skeleton* sk, int k, float *progress);
        void add_edge(Vertex* src, Edge e);
        Animation* get_current_motion();
        void move_to_next();
        pair<Vertex*, Edge*> get_head();
        map<Vertex*, vector<Edge>> get_graph();

        ~MotionGraph() {
            delete head.first;
            delete head.second;
            for (auto item:G){
                delete item.first;
                // for (auto v_item:item.second) delete v_item;
            }
        }

    private:
        Edge* get_min_edge();
        pair<Vertex*, Edge*> head, next_candidate;
        map<Vertex*, vector<Edge>> G;
    };
}