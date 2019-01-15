#include <stdio.h>
#include <stdlib.h>

// 归并排序算法的核心部分其实就是merge的部分, 会一直拆分数据, 直到最后剩下两个元素的时候
// 开始合并数据, 因此需要注意递归的深度问题
// TODO: merge函数还可以通过哨兵的方式优化代码? HOW
// HOW: 两个数组最后都存储一个最大的值当做哨兵? 
void merge(int *data, int *tmp, int start, int mid, int end) {
    int i=start, j=mid+1, k=start;
    while(i != mid+1 && j != end+1) {
        if(data[i] > data[j]) {
            tmp[k++] = data[j++];
        } else {
            tmp[k++] = data[i++];
        }
    }

    while(i != mid+1) {
        tmp[k++] = data[i++];
    }

    while(j != end+1) {
        tmp[k++] = data[j++];
    }

    for(i=start; i<=end; ++i) {
        data[i] = tmp[i];
    }
}

void mergesort_c(int *data, int *tmp, int start, int end) {
    if(start >= end) return;

    int mid = start + (end-start) / 2;
    mergesort_c(data, tmp, start, mid);
    mergesort_c(data, tmp, mid+1, end);

    merge(data, tmp, start, mid, end);

}

void merge_sort(int *data, int n) {
    int *tmp = (int*)malloc(sizeof(int) * n);
    mergesort_c(data, tmp, 0, n-1);
    for(int i=0; i<n; ++i) {
        data[i] = tmp[i];
    }
    free(tmp);
}

int main() {
    int data[] = {3, 4, 5, 1, 2, 6, 7, 9, 10, 8, 9};
    int count = sizeof(data) / sizeof(int);
    merge_sort(data, count);

    for(int i=0; i<count; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

/*
稳定算法, 时间复杂度计算方法: 递推关系是: T(a) = T(b) + T(c) + K K是将两个子问题结果合并
成问题时所消耗的时间.

利用上述的递推关系, 可以假设对n个元素进行归并排序需要的时间是T(n), 则分解为两个子数组排序的时间
是T(n/2), merge合并两个有序子数组的时间复杂度是O(n), 所以套用递推公式, 归并排序的时间复杂度的
计算公式是:

T(1) = C // n=1时, 只需要常数级的执行时间
T(n) = 2*T(n/2) + n n>1时

T(n) = 2*T(n/2) + n
     = 2*(2*T(n/4) + n/2) + n = 4*T(n/4) + 2n
     = 4*(2*T(n/8) + n/4) + 2n = 8*T(n/8) + 3n
     = ....
     = 2^k*T(n/2^k) + k*n

当T(n/2^k) = T(1)时, 得到k=lgn, 因此T(n) = Cn + nlgn
用大O表示则时间复杂度就是O(nlogn)

归并排序的执行效率与要排序的原始数组的有序程度无关, 其时间复杂度是非常稳定的.

归并排序的空间复杂度是O(n)
 */

/*
python版本归并排序:
# encoding: utf-8

# merge使用哨兵
def merge(data, start, mid, end):
    left = data[start:mid+1]
    right = data[mid+1:end+1]

    maxvalue = float("inf")
    left.append(maxvalue)
    right.append(maxvalue)
    i = j = 0
    k = start

    # 使用left的理由: 1. left中的个数一定会大于等于right
    # 使用!=比使用<的效率会高一点儿
    while left[i] != maxvalue:
        if left[i] < right[j]:
            data[k] = left[i]
            i += 1
        else:
            data[k] = right[j]
            j += 1
        
        k += 1

def merge(data, start, mid, end):
    i = start
    j = mid+1
    tmps = []
    while i <= mid and j <= end:
        if data[i] > data[j]:
            tmps.append(data[j])
            j += 1
        else:
            tmps.append(data[i])
            i += 1

    while i <= mid:
        tmps.append(data[i])
        i += 1

    while j <= end:
        tmps.append(data[j])
        j += 1
    data[start:end+1] = tmps

def mergesort_c(data, start, end):
    if start >= end:
        return
    
    mid = int((start+end) / 2)
    mergesort_c(data, start, mid)
    mergesort_c(data, mid+1, end)

    merge(data, start, mid, end)

def mergesort(data):
    size = len(data)
    mergesort_c(data, 0, size-1)

data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
mergesort(data)
print(data)
 */
