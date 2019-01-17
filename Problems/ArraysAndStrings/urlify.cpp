#include<iostream>
#include<deque>
#include<string>
#include<stdlib.h>
#include<string.h>

using namespace std;

void insert_string_at_index(char* arr, int ind, string s){
    for (int i = 0; i<s.length(); ++i){
        arr[ind+i] = s[i];
    }
}

char pop_back(deque<char>& que){
    char c = que[que.size() -1];
    que.pop_back();
    return c;
}

void urlify(char* s, int true_size){
    deque<char> que;
    char cur_char;
    int ind=0;

    while(ind < true_size){
        // cout<<ind<<endl;
        if (que.size() == 0){
            if (s[ind] != '_'){
                cout<<"Here index"<<ind<<endl;
                ++ind;
                continue;
            } else {
                cur_char = s[ind];
            }
        } else{
            cout<<"Here it reaches"<<endl;
            cur_char = pop_back(que);
            que.push_front(s[ind]);
        }
        
        cout<<cur_char<<endl;
        if (cur_char == '_'){
            que.push_front(s[ind+1]);
            if (ind+2 < true_size) que.push_front(s[ind+2]);
            insert_string_at_index(s, ind, "%20");
            cout<<"Size is "<<que.size()<<endl;
            ind+=3;
        }else{
            s[ind] = cur_char;
            ind++;
        }
    }
    while(que.size() >0){
        cur_char =  pop_back(que);
        if (cur_char == '_'){
            insert_string_at_index(s, ind, "%20");
            ind+=3;
        }
        else{
            s[ind] = cur_char;
            ind++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int true_size = atoi(argv[2]);
    string st = argv[1];
    char s[st.size()+50] = {0};
    strcpy(s, argv[1]);
    urlify(s,  true_size);
    cout << "URLIFIED: " << s << endl;
    return 0;
}