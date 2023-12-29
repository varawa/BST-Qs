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
    if(root == NULL){
        cout<<"Tree is empty !"<<endl ;
    }
    else{
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
}

node* delete_node(node* &root , int del){
    if(root == NULL){
        cout<<"Tree is empty !"<<endl ;
        return NULL ;
    }
    else{
        if(root->data == del){
            if(root->left == NULL && root->right == NULL){
                delete root ;
                return NULL ;
            }
            if(root->left && !root->right){
                root = root->left ;
                delete root->left ;
                return root ;
            }
            if(!root->left && root->right){
                root = root->right ;
                delete root->right ;
                return root ;
            }
            if(root->left && root->right){
                node* newsuc = NULL ;
                node* temp = root->left ;
                while(temp->right){
                    newsuc = temp ;
                    temp = temp->right ;
                }
                root->data = temp->data ;
                if(newsuc != root){
                    newsuc->right = temp->left ;
                }
                else
                {
                    newsuc->left = temp->left ;
                }
                delete temp ;
                return root ;
            }
        }
        if(del > root->data){
            delete_node(root->right , del) ;
        }
        else{
            delete_node(root->left , del) ;
        }

    }
    return root ;
}

int main(){
    node* tree = NULL ;
    cout<<"Data as input in tree : "<<endl ;
    takeinput(tree) ;

    level_order_traversal(tree) ;
    tree = delete_node(tree , 70) ;
    level_order_traversal(tree) ;
    
    return 0 ;
}

