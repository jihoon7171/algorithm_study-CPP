#include <iostream>
#include<cmath>
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

bool issosu(int a){
    if( a== 1){
        return false;
    }
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(issosu(i)) cout<<i<<"\n";
    }
}