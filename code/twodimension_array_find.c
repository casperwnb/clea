/*
 * 题目:
 * 在一个二维数组中, 每一行都按照从左到右递增的顺序排列,
 * 每一列都按照从上到下递增的顺序排序. 请查找该二维数组中是否存在
 * 给定的某个整数.
 * 例如:
    1 2 8 9
    2 4 9 12
    4 7 10 13
    6 8 11 15
*/

#include <stdio.h>
#include <stdbool.h>

// 从右上角或左下角开始进行查找, 因为从此处开始查找时,
// 每比一次就可以排除一行或者一列数据
// 如果从左上或右下开始比较, 则无法排除更多的数据, 效率就很低.
bool findnum(int *data, int rows, int columns, int num) {
    if(data != NULL && rows > 0 && columns > 0) {
        int row = 0;  // 左上
        int column = columns - 1;
        int cur = 0;
        while(row<rows && column >= 0) {
            cur = row * columns + column;
            if(data[cur] == num) {
                printf("find at: %d %d\n", row, column);
                return true;
            } else if(data[cur] > num) {
                column -= 1;
            } else {
                row += 1;
            }
        }
    }
    printf("not found\n");
    return false;
}

int main() {
    int data[][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    int rows = 4;
    int columns = 4;
    int num;
    printf("请输入需要查找的数据: ");
    scanf("%d", &num);
    findnum((int*)data, rows, columns, num);
    return 0;
}
