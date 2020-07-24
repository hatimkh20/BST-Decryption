#include<iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class BST 
{
	struct Node 
	{
	    string data;
	    Node* left;
	    Node* right;
	};
	
	Node* root;
	
	Node* makeEmpty(Node* root) 
	{
	    if(root == NULL)
	        return NULL;
	    {
	        makeEmpty(root->left);
	        makeEmpty(root->right);
	        delete root;
	    }
	    return NULL;
	}
	
	//insert
	Node* insert(string value, Node* root)
	{
	    if(root == NULL)
	    {
	        root = new Node;
	        root->data = value;
	        root->left = root->right = NULL;
	        return root;
	    }
	    else
	    {
			if(value < root->data)
		        root->left = insert(value, root->left);
		    
			else
		        root->right = insert(value, root->right);
		    
			return root;
		}
	}
	
    //search
	int search(Node* root,string value)
	{
		if(root == NULL)
		{
			return 0;
		}
		else
		{
			if(root->data == value)
			{
				return 1;	
			}
			else if(value < root->data)
			{
				return search(root->left, value);
			}
			else
			{
				return search(root->right, value);	
			}
		}
	}
	
	//traversal
	void inOrder(Node* root)
	{
		
		if(root!= NULL)
		{
			inOrder(root->left);
			cout<< root->data << "  ";
			inOrder(root->right);	
		}
	}
	
	public:
    BST() 
	{
        root = NULL;
    }

    ~BST()
	{
        root = makeEmpty(root);
    }

    void insert(string value) 
	{
        root = insert(value, root);
    }
    
    int search(string value)
    {
    	return search(root,value);
	}
    
    void display()
    {
    	inOrder(root);
	}
};

