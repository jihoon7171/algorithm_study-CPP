#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;
unordered_set<string>name;
int truck[1000];

int find(char a){
    if(a =='Y'){
        return name.size();
    }else if(a=='F'){
        return name.size()/2;
    }else if(a=='O'){
        return name.size()/3;
    }
    return 0;
}

int main(){
    int a,count=0;
    cin>>a;
    char g;
    cin>>g;

    for(int i=0;i<a;i++){
        string as;
        cin>>as;
        name.insert(as);
    }
    cout<<find(g);
    

}


