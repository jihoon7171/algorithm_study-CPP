#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
pair<int, int>one;
pair<int, int>two;
vector<pair<int, int>>v;
int ccw(int x1, int x2, int x3, int y1, int y2, int y3){
    return (x1*y2) + x2*y3 + x3*y1 -(x2*y1+x3*y2+x1*y3);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<3;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int answer = ccw(v[0].first, v[1].first, v[2].first, v[0].second, v[1].second, v[2].second);
    if(answer > 0){
        cout<<1;
    }else if(answer == 0){
        cout<<0;
    }else{
        cout<<-1;
    }
}