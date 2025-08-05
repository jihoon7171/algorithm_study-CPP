#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int n;
vector<pair<long long, long long>>s;
int main(){
       ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    s.resize(n);
    long long count = 0;
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s.begin(), s.end());
    long long last = s[0].second;
    count += s[0].second - s[0].first;
    for(int i=1;i<s.size();i++){
        long long ns = s[i].first;
        long long ne = s[i].second;
        if(ne < last) continue;
        if(ns<last){
            ns = last;
        }
        // cout<<i<<" "<<count<<"\n";
        count += ne-ns;
        last = ne;
    }
    cout<<count;


}
