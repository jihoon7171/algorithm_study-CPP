#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int a;
    cin>>a;
    vector<string>qw(a);
    for(int i=0;i<a;i++){
        cin>>qw[i];
    }
    sort(qw.begin(), qw.end(), [](const string &s1, const string &s2) {
        if (s1.size() == s2.size()) {
            return s1 < s2;
        }
        return s1.size() < s2.size();
    });
    
  qw.erase(unique(qw.begin(), qw.end()), qw.end());


    for(int i=0;i<qw.size();i++){
        cout<<qw[i]<<"\n";
    }

}