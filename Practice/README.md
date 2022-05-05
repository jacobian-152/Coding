# Practice

# Basics

This write-up covers the basic knowledge required to start competitive coding. The contents of this write-up are not the author's own property but are a result of abstraction from multiple sources, and should be considered only for knowledge sharing.
All the references are provided at the bottom of this page.

## Data type ranges

- **int** : -32,768 to 32767
- **unsigned int** : 0 to 65535
- **long int** : -2,147,483,648 to 2,147,483,647
- **unsigned long int** :0 to 4,294,967,295
- **long long int** : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
- **unsigned long long int** : 0 to 18,446,744,073,709,551,615
- **float** : 3.4E-38 to 3.4E+38
- **double** : 1.7E-308 to 1.7E+308
- **long double** : 3.4E-4932 to 1.1E+4932

## Macros

[TO-DO]

## Standard Template Library

Header

```c
#include<bits/stdc++.h>
//OR
#include<vector>
#include<set>
#include<map>
#include<algorithm> ...

using namespace std;

```

### 1. Vector

```c
// Declaration
// 1-D vector
vector<int> V1; // Empty vector.
vector<int> V2(10); // Vector of size 10. By default will be zero.
vector<int> V3 = V2; // Copy - V3 is equal to V2 by value.
vector<int> V4(V2); // Copy - V4 is equal to V2 by value.
vector<string> V5(10, "default") // Vector of size 10 and all value initialized as "default."
// 2-D vector
vector< vector <int> > matrix; // Empty 2-D vector or matrix.
vector< vector <int> > matrix(N, vector<int> (M, 0)) // N x M 2-D matrix initialized to 0.

// Built-in methods
unsigned int size = V2.size();
bool isEmpty = V2.empty();

// Adding element
V1.push_back(1);
V2.push_back(2); // Output vector=0,0,0,0,0,0,0,0,0,0,2
V2[0] = 3; // Output vector=3,0,0,0,0,0,0,0,0,0,2

// Resize vector
V2.resize(20);

// Clear vector
V2.clear();

// Insert element.
V2.insert(position, value);

// Erase element
V2.erase(iterator);
V2.erase(begin iterator, end iterator);

// Iterator for first and last element
V2.begin();
V2.rbegin();

// Iterator for last and first element
V2.end();
V2.rend();

// Pass by value
void function(vector<int> V1){}

// Pass by reference
void function(vector<int> &V2){} // Use 'const' to ensure vector is immutable.
```

#### Point/s:

- Vector when passed by value as a parameter to a function consumes time and space, so pass only if required.

### 2. Pairs

```c
// Declaration
pair<string,string> point;
string firstVal = point.first;
string secondVal = point.second;
```

#### Point/s:

- Pairs are compared from first to second when sorting.

### 3. Iterators

```c
for(vector<int> ::iterator it = V.begin(); it != V.end(); it++){
    cout<< *it<<" ";
}
// OR use auto
for(auto it = V.begin(); it != V.end(); it++){
    cout<< *it<<" ";
}
// OR using typeof
for(typeof(V.begin()) it = V.begin(); it != V.end(); it++){
    cout<< *it<<" ";
}

// find() built-in method. Time complexity = O(N)
auto it = find(V.begin(), V.end(), 5) // Will search and return iterator for element 5.
bool exists = (find(V.begin(), V.end(), 5)!=V.end())
int elementPos = find(V.begin(), V.end(), 5) - V.begin()

// max_element built-in method
int maxElement = * max_element(V.begin(), V.end())
int maxElementPos = max_element(V.begin(), V.end()) - V.begin()

// sort built-in method
sort(V.begin(), V.end()) // Ascending order
sort(V.rbegin(), V.rend()) // Descending order

// constant iterator ; CV is a constant vector.
for(vector<int> ::const_iterator = CV.begin(); it != CV.end(); it++){
    cout<< *it<<" ";
}
```

### 4. String

```c
string s = "Hello World!!";
string subStr_1 = s.substr(0,2); // output : "He"
string subStr_2 = s.substr(6); // output : "World!!"
int size = s.length();
```

### 5. Set

```c
set<int> S;
S.insert(1);
S.erase(1); // Takes element.
int size = S.size();
bool exists = S.find(1) != S.end(); // Check points below

unordered_set<int> US;
```

### 6. Map

```c
map<string, int> M;
M["key"] = 1;
S.erase(iterator);
int size = S.size();

unordered_map<int, int> UM;

// Traversing
for(typeof(UM.begin()) it=UM.begin(); it!= UM.end(); it++){
    cout<<"First element : "<< it->first <<endl;
    cout<<"Second element : "<< it -> second <<endl;
}
```

#### Point/s:

- When finding element in set and maps do not use global find method. Instead, use the member function "find()". The time complexity of this is O(logN) - lower than the O(N) of find() global algo.
- Internally both set and map are almost always stored as red-black trees.
- **map** and **set** elements are stored in sequential order. So it is strongly discouraged to change element while traversing. Use unordered_map and unordered_set instead.

### 7. Algorithms

```c
min(a,b);
max(a,b);
swap(a,b);
sort(begin, end);
find(begin, end, element);
count(begin, end, element);
next_permutation(begin, end); // Returns true if next permutation exists, otherwise false.
prev_permutation(begin, end); // Returns true if prev permutation exists, otherwise false.
```

#### Point/s:

- Sort elements to check all permutations before using "next_permutation"

## References

1. [Power up C++ with the Standard Template Library Part One](https://www.topcoder.com/thrive/articles/Power%20up%20C++%20with%20the%20Standard%20Template%20Library%20Part%20One)
2. [Power up C++ with the Standard Template Library Part Two: Advanced Uses](https://www.topcoder.com/thrive/articles/Power%20up%20C++%20with%20the%20Standard%20Template%20Library%20Part%20Two:%20Advanced%20Uses)

## Author

Niranjan Kumawat
Contact: niranjankumawat152@gmail.com
