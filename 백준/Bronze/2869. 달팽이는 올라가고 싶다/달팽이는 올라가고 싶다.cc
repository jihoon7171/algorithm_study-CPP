#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
#include<sstream>
#include<unordered_set>
using namespace std;

int main() {
    int a,b,v;
    cin>>a>>b>>v;
    int count=1, temp=a-b;
    int newa = v-a;
    if(v==a){
        cout<<count;
        return 0;
    }
    count += newa/(a-b);
    if(newa%(a-b)==0){
    cout<<count;
    }else{
        cout<<count+1;
    }

}
