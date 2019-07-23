#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>

#include "Animation.h"
#include "blending.h"

using namespace std;

class Vertex {
public:
    Vertex(string name, Animation* motion, string action = "Undefined");
    Animation* get_anim();

private:
    string v_name;
    string v_action;
    Animation* anim;
};

class Edge {
public:
    Edge(Vertex* v1, Vertex* v2, int i, int j, float d);
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
    MotionGraph() {}
    void add_edge(Vertex* src, Edge e);
    Animation* get_current_motion();
    void move_to_next();
    Vertex* get_head();

    ~MotionGraph() {
        delete head;
        for (auto item:G){
            delete item.first;
            // for (auto v_item:item.second) delete v_item;
        }
    }

private:
    Edge* get_min_edge();
    Vertex* head;
    map<Vertex*, vector<Edge>> G;
};