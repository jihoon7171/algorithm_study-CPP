#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int onear[5] = {1,2,3,4,5};
int twoar[8] = {2,1,2,3,2,4,2,5};
int threear[10] = {3,3,1,1,2,2,4,4,5,5};

int checkone(vector<int> answers){

    int onecount =0;
for(int i=0;i<answers.size();i++){
    int w = i%5;
        if(answers[i] == onear[w]){
        onecount++;    
        }
    }
    return onecount;
}

int checktwo(vector<int> answers){

    int twocount =0;
for(int i=0;i<answers.size();i++){
     int w = i%8;
        if(answers[i] == twoar[w]){
        twocount++;    
        }
    }
    return twocount;
}
int checkthree(vector<int> answers){

    int threecount =0;
for(int i=0;i<answers.size();i++){
             int w = i%10;
        if(answers[i] == threear[w]){
        threecount++;    
        }
    }
    return threecount;
}

vector<int> solution(vector<int> answers) {
    vector<int>result;
    int acount=0, bcount=0, ccount=0;
    vector<int> answer;
    acount = checkone(answers);
    bcount = checktwo(answers);
    ccount = checkthree(answers);
    int maxcount = max({acount, bcount, ccount});
    if(maxcount == acount) answer.push_back(1);
     if(maxcount == bcount) answer.push_back(2);
     if(maxcount == ccount) answer.push_back(3);
    
    
    
    return answer;
}