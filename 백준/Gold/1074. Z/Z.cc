#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int n,r,c;
int answer=0;
void run(int x, int y, int size){
    if(x==r && y==c){
        cout<<answer;
        return ;
    }
    if( r>= x && r<x+size && c >=y && c<y+size ){
        run(x,y,size/2);
        run(x,y+size/2,size/2);
        run(x+size/2,y,size/2);
        run(x+size/2,y+size/2,size/2);
    }else{
        answer +=size*size;
    }
}

int main() {
    cin>>n>>r>>c;
    run(0,0,(1<<n));
    return 0;



}