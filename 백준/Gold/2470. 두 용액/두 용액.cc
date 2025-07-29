#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int n;
int main(){
    cin>>n;
    pair<int, int>answer;
    int backanswer = INT_MAX;
    vector<int>liquid(n);
    for(int i=0;i<n;i++){
        cin>>liquid[i];
    }
    sort(liquid.begin(), liquid.end());
    int s = 0;
    int e = n-1;
    while(s<e){
        int temp = liquid[s] + liquid[e];
        int abstemp = abs(temp);
        if(backanswer > abstemp){
            backanswer = abstemp;
            answer.first = liquid[s];
            answer.second = liquid[e];
        }
        if(temp > 0){
            e -=1;
        }else{
            s +=1;
        }
    }
    cout<<answer.first<<" "<<answer.second;

}

 