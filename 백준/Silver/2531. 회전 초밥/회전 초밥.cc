#include<vector>
#include<iostream>
using namespace std;

int n,d,k,c;
int arr[30001];
int visited[30001];


int main(){
    int max=0;
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int eat=0;
        for(int j=i;j<i+k;j++){
            if(visited[arr[j%n]]==0){
                eat++;
                visited[arr[j%n]]++;
            }
        }
        if( eat >= max){
            if(visited[c] == 1){
                max = eat;
            }else{
                max = eat+1;
            }
        }
        for(int j=i;j<i+k;j++){
                visited[arr[j%n]]=0;
            }
    }
     cout<<max;
}