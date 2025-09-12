#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
vector<pair<pair<int, int>, int>> score;
vector<int>d;
vector<int>land;

void run(){
    
}

int n,m;
int main() {
    cin>>n>>m;
    land.resize(n+1);
    vector<int>s(n+2);
    d.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>land[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        score.push_back({{a,b},c});
    }
    sort(score.begin(), score.end());
    for(int i=0;i<score.size();i++){
        int s = score[i].first.first;
        int e = score[i].first.second;
        int sc = score[i].second;
        d[s] = d[s]+sc;
        d[e+1] = d[e+1]-sc;
    }
    s[1] = d[1];
    for(int i=1;i<=n;i++){
        s[i] = s[i-1]+d[i];
    }
    for(int i=1;i<=n;i++){
        cout<<land[i] + s[i]<<" ";
    }
    return 0;
}