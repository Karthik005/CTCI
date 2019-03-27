#include<iostream>
#include<queue>

#include<DataStructures.hpp>

using namespace std;

template<typename T>
class BinaryMinHeap {
    private:
    b_node<T> * root_;
    size_t size_;


    b_node<T> * find_right_most(bool return_parent, b_node<T> * current_node) {
        
    }

    b_node<T> * bubble_up(b_node<T> * bubble_node, b_node<T> *current_node)
    {
        if (current_node == nullptr)
            return false;
        
        if (current_node->left == bubble_node) {
            
        }
    }

    b_node<T> * insert_rec(T value, b_node<T> * current_node) {
        if (current_node == nullptr) {
            size_++;
            return create_node(value);
        } else if (value < current_node->data) {
            current_node->left = insert_rec(value, current_node->left);
        } else if (value > current_node->data) {
            current_node -> right = insert_rec(value, current_node->right);
        }
        return current_node;
    }

    void delete_children(b_node<T> * current_node) {
        if (current_node == nullptr) {
            return;
        } else {
            delete_children(current_node->left);
            delete_children(current_node->right);
            delete current_node->left;
            delete current_node->right;
            return;
        }
    }

  public:
    BinarySearchTree() {
        size_ = 0;
        root_ = nullptr;
    }

    bool search(T value) {
        return search_rec(value, root_);
    }

    void insert(T value) {
        root_ = insert_rec(value, root_);
    }

    b_node<T> * create_node(T value) {
        return new b_node<T>(value);
    }

    ~BinarySearchTree(){
        delete_children(root_);
        delete root_;
    }

};