#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    string temp;
    cin>>temp;
    string s,e;
    for(int i=0;i<temp.size();i++){
        if(temp[i] == '*'){
            s = temp.substr(0,i);
            e = temp.substr(i+1);
        }
    }
    reverse(e.begin(), e.end());
    while(t--){
        string q;
        cin>>q;
        if (q.size() < s.size() + e.size()) {
            cout << "NE\n";
            continue;
        }
        bool flag = true;
        for(int i=0;i<s.size();i++){
            if(q[i] != s[i]){
                flag = false;
                cout<<"NE\n";
                break;
            }
        }
        if(!flag) continue;
        reverse(q.begin(), q.end());
        for(int i=0;i<e.size();i++){
            if(q[i] != e[i]){
                flag = false;
                cout<<"NE\n";
                break;
            }
        }
        if(flag){
            cout<<"DA\n";
        }
        
    }

}
