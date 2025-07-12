#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1e5;

void Swap(int &a, int &b) { int c = a; a = b; b = c; }

#if 0 //# SelectionSort
void SelectionSort(int a[], int N) {
    // Ghi chú: tại sao không sử dụng kí hiệu & trong hàm này?
    /* Trả lời: Mảng trong C++ được truyền theo cơ chế tham chiếu (pass by reference) mặc định, nên không
        cần dùng kí hiệu &. Khi truyền mảng vào hàm, chỉ địa chỉ của phần tử đầu tiên được  truyền vào. */
    int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
    for (int i = 0; i < N - 1; i++) {
        // Ghi chú: vòng lặp này dùng để làm gì?
        /*  Trả lời: Vòng lặp này duyệt qua từng phần tử của mảng, chọn phần tử nhỏ nhất trong phần còn lại 
            của mảng để đặt vào vị trí i. */
        min = i;
        for (int j = i + 1; j < N; j++) {
            // Ghi chú: vòng lặp này dùng để làm gì?
            /*  Trả lời: Vòng lặp này dùng để tìm chỉ số của phần tử nhỏ nhất trong đoạn mảng chưa được 
                sắp xếp, bắt đầu từ vị trí i + 1 đến cuối mảng. Nó so sánh các phần tử để cập nhật giá 
                trị min nếu tìm thấy phần tử nhỏ hơn.*/
            if (a[j] > a[min]) {
                min = j;
                // Ghi chú: thao tác này dùng để làm gì?
                /*  Trả lời: Thao tác này cập nhật giá trị min thành chỉ số j nếu phần tử của chỉ số j nhỏ hơn 
                    phần tử của chỉ số min hiện tại. Điều này giúp ghi nhớ vị trí của phần tử nhỏ nhất tìm 
                    thấy trong đoạn mảng đang xét.*/
            }
        }
        if (min != i) {
            Swap(a[min], a[i]);
            // Ghi chu: thao tác này dùng để làm gì?
            /*  Trả lời: Thao tác này hoán đổi phần tử nhỏ nhất tìm thấy (tại a[min]) với phần tử ở vị trí đầu 
                của đoạn chưa sắp xếp (a[i]). Điều này đảm bảo phần tử nhỏ nhất được đặt vào đúng vị trí trong 
                mảng sau mỗi lần lặp.*/
        }
    }
}

int main() {
    #if 0
    int x[10] = {12, 2, 8, 5, 1, 6, 4, 15}; // khởi tạo các giá trị trong mảng
    int n = 8;                              // số phần tử của mảng
    SelectionSort(x, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    #endif
    #if 1
    ifstream ifile("input.txt");
    if (!ifile) {
        cout << "Can not file input.txt" << endl;
        return 0;
    }
    int x[MAXN], n = 0;
    while(ifile >> x[n]) ++n;
    ifile.close();
    SelectionSort(x, n);
    ofstream ofile("output.txt");
    for (int i = 0; i < n; i++)
        ofile << x[i] << ' ';
    ofile.close();
    #endif
}
#endif

#if 0 //# Heap Sort
// Shift === Heapify
void Shift(int a[], int left, int right) {
    int x, curr, joint;
    curr = left;
    joint = 2 * curr + 1; // Con trái
    x = a[curr];
    while (joint <= right) {
        if (joint < right && a[joint] < a[joint + 1]) 
            joint = joint + 1;
        if (a[joint] < x) break;
        a[curr] = a[joint];
        curr = joint;
        joint = 2 * curr + 1;
    }
    a[curr] = x;
}

void CreateHeap(int a[], int N) {
    for (int left = (N - 1) / 2; left >= 0; left--)
        Shift(a, left, N - 1);
}

void HeapSort(int a[], int N) {
    CreateHeap(a, N); 
    for (int i = N - 1; i > 0; i--) {
        Swap(a[0], a[i]); 
        Shift(a, 0, i - 1);
    }
}

void ShiftMin(int a[], int left, int right) {
    int x, curr, joint;
    curr = left;
    joint = 2 * curr + 1;
    x = a[curr];
    while (joint <= right) {
        if (joint < right && a[joint] > a[joint + 1])
            joint = joint + 1;
        if (a[joint] > x) break;
        a[curr] = a[joint];
        curr = joint;
        joint = 2 * curr + 1;
    }
    a[curr] = x;
}

void CreateMinHeap(int a[], int N) {
    for (int left = (N - 1) / 2; left >= 0; left--)
        ShiftMin(a, left, N - 1);
}

void HeapSortDescending(int a[], int N) {
    CreateMinHeap(a, N);
    for (int i = N - 1; i > 0; i--) {
        Swap(a[0], a[i]);
        ShiftMin(a, 0, i - 1);
    }
}

int main() {
    #if 0
    int x[10] = {12, 2, 8, 5, 1, 6, 4, 15}; // khởi tạo các giá trị trong mảng
    int n = 8;                              // số phần tử của mảng
    HeapSort(x, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    #endif
    #if 1
    ifstream ifile("input.txt");
    if (!ifile) {
        cout << "Can not file input.txt" << endl;
        return 0;
    }
    int x[MAXN], n = 0;
    while(ifile >> x[n]) ++n;
    ifile.close();
    // HeapSort(x, n);
    HeapSortDescending(x, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    #endif
}
#endif

#if 0 //# Quick Sort
/* Đếm số phép gán & Đếm số phép so sánh
int assignments = 0; // Đếm số phép gán
int comparisons = 0; // Đếm số phép so sánh

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    assignments += 3; // 3 phép gán trong Swap
}

void QuickSort(int a[], int left, int right) {
    if (left >= right) return;
    int i, j, x;
    x = a[(left + right) / 2]; // Chọn phần tử mốc
    assignments++; // Gán giá trị cho x
    i = left;
    j = right;
    assignments += 2; // Gán i và j
    while (i < j) {
        while (a[i] < x) {
            i++;
            comparisons++; // So sánh a[i] < x
        }
        while (a[j] > x) {
            j--;
            comparisons++; // So sánh a[j] > x
        }
        if (i <= j) {
            Swap(a[i], a[j]);
            i++;
            j--;
            assignments += 2; // Gán mới i, j
        }
    }
    
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}
 */

void QuickSort(int a[], int left, int right) {
    int i, j, x;
    if (left >= right) return;
    x = a[(left + right) / 2]; // chọn phần tử giữa làm giá trị mốc
    i = left;
    j = right;
    while (i < j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}

int main() {
    #if 0
    int x[10] = {12, 2, 8, 5, 1, 6, 4, 15}; // khởi tạo các giá trị trong mảng
    int n = 8;                              // số phần tử của mảng
    QuickSort(x, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    #endif
    #if 1
    ifstream ifile("input.txt");
    if (!ifile) {
        cout << "Can not file input.txt" << endl;
        return 0;
    }
    int x[MAXN], n = 0;
    while(ifile >> x[n]) ++n;
    ifile.close();
    QuickSort(x, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << "\nSo phep hoan doi: " << assignments;
    cout << "\nSo phep so sanh: " << comparisons << endl;
    #endif
}
#endif

#if 1 //# Merge Sort
int b[MAXN], c[MAXN], nb, nc; // Ghi chú: 2 mảng này dùng để làm gì?
/*  Trả lời: Mảng b[] và c[] được sử dụng để lưu hai nửa của dãy a[] trong quá trình phân tách và trộn (merge). */
    #if 0 // increase
    void Distribute(int a[], int N, int &nb, int &nc, int k) {
        int i, pa, pb, pc; // Ghi chú: các biến này có ý nghĩa gì?
        /*  Trả lời:
            i: Biến đếm trong vòng lặp (kiểm soát số phần tử di chuyển vào b[] hoặc c[]).
            pa: Vị trí hiện tại trong mảng a[] (quét toàn bộ mảng a[]).
            pb: Vị trí hiện tại trong mảng b[] (điểm chèn phần tử tiếp theo vào b[]).
            pc: Vị trí hiện tại trong mảng c[] (điểm chèn phần tử tiếp theo vào c[]).
        */
        pa = pb = pc = 0;
        while (pa < N) {
            for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) {
                // Ghi chú: vòng lặp này có ý nghĩa gì?
                /*  Trả lời
                    Sao chép k phần tử từ a[] vào b[], bắt đầu từ pa. Nếu còn phần tử trong a[] (pa < N) và 
                    chưa đạt k phần tử (i < k), tiếp tục chép vào b[].Tăng pa và pb sau mỗi lần sao chép để 
                    tiếp tục duyệt qua a[] và cập nhật b[].
                */
                b[pb] = a[pa];
            }
            for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) {
                // Ghi chú: vòng lặp này có ý nghĩa gì?
                /*  Trả lời:
                    Sao chép k phần tử tiếp theo từ a[] vào c[]. Hoạt động tương tự như vòng lặp trước nhưng 
                    chép vào c[] thay vì b[]. Giúp phân chia a[] thành hai nhóm con có kích thước tối đa k.
                */
                c[pc] = a[pa];
            }
        }
        nb = pb;
        nc = pc;
    }

    void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k) {
        int rb, rc;
        rb = min(nb, pb + k);
        rc = min(nc, pb + k);
        while ((pb < rb) && (pc < rc)) {
            if (b[pb] < c[pc])
                a[pa++] = b[pb++];
            else
                a[pa++] = c[pc++];
        }
        while (pb < rb) {
            a[pa++] = b[pb++];
        }
        while (pc < rc) {
            a[pa++] = c[pc++];
        }
    }

    void Merge(int a[], int nb, int nc, int k) {
        int pa, pb, pc;
        pa = pb = pc = 0;
        while ((pb < nb) && (pc < nc)) {
            MergeSubarr(a, nb, nc, pa, pb, pc, k);
        }
        while (pb < nb) {
            a[pa++] = b[pb++]; // Ghi chú: câu lệnh này có ý nghĩa gì?
            /*  Trả lời: Khi tất cả phần tử trong c[] đã được đưa vào a[], nhưng b[] vẫn còn phần tử chưa 
                xét, câu lệnh này sao chép các phần tử còn lại từ b[] vào a[]. pb++ giúp tiếp tục duyệt 
                phần tử tiếp theo trong b[].
            */
        }
        while (pc < nc) {
            a[pa++] = c[pc++]; // Ghi chú: câu lệnh này có ý nghĩa gì?
            /*  Trả lời: Khi tất cả phần tử trong b[] đã được đưa vào a[], nhưng c[] vẫn còn phần tử chưa 
                xét, câu lệnh này sao chép các phần tử còn lại từ c[] vào a[]. pc++ giúp tiếp tục duyệt 
                phần tử tiếp theo trong c[].
            */
        }
    }

    void MergeSort(int a[], int N) {
        int k = 1;
        while (k < N) {
            Distribute(a, N, nb, nc, k);
            Merge(a, nb, nc, k);
            k *= 2;
        }
    }
    #endif

    #if 1 // decrease
    void Distribute(int a[], int N, int &nb, int &nc, int k) {
        int i, pa, pb, pc;
        pa = pb = pc = 0;
        while (pa < N) {
            for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) b[pb] = a[pa];
            for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) c[pc] = a[pa];
        }
        nb = pb;
        nc = pc;
    }

    void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k) {
        int rb = min(nb, pb + k);
        int rc = min(nc, pc + k);
        while ((pb < rb) && (pc < rc)) {
            if (b[pb] > c[pc]) a[pa++] = b[pb++];
            else a[pa++] = c[pc++];
        }
        while (pb < rb) a[pa++] = b[pb++];
        while (pc < rc) a[pa++] = c[pc++];
    }

    void Merge(int a[], int nb, int nc, int k) {
        int pa, pb, pc;
        pa = pb = pc = 0;
        while ((pb < nb) && (pc < nc)) MergeSubarr(a, nb, nc, pa, pb, pc, k);
        while (pb < nb) a[pa++] = b[pb++];
        while (pc < nc) a[pa++] = c[pc++];
        
    }

    void MergeSort(int a[], int N) {
        int k = 1;
        while (k < N) {
            Distribute(a, N, nb, nc, k);
            Merge(a, nb, nc, k);
            k *= 2;
        }
    }    
    #endif

int main() {
    int x[] = {5, 2, 9, 3, 7, 2, 4, 11}; // khởi tạo các giá trị trong mảng
    int n = sizeof(x) / sizeof(x[0]);    // số phần tử của mảng
    MergeSort(x, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
}
#endif