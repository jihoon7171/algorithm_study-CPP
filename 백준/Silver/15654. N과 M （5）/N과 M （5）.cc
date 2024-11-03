#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<cmath>
#include<queue>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;
int n,m;
vector<int>answer;
vector<int>number;
void dfs(int count,vector<bool>check){
    if(count == m){
        for(int i=0;i<m;i++){
            cout<<answer[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=0;i<n;i++){
        if(!check[i]){
            check[i] = true;
            answer[count] = number[i];
            dfs(count+1, check);
            check[i] = false;
        }
    }

}
int main(){

    cin>>n>>m;
    number.resize(n);
    answer.resize(m);
    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    vector<bool>check(n, false);
    sort(number.begin(), number.end());
    dfs(0, check);
    


}


    