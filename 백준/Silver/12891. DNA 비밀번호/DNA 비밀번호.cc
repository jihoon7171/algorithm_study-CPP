#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;
    vector<char>as(a);
    for(int i=0;i<a;i++){
        cin>>as[i];
    }
    vector<int>point(4);

    int answer=0;
    for(int i=0;i<4;i++){
        cin>>point[i];
    }
    vector<int>answerpoint(4,0);
    for(int i=0;i<b;i++){
        if(as[i] == 'A'){
            answerpoint[0]++;
        }else if(as[i]=='C'){
            answerpoint[1]++;
        }else if(as[i]=='G'){
            answerpoint[2]++;
        }else if(as[i] == 'T'){
            answerpoint[3]++;
        }
    }
    int count=0;
    for(int i=0;i<4;i++){
        if(answerpoint[i] >= point[i]){
            count++;
        }
    }
    if(count == 4){
        answer++;
    }
    for(int i=b;i<a;i++){
        count =0;
        if(as[i-b] == 'A'){
            answerpoint[0]--;
        }else if(as[i-b]=='C'){
            answerpoint[1]--;
        }else if(as[i-b]=='G'){
            answerpoint[2]--;
        }else if(as[i-b] == 'T'){
            answerpoint[3]--;
        }

        if(as[i] == 'A'){
            answerpoint[0]++;
        }else if(as[i]=='C'){
            answerpoint[1]++;
        }else if(as[i]=='G'){
            answerpoint[2]++;
        }else if(as[i] == 'T'){
            answerpoint[3]++;
        }

    for(int i=0;i<4;i++){
        if(answerpoint[i] >= point[i]){
            count++;
        }
    }
    if(count == 4){
        answer++;
    }

    }

    
    cout<<answer;
   
}