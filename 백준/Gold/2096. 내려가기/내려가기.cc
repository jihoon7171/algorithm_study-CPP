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
int t;
int main(){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    int maxdp[2][3];
    int mindp[2][3];
    maxdp[0][0] = a;
    maxdp[0][1] = b;
    maxdp[0][2] = c; 
    mindp[0][0] = a;
    mindp[0][1] = b;
    mindp[0][2] = c; 
    for(int i=1;i<n;i++){
        int cur = i%2;
        int prev = (i-1)%2;
        cin>>a>>b>>c;
        maxdp[cur][0] = max(maxdp[prev][0]+a,maxdp[prev][1]+a);
        maxdp[cur][1] = max({maxdp[prev][0]+b,maxdp[prev][1]+b, maxdp[prev][2]+b}) ;
        maxdp[cur][2] = max(maxdp[prev][1]+c, maxdp[prev][2]+c);

        mindp[cur][0] = min(mindp[prev][0]+a,mindp[prev][1]+a);
        mindp[cur][1] = min({mindp[prev][0]+b,mindp[prev][1]+b, mindp[prev][2]+b}) ;
        mindp[cur][2] = min(mindp[prev][1]+c, mindp[prev][2]+c);

    }
    int last = (n-1)%2;
    cout<<max({maxdp[last][0], maxdp[last][1], maxdp[last][2]})<<" "<<min({mindp[last][0], mindp[last][1], mindp[last][2]});
    

}