#include<vector>

using namespace std;


template<typename T>
struct g_node {
    T value;
    vector<g_node<T> *> adj_list;
    vector<int> w_list;

    void push_node(g_node * neighbr, int weight=1) {
        adj_list.push_back(neighbr);
        w_list.push_back(weight);
    }

};

template<typename T>
class Graph {
    private:
    vector<g_node<T>*> nodes;
    
    public:
    
    g_node * create_node(T value) {
        g_node * ret_node = new g_node<T>();
        ret_node->value = value;
        return ret_node;
    }

    void add_node(g_node * node) {
        nodes.push_back(node);
    }

    ~Graph() {
        for (const auto& x : nodes) {
            delete x;
        }
    }
}
