#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int main() {
    int a,b,count=0;
    cin>>a>>b;
    unordered_set<string>n;
    vector<string>m(b);
    for(int i=0;i<a;i++){
        string temp;
        cin>>temp;
        n.insert(temp);
    }
    for(int i=0;i<b;i++){
        cin>>m[i];
    }
    for(int i=0;i<b;i++){
        if(n.find(m[i]) != n.end()){
            count++;
        }
        
    }
    cout<<count;

}
