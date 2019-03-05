#ifndef DATASTRUCT
#define DATASTRUCT

#define HASH_SIZE 100

template <typename T>
struct node
{
    T val;
    struct node<T> *next;
};

template <typename T>
class LinkedList
{
  protected:
    node<T> *root;
    void deleteNext(node<T> *nodeval);

  public:
    node<T> *createNode(T);
    void insertEnd(node<T> *nodeval);
    void insertBeginning(node<T> *nodeval);
    bool deleteNodeWithVal(T val);
    bool search(T val);
    void printList();
    node<T> *getRoot();
    LinkedList();
    ~LinkedList();
};

// template <typename K, typename v>
// class HashTable
// {
//   private:
//     LinkedList<V>* linkedList[HASH_SIZE];
//     int (*hashFunc)(const K&);

//   public:
//     void set(K key, V value);
//     bool search(K key)
//     HashMap();
//     ~HashMap();
// };

template <typename T>
class ArrayList
{
  private:
    T* array;
    int max_size;
    int size;
  public:
    void append(T value);
    bool search(T val);
    void printList();
    ArrayList();
    ArrayList(int size);
    ~ArrayList();
};

#endif

