#include <iostream>
using namespace std;
class BST
{
   BST *left, *right;
   int data;

public:
   
   BST()
   {
      data = 0;
      left = NULL;
      right = NULL;
   }
   BST(int value)
   {
      data = value;
      left = NULL;
      right = NULL;
   }
   // insertion
   BST *insert(BST *root, int value)
   {
      if (root == NULL)
         return new BST(value);

      if (value > root->data)
         root->right = insert(root->right, value);
      else if (value < root->data)
         root->left = insert(root->left, value);
      return root;
   }
   // search value
   BST *search(BST *root, int key)
   {

      if (root == NULL || root->data == key)
         return root;

      if (root->data < key)
         return search(root->right, key);

      return search(root->left, key);
   }
   // in_order transversal

   void in_order(BST *root)
   {
      if (root != NULL)
      {
         in_order(root->left);
         cout << root->data << " ";
         in_order(root->right);
      }
   }
   // pre_order transversal
   void pre_order(BST *root)
   {
      if (root != NULL)
      {
         cout << root->data << " ";
         pre_order(root->left);
         pre_order(root->right);
      }
   } // post_order transversal
   void post_order(BST *root)
   {
      if (root != NULL)
      {
         post_order(root->left);
         post_order(root->right);
         cout << root->data << " ";
      }
   }
   // height of node
   int height(BST *root)
   {
      if (root == NULL)
      {
         return 0;
      }
      else
      {
         int left_side = height(root->left);
         int right_side = height(root->right);
         if (left_side > right_side)
         {
            return (left_side + 1);
         }
         else
         {
            return (right_side + 1);
         }
      }
   }
   // extreme left contain min value
   int min_value(BST *root)
   {
      BST *current = root;
      while (current->left != NULL)
         current = current->left;
      return current->data;
   }
   // extreme right contain max value
   int max_value(BST *root)
   {
      BST *current = root;
      while (current->right != NULL)
         current = current->right;
      return current->data;
   }
   // min value whole node return
   BST *min_value_address(BST *root)
   {
      BST *current = root;
      while (current->left != NULL)
         current = current->left;
      return current;
   }
   // max value whole node return
   BST *max_value_address(BST *root)
   {
      BST *current = root;
      while (current->right != NULL)
         current = current->right;
      return current;
   }
   // delete whole tree
   void delete_whole_BST(BST *root)
   {
      if (root != NULL)
      {
         delete_whole_BST(root->left);
         delete_whole_BST(root->right);
         delete root;
      }
   }
   // delte node
   BST *delete_node(BST *root, int element)
   {

      if (root == NULL)
         return root;
      if (element < root->data)
         root->left = delete_node(root->left, element);
      else if (element > root->data)
         root->right = delete_node(root->right, element);
      else
      {
         // leaf node no child
         if (root->left == NULL && root->right == NULL)
         {
            return NULL;
         }
         // node have only one right child
         else if (root->left == NULL)
         {
            BST *temp = root->right;
            delete root;
            return temp;
         }
         // node have only one left child
         else if (root->right == NULL)
         {
            BST *temp = root->left;
            delete root;
            return temp;
         }
         // root node delted than its work
         BST *temp = min_value_address(root->right);
         root->data = temp->data;
         root->right = delete_node(root->right, temp->data);
      }
      return root;
   }
};

int main()
{
   int element;
   BST b, *root = NULL;
   root = b.insert(root, 50);
   b.insert(root, 60);
   b.insert(root, 40);
   b.insert(root, 70);
   b.insert(root, 30);
   b.insert(root, 45);
   b.insert(root, 55);
   b.insert(root, 33);
   b.insert(root, 67);
   b.insert(root, 11);
   for (int i = 0; i < 100; i++)
      b.insert(root, i);

   cout << "Inorder Traversal of Binary Search Tree : ";
   cout << endl;
   b.in_order(root);
   cout << endl;

   cout << "Height of BST is " << b.height(root) << endl;

   cout << "Enter element to find in tree: ";
   cin >> element;

   if (b.search(root, element))
      cout << element << " is present in tree.\n";
   else
      cout << element << " is not present in tree.\n";

   cout << "Minimum Value in BST is: " << b.min_value(root) << endl;
   cout << "Maximum Value in BST is: " << b.max_value(root) << endl;
   cout << endl;
   cout << "Enter Element to delete: ";
   cin >> element;

   b.delete_node(root, element);
   cout << endl;

   cout << "Inorder Traversal of Binary Search Tree after deleting node: ";
   cout << endl;

   b.in_order(root);
   cout << endl;

   b.delete_whole_BST(root);
   return 0;
}
