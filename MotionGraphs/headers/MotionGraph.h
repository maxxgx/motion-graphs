#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include "Animation.h"

using namespace std;

class Vertex {
public:
    string v_name;
    Animation* anim;
};

class Edge {
public:
    virtual Animation get_motion() = 0;

    Vertex* v1, v2;
    int frame_i, frame_j;
};

class Transition: public Edge {
public:
    Animation get_motion();
};

class OriginalTran: public Edge {
public:
    Animation get_motion();
};

class MotionGraph {
public:
    void add_edge(Vertex* v1, Vertex* v2, Edge e);

    Map<Vertex, vector<Edge>> G;
};