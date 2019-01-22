#include <stdio.h>
#include <stdbool.h>

// 二分查找的递归实现
int bsearchrecurse(int *data, int start, int end, int v) {
    if(start > end) return -1;
    int mid = start + (end-start)/2;
    if(data[mid] == v) {
        return mid;
    } else if(data[mid] > v) {
        return bsearchrecurse(data, start, mid-1, v);
    } else {
        return bsearchrecurse(data, mid+1, end, v);
    }
}
int bsearch(int *data, int n, int v) {
    return bsearchrecurse(data, 0, n-1, v);
}

// 二分查找的非递归实现
int bsearchiter(int *data, int n, int v) {
    int low = 0, high=n-1, mid;
    
    while(low <= high) {
        mid = low + (high-low)/2;
        if(data[mid] == v) return mid;
        else if(data[mid]>v) high = mid-1;
        else high = mid+1;
    }
    return -1;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(data)/sizeof(data[0]);
    int idx = bsearch(data, n, -8);
    printf("idx=%d\n", idx);
    return 0;
}
