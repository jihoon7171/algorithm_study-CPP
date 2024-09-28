#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int>name;
    vector<int>giftindex(friends.size());
    vector<int>result(friends.size(),0);
    for(int i=0;i<friends.size();i++){
        name[friends[i]] = i;
    }

    vector<vector<int>>giftcount(friends.size(), vector<int>(friends.size(),0));
    /*선물 주고받은 표 만들기*/
    for(int i=0;i<gifts.size();i++){
        string temp = gifts[i];
        int cc = temp.find(" ");
        string from = temp.substr(0,cc);
        string to = temp.substr(cc+1);
        giftcount[name[from]][name[to]]++; 
    }
    /*선물 지수 계산*/
    for(int i=0;i<friends.size();i++){
        int give=0, receive = 0;
        for(int j=0;j<friends.size();j++){
             give += giftcount[i][j];
             receive += giftcount[j][i];
        }
        giftindex[i] = give-receive;
    }
    for(int i=0;i<friends.size();i++){
        for(int j=0;j<friends.size();j++){
            if(i!=j){
                if(giftcount[i][j]>giftcount[j][i]){
                    result[i]++;
                }else if(giftcount[i][j] == giftcount[j][i]){
                    if(giftindex[i]>giftindex[j]){
                        result[i]++;
                    }
                }
            }
        }
    }
    answer = *max_element(result.begin(), result.end());

    return answer;
}