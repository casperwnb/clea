#include <stdio.h>

// 当data[mid] <= v时, 此时进行判断,
// 当mid=n-1时, 直接返回mid
// 当data[mid+1] > v时, 此时就是第一个大于等于给定值的位置,
// 否则调整low的值
int bsearchlastle(int *data, int n, int v) {
    int low = 0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(data[mid] <= v) {
            if(mid == n-1 || data[mid+1] > v) return mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

/*
 * 理解:
 * 当data[mid] < v时, 提升low的值
 * 当data[mid] > v时, high的值需要更新
 */
int bsearchlastlehard(int *data, int n, int v) {
    int low=0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if (data[mid] <= v) {
            if(high == low) return high;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return high;
}

int main() {
    int data[] = {1, 3, 4, 6, 6, 6, 6, 7, 8, 9};
    int n = sizeof(data)/sizeof(data[0]);
    int v = 50;
    int idx = bsearchlastlehard(data, n, v);
    printf("%d\n", idx);
    idx = bsearchlastle(data, n, v);
    printf("%d\n", idx);
    return 0;
}
