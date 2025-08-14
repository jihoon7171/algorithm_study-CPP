#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int n,m;
vector<vector<int>>city;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    city.resize(n+1, vector<int>(n+1, INT_MAX));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        city[a][b] = min(city[a][b], c);
    }

    vector<vector<int>>dist(n+1, vector<int>(n+1, INT_MAX));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j] = 0;
            }else{
                if(city[i][j] != INT_MAX){
                    dist[i][j] = city[i][j];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INT_MAX){
                cout<<0<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    

}
