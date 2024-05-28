#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h=3, w = brown/2 -1;
    int save = w;
    for(h=3;h<=save;h++){
        if((h-2)*(w-2) == yellow){
            if(w>=h){
                break;
            }
        }
        w--;
    }
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}