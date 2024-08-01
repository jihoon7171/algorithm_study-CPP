#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int sum (vector<int> &a, int mid){
    int suma =0;
    for(int i=0;i<a.size();i++){
        suma+=min(mid, a[i]);
    }
    return suma;
}


int main(){
    int a,result=0;
    cin>>a;
    vector<int>city(a);
    for(int i=0;i<a;i++){
        cin>>city[i];
    }
    int budget;
    cin>>budget;
    sort(city.begin(), city.end());
    int minq = 0;
    int maxq = city[city.size()-1];

    while(minq<=maxq){
        int midq = (minq+maxq)/2;
        if(sum(city, midq)<=budget){
            result = max(midq, result);
            minq = midq+1 ;
        }else{
            maxq = midq-1;
        }
    }
    
    cout<<result<<endl;


}
