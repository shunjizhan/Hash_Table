// Hashtable Project

#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <ctime>
#include "Hashtable.h"
using namespace std;

int main()
{
  
  //freopen("DoubleHashing.txt","r",stdin);
  freopen("LinearProbing.txt","r",stdin);

  //clock_t start, end; 
  //start = clock();
  //int i = 1;

	try
	{
		table<Student> h;

		while(true)
		{
			string str;
			cin >> str;
			if(cin.eof())
			{
				break;
			}
			if(str.compare("exit") == 0)
			{
				break;
			}
			else if(str.compare("linearprobing") == 0)
			{
				h.setMode(1);
			}
			else if(str.compare("doublehashing") == 0)
			{
				h.setMode(2);
			}
			else if(str.compare("insert") == 0)
			{
				int key;
				string name;
				double gpa;
				cin >> key >> name >> gpa;
				Student tmp(name, gpa);
				h.insert(key, tmp);

				/*   
				  if(h.getUsed()==i*2500){
				     cout << "insert=" << i*2500 << " " << "runningtime=" << clock()-start << endl;
				     i++;
				  }
				*/
			}
			else if(str.compare("lookup") == 0)
			{
				int key;
				cin >> key;
				h.lookup(key);
			}
			else if(str.compare("delete") == 0)
			{
				int key;
				cin >> key;
				h.remove(key);
			}
			else if(str.compare("print") == 0)
			{
				h.print();
			}
			else
			{
				cin.clear();
				cout << "Inputed string format was incorrect" << endl;
			}
		}
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}

	/*
        end = clock();
	double diff = double(end-start);
	cout << "total running time is:" << diff << endl;
	*/
	
	return 0;

}

