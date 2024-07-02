#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

bool comp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first; }

int main(){
    int a;
    cin>>a;
    vector<pair<int, string>>st(a);   
    cin.ignore();
    for(int i=0;i<a;i++){
        cin>>st[i].first>>st[i].second;
    }
    stable_sort(st.begin(), st.end(), comp);
    for(int i=0;i<a;i++) {
        cout<<st[i].first<<" "<<st[i].second<<"\n";
    }



}

