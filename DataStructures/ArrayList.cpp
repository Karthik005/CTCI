#include<iostream>
#include <initializer_list>
#include <iostream>

template<typename T>
class ArrayList {
    typedef unsigned int uint;
    
    private:
    T *array_;
    uint size_;
    uint max_size_;

    void resize(const uint& new_size){
        T *temp = array_;
        array_ = new T[new_size];
        uint i = 0;
        for (const T& x : temp) {
            array_[i] = x;
            i++;
        }
        max_size_ = new_size;
        delete[] temp;
    }


    public:
    ArrayList(): 
        size_{0}, max_size_{1}, array_{new T[1]} {} 
    
    ArrayList(const std::initializer_list<T>& list): 
        size_{list.size}, max_size_{list.size}, array_{new T[list.size]} {}
    
    ArrayList(const ArrayList<T> &list) : 
        size_{list.size()}, max_size_{list.max_size()}, array_{new T[list.max_size()]} {}

    void operator=(const ArrayList<T> &list) {
        size_ = list.size();
        max_size_ = list.max_size();
        array_ = new T[list.max_size()];
    }

    uint size() const { return size_;}

    uint max_size() const { return max_size_;}

    T& operator[](const uint& index) {
        return array_[index];
    }

    void push_back(const T& value) {
        if (size_ == max_size_) {
            resize(max_size_*2);
        }
        array_[size_] = value;
        size_++;
    }

    void pop() {
        if (size_ == 0) {
            throw std::out_of_range("Size of ArrayList object is 0");
        }
        size--;
        if (size_ == max_size_/2) {
            resize(max_size_/2);
        }
    }



};

/*********************************
 * Compiler errors hit
 * PS F:\Excelsior\GoDev\Code\DataStructures> g++ .\ArrayList.cpp -c
PS F:\Excelsior\GoDev\Code\DataStructures> g++ .\ArrayList.cpp -c
.\ArrayList.cpp: In member function 'void ArrayList<T>::size() const':
.\ArrayList.cpp:41:32: error: return-statement with a value, in function returning 'void' [-fpermissive]
     void size() const { return size_;}
                                ^~~~~
.\ArrayList.cpp: In member function 'void ArrayList<T>::max_size() const':
.\ArrayList.cpp:43:36: error: return-statement with a value, in function returning 'void' [-fpermissive]
     void max_size() const { return max_size_;}
                                    ^~~~~~~~~
.\ArrayList.cpp: In member function 'void ArrayList<T>::push_back(const T&)':
.\ArrayList.cpp:50:9: error: 'array' was not declared in this scope
         array[current_index_] = value;
         ^~~~~
.\ArrayList.cpp:50:9: note: suggested alternative: 'array_'
         array[current_index_] = value;
         ^~~~~
         array_
PS F:\Excelsior\GoDev\Code\DataStructures> g++ .\ArrayList.cpp -c
.\ArrayList.cpp: In member function 'void ArrayList<T>::size() const':
.\ArrayList.cpp:41:32: error: return-statement with a value, in function returning 'void' [-fpermissive]
     void size() const { return size_;}
                                ^~~~~
.\ArrayList.cpp: In member function 'void ArrayList<T>::max_size() const':
.\ArrayList.cpp:43:36: error: return-statement with a value, in function returning 'void' [-fpermissive]
     void max_size() const { return max_size_;}
                                    ^~~~~~~~~
.\ArrayList.cpp: In member function 'T& ArrayList<T>::operator[](const uint&)':
.\ArrayList.cpp:46:16: error: 'array' was not declared in this scope
         return array[index];
                ^~~~~
.\ArrayList.cpp:46:16: note: suggested alternative: 'array_'
         return array[index];
                ^~~~~
                array_
.\ArrayList.cpp: In member function 'void ArrayList<T>::push_back(const T&)':
.\ArrayList.cpp:50:9: error: 'array' was not declared in this scope
         array[current_index_] = value;
         ^~~~~
.\ArrayList.cpp:50:9: note: suggested alternative: 'array_'
         array[current_index_] = value;
         ^~~~~
         array_
PS F:\Excelsior\GoDev\Code\DataStructures> g++ .\ArrayList.cpp -c
.\ArrayList.cpp: In member function 'T& ArrayList<T>::operator[](const uint&)':
.\ArrayList.cpp:46:16: error: 'array' was not declared in this scope
         return array[index];
                ^~~~~
.\ArrayList.cpp:46:16: note: suggested alternative: 'array_'
         return array[index];
                ^~~~~
                array_
.\ArrayList.cpp: In member function 'void ArrayList<T>::push_back(const T&)':
.\ArrayList.cpp:50:9: error: 'array' was not declared in this scope
         array[current_index_] = value;
         ^~~~~
.\ArrayList.cpp:50:9: note: suggested alternative: 'array_'
         array[current_index_] = value;
         ^~~~~
         array_
PS F:\Excelsior\GoDev\Code\DataStructures> g++ .\ArrayList.cpp -c
.\ArrayList.cpp: In member function 'void ArrayList<T>::push_back(const T&)':
.\ArrayList.cpp:50:9: error: 'array' was not declared in this scope
         array[current_index_] = value;
         ^~~~~
.\ArrayList.cpp:50:9: note: suggested alternative: 'array_'
         array[current_index_] = value;
         ^~~~~
*************************************************/