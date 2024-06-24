#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

long long gcd(long long a, long long b){
    while(b != 0){
        long long t = b;
        b = a%b;
        a = t;
    }
    return a;
}

long long findgcd(vector<long long> a){
    long long result = a[1];
    for(int i=2;i<a.size();i++){
        result  = gcd(result, a[i]);
        if(result == 1){
            break;
        }
    }
    return result;
} 


int main(){
    int a;
    cin>>a;
    vector<long long>tree(a);
    vector<long long>distance(a);
    for(int i=0;i<a;i++){
        cin>>tree[i];
    }
    for(int i=1;i<a;i++){
        distance[i] = tree[i]-tree[i-1];
    }

    int comp = findgcd(distance);
    int answer=0;


    for(int i=1;i<a;i++){
        answer += (distance[i]/comp)-1;
    }
    cout<<answer;
}