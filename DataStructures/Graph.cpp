#include<vector>

using namespace std;

template <typename T> struct v_pair;

template<typename T>
struct g_node {
    T value;
    vector<v_pair<T>> adj_list;

    void push_node(g_node * neighbr, int weight=1) {
        adj_list.push_back(v_pair<T>{neighbr, weight});
    }

};

template<typename T>
struct v_pair {
    g_node<T>* vert;
    int dist;
};

template<typename T>
class Graph {
    private:
    vector<g_node<T>*> nodes;
    
    public:
    
    g_node<T> * create_node(T value) {
        g_node<T> * ret_node = new g_node<T>();
        ret_node->value = value;
        return ret_node;
    }

    void add_node(g_node<T> * node) {
        nodes.push_back(node);
    }

    g_node<T> * at(int index) {
        return nodes[index];
    }

    g_node<T> operator[](int index){
        return nodes[index];
    }

    int size() {
        return nodes.size();
    }

    ~Graph() {
        for (const auto& x : nodes) {
            delete x;
        }
    }
};
