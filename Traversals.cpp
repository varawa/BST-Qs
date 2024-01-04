#include<iostream>

using namespace std ;

class node{
    public:
        int data ;
        node* left ;
        node* right ;

        node(int data){
            this->data = data ;
            this->left = NULL ;
            this->right = NULL ;
        }
};

node* insert(node* &root , int data){
    if(root == NULL){
        root = new node(data) ;
        return root ;
    }

    if(data > root->data){
        root->right = insert(root->right , data) ;
    }
    else{
        root->left = insert(root->left , data) ;
    }
    return root ;
}

void takeinput(node* &root){
    int data ;
    cin>>data ;

    while(data != -1){
        insert(root , data) ;
        cin>>data ;
        cout<<data ;
    }
}


void preorder(node* root){
    cout<<root->data <<" " ;

    if(root->left){
        preorder(root -> left) ;
    }
    if(root->right){
        preorder(root -> right) ;
    }
}

void postorder(node* root){

    if(root->left){
        postorder(root -> left) ;
    }
    if(root->right){
        postorder(root -> right) ;
    }
    cout<<root->data <<" " ;
}

void inorder(node* root){

    if(root->left){
        inorder(root -> left) ;
    }
    cout<<root->data <<" " ;
    if(root->right){
        inorder(root -> right) ;
    }
}

int main(){
    node* tree = NULL ;
    takeinput(tree) ;
    
    cout<<"Preorder : "<<endl ;
    preorder(tree) ;
    cout<<"Postorder : "<<endl ;
    postorder(tree) ;
    cout<<"Inorder : "<<endl ;
    inorder(tree) ;
    return 0 ;
}