#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* newNode(int data)
{
	node* root= new node;
	root->data=data;
	root->left=NULL;
	root->right=NULL;
}
node* minimal_tree(int arr[],int start, int end)
{
	if(start>end)
	return NULL;
	int mid=(start+end)/2;
	node* root = newNode(arr[mid]);
	root->right=minimal_tree(arr,mid+1,end);
	root->left=minimal_tree(arr,start,mid-1);
	return root;
}
void preorder(node* root)
{
	if(root==NULL)
	return;
	else
	{
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
}
int height(int data);
bool isBalanced(node* root)
{
	if(root==NULL)
	return 1;
	int lh;
	int rh;
	lh=height(root->left);
	rh= height(root->right);
	if((abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right))
	return 1;
	else return 0;
}
int height(node* root)
{
	if(root==NULL)
	return 1;
	else
	return 1+ max(height(root->left),height(root->right));
}
bool validateBST(node* root)
{
	if(root==NULL)
	return true;
	else if(root->left->data>root->data||root->right->data<root->data)
	return false;
	else if(validateBST(root->right)&&validateBST(root->right));
	return false;
	
}
node* successor(node* root, node* n)
{
	if(n->right!=NULL)
	return minValue(n->right);
	node* p=n->parent;
	while(p!=NULL&&n==p->right)
	{
		n=p;
		p=p->parent;
	}
	return p;
}
node* minValue(node* n)
{
node* current=n;
while(current->left!=NULL)
current=current->left;
return current;	
}
struct node* insert(struct node* node, int data) 
{ 
  /* 1. If the tree is empty, return a new, 
      single node */
  if (node == NULL) 
    return(newNode(data)); 
  else
  { 
    struct node *temp;   
  
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data) 
    {     
         temp = insert(node->left, data); 
         node->left  = temp; 
         temp->parent= node; 
    } 
    else
    { 
        temp = insert(node->right, data); 
        node->right = temp; 
        temp->parent = node; 
    }     
   
    /* return the (unchanged) node pointer */
    return node; 
  } 
}  
   
/* Driver program to test above functions*/
int main() 
{ 
  struct node* root = NULL, *temp, *succ, *min; 
  
  //creating the tree given in the above diagram 
  root = insert(root, 20); 
  root = insert(root, 8); 
  root = insert(root, 22); 
  root = insert(root, 4); 
  root = insert(root, 12); 
  root = insert(root, 10);   
  root = insert(root, 14);     
  temp = root->left->right->right; 
  
  succ =  inOrderSuccessor(root, temp); 
  if(succ !=  NULL) 
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);     
  else
    printf("\n Inorder Successor doesn't exit"); 
  
  getchar(); 
  return 0; 
} 

