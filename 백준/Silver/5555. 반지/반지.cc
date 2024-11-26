#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    string qw;
    cin>>qw>>a;
    int count=0; 
    for(int i=0;i<a;i++){
        string temp;
        cin>>temp;
        queue<int>q;
        for(int j=0;j<temp.size();j++){
            if(temp[j] == qw[0]){
                q.push(j);
            }
        }
        while(!q.empty()){
            int start = q.front();
            q.pop();
            bool checking = true;
            for(int j=0;j<qw.size();j++){
                if(temp[(start+j)%10] != qw[j]){
                    checking = false;
                }
            }
            if(checking){
                count++;
                break;
            }
        }
    }
    cout<<count;


}