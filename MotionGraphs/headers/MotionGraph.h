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
        virtual ~Edge() {}

        virtual Vertex* get_target();
        float get_weight();
        Animation get_motion(Vertex* src);
        pair<int,int> get_frames();

    private:
        Vertex* target;
        int frame_i, frame_j;
        float weight;
    };

    class MotionGraph {
    public:
        MotionGraph(map<string, Animation*> anim_list, Skeleton* sk, int k, float *progress);
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
        pair<Vertex*, Edge*> head;
        map<Vertex*, vector<Edge>> G;
    };
}