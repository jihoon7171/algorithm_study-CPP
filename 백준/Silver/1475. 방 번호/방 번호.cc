#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;



int main(){
   
    vector<int>num(10);
    string a;
    int sixnine=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        int temp = a[i] - '0';\
        if(temp == 6 || temp == 9){
            sixnine++;
            continue;
        }
         num[temp]++;
    }

    sixnine = (sixnine+1)/2;


    int ans = max(*max_element(num.begin(), num.end()), sixnine);
    cout<<ans;
}


