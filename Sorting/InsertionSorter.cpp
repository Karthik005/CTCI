#include<vector>
#include "InsertionSorter.h"

InsertionSorter::InsertionSorter()
{
}

std::vector<int> 
InsertionSorter::sort(std::vector<int> src_vec){

    if (src_vec.size() <=1){
        return src_vec;
    }
    
    int dec, key, aux;

    for (size_t i = src_vec.size() >= 2 ? 1 : 0; i < src_vec.size(); i++)
    {
        key = src_vec[i];
        dec = i-1;
        while (key < src_vec[dec] && dec > -1){
            src_vec[dec+1] = src_vec[dec];
            dec--;
        }
        src_vec[dec+1] = key;
    }
    return src_vec;
}


InsertionSorter::~InsertionSorter()
{
}