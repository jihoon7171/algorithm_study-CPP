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
    int n;
    cin>>n;
    vector<int>num(n+1);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    int count =0;
    for(int i=n-1;i>=1;i--){
        int now = num[i];
        int front = num[i+1];
        while(now >= front){
            now--;
            count++;
        }
        num[i] = now;
    }
    cout<<count;


}
