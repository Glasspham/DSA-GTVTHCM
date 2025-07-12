#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
struct Word
{
    int key;
    char value[128];
};
int Hash(int k, int M)
{
    if (M == 0) return 0;
    return (k % M);
}
void InitHash(Word *&U, int M)
{
    Word K[5];
    K[0].key = 1; // MSSV
    strcpy(K[0].value, "Messi");
    K[1].key = 3;
    strcpy(K[1].value, "Ronaldo");
    K[2].key = 5;
    strcpy(K[2].value, "Rooney");
    K[3].key = 7;
    strcpy(K[3].value, "Drogba");
    K[4].key = 9;
    strcpy(K[4].value, "Xavi");
    int i, pos;
    for (i = 0; i < M; i++)
        U[i].key = 0;
    for (i = 0; i < 5; i++)
    {
        pos = Hash(K[i].key, M);
        U[pos] = K[i];
    }
}
int main(int argc, char *argv[])
{
    int M = 10;
    Word *U = new Word[M];
    int pos;
    InitHash(U, M);
    int x;
    printf("Nhap MSSV tim kiem: ");
    scanf("%d", &x);
    pos = Hash(x, M);
    if (U[pos].key == 0)
    {
        printf("Khong tim thay SV nao trong bang bam\n");
    }
    else
    {
        printf("Ten cua SV can tim kiem la: %s\n", U[pos].value);
    }
    return 0;
}
#endif

#if 1
struct Word {
    int key;
    char value[128];
};

int Hash(int k, int M) {
    if (M == 0) return 0;
    return (k % M);
}

void InitHash(Word *&U, int M, Word *K, int n) {
    for (int i = 0; i < M; i++)
        U[i].key = 0;  // Đánh dấu ô trống
    for (int i = 0; i < n; i++) {
        int pos = Hash(K[i].key, M);
        U[pos] = K[i];  // Lưu vào bảng băm
    }
}

int main() {
    int M = 10;  // Kích thước bảng băm
    int n;       // Số lượng sinh viên nhập vào
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    Word *K = new Word[n];  // Mảng chứa dữ liệu nhập vào
    for (int i = 0; i < n; i++) {
        printf("Nhap MSSV thu %d: ", i + 1);
        scanf("%d", &K[i].key);
        printf("Nhap ten SV: ");
        scanf(" %[^\n]", K[i].value);
    }
    Word *U = new Word[M];  // Bảng băm
    InitHash(U, M, K, n);
    // Tìm kiếm sinh viên
    int x;
    printf("Nhap MSSV tim kiem: ");
    scanf("%d", &x);
    int pos = Hash(x, M);
    if (U[pos].key == 0)
        printf("Khong tim thay SV nao trong bang bam\n");
    else printf("Ten cua SV can tim kiem la: %s\n", U[pos].value);
    // Giải phóng bộ nhớ
    delete[] K;
    delete[] U;
    return 0;
}
#endif