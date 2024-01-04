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

void inorder_predecessor(node* root , int num , node* &pre ){
    if(root == NULL){
        return ;
    }
    if(root->data == num){
        
        if(root->left){
            node* temp = root->left ;
            while(temp->right){
                temp = temp->right ;
            }
            pre = temp ;
        }
        return ;
    }
    else if(num > root->data){
        inorder_predecessor(root->right , num , pre ) ;
    }
    else{
        inorder_predecessor(root->left , num , pre) ;
    }
    
}

int main(){
    node* tree = NULL ;
    cout<<"Enter elements of binary search tree : "<<endl ;
    takeinput(tree) ;
    node* pred = NULL ;
    
    inorder_predecessor(tree , 15 , pred ) ;
    
    cout<<"Inorder predecessor of 15 is : "<<pred->data ;
    
    return 0 ;
}