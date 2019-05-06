#include <stack>
#include <iostream>

using namespace std;

void move_disc(stack<int>& one, stack<int>& two) {
    two.push(one.top());
    one.pop();
}

void move_ndiscs(stack<int>& start, stack<int>& mid, stack<int>& end, int n)
{
    cout << "enters here" << endl;
    if (n == 0) return;
    else if (n == 1) {
        move_disc(start, end);
        return;        
    }

    move_disc(start, mid);
    move_ndiscs(end, mid, start, n-1);
    move_disc(mid, end);
    move_ndiscs(start, mid, end, n-1);

}

int main() {
    stack<int> start, mid, end;
    for (int i = 1; i < 5; ++i) {
        start.push(i);
    }
    move_ndiscs(start, mid, end, 4);
    while(!end.empty()) {
        cout << end.top() <<" ";
        end.pop();
    }
    cout <<endl;
}