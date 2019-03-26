#include<vector>

template <typename T>
struct b_node
{
    T data;
    b_node<T> * left;
    b_node<T> * right;

    b_node(T data_val)
    {
        data = data_val;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BinarySearchTree {
    private:
    b_node<T> * root_;
    size_t size_;

    bool search_rec(T value, b_node<T> * parent, b_node<T> * store_nearest) {
        if (parent == nullptr) return false;
        if (value == parent->data ) {
            store_nearest = parent;
            return true;
        } else if (parent->left == nullptr && parent->right== nullptr) {
            store_nearest = parent;
            return false;
        } else if (value < parent->data) {
            if (!search_rec(value, parent->left, store_nearest)) {
                
            }
        } else if (value > parent->data) {
            return search_rec(value, parent->right, store_nearest);
        }
    }

    void insert_rec(T value, b_node<T>)
    {

    }

  public:
    BinarySearchTree() {
        size_ = 0;
        root_ = nullptr;
    }



};