# PR02 - Part 1 - Vector
CS273 Whitworth University, Scott Griffith  
Last Modified 2/21/2024   
Reference to Data Structures and Design Using C++ (Koffman, Wolfgang) and other CS faculty and students

## Grade Breakdown
| Vector Sub-task              | Grade |
|------------------------------|-------|
| Documentation                |  10   |
| Implementation               |  25   |
| Unit Test                    |   5   |
| Acceptance Test              |   5   |
|                              |       |
|  __Total__                   |  45  |

## Vector Implementation

First (well... second, after array) basic data structure. We want to make a dynamic array, something that will automatically grow as we add data to it. You are going to be basing your vector on the interface pattern (methods/functions) and behavior of STL definition of vector (http://www.cplusplus.com/reference/vector/vector/). 

### Documentation (10 pts) 
I am not going to require UML diagrams, but you are welcome to provide one. **You will need to fully document your implementation.** Your `vector.h` file should be full of comments and headers. You must have at a minimum: A header for the whole class describing what it does, a header for each method with clear and concise arguments, and good comments in your code.

### Implementation (30 pts)
You will implement your own `vector` data structure. This structure will follow the functionality of the `std::vector`. Your vector class will have to be templated to hold generic data. Your class must be properly separated into two parts: a fully formed .h file and a completed .cpp file. (see the included `TemplateClass` for an example).  

Place your definition of your vector in `namespace cs273`. This will aid in separating out the `std::vector` and your `cs273::vector`.  

You will implement the following methods. You will be graded on how exacting your implementation is to the methods. They need to be the same name and arguments. If not, your vector will not be interchangeable with the `std::vector`.   

* Appropriate Constructors
  * At a minimum an empty constructor and a copy constructor 
* Destructor
* `operator=` - Assignment operator, Minimize number of copies being made and amount of memory being used. __This should be an O(n) operation.__
* `Type& operator[](int index)` and `Type& at(int index)` – Access element at `index`
* `void resize(int n)` – Change the dynamic array to hold `n` elements. Should work for `n` > number of elements and `n` < number of elements  
  * Should be called automatically when inserting / pushing
* `int size()` – Get number of elements in vector 
* `int capacity()` – get total capacity of vector 
* `void assign(int n, Type element)` – Assigns new values to the vector, destroys old values. New vector is all `element` and size = `n`
* `void insert(int index, Type element)` – Insert `element` into the vector at position `index`
  * This is different than the STL. STL uses iterators. That is fine.
* `void push_back(Type element)` – puts `element` at the end of the vector 
* `void pop_back()` – Removes last element in the vector 
* `void erase(int index)` – Removes the `index` element from the vector
  * this is different from the STL. STL uses iterators. That is fine.
* `void swap(vector<Type>& other)` – Swaps the data from `other` into this vector. Should be O(c) 
  
You are welcome to implement other methods, but you must document them. 

### Unit Test (5 pts)
You need to develop a fully functional unit test (`vectorTest.cpp`) for all of the methods you defined above. I would suggest making this at the same time as your vector class. This unit test should show that you can use your vector on any type and that the methods work as intended and documented.

### Acceptance Testing (5 pts)
The first pass at grading your vector is with the included `AssignmentIntegration` application. This code utilizes the `std::vector`, you are going to modify just two lines of code to get it to run with your vector instead.

In [homework.h](./AssignmentIntegration/headers/homework.h) change the following:
```cpp
#include <vector>
using std::vector;
```
to 
```cpp
#include "..\headers\vector.h" //or wherever you keep your .h file
using cs273::vector;
```

If everything is working correctly, that is it!
