#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class Sort {
private:
    int comparisons;
    int swaps;

public:
    Sort() {
        comparisons = 0;
        swaps = 0;
        srand(time(0));
    }

    void resetCounts() {
        comparisons = 0;
        swaps = 0;
    }

    void generateRandomArray(int* arr, int n) {
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100;
    }

    void selectionSort(int* arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
                swaps++;
            }
        }
    }

    void bubbleSort(int* arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    swapped = true;
                }
            }

            if (not swapped) break;
        }
    }

    void insertionSort(int* arr, int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 and arr[j] > key) {
                comparisons++;
                arr[j + 1] = arr[j];
                j--;
                swaps++;
            }
            if (j >= 0) comparisons++;
            arr[j + 1] = key;
        }
    }

    void performSort(int* arr, int n, string choice) {
        resetCounts();

        if (choice == "selection") {
            selectionSort(arr, n);
        } else if (choice == "bubble") {
            bubbleSort(arr, n);
        } else if (choice == "insertion") {
            insertionSort(arr, n);
        } else {
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "\nSorted array using " << choice << " sort:\n\n";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n\nComparisons: " << comparisons;
        cout << "\nSwaps: " << swaps << "\n";
    }

    void analyze(int n) {
        int* original = new int[n];
        generateRandomArray(original, n);

        cout << "\nGenerated Array: ";
        for (int i = 0; i < n; i++) cout << original[i] << " ";
        cout << "\n\n";

        int* selectionSortArray = new int[n];
        int* bubbleSortArray = new int[n];
        int* insertionSortArray = new int[n];

        copy(original, original + n, selectionSortArray);
        copy(original, original + n, bubbleSortArray);
        copy(original, original + n, insertionSortArray);

        int selectionComparisons, bubbleComparisons, insertionComparisons;
        int selectionSwaps, bubbleSwaps, insertionSwaps;

        resetCounts();
        selectionSort(selectionSortArray, n);
        selectionComparisons = comparisons; selectionSwaps = swaps;

        resetCounts();
        bubbleSort(bubbleSortArray, n);
        bubbleComparisons = comparisons; bubbleSwaps = swaps;

        resetCounts();
        insertionSort(insertionSortArray, n);
        insertionComparisons = comparisons; insertionSwaps = swaps;

        cout << "\n--- Sorting Analysis ---\n";
        cout << "Selection Sort -> Comparisons: " << selectionComparisons << ", Swaps: " << selectionSwaps << endl;
        cout << "Bubble Sort    -> Comparisons: " << bubbleComparisons << ", Swaps: " << bubbleSwaps << endl;
        cout << "Insertion Sort -> Comparisons: " << insertionComparisons << ", Swaps: " << insertionSwaps << endl;

        int totalOps[3] = {
            selectionComparisons + selectionSwaps,
            bubbleComparisons + bubbleSwaps,
            insertionComparisons + insertionSwaps
        };
        string names[3] = {"Selection Sort", "Bubble Sort", "Insertion Sort"};

        int best = 0, worst = 0;
        for (int i = 1; i < 3; i++) {
            if (totalOps[i] < totalOps[best]) best = i;
            if (totalOps[i] > totalOps[worst]) worst = i;
        }

        cout << "\nBest Technique: " << names[best];
        cout << "\nWorst Technique: " << names[worst] << endl;

        delete[] selectionSortArray;
        delete[] bubbleSortArray;
        delete[] insertionSortArray;
        delete[] original;
    }
};

int main() {
    Sort sorter;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    string choice;
    cout << "\nEnter sorting technique (selection / bubble / insertion): ";
    cin >> choice;

    sorter.performSort(arr, n, choice);

    cout << "\n\n--- Performing Sorting Analysis on Random Array ---\n";
    sorter.analyze(n);

    delete[] arr;
    return 0;
}