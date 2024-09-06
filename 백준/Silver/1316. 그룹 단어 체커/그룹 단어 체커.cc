#include<iostream>
#include<vector>
using namespace std;

bool check(string as){
    vector<int>check(40, 0);
        check[as[0]-'a']++;
        int temp = as[0]-'a';
    for(int i=1;i<as.size();i++){
        if(check[as[i]-'a'] != 0){
            if(as[i-1]-'a' == as[i]-'a'){
                continue;
            }else{
                return false;
            }
        }else{
            check[as[i]-'a']++;
        }
    }
    return true;

}

int main() {
    int a,count=0;
    cin>>a;
    for(int i=0;i<a;i++){
        string as;
        cin>>as;
        if(check(as)){
            count++;
        }

    }
    cout<<count;
}
