#include<iostream>
#include<vector>
using namespace std;

int a;


int findgaro(vector<vector<char>>& room) {
    int count = 0;
    for (int i = 0; i < a; i++) {
        int check = 0;
        for (int j = 0; j < a; j++) {
            if (room[i][j] == '.') {
                check++;
            } else if (room[i][j] == 'X') {
                if (check >= 2) {
                    count++;
                }
                check = 0;
            }
        }
        if (check >= 2) {
            count++;
        }
    }
    return count;
}

int findsero(vector<vector<char>>& room) {
    int count = 0;
    for (int i = 0; i < a; i++) {
        int check = 0;
        for (int j = 0; j < a; j++) {
            if (room[j][i] == '.') {
                check++;
            } else if (room[j][i] == 'X') {
                if (check >= 2) {
                    count++;
                }
                check = 0;
            }
        }
        if (check >= 2) {
            count++;
        }
    }
    return count;
}

int main() {
   
    cin >> a;

    vector<vector<char>> room(a, vector<char>(a));  

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> room[i][j];
        }
    }


    cout << findgaro(room) << " " << findsero(room);

    return 0;
}
