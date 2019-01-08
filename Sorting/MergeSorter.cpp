#include<vector>
#include<iostream>
#include"MergeSorter.h"
using namespace std;
MergeSorter::MergeSorter(/* args */)
{
}

std::vector<int>
MergeSorter::sort(std::vector<int> src_vec)
{
    std::vector<int>& src_vec_ref = src_vec;
    mergeSort(src_vec_ref, 0, src_vec.size()-1);
    return src_vec;
}

void 
MergeSorter::merge(std::vector<int>& src_vec, int low, int mid, int high){
    
    int low_arr[mid-low+1];
    int hi_arr[high-mid];
    int l_in = 0, h_in = 0;
    for(int i = 0; i < mid-low+1; i++)
    {
        low_arr[i] = src_vec[low+i];
    }
    
    for(int i = 0; i < high-mid; i++)
    {
        hi_arr[i] = src_vec[mid+i+1];
    }
    
    for(int i = low; i <= high; i++)
    {
        if ((low_arr[l_in] <= hi_arr[h_in] || h_in > high-mid-1) 
             && l_in < mid-low+1){
            src_vec[i] = low_arr[l_in];
            l_in++;
        }
        else {
            src_vec[i] = hi_arr[h_in];
            h_in++;
        }

    }

}

void MergeSorter::mergeSort(std::vector<int>& src_vec, int low, int high)
{
    if (low == high){
        return;
    }
    int mid = ((high+low) / 2);
    mergeSort(src_vec, low, mid);
    mergeSort(src_vec, mid+1, high);
    merge(src_vec, low, mid, high);
    return;
}

MergeSorter::~MergeSorter()
{
}