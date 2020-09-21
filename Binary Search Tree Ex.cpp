#include <stdio.h>
#include <stdlib.h>

struct node{ 
    int number;
    int height;
    struct node *left, *right; 
}; 

struct node *create(int num, int height){
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->number = num;
	temp->height = height;
	temp->left = temp->right = NULL;
	
	return temp;
}

struct node *insert(struct node* node, int num, int height){
	height += 1;
	
	if(node == NULL) return create(num, height);
	
	if(num < node->number) node->left =  insert(node->left, num, height);
	else if(num > node->number) node->right = insert(node->right, num, height);
	
	return node;
}

void display(struct node* root, int left, int right){
	if(root != NULL){
		printf("Height %d, left/right %d/%d: %d\n", root->height, left, right, root->number);
		
		display(root->left, left+1, right);
		display(root->right, left, right+1);
	}
	return;
}

int search(struct node* root, int left, int right, int key){
	if(root != NULL){
		if(key == root->number){
			printf("Height %d, left/right %d/%d: %d\n", root->height, left, right, root->number);
			return 0;
		}
		
		search(root->left, left+1, right, key);
		search(root->right, left, right+1, key);
	}
	return 1;
}

struct node* deleteTree(struct node* root){
	if(root == NULL) return root;
	
	deleteTree(root->left);
	deleteTree(root->right);
	
	free(root);
	return root;
}

int main(){
	int choice, num, height;
	struct node* root = NULL;
	
	do{
		system("CLS");
		printf("Binary Search Tree\n");
		printf("====================\n");
		printf("[1] Insert New Node\n");
		printf("[2] Display All of Tree\n");
		printf("[3] Search Specific Node\n");
		printf("[4] Exit\n");
		printf(">> ");
		scanf("%d", &choice);
		
		if(choice == 1){
			do{
				printf("Input number [1-999]\t: ");
				scanf("%d", &num);
			}while(num < 1 || num > 999);
			
			height = 0;
			if(root == NULL){
				root = insert(root, num, height);
			}
			else{
				insert(root, num, height);
			}
		}
		else if(choice == 2){
			if(root == NULL){
				printf("Tree is empty, nothing to display.\n");
			}
			else display(root, 0, 0);
			printf("\n");
			system("pause");
		}
		else if(choice == 3){
			if(root == NULL){
				printf("Tree is empty.\n");
			}
			else{
				int key;
				printf("Key: ");
				scanf("%d", &key);
				if (search(root, 0, 0, key) == 1){
					printf("Key not found in tree.\n");
				}
			}
			printf("\n");
			system("pause");
		}
	}while(choice != 4);
	deleteTree(root);
	root = NULL;
	return 0;
}
