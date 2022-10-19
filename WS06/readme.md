# Workshop #6: Class with a Resource
In this workshop, you will implement copy constructor and copy assignment to prevent memory leak and resize allocated memory.

- Version (0.9) under review 


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create copy constructors
- define and create copy assignment 
- Resize dynamically allocated memory.
- Read from and into a file
- Overload insertion operator so the class can be printed using ostream
- Overload extraction operator so the class can be read using istream

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

> This workshop is due in the week after the study break, but start working on it now while the concept is fresh in your mind. <br /> :warning: Also note that the due date of milestone 1 of the project in the same week. 

Depending on the section you are enrolled in, the submission due day of the week may shift a day or two. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]

### Overall workshop due days
- day 1: Workshop open for preview<br/>
  (If you need to check your program with the submitter, you can use `-feedback` option to test the execution without submission)
- day 2: submission opens for both parts 1 and 2
- day 5: (end of day) Part 1 due
- day 8: (end of day) Part 2 due
- day 9: (end of day) submissions rejected

If at the deadline (end of day 8) the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

# Part 1 - LAB (50%) The Numbers Module

Your task for this lab is to complete the implementation of the **Numbers** class. This class reads several double values from a file (one number per line) and holds them dynamically in memory. Then the caller application has the option of adding numbers to the collection. This Module can provide information about the numbers and display them on the screen:<br />
- The Module can display the values in ascending order (sort).
- The Module can find the largest value
- The Module can find the smallest value
- The Module can calculate the average of the values in the collection

Also, The **Numbers** class has the following capabilities: 
- A **Numbers** object can safely be copied or assigned to another **Numbers** module
- A **Numbers** object can be displayed or inserted into an istream object.
- A **Numbers** object can be read or extracted from an istream object.

When the **Numbers** object goes out of the scope the values overwrite the old values in the file, ONLY IF the object is the original object and not a copy.

# The Numbers class
The Numbers class has four attributes:
```C++
    double* m_numbers; // holds the address of the dynamic array of doubles holding the number collection
    char* m_filename;  // holds the name of the file associated with the class (if it is the original object and not a copy)
    bool m_isOriginal; // true if this object is the original (and not a copy)
    int m_numCount; // holds the number of values in the m_number dynamic array
```

## Constructors, Destructor and Copy Assignment

The **Numbers** class can be instantiated in three different ways:

### One argument constructor (implemented)
Creates an original instance of the Numbers class by receiving the data file name as a constant Cstring
- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to true.
- Sets the filename of the class (**setFilename()**)
- Sets the number of the double values to be read from the file (sets m_numCount using **numberCount()**)

If the number of double values in the file is greater than zero it tries to read the values from the file using the **load()** function as follows:

- If not successful, it will free the memory pointed by m_numbers and m_filename
- sets the object back to the safe empty state and sets the class NOT TO BE original anymore.

### Default constructor  (implemented)

- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to false.

### Destructor (implemented)
- Saves the values in the file
- deletes the memory pointed by m_numbers and m_filename

### Copy Constructor (to be implemented by students)
- Sets the object to the safe empty state
- Sets the object NOT to be original
- Assigns the current object to the **Numbers** object that is being copied. (calls the Copy Assignment Operator)


### Copy Assignment Operator (to be implemented by students)
- deletes the current collection of the double values
- sets the object to the safe empty state.
- sets the object not to be original

If this is not a self-copy assignment

- Allocates new memory pointed by m_numbers to the number of the values in the object that is being copied.
- Copies all the double values in the object that is being copied into the newly allocated memory.

In any case the reference of the current object is returned

## Member Functions and Member operator+= overload 

### deallocate() (implemented)
Deallocates the dynamic memory.

### isEmpty() (implemented)
returns true if **m_numbers** is null

### setEmpty() (implemented)
sets m_numbers and m_filename to nullptr.
sets m_numCount to zero.

### setFilename() (implemented)
- Receives a constant Cstring for the data file name.
- Frees the memory pointed by m_filename pointer
- Allocates memory to hold the data file name as a Cstring.
- Copies the data file name to the newly allocated memory.


### max() (implemented)
Returns the largest double number in the list

### min() (implemented)
Returns the smallest double number in the list

### average()  (implemented)
Returns the average of the double numbers in the list.

### Numbers& sort(bool ascending) (to be implemented by students)
Based on the value of the ascending argument, This private method will sort the numbers in ascending or descending order and then returns the reference of the current Numbers object.

Use one of the sort algorithms you learned from IPC144 to sort the numbers:  
[IPC144 Sort Algorithm](https://intro2c.sdds.ca/F-Refinements/algorithms#sorting)

### Unary negation operator ( - )  (to be implemented by students)
```C++
Numbers operator-()const
```
This unary operator (that is incapable of modifying the current object) will return a descending sorted copy of the Numbers object.

### Unary plus operator ( + )  (to be implemented by students)
```C++
Numbers operator+()const
```
This unary operator (that is incapable of modifying the current object) will return an ascending sorted copy of the Numbers object.

### numberCount() (to be implemented by students)
This function (that is incapable of modifying the current object), will return the number of lines in the data file (hence returning the number of double values in the file).
- Create an instance of **ifstream** to open the data file name.
- While the **ifstream** object has not failed keep reading single characters from the file
- Count the number of **newline** characters in an integer variable
- Return the number of counted **newlines** when all characters in the file are scanned.

### load() (to be implemented by students)
This function returns true if all the double values are read from the data file and stored in a dynamically allocated memory pointed by **m_numbers**, otherwise returns false.
- If the number of double values in the file is greater than zero (m_numCount > 0)
- Allocate memory to hold the double values in an array pointed by m_numbers.
- Create an instance of ifstream for the data file
- While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)<br />
> make sure to add to the index of the loop only if the istream object has not failed in its last reading
- return true if the number of read doubles is equal to the m_numCount member variable.

### save() (to be implemented by students)
- If the current object is the original and it is not in a safe empty state
- Create an instance of ofstream to overwrite the data file
- Write all the elements of the m_numbers array using the ofstream object.
- Write a newline after each double value.

### Operatro += (to be implemented by students)
Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object.

You need to increase the size of the allocated memory by one (add one double to the array), to be able to do this. 

Here is the sequence of the actions to be taken to resize memory:
- Create a temporary local pointer and allocate memory with the increased size
- Copy all the current values to the newly allocated memory.
- Update the size of the data to the new size
- Now that all the values are copied to the new memory, delete the original allocated memory
- Set the original data pointer to point to newly allocated memory
- You are done!

[View the Slides](lab/memoryResizing.pdf)

Using the above guidelines; in our case, do the following only if the object is not in an empty state:
- Create a temp double-pointer and allocate memory to the size: **m_numCount + 1**
- In a loop, copy all the double **m_numbers** elements to the double **temp** number elements (up to m_numCount)
- Add one to m_numCount (to update the number of double values)
- copy the value of the double argument to the last element of the double **temp** array (and therefore add the double value to the list)
- delete m_numbers to get rid of the original allocated memory
- Set **m_numbers** to **temp** pointer; by doing this m_numbers will point to the newly allocated memory.

Regardless of whether the object is empty or not return the reference of the current object.

### display function. (to be implemented)
```C++
   ostream& display(ostream& ostr) const
```
Displays the Numbers object on the screen. Note that all the double numbers are printed with two digits after the decimal point. 

- if the object is empty, write **"Empty list"**.
- if the object is not empty start by writing:  **"========================="** on **ostr** and then go to newline
- if the object is flagged as original, then write the file name otherwise write ```"*** COPY ***"``` and then go to a new line
- write all the double numbers separated by **", "** (A comma and a space) and then go to a new line
- write **"-------------------------"** and go to a new line
- Write **"Total of " << m_numCount << " number(s)"** and go to new line
- write **"Largest number:  "** and the largest number in the list and go to a new line
- write **"Smallest number: "** and the smallest number in the list and go to a new line
- write **"Average:         "** and the average of all the numbers in the list and go to a new line
- write **"========================="** and DO NOT GO TO NEWLINE

At the end return the ostr object.

#### Execution sample
A Numbers object that has the double values 34.1, 3, 6, 12.2 and 34.56 in a file called **numbers.txt**<br />
should be displayed as follows:  
```Text
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
```
If a Number object is empty, it will be displayed as follows:
```Text
Empty list
```

## Helper function overloads (to be implemented)
```C++    
ostream& operator<<(ostream& os, const Numbers& N);
```
Overload the insertion operator to display the Numbers object using istream.
- call the display function of N and return it

```C++
istream& operator>>(istream& istr, Numbers& N);
```
Overload the extraction operator to read the Numbers object using istream.
- read a double value using istr
- if the successful add the double value to N using the += operator
- return istr;

## the tester program 
```C++
/***********************************************************************
// OOP244 Workshop 6 p1: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/10/1
// Author  Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Numbers.h"
using namespace sdds;
using namespace std;
void startTest(int n) {
   cout << "Test";
   for (int i = 0; i < 30; i++) cout << " " << n;
   cout << endl;
}
void endTest(int n) {
   cout << "End Test";
   for (int i = 0; i < 28; i++) cout << " " << n;
   cout << endl;
}

void resetFile(const char* fname) {
   ofstream f(fname);
   f.setf(ios::fixed);
   f.precision(2);
   f << 6.00 << endl << 12.20 << endl << 3.00 << endl << 34.10 << endl;
}
void displayFile(const char* fname) {
   ifstream f(fname);
   char ch;
   cout << endl << "Content of \"" << fname << "\"" << endl
      << "*****************************************************************" << endl;
   while (f.get(ch)) {
      cout << ch;
   }
   cout << "*****************************************************************" << endl;
}
void displayList(Numbers N) {
   cout << "Add a number to the list: ";
   cin >> N;
   cout << N << endl;
}
void test1() {
   startTest(1);
   Numbers N("numbers.txt");
   N += 34.56;
   cout << N << endl;
   displayList(N);
   endTest(1);
}
void test2() {
   startTest(2);
   Numbers N("numbers.txt");
   Numbers M(N);
   Numbers L;
   Numbers BAD("BadFileName.txt");
   cout << N << endl << M << endl << L << endl << BAD <<endl;
   cout << "Ascending:" << endl << +N << endl << "Descending:" << endl << -N << endl;
   M += 1000;
   L = M;
   N = L;
   cout << N << endl << M << endl << L << endl;
   cout << "Ascending:" << endl;
   cout << +N << endl << +M << endl << +L << endl;
   cout << "Descending: "<< endl;
   cout << -N << endl << -M << endl << -L << endl;
   endTest(2);
}
void test3() {
   startTest(3);
   cout << endl << "In this test we use your insertion and extraction operators to do" << endl
      << "File IO. This makes sure your implementation is done correctly" << endl 
      << "using the reference of istream and ostream and NOT cin and cout" << endl << endl;
   ifstream addnum("add.txt");
   ofstream output("output.txt");
   Numbers N("numbers.txt");
   addnum >> N;
   addnum >> N;
   addnum >> N;
   output << N << endl << +N << endl << -N << endl;
   endTest(3);
}
int main() {
   resetFile("numbers.txt");
   test1();
   displayFile("numbers.txt");
   test2();
   displayFile("numbers.txt");
   test3();
   displayFile("numbers.txt");
   displayFile("add.txt");
   displayFile("output.txt");
   return 0;
}
```

## execution sample
The tester program's execution should generate the following output:



```Text

Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
=========================
numbers.txt
6.00, 12.20, 3.00, 34.10, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
Add a number to the list: 123
=========================
*** COPY ***
6.00, 12.20, 3.00, 34.10, 34.56, 123.00
-------------------------
Total of 6 number(s)
Largest number:  123.00
Smallest number: 3.00
Average:         35.48
=========================
End Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Content of "numbers.txt"
*****************************************************************
6.00
12.20
3.00
34.10
34.56
*****************************************************************
Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
=========================
numbers.txt
6.00, 12.20, 3.00, 34.10, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
=========================
*** COPY ***
6.00, 12.20, 3.00, 34.10, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
Empty list
Empty list
Ascending:
=========================
*** COPY ***
3.00, 6.00, 12.20, 34.10, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
Descending:
=========================
*** COPY ***
34.56, 34.10, 12.20, 6.00, 3.00
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
=========================
*** COPY ***
6.00, 12.20, 3.00, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
6.00, 12.20, 3.00, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
6.00, 12.20, 3.00, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
Ascending:
=========================
*** COPY ***
3.00, 6.00, 12.20, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
3.00, 6.00, 12.20, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
3.00, 6.00, 12.20, 34.10, 34.56, 1000.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
Descending:
=========================
*** COPY ***
1000.00, 34.56, 34.10, 12.20, 6.00, 3.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
1000.00, 34.56, 34.10, 12.20, 6.00, 3.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
=========================
*** COPY ***
1000.00, 34.56, 34.10, 12.20, 6.00, 3.00
-------------------------
Total of 6 number(s)
Largest number:  1000.00
Smallest number: 3.00
Average:         181.64
=========================
End Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

Content of "numbers.txt"
*****************************************************************
6.00
12.20
3.00
34.10
34.56
*****************************************************************
Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

In this test we use your insertion and extraction operators to do
File IO. This makes sure your implementation is done correctly
using the reference of istream and ostream and NOT cin and cout

End Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

Content of "numbers.txt"
*****************************************************************
6.00
12.20
3.00
34.10
34.56
-5.00
222.10
333.20
*****************************************************************

Content of "add.txt"
*****************************************************************
-5.00
222.10
333.20
*****************************************************************

Content of "output.txt"
*****************************************************************
=========================
numbers.txt
6.00, 12.20, 3.00, 34.10, 34.56, -5.00, 222.10, 333.20
-------------------------
Total of 8 number(s)
Largest number:  333.20
Smallest number: -5.00
Average:         80.02
=========================
=========================
*** COPY ***
-5.00, 3.00, 6.00, 12.20, 34.10, 34.56, 222.10, 333.20
-------------------------
Total of 8 number(s)
Largest number:  333.20
Smallest number: -5.00
Average:         80.02
=========================
=========================
*** COPY ***
333.20, 222.10, 34.56, 34.10, 12.20, 6.00, 3.00, -5.00
-------------------------
Total of 8 number(s)
Largest number:  333.20
Smallest number: -5.00
Average:         80.02
=========================
*****************************************************************
```

## PART 1 Submission (lab)

### Files to submit:  

```Text
Numbers.cpp
Numbers.h
main.cpp
```

### Data Entry

Enter `123` when prompted.

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%) 


## `Basket` Module

Design and code a class named `Basket` that holds information about a fruit basket. Place your class definition in a header file named `Basket.h` and your function definitions in an implementation file named `Basket.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

Add to this module a custom type called `Fruit`:
```C++
struct Fruit
{
  char m_name[30 + 1]; // the name of the fruit
  double m_qty;        // quantity in kilograms
};
```

### `Basket` Class

Design and code a class named `Basket` that holds information about a fruit basket.


#### `Basket` Private Members

The class should be able to store the following data:

- a dynamically allocated array of objects of type `Fruit`. This is the resource that you must manage.
- the size of the Furits array.
- the price of the basket.

You can add any other private members in the class, as required by your design.



#### `Basket` Public Members

- the default constructor
- a custom constructor that receives as parameters an array of objects of type `Fruit`, the size of the array received in the fist parameter, and the price of the basket (in this order); stores the parameters into the attributes if **all** the parameters are valid (the numbers are greater than 0, and the array is not null).
- the copy constructor (you must do a deep-copy for the resource, and a shallow copy for the other attributes)
- the copy assignment operator (you must do a deep-copy for the resource, and a shallow copy for the other attributes; note that the copy constructor and copy assignment operator have almost identical logic -- reuse the code)
- the destructor
- `void setPrice(double price)`: updates the price attribute to the value received as parameter
- the conversion to `bool` operator: returns `true` if the basket contains any fruits, `false` otherwise.
- an overload of the `+=` operator that receives as a parameter an object of type `Fruit` (by value) and adds it to the dynamic Fruits array (You need to resize the array)


#### Friend Helper Functions

- overload the insertion operator (`operator<<`) to insert into the stream (received as the first parameter) the content of an object of type `Basket` (received as the second parameter).

  If the basket doesn't contain any fruit, print the message `The basket is empty!<ENDL>`.

  If the basket contains fruits, print the content in the format:
  ```txt
  Basket Content:<ENDL>
  [FRUIT_1_NAME]: [FRUIT_1_QUANTITY]kg<ENDL>
  [FRUIT_2_NAME]: [FRUIT_2_QUANTITY]kg<ENDL>
  ...
  Price: [BASKET_PRICE]<ENDL>
  ```
  The fruit names should be printed on fields of size 10, aligned to the right; the fruit quantities and basket price should be printed with **two** significant digits.



### Tester program:
```C++
/***********************************************************************
// OOP244 Workshop 6 p2:  Classes with Resources
//
// File  main.cpp
// Version 2.1
// Author  Nargis Khan
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include<iostream>
#include<cstring>
#include"Basket.h"
#include"Basket.h" //intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title) {
   char oldFill = cout.fill('-');
   cout.width(40);
   cout << "" << endl;

   cout << "|> " << title << endl;

   cout.fill('-');
   cout.width(40);
   cout << "" << endl;
   cout.fill(oldFill);
}

int main() {
   sdds::Fruit fruits[]{
      {"apple",  0.75},
      {"banana", 1.65},
      {"pear",   0.51},
      {"mango",  0.75},
      {"plum",   2.20},
   };

   {
      printHeader("T1: Default Constructor");

      Basket aBasket;
      cout << aBasket;

      // conversion to bool operator
      if(aBasket)
         cout << "Test failed: the basket should be empty!\n";
      else
         cout << "Test succeeded: operator said the basket is empty!\n";

      cout << endl;
   }

   {
      printHeader("T2: Custom Constructor");

      Basket aBasket(fruits, 2, 6.99);
      cout << aBasket;

      // conversion to bool operator
      if(aBasket)
         cout << "Test succeeded: operator said the basket has content!\n";
      else
         cout << "Test failed: the basket should NOT be empty!\n";

      cout << endl;
   }

   {
      printHeader("T3: += operator");

      Basket aBasket;
      aBasket += fruits[2];
      (aBasket += fruits[0]) += fruits[4];
      aBasket.setPrice(12.234);

      cout << aBasket;
      cout << endl;
   }

   {
      printHeader("T4: Copy Constructor");

      Basket b1;
      Basket b2(b1);

      cout << "Basket #1 -> " << b1;
      cout << "Basket #2 -> " << b2;

      b1 += fruits[3];
      b1.setPrice(3.50);

      Basket b3(b1);
      cout << "Basket #3 -> " << b3;
      cout << endl;
   }

   {
      printHeader("T5: Copy Assignment");

      Basket b1, b2, b3(fruits, 5, 19.95);

      b1 = b2;
      cout << "Basket #1 -> " << b1;
      cout << "Basket #2 -> " << b2;

      b1 = b3;
      cout << "Basket #1 -> " << b1;

      b3 = b2;
      cout << "Basket #3 -> " << b3;
   }

   return 0;
}

```

### Data Entry

No data entry is needed


## Execution Sample
```text
----------------------------------------
|> T1: Default Constructor
----------------------------------------
The basket is empty!
Test succeeded: operator said the basket is empty!

----------------------------------------
|> T2: Custom Constructor
----------------------------------------
Basket Content:
     apple: 0.75kg
    banana: 1.65kg
Price: 6.99
Test succeeded: operator said the basket has content!

----------------------------------------
|> T3: += operator
----------------------------------------
Basket Content:
      pear: 0.51kg
     apple: 0.75kg
      plum: 2.20kg
Price: 12.23

----------------------------------------
|> T4: Copy Constructor
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #3 -> Basket Content:
     mango: 0.75kg
Price: 3.50

----------------------------------------
|> T5: Copy Assignment
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #1 -> Basket Content:
     apple: 0.75kg
    banana: 1.65kg
      pear: 0.51kg
     mango: 0.75kg
      plum: 2.20kg
Price: 19.95
Basket #3 -> The basket is empty!

```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
Item.cpp
Item.h
main.cpp
```

### Data Entry

No data entry needed

## Submission Process:

Upload your the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

