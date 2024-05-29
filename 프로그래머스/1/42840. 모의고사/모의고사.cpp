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

        if(answers[i] == onear[i%5]){
        onecount++;    
        }
    }
    return onecount;
}

int checktwo(vector<int> answers){
    int twocount =0;
for(int i=0;i<answers.size();i++){

        if(answers[i] == twoar[i%8]){
        twocount++;    
        }
    }
    return twocount;
}
int checkthree(vector<int> answers){
    int threecount =0;
for(int i=0;i<answers.size();i++){

        if(answers[i] == threear[i%10]){
        threecount++;    
        }
    }
    return threecount;
}

vector<int> solution(vector<int> answers) {
    int acount=0, bcount=0, ccount=0;
    vector<int> answer;
    acount = checkone(answers);
    bcount = checktwo(answers);
    ccount = checkthree(answers);
    answer.push_back(acount);
    answer.push_back(bcount);
    answer.push_back(ccount);
    
    sort(answer.begin(), answer.end());
    
    if(answer[0] > answer[1]){
    answer.clear();
    answer.push_back(acount);
    }else {
        if(answer[1] >answer[2]){
        answer.pop_back();    
        }
    }
    
    
    return answer;
}