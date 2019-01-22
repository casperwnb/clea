#include <stdio.h>

int bsearchlast(int *data, int n, int v) {
    int low = 0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(data[mid] > v) high = mid - 1;
        else if(data[mid] < v) low = mid + 1;
        else {
            if(mid == n-1 || data[mid+1] != v) return mid;
            else low = mid + 1;
        }
    }
    return -1;
}

// 查找最后一个出现的元素, 经过多次查找后, 如果存在该元素, high一定就是
// 最后的下标值
int bsearchlasthard(int *data, int n, int v) {
    int low=0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(data[mid] <= v) low = mid+1;
        else high = mid-1;
    }
    if(data[high] == v) return high;
    return -1;
}

int main() {
    int data[] = {1, 3, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(data)/sizeof(data[0]);
    int idx = bsearchlasthard(data, n, 8);
    printf("%d\n", idx);
    return 0;
}
