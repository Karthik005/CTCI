#include "../../DataStructures/DataStructures.hpp"
#include "../../DataStructures/LinkedListAdv.cpp"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


void ll_bst(b_node<int>* root, vector<LinkedListAdv<int>>& ll_list) {
    if (root == nullptr) return;

    queue<b_node<int>*> bst_que;
    queue<int> dpt_que;

    LinkedListAdv<int> cur_lst;

    bst_que.push(root);
    dpt_que.push(0);

    while(!bst_que.empty()) {
        b_node<int>* cur_node = bst_que.front();
        int cur_dpt = dpt_que.front();
        bst_que.pop();
        dpt_que.pop();
        cur_lst.insert_end(cur_lst.create_node(cur_node->data));

        if (dpt_que.empty() || 
            dpt_que.front() > cur_dpt) {
            ll_list.push_back(cur_lst);
            cur_lst = LinkedListAdv<int>();
        }

        if (cur_node->left != nullptr) {
            bst_que.push(cur_node->left);
            dpt_que.push(cur_dpt+1);
        }

        if (cur_node->right != nullptr) {
            bst_que.push(cur_node->right);
            dpt_que.push(cur_dpt + 1);
        }
    }
}

b_node<int> *create_emplace(int val)
{
    b_node<int>* new_node = new b_node<int>(val);
    return new_node;
}

b_node<int> *get_b_tree(std::vector<int> sort_arr, int start_ind, int end_ind)
{
    if (start_ind > end_ind)
        return nullptr;

    int mid_ind = (start_ind + end_ind) / 2;
    // std::cout << mid_ind << std::endl;
    b_node<int> *root = create_emplace(sort_arr[mid_ind]);
    if (start_ind < end_ind)
    {
        root->left = get_b_tree(sort_arr, start_ind, mid_ind - 1);
        root->right = get_b_tree(sort_arr, mid_ind + 1, end_ind);
    }

    return root;
}

int main() {
    std::vector<int> alpha{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> beta{1, 2, 3, 4, 5, 6, 7};
    // b_node<int> *a = get_b_tree(alpha, 0, 7);
    b_node<int> *b = get_b_tree(beta, 0, 6);
    vector<LinkedListAdv<int>> llist;
    ll_bst(b, llist);
    for(auto& x : llist) {
        x.printList();
    }
}