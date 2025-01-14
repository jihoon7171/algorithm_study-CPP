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
#include<sstream>
using namespace std;
int n,m;
vector<string>name;
vector<int>number;
vector<int>character;
int bn(int p){
    int mid = 0, left = 0, right = n-1;
    while(left<=right){
        mid = (left+right)/2;
        if(p<=number[mid]){
            right = mid-1;
        }else{
            left = mid +1;
        }
    }
    if( p > number[mid]){
        return mid+1;
    }else{
        return mid;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    name.resize(n);
    number.resize(n);
    for(int i=0;i<n;i++){
        cin>>name[i]>>number[i];
    }
    int p;
    for(int i=0;i<m;i++){
        cin>>p;
        cout<<name[bn(p)]<<"\n";
    }

}
