#include <string>
#include <vector>
#include<iostream>
using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int big1=1,big2=1;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){
        int temp;
        temp = sizes[i][0];
        sizes[i][0] = sizes[i][1];
        sizes[i][1] = temp;
        }
    }
    big1 = sizes[0][0];
    for(int i=1;i<sizes.size();i++){
    if(big1 < sizes[i][0]){
        big1 = sizes[i][0];
        }    
    }
    big2 = sizes[0][1];
    for(int i=1;i<sizes.size();i++){
    if(big2 < sizes[i][1]){
     big2 = sizes[i][1];   
    }
    }
    answer = big1 * big2;
    return answer;
}