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
    typedef struct path_metrics{
        float avg=0.0f, max=0.0f, min=0.0f, sum=0.0f;
        int num_transitions=0;
    } path_metrics;


    typedef struct metrics{
        float avg=0.0f, max=0.0f, min=-1000.0f, sum=0.0f;
        int num_tot_edges=0, num_vertex=0;
        int max_num_edges=0, min_num_edges=-1;
        float avg_num_edge_per_vertex=0.f;
    } metrics;

    class Vertex {
    public:
        Vertex(string name, Animation* motion, string action = "Undefined");
        Animation* get_anim();
        string get_name();
        string get_action();
        void set_anim(Animation* anim);

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

    path_metrics get_path_metrics(vector<pair<Vertex*, Edge>> path);
    
    class MotionGraph {
    public:
        MotionGraph(vector<pair<string,Animation*>> anim_list, Skeleton* sk, int k, float *progress);
        void add_edge(Vertex* src, Edge e);
        pair<Vertex*, Edge*> get_head();
        void set_head(pair<Vertex*, Edge>& h);

        map<Vertex*, vector<Edge>> get_graph();
        void reset_head();

        Animation* edge2anim(Vertex* src, Edge e);
        Animation* edge2anim(Vertex* src, Edge e, Animation* A, Animation* B);
        Animation* edge2anim(vector<pair<Vertex*, Edge>> edges, map<int, int> *frame_to_edge);
        vector<pair<Vertex*, Edge>> traverse_min_rand(float threshold);
        vector<pair<Vertex*, Edge>> traverse_sequential(vector<pair<string,Animation*>> anim_list, float threshold);

        void update_motions(vector<pair<string,Animation*>> anim_list, Skeleton* sk, float *progress);
        void add_motions(vector<pair<string,Animation*>> anim_list, Skeleton* sk, float *progress);
        void remove_motions(vector<string> anim_list_to_remove);

        metrics get_metrics();

        ~MotionGraph() {
            delete head.first;
            // delete head.second;
            for (auto item:G){
                delete item.first;
                // for (auto v_item:item.second) delete v_item;
            }
        }

    private:
        Edge* get_min_edge();
        pair<Vertex*, Edge*> head = make_pair(nullptr, nullptr), 
                            next_candidate = make_pair(nullptr, nullptr), 
                            head_init_copy = make_pair(nullptr, nullptr);
        map<Vertex*, vector<Edge>> G;
        map<string, Vertex*> vert_map;
        int k;

        double tot_cpu_time = 0.0f;
        metrics graph_info;
        
        void update_graph_info();
    };
}