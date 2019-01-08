#if !defined(__ABSTRACT_SORTER__)
#define __ABSTRACT_SORTER__

#include <vector>
class AbstractSorter
{
  private:
    /* data */
  public:
    AbstractSorter(/* args */){};
    virtual std::vector<int> sort(std::vector<int>) = 0;
    ~AbstractSorter(){};
};

#endif // __ABSTRACT_SORTER__



