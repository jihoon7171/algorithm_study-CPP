#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

long long ans[101] = {0,1,1,1,2,2,3,4,5,7,9};

int main(){
    int a;
    cin>>a;

    for(int i=11;i<101;i++){
        ans[i] = ans[i-1]+ans[i-5];
    }

    for(int i=0;i<a;i++){
        int temp;
        cin>>temp;
        cout<<ans[temp]<<"\n";
    }

}


