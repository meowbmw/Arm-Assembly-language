#include <iostream>
#include <cstring>

extern "C" int abs_asm(int x);
extern "C" int sum_asm(int x);
extern "C" void *memcpy_asm(void *dest, const void *src, int n);
extern "C" void quick_sort(int arr[], int low, int high);

/*
TODOs:
abs
loop sum
memcpy
quicksort
*/
using namespace std;
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // int dest[] = {1, 2, 3, 4, 5};
    // int src[] = {4,5,6};
    // memcpy_asm(dest,src,3* sizeof(int));
    // for (int i = 0; i < 3; i++)
    // {cout << dest[i];}

    // cout << "The return value is: " << sum_asm(4) << endl;

}