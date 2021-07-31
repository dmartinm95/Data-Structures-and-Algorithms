#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class MyArray {
private:
    int length;
    unordered_map<int, int> data;

public:
    int get(int index) {
        return data[index];
    }

    void push(int item) {
        data[length] = item;
        length++;
    }

    void pop() {
        data.erase(length - 1);
        length--;
    }

    void deleteElement(int index) {
        data.erase(index);
        length--;
    }

    void printElements() {
        cout << endl;
        for (int i = 0; i < length; i++) {
            cout << data[i] << " " << flush;
        }
        cout << endl;
    }
};

string reverseString(string inputString) {

    string resultString;

    for (int i = inputString.length() - 1; i >= 0; i--) {
        resultString += inputString[i];
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    return resultString;
}

string reverseString2(string &inputString) {

    int n = inputString.length();

    for (int i = 0; i < n / 2; i++) {
        swap(inputString[i], inputString[n - i - 1]);
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    return inputString;
}

vector<int> mergeSortedArrays(vector<int> &vector1, vector<int> &vector2) {
    vector<int> mergedVector;
    int i = 0;
    int j = 0;
    int vector1Size = vector1.size();
    int vector2Size = vector2.size();

    while (i < vector1Size && j < vector2Size) {
        // cout << vector1[i] << ", " << vector2[j] << endl;
        if (vector1[i] <= vector2[j]) {
            mergedVector.push_back(vector1[i]);
            i++;
        } else {
            mergedVector.push_back(vector2[j]);
            j++;
        }
    }

    // Push the remaining numbers from vector 1
    while (i < vector1Size) {
        mergedVector.push_back(vector1[i]);
        i++;
    }

    // Push the remaining numbers from vector 2
    while (j < vector2Size) {
        mergedVector.push_back(vector2[j]);
        j++;
    }

    // Time Complexity: O(n + m) where n: size of vector 1 and m is the size of vector 2
    // Space Complexity: O(n + m)
    return mergedVector;
}

int main() {

    vector<string> strings = {"a", "b", "c", "d"};

    strings.push_back("e"); // O(1)

    strings.pop_back(); // O(1)

    strings.insert(strings.begin(), "x"); // O(n)

    strings.erase(strings.begin() + 2); // O(n)

    for (string character : strings) {
        cout << character << " " << flush;
    }

    MyArray newArray = MyArray();

    newArray.push(5);
    newArray.push(10);
    newArray.push(15);
    newArray.push(20);

    newArray.printElements();

    string inputString = "Hello World!";
    cout << "Reversing string "
         << "'" << inputString << "' = "
         << "'" << reverseString2(inputString) << "'" << endl;

    vector<int> vector1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vector2 = {4};

    vector<int> result = mergeSortedArrays(vector1, vector2);

    for (int number : result) {
        cout << number << " " << flush;
    }

    return 0;
}