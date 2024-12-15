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
int find(string temp){
    set<string>as;
    for(int i=1;i<=temp.size();i++){
        int start = i;
        for(int j=0;j<temp.size();j++){
            string now;
            if(j+start-1 < temp.size()){
                now = temp.substr(j,start);
            }
            as.insert(now);
        }
    }
    cout<<as.size()-1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string temp;
    cin>>temp;
    find(temp);



}
