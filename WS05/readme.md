# Workshop #05: Member operators and Helper functions
* Version 1.1 (synced tester source with the main.cpp [p1] in the repo)
* Version 1.2-lab (Corrected the execution sample to the one on matix)<br />
in (**<< operator** and **>> operator**) requirements, the instruction for apartment number being set to zero is removed.


In this workshop, you will implement different types of operator overload in partially developed classes.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create binary member operator
- define and create a type conversion operator
- define and create a unary operator
- define and create helper binary operator between classes
- define and create a helper operator between a primitive type and a class.

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

> Because of the Thanksgiving holiday the due dates of workshops 5 and 6 will shift to two days later.

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

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# Part 1 - LAB (50%)

Your task for this part of the workshop is to complete the implementation of the Apartment module which has the apartment number and the rent.

# The Apartment Class
 There are two attributes within the Apartment class: an integer holding the apartment number (m_number) and a double holding the rent for the apartment class (m_balance)

The apartment class can be:

- In an Invalid Empty State: an Apartment can be set to this state by assigning the Apartment object to an invalid int (or through the different constructors' logic). In such situations, the Apartment number is set to -1 and the rent is set to 0. The object in this case is rendered inactive and cannot be used anymore.
- In a Valid State: an apartment is considered valid if the apartment number is a 4 digit integer with a zero or positive rent balance.

# Already implemented:
### Constructor
Two argument constructor (integer, double) 
```C++
  Apartment(int number, double balance);
```
The two-argument constructor sets the apartment number and balance to the incoming arguments only if both values are valid. If an invalid apartment number or a negative rent balance is passed to the constructor, the object will be set to an invalid empty state.
### display function
```C++
   ostream& display() const 
```
Displays the apartment information.
## To be implemented:
### type conversion operators
- **operator bool**<br />
This operator returns **true** if the **apartment object** is  **valid**; otherwise, it will return **false**.  This operator cannot modify the **apartment** object.
- **operator int**<br />
returns the **apartment number**. This operator cannot modify the **apartment** object.
- **operator double**<br />
returns the **rent balance value**. This operator cannot modify the **apartment** object.

### Unary member operator
- **bool operator ~()**<br />
returns **true** if the apartment balance is **zero**; otherwise, it returns **false**. This operator cannot modify the **apartment** object.
> Note: Balance is considered to be zero if it has a value less than `0.00001`

### Binary member operators
> Note: All of the binary member operators **will not take any action** if the **apartment**  is **invalid**; the only exception to this is when you are assigning one Apartment object to another Apartment object.

#### assignment operators
- overload the **assignment operator** so an **apartment** can be set to an **integer**. Doing so should set the **apartment number** of the **apartment** to the **integer value**. <br />
If the **integer value** is an invalid apartment number, the object should be set to an **invalid empty state** instead. <br />
In any case, a reference of the **current object** (**apartment**) should be returned. 
```C++
Apartment A,B; 
   A = 1111;  // the Apartment number of A will be set to 1111
   B = 22222; // the Apartment B will be set to invalid state
```
- overload the **assignment operator** so an **apartment** can be set to another **apartment** object. This action should **swap** the rent balance and the apartment number of one apartment to another. Therefore, unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the rent balance and the number of the left apartment will be swapped with the balance and the number of the right apartment<br />
In any case, a reference of the **current object** (**apartment**) should be returned. 
```C++
   Apartment A, B(6666, 400);
   A = B;  // A will have the properties of B.
```
- overload the **+= operator** to add a double value to an apartment. This should act like adding to the balance of the rent of an apartment. (i.e., the value of the double should be added to the rent balance)<br />
if the apartment is invalid or the double value is negative, no action should be taken.<br />
In any case, a reference of the **current object** (**apartment**) should be returned. 
```C++
Apartment A(5555, 400.0), Invalid(55555, -10);
   A += 200.0;  // A will have a balance of 600 
   Invalid += 300.0; // Nothing will happen since it is invalid
   A += -20.0; // Nothing will happen since the double value added is negative
```
- overload the **-= operator** to reduce an apartment rent balance by a double value. This should act like decreasing the rent balance of an apartment account. (i.e., the value of the balance should be reduced by the double value)<br />
if the apartment is in an invalid state, the double value is negative, or there is not enough money in the apartment account - no action should be taken.<br />
In any case, a reference of the **current object** (**apartment**) should be returned. 
```C++
Apartment A(5555, 400.0), Invalid(55555, -10);
   A -= 150.0;  // A will have a balance of 250 
   A -= 300.0; // Nothing will happen since there is not enough money in A after the line above
   A -= -20.0; // Nothing will happen since double value is negative
   Invalid -= 20.0 // Nothing will happen since apartment is invalid
```

- overload the **<< operator** (left shift operator) to move the balance from the right apartment to the left apartment. After this operation, the balance of the left apartment account will be the sum of both the left and right apartment, and the balance of the right apartment account will be zero. <br />
The balance of an apartment should not be able to be "moved" to itself and this operation will not affect the account in this situation.<br />
In any case, a reference of the **current object** (**apartment**) should be returned. 
```C++
Apartment A(5555, 400.0),B(6666, 500.0), Invalid(55555, -10);
   A << B;  // A will have a balance of 900.0, B will have a balance of zero
   A << A; // Nothing will happen 
   A << Invalid; // Nothing will happen
   Invalid << A; // Nothing will happen
```

- overload the **>> operator** (right shift operator) to move the balance from the left apartment to the right apartment. After this operation, the balance of the right apartment account will be the sum of both the right and left apartment and the balance of the left apartment account will be zero. <br />
Funds of an Apartment should not be able to be moved to itself and this operation does not affect the Apartment.<br />
In any case, a reference of the **current object** (**Apartment**) should be returned. 
```C++
Apartment A(5555, 400.0),B(6666, 500.0), Bad(55555, -10);
   A >> B;  // B will have a balance of 900.0, A will have a balance of zero
   B >> B; // Nothing will happen 
   B >> Invalid; // Nothing will happen
   Invalid >> B; // Nothing will happen
```

### Binary helper operators

- create a binary stand-alone helper **+ operator** that accepts a **constant apartment reference** on the left and another **constant apartment reference** on the right that returns a **double** value. <br />
The **double** value should be the **sum** of the **balances** of the two apartments accounts.<br />
If any of the two apartments is **invalid**, then **zero** is returned.<br />
```C++
   Apartment A(5555, 400.0), B(6666, 600.0), Invalid(55555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Invalid; // sum should be 0 since apartment is invalid
   sum = Invalid + B; // sum should be 0 since apartment is invalid
```
- create a binary stand-alone helper **+= operator** that accepts a **double reference** on the left and a **constant apartment reference** on the right that returns a **double** value. <br />
The value of the rent balance of the right operand (apartment reference) should be added to the left operand and then the sum will be returned.

```C++
   Apartment A(5555, 400.0), B(6666, 600.0), Bad(55555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0
```
## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 5 p1: tester program
//
// File  main.cpp
// Version 1.1
// Date  summer of 2022
// Author  Kalimullah Jawad
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2022/10/06      peer review
// Fardad          2022/10/16      synced with the main.cpp in repo
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Apartment.h"
using namespace std;
using namespace sdds;

void aprtmentsDisplay(const Apartment* apt, int num);
void aprtmentDisplay(const Apartment& apt);
void allApartmentsDisplay(const Apartment* apt, int num);
void balancesDisplay(const Apartment* apt, int num);
int emptyApartments(const Apartment* apt, int num);

int main() {
    double value;
    Apartment mixed[] = {
       {1111, 112.11},
       {2222, 223.22},
       {33333, 334.333}, // invalid
       {4444, 4435.44},
       {55555, 544.55},  // invalid
       {66666, 666.66},   // invalid
       {7777, 788.77}
    };
    cout << "Using bool conversion overload and operator ~ to print the apartments " << endl;
    aprtmentsDisplay(mixed, 7);
    cout << "Charging apartment #1 $50.02 using += operator:" << endl;
    aprtmentDisplay(mixed[0] += 50.02);
    cout << "Deducting $100.01 from apartment #2 using -= operator:" << endl;
    aprtmentDisplay(mixed[1] -= 100.01);
    cout << "Deducting $5555.55 from apartment #4 using -= operator (fail):" << endl;
    aprtmentDisplay(mixed[3] -= 5555.55);
    cout << "Adding and deducting negative amounts on apartment #4 (fail):" << endl;
    aprtmentDisplay(mixed[3] -= -5.55);
    aprtmentDisplay(mixed[3] += -50.55);
    cout << "Displaying first two departments: " << endl;
    aprtmentsDisplay(mixed, 2);
    cout << "Moving the balance of apartment 1 to 2:" << endl;
    mixed[0] >> mixed[1];
    aprtmentsDisplay(mixed, 2);
    cout << "Moving the balance of apartment 2 to 1:" << endl;
    mixed[0] << mixed[1];
    aprtmentsDisplay(mixed, 2);
    cout << "Attempting to move the balance an apartment to itself (fail):" << endl;
    aprtmentDisplay(mixed[0] << mixed[0]);
    cout << "Combined balance of apartment 4 and 7 in three different ways:" <<endl;
    // 1
    cout << (value = mixed[3] + mixed[6]) << ", ";
    // 2
    value = 0;
    value += mixed[3];
    value += mixed[6];
    // 3
    cout << value << ", and ";
    value = double(mixed[3]);
    value += double(mixed[6]);
    cout << value << endl;
    cout << "Moving apartments from #1 to #2 using operator=:" << endl;
    cout << "Before: " << endl;
    aprtmentsDisplay(mixed, 2);
    mixed[1] = mixed[0];
    cout << "After: " << endl;
    aprtmentsDisplay(mixed, 2);
    cout << "Displaying all apartments: " << endl;
    aprtmentsDisplay(mixed, 7);
    cout << "Changing number of apartment #7:" << endl;
    aprtmentDisplay(mixed[6] = 12121);
    allApartmentsDisplay(mixed, 7);
    balancesDisplay(mixed, 7);
    cout << "Total of " << emptyApartments(mixed, 7) << " empty apartment(s)" << endl;
    return 0;
}

void aprtmentsDisplay(const Apartment* apt, int num) {
   cout << "+-----+------+--------------+" << endl;
   cout << "|ROW# | APT# |    BALANCE   |" << endl;
   cout << "+-----+------+--------------+" << endl;
   for(int i = 0; i < num; i++) {
      cout << "| ";
      cout.width(3);
      cout.fill('0');
      cout << (i + 1) << " | ";
      cout.fill(' ');
      apt[i].display() << "|" << endl;
   }
   cout << "+-----+------+--------------+" << endl;
}
void aprtmentDisplay(const Apartment& apt) {
   aprtmentsDisplay(&apt, 1);
}
void allApartmentsDisplay(const Apartment* apt, int num) {
   cout << "Display numbers of all the apartments " << endl;
   cout << " int conversion operator should be implemented" << endl;
   for(int i = 0; i < num; i++) {
      cout << int(apt[i]) << " ";
   }
   cout << endl;
}
void balancesDisplay(const Apartment* apt, int num) {
   cout << "Display total income balance: " << endl;
   cout << " double conversion operator should be used" << endl;
   for(int i = 0; i < num; i++) {
      cout << double(apt[i]) << " ";
   }
   cout << endl;
}

int emptyApartments(const Apartment* apt, int num) {
   int sum = 0;
   for(int i = 0; i < num; i++) {
      sum += apt[i] && ~apt[i]; 
   }
   return sum;
}
```

## Execution sample

The tester program tests all the operator overloads and the output should be as follows:
```Text
Using bool conversion overload and operator ~ to print the apartments 
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       112.11 |
| 002 | 2222 |       223.22 |
| 003 | Invld|  Apartment   |
| 004 | 4444 |      4435.44 |
| 005 | Invld|  Apartment   |
| 006 | Invld|  Apartment   |
| 007 | 7777 |       788.77 |
+-----+------+--------------+
Charging apartment #1 $50.02 using += operator:
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       162.13 |
+-----+------+--------------+
Deducting $100.01 from apartment #2 using -= operator:
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 2222 |       123.21 |
+-----+------+--------------+
Deducting $5555.55 from apartment #4 using -= operator (fail):
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 4444 |      4435.44 |
+-----+------+--------------+
Adding and deducting negative amounts on apartment #4 (fail):
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 4444 |      4435.44 |
+-----+------+--------------+
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 4444 |      4435.44 |
+-----+------+--------------+
Displaying first two departments: 
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       162.13 |
| 002 | 2222 |       123.21 |
+-----+------+--------------+
Moving the balance of apartment 1 to 2:
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |         0.00 |
| 002 | 2222 |       285.34 |
+-----+------+--------------+
Moving the balance of apartment 2 to 1:
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       285.34 |
| 002 | 2222 |         0.00 |
+-----+------+--------------+
Attempting to move the balance an apartment to itself (fail):
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       285.34 |
+-----+------+--------------+
Combined balance of apartment 4 and 7 in three different ways:
5224.21, 5224.21, and 5224.21
Moving apartments from #1 to #2 using operator=:
Before: 
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 1111 |       285.34 |
| 002 | 2222 |         0.00 |
+-----+------+--------------+
After: 
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 2222 |         0.00 |
| 002 | 1111 |       285.34 |
+-----+------+--------------+
Displaying all apartments: 
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | 2222 |         0.00 |
| 002 | 1111 |       285.34 |
| 003 | Invld|  Apartment   |
| 004 | 4444 |      4435.44 |
| 005 | Invld|  Apartment   |
| 006 | Invld|  Apartment   |
| 007 | 7777 |       788.77 |
+-----+------+--------------+
Changing number of apartment #7:
+-----+------+--------------+
|ROW# | APT# |    BALANCE   |
+-----+------+--------------+
| 001 | Invld|  Apartment   |
+-----+------+--------------+
Display numbers of all the apartments 
 int conversion operator should be implemented
2222 1111 -1 4444 -1 -1 -1 
Display total income balance: 
 double conversion operator should be used
0.00 285.34 0.00 4435.44 0.00 0.00 0.00 
Total of 1 empty apartment(s)

```
## PART 1 Submission

### Files to submit:  

```Text
Apartment.cpp
Apartment.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e., functions, classes etc.) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No data entry

### Submission Process:

Upload the files listed above to your `matrix` Apartment. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your Apartment
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%) 

> Note that you can (and probably should) add additional methods to make the DIY part work. <br/ >Also, when developing the operator overloads, remember that many operator overloads can reuse the other operators by calling them. For example "less than" is the same as "not greater than or equal" 

Create a C++ Module for a class called **Mark** to encapsulate a mark between **0** and **100**.

| Mark              | Grade | Scale 4 mark |
|-------------------|-------|--------------|
| `0 <= Mark < 50`    | F     | 0.0          |
| `50 <= Mark < 60`   | D     | 1.0          |
| `60 <= Mark < 70`   | C     | 2.0          |
| `70 <= Mark < 80`   | B     | 3.0          |
| `80 <= Mark <= 100` | A     | 4.0          |



> **:warning:Important:** No values are allowed to be kept in a mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This rule is to be followed during the workshop and applies to all the functions and operators of class **Mark**

## Construction
A Mark object can be created using an integer value (one argument constructor)that sets the value of the mark. If this value is not provided (no argument constructor), the value of the mark will be zero.
```C++
   Mark m, n(25), k(200), p(-10);
   // value of m is 0
   // value of n is 25
   // k is invalid
   // p is invalid
```


## Type conversion Operators:

- A Mark object can be casted to an integer (int type); the result would be the value of the mark or zero if the mark is in an invalid state.
```C++
  Mark m, n(25), k(200), p(-10);
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
```
**Ouptut:** 
```Text
0
25
0
0
```


- A Mark object can be casted to a double; the result would be the GPA equivalent of the integer value. See the table of mark values above. Casting an invalid mark will result in a zero value.
```C++
   Mark m(50), n(80), k(120);
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
```
**Output:** 
```Text
1
4
0
```
- A Mark object can be casted to a character (char type); the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result in an 'X' value.
```C++
   Mark m(50), n(80), k(120);
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
```
**Output:** 
```Text
D
A
X
```
- A Mark can be casted to a boolean (bool type); the result would be if the mark in a valid state(true) or not (false).

```C++
   Mark n(80), k(120);
   cout << bool(n) << endl;
   cout << bool(k) << endl;
```
**Output:** 
```Text
1
0
```
## Comparison operator overloads
- A Mark can be compared with other Marks using ```==, !=, <, >, <=``` and ```>=``` returning a boolean in result. <br />Comparison results involving invalid marks are undefined 
```C++
   Mark m(40), n(80);
   cout << (m > n) << endl;
   cout << (m < n) << endl;
   cout << (m >= n) << endl;
   cout << (m <= n) << endl;
   cout << (m == m) << endl;
   cout << (m != n) << endl;
```
**Output:**
```text
0
1
0
1
1
1
```

## Unary operators:
- The ```++ and --``` operators (postfix and prefix) work with a mark exactly as they do with an integer, except that they don't take any action if the mark is invalid.
```C++
  Mark m, n(25), k(200);
   cout << int(++m) << endl;
   cout << int(--n) << endl;
   cout << int(n--) << endl;
   cout << int(m++) << endl;
   cout << int(n) << endl;
   cout << int(m) << endl;
   
```
**Ouptut:** 
```Text
1
24
24
1
23
2
```

- ```~``` operator returns true if the mark is a pass. 

```C++
   Mark m(40), n(80), k(120);
   cout << ~m << endl;
   cout << ~n << endl;
   cout << ~k << endl;
```
**Output:** 
```Text
0
1
0
```

## Binary Operators
- A Mark object can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment. 
```C++
  Mark m, n(25), k(200);
  cout << int(m = 80) << endl;
  cout << int(n = 120) << endl;
  cout << int(k = 70) << endl;
  cout << int(n = m = 90) << endl;
```
**Output:** 
```Text
80
0
70
90
```

- An integer can be added to the value or deducted from the value of the mark using += and -= operator; if the mark is invalid, the action is omitted. A reference of the mark is returned after the operation.
```C++
  Mark m, n(25), k(200);
  cout << int(m += 20) << endl;
  cout << int(n += 20) << endl;
  cout << int(k += 20) << endl;
  cout << int(n += 60) << endl;
  cout << int(m -= 10) << endl;
  cout << int(m -= 20) << endl;
```
**Output:** 
```Text
20
45
0
0
10
0
```

- A mark's value can be added to an integer or deducted from an integer, returning the integer after the operation. Invalid marks will not have any effect on the value of the integer.
```C++
   int val = 60;
   Mark n(80), k(120);
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   cout << (val -= n) << endl;
   cout << (val -= k) << endl;
```
**Output:** 
```Text
140
140
60
60
```
- The sum of a Mark and an integer or another Mark will return a Mark with the sum of the two values as a result. 

```C++
   int val = 15;
   Mark m(10), n(80);
   cout << int(n + val) << endl;
   cout << int(m + n ) <<  endl;
   cout << int(m + n + val) << endl;
```
**Output:** 
```Text
95
90
0
```

- `<<` and `>>` operators move and add the mark value from one mark (source) to another (destination) leaving the source as zero.
```C++
   int val = 15;
   Mark m(70), n(80), p(20);
   m << p;
   cout << int(m) << endl;
   cout << int(p) << endl;
   m >> p;
   cout << int(m) << endl;
   cout << int(p) << endl;
   p << n;
   cout << int(p) << endl;
```
**Output:** 
```Text
90
0
0
90
0
```

 
##Tester program:
```C++
/***********************************************************************
// OOP244 Workshop 5 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/10/10
// Author  Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "Mark.h"
using namespace std;
using namespace sdds;

ostream& prn(const Mark& m, int mode = 0, ostream& ostr = cout);
ostream& operator<<(ostream& ostr, const Mark& M);
void testComparison(const Mark& L, const Mark& E, const Mark& H);
void unaryOpTest();
void constructorAndConversion();
void binaryTest(const Mark& I);
int main() {
   Mark L = 49, E = 50, H = 51, I = 20;
   constructorAndConversion();
   testComparison(L, E, H);
   unaryOpTest();
   binaryTest(I);
   return 0;
}

void testComparison(const Mark& L, const Mark& E, const Mark& H) {
   cout << "Testing Comparision!" << endl;

   cout << L << "  < " << E << ": " << (L < E ? "T" : "F") << endl;
   cout << L << "  > " << E << ": " << (L > E ? "T" : "F") << endl;
   cout << L << " <= " << E << ": " << (L <= E ? "T" : "F") << endl;
   cout << L << " >= " << E << ": " << (L >= E ? "T" : "F") << endl;
   cout << L << " == " << E << ": " << (L == E ? "T" : "F") << endl;
   cout << L << " != " << E << ": " << (L != E ? "T" : "F") << endl;
   cout << "----------------" << endl;

   cout << E << "  < " << E << ": " << (E < E ? "T" : "F") << endl;
   cout << E << "  > " << E << ": " << (E > E ? "T" : "F") << endl;
   cout << E << " <= " << E << ": " << (E <= E ? "T" : "F") << endl;
   cout << E << " >= " << E << ": " << (E >= E ? "T" : "F") << endl;
   cout << E << " == " << E << ": " << (E == E ? "T" : "F") << endl;
   cout << E << " != " << E << ": " << (E != E ? "T" : "F") << endl;
   cout << "----------------" << endl;

   cout << E << "  < " << H << ": " << (E < H ? "T" : "F") << endl;
   cout << E << "  > " << H << ": " << (E > H ? "T" : "F") << endl;
   cout << E << " <= " << H << ": " << (E <= H ? "T" : "F") << endl;
   cout << E << " >= " << H << ": " << (E >= H ? "T" : "F") << endl;
   cout << E << " == " << H << ": " << (E == H ? "T" : "F") << endl;
   cout << E << " != " << H << ": " << (E != H ? "T" : "F") << endl;
   cout << "----------------" << endl;
}
void unaryOpTest() {
   Mark m, n(51), p(100), R;
   cout << "Testing Unary operators!" << endl;
   cout << "m: " << m << endl;
   R = m--;
   cout << "R = m--, R: " << R << ", m: " << m << endl;
   R = --m;
   cout << "R = --m, R: " << R << ", m: " << m << endl;
   R = m++;
   cout << "R = m++, R: " << R << ", m: " << m << endl;
   R = ++m;
   cout << "R = ++m, R: " << R << ", m: " << m << endl;
   cout << "-----------------------------------------" << endl;
   cout << "n: " << n << endl;
   R = --n;
   cout << "R = --n, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = n--;
   cout << "R = n--, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = ++n;
   cout << "R = ++n, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = n++;
   cout << "R = n++, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   cout << "-----------------------------------------" << endl;
   cout << "p: " << p << endl;
   R = p++;
   cout << "R = p++, R: " << R << ", p: " << p << endl;
   R = ++p;
   cout << "R = ++p, R: " << R << ", p: " << p << endl;
   R = p--;
   cout << "R = p--, R: " << R << ", p: " << p << endl;
   R = --p;
   cout << "R = --p, R: " << R << ", p: " << p << endl;
}
void constructorAndConversion() {
   Mark m, n(30), k(75), p(300);
   cout << "Constructors and" << endl;
   cout << "and conversion" << endl;
   prn(m) << ", ";
   prn(n, 1) << ", ";
   prn(k, 2) << ", ";
   prn(p) << endl;

}
void binaryTest(const Mark& C) {
   Mark m, n = 90;
   cout << "Testing Member Binaries!" << endl;
   cout << "m: " << m << endl;
   cout << "m = 75, m: " << (m = 75) << endl;
   cout << "m = -1, m: " << (m = -1) << endl;
   cout << "m = 100, m: " << (m = 100) << endl;
   cout << "m = 101, m: " << (m = 101) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "m += 65: " << (m += 65) << endl;
   cout << "m -= 10: " << (m -= 10) << endl;
   cout << "m = 10: " << (m = 10) << endl;
   cout << "m += 65: " << (m += 65) << endl;
   cout << "m -= 55: " << (m -= 10) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "m = 5" << endl;
   m = 5;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "m << n: " << (m << n) << endl;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "m >> n: " << (m >> n) << endl;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "-----------------------------------------" << endl;
   cout << "C: " << C << endl;
   cout << "C + 30: " << (C + 30) << endl;
   cout << "C + -90: " << (C + -90) << endl;
   cout << "C + 100: " << (C + 100) << endl;
   cout << "C + C: " << (C + C) << endl;
   cout << "n = 90" << endl;
   n = 90;
   cout << "n: " << n << endl;
   cout << "C + n: " << (C + n) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "Testing Helper Binaries!" << endl;
   int v = 50;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v += C: " << (v += C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v -= C: " << (v -= C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v + C: " << (v + C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
}
ostream& prn(const Mark& m, int mode, ostream& ostr) {
   ostr << "[";
   if(bool(m)) {
      if(mode == 1) {
         ostr << char(m);
      } else if(mode == 2) {
         ostr << fixed << setprecision(1) << setw(3) << double(m);
      } else {
         ostr << setw(3) << right << int(m);
      }
   } else {
      ostr << "Invalid!";
   }
   return ostr << "]";
}
ostream& operator<<(ostream& ostr, const Mark& M) {
   return prn(M, 0, ostr);
}

 
```
Here is the execution sample for the tester program
```Text
Constructors and
and conversion
[  0], [F], [3.0], [Invalid!]
Testing Comparision!
[ 49]  < [ 50]: T
[ 49]  > [ 50]: F
[ 49] <= [ 50]: T
[ 49] >= [ 50]: F
[ 49] == [ 50]: F
[ 49] != [ 50]: T
----------------
[ 50]  < [ 50]: F
[ 50]  > [ 50]: F
[ 50] <= [ 50]: T
[ 50] >= [ 50]: T
[ 50] == [ 50]: T
[ 50] != [ 50]: F
----------------
[ 50]  < [ 51]: T
[ 50]  > [ 51]: F
[ 50] <= [ 51]: T
[ 50] >= [ 51]: F
[ 50] == [ 51]: F
[ 50] != [ 51]: T
----------------
Testing Unary operators!
m: [  0]
R = m--, R: [  0], m: [Invalid!]
R = --m, R: [Invalid!], m: [Invalid!]
R = m++, R: [Invalid!], m: [Invalid!]
R = ++m, R: [Invalid!], m: [Invalid!]
-----------------------------------------
n: [ 51]
R = --n, R: [ 50], n: [ 50] Passed!
R = n--, R: [ 50], n: [ 49] Failed!
R = ++n, R: [ 50], n: [ 50] Passed!
R = n++, R: [ 50], n: [ 51] Passed!
-----------------------------------------
p: [100]
R = p++, R: [100], p: [Invalid!]
R = ++p, R: [Invalid!], p: [Invalid!]
R = p--, R: [Invalid!], p: [Invalid!]
R = --p, R: [Invalid!], p: [Invalid!]
Testing Member Binaries!
m: [  0]
m = 75, m: [ 75]
m = -1, m: [Invalid!]
m = 100, m: [100]
m = 101, m: [Invalid!]
-----------------------------------------
m += 65: [Invalid!]
m -= 10: [Invalid!]
m = 10: [ 10]
m += 65: [ 75]
m -= 55: [ 65]
-----------------------------------------
m = 5
m: [  5], n: [ 90]
m << n: [ 95]
m: [ 95], n: [  0]
m >> n: [  0]
m: [  0], n: [ 95]
-----------------------------------------
C: [ 20]
C + 30: [ 50]
C + -90: [Invalid!]
C + 100: [Invalid!]
C + C: [ 40]
n = 90
n: [ 90]
C + n: [Invalid!]
-----------------------------------------
Testing Helper Binaries!
v: 50, C: [ 20]
v += C: 70
v: 70, C: [ 20]
v -= C: 50
v: 50, C: [ 20]
v + C: 70
v: 50, C: [ 20]

```

> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.


## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:

```Text
Mark.h
Mark.cpp
main.cpp

```

### Data Entry

??? explain what data  will be used for submission and testing

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

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

