/*
 * 将字符串中的每个空格替换成'%20',
 * 例如: 输入We are Happy.
 * 替换为: We%20are%20Happy
 * 注意:
 * 1. 原有字符串有足够的空间存储替换后的字符串
 * 2. 时间复杂度必须是O(n)
 * 
 * 衍生问题: 合并两个有序的数组
*/

#include <stdio.h>

void replaceblank(char *data, int length) {
    int clength = 0, blank = 0;

    // 空字符串或者没有足够的空间
    if(data == NULL || length <= 0) {
        return;
    }

    // 计算字符串中的空格数以及字符长度
    while(data[clength] != '\0') {
        if(data[clength] == ' ') {
            ++blank;
        }
        ++clength;
    }

    if (blank == 0) {  // 无空格, 直接返回即可
        return;
    }

    // 计算替换后的字符串长度
    int newlength = clength + blank * 2;

    if(newlength+1 > length) {
        printf("存储空间不够");
        return;
    }

    while(clength >= 0) {
        if(data[clength] == ' ') {
            data[newlength--] = '0';
            data[newlength--] = '2';
            data[newlength--] = '%';
        } else {
            data[newlength--] = data[clength];
        }
        --clength;
    }
}

// 有序数组的合并, 从后往前合并, 类似思想可以运用到链表数据的合并
void mergearray(int *data1, int *data2, int len1, int len2, int length) {
    if(len1 + len2 > length) {
        printf("空间不够");
        return;
    }
    int location = len1+len2-1;
    int loc1 = len1 - 1;
    int loc2 = len2 - 1;
    while(loc1 >= 0 && loc2 >= 0) {
        if(data1[loc1] > data2[loc2]) {
            data1[location] = data1[loc1];
            --loc1;
        } else {
            data1[location] = data2[loc2];
            --loc2;
        }
        --location;
    }

    // 复制data2剩余的数据即可, 当data1还剩余数据时, 就不用继续合并了.
    if(loc1 < 0) {  
        for(; loc2 >= 0;) {
            data1[location--] = data2[loc2--];
        }
    }
    for(int i=0; i<len1+len2; ++i) {
        printf("%d ", data1[i]);
    }
}

int main() {
    char data[100] = "We  are Happy";
    replaceblank(data, 100);
    printf("%s\n", data);

    char cdata2[100] = "";
    replaceblank(cdata2, 100);
    printf("%s\n", cdata2);

    int data1[100] = {-1, 1, 3, 5, 7, 9, 20, 23, 43};
    int data2[100] = {2, 4, 6, 8, 10, 100, 200, 301, 302, 303, 304};
    mergearray(data1, data2, 9, 11, 100);
    return 0;
}
