#include <iostream>
#include <string>
using namespace std;



int main() {
    string a;
    cin >> a;
    int num=0, ptr=0;
    while(num++<30001){
        string temp = to_string(num);
        for(int i=0;i<temp.size();i++){
            if(temp[i] == a[ptr]){
                ptr++;
            }
            if(ptr == a.size()){
                cout<<num;
                return 0;
            }
        }

    }

}
