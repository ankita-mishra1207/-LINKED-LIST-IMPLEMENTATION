#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d\n", value);
}

// Function to delete a node by value
void delete(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list.\n", value);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted %d\n", value);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate all operations
int main() {
    insert(10);
    insert(20);
    insert(30);
    display();         // Output: 10 → 20 → 30 → NULL

    delete(20);
    display();         // Output: 10 → 30 → NULL

    insert(40);
    display();         // Output: 10 → 30 → 40 → NULL

    delete(50);        // Value not in list

    return 0;
}
