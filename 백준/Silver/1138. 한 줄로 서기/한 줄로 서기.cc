#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int answer[11];

int main(){
    int a;
    cin>>a;
    vector<int>key(a+1);
    for(int i=1;i<=a;i++){
        cin>>key[i];
    }
    for(int i=1;i<=a;i++){
        int temp = key[i]+1;
        int count=0;
        for(int j=1;j<=a;j++){
            if(answer[j]==0){
                if(count == key[i]){
                    answer[j] = i;
                    break;
                }
                            count++;
            }

        }

    }
    for(int i=1;i<=a;i++){
        cout<<answer[i]<<" ";
    }

}