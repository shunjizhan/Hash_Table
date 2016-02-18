#include <string>
#include <iostream>
#include <exception>
#include <cstdio>
using namespace std;

class Student {
 public:
  Student();
  Student(std::string name, double gpa);
  std::string getName();
  double getGPA();
  
 private:
  std::string name;
  double gpa;
};

template<class T>
class HashEntry {
 public:
  HashEntry();
  HashEntry(int key, T value);
  int getKey();
  T getValue();
  void setKey(int key);

 private:
  T value;
  int key;
};


//////// HashEntry Implementation ////////

template<class T>
HashEntry<T>::HashEntry() {
  this->key = -1;
}

template<class T>
HashEntry<T>::HashEntry(int key, T value){
  this->key = key;
  this->value = value;
}

template<class T>
int HashEntry<T>::getKey(){
  return this->key;
}

template<class T>
T HashEntry<T>::getValue(){
  return this->value;
}

template<class T>
void HashEntry<T>::setKey(int key){
  this->key = key;
}


