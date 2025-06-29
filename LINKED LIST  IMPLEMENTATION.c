#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Head pointer
Node* head = NULL;

// Create a new node
Node* createNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", val);
}

// Insert at end
void insertAtEnd(int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", val);
}

// Delete by value
void deleteByValue(int val) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    Node* prev = NULL;

    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (!prev) {
        head = head->next; // deleting head node
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted value %d.\n", val);
}

// Display the list
void displayList() {
    Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete by Value\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
