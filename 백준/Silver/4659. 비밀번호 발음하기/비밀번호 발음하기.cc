#include <iostream>
#include <vector>
#include <string>
using namespace std;

void checkout(string as){
    int mo = 0; 
    vector<int>moch(as.size(), 0);  
    vector<int>jach(as.size(), 0);  

    for(int i = 0; i < as.size(); i++){
        if(as[i] == 'a' || as[i] == 'e' || as[i] == 'o' || as[i] == 'i' || as[i] == 'u'){
            mo++;
            moch[i] = 1;
        } else {
            jach[i] = 1;
        }

        if(i > 0){
            
            if(as[i-1] == as[i] && as[i] != 'e' && as[i] != 'o'){
                cout << "<" << as << "> is not acceptable." << "\n";
                return;
            }
        }
    }

   
    if(mo == 0){
        cout << "<" << as << "> is not acceptable." << "\n";
        return;
    }

if(as.size()>2){
    for(int i = 0; i < as.size()-2; i++){
        if((moch[i] == 1 && moch[i+1] == 1 && moch[i+2] == 1) || 
           (jach[i] == 1 && jach[i+1] == 1 && jach[i+2] == 1)){
            cout << "<" << as << "> is not acceptable." << "\n";
            return;
        }
    }
}

    cout << "<" << as << "> is acceptable." << "\n";
}

int main(){
    string as;
    while(true){
        cin >> as;
        if(as == "end"){
            break;
        }
        checkout(as);
    }
}
