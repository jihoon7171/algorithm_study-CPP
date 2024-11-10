#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;
int n,m;
vector<int>answer(8);
vector<int>num(8);
void dfs(int index, int count){
    if(count == m){
        for(int i=0;i<m;i++){
            cout<<answer[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=index;i<n;i++){
        answer[count] = num[i];
        dfs(i+1, count+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    num.resize(n);
    answer.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    dfs(0,0);



}