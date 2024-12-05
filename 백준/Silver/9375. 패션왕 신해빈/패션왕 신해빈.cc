#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;


    for(int i=0;i<n;i++){
            set<string>search;
            map<string, int>save;
            int count =1;
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            string name, type;
            cin>>name>>type;
            save[type]++;
            search.insert(type);
        }
        for(string temp : search){
            count *= (save[temp]+1);
        }
        cout<<count-1<<"\n";
    }





}