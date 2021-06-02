//
// Created by spawnfire on 16/05/21.
//


#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node * left=nullptr;
    Node * right=nullptr;
    int val;
    ~ Node(){
        cout<<"clean up: "<<val<<endl;
        delete left;
        delete right;
    }
};

void insert(Node **root, int x) {
    if ((*root) == nullptr) {
        (*root) = new Node();
        (*root)->val = x;
    }
    else if ((*root)->val > x) {
        insert(&(*root)->left, x);
    } else {
        insert(&(*root)->right, x);
    }
}

void inorder(Node* root){
    if(root== nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

bool check_if_binary_search_tree(Node *left,Node*right,int x){ // NOTE THE EQUALITY CASES
    if(right== nullptr && left== nullptr)
        return true;
    if(left!= nullptr && right!= nullptr){
        if(left->val<=x && right->val >= x){
            return check_if_binary_search_tree(left->left,left->right,left->val)&& check_if_binary_search_tree(right->left,right->right,right->val);
        }
    }
    else if(right!= nullptr){
        if(right->val>=x)
            return check_if_binary_search_tree(right->left,right->right,right->val);

    }else if(left!= nullptr){
        if(left->val<=x)
            return check_if_binary_search_tree(left->left,left->right,left->val);

    }
    return false;

}

bool search(Node *root,int x){
    if(root== nullptr)
        return false;
    if(root->val == x){
        return true;
    }
    else if(root->val < x){
        return search(root->right,x);
    }else{
        return search(root->left,x);
    }
}

int main(){
    int arr[]={1,2,4,52,7,2,7,42,3};
    int size=sizeof(arr)/sizeof(int);
    Node* root=nullptr;
    for(int i=0;i<size;i++){
        insert(&root,arr[i]);
    }
    inorder(root);
    cout<<endl;
    cout<<check_if_binary_search_tree(root->left,root->right,root->val)<<endl;
    delete(root);
    return 0;
}