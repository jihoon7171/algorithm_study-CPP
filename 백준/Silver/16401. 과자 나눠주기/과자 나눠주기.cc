#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int n,m;
int main(){
    cin>>m>>n;
    vector<int>snack(n);
    for(int i=0;i<n;i++){
        cin>>snack[i];
    }
    sort(snack.begin(), snack.end());
    int s = 1;
    int e = snack[n-1];
    int answer = INT_MIN;

    while(s<=e){
        int mid = (s+e)/2;
        int count = 0;
        bool possible = false;
        for(int i=0;i<n;i++){
            count += snack[i]/mid;
        }
        if(count >= m){
            answer = max(answer, mid);
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    if(answer == INT_MIN){
        cout<<0;
    }else{
        cout<<answer;
    }

}

 