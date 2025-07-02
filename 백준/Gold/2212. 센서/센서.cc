#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
vector<int>sensor;
int n,k;
int main(){
    cin>>n>>k;
    set<int>number;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        number.insert(temp);
    }
    for(auto a : number){
        sensor.push_back(a);
    }
    int size = sensor.size();
    sort(sensor.begin(), sensor.end());
    vector<int>gap;
    for(int i=0;i<size-1;i++){
        gap.push_back(abs(sensor[i] - sensor[i+1]));
    }
    sort(gap.begin(), gap.end(), greater<int>());
    int total = 0;
    for(int i=k-1;i<gap.size();i++){
        total += gap[i];
    }
    cout<<total;

}

