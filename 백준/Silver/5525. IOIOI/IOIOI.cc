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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    string temp;
    cin>>temp;
    string comp = "";
    for(int i=0;i<n*2+1;i++){
        if(i%2 == 1){
            comp += 'O';
        }else{
            comp += 'I';
        }
    }
    int count=0;
    int index = 0;
    while((index = temp.find(comp, index)) != string::npos){
        count++;
        index++;
        // cout<<index<<"\n";
    }
    cout<<count;



}
