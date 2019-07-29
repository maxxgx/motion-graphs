#include "../headers/MotionGraph.h"

namespace mograph {
    //Constructor
    Vertex::Vertex(string name, Animation* motion, string action)
    {
        this->v_name = name;
        this->v_action = action;
        this->anim = motion;
    }

    Edge::Edge(Vertex* target, int i, int j, float d)
    {
        this->target = target;
        this->frame_i = i;
        this->frame_j = j;
        this->weight = d;
    }

    Animation* Vertex::get_anim()
    {
        return this->anim;
    }

    string Vertex::get_name()
    {
        return this->v_name;
    }

    string Vertex::get_action()
    {
        return this->v_action;
    }

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


    /* MotionGraph class */
    void MotionGraph::add_edge(Vertex* src, Edge e)
    {
        this->G[src].push_back(e);
    }

    void MotionGraph::move_to_next()
    {
        this->head.first = head.second->get_target();
        this->head.second = get_min_edge();
    }

    Edge* MotionGraph::get_min_edge()
    {
        Edge* min;
        float min_w = std::numeric_limits<float>::infinity();
        for (auto e:G[head.first]) {
            if (e.get_weight() < min_w) {
                min = new Edge(e.get_target(), e.get_frames().first, e.get_frames().second, e.get_weight());
                min_w = e.get_weight();
            }
        }
        return min;
    }

    Animation* MotionGraph::get_current_motion()
    {
        this->head.second = get_min_edge();
        // Vertex* tar = head.second->get_target();
        // Animation* tar_anim = head.second->get_target()->get_anim();
        // cout << "tar_anim size = " <<  this->head.second->get_target()->get_anim()->getNumberOfFrames() << endl;
        int i = this->head.second->get_frames().first;
        int j = this->head.second->get_frames().second;
        // cout << "Getting current motion: head.first = " << head.first->get_anim()->getNumberOfFrames() << 
            // ",head.second = " << head.second->get_target()->get_anim()->getNumberOfFrames() << endl;
        Animation* A = head.first->get_anim();
        Animation* B = head.second->get_target()->get_anim();
        return blending::blend_anim(A, B, i, j, 40);
    }

    pair<Vertex*, Edge*> MotionGraph::get_head()
    {
        return head;
    }

    map<Vertex*, vector<Edge>> MotionGraph::get_graph()
    {
        return G;
    }

    MotionGraph::MotionGraph(map<string, Animation*> anim_list, Skeleton* sk, int k, float *progress)
    {
        cout << "Creating mograph..." << endl;
        // Create vertex
        map<string, Vertex*> vert_map;
        for (auto A:anim_list) {
            vert_map[A.first] = new Vertex(A.first, A.second);
            if (head.first == NULL) {
                head.first = vert_map[A.first];
            }
            cout << "Adding vertex " << A.first <<endl;
        }
        cout << "Added " << vert_map.size() << " vertices..." << endl;

        map<string, set<string>> added_pairs;
        for (auto A:anim_list) {
            for (auto B:anim_list) {
                if (A.first != B.first &&
                    added_pairs[A.first].find(B.first) == added_pairs[A.first].end()
                    ){ // not same animation
                    auto dist_mat_range = blending::compute_distance_matrix(A.second, B.second, sk, k, progress);
                    int size_a = A.second->getNumberOfFrames();
                    int size_b = B.second->getNumberOfFrames();
                    if (size_a * size_b != dist_mat_range.first.size()) {
                        cout << "----------------------\tdist_mat size is different than num of frame" << endl;
                    } else
                    {
                         cout << "----------------------\t size == num of frame" << endl;
                    }
                    
                    vector<pair<int,int>> local_minimas = blending::find_local_minima(dist_mat_range.first, size_b, size_a);
                    cout << "----------------------\t local minima done" << endl;
                    vector<Edge> edges_a, edges_b;
                    for (auto l:local_minimas) {
                        int i = l.first, j = l.second;
                        cout << " i = " << i << ", j = " << j << endl; 
                        float d = dist_mat_range.first.at(i*size_b + j);
                        Edge e(vert_map[B.first], l.first, l.second, d);
                        edges_a.push_back(e);

                        Edge e_2(vert_map[A.first], l.second, l.first, d);
                        edges_b.push_back(e_2);
                    }
                    this->G[vert_map[A.first]].insert(this->G[vert_map[A.first]].end(), edges_a.begin(), edges_a.end());
                    this->G[vert_map[B.first]].insert(this->G[vert_map[B.first]].end(), edges_b.begin(), edges_b.end());

                    // flag A and B, B and A as inserted
                    added_pairs[A.first].insert(B.first);
                    added_pairs[B.first].insert(A.first);
                }
            }
        }
        
        for (auto v_es:G) {
            cout << "Added " << v_es.second.size() << " edges to vertex " << v_es.first << endl;
            int c = 0;
            for(auto e:v_es.second) {
                // cout << "\t\tEdge " << c << ": target = " << e.get_target() <<endl; c++;
            }
        }
        cout << "... end construction mograph." << endl;
    }
}