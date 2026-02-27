#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
    int size;
} MyLinkedList;
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    obj->size++;
}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        printf("Invalid index!\n");
        return;
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        printf("Invalid index!\n");
        return;
    }
    Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    obj->size--;
}
void display(MyLinkedList* obj) {
    Node* curr = obj->head;
    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}
int main() {
    MyLinkedList* list = myLinkedListCreate();
    int choice, val, index;
    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Add at Head\n");
        printf("2. Add at Tail\n");
        printf("3. Add at Index\n");
        printf("4. Delete at Index\n");
        printf("5. Get value at Index\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                myLinkedListAddAtHead(list, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                myLinkedListAddAtTail(list, val);
                break;
            case 3:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &val);
                myLinkedListAddAtIndex(list, index, val);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                myLinkedListDeleteAtIndex(list, index);
                break;
            case 5:
                printf("Enter index: ");
                scanf("%d", &index);
                int result = myLinkedListGet(list, index);
                if (result == -1)
                    printf("Invalid index!\n");
                else
                    printf("Value = %d\n", result);
                break;
            case 6:
                display(list);
                break;
            case 7:
                myLinkedListFree(list);
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
