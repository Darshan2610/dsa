#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right;
} *node;

node create(node,int);
node createTree(node, int);
void preorder(node);
void postorder(node);
void inorder(node);
int search(node, int);

int main (){
    int done = 0,
    choice, n, flag,item;
    node root = NULL;
    while(!done){
        printf("1.create  2.preorder  3.inorder  4.postorder  5,search");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("enter the no of nodes : ");
                scanf( "%d" ,&n );
                root = create(root, n);
                break;
            case 2:
            preorder(root);
            break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
            case 5 :
                printf("enter element to be searched: ");
                scanf( "%d" ,&item);
                int a = search(root, item);
                if(a==-1){
                    printf("\nno found\n");
                }
                printf("element is found");
                break;
            default :
                done = 1;
                break;
        }
    }

    return 0;
}

node create(node root, int n)
{
    int i, e;
    

    if (root == NULL)
    {
        for (i = 1; i <= n; i++)
        {
            printf("Enter Data element\n");
            scanf("%d", &e);
            root = createTree(root, e);
        }
    }
    else
    {
        printf("Tree already has some data\n");
    }

    return root;
}

node createTree(node root, int e){
    if(root == NULL){
        root = (node)malloc(sizeof(struct tree));
        root->info = e;
        root->left = root->right = NULL;
    }
    else if (e==root->info)
    {
        printf("duplicate value not allowed");
    }
    else if (e<root->info){
        root->left = createTree(root->left,e);
    }
    else{
        root->right = createTree(root->right, e);
    }
    return root;
}

int search(node root, int item){
    if(item == root->info){
        return 1;
    }
    else if (item<root->info)
    {
        return search(root->left, item);
    }
    else{
        return search(root->right, item);
    }
    

}

void preorder(node root){
    if(root != NULL){
        printf("%d\t", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node root){
    if(root != NULL){
        preorder(root->left);
        printf("%d\t", root->info);
        preorder(root->right);
    }
}
void postorder(node root){
    if(root != NULL){
        
        preorder(root->left);
        preorder(root->right);
        printf("%d\t",root->info);
    }
}


