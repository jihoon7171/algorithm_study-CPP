#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int>yk(a);
    for(int i=0;i<a;i++){
        cin>>yk[i];
    }
    sort(yk.begin(), yk.end());
    cout<<yk[0]*yk[a-1];
} 
