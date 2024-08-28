#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> gset(m);
    vector<int> gg(m);
    for (int i = 0; i < m; i++) {
        cin >> gset[i] >> gg[i];
    }
    int setmin = *min_element(gset.begin(), gset.end());
    int ggmin = *min_element(gg.begin(), gg.end());

    while (n > 0) {
        if (n >= 6) {
            if (6 * ggmin <= setmin) {
                count += 6 * ggmin;
            } else {
                count += setmin;
            }
            n -= 6;
        } else {
            if (n * ggmin <= setmin) {
                count += n * ggmin;
            } else {
                count += setmin;
            }
            n = 0; 
        }
    }
    cout << count;

    return 0;
}
