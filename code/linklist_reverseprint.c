#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node, *LinkList, ListNode;

LinkList create(int n, bool reverse) {
    if(n <= 0) {
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));

    head->val = 1;
    head->next = NULL;

    if(reverse) {  // 逆序创建
        for(int i=1; i<n; ++i) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->val = i+1;
            node->next = head;
            head = node;
        }
    } else {
        Node* tmp = head;
        for(int i=1; i<n; ++i) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->val = i + 1;
            node->next = NULL;
            tmp->next = node;
            tmp = node;
        }
    }
    return head;
}

void printlist(LinkList head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// 递归
void reversePrint(LinkList head) {
    #ifdef OK
    if(head == NULL) {
        return;
    } else {
        reversePrint(head->next);
        printf("%d ", head->val);
    }
    #else
    if(head != NULL) {
        if(head->next != NULL) {
            reversePrint(head->next);
        }
        printf("%d ", head->val);
    }
    #endif
}

// 也可以不用递归调用来打印链表, 此时可以使用一个栈, 遍历链表时将值存入到栈中,
// 然后在依次弹出栈中内容即可.
