#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} node_t;
 
//giai phong cay
void Free( node_t* root );
 // so sanh trong if de chuyen sang con trai
int LeftOf( const int value, const node_t* root );
//  so sanh trong if de chuyen sang con phai
int RightOf( const int value, const node_t* root );
// chen vao gia tri
node_t* Insert( node_t* root, const int value );
// tim kiem gia tri
bool Search( const node_t* root, int value );
// gia tri not trai nhat
int LeftMostValue( const node_t* root );
// xoa phan tu co gia tri value
node_t* Delete( node_t* root, int value );
//////  DFS
// duyet theo thu tu truoc
void PreOrder(node_t* root);
//duyet theo thu tu giua
void InOrder(node_t* root);
// duyet theo thu tu sau
void PostOrder(node_t* root);

 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
// so sanh trong if de chuyen sang con trai
int LeftOf( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
//    return value <= root->data;
}
 
//  so sanh trong if de chuyen sang con phai
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
// chen vao gia tri
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
// tim kiem gia tri
bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}
 
// gia tri not trai nhat
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}
// xoa phan tu co gia tri value
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}
 
// duyet theo thu tu truoc
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
//duyet theo thu tu giua
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
// duyet theo thu tu sau
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
 

 
int main()
{
    node_t* root = NULL;
 
    root = Insert( root, 25 );
    root = Insert( root, 15 );
    root = Insert( root, 50 );
    root = Insert( root, 10 );
    root = Insert( root, 22 );
    root = Insert( root, 35 );
    root = Insert( root, 70 );
    root = Insert( root, 4 );
    root = Insert( root, 12 );
    root = Insert( root, 18 );
    root = Insert( root, 24 );
    root = Insert( root, 31 );
    root = Insert( root, 44 );
    root = Insert( root, 66 );
    root = Insert( root, 90 );
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
    printf("\n==Thu them phan tu 15 vao BTS==\n");
    Insert(root, 1);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
 
    printf("\n==Thu xoa phan tu 50 khoi BTS==\n");
    Delete(root, 50);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
 
 
 
    Free( root );
    root = NULL;
    return 0;
}

// Duyet preorder : 25 15 10 4 12 22 18 24 50 35 31 44 70 66 90 
// Duyet inorder  : 4 10 12 15 18 22 24 25 31 35 44 50 66 70 90 
// Duyet postorder:4 12 10 18 24 22 15 31 44 35 66 90 70 50 25 
// ==Thu them phan tu 15 vao BTS==