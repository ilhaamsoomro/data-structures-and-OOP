#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* createNode (char data){
    Node* newnode = new Node();
    newnode->data= data;
    newnode->left= newnode->right= nullptr;
    return newnode;
}

void printinorder (Node* rootnode){

    if (rootnode == nullptr) return; 
    
     printinorder(rootnode->left);
     cout<<rootnode->data;
     printinorder(rootnode->right);
}
void printpreorder (Node* rootnode){
    if (rootnode == nullptr) return; 

     cout<<rootnode->data;
     printpreorder(rootnode->left);
     printpreorder(rootnode->right);
}

void printpostorder (Node* rootnode){
    if (rootnode == nullptr) return; 
     printpostorder(rootnode->left);
     printpostorder(rootnode->right);
     cout<<rootnode->data;
}


int main(){
    Node* rootnode = createNode('-');
    rootnode->left = createNode('a');
    rootnode->right = createNode('b');

    cout<<"Preorder : ";
    printpreorder(rootnode);

    cout<<"\nInorder : ";
    printinorder(rootnode);

    cout<<"\nPostorder : ";
    printpostorder(rootnode);

}
