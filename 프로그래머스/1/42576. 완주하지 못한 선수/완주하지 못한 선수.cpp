#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int count=0;
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++){
        if(completion[i] != participant[i]){
            answer = participant[i];
            break;
        }else{
            count++;
        }


    }
        if(count == completion.size()){
            answer = participant.back();
        }

    return answer;
}