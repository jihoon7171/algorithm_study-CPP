#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;
vector<int>number;
int n,m;    

void dfs(int index, int count){
    if(count == m){
       for(int i=0;i<m;i++){
        cout<<number[i]<<" ";
       }
       cout<<"\n";
       return;
    }
    for(int i=index;i<=n;i++){
        number.push_back(i);
        dfs(i+1, count+1);
        number.pop_back();
    }

}

int main(){
    cin>>n>>m;

    dfs(1,0);


}


