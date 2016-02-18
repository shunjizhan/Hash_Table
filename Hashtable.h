#include <string>
#include <iostream>
#include <exception>
#include <cstdio>
#include <iomanip>
#include "Student.h"
using namespace std;

template <class T>
class table {
 public:
  table();
  ~table();
  table(int size);
  void insert(int key, T value);
  void lookup(int key);
  bool lookup_bool(int key);
  void remove(int key);
  void print();
  void grow();

  int getSize();
  int getUsed();
  void setSize(int size); 
  void setUsed(int used);
  void setMode(int mode);

  void updateLoad();
  int findNextPrime(int size);
  bool isPrime(int number);

  int hash1(int k);
  int hash2(int k);
  //int hash2(int k, int i);

  HashEntry<T>** Array;
  
 private:
  int size;
  int used;
  int mode;
};

/////////////////////////////////////////////////////////////////////

template <class T>
table<T>::table() {
  this->size = 5;
  this->mode = 1;
  this->used = 0;
  Array = new HashEntry<T>*[this->size];
  for(int i=0; i<5; i++) {
    Array[i] = new HashEntry<T>;
    Array[i]->setKey(-1);
    }
}

template <class T>
table<T>::~table() {
  for(int i=0; i<getSize(); i++) {
    delete Array[i];
    }
}


template <class T>
table<T>::table(int size) {
  this->size = size;
  this->mode = 1;
  this->used = 0;
  Array = new HashEntry<T>*[this->size];
  for(int i=0; i<size; i++) {
    Array[i] = new HashEntry<T>;
    Array[i]->setKey(-1);
    }
}


template <class T>
void table<T>::insert(int key, T value) {
    int h1 = hash1(key);
    int index = h1;
  if (this->mode == 1) {             // mode 1
    while(Array[index]->getKey() != -1) {
      index++;
      index = index % getSize();
    }
  }

  else if (this->mode == 2) {            // mode 2
      while(Array[index]->getKey() > 0) {
	/*cout << "index=" << index ;
	  cout << "hash2=" << hash2(keyi) <<endl;*/
	int h2=hash2(key);
	index += h2;
	index = index % getSize();
      }

    
  }
  
  //delete Array[index];
  Array[index] = new HashEntry<T>(key, value);
  //cout <<"1";
  updateLoad();
  //cout <<"2";
  cout << "item successfully inserted" << endl;
  
}
  



template <class T>
void table<T>::lookup(int key) {
  int index = hash1(key);
  int count = 0;
  while (Array[index]->getKey() != key) {
    index = (index+1) % getSize();
    count ++;
    if (count > getSize()) {
      cout << "item not found" << endl;
      return;
    }
  }

  cout <<  "item found; " << Array[index]->getValue().getName() << " ";
  cout << index << endl;
 }

template <class T>
bool table<T>::lookup_bool(int key) {
  int index = hash1(key);
  int count = 0;
  while (Array[index]->getKey() != key) {
    index = (index+1) % getSize();
    count ++;
    if (count > getSize()) {
      return false;
    }
  }
  return true;
 }


template <class T>
void table<T>::remove(int key) {
  int index = hash1(key);
  int count = 0;
  while (Array[index]->getKey() != key) {
    index = (index+1) % this->getSize();
    count ++;
    if (count > this->getSize()) {
      cout << "item not present in the table" << endl;
      return;
    }
  }
  
  Array[index]->setKey(-1);
  cout <<  "item successfully deleted" << endl ;
  setUsed(getUsed()-1);
}


template <class T>
void table<T>::print() {
  for(int i=0; i<getSize(); i++) {
    if (Array[i]->getKey() != -1) {
    cout << "(" << Array[i]->getKey() << "," 
     << Array[i]->getValue().getName() << ",";
    cout << std::fixed << std::setprecision(1) << Array[i]->getValue().getGPA() << ")";
    }
  }
  cout << endl;
}

////////////////////////// insert helper /////////////////////////////////////

template <class T>
void table<T>::updateLoad() {
  setUsed(getUsed()+1);
  int newload = getUsed()/(double)getSize();
  if (newload > 0.7) {
    grow();
  }
}

template <class T>
void table<T>::grow() {
  int oldsize = getSize();
  int newsize = findNextPrime(2*oldsize);
  setSize(newsize);
  cout << "table doubled" << " "
       << "size=" << getSize() << endl;

  HashEntry<T>** temp = new HashEntry<T>*[newsize];
  for(int i=0; i<newsize; i++) {
    temp[i] = new HashEntry<T>;
    temp[i]->setKey(-1);
  }

  // rehash exist students
  int keyi;
  int h1;
  int index;
  for(int i=0; i<oldsize; i++){
    keyi = Array[i]->getKey();
    if(keyi > 0){
    h1 = hash1(keyi);
    index = h1;
    
    if (this->mode == 1) {                   // mode 1
    while(temp[index]->getKey() != -1) {
      index++;
      index = index % getSize();
    }
    }                                       // end mode 1

    else if (this->mode == 2) {             // mode 2
      int i=0;
      while(temp[index]->getKey() > 0) {
	/*cout << "index=" << index ;
	  cout << "hash2=" << hash2(keyi) <<endl;*/
	int h2=hash2(keyi);
	index += h2;
	index = index % getSize();
      }
    
    }                                         // end mode 2
    
    //delete temp[index];
    temp[index] = new HashEntry<T>(keyi, Array[i]->getValue());  
    }}                                        // end for loop

  for(int i=0; i<oldsize;i++){
    delete Array[i];
  }
  Array = new HashEntry<T>*[newsize];
  for(int i=0; i<newsize;i++){
    Array[i] = new HashEntry<T>(temp[i]->getKey(),temp[i]->getValue());
  }
   delete [] temp;
  /*Array = temp;
    for(int i=0;i<oldsize;i++){
      delete temp[i];
      }*/
     
}

  

template <class T>
int table<T>::findNextPrime(int size) {
  int newprime = size+1;
  while(true) {
    if(isPrime(newprime)){
      return newprime;
    }
    newprime++;
  }
}

template <class T>
bool table<T>::isPrime(int number) {
  if(number<2) {return false;}
  for(int i=2; i<number; i++) {
    if(number % i == 0){
      return false;
    } 
 }
  return true;
}

///////////////////////// set and get methods ////////////////////////////

template <class T>
int table<T>::getSize() {
  return this->size;
}


template <class T>
void table<T>::setSize(int size) {
  this->size = size;
}


template <class T>
int table<T>::getUsed() {
  return this->used;
}


template <class T>
void table<T>::setUsed(int used) {
  this->used = used;
}


template <class T>
void table<T>::setMode(int newmode) {
  this->mode = newmode;
}

template <class T>
int table<T>::hash1(int k) {
  return (k % 492113) % getSize();
}


template <class T>
int table<T>::hash2(int k) {
  if((k % 392113) % getSize()==0){
    return 1;
  }
  return ((k % 392113) % getSize());
}

