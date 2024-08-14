#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int num=0;
vector<int>number(5);
for(int i=0;i<5;i++){
    cin>>number[i];
    num += number[i];
}
num = num/5;
sort(number.begin(), number.end());
cout<<num<<"\n"<<number[5/2];

}