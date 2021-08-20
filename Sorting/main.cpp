#include <iostream>
#include <vector>

//// BUBBLE SORT ////
void bubbleSort(std::vector<int> &numbers) {
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}
//// ======== ////

//// SELECTION SORT ////
void selectionSort(std::vector<int> &numbers) {
    int n = numbers.size();

    for (int i = 0; i < n; i++) {

        int smallest = numbers[i];
        int smallestIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (smallest > numbers[j]) {
                smallest = numbers[j];
                smallestIndex = j;
            }
        }

        // Swap
        int temp = numbers[i];
        numbers[i] = smallest;
        numbers[smallestIndex] = temp;
    }
}
//// ======== ////

//// INSERTION SORT ////
void insertionSort(std::vector<int> &numbers) {
    int n = numbers.size();
    int j;
    int value;

    for (int i = 1; i < n; i++) {

        value = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > value) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = value;
    }
}
//// ======== ////

//// MERGE SORT ////
void merge(std::vector<int> &numbers, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    // Copy data to temp arrays
    for (int i = 0; i < subArrayOne; i++) {
        leftArray.push_back(numbers[left + i]);
    }

    for (int j = 0; j < subArrayTwo; j++) {
        rightArray.push_back(numbers[mid + 1 + j]);
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into numbers[left...right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            numbers[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            numbers[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaning elements of left[], if any
    while (indexOfSubArrayOne < subArrayOne) {
        numbers[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaning elements of right[], if any
    while (indexOfSubArrayTwo < subArrayTwo) {
        numbers[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(std::vector<int> &numbers, int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(numbers, begin, mid);
    mergeSort(numbers, mid + 1, end);
    merge(numbers, begin, mid, end);
}
//// ======== ////

//// QUICK SORT ////
int partition(std::vector<int> &numbers, int low, int high) {

    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (numbers[j] < pivot) {
            i++;

            // Swap numbers[i] and numbers[j]
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }

    // Swap numbers[i+1] and numbers[high]
    int temp = numbers[i + 1];
    numbers[i + 1] = numbers[high];
    numbers[high] = temp;

    return i + 1;
}

void quickSort(std::vector<int> &numbers, int low, int high) {
    if (low < high) {
        int pi = partition(numbers, low, high);

        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }
}
//// ======== ////

//// PRINT VECTOR ////
void printVector(std::vector<int> &numbers) {

    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
//// ======== ////

// Test program
int main() {
    std::vector<int> numbersBubble = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    std::vector<int> numbersSelection = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    std::vector<int> numbersInsertion = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    std::vector<int> numbersMerge = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    std::vector<int> numberQuick = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    // Bubble Sort
    std::cout << "\nBefore bubble sorting:\n";
    printVector(numbersBubble);

    bubbleSort(numbersBubble);

    std::cout << "\nAfter bubble sorting:\n";
    printVector(numbersBubble);

    // Selection Sort
    std::cout << "\nBefore selection sorting:\n";
    printVector(numbersSelection);

    selectionSort(numbersSelection);

    std::cout << "\nAfter selection sorting:\n";
    printVector(numbersSelection);

    // Insertion Sort
    std::cout << "\nBefore insertion sorting:\n";
    printVector(numbersInsertion);

    insertionSort(numbersInsertion);

    std::cout << "\nAfter insertion sorting:\n";
    printVector(numbersInsertion);

    // Merge Sort
    std::cout << "\nBefore merge sorting:\n";
    printVector(numbersMerge);

    int vectorSize = numbersMerge.size();
    mergeSort(numbersMerge, 0, vectorSize - 1);

    std::cout << "\nAfter merge sorting:\n";
    printVector(numbersMerge);

    // Quick Sort
    std::cout << "\nBefore quick sorting:\n";
    printVector(numberQuick);

    vectorSize = numberQuick.size();
    quickSort(numberQuick, 0, vectorSize - 1);

    std::cout << "\nAfter quick sorting:\n";
    printVector(numberQuick);

    return 0;
}