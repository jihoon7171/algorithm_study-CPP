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
using namespace std;
int a,b,c;

int iterative_power(long long a, long long n, long long c){
    long long result = 1;
    a = a%c;
    while(n>0){
        if(n%2 == 1){
            result = (result*a)%c;
            n = n-1;
        }
        a = (a*a)%c;
        n = n/2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>c;
    int temp = iterative_power(a,b,c);
    cout<<temp;


}
