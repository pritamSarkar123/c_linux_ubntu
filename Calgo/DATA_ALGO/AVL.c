#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int max(int a,int b){
    return (a>b) ? a : b;
}
struct Node *newnode(int x){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=x;
    n->height=1;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int height(struct Node *r){
    if(r==NULL) return -1;
    else return r->height;
}
int height_balance(struct Node *r){
    return max(height(r->left),height(r->right))+1;
}

struct Node *rotate_left(struct Node *r){
    struct Node *t=r->right;
    r->right=t->left;
    t->left=r;
    r->height=height_balance(r);
    return r;  
}

struct Node *rotate_right(struct Node *r){
    struct Node *t=r->left;
    r->left=t->right;
    t->right=r;
    r->height=height_balance(r);
    return r;  
}

struct Node *avl_balance(struct Node *r){
    int balance=height(r->left)-height(r->right);
    if(balance>1){
        if(height(r->left->left)>=height(r->left->right)) return rotate_right(r);
        else{
            r->left=rotate_left(r->left);
            return rotate_right(r);
        }
    }
    if(balance<-1){
        if(height(r->right->right)>=height(r->right->left)) return rotate_left(r);
        else{
            r->right=rotate_right(r->right);
            return rotate_left(r);
        }
    }
}
struct Node *find_min(struct Node *r){
    if(r->left==NULL){
        return r;
    }
    return find_min(r->left);
}

struct Node *avl_insert(struct Node *r,int x){//<<<<<<<<<<<<<<<<<<<<<<
    if(r==NULL){
        r=newnode(x);
    } 
    else if(x<=r->data) r->left=avl_insert(r->left,x);
    else r->right=avl_insert(r->right,x);
    r=avl_balance(r);
    r->height=height_balance(r);
    return r;
}

struct Node *avl_delete(struct Node *r,int x){///>>>>>>>>>>>>>>>>>>>>>>>>
    if(r==NULL){
        printf("nothing to delete");
        return r;
    }
    else if(r->data > x) r->left=avl_delete(r->left,x);
    else if(r->data <= x) r->right=avl_delete(r->right,x);
    else{ // data got
        if(r->left==NULL && r->right==NULL){
            free(r);
            r=NULL;
        }
        else if(r->left==NULL){
            struct Node *t=r;
            r=r->right;
            free(t);
        }
        else if(r->right==NULL){
            struct Node *t=r;
            r=r->left;
            free(t);
        }
        else{ // have both left and right subtree
            struct Node *t =find_min(r->right);
            r->data=t->data;
            r->right=avl_delete(r->right,t->data);
        }
    }
    r=avl_balance(r);
    r->height=height_balance(r);
    return r;
}
int find_height(struct Node *r){
    if(r==NULL) return -1;
    else
        return max(find_height(r->left),find_height(r->right))+1;
}
void in_order(struct Node *r){
    if(r==NULL) return;
    in_order(r->left);
    printf("%d ",r->data);
    in_order(r->right);
}
int main(){
    struct Node *root;
    /*root=avl_insert(root,1);
    root=avl_insert(root,2);
    root=avl_insert(root,3);
    root=avl_insert(root,4);
    root=avl_insert(root,5);
    root=avl_insert(root,6);
    root=avl_insert(root,15);
    root=avl_insert(root,9);
    root=avl_insert(root,18);
    root=avl_insert(root,25);
    int h=find_height(root);
    printf("height of the tree %d\n",h);
    in_order(root);
    root=avl_delete(root,6);
    root=avl_delete(root,9);
    root=avl_delete(root,1);
    h=find_height(root);
    printf("after deletion height of the tree %d\n",h);
    in_order(root);
    return 0;*/
}
