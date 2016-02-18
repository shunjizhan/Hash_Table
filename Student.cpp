#include "Student.h"

Student::Student() {}
Student::Student(std::string name, double gpa) {
  this->name = name;
  this->gpa = gpa;
}

std::string Student::getName() {
  return this->name;
}

double Student::getGPA() {
  return this->gpa;
}

