#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<limits.h>
#include<queue>
using namespace std;
int m,n;
queue<int>q;

int mile(vector<int>&apply, int p, int l){
    if(p<l){
        return 1;
    }else{
        sort(apply.begin(), apply.end());
        return apply[p-l];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>answer;
    for(int i=0;i<n;i++){
        int p,l;
        cin>>p>>l;
        vector<int>apply(p);
        for(int j=0;j<p;j++){
            cin>>apply[j];
        }
    answer.push_back(mile(apply, p, l));
    }

    sort(answer.begin(), answer.end());
    int temp=0;
    int count=0;
    for(int i=0;i<answer.size();i++){
        temp += answer[i];
        if(temp > m){
            break;
        }else{
            count++;
        }
    }
    cout<<count;

}
