#include"DataStructures.hpp"
#include<iostream>
template <typename T>
node<T>* LinkedList<T>::createNode(T value){
    node<T>* newNode = new node<T>();
    newNode->val = value;
    newNode->next=NULL;
    return newNode;
}

template <typename T>
void LinkedList<T>::insertEnd(node<T>* nodeval){
    node<T>* iter = root;
    if (iter == NULL){
        root = nodeval;
        return;
    }
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = nodeval;
}

template <typename T>
void LinkedList<T>::insertBeginning(node<T> *nodeval)
{
    nodeval->next = root;
    root = nodeval;
}

template <typename T>
bool LinkedList<T>::deleteNodeWithVal(T value){
    if (root->val == value){
        deleteNext(NULL);
        return true;
    }
    node<T>* iter = root;
    while(iter!=NULL && iter->next != NULL){
        if (iter->next->val == value){
            deleteNext(iter);
            return true;
        }
    }
    return false;
}

template <typename T>
bool LinkedList<T>::search(T val){
    node<T>* iter = root;
    while (iter != NULL){
        if (iter->val == val){
            return true;
        }
        iter = iter->next;
    }
    return false;
}

template <typename T>
LinkedList<T>::LinkedList(){
    root = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    deleteDownNodes(root);
    delete(root);
}

template<typename T>
void deleteDownNodes(node<T>* root_node){
    if (root_node->next == NULL){
        return;
    }
    deleteDownNodes(root_node->next);
    delete root_node->next;
}

template <typename T>
void LinkedList<T>::printList(){
    node<T>* iter = root;
    while(iter != NULL){
        std::cout<<iter->val<<" "<<std::endl;
        iter = iter->next;
    }
}

template<typename T>
node<T>* LinkedList<T>::getRoot(){
    return root;
}

template <typename T>
void LinkedList<T>::deleteNext(node<T> *nodeval){
    node<T> *tmp;
    if (nodeval == NULL){
        tmp = root;
        root = root->next;
        delete tmp;
        return;
    }
    tmp = nodeval->next;
    if (tmp != NULL){
        nodeval->val = tmp->val;
        nodeval->next = tmp->next;
    }
    delete tmp;
}