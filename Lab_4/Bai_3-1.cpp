#include <stdio.h>
int Hash(int k, int M)
{
    if (M == 0)
    return 0;
    return (k % M);
}
void InitHash(int *&U, int M)
{
    int K[5] = {1,2,4,6,9}; // stl set
    int i, pos;
    for(i = 0; i < M; i++) U[i] = 0;
    for(i = 0; i < 5; i++)
    {
        pos = Hash(K[i], M);
        U[pos] = K[i];
    }
}
int main(int argc, char* argv[])
{
    int M = 10;
    int *U = new int[M];
    int pos;
    InitHash(U, M);
    int x;
    printf("Nhap khoa tim kiem: ");
    scanf("%d", &x);
    pos = Hash(x, M);
    if (U[pos] == 0){
        printf("Khong tim thay khoa trong bang bam\n");
    }
    else{
        printf("Gia tri phan tu can tim kiem: %d\n", U[pos]);
    }
    return 0;
}