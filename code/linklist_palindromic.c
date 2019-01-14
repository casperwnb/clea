#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char value;
    struct Node *next;
} Node, *List;

List create(int count, char *str) {
    List head = (List)malloc(sizeof(Node));
    head->next = NULL;

    /*
    // 逆序插入数据
    for(int i=0; i<count; ++i) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->value = str[i];
        node->next = head->next;
        head->next = node;
    }
    */

    // 正序插入数据
    List thead;
    thead = head;
    for(int i=0; i<count; ++i) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->value = str[i];
        node->next = NULL;
        thead->next = node;
        thead = node;
    }
    return head;
}

// 通过翻转前半部分链表来实现回文字符串的判断, 时间复杂度是O(n), 空间复杂度是O(1)
// 注意: 此方法破坏了原来的链表
bool ispalindromic(List head) {
    if (head == NULL || head->next == NULL)
        return false;

    List slow = head->next;
    List prev = NULL;
    List next = NULL;
    List fast = head->next;
    while(1) {
        if(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;  // 快指针

            // 慢指针, 并且翻转前面的链表
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        } else {
            break;
        }
    }
    if(fast->next == NULL) {  // 奇数个节点
        slow = slow->next;
        while(slow != NULL) {
            if(prev->value == slow->value) {
                prev = prev->next;

                slow = slow->next;
            } else {
                return false;
            }
        }
    } else {  // 偶数个节点
        next = slow->next;
        slow->next = prev;
        while(next != NULL) {
            if(next->value == slow->value) {
                slow=slow->next;
                next = next->next;
            } else {
                return false;
            }
        }
    }
    return true;
}

void printlist(List head) {
    if(head == NULL) {
        return;
    }
    List node = head->next;
    while(node != NULL) {
        printf("%c ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    char str[] = "ABCCAB";
    List head = create(strlen(str), str);
    printf("字符串为: ");
    printlist(head);

    bool r = ispalindromic(head);
    if (r) {
        printf("这是回文串\n");
    } else {
        printf("这不是回文串\n");
    }
    return 0;
}
