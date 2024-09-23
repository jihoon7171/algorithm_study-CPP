#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
vector<int>result(9);
int a,b;
void dfs(int count, int start){
    if(count == b){
        for(int i=0;i<b;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }

        for(int j=start;j<=a;j++){
            result[count] = j;
            dfs(count+1, j);
        }
    
}

int main() {
    cin>>a>>b;
    dfs(0, 1);

} 