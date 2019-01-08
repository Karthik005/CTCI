#include<vector>
#include"AbstractSorter.h"


class MergeSorter: public AbstractSorter
{
private:
  void merge(std::vector<int> &src_vec, int low, int mid, int high);
  void mergeSort(std::vector<int> &src_vec, int low, int high);

public:
    MergeSorter(/* args */);
    std::vector<int> sort(std::vector<int> src_vec);
    ~MergeSorter();
};
