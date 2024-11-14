#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long a;
    cin>>a;
    vector<long long>num(a);
    long long b;
    cin>>b;
    for(long long i=0;i<a;i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());
    long long start = 1;
    long long end = num[num.size()-1];
    long long result = 0;
    while(start <= end){
        long long length =(start+end)/2;
        long long count=0;
        for(long long i=0;i<a;i++){
            count+=num[i]/length;
        }
        if(count >= b){
            result = length;
            start = length+1;
        }else{
            end = length-1;
        }
    }
    cout<<result;

}