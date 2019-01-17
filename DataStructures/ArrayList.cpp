#include<iostream>
#include"DataStructures.hpp"

using namespace std;

template <typename T>
ArrayList<T>::ArrayList(){
    this->array = new T[1];
    this->size = 0;
    this->max_size = 1;
}

template <typename T>
ArrayList<T>::ArrayList(int size)
{
    this->array = new T[size];
    this->size = 0;
    this->max_size = size;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] this->array;
}

template <typename T>
void ArrayList<T>::append(T value)
{
    if (this->size == this->max_size){
        /*Double the array size and copy*/
        cout<<"Doubling";
        T* old_arr = this->array;
        this->array = new T[max_size*2];
        for (int i=0; i<size; ++i){
            this->array[i] = old_arr[i];
        }
        this->max_size = max_size*2;
        delete[] old_arr;
        cout<<"Max size "<<this->max_size<<endl;
    }
    
    this->array[this->size] = value;
    this->size++;
}

template <typename T>
bool ArrayList<T>::search(T value)
{
    for(int i = 0; i<this->size; ++i){
        if  (this->array[i] == value) return true;
    }
    return false;
}

template <typename T>
void ArrayList<T>::printList()
{
    for (int i = 0; i < this->size; ++i)
    {
        cout<<this->array[i]<<" ";
    }
    cout<<endl;
}