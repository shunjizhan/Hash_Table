# Introduction
This is a hash table written in C++, which can do linear probing and double hashing.

# Run
    cd Hash_Table/
    make hashTable

# Functionalities:
`insert [key] [value]` insert an entry into the hashtable.     
`lookup [key]` Use the hash table to determine if key is in the data structure and print its associated value and also the position separated by a single space.    
`remove [key]` Use the hash table to determine where key is, delete it from the hash table.    
`print:` Print out the hash table (in the array format).    

# Sample Input
    linearprobing     
    insert 8670959 asad 3.9 insert 7670931 victor 3.6 insert 7636338 omid 4.0 lookup 7636338      
    insert 5712195 jin 2.5 print      
    delete 4444444    
    delete 5712195      
    print       
    delete 7636338      
    lookup 8670959      
    delete 8670959      
    print       

# Sample Output
    item successfully inserted item successfully inserted item successfully inserted item found; omid 4     
    table doubled     
    item successfully inserted (7670931,victor,3.6)(7636338,omid,4)(5712195,jin,2.5)(8670959,asad,3.9) item not present in the table     
    item successfully deleted (7670931,victor,3.6)(7636338,omid,4)(8670959,asad,3.9)     
    item successfully deleted     
    item found; asad 8     
    item successfully deleted     
    (7670931,victor,3.6)     

# Specification
- It takes in a 7-digit positive integer or less as a key and stores both the key and the associated Student object.    
- Collisions will be resolved through linear probing or double hashing.
- Dynamic resizing is supported such that the table size will be doubled if the load factor crosses over 0.7.
- Deletions is through the lazy deletion method.

# Author
Shunji Zhan