#include "../headers/MotionGraph.h"

Vertex* Edge::get_target()
{
    return this->target;
}

float Edge::get_weight()
{
    return this->weight;
}

pair<int,int> Edge::get_frames()
{
    return make_pair(frame_i, frame_j);
}

Animation* Vertex::get_anim()
{
    return this->anim;
}

void MotionGraph::add_edge(Vertex* src, Edge e)
{
    this->G[src].push_back(e);
}

void MotionGraph::move_to_next()
{
    this->head = this->get_min_edge()->get_target();
}

Edge* MotionGraph::get_min_edge()
{
    vector<Edge> edges = G[head];
    Edge* min;
    float min_w = std::numeric_limits<float>::infinity();
    for (auto e:edges) {
        if (e.get_weight() < min_w) {
            min = &e;
            min_w = e.get_weight();
        }
    }
    return min;
}

Animation* MotionGraph::get_current_motion()
{
    Edge* e = this->get_min_edge();
    return blending::blend_anim(head->get_anim(), e->get_target()->get_anim(), 
        e->get_frames().first, e->get_frames().second, 40);
}