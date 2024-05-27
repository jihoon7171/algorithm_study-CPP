#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;
    
    for(int i = 0; i < citations.size(); i++) {
        int h = citations.size() - i;
        if(citations[i] >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}
