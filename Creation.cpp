#include<iostream>
#include<queue>
using namespace std ;

class node{
    public:
        int data ;
        node* left ;
        node* right ;

        node(int d){
            this->data = d ;
            this->right = NULL ;
            this->left = NULL ;
        }
};


node* insert(node* &root , int d){
    if(root == NULL){
        root = new node(d) ;
        return root ;
    }

    if(d > root->data){
        root -> right = insert(root->right , d) ;
    }

    else{
        root -> left = insert(root->left , d) ;
    }
    return root ;
}

void takeinput(node* &root){
    int data ;
    
    cin >> data ;
    while(data != -1){
        root = insert(root , data) ;
        cin >> data ;
    }
}

void level_order_traversal(node* root){
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        if(temp != NULL){
            cout<<temp->data<<" ";
        }

        if(temp == NULL){
            cout<<endl ;
            if(!q.empty()){
                q.push(NULL) ;
            }
        }
        else{
            if(temp->left){
                q.push(temp->left) ;
            }
            if(temp->right){
                q.push(temp->right) ;
            }
        }
    }
}

node* inorder_predecessor(node* root , int num , node* pre ){
    if(root == NULL){
        return NULL ;
    }
    if(root->data == num){
        
        if(root->left){
            node* temp = root->left ;
            if(temp->right){
                while(temp->right){
                    temp = temp->right ;
                }
                pre = temp ;
            }
        }
    }
    else if(num > root->data){
        pre = root ;
        inorder_predecessor(root->right , num , pre ) ;
    }
    else{
        
        inorder_predecessor(root->left , num , pre) ;
    }
}



int main(){
    node* tree = NULL ;
    cout<<"Data as input in tree : "<<endl ;
    takeinput(tree) ;

    level_order_traversal(tree) ;
    
    return 0 ;
}

