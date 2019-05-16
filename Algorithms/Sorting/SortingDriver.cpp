#include "AbstractSorter.hpp"
#include "InsertionSorter.hpp"
#include "MergeSorter.hpp"
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
    AbstractSorter<int> *sorteri = new InsertionSorter<int>();
    AbstractSorter<int> *sorterm = new MergeSorter<int>;

    for(size_t i = 0; i < src_vec.size(); i++)
    {
        src_vec[i] = atoi(argv[2+i]);
    }

    std::vector<int> merg_vec(src_vec);
    std::vector<int> merg_vec_rev(src_vec);
    std::vector<int> src_vec_rev(src_vec);

    sorteri->sort(src_vec);
    printSortedVec("Insertion sorted:", src_vec);
    
    sorteri->sort(src_vec_rev, true);
    printSortedVec("Insertion sorted rev:", src_vec_rev);
    
    sorterm->sort(merg_vec);
    printSortedVec("Merge sorted:", merg_vec);
    
    sorterm->sort(merg_vec_rev, true);
    printSortedVec("Merge sorted rev:", merg_vec_rev);

    return 0;
}

