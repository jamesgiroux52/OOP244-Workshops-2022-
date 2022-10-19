# Workshop #4: Constructors, Destructors and Current object
* Version 1.0
* Version 1.1, corrections during the overview session
* Version 1.2, Corrected the name TourPassenger to TourTicket.

## Workshop Online Overview Session. (Monday Oct 03 8:55 - 9:45)
The overview session will go through the workshop, explaining the steps and answering questions you might have.

The session will be online on BigBlueButton. Click on the link below 5 minutes before the session begins to join the session. 

### No listen only connections please
Make sure your microphone is set up and join with the microphone. This is an interactive session, avoid "Listen only" connections unless you REALLY have to.
[Click HERE to join the session](https://connect.rna2.blindsidenetworks.com/invite/to?c=rPAbrdZK-4K0uMDK88CBO93C86ec2X4t0eSfUSK5I18&m=df35c27d0f1972926dfb207f1c195b8402c73621&t=1664801551840&u=senecacollege)
### Overview session recordings
[Click here to view the recording](https://youtu.be/wSwbSvu31_M)

## Learning Outcomes

In this workshop, you will use Constructors,  Destructor and references of the current object to encapsulate a passenger seat in a Boeing 737.


Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor
- define a custom constructor with a different number of arguments
- define a Destructor to prevent a memory leak.
- use reference of the current object
- describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

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


Your task for this part of the workshop is to encapsulate the passenger name, seat number and letter on a Boeing 737 passenger airplane in a class called Seat. (**Seat.h** and **Seat.cpp**)

This class will be used by another programmer for booking applications.

Study the seat plan below and understand the way seats are placed and numbered:
![Boeing 737 Seat plan](images/737.png)

- valid row numbers: 1 to 4; Business class, 7 to 15; Economy plus and 20 to 38; Economy
- Valid letters: 1 to 4, ABEF, 7 to 38, ABCDEF

## Seat Class (Module)
Design a **Seat** class with the following specifications:

### Attributes
- a character pointer to hold the passenger name Dynamically as a Cstring
- an integer to keep the seat row number
- a character to hold the letter of the seat. 

Example:  
```text
Roger Waters, 14A
```
### Private methods
```C++
bool validate(int row, char letter)const;
```
Code a private method to return true if the row number and the seating letter, together correctly address a seat in the airplane.
Validations:
- row numbers 1 to 4, 7 to 15 and 20 to 38 are considered valid seat values.
- for rows 1 to 4, letters A, B, E and F are acceptable values.
- for the rest, the acceptable values are A, B, C, D, E and F.

If the row number and letter fall into the above pattern return true, otherwise, return false.

This method is a query, hence it does not modify the current object.

```C++
Seat& alAndCp(const char* str);
```
Since on many occasions you need to allocate memory for passenger name and copy the value into the allocated memory, it is better to create a private method to modularize this action.
- before validating the str argument to be a valid Cstring set the passenger name pointer attribute to nullptr so the passenger name pointer will be set to nullptr if allocation fails.
  - then validate the str argument. If it is not null and not empty, then allocate memory to the length of the str argument (plus one for null) and keep the address in the passenger pointer attribute.
  - copy the content of the str Cstring into the newly allocated memory.
- return the reference of the current object in case it is needed in the caller function.

> Note that since this function does not deallocate the passenger name before allocation, you need to do it before calling the function.

### Public functions and Construction and destruction.

### Safe Empty state and Seating
```C++
Seat& reset();
```
This function resets the object into a safe empty state as follows:
 - deallocates the passenger name
 - sets passenger name to nullptr
 - sets row and letter to zero
 
Then it will return the reference of the current object for possible future use.
```C++
bool isEmpty() const;
```
This query returns if the object is in an empty state by returning true if the passenger name pointer attribute is nullptr and false otherwise.
 
```C++
bool Seat::assigned() const;
```
This query returns true if the seats are assigned and valid by returning the validate method call result.


### Constructors and destructor
The Seat class can be instantiated in three different ways:

### 1- No argument constructor
```C++
Seat();
```
sets the object to the safe empty state as in reset method. 
> If you are using the reset method here, make sure to set the passenger pointer attribute to nullptr before calling the reset().
 
### 2- One argument constructor
```C++
Seat(const char* passengerName);
```
If passengerName argument is a valid and non-empty Cstring, this constructor will allocate memory for passenger name in the passenger name pointer attribute and then copies the content of the passenger name argument into the newly allocated memory.  See alAndCp() function!

Then sets the seat row and letter to zero.

### 3- Three argument constructor

```C++
Seat(const char* passengerName, int row, char letter);
```
Works exactly like the one argument constructor but instead of setting setting row and letter to zero, it will set them to the corresponding values after validating them. If values are not valid, it will set ONLY the row and letter to zero. see the set() method!

### Destructor
```C++
~Seat()
```
Deallocates the memory pointed by the passenger name pointer attribute.
 
## Modifier and Query Methods

```C++
Seat& set(int row, char letter);
```
The set function will validate the row and letter, if they are valid the corresponding attributes will be set to these argument values. If not, the attributes will be set to zero.

At the end set will return the address of the current object.
 
```C++
int row()const;
```
Returns the row attribute value.
```C++
char letter()const;
```
Returns the letter attribute value.
```C++
const char* passenger()const;
```
Returns the value of the passenger name pointer attribute.

## Input/Output

```C++
std::ostream& display(std::ostream& coutRef = std::cout)const
```
Receives the reference of the cout object by default and using the reference instead of cout, prints the passenger and seat information as follows.
> Although it seems strange to use the reference of cout instead of cout itself, however, later in the semester we will learn that by doing this, you can modify the behaviour of the display function base on the type of ostream object. For now, follow the instructions and implement the function as is, and then when the time comes later during the semester, the reason will become clear.


`Passenger Name.......................... 17A`
- Inserts the passenger name into the ostream in width of 40 characters, left justified and filled the spaces with dots ('.').
- Inserts a space
- Inserts the seating number
- Inserts the seating letter
  
> If the passenger name is longer than 40 character only the first 40 characters will be inserted. (To acoomplish this you can use a local 40+1 character cstring and copy the passenger name into it and print the local cstring instead.)
  
If the seat number is invalid (zero), then it will insert three underlines ("___") instead:

`Passenger Name.......................... ___`

If the Seat object is in an empty state it will only print:  

`Invalid Seat!`

At the end return the reference of the ostream;

```C++
std::istream& read(std::istream& cinRef = std::cin);
```
First reset the object to the empty state.

Then Extract the 3 values in three local function scope variables:
- a character Cstring with a length of 70+1 (assuming a name can not be more than 70 chars)
- an integer for row
- a character for the seating letter.

in the following format:

- Name   (use getline())
- comma
- seat number (use extraction operator)
- seat letter (use extraction operator)

After extracting all three from the istream reference argument, check and see if the istream NOT failed. 
If it did not, allocate memory and copy the name into the passenger name pointer attribute (alAndCp()).
If it didn't fail to allocate and copy, then set the values of row and letter attributes using the set() function.

At the end return the reference of the istream;


## Tester Program
```C++  
/***********************************************************************
// OOP244 Workshop 4 p1: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/09/27
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Seat.h"
using namespace std;
using namespace sdds;
void testSeatClass();
void displayPassenger(const Seat& S, int row);
void listSeatBookings();
int main() {
   testSeatClass();
   listSeatBookings();
   return 0;
}
void testSeatClass() {
   cout << "Testing Seat class Functionalities..." << endl;
   Seat A;
   A.display(cout << "       Should be Invalid: ") << endl;
   Seat B = "Darth Vader";
   B.display(cout << "       Seat not assigned: ") << endl;
   Seat C("Luke Skywalker", 7, 'B');
   C.display(cout << "           Assigned Seat: ") << endl;
   B.set(7, 'A');
   B.display(cout << "Darth`s seat is assigned: ") << endl;
   Seat D(nullptr, 12, 'C');
   D.display(cout << "   nullptr name; Invalid: ") << endl;
   Seat E("", 12, 'C');
   E.display(cout << "     Empty name; Invalid: ") << endl;
   Seat F("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.", 2, 'A');
   F.display(cout << "        A very long name: ") << endl;
   B.set(-1, 'A').display(cout << "          bad row number: ") << endl;
   B.set(5, 'A').display(cout << "          bad row number: ") << endl;
   B.set(6, 'A').display(cout << "          bad row number: ") << endl;
   B.set(16, 'A').display(cout << "          bad row number: ") << endl;
   B.set(19, 'A').display(cout << "          bad row number: ") << endl;
   B.set(39, 'A').display(cout << "          bad row number: ") << endl;
   B.set(1, 'C').display(cout << "         bad seat letter: ") << endl;
   B.set(1, 'D').display(cout << "         bad seat letter: ") << endl;
   B.set(12, 'G').display(cout << "         bad seat letter: ") << endl;
   C.display(cout << "  Luke's individual info: ") << endl;
   cout << "Name: " << C.passenger() << endl
      << "Row: " << C.row() << endl
      << "letter: " << C.letter() << endl;
   C.reset().display(cout << "       Seat gone (reset): ") << endl;
   cout << " Give the seat to luke's sister; enter following information:" << endl
      << "Leia Organa,12B<ENTER>" << endl;
   C.read();
   cout << "you entered: " << endl;
   C.display(cout << "             Leia's seat: ") << endl;
   cout << "========================================================================" << endl;
}
void displayPassenger(const Seat& S, int row) {
   cout.width(3);
   cout << row << "- ";
   if(!S.isEmpty()) {
      if(S.assigned()) {
         if(S.row() <= 4) cout << "Business Class ";
         else if(S.row() < 20) cout << "  Economy Plus ";
         else cout << "       Economy ";
         if(S.letter() == 'A' || S.letter() == 'F')
            cout << "Window: ";
         else if((S.row() < 4 && (S.letter() == 'B' || S.letter() == 'E'))
                 || (S.row() >= 7 && (S.letter() == 'C' || S.letter() == 'D')))
            cout << " Aisle: ";
         else cout << "Middle: ";
      } else {
         cout << "Invalid seat assigned: ";
      }
   }
   S.display() << endl;
}

void listSeatBookings() {
   cout << "Testing Read and constant methods" << endl;
   ifstream passengers("passengers.csv");  // works exactly like cin, but for a file.
   Seat S;
   int cnt = 1;
   while(S.read(passengers)) {
      displayPassenger(S, cnt++);
   }
}
```

## Execution Sample

```text
Testing Seat class Functionalities...
       Should be Invalid: Invalid Seat!
       Seat not assigned: Darth Vader............................. ___
           Assigned Seat: Luke Skywalker.......................... 7B
Darth`s seat is assigned: Darth Vader............................. 7A
   nullptr name; Invalid: Invalid Seat!
     Empty name; Invalid: Invalid Seat!
        A very long name: Hubert Blaine Wolfeschlegelsteinhausenbe 2A
          bad row number: Darth Vader............................. ___
          bad row number: Darth Vader............................. ___
          bad row number: Darth Vader............................. ___
          bad row number: Darth Vader............................. ___
          bad row number: Darth Vader............................. ___
          bad row number: Darth Vader............................. ___
         bad seat letter: Darth Vader............................. ___
         bad seat letter: Darth Vader............................. ___
         bad seat letter: Darth Vader............................. ___
  Luke's individual info: Luke Skywalker.......................... 7B
Name: Luke Skywalker
Row: 7
letter: B
       Seat gone (reset): Invalid Seat!
 Give the seat to luke's sister; enter following information:
Leia Organa,12B<ENTER>
Leia Organa,12B
you entered:
             Leia's seat: Leia Organa............................. 12B
========================================================================
Testing Read and constant methods
  1- Business Class Window: Baby Gerald............................. 1A
  2- Business Class  Aisle: Groundskeeper Willie.................... 1B
  3- Business Class  Aisle: Dolph Starbeam.......................... 1E
  4- Business Class Window: Kirk Van Houten......................... 1F
  5- Business Class Window: Artie Ziff.............................. 2A
  6- Business Class  Aisle: Edna Krabappel.......................... 2B
  7- Business Class  Aisle: Luann Van Houten........................ 2E
  8- Business Class Window: Janey Powell............................ 2F
  9- Business Class Window: Akira Kurosawa.......................... 3A
 10- Business Class  Aisle: Luigi Risotto........................... 3B
 11- Business Class  Aisle: Homer Simpson........................... 3E
 12- Business Class Window: Selma Bouvier........................... 3F
 13- Business Class Window: Wendell Borton.......................... 4A
 14- Business Class Middle: Manjula Nahasapeemapetilon.............. 4B
 15- Business Class Middle: Kearney Zzyzwicz........................ 4E
 16- Business Class Window: Brandine Spuckler....................... 4F
 17- Invalid seat assigned: Moe Szyslak............................. ___
 18- Invalid seat assigned: Ralph Wiggum............................ ___
 19-   Economy Plus  Aisle: Barney Gumble........................... 7D
 20-   Economy Plus Window: Carl Carlson............................ 7F
 21-   Economy Plus  Aisle: Gil Gunderson........................... 7C
 22-   Economy Plus Middle: Gloria Jailbird......................... 7B
 23-   Economy Plus Middle: Krusty The Clown........................ 7E
 24-   Economy Plus Window: Rod Flanders............................ 7A
 25-   Economy Plus Window: Bumblebee Man........................... 8A
 26-   Economy Plus  Aisle: Disco Stu............................... 8D
 27-   Economy Plus Middle: Helen Lovejoy........................... 8B
 28-   Economy Plus Window: Rabbi Hyman Krustofsky.................. 8F
 29-   Economy Plus Middle: Roger Meyers Jr......................... 8E
 30-   Economy Plus  Aisle: Shauna Chalmers......................... 8C
 31-   Economy Plus  Aisle: Bernice Hibbert......................... 9C
 32-   Economy Plus  Aisle: Dewey Largo............................. 9D
 33-   Economy Plus Window: Lunchlady Doris......................... 9F
 34-   Economy Plus Middle: Mayor Joe Quimby........................ 9E
 35-   Economy Plus Middle: Squeaky-Voiced Teen..................... 9B
 36-   Economy Plus Window: Waylon Smithers......................... 9A
 37-   Economy Plus  Aisle: Cletus Spuckler......................... 10D
 38-   Economy Plus Middle: Herman Hermann.......................... 10E
 39-   Economy Plus Window: Kent Brockman........................... 10A
 40-   Economy Plus Middle: Lindsey Naegle.......................... 10B
 41-   Economy Plus  Aisle: Ned Flanders............................ 10C
 42-   Economy Plus Window: Todd Flanders........................... 10F
 43-   Economy Plus  Aisle: Allison Taylor.......................... 11D
 44-   Economy Plus Window: Marge Simpson........................... 11F
 45-   Economy Plus Middle: Martin Prince........................... 11E
 46-   Economy Plus Middle: Rainier Wolfcastle...................... 11B
 47-   Economy Plus  Aisle: Sarah Wiggum............................ 11C
 48-   Economy Plus Window: Uter Zorker............................. 11A
 49-   Economy Plus  Aisle: Hans Moleman............................ 12C
 50-   Economy Plus  Aisle: Jessica Lovejoy......................... 12D
 51-   Economy Plus Window: Jimbo Jones............................. 12A
 52-   Economy Plus Middle: Judge Roy Snyder........................ 12B
 53-   Economy Plus Window: Kumiko Albertson........................ 12F
 54-   Economy Plus Middle: Milhouse Van Houten..................... 12E
 55-   Economy Plus Window: Apu Nahasapeemapetilon.................. 13F
 56-   Economy Plus  Aisle: Elizabeth Hoover........................ 13D
 57-   Economy Plus Middle: Lisa Simpson............................ 13E
 58-   Economy Plus Middle: Miss Springfield........................ 13B
 59-   Economy Plus  Aisle: Patty Bouvier........................... 13C
 60-   Economy Plus Window: Wise Guy................................ 13A
 61-   Economy Plus  Aisle: Jacqueline Bouvier...................... 14D
 62-   Economy Plus Window: Jasper Beardly.......................... 14A
 63-   Economy Plus Middle: Sea Captain............................. 14E
 64-   Economy Plus Middle: Seymour Skinner......................... 14B
 65-   Economy Plus  Aisle: The Rich Texan.......................... 14C
 66-   Economy Plus Window: Troy McClure............................ 14F
 67-   Economy Plus  Aisle: Bart Simpson............................ 15C
 68-   Economy Plus Middle: Johnny Tightlips........................ 15E
 69-   Economy Plus Window: Lionel Hutz............................. 15F
 70-   Economy Plus Middle: Mona Simpson............................ 15B
 71-   Economy Plus  Aisle: Ruth Powers............................. 15D
 72-   Economy Plus Window: Sideshow Mel............................ 15A
 73- Invalid seat assigned: Abraham Simpson......................... ___
 74- Invalid seat assigned: Alice Glick............................. ___
 75- Invalid seat assigned: Chazz Busby............................. ___
 76- Invalid seat assigned: Nelson Muntz............................ ___
 77- Invalid seat assigned: Snake Jailbird.......................... ___
 78- Invalid seat assigned: Surly Duff.............................. ___
 79- Invalid seat assigned: Chris Griffin........................... ___
 80- Invalid seat assigned: Comic Book Guy.......................... ___
 81- Invalid seat assigned: Drederick Tatum......................... ___
 82- Invalid seat assigned: Lenny Leonard........................... ___
 83- Invalid seat assigned: Ling Bouvier............................ ___
 84- Invalid seat assigned: Maude Flanders[D]....................... ___
 85- Invalid seat assigned: Brian Griffin........................... ___
 86- Invalid seat assigned: Diane Simmons........................... ___
 87- Invalid seat assigned: Lois Griffin............................ ___
 88- Invalid seat assigned: Maggie Simpson.......................... ___
 89- Invalid seat assigned: Peter Griffin........................... ___
 90- Invalid seat assigned: Stewie Griffin.......................... ___
 91- Invalid seat assigned: Cleveland Brown......................... ___
 92- Invalid seat assigned: Glenn Quagmire.......................... ___
 93- Invalid seat assigned: Joe Swanson............................. ___
 94- Invalid seat assigned: Judge Dignified Q. Blackman............. ___
 95- Invalid seat assigned: Meg Griffin............................. ___
 96- Invalid seat assigned: Tom Tucker.............................. ___
 97-        Economy  Aisle: Bonnie Swanson.......................... 20C
 98-        Economy Middle: Bruce Jake Tucker....................... 20E
 99-        Economy Window: Elmer Hartman........................... 20F
100-        Economy Window: Jonathan Weed........................... 20A
101-        Economy Middle: Loretta Brown........................... 20B
102-        Economy  Aisle: Rupert Kevin Swanson.................... 20D
103-        Economy Middle: Babs Pewterschmidt...................... 21B
104-        Economy Window: Carter Pewterschmidt.................... 21A
105-        Economy Middle: Cleveland Brown Jr...................... 21E
106-        Economy Window: Jasper Goldman.......................... 21F
107-        Economy  Aisle: Mayor Adam West......................... 21C
108-        Economy  Aisle: Tricia Takanawa......................... 21D
109-        Economy Middle: Connie D'Amico.......................... 22E
110-        Economy  Aisle: Ernie The Giant Chicken................. 22D
111-        Economy Window: Evil Monkey............................. 22A
112-        Economy Middle: Horace Jim Kaplan....................... 22B
113-        Economy Window: Muriel Goldman.......................... 22F
114-        Economy  Aisle: Neil Goldman............................ 22C
115-        Economy Middle: Francis Griffin......................... 23B
116-        Economy  Aisle: John Herbert............................ 23D
117-        Economy Middle: Mort Goldman............................ 23E
118-        Economy Window: Patty Ruth Cochamer..................... 23F
119-        Economy Window: Principal John Shepherd................. 23A
120-        Economy  Aisle: Thelma Griffin.......................... 23C
121-        Economy Middle: Angela Esther........................... 24E
122-        Economy  Aisle: Carol West.............................. 24C
123-        Economy  Aisle: Greased-Up Deaf Guy..................... 24D
124-        Economy Window: Jillian Russell-Wilcox.................. 24F
125-        Economy Middle: Ollie Williams.......................... 24B
126-        Economy Window: Seamus Levine........................... 24A
127-        Economy  Aisle: Al Harrington........................... 25C
128-        Economy Middle: Carl Woods.............................. 25E
129-        Economy Window: James William Bottomtooth III........... 25A
130-        Economy  Aisle: James Woods............................. 25D
131-        Economy Middle: Jesse Opie.............................. 25B
132-        Economy Window: Rallo Tubbs............................. 25F
133-        Economy  Aisle: Donna Tubbs-Brown....................... 26D
134-        Economy Window: Fouad RJ Consuela....................... 26A
135-        Economy Middle: Ida Davis Jerome........................ 26E
136-        Economy Window: Shmi Skywalker.......................... 26F
137-        Economy  Aisle: Susie Swanson........................... 26C
138-        Economy Middle: Tomik & Bellgarde....................... 26B
139-        Economy Window: Ben Solo................................ 27F
140-        Economy Middle: Doug Tammy.............................. 27E
141-        Economy Window: Joyce Kinney............................ 27A
142-        Economy  Aisle: Miss Tammy.............................. 27D
143-        Economy  Aisle: Roberta Tubbs........................... 27C
144-        Economy Middle: Stella Vinny............................ 27B
145-        Economy Window: Anakin Skywalker........................ 28A
146-        Economy Middle: Darth Vader............................. 28B
147-        Economy Middle: Han Solo................................ 28E
148-        Economy  Aisle: Leia Organa............................. 28D
149-        Economy  Aisle: Luke Skywalker.......................... 28C
150-        Economy Window: Ryoo Naberrie........................... 28F
```
## PART 1 Submission (lab)

### Files to submit:  

```Text
Seat.cpp
Seat.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

Follow the instructions during execution

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

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%) 

You have been provided the fully implemented module/class called "TourTicket". 
```C++
class TourTicket {
  char m_name[41]; // passenger name
  int m_ticketNumber;
  void copyName(const char* str);
public:
  TourTicket();
  TourTicket& issue(const char* passengerName);
  std::ostream& display(std::ostream& coutRef = std::cout)const;
  bool valid()const;
};
```
> Read the code of the class and understand how it works. This class does exactly what needs to be done to complete this workshop. However, you can modify it to your need or taste if you like.

## Your Task

Create a module/class called TourBus to encapsulate a TourBus carrying passengers for a city tour using a dynamic TourTicket array.   

Your TourBus should come in three sizes: 
- 4 passenger private tour
- 16 passengers Mini tour bus
- 22 passengers Full-size bus. 

Any attempt to create a TourBus with a size different than the above should result in an invalid unusable TourBus.

### Required Functionalities

- A TourBus should be created using the number of passengers it can carry.
- A TourBus should be able to return if it is in a valid state using a query method called ```validTour()```;
- A TourBus Should be able to Board Passengers by issuing their tickets when entering the bus. This should be done using a method called ```board()``` returning the reference of the TourBus Object. Execution sample if this is a private tour with 4 passengers:  
```text
Boarding 4 Passengers:
1/4- Passenger Name: Homer Simspson
2/4- Passenger Name: Marge Simpson
3/4- Passenger Name: Lisa Simpson
4/4- Passenger Name: Bart Simpson
```
- A method called `startTheTour()` Should start the tour as follows:
This method should check and make sure the bus is in a valid state, then if all the passengers are boarded, it should print their name and ticket number to start the tour. Execution sample: 

When The bus is valid and fully boarded:
```text
Starting the tour....
Passenger List:
|Row | Passenger Name                           | Num |
+----+------------------------------------------+-----+
|  1 | Homer Simpson                            | 100 |
|  2 | Marge Simpson                            | 101 |
|  3 | Lisa Simpson                             | 102 |
|  4 | Bart Simpson                             | 103 |
+----+------------------------------------------+-----+
```
When the bus is valid and not fully boarded:
```text
Cannot start the tour, the bus is not fully boarded!
```
If bus is in an invalid state, no action will be taken.


## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 4 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/09/27
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "TourBus.h"
using namespace std;
using namespace sdds;
void depart(const TourBus& T) {
   if(T.validTour()) 
      T.startTheTour();
}
int main() {
   TourBus* t;
   bool done = false;
   int num;
   cout << "Enter the following data:" << endl
      << "100<ENTER>" << endl
      << "10<ENTER>" << endl
      << "22<ENTER>" << endl
      << "16<ENTER>" << endl
      << "4<ENTER>" << endl
      << "John Doe<ENTER>" << endl
      << "Jane Doe<ENTER>" << endl
      << "Jack Doe<ENTER>" << endl
      << "Jill Doe<ENTER>" << endl
      << "-------------------" << endl;
   while(!done){
      cout << "Please enter number of passengers: ";
      cin >> num;
      cin.ignore(1000, '\n');
      t = new TourBus(num);
      if(t->validTour()) {
         if(num == 4) {
            depart(t->board());
            done = true;
         }
         else {
            depart(*t);
         }
      }
      else {
         cout << "Invalid tour bus!" << endl;
      }
      delete t;
   }
   return 0;
}
```
## Execution Sample
```text
Enter the following data:
100<ENTER>
10<ENTER>
22<ENTER>
16<ENTER>
4<ENTER>
John Doe<ENTER>
Jane Doe<ENTER>
Jack Doe<ENTER>
Jill Doe<ENTER>
-------------------
Please enter number of passengers: 100
Invalid tour bus!
Please enter number of passengers: 10
Invalid tour bus!
Please enter number of passengers: 22
Cannot start the tour, the bus is not fully boarded!
Please enter number of passengers: 16
Cannot start the tour, the bus is not fully boarded!
Please enter number of passengers: 4
Boarding 4 Passengers:
1/4- Passenger Name: John Doe
2/4- Passenger Name: Jane Doe
3/4- Passenger Name: Jack Doe
4/4- Passenger Name: Jill Doe
Starting the tour....
Passenger List:
|Row | Passenger Name                           | Num |
+----+------------------------------------------+-----+
|  1 | John Doe                                 | 100 |
|  2 | Jane Doe                                 | 101 |
|  3 | Jack Doe                                 | 102 |
|  4 | Jill Doe                                 | 103 |
+----+------------------------------------------+-----+

```
## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.



## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
TourTicket.cpp
TourTicket.h
TourBus.cpp
TourBus.h
main.cpp
```

### Data Entry

Follow the instructions of the tester program

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

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

