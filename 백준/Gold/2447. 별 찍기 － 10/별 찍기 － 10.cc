#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int n,temp;
vector<vector<char>>matrix;
void printstar(int x, int y){
   //cout<<"***\n* *\n***";
   int count=0;
    for(int i=y;i<y+3;i++){
        for(int j=x;j<x+3;j++){
            count++;
            if(count == 5){
                matrix[i][j]=' ';
                continue;
            }
            matrix[i][j] = '*';
        }
    }
}

void printspace(int x, int y,int size){
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            matrix[i][j]=' ';
        }
    }
}

void run(int x, int y, int size){
    if(size == 3){
        printstar(x,y);
    }else{
        for(int i=0;i<3;i++){
            run(x+i*size/3, y, size/3);
        }
        //cout<<"\n";
        run(x+0,y+size/3,size/3);
        printspace(x+size/3, y+size/3, size/3);
        run(x+size/3*2,y+size/3,size/3);
        for(int i=0;i<3;i++){
            run(x+i*size/3,y+size/3*2,size/3);
        }
    }
}

void answerprint(){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    cin>>n;
    matrix.resize(n, vector<char>(n));
    run(0,0,n);
    answerprint(); 
}