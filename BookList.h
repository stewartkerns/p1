// Stewart Kerns
// File: BookList.h
// Date: 10/04/2022
// Purpose: This is the header file for BookList.cpp and holds all the methods
// and fields

#ifndef P1_BOOKLIST_H
#define P1_BOOKLIST_H
#include <string>
using namespace std;

class BookList {
public:


    BookList();
    //This constructor initializes numElements and isbnInt as well as creating
    //the stuctArray for the object
    //IN: none
    //MODIFY: create a struct array and initialize fields
    //OUT: none

    ~BookList();
    //This destructor deletes the object after the program is done
    //IN: none
    //MODIFY: delete the object
    //OUT: none

    BookList(const BookList &);
    //This copy constructor copies the fields of a passed in BookList
    //IN: BookList with fields to copy
    //MODIFY: Set fields to that of the passed in BookList
    //OUT: none

    BookList& operator=(const BookList &);
    //This method overloads the = sign and allows for a copy to be made
    //IN: BookList to copy
    //MODIFY: Set all the values of the BookList object to the object it's set
    // to
    //OUT: BookList that is the same as the other, but not same address

    void add(string, string, string);
    //The add function takes the author, title, and year(s) the book was
    //published and adds it into the structArray
    //IN: author string, title string, year(s) string
    //MODIFY: Add an element containing the data input into the structArray
    //OUT: none

    int get(int) const;
    //This method finds the first instance of the isbn input and returns the
    //element number
    //IN: isbn number to search for
    //MODIFY: none
    //OUT: element of the isbn number

    bool empty() const;
    //This method returns a boolean for if the structArray is empty or not
    //IN: none
    //MODIFY: none
    //OUT: boolean if the structArray is empty or not

    int size() const;
    //This method returns the number of elements that have data in them in the
    //structArray
    //IN: none
    //MODIFY: none
    //OUT: return the number of elements that have data in the structArray

    string to_string() const;
    //The to_string method outputs the data of the structArray to a string
    //which can be printed
    //IN: none
    //MODIFY: none
    //OUT: formatted string representation of the structArray data

    string getBookData(int);
    // This method gets the book title, author, and year or years published and
    // returns it as a single string
    // IN: isbn for the book info is wanted on
    // MODIFY: none
    // OUT: string of the data for the isbn of the book

    //private methods and fields
private:

    //create a struct to hold data for a single book.  This includes the isbn,
    //the author, the title, and year(s) the book(s) was published.
    struct Book{
        int isbn;
        string author;
        string title;
        string year;
    };

    void resize();
    //This method is used when the array runs out of data and the capacityRow needs
    //to be increased.  The array size is double and then data is copied over
    //IN: none
    //MODIFY: resize the capacityRow of structArray to double the current size
    //OUT: none

    //declare a pointer to for an array of Book objects
    Book* structArray;

    //declare an int for the number of elements with data
    int numElements;

    //declare an int for the capacityRow of the array
    int capacity;
};

#endif //P1_BOOKLIST_H
