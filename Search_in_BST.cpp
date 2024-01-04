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
            this->right = this->left = NULL ;
        }

};

int search(node* root , int ser){
    if(root->data == ser){
        return 1 ;
    }
    else{
        if(ser > root->data){
            return search(root->right , ser) ;
        }
        if(ser < root->data){
            return search(root->left , ser) ;
        }
    }
    return 0 ;
}

node* insert(node* &root , int d){
    if(root == NULL){
        root = new node(d) ;
        return root ;
    }
    if(d > root->data){
        root->right = insert(root->right , d) ;
    }
    if(d < root->data){
        root->left = insert(root->left , d) ;
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

int main(){
    cout<<"Enter elements for binary search tree : "<<endl;
    node* tree = NULL ;
    takeinput(tree) ;
    level_order_traversal(tree) ;
    int x = search(tree , 4) ;
    if(x == 1){
        cout<<"Element found !"<<endl ;
    }
    else{
        cout<<"Element not found !"<<endl ;
    }
    return 0 ;

}

