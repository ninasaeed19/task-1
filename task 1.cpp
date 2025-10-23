#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time() and clock()
#include <fstream>   // for writing to files (CSV)
using namespace std;

// 1. bubble sort
// goes through the array again and again
// swapping two elements if they’re in the wrong order
// counts how many comparisons are made
int bubble_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return count;
}

// 2. selection sort
// finds the smallest element in the unsorted part
// and puts it at the beginning
// counts how many comparisons are made
int selection_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return count;
}

// 3. insertion sort
// builds the sorted array one item at a time
// compares the current element with all elements before it
int insertion_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            count++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    return count;
}

// 4. arrays
// make_random()  - fills array with random numbers 0–99
// make_sorted()  - fills array with 0,1,2...
// make_reversed()- fills array with n,n-1...
void make_random(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}
void make_sorted(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}
void make_reversed(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

// 5. main test function
// this runs all 3 sorting algorithms on 3 types of arrays:
// random, sorted, and reversed
// for different sizes 
// it counts comparisons and measures time using clock()
void test_comparisons() {
    srand(time(0)); // makes random numbers different each time

    // two files for Excel
    ofstream comp("comparisons.csv"); // for number of comparisons
    ofstream times("time.csv");       // for execution time 

    // first line in each file = column headers
    comp << "Size,Case,Bubble,Selection,Insertion\n";
    times << "Size,Case,Bubble,Selection,Insertion\n";

    int arr[100]; // array large enough for all tests

    
    for (int n = 5; n <= 30; n++) {
        cout << "\nTesting array size: " << n << " \n";

        // random array
        make_random(arr, n);
        clock_t start = clock(); // start timer
        int b1 = bubble_sort_count(arr, n);
        clock_t end = clock();   // stop timer
        double tb1 = double(end - start) / CLOCKS_PER_SEC;

        make_random(arr, n);
        start = clock();
        int s1 = selection_sort_count(arr, n);
        end = clock();
        double ts1 = double(end - start) / CLOCKS_PER_SEC;

        make_random(arr, n);
        start = clock();
        int i1 = insertion_sort_count(arr, n);
        end = clock();
        double ti1 = double(end - start) / CLOCKS_PER_SEC;

        // save random results
        comp << n << ",Random," << b1 << "," << s1 << "," << i1 << "\n";
        times << n << ",Random," << tb1 << "," << ts1 << "," << ti1 << "\n";

        // sorted array
        make_sorted(arr, n);
        start = clock();
        int b2 = bubble_sort_count(arr, n);
        end = clock();
        double tb2 = double(end - start) / CLOCKS_PER_SEC;

        make_sorted(arr, n);
        start = clock();
        int s2 = selection_sort_count(arr, n);
        end = clock();
        double ts2 = double(end - start) / CLOCKS_PER_SEC;

        make_sorted(arr, n);
        start = clock();
        int i2 = insertion_sort_count(arr, n);
        end = clock();
        double ti2 = double(end - start) / CLOCKS_PER_SEC;

        // save sorted results
        comp << n << ",Sorted," << b2 << "," << s2 << "," << i2 << "\n";
        times << n << ",Sorted," << tb2 << "," << ts2 << "," << ti2 << "\n";

        // reversed array
        make_reversed(arr, n);
        start = clock();
        int b3 = bubble_sort_count(arr, n);
        end = clock();
        double tb3 = double(end - start) / CLOCKS_PER_SEC;

        make_reversed(arr, n);
        start = clock();
        int s3 = selection_sort_count(arr, n);
        end = clock();
        double ts3 = double(end - start) / CLOCKS_PER_SEC;

        make_reversed(arr, n);
        start = clock();
        int i3 = insertion_sort_count(arr, n);
        end = clock();
        double ti3 = double(end - start) / CLOCKS_PER_SEC;

        // save reversed results
        comp << n << ",Reversed," << b3 << "," << s3 << "," << i3 << "\n";
        times << n << ",Reversed," << tb3 << "," << ts3 << "," << ti3 << "\n";

        cout << "→ Finished testing size " << n << endl;
    }

    comp.close();
    times.close();

    cout << "\n Files created:\n";
    cout << "   - comparisons.csv  (number of comparisons)\n";
    cout << "   - time.csv         (execution time in seconds)\n";

}

// 6. main function
int main() {
    test_comparisons();
    return 0;
}
