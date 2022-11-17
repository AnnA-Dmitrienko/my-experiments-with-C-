//Dictionary.h 
#pragma once 
#include<iostream> 
#include<iomanip> 
using namespace std;

template <typename T>
class Dictionary
{
private:
   struct TreeNode
   {
      T value{};
      TreeNode* left{};
      TreeNode* right{};
   };

   TreeNode* root;

   //private functions 
   void insert(TreeNode*&, TreeNode*&);
   void destroySubTree(TreeNode*);
   void deleteNode(T, TreeNode*&);
   void makeDeletion(TreeNode*&);
   void displayInOrder(TreeNode*)const;
   void displayByCount(TreeNode* )const;
   int count1(TreeNode*);



public:
   Dictionary()		// default Constructor 
   {
      root = nullptr;

   }

   Dictionary(struct TreeNode tree)		//  parameterized Constructor 
   {
      tree = nullptr;

   }
   virtual ~Dictionary()	// Destructor 
   {
      destroySubTree(root);
      cout << "\nDestructor...all nodes were deleted!\n";
   }

   //basic operations 
   void insertNode(T);
   bool searchNode(T);
   bool remove(T); //left as bool to check if data is there to be removed  
   int displayCount() {
      return count1(root);
   }

   void showNodesInOrder() const
   {
      cout << "..........................\n";
      cout << "Books  displayed In-Order:\n";
      cout << "..........................\n";
      displayInOrder(root);
   }

   void showNodesFiltered() const
   {
      cout << "..........................\n";
      cout << "Filtered Books (count>1):\n";
      cout << "..........................\n";
      displayByCount(root);
   }

};

template <typename T>
void Dictionary<T>::destroySubTree(TreeNode* nodePtr) {
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

template <typename T>
void Dictionary<T>::makeDeletion(TreeNode*& nodePtr)
{
   TreeNode* tempNodePtr;	// Temporary pointer, used in 
   // reattaching the left subtree. 
   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;
      // Reattach the left child 
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      // Reattach the right child 
      delete tempNodePtr;
   }
   // If the node has two children. 
   else
   {
      // Move one node the right. 
      tempNodePtr = nodePtr->right;
      // Go to the end left node. 
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree. 
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree. 
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

template <typename T>
void Dictionary<T>::deleteNode(T obj, TreeNode*& nodePtr)
{
   if (searchNode(obj)) {
      if (obj < nodePtr->value)
         deleteNode(obj, nodePtr->left);
      else if (obj > nodePtr->value)
         deleteNode(obj, nodePtr->right);
      else
         makeDeletion(nodePtr);
      cout << "Book successfully deleted ";
   }
   else cout << "Cannot delete, no such node in the tree!" << endl;

}


template <typename T>
bool Dictionary<T>::remove(T obj)
{
   deleteNode(obj, root);
   return true;
}


template <typename T>
void Dictionary<T>::displayInOrder(TreeNode* nodePtr)const
{

   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

template <typename T>
void Dictionary<T>::displayByCount(TreeNode* nodePtr)const
{

   if (nodePtr)
   {
      if (nodePtr->value.getCopies() > 1) {

         displayByCount(nodePtr->left);
         cout << "Book is: " << nodePtr->value.getTitle() << endl;
         cout << "# of Copies: " << nodePtr->value.getCopies() << endl << endl;
         displayByCount(nodePtr->right);

     }
    
   }
}

template <class T>
void Dictionary<T>::insert(TreeNode*& root, TreeNode*& newNode)
{
   if (root == nullptr)
      root = newNode;
   else if (newNode->value < root->value)
      insert(root->left, newNode);
   else
      insert(root->right, newNode);
}

template <class T>
void Dictionary<T>::insertNode(T obj)
{
   TreeNode* newNode = nullptr;

   newNode = new TreeNode;
   newNode->value = obj;
   newNode->left = newNode->right = nullptr;

   insert(root, newNode);
}


//search node 
template <typename T>
bool Dictionary<T>::searchNode(T obj) {
   TreeNode* nodePtr = root;
   while (nodePtr) {
      if (nodePtr->value == obj) return true;
      else if (obj < nodePtr->value) nodePtr = nodePtr->left; //traverse left 
      else nodePtr = nodePtr->right; //traverse right  
   }
   return false; //if nothing found  
}

//count the nodes in the tree 
template <class T>
int Dictionary<T>::count1(TreeNode* root)
{
   int count = 1;
   if (root->left != nullptr)
   {
      count += count1(root->left);
   }
   if (root->right != nullptr)
   {
      count += count1(root->right);
   }
   return count;
}


