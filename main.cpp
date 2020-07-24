#include<iostream>
#include <fstream>
#include <conio.h>
#include "class_BST.cpp"
using namespace std;

int main()
{
	ifstream file;
	file.open("password.txt");
	string word = "";
	int maxLength = 0;
	while(!file.eof())
	{
		getline(file,word);
		if(word.length() > maxLength)
		{
			maxLength = word.length();
		}
	}
	maxLength = maxLength + 1;
	BST bst[maxLength];

	file.seekg(0,ios::beg);
	while(!file.eof())
	{
		getline(file,word);
		bst[word.length()].insert(word);
	}
	
	file.close();
	
	//getting encrypted text from user
	string enWord = "";
	cout << "\nEnter Encrypted Word: " ;
	cin >> enWord;
	
	int enSize = enWord.length();
	
	char c0,c1,c2,c3,c4,c5;
	string check0 = "";    		//subtraction
	string check1 = "";			//addition
	string check2 = "";			//increasing order
	string check3 = "";			//decreasing order
	string check4 = "";			//even odd
	
	int flag = 0;
	for(int i=0; i<256; i++)
	{
		check0 = "";    		//subtraction
		check1 = "";			//addition
		check2 = "";			//increasing order
		check3 = "";			//decreasing order
		check4 = "";			//even odd
		
		for(int j=0; j<enSize;j++)
		{
			c0 = enWord[j] - i;
			check0 = check0 + c0;  	//subtraction
			
			c1 = enWord[j] + i;
			check1 = check1 + c1;  	//addition

			c2 = enWord[j] + i + j + 1;
			check2 = check2 + c2;  	//increasing order
			
			c3 = enWord[j] + i - j - 1; 
			check3 = check3 + c3;  	//decreasing order
			
			if(j%2 == 0)
				c4 = enWord[j] - i;
			else
				c4 = enWord[j] + i;
					
			check4 = check4 + c4;  	//even odd
		}
		
		if(bst[enSize].search(check0)) 
		{
			cout << "\n Decrypted Word : " << check0;
			cout << "\n Key : " << i;
			cout << "\n Operation: Subtraction" ;
			flag = 1;
			break;
		}
		else if(bst[enSize].search(check1))
		{
			cout << "\n Decrypted Word : " << check1;
			cout << "\n Key : " << i;
			cout << "\n Operation: Addition" ;
			flag = 1;
			break;
		}
		else if(bst[enSize].search(check2))
		{
			cout << "\n Decrypted Word : " << check2;
			cout << "\n Key : " << i;
			cout << "\n Operation: Increasing Order" ;
			flag = 1;
			break;
		}
		else if(bst[enSize].search(check3))
		{
			cout << "\n Decrypted Word : " << check3;
			cout << "\n Key : " << i;
			cout << "\n Operation: Decreasing Order" ;
			flag = 1;
			break;
		}
		else if(bst[enSize].search(check4))
		{
			cout << "\n Decrypted Word : " << check4;
			cout << "\n Key : " << i;
			cout << "\n Operation: Even Odd" ;
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		cout << "\n Value Not Found :(" ;
	}
	
	for(int i=0; i<maxLength; i++)
	{
		bst[i].~BST();
	}
	
	return 0;
}
