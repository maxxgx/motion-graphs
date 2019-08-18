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

    Edge* MotionGraph::get_min_edge()
    {
        if (G[head.first].size() < 0) {
            return NULL;
        }
        random_selector<> rnd_sel{};
    
        vector<Edge> valid;
        std::copy_if(begin(G[head.first]), end(G[head.first]), back_inserter(valid), 
            [&](Edge e) { return e.get_frames().first >= head.second->get_frames().second+k;});
        std::sort(begin(valid), end(valid));

        if (valid.size() > 0) {
            int top_pool = valid.size() / 20 + 1; // top 5%
            vector<Edge> top(begin(valid), begin(valid) + top_pool);
            //randomly select from top edges
            Edge e = rnd_sel(top);

            Edge* selected = new Edge(e.get_target(), e.get_frames().first, e.get_frames().second, e.get_weight());
            cout << "next_candidate tar = " << selected->get_target() << " | i = " << selected->get_frames().first << ", j = " << selected->get_frames().second << endl;
            return selected;
        } else {
            cout << "valid size < 0"<< ", head edge frames " << head.second->get_frames().first << "-" << head.second->get_frames().second << endl;
            return NULL;
        }
    }

    pair<Vertex*, Edge*> MotionGraph::get_head()
    {
        return head;
    }

    void MotionGraph::set_head(pair<Vertex*, Edge>& h)
    {
        this->head.first = h.first;
        this->head.second = &h.second;
    }

    map<Vertex*, vector<Edge>> MotionGraph::get_graph()
    {
        return G;
    }

    void MotionGraph::reset_head()
    {
        head = head_init_copy;
    }

    MotionGraph::MotionGraph(vector<pair<string,Animation*>> anim_list, Skeleton* sk, int k, float *progress)
    {
        this->k = k;
        cout << "Creating mograph..." << endl;
        // Create vertex
        for (auto A:anim_list) {
            vert_map[A.first] = new Vertex(A.first, A.second);
            if (head.first == nullptr) head.first = vert_map[A.first];
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

                    // Addint edges to vertex A and B
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
            // Close gaps between transition edges
            // vector<Edge> gaps;
            int c=0;
            for(auto e:v_es.second) {
                cout << "\t\tEdge " << c << ": target = " 
                << e.get_target() 
                << " | i-j = " << e.get_frames().first << "-" << e.get_frames().second
                <<endl; c++;
                // int i = e.get_frames().first;
                // int j = e.get_frames().second;
            }
        }
        head_init_copy = head;
        cout << "... end construction mograph." << endl;
    }

    Animation* MotionGraph::edge2anim(Vertex* src, Edge e)
    {
        Vertex* tar = e.get_target();

        int i = e.get_frames().first;
        int j = e.get_frames().second;
        
        // cout << "\tblending src: " <<  src
        //     << ", edge tar = "<<tar
        //     << ", i-j = " << i
        //     << "-" << j
        //     << ", w -> " << e.get_weight()
        //     << endl;

        // same animation 
        if (tar == src) { 
            return new Animation(src->get_anim()->getPosesInRange(i,j));
        } else {
            Animation* A = src->get_anim();
            Animation* B = e.get_target()->get_anim();
            return blending::blend_anim(A, B, i, j, k);
        }
    }

    Animation* MotionGraph::edge2anim(vector<pair<Vertex*, Edge>> edges)
    {
        vector<Pose*> poses;
        for (auto src_edge:edges) {
            vector<Pose*> cur_poses = edge2anim(src_edge.first, src_edge.second)->getAllPoses();
            poses.insert(end(poses), begin(cur_poses), end(cur_poses));
        }
        Animation* anim = new Animation(poses);
        return anim;
    }

    void print_traversal_path(vector<pair<Vertex*, Edge>> path) 
    {
        cout << "\nPath:\n" ;
        for (auto &v:path) {
            cout << "\t\tvisited node: " << v.first->get_name().substr(v.first->get_name().find_last_of("/"))
                << " --- target node :  " << v.second.get_target()->get_name().substr(v.second.get_target()->get_name().find_last_of("/"))
                << ", edge i-j = " << v.second.get_frames().first
                << "-" << v.second.get_frames().second
                << ", w -> " << v.second.get_weight()
                << endl;
        }
        cout << "total traversed nodes: " << path.size() << endl;
    }

    vector<pair<Vertex*, Edge>> MotionGraph::traverse_min_rand(float threshold)
    {
        vector<pair<Vertex*, Edge>> visited;
        // visited.push_back(make_pair(next_candidate.first, *next_candidate.second));

        set<Vertex*> visited_nodes;

        cout << "\n===============================\n" << endl;
        cout << "Graph traversal path:" << endl;
        cout << "head.first: " << head.first << ", target = " 
                // << head.second->get_target() 
                // << " | i-j = " << head.second->get_frames().first << "-" << head.second->get_frames().second
                <<endl;

        while (true) {
            // Select candidate for transition
            Edge* tran_candidate = nullptr;
            int head_anim_frame =  head.second == nullptr ? 1 : head.second->get_frames().second + k;
            
            int min_dist = std::numeric_limits<float>::max();
            if (head.second == nullptr) {
                random_selector<> rnd_sel{};
                Edge e = rnd_sel(this->G[head.first]);
                tran_candidate = new Edge(e);
            } else {
                for (Edge& e:this->G[head.first]) {
                    float w = e.get_weight();
                    if (visited_nodes.find(e.get_target()) == end(visited_nodes))
                        w *= 100;
                    if (w < min_dist && e.get_frames().first >= head_anim_frame + k) {
                        tran_candidate = &e;
                    }
                }
            }

            // cant find another transitoin point or visited all
            if (tran_candidate == nullptr || visited_nodes.size() == G.size()) {
                Edge final_edge(head.first, head.second->get_frames().second + k, head.second->get_target()->get_anim()->getNumberOfFrames(), -1);
                visited.push_back(make_pair(head.first, final_edge));
                break;
            }
            // gap between head and candidate
            if (head_anim_frame < tran_candidate->get_frames().first) {
                Edge gap(head.first, head_anim_frame, tran_candidate->get_frames().first - k, -1);
                visited.push_back(make_pair(head.first, gap));
            } 
            visited.push_back(make_pair(head.first, *tran_candidate));
            head.second = tran_candidate;
            if (head.second != nullptr) head.first = head.second->get_target();

            visited_nodes.insert(head.first);
        }

        print_traversal_path(visited);
        return visited;
    }

    vector<pair<Vertex*, Edge>> MotionGraph::traverse_sequential(vector<pair<string,Animation*>> anim_list, float threshold)
    {
    /**
     *  Algorithm:
     *  1. for each animation, get the next one in order
     *  2. filter the edges to next animation that meet the threshold
     *  3. select one of the best fit edges.
     */
        vector<pair<Vertex*, Edge>> trav;
        Edge* last_e = nullptr; 
        for (int i = 0; i < anim_list.size(); i++){
            // 1. select next
            Vertex* curr = this->vert_map[anim_list.at(i).first];
            Vertex* next = nullptr;
            try {
                next = this->vert_map[anim_list.at(i+1).first];
            } catch (std::out_of_range e) {
                next = nullptr;
            }

            cout << "curr = " << curr->get_name().substr(curr->get_name().find_last_of("/")) << endl;
            cout << "next = " << next << endl;

            // 2. filter edges
            vector<Edge> edges(G[curr]); // copy of all the edges
            edges.erase(
                std::remove_if(begin(edges), end(edges), [&] (Edge e) {
                    return e.get_target() != next;} ),
                    end(edges));

            edges.erase(
                std::remove_if(begin(edges), end(edges), [&] (Edge e) {
                if (last_e != nullptr) {
                    return last_e->get_frames().second + k > e.get_frames().first;
                } else
                    return false;}),
                end(edges));

            std::sort(begin(edges), end(edges));
            
            cout << "Sorted edges:" << endl;
            for (auto e:edges) 
                cout << "\t\tcurr node: " << curr->get_name().substr(curr->get_name().find_last_of("/"))
                << " --- target node :  " << e.get_target()->get_name().substr(e.get_target()->get_name().find_last_of("/"))
                << ", edge i-j = " << e.get_frames().first
                << "-" << e.get_frames().second
                << ", w -> " << e.get_weight()
                << endl;

            if (edges.size() > 0) {
                float top_perc = 0.2f; // top 20 %
                cout << "\n size of edges = " << edges.size() << ", ith = " << int(top_perc * edges.size()) << endl;
                float ith_val = edges.at(int(top_perc * edges.size())).get_weight();

                cout << "ith val = " << ith_val << endl;

                edges.erase(
                    std::remove_if(begin(edges), end(edges), [&] (Edge e) {return e.get_weight() >= ith_val && e.get_weight() > threshold;}),
                    end(edges));
                if (edges.size() <= 0) {
                    cout << "\nError: no edges to select... threshold too low" << endl;
                    return trav;
                }
                
                cout << "\nAfter selection:" << endl;
                for (auto e:edges) 
                    cout << "\t\tcurr node: " << curr->get_name().substr(curr->get_name().find_last_of("/"))
                    << " --- target node :  " << e.get_target()->get_name().substr(e.get_target()->get_name().find_last_of("/"))
                    << ", edge i-j = " << e.get_frames().first
                    << "-" << e.get_frames().second
                    << ", w -> " << e.get_weight()
                    << endl;

            // 3. select from the remaining
                random_selector<> rnd_sel{};
                Edge selected_e = rnd_sel(edges);
                cout << "selected w = " << selected_e.get_weight() << endl;            

                if (last_e == nullptr) { // first animation
                    Edge gap(curr, 1, selected_e.get_frames().first - k, -1);
                    trav.push_back(make_pair(curr, gap));
                    last_e = new Edge(selected_e);
                } else {
                    Edge gap(curr, last_e->get_frames().second + k, selected_e.get_frames().first - k, -1);
                    trav.push_back(make_pair(curr, gap));
                    last_e = new Edge(selected_e);
                }
                trav.push_back(make_pair(curr,selected_e));
            } else {
                cout << "\nError: no edges to select..." << endl;
            }

            if (next == nullptr) { // last animation
                cout << "next == null" << endl;
                // create anim to finish off the last animation
                int last_frame_e = last_e->get_frames().second;
                Edge gap(curr, last_frame_e+k, curr->get_anim()->getNumberOfFrames(), -1);
                trav.push_back(make_pair(curr, gap));
                cout << "breaking" << endl;
                break;
            }
            cout << "bottom loop" << endl;
        }
        cout << "Traversal done..." << endl;
        print_traversal_path(trav);
        return trav;
    }
}
