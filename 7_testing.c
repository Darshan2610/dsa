#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int usn;
    char name[20];
    char program[20];
    int sem;
    int phno;
    struct Student* next;
};
typedef struct Student Node;

// Node *head = NULL0;
Node *create();
Node *insFront(Node *, Node *);
Node *insEnd(Node*, Node*); 
Node *delFront(Node*);
Node *delEnd(Node *);
void display(Node*);
int count(Node*);
void freelist(Node*);

int main (){
    int choice,done=0,dis;
    Node *head = NULL;
    while(!done){
        printf("\n1. Create a student\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Display list\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch(choice) {
            case 1:
                head = insFront(head, create());
                break;
            case 2:
                head = insFront(head, create());
                break;
            case 3:
            head = insEnd(head, create());
            break;
            case 4:
                head = delFront(head);
                break;
            case 5:
                head = delEnd(head);
                break;
            case 6:
                display(head);
                // printf("no of nodes are: %d", dis);
                break;
            case 7:
                printf("the no of nodes are %d",count(head));
                break;
            case 8:
                freelist(head);
                printf("Terminated");
                done = 1;
                break;
            default :
                printf("invalid choice");
        }
    }
    return 0;
}

Node *create(){
    Node *new_node = (Node*)malloc(sizeof(Node));
    printf("enter usn: ");
    scanf("%d", &new_node->usn);
    printf("enter name: ");
    scanf("%s", new_node->name);
    printf("enter programe: ");
    scanf("%s", new_node->program);
    printf("enter sem: ");
    scanf("%d",&new_node->sem);
    printf("enter phone: ");
    scanf("%d", &new_node->phno);
    new_node->next=NULL;
    return new_node;
}

Node *insFront(Node* head, Node* new_node){
    new_node->next = head;
    return new_node;
}

Node *insEnd(Node* head, Node* new_node){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

Node *delFront(Node *head){
    if(head == NULL){
        printf("no data : \n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
    
}

Node *delEnd(Node *head){
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

void display(Node *head)
{
    printf("Student List:\n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("USN: %d, Name: %s, Programme: %s, Semester: %d, Phone: %d\n", temp->usn, temp->name, temp->program, temp->sem, temp->phno);
        temp = temp->next;
    }
}

int count(Node *head){
    Node *temp = head;
    int node_count=0;
    while(temp!=NULL){
        node_count++;
        temp=temp->next;
        
    }
    return node_count;
}

void freelist(Node *head){
    Node *temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}