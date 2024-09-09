#include <iostream>
#include <string>
using namespace std;

int checkst(string as) {
    int count = 0;
    int pos = 0;

    while (pos < as.size()) {
        if (as.find("dz=", pos) == pos) {
            count++;
            pos += 3;
        } else if (as.find("c=", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("c-", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("d-", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("lj", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("nj", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("s=", pos) == pos) {
            count++;
            pos += 2;
        } else if (as.find("z=", pos) == pos) {
            count++;
            pos += 2;
        } else {
            count++;
            pos++;
        }
    }

    return count;
}

int main() {
    string as;
    cin >> as;
    cout << checkst(as) << endl;
    return 0;
}
