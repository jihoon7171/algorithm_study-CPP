#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main(){
    int a,ans=-50000;
    cin>>a;
    vector<int>rope(a);
    for(int i=0;i<a;i++){
        cin>>rope[i];
    }
    sort(rope.begin(), rope.end());
    for(int i=0;i<a;i++){
        int temp;
        temp = rope[i]*(a-i);
        ans = max(temp, ans);
    }
    cout<<ans;

}
