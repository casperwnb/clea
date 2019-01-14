#include <stdio.h>
#include <stdbool.h>

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void selectsort(int *data, int n) {
    for(int i=0; i<n; ++i) {
        int min=i, j = i+1;
        for(; j < n; ++j) {
            if(data[min] > data[j]) {
                min = j;
            }
        }
        if(min != i) {
            int tmp = data[i];
            data[i] = data[min];
            data[min] = tmp;
        }
    }
}

int main() {
    int data[] = {3, 5, 4, 1, 2, 6, 7};
    int n = sizeof(data)/sizeof(data[0]);
    selectsort(data, n);
    printarray(data, n);
    return 0;
}


/*
Python版本插入排序:
def selectsort(data):
    size = len(data)
    for i in range(size):
        minidx = i
        for j in range(i+1, size):
            if data[minidx] > data[j]:
                minidx = j

        if minidx != i:
            data[minidx], data[i] = data[i], data[minidx]
*/
