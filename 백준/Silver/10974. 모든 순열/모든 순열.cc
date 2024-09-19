#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
using namespace std;
    int a;
    int basic[9];
    int check[9];
    vector<int>num(9);
void dfs(int index){
    if(index == a){
        for(int i=0;i<a;i++){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=a;i++){
        if(check[i]==0){
            num[index] = basic[i];
            check[i] = 1;
            dfs(index+1);
            check[i] = 0;
        }
    }
}


int main() {
    cin>>a;
    for(int i=0;i<=a;i++){
        basic[i] = i;
    }
    dfs(0);
} 
