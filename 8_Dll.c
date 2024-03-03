#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
typedef struct Employee
{
    int SSN;
    char Name[50];
    char Dept[50];
    char Designation[50];
    float Sal;
    long long int PhNo;
    struct Employee *prev;
    struct Employee *next;
} Employee;

// Function to create a new employee node
Employee *createEmployee(int ssn, char *name, char *dept, char *designation, float sal, long long int phNo)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    if (newEmployee == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newEmployee->SSN = ssn;
    strcpy(newEmployee->Name, name);
    strcpy(newEmployee->Dept, dept);
    strcpy(newEmployee->Designation, designation);
    newEmployee->Sal = sal;
    newEmployee->PhNo = phNo;
    newEmployee->prev = NULL;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to insert a new employee at the end of the DLL
void insertEnd(Employee **head, Employee *newEmployee)
{
    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        Employee *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->prev = temp;
    }
}

// Function to display the data of all DLL nodes and count the number of nodes
void display(Employee *head)
{
    Employee *temp = head;
    int count = 0;
    printf("Employee Data:\n");
    while (temp != NULL)
    {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Sal: %.2f, PhNo: %lld\n", temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        temp = temp->next;
        count++;
    }
    printf("Total number of employees: %d\n", count);
}

// Function to perform insertion at the front of DLL
void insertFront(Employee **head, Employee *newEmployee)
{
    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        newEmployee->next = *head;
        (*head)->prev = newEmployee;
        *head = newEmployee;
    }
}

// Function to delete a node from the end of DLL
void deleteEnd(Employee **head)
{
    if (*head == NULL)
    {
        printf("DLL is empty, cannot delete.\n");
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Employee *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// Function to delete a node from the front of DLL
void deleteFront(Employee **head)
{
    if (*head == NULL)
    {
        printf("DLL is empty, cannot delete.\n");
    }
    else
    {
        Employee *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

int main()
{
    Employee *head = NULL;
    char choice;
    int ssn;
    char name[50];
    char dept[50];
    char designation[50];
    float sal;
    long long int phNo;

    do
    {
        printf("\nMenu:\n");
        printf("a. Create a DLL of N Employees Data\n");
        printf("b. Display the data of all DLL nodes\n");
        printf("c. Insertion at End of DLL\n");
        printf("d. Deletion at End of DLL\n");
        printf("e. Insertion at Front of DLL\n");
        printf("f. Deletion at Front of DLL\n");
        printf("x. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter SSN, Name, Dept, Designation, Sal, PhNo for each employee (separated by space):\n");
            scanf("%d %s %s %s %f %lld", &ssn, name, dept, designation, &sal, &phNo);
            insertEnd(&head, createEmployee(ssn, name, dept, designation, sal, phNo));
            break;
        case 'b':
            display(head);
            break;
        case 'c':
            printf("Enter SSN, Name, Dept, Designation, Sal, PhNo for the new employee (separated by space):\n");
            scanf("%d %s %s %s %f %lld", &ssn, name, dept, designation, &sal, &phNo);
            insertEnd(&head, createEmployee(ssn, name, dept, designation, sal, phNo));
            break;
        case 'd':
            deleteEnd(&head);
            break;
        case 'e':
            printf("Enter SSN\n, Name\n, Dept\n, Designation\n, Sal\n, PhNo\n for the new employee (separated by space):\n");
            insertFront(&head, createEmployee(ssn, name, dept, designation, sal, phNo));
            break;
        case 'f':
            deleteFront(&head);
            break;
        case 'x':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'x');

    return 0;
}
