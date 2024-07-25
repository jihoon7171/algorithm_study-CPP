#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int index=0;
    bool minuscheck=false;
    string qw;
    cin>>qw;
    string num="";
    for(int i=0;i<qw.size();i++){

        if(qw[i] == '+' || qw[i] == '-'){
            if(minuscheck){
                index -= stoi(num);
                num = "";
            }else{
                index +=stoi(num);
                num = "";
            }
            
        }else{
            num +=qw[i];
        }
            if(qw[i] == '-'){
            minuscheck = true;
        }
    }
        if (num != "") {
        if (minuscheck) {
            index -= stoi(num);
        } else {
            index += stoi(num);
        }
    }
    
    cout<<index;

}