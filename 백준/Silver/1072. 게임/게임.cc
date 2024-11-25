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
    long long x,y;
    cin>>x>>y;
    long long z = (y*100)/x;
    if(z>=99){
        cout<<-1;
        return 0;
    }
    long long answer=LLONG_MAX;
    long long start = 0, end = 1000000000;
    while(start<=end){
        long long mid = (start+end)/2;
        long long temp = ((mid+y)*100)/(x+mid);
        if(temp > z){
            answer = min(answer, mid);
            end = mid -1;
        }else{
            start = mid+1;
        }
    }
    cout<<answer;
    



}