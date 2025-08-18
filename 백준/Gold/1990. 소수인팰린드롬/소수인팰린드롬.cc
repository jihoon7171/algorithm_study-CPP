#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
long long a,b;
vector<bool>num;

void ispossible(long long n){
    bool flag = true;
    string t = to_string(n);
    long long s = 0;
    long long e = t.size()-1;
    while(s<e){
        if(t[s] != t[e]){
            flag = false;
            break;
        }
        s++;e--;
    }
    if(flag){
        cout<<n<<"\n";
    }
}

void sosu(){
    for(long long i=2;i<=b;i++){
        num[i] = true;
    }

    for(long long i=2;i<=sqrt(b);i++){
       if(!num[i]){
            continue;
       }
       for(long long j=i*i;j<=b;j+=i){
        num[j] = false;
       }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    num.resize(b+1);
    sosu();
    //이제 저기에는 소수만 남아있음 ( 소수만이 자기 숫자로 채워져있는 상황 );
    for(long long i=a;i<=b;i++){
        if(i>10000001){
            break;
        }
        if(!num[i]){
            continue;
        }
        ispossible(i);
    }
    cout<<-1;

}
