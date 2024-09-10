#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double x,y,r,tx,ty,tr;

void find(){
    double d = sqrt((x-tx)*(x-tx) + (y-ty)*(y-ty));
    if(d==0 && r==tr){
         cout<<"-1";
        return ;
    }
    if(r+tr >d && abs(r-tr) < d){
          cout<<"2";
        return ;
    }
    if(d==r+tr || d== abs(r-tr)){
        cout<<"1";
        return ;
    }
    if(d>r+tr || abs(r-tr) > d ){
         cout<<"0";
        return ;
    }
}
int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
    cin>>x>>y>>r>>tx>>ty>>tr;
    find();
    cout<<"\n";
    }
}