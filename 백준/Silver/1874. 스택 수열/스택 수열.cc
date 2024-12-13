#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    vector<bool>check(n+1, true);
    int temp;
        queue<char>answer;
    cin>>temp;
    stack<int>seq;
    for(int i=1;i<=temp;i++){
        seq.push(i);
       //cout<<"+"<<"\n";
        answer.push('+');
        check[i] = false;
    }
  //  cout<<"-"<<"\n";
    answer.push('-');
    int nowtop  = seq.top();
    seq.pop();


    for(int i=1;i<n;i++){
        int temp;
        cin>>temp;
        if(seq.empty() || temp > seq.top() ){
            bool checking = false;
            for(int j=nowtop+1;j<=temp;j++){
                if(check[j]){
                seq.push(j);
                answer.push('+');
               // cout<<"+"<<"\n";
                check[j] = false;             
                checking = true;      
                }
            }
            if(checking){
                answer.push('-');
               // cout<<"-"<<"\n";
                nowtop = seq.top();
                seq.pop();
            }
        }else if(temp == seq.top()){
            seq.pop();
            answer.push('-');
           // cout<<"-"<<"\n";
        }else{
            cout<<"NO";
            return 0;
        }

    }
    while(!answer.empty()){
        cout<<answer.front()<<"\n";
        answer.pop();
    }

}
