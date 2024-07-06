#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int lotto[13];
int my[13];
int a;

void dfs(int start, int depth){
    if(depth==6){
        for(int i=0;i<depth;i++){
            cout<<lotto[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=start; i<a;i++){
        lotto[depth] = my[i];
        dfs(i+1, depth+1);
    }


    

}


int main(){
    while(1){
        cin>>a;
        if(a==0){
            break;
        }
        vector<int>number(a);
        for(int i=0;i<a;i++){
            cin>>my[i];
        }
        dfs(0,0);
        cout<<"\n";
    }


}