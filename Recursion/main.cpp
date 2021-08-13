#include <algorithm>
#include <iostream>
#include <vector>
// Find the factorial of a number

// Use recursion method
int findFactorialRecursive(int number) {
    if (number == 0) {
        return 1;
    }

    // Time Complexity: O(n)
    return (number * findFactorialRecursive(number - 1));
}

// Use iterative method
int findFactorialIterative(int number) {
    int answer = 1;
    for (int i = number; i > 0; i--) {
        answer *= i;
    }

    // Time Complexity: O(n)
    return answer;
}

// Find the fibonacci sequence
// Given a number N return the index value of the fibonacci sequence

// Use iterative method
int fibonacciIterative(int n) {
    std::vector<int> values{0, 1};

    for (int i = 2; i < n + 1; i++) {
        values.push_back(values[i - 2] + values[i - 1]);
    }

    // Time complexity: O(n)
    return values[n];
}

// Use recursion method
int fibonacciRecursive(int n) {

    if (n < 2) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // Time complexity: O(2^n) Exponential time, size of tree exponentially grows as the value increases
}

// Reversing a string

// Use recursion method
void reverseStringRecursive(std::string &word, int k) {
    static int i = 0;

    if (k == word.length()) {
        return;
    }

    reverseStringRecursive(word, k + 1);

    if (i <= k) {
        std::swap(word[i++], word[k]);
    }
}

// Use iterative method
std::string reverseStringIterative(std::string word) {
    std::string result = "";
    for (int i = word.size() - 1; i >= 0; i--) {
        result.push_back(word[i]);
    }

    return result;
}

int main() {

    int factorialNumber = 5;
    int result = findFactorialRecursive(factorialNumber);

    std::cout << factorialNumber << "! = " << result << std::endl;

    int fibonacciIndex = 9;
    int fibonacciResult = fibonacciRecursive(fibonacciIndex);

    std::cout << "At index " << fibonacciIndex << ", fibonacci value (recursive) is: " << fibonacciResult << std::endl;

    int fibonacciResultIterative = fibonacciIterative(fibonacciIndex);
    std::cout << "At index " << fibonacciIndex << ", fibonacci value (iterative) is: " << fibonacciResultIterative << std::endl;

    std::string stringToReverse = "yoyo mastery";
    std::string reversedString = reverseStringIterative(stringToReverse);

    std::cout << "Original string '" << stringToReverse << "', reversed string (iterative) is: '" << reversedString << "'" << std::endl;

    reversedString = "yoyo mastery";

    reverseStringRecursive(reversedString, 0);

    std::cout << "Original string '" << stringToReverse << "', reversed string (recursive) is: '" << reversedString << "'" << std::endl;

    return 0;
}