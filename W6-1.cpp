#include <iostream>
#include <stack>

using namespace std;

class BinTreeNode{
public:
  BinTreeNode(int value){
    this->value=value;
    this->left=NULL;
    this->right=NULL;
  }
  int value;
  BinTreeNode* left;
  BinTreeNode* right;

};

BinTreeNode* tree_insert(BinTreeNode* tree, int item){
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)
      if(tree->left==NULL)
        tree->left=new BinTreeNode(item);
      else
        tree_insert(tree->left,item);
    else
      if(tree->right==NULL)
        tree->right=new BinTreeNode(item);
      else
        tree_insert(tree->right,item);
  return tree;

}

void postorder(BinTreeNode* tree){
  if(tree->left!=NULL)
    postorder(tree->left);
  if(tree->right!=NULL)
    postorder(tree->right);
  cout << tree->value << endl;

}

/*void in_order(BinTreeNode* tree){
  if(tree->left!=NULL)
    in_order(tree->left);
  cout << tree->value << endl;
  if(tree->right!=NULL)
    in_order(tree->right);
}*/

void in_order(BinTreeNode* tree){               //iterative in order

    BinTreeNode* currentNode = tree;
    stack<BinTreeNode*> nodeStack;
    bool endOfTree = false;

    while (endOfTree == false)
    {
        if (currentNode != NULL)                //if current node is not empty
        {
            nodeStack.push(currentNode);        //places value into stack
            currentNode = currentNode->left;    //navigating to left child of current node
        }
        else if (currentNode == NULL && !nodeStack.empty())     //if current node is empty and node stack is not empty
        {
            currentNode = nodeStack.top();      //return to previous node
            cout << currentNode->value << endl; //prints the value
            nodeStack.pop();                    //removes node in stack
            currentNode = currentNode->right;   //navigates to right child of current node
        }
        else
        {
            endOfTree =  true;                  //break out of while loop
        }

    }
}

//insert tree sort

void treeSort(int item[],int length)
{

    BinTreeNode* tree = tree_insert(0,item[0]); //inserting the root node
    for (int i = 1; i < length; i++) {
        tree_insert(tree, item[i]);             //inserting child nodes
    }
    in_order(tree);                             //print values in order
}

void W6_1()
{
  //BinTreeNode* t=tree_insert(0,6);
  //tree_insert(t,10);
  //tree_insert(t,5);
  //tree_insert(t,2);
  //tree_insert(t,3);
  //tree_insert(t,4);
  //tree_insert(t,11);
  //in_order(t);

  int numbers[] = {2,4,8,3,12,5,10};                //declaring sample array
  int length = sizeof(numbers) / sizeof(numbers[0]);//finding length must be done outside function [in function, will return
                                                    //length of pointer instead]
  treeSort(numbers,length);                         //perform tree sort algorithm

}
