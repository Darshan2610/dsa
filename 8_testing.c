#include<stdio.h>
#include<stdlib.h>

typedef struct Employee
{
    int SSN;
    char Name[50];
    char Dept[50];
    char Designation[50];
    int Sal;
    int PhNo;
    struct Employee *prev;
    struct Employee *next;
} Emp;

Emp *create();
Emp *insfront(Emp *, Emp *);
Emp *insEnd(Emp *, Emp *);
Emp *delfront(Emp *);
Emp *delend(Emp *);
void display(Emp *);

int main (){
    Emp *head = NULL;
    int choice, done = 0;
    while(!done){
        printf("1=create  2=insfront  3=insend\n4=delfront  5=delend  6=display\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                head = insEnd(head, create());
                break;
            case 2: head = insfront(head, create());break;
            case 3:
                head = insEnd(head, create());
                break;
            case 4:
                head = delfront(head);
                break;
            case 5: head = delend(head);break;
            case 6: display(head);break;
            default : done = 1;
            break;
        }
    }

    return 0;
}

Emp *create(){
    Emp *new = (Emp*)malloc(sizeof(Emp));
    printf("enter ssn : ");
    scanf("%d", &new->SSN);
    printf("enter name : ");
    scanf("%s", new->Name);
    printf("enter dept : ");
    scanf("%s", new->Dept);
    printf("enter desig : ");
    scanf("%s", new->Designation);
    printf("enter sal : ");
    scanf("%d", &new->Sal);
    printf("enter phone : ");
    scanf("%d", &new->PhNo);
    new->next=NULL;
    new->prev = NULL;
    return new;
}

Emp *insEnd(Emp *head, Emp *new)
{
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        Emp *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    return head;
}

Emp *insfront(Emp *head, Emp *new)
{
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
    return head;
}

Emp *delend(Emp *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    Emp *temp = head;
    Emp *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        free(temp);
        return NULL;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

Emp *delfront(Emp *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    Emp *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

void display(Emp *head)
{
    printf("Employee List:\n");
    int count = 0;
    Emp *temp = head;
    while (temp != NULL)
    {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Sal: %d, PhNo: %d\n", temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        count++;
        temp = temp->next;
    }
    printf("Total number of employees: %d\n", count);
}

void freeList(Emp *head)
{
    Emp *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
