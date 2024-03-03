#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char USN[20];
    char Name[50];
    char Programme[50];
    int Sem;
    char PhNo[15];
    struct Student* next;
};

typedef struct Student Node;

// Function prototypes
Node* createStudent();
Node* insertFront(Node*, Node*);
Node* insertEnd(Node*, Node*);
Node* deleteFront(Node*);
Node* deleteEnd(Node*);
void display(Node*);
int countNodes(Node*);
void freeList(Node*);

int main() {
    int choice;
    Node* head = NULL;
    do {
        printf("\n1. Create a student\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Display list\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = insertFront(head, createStudent());
                break;
            case 2:
                head = insertFront(head, createStudent());
                break;
            case 3:
                head = insertEnd(head, createStudent());
                break;
            case 4:
                head = deleteFront(head);
                break;
            case 5:
                head = deleteEnd(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 8:
                freeList(head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// Function to create a new student
Node* createStudent() {
    Node* newStudent = (Node*)malloc(sizeof(Node));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter USN: ");
    scanf("%s", newStudent->USN);
    printf("Enter Name: ");
    scanf("%s", newStudent->Name);
    printf("Enter Programme: ");
    scanf("%s", newStudent->Programme);
    printf("Enter Semester: ");
    scanf("%d", &newStudent->Sem);
    printf("Enter Phone number: ");
    scanf("%s", newStudent->PhNo);
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the front of the list
Node* insertFront(Node* head, Node* newStudent) {
    newStudent->next = head;
    return newStudent;
}

// Function to insert a student at the end of the list
Node* insertEnd(Node* head, Node* newStudent) {
    if (head == NULL) {
        return newStudent;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
    return head;
}

// Function to delete a student from the front of the list
Node* deleteFront(Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a student from the end of the list
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        free(temp);
        return NULL;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

// Function to display the list
void display(Node* head) {
    printf("Student List:\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Programme: %s, Semester: %d, Phone: %s\n", temp->USN, temp->Name, temp->Programme, temp->Sem, temp->PhNo);
        temp = temp->next;
    }
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the memory allocated for the list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
