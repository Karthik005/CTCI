#include<iostream>
#include<vector>
#include<utility>
#include<stack>

using namespace std;

template<typename T>
void print_vec(const vector<T>& vec) {
    for (const auto& i : vec) {
        cout << i <<", ";
    }
    cout << endl;
}

template <typename T>
void print_matrix(const vector<vector<T>>& vec)
{
    for (const auto &i : vec)
    {
        print_vec(i);
    }
    cout << endl;
}

template <typename A,typename B>
void print_pair(const pair<A,B>& a) {
    cout << "(" << a.first <<"," << a.second << ")" <<endl;
}
