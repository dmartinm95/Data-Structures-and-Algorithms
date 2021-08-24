#include <functional>
#include <iostream>
#include <map>
#include <vector>

// Function simply adds 80 to value n
// Using funcion closures to store the cache in the functions scope and not global
std::function<int(int)> memoizedAddTo80() {
    std::map<int, int> cache;

    // Lamba expression that takes n by copy and cache by reference and returns and integer
    return [&cache](int n) {
        std::map<int, int>::iterator iter = cache.find(n);

        if (iter == cache.end()) {
            std::cout << "Computing answer..." << std::endl;
            cache[n] = n + 80;
            return n + 80;
        } else {
            std::cout << "Reading from cache..." << std::endl;
            return iter->second;
        }
    };
}

// Recursive Fibonacci Sequence solution
int calculations = 0;
int fibonacci(int n) {
    calculations++;
    if (n < 2) {
        return n;
    }

    // Time Complexity: O(2^n), not great
    // Space Complexity: O(log(n))
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Memoized Fibonacci Sequence solution
std::map<int, int> fibCache;
int memoizedCalculations = 0;
int memoizedFibonacci(int n) {
    memoizedCalculations++;
    std::map<int, int>::iterator iter = fibCache.find(n);
    if (iter != fibCache.end()) {
        return iter->second;
    }

    if (n < 2) {

        return n;
    }

    fibCache[n] = memoizedFibonacci(n - 1) + memoizedFibonacci(n - 2);

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    return fibCache[n];
}

// Bottom up Fibonacci Sequence solution
int bottomUpCalculations = 0;
int bottomUpFibonacci(int n) {
    std::vector<int> answer{0, 1};
    for (int i = 2; i <= n; i++) {
        bottomUpCalculations++;
        answer.push_back(answer[i - 2] + answer[i - 1]);
    }
    return answer[n];
}

// Test program
int main() {

    std::function<int(int)> memoized = memoizedAddTo80();

    std::cout << memoized(10) << std::endl;
    std::cout << memoized(10) << std::endl;
    std::cout << memoized(20) << std::endl;
    std::cout << memoized(20) << std::endl;
    std::cout << std::endl;

    int fibAtIndex = 10;
    std::cout << "Recursive Fibonacci number at index: " << fibAtIndex << " is = " << fibonacci(fibAtIndex) << std::endl;
    std::cout << "Recursive calculations: " << calculations << std::endl;

    std::cout << std::endl;
    std::cout << "Memoized Fibonacci number at index: " << fibAtIndex << " is = " << memoizedFibonacci(fibAtIndex) << std::endl;
    std::cout << "Memoized calculations: " << memoizedCalculations << std::endl;

    std::cout << std::endl;
    std::cout << "Bottom Up Fibonacci number at index: " << fibAtIndex << " is = " << bottomUpFibonacci(fibAtIndex) << std::endl;
    std::cout << "Bottom Up calculations: " << bottomUpCalculations << std::endl;

    return 0;
}