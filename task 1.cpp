

#include <iostream>
using namespace std;
class node {
public:
    int data;
    Node* left;
    Node* right;
    
    node( int value){
        data=value;
        left = right = nullptr;
        
    }
};
class tree{
public:
    Node* root;
    tree(){
        root = null ptr;
    } (Node* node, int value){
        if (node == nulptr){
            return new Node(value);
        }
        if (value < node->date){
            node -> left = insert (node -> left, value);
        }
    }else{
        node->right= insert(node->right, value);
    }
    return node;
    void inordertraversal(Node* node){
        if (node != nullptr){
            inordertraversal(node->left);
            cout<< node-> data<<" ";
            inordertraversal(node->right);
           
        }
    }
     void preordertraversal(Node* node){
        if (node != nullptr){
            cout<< node-> data<<" ";
            preordertraversal(node->left);
            preordertraversal(node->right);
        }
    void postordertraversal(Node* node){
        if (node != nullptr){
            postordertraversal(node->left);
            postordertraversal(node->right);
            cout<< node-> data<<" ";
            
        }
     }
}
        