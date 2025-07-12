#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;
using namespace chrono;

struct SortStats {
    long long comparisons = 0;
    long long assignments = 0;
};
// 1. Viết chương trình so sánh các thuật toán Selection Sort, Heap Sort, Quick Sort, Merge Sort.
#if 0 
// Selection Sort
void selectionSort(vector<int>& arr, SortStats& stats) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            stats.comparisons++; // So sánh
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
        stats.assignments += 3; // Swap có 3 phép gán
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i, SortStats& stats) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        stats.comparisons++;
        if (arr[left] > arr[largest]) largest = left;
    }
    if (right < n) {
        stats.comparisons++;
        if (arr[right] > arr[largest]) largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        stats.assignments += 3;
        heapify(arr, n, largest, stats);
    }
}

void heapSort(vector<int>& arr, SortStats& stats) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, stats);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        stats.assignments += 3;
        heapify(arr, i, 0, stats);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high, SortStats& stats) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        stats.comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            stats.assignments += 3;
        }
    }
    swap(arr[i + 1], arr[high]);
    stats.assignments += 3;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, SortStats& stats) {
    if (low < high) {
        int pi = partition(arr, low, high, stats);
        quickSort(arr, low, pi - 1, stats);
        quickSort(arr, pi + 1, high, stats);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right, SortStats& stats) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        stats.assignments++;
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
        stats.assignments++;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        stats.comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        stats.assignments++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        stats.assignments++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        stats.assignments++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, SortStats& stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, stats);
        mergeSort(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

int main() {
    const int SIZE = 10000; // Kích thước mảng
    vector<int> originalArr(SIZE);
    for (int& num : originalArr)
        num = rand() % 100000; // Sinh số ngẫu nhiên từ 0 đến 99999

    cout << "So sanh cac thuat toan sap xep voi " << SIZE << " phan tu:\n\n";

    vector<int> selectionArr = originalArr;
    SortStats selectionStats;
    auto start = high_resolution_clock::now();
    selectionSort(selectionArr, selectionStats);
    auto stop = high_resolution_clock::now();
    double selectionDuration = duration_cast<microseconds>(stop - start).count() / 1000.0;

    cout << "Selection Sort:\n";
    cout << "  - Thoi gian: " << selectionDuration << " ms\n";
    cout << "  - So phep so sanh: " << selectionStats.comparisons << "\n";
    cout << "  - So phep gan: " << selectionStats.assignments << "\n\n";

    vector<int> heapArr = originalArr;
    SortStats heapStats;
    start = high_resolution_clock::now();
    heapSort(heapArr, heapStats);
    stop = high_resolution_clock::now();
    double heapDuration = duration_cast<microseconds>(stop - start).count() / 1000.0;

    cout << "Heap Sort:\n";
    cout << "  - Thoi gian: " << heapDuration << " ms\n";
    cout << "  - So phep so sanh: " << heapStats.comparisons << "\n";
    cout << "  - So phep gan: " << heapStats.assignments << "\n\n";

    vector<int> quickArr = originalArr;
    SortStats quickStats;
    start = high_resolution_clock::now();
    quickSort(quickArr, 0, quickArr.size() - 1, quickStats);
    stop = high_resolution_clock::now();
    double quickDuration = duration_cast<microseconds>(stop - start).count() / 1000.0;

    cout << "Quick Sort:\n";
    cout << "  - Thoi gian: " << quickDuration << " ms\n";
    cout << "  - So phep so sanh: " << quickStats.comparisons << "\n";
    cout << "  - So phep gan: " << quickStats.assignments << "\n\n";

    vector<int> mergeArr = originalArr;
    SortStats mergeStats;
    start = high_resolution_clock::now();
    mergeSort(mergeArr, 0, mergeArr.size() - 1, mergeStats);
    stop = high_resolution_clock::now();
    double mergeDuration = duration_cast<microseconds>(stop - start).count() / 1000.0;

    cout << "Merge Sort:\n";
    cout << "  - Thoi gian: " << mergeDuration << " ms\n";
    cout << "  - So phep so sanh: " << mergeStats.comparisons << "\n";
    cout << "  - So phep gan: " << mergeStats.assignments << "\n\n";

    return 0;
}
#endif

// 2. Viết chương trình so sánh hiệu suất giữa QuickSort với pivot là phần tử đầu dãy và pivot là phần tử giữa dãy.
#if 0 
// QuickSort - Pivot là phần tử đầu dãy
int partitionFirst(vector<int>& arr, int low, int high, SortStats& stats) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) { i++; stats.comparisons++; }
        while (i <= j && arr[j] > pivot) { j--; stats.comparisons++; }
        if (i < j) {
            swap(arr[i], arr[j]);
            stats.assignments += 3;
        }
    }
    swap(arr[low], arr[j]);  // Đưa pivot về đúng vị trí
    stats.assignments += 3;
    return j;
}

void quickSortFirst(vector<int>& arr, int low, int high, SortStats& stats) {
    if (low < high) {
        int pivotIndex = partitionFirst(arr, low, high, stats);
        quickSortFirst(arr, low, pivotIndex - 1, stats);
        quickSortFirst(arr, pivotIndex + 1, high, stats);
    }
}

// QuickSort - Pivot là phần tử giữa dãy
int partitionMiddle(vector<int>& arr, int low, int high, SortStats& stats) {
    int mid = (low + high) / 2;
    swap(arr[low], arr[mid]);  // Đưa phần tử giữa về đầu
    stats.assignments += 3;
    return partitionFirst(arr, low, high, stats);  // Sử dụng lại partitionFirst
}

void quickSortMiddle(vector<int>& arr, int low, int high, SortStats& stats) {
    if (low < high) {
        int pivotIndex = partitionMiddle(arr, low, high, stats);
        quickSortMiddle(arr, low, pivotIndex - 1, stats);
        quickSortMiddle(arr, pivotIndex + 1, high, stats);
    }
}

// Hàm chạy benchmark và đo thời gian
void benchmarkQuickSort(vector<int> arr, bool useMiddlePivot) {
    SortStats stats;
    auto start = high_resolution_clock::now();
    if (useMiddlePivot) quickSortMiddle(arr, 0, arr.size() - 1, stats);
    else quickSortFirst(arr, 0, arr.size() - 1, stats);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << (useMiddlePivot ? "Pivot giua:" : "Pivot dau:") << "\n  - Thoi gian: " 
         << duration.count() << "ms\n  - So phep so sanh: " << stats.comparisons 
         << "\n  - So phep gan: " << stats.assignments << "\n";
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = rand() % 1000000;
    cout << "So sanh QuickSort voi cac cach chon pivot:\n\n";
    benchmarkQuickSort(arr, false); // Pivot là phần tử đầu
    cout << endl;
    benchmarkQuickSort(arr, true);  // Pivot là phần tử giữa
    return 0;
}
#endif

// 3. Insertion Sort.
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. Binary Insertion Sort.
int binarySearch(vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > item) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        for (int j = i; j > pos; j--)
            arr[j] = arr[j - 1];
        arr[pos] = key;
    }
}

// 5. Interchange Sort.
void interchangeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

// 6. Bubble Sort.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 7. Shaker Sort.
void shakerSort(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        left++;
    }
}

// 8. Shell Sort.
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i], j = i;
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

// 9. Radix Sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 45, 3, 2};
    // Gọi từng thuật toán sắp xếp
    
    vector<int> a = arr;
    cout << "Insertion Sort: ";
    insertionSort(arr);
    for(int i : arr) cout << i << " ";

    a = arr;
    cout << "\nBinary Insertion Sort: ";
    binaryInsertionSort(arr);
    for(int i : arr) cout << i << " ";

    a = arr;
    cout << "\nInterchange Sort: ";
    interchangeSort(arr);
    for(int i : arr) cout << i << " ";

    a = arr;
    cout << "\nBubble Sort: ";
    bubbleSort(arr);
    for(int i : arr) cout << i << " ";

    a = arr;
    cout << "\nShaker Sort: ";
    shakerSort(arr);
    for(int i : arr) cout << i << " ";
    
    a = arr;
    cout << "\nShell Sort: ";
    shellSort(arr);
    for(int i : arr) cout << i << " ";

    a = arr;
    cout << "\nRadix Sort: ";
    radixSort(arr);
    for(int i : arr) cout << i << " ";

    return 0;
}
