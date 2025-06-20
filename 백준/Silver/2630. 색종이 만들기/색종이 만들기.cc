#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int n;
vector<vector<int>>matrix;
int oneanswer = 0;
int zeroanswer = 0;
bool checking(int x, int y, int size){
    int onecount = 0;
    int zerocount = 0;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(matrix[i][j] == 0){
                zerocount++;
            }else if(matrix[i][j] == 1){
                onecount++;
            }
        }
    }
    if(onecount == size*size){
        oneanswer++;
        return true;
    }else if(zerocount == size*size){
        zeroanswer ++;
        return true;
    }
    return false;
}

void run(int x, int y, int size){
    if(checking(x,y,size)){
        return ;
    }else{
        run(x,y,size/2);
        run(x+size/2,y,size/2);
        run(x,y+size/2,size/2);
        run(x+size/2,y+size/2,size/2);
    }
}

int main() {
    cin>>n;
    matrix.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    run(0,0,n);
    cout<<zeroanswer<<"\n"<<oneanswer;

}