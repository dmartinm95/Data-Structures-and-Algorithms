#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

void findNemo(string *a, unsigned int n) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        if (a[i] == "nemo") {
            cout << "Found NEMO!" << endl;
        }
    }
    auto elapsed = chrono::high_resolution_clock::now() - start;
    long long milliseconds = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
    cout << "Call to find Nemo took " << milliseconds << " milliseconds." << endl;
}

int main() {
    string everyone[] = {"dory", "bruce", "marlin", "nemo", "gill", "bloat", "nigel", "squirt", "darla", "hank"};
    string nemo[] = {"nemo"};
    string large[10000];
    fill_n(large, 10000, "nemo");

    unsigned int size = sizeof(large) / sizeof(large[0]);
    findNemo(large, size);

    return 0;
}