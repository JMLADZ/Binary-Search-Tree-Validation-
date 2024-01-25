#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 18

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;                        
    n->left = NULL;                         
    n->right = NULL;                        
    return n;
}

int i, j, arr[11], arrnum = 0;              // global variable.
struct node* root;

void inOrder(struct node* root) {          
    struct node* stack[MAX_SIZE];
    int top = -1;                           
    struct node* current = root;            
    while (current != NULL || top != -1) {  // loop sa inorder traversal. NULL and current OR top != -1. 
        while (current != NULL){            
            stack[++top] = current;         // push the "current" node to  stack and increment sa "top" index.
            current = current->left;        //update sa left child.  traversal to the left sub tree of current node.
        }                                   // innner loop ends if ang current becomes NULL meaning na reach na niya ang 
                                            // left subtree  sa current node.
        current = stack[top--];             
        printf("%d ", current->data);       // print value in inorder. 
        
		arr[arrnum] = current->data;        //store data in the array.
		arrnum++;                          
        current = current->right;           
    }
}

int isBST(struct node* root) {
    if (root == NULL)
        return 1;                           // if root empty

    if (root->left != NULL && root->left->data > root->data)
        return 0;                           // return false if root.left.data is greater than root.data & 

    if (root->right != NULL && root->right->data < root->data)
        return 0;                           // return false if root.left.data is less than root.data

    return isBST(root->left) && isBST(root->right);
}

int dup_chck(){
	for(i = 0; i < 11; i++)
		{
			for(j = i + 1 ; j < 11; j++)    
			{
				//puts("JMLADZ");
				if(i != j)                 
				{
					if(arr[i] == arr[j])   
					{
						puts("\nYOU ENTERED A DUPLICATE NUMBER \n");
						printf("%d == %d", arr[i], arr[j]);
						return true;        
					}
				}	
			}
		}
	return false;                           
}

void tree(){
    root = createNode(6);                   
    root->left = createNode(5);
    root->right = createNode(7);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(0);
    root->right->right = createNode(9);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(4);
    root->right->left->right = createNode(10);
    root->right->right->right = createNode(11);
}

void display(){
    char num = ' ';                         // \t = 9 spaces
    int num2 = 5;
    
    puts("");
    printf("%54c%d", num, root->data);      
    puts("\n\n\n");
    printf("%36c%d%36c%d", num, root->left->data, num,root->right->data);
	puts("\n\n");                           
    printf("%27c%d%18c%d%18c%d%18c%d", num, root->left->left->data, num, root->left->right->data, num, root->right->left->data, num, root->right->right->data);//tulo
    puts("\n\n");
    printf("%18c%d%18c%d%36c%d%18c%d\n", num, root->left->left->left->data, num, root->left->left->right->data, num, root->right->left->right->data, num, root->right->right->right->data);//upat
	puts("--------------------------------------------------------------------------------------------------------");
}

int main() {
    
    tree();
    puts("\nINORDER");
    inOrder(root);
    puts("\nDISPLAY");
    display();
    
    if (isBST(root) && !dup_chck())
        puts("\n\nThe binary tree is a valid binary search tree.");// print if ma satisfy ang BST and walay duplicate
    else
        puts("\n\nThe binary tree is NOT a valid binary search tree.\n\n");// else kini e print

    return 0;
}