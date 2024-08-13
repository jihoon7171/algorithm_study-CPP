#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
#include<sstream>
#include<unordered_set>
using namespace std;

int main() {
            ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    unordered_set<string>keyword;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        keyword.insert(temp);
    }
    char stan = ',';
    for(int i=0;i<m;i++){
        string temp;
        cin>>temp;
        istringstream ss(temp);
        string temp1;
        vector<string>words;
        while(getline(ss, temp1, stan)){
            words.push_back(temp1);
        }
        for(int j=0;j<words.size();j++){
            if(keyword.find(words[j]) != keyword.end()){
                keyword.erase(words[j]);
            }
        }
          cout<<keyword.size()<<"\n";
    }



}
