#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long a,b,c,d,three;
    cin>>a>>b>>c>>d;
    long long one = (a+b)*c;
    long long two = min(a,b)*d + abs(a-b)*c;
    if((a+b)%2==0){
         three = max(a,b)*d;
    }else{
         three = (max(a,b)-1)*d+c;
    }
    cout<<min({one, two, three});
}
