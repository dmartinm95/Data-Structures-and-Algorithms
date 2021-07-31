#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// When you pass by const reference, you take the argument in by reference (avoid making any copies of it)
// but cannot make any changes to the original object (as opposed to passing it by value)
bool existsPairThatAddsToSum(const vector<int> &array, int sum) {

    // Space complexity: O(N)
    unordered_set<int> complements;

    // Time complexity: O(N)
    for (int number : array) {
        if (complements.find(number) != complements.end()) {
            cout << "Pair found is: [" << number << ", " << sum - number << "]." << endl;
            return true;
        }
        complements.insert(sum - number);
    }

    return false;
}

int main() {
    cout << "Coding Problem: \nGiven a single array of numbers and a sum value, return true if any pair of numbers adds up to the sum" << endl;
    vector<int> numberArray{1, 2, 4, 3, 5, 6, 7};
    int sum = 8;

    bool foundPair = existsPairThatAddsToSum(numberArray, sum);
    if (foundPair) {
        cout << "Found a pair!" << endl;
    } else {
        cout << "Didn't find a pair." << endl;
    }
    return 0;
}
