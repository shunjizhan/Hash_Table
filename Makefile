CXX=clang++
# CXX=g++

hashTable: Student.o Hashtable.o Main.o
	${CXX} Student.o Hashtable.o Main.o -o hash

clean:
	/bin/rm -f *.o Hashtable.o Student.o Main.o hash

Hashtable.o: Hashtable.cpp
	${CXX} -c Hashtable.cpp

Student.o: Student.cpp
	${CXX} -c Student.cpp

Main.o: Main.cpp
	${CXX} -c Main.cpp
