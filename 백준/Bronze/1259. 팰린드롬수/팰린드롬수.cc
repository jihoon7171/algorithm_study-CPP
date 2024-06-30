#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool check(string a){
    for(int i=0;i<(a.size())/2;i++){
        if(a[i] != a[a.size()-(i+1)]){
            return false;
        }
    }
    return true;
}
 



int main(){
    vector<string>arr;
    string as;
    while(1){
       cin>>as;
       if(as == "0"){
        break;
       }
       arr.push_back(as);
    }
    for(int i=0;i<arr.size();i++){
        if(check(arr[i]))
            {cout<<"yes"<<"\n";}else{
                cout<<"no"<<"\n";
            }
    }





}