#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<deque>
using namespace std;


int main() {
    int a,b;
    cin>>a>>b;
    vector<int>temperate(a);
    for(int i=0;i<a;i++){
        cin>>temperate[i];
    }
    int result=0;
    for(int i=0;i<b;i++){
        result+=temperate[i];
    }
            int nowmax = result;
    int start = 0;
    int end = b-1;
    while(end<a-1){

        nowmax -= temperate[start++];
        nowmax += temperate[++end];
        result = max(nowmax, result);
    }
    cout<<result;

}