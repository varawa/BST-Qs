#include<iostream>
using namespace std ;

class node{
    public:
        int data ;
        node* left ;
        node* right ;

        node(int d){
            this->data = d ;
            this->left = this->right = NULL ;
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
    if(data < root->data){
        root->left = insert(root->left , data) ;
    }
    return root ;
}

void takeinput(node* &root){
    int data ;
    cin>>data ;
    while(data != -1){
        root = insert(root , data) ;
        cin>>data ;
    }
}

int min_of_tree(node* root){
    node* temp = root ;
    while(temp->left != NULL){
        temp = temp->left ;
    }
    cout<<"Minimum of tree : "<<endl ;
    cout<<temp->data<<endl ;
}

int max_of_tree(node* root){
    node* temp = root ;
    while(temp->right != NULL){
        temp = temp->right ;
    }
    cout<<"Maximum of tree : "<<endl ;
    cout<<temp->data<<endl ;
}

int main(){
    node* tree = NULL ;
    cout<<"Enter elements of binary search tree : "<<endl ;
    takeinput(tree) ;

    min_of_tree(tree) ;
    max_of_tree(tree) ;
    return 0 ;
}