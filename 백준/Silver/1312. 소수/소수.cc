#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;






int main(){
    int a,b,n;
    cin>>a>>b>>n;
    int count=1;
    int qw = a%b;
    while(count<=n){
        if(count == n){
            cout<<(qw*10)/b;
            break;
        }
        qw = (qw*10)%b;
        count++;
    }


}
