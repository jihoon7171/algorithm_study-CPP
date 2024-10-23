#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
long long a,b;

int main(){

    cin>>a>>b;
    vector<long long>tree(a);
    for(int i=0;i<a;i++){
        cin>>tree[i];
    }
    sort(tree.begin(), tree.end());
    long long start =0;
    long long end = tree[a-1];
    long long answer=0;
    long long  mid = (start+end)/2;
    while(start<=end){
        long long tr = 0;
      mid = (start+end)/2;
        for(int i=0;i<a;i++){
            if(mid < tree[i]){
                tr += tree[i] - mid;
            }
        }
        if(tr >= b){
           answer = mid;
           start = mid+1;
        }else end = mid-1;
        }
          cout<<answer;
    }
  

