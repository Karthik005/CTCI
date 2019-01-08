#include "AbstractSorter.h"
#include "InsertionSorter.h"
#include "MergeSorter.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

void printSortedVec(const char* prepend, const std::vector<int>& sorted_vec){
    std::cout << prepend;
    for (size_t i = 0; i < sorted_vec.size(); i++)
    {
        std::cout << sorted_vec[i] << " ";
    }
    std::cout << std::endl;
}


main(int argc, char const *argv[])
{
    std::vector<int> src_vec(atoi(argv[1]));
    InsertionSorter iSorter = InsertionSorter();
    MergeSorter mSorter = MergeSorter();
    for(size_t i = 0; i < src_vec.size(); i++)
    {
        src_vec[i] = atoi(argv[2+i]);
    }

    std::vector<int> isorted_vec(iSorter.sort(src_vec));
    std::vector<int> msorted_vec(mSorter.sort(src_vec));

    printSortedVec("Insertion sorted:", isorted_vec);
    printSortedVec("Merge sorted:", msorted_vec);

    return 0;
}

