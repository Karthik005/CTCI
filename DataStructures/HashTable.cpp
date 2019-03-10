#include <tuple>
#include <vector>
#include <iostream>
using namespace std;


template <typename Key, typename Val>
class HashTable{
    typedef unsigned uint;

    public:
      class HashFunction
      {
          public:
          typedef unsigned uint;
          virtual uint operator()(const Key &keyval) const = 0;
          virtual ~HashFunction(){};
      };

    private:
      vector<tuple<Key, Val>> *array_;
      const HashFunction *func_;
      uint size_;

    public:
      HashTable(const uint &size, const HashFunction &func) : func_{&func}, size_{size}, array_{new vector<tuple<Key, Val>>[size]} {}

      Val &operator[](const Key &key)
      {
          uint hash_val = (*func_)(key);
          cout << hash_val <<endl;
          for (auto &x : array_[hash_val])
          {
              if (get<0>(x) == key)
              {
                  return get<1>(x);
              }
          }

          tuple<Key, Val> new_tup;
          get<0>(new_tup) = key;
          vector<tuple<Key, Val>> &v_ref = array_[hash_val];
          v_ref.push_back(new_tup);
          return get<1>(v_ref[v_ref.size() - 1]); 
    }

    ~HashTable() {
        delete[] array_;
        delete func_;
    }
};

class SampleHash : public HashTable<int, int>::HashFunction {
    unsigned operator()(const int &keyval) const {
        cout << "aksdfhka";
        return keyval+24;
    }

};




int main()
{
    HashTable<int, int>::HashFunction *hash_fun = new SampleHash();
    HashTable<int, int> hash_table(100, *hash_fun);
    hash_table[6] = 6;
    cout << "value is " << hash_table[6] <<endl;
}