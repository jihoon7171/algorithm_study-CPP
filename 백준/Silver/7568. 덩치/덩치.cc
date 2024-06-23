#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main(){
    int a;
    cin>>a;
    vector<vector<int>>comp(a, vector<int>(2));
    for(int i=0;i<a;i++){
        for(int j=0;j<2;j++){
            cin>>comp[i][j];
        }
    }
    vector<int>answer(a,1);

    for(int i=0;i<a;i++){
        for(int j=i;j>=0;j--){
            if(comp[j][0] > comp[i][0] && comp[j][1] > comp[i][1]){
                answer[i]++;
            }
        }
        for(int j=i;j<a;j++){
            if(comp[j][0] > comp[i][0] && comp[j][1] > comp[i][1]){
                answer[i]++;
            }
        }
    }
    for(int i=0;i<a;i++){
        cout<<answer[i]<<" ";
    }
}