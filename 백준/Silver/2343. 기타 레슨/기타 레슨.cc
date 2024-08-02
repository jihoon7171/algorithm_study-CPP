#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
using namespace std;

int m;
vector<int>answer;

bool bluray(vector<int> &a, int mid) {
    int count = 1;  
    int sum = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (sum + a[i] > mid) {
            count++; 
            sum = a[i];
            if (count > m) {
                return false;  
            }
        } else {
            sum += a[i];
        }
    }

    return true;  
}


int main(){
    int n,sum=0,answer=0;
    cin>>n>>m;
    vector<int>gt(n); 


    for(int i=0;i<n;i++){
        cin>>gt[i];
    }
        for(int i=0;i<n;i++){
        sum+=gt[i];
    }
    int low = *max_element(gt.begin(), gt.end());
    int high = sum;

    while(low<=high){
        int mid = (low+high)/2;
        if(bluray(gt, mid)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }

    }
    cout<<answer;
}
