#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<cstring>
#include<deque>
using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int>num(a);
    for(int i=0;i<a;i++){
        cin>>num[i];
    }
    int x;
    cin>>x;
    int count=0;
    sort(num.begin(), num.end());
    int start = 0;
    int end = a-1;
    while(start<end){
        if(num[start] + num[end] == x){
            count++;
            start++;
            end--;
        }else if(num[start] +num[end] > x){
            end--;
        }else {
            start++;
        }
    }
    cout<<count;

}