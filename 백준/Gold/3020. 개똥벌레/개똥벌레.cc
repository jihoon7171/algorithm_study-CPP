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
vector<long long>house;
int n,h;
vector<int>j;
vector<int>s;
int main(){
    cin>>n>>h;
    j.resize(n/2);
    s.resize(n/2);
    for(int i=0;i<n/2;i++){
        cin>>j[i]>>s[i];
    }
    sort(j.begin(), j.end());
    sort(s.begin(), s.end());
    int breakcount = INT_MAX;
    int answer = 0;
    for(int i=1;i<=h;i++){
        int jcount, scount;
        jcount = lower_bound(j.begin(), j.end(), i) - j.begin();
        scount = lower_bound(s.begin(), s.end(), h-i+1)-s.begin();
        int count = n-(jcount+scount);
        if(count < breakcount){
            breakcount = count;
            answer = 1;
        }else if(count == breakcount){
            answer++;
        }
    }
    cout<<breakcount<<" "<<answer;




}