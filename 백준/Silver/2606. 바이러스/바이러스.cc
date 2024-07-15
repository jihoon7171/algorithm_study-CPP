#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<vector<int>>link(101);
bool check[101];

void dfs(int a, int &count){
    check[a] = true;
    for(int i=0;i<link[a].size();i++){
        int y = link[a][i];
        if(!check[y]){
            count++;
            dfs(y,count);
        }
    }
}

int main(){
    int a,b,one,two,count=0;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        cin>>one>>two;
        link[one].push_back(two);
        link[two].push_back(one);
    }
    dfs(1,count);

    cout<<count;

}