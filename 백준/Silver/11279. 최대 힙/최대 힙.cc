#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
    priority_queue<int>q;
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int temp;
        cin>>temp;
        if(temp == 0 && !q.empty()){
            cout<<q.top()<<"\n";
            q.pop();
        }else if(temp == 0 && q.empty()){
            cout<<"0"<<"\n";
        }else {
            q.push(temp);
        }
    }

}