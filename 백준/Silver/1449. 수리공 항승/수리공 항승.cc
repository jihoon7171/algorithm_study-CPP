#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


int main() {
    int n, tape;
    cin>>n>>tape;
    vector<int>water(n);
    for(int i=0;i<n;i++){
        cin>>water[i];
    }
    int answer=0;
    sort(water.begin(), water.end());
    int i=0;
    while(i<n){
        answer++;
        int start = water[i];
        while(i<n && water[i]+1 <= start+tape ){
            i++;
        }
    }
    
      cout<<answer;

    
}
