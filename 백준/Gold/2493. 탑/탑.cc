#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
        cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a;
    cin>>a;
    stack<pair<int, int>>s; //높이, 인덱스
    for(int i=0;i<a;i++){
        int height, index;
        cin>>height;
        index = i+1;
        while(!s.empty()){
            if(s.top().first >height){
                cout<<s.top().second<<" ";
                break;
            }
                            s.pop();
        }

        if(s.empty()){
            cout<<"0"<<" ";
        }
        s.push({height, index});
    }




}