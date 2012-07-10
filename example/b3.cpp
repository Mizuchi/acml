#include<acml/acml.hpp>
#include<acml/json.hpp>
#include<string>
#include<iostream>
using namespace std;

struct TreeNode {
    TreeNode *leftChild, *rightChild;
    TreeNode(): leftChild(NULL), rightChild(NULL) {}
};

ACML_REGISTER_HANDLE(TreeNode*, visitor, value) {
    if(value != NULL) {
        if(value->leftChild != NULL)  
            visitor(value->leftChild, "left_child");
        if(value->rightChild != NULL) 
            visitor(value->rightChild, "right_child");
    }
}

int main() {
    typedef TreeNode Node;
    Node *r = new Node;
    r->leftChild = new Node;
    r->rightChild = new Node;
    r->leftChild->rightChild = new Node;
    cout << acml::json::dumps(r) << endl;    
    
    //  We build a tree looks like this::
    //
    //      r 
    //     / \
    //    #   #
    //     \
    //      #
}
                                
                                
                                
                                
                                
                                
                                
                                
