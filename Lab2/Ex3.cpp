#include <bits/stdc++.h>
using namespace std;
class AvlTree{
    public:
       int data;
       AvlTree *left;
       AvlTree *right;
       int height;
       AvlTree()
       {
       	data = 0;
       	left = nullptr;
       	right = nullptr;
       	height = 0;
       }
       AvlTree(int val)
       {
       	data = val;
       	left = nullptr;
       	right = nullptr;
       	height = 0;
       }
};
int height(AvlTree *root){
    if(!root)
    	return 0;
    return root->height;
}
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
AvlTree *rightRotation(AvlTree *y)
{
    AvlTree *x=y->left;
    AvlTree *temp_null=x->right;
    x->right=y;
    y->left=temp_null;
    //Updating height of every node
    y->height = max(height(y->left),height(y->right));
    x->height = max(height(x->left),height(x->right));
    
    return x;
}
AvlTree *leftRotation(AvlTree *x)
{
    AvlTree *y=x->right;
    AvlTree *temp_null=y->left;
    y->left=x;
    x->right=temp_null;
    
    //Updating height of every node
    y->height = max(height(y->left),height(y->right));
    x->height = max(height(x->left),height(x->right));
    
    return y;
}
int BalanceFactor(AvlTree *node){
    if(!node)
    	return 0;
    return height(node->left)-height(node->right);
}
AvlTree *insertNode(AvlTree* root,int key){
    if(!root)
    {
    	AvlTree *newNode = new AvlTree(key);
    	return newNode;
    }
    if(key<root->data)
            root->left = insertNode(root->left,key);
    else if(key>root->data)
            root->right = insertNode(root->right,key); 
    else
            return root;
    
    root->height = max(height(root->left),height(root->right));
    int balance = BalanceFactor(root);
    
    if(balance>=2 and key < root->left->data)   	 // Right Rotation Case (left skew)
            return rightRotation(root);
    
    if(balance<=-2 and key > root->right->data)
            return leftRotation(root);        		  // Left Rotation Case (right skew)
        
    if(balance>=2 and key > root->left->data){
            root->left=leftRotation(root->left);     	  // Left Right Rotation
            return rightRotation(root);
    }

    if(balance<=-2 and key < root->right->data){
            root->right=rightRotation(root->right);    	    // Right Left Rotation
            return leftRotation(root);
       }
    return root;
}
void traversal(AvlTree *root)    		  //inorder traversal
{
    if(root==NULL)
        return;
    
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
    
}
int main()
{
	int x;
AvlTree *root=NULL;
for(int i=0;i<10;i++){
    	cin>>x;
    	root=insertNode(root,x);
    	}
traversal(root);
return 0;
}
