#include<iostream>
#include<string>
#include<set>
using namespace std;

bool all_unique_map(string s){
    set<char> char_map;

    for(int i=0; i<s.size(); ++i){
        if (char_map.find(s[i]) == char_map.end()){
            char_map.insert(s[i]);
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = argv[1];
    cout<<"Contains all unique: " <<all_unique_map(s)<<endl;
    return 0;
}
