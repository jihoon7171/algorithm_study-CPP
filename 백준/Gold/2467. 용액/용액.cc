#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
vector<long long>liquid;
int n;
int main(){
    long long answer = LLONG_MAX;
    long long al;long long ar;
    cin>>n;
    liquid.resize(n);
    for(int i=0;i<n;i++){
        cin>>liquid[i];
    }
    sort(liquid.begin(), liquid.end());
    long long l = 0;
    long long r = n-1;
    while(l<r){
        long long temp = liquid[l]+liquid[r];
        if(temp == 0){
            answer = temp;
            al = l;
            ar = r;
            break;
        }
        if(abs(temp) < answer){
            answer = abs(temp);
            al = l;
            ar = r;
        }
        if(temp > 0){
            r--;
        }else if(temp < 0){
            l++;
        }
    }
    cout<<liquid[al]<<" "<<liquid[ar];


}