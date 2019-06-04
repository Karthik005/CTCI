#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<typename T>
void print_vec(vector<T> vec) {
    for (const auto& i : vec) {
        cout << i <<", ";
    }
    cout << endl;
}

template <typename T>
void print_matrix(vector<vector<T>> vec)
{
    for (auto &i : vec)
    {
        print_vec(i);
    }
    cout << endl;
}
