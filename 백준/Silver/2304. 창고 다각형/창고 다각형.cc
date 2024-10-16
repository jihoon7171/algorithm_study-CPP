#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
pair<int, int> godirection[4] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    vector<pair<int, int>>storage(a);
    for(int i=0;i<a;i++){
        cin>>storage[i].first>>storage[i].second;
    }
    sort(storage.begin(), storage.end());
    int garo = storage[a-1].first-storage[0].first+1;
    int sero=0;
    for(int i=0;i<a;i++){
        sero = max(storage[i].second, sero);
    }
    int bigthing = garo*sero;
    pair<int, int>temp = storage[0];
    for(int i=1;i<a;i++){
        if(temp.second<storage[i].second){
           int q =  (storage[i].first -temp.first) *(sero - temp.second);
           bigthing -= q;
            temp = storage[i];
        }
    }
    temp = storage[a-1];
    for(int i=a-1;i>=1;i--){
        if(temp.second<storage[i].second){
            int q= (temp.first -storage[i].first)*(sero - temp.second);
           bigthing -= q;
            temp = storage[i];
        }
    }
    cout<<bigthing;


}
