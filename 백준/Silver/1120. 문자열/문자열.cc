#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#include<sstream>
#include<unordered_set>
#include<cctype>
using namespace std;
//30<= || >=30 || ~30~ 

int finddiff(string a, string b){
    int count=0;
     int minthing=52;
    if(a.size() == b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                 count++;
            }
        }
        return count;
    }

    for(int i=0;i<=b.size()-a.size();i++){
        int temp=0;
        for(int j=0;j<a.size();j++){
            if(a[j] != b[j+i]){
                temp++;
            }
        }
        minthing = min(temp, minthing);
    }
    return minthing;

}


int main() {
    string a,b;
    cin>>a>>b;
    cout<<finddiff(a,b);

}
