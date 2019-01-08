#
#if !defined(__INSERTION_SORTER__)
#define __INSERTION_SORTER__
#include "AbstractSorter.h"
#include <vector>

class InsertionSorter: public AbstractSorter
{
  private:
  public:
    InsertionSorter();
    std::vector<int> sort(std::vector<int>);
    ~InsertionSorter();
};

#endif // __INSERTION_SORTER__

