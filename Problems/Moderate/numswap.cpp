#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a+b;
    b = a-b;
    a = a-b;
}

int main() {
    int a = 8;
    int b = 9;
    swap(a,b);
    cout <<a<<","<<b<<endl;
}