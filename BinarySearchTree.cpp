#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void search(Node* node, int num){
        if(num == node->data){
            cout<<"Number found.";
        return;
        }
        else if(num > node->data && node->right != NULL){
            search(node->right, num);
        }
        else if(num < node->data && node->left != NULL){
            search(node->left, num);
        }
        else {
         cout<<"Number not found.";}
}
   

int main(){
    int num;

    Node* root = createNode(8);
    
    root->left = createNode(6);
    root->right = createNode(10);

    root->left->left = createNode(5);
    root->left->right = createNode(7);
    root->right->left = createNode(9);
    root->right->right = createNode(11);

    cout<<"Input the number you want to find : ";
    cin>>num;

    search(root, num);
}