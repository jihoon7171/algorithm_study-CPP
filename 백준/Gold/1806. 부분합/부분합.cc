#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,s;
    cin>>n>>s;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int start =0,end=0,answer=INT_MAX;
    int sum = num[0];
    while(start<=end && end<n){
        if(sum>=s){
            int temp = end-start+1;
            answer = min(answer, temp);
            sum -= num[start];
            start++;
        }else{
            end++;
            sum += num[end];
        }
    }
    if(answer == INT_MAX) {
        cout<<0;
        return 0;
    }
    cout<<answer;


}