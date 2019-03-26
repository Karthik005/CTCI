

#ifndef TREE_NODE
#define TREE_NODE

#include <vector>

template<typename T>
struct t_node{
    T data;
    vector<T> children;
    
    t_node(T data_val) {
        data = data_val;
    }
};


#endif