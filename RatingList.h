// Stewart Kerns
// File: RatingList.h
// Date: 10/12/2022
// Purpose: This is the header file for the RatingList.cpp file and holds all
// the methods and fields for the class

#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


class RatingList {

public:
    RatingList();
    // The constructor initializes all the fields and sets up the ratings
    // array
    // IN: none
    // MODIFY: set up the ratings array, initialize all fields
    // OUT: none

    ~RatingList();
    //This destructor deletes the object after the program is done
    //IN: none
    //MODIFY: delete the object
    //OUT: none

    RatingList(const RatingList &);
    //This copy constructor copies the fields of a passed in RatingList
    //IN: RatingList with fields to copy
    //MODIFY: Set fields to that of the passed in RatingList
    //OUT: none

    RatingList& operator=(const RatingList &);
    //This method overloads the = sign and allows for a copy to be made
    //IN: RatingList to copy
    //MODIFY: Set all the values of the RatingList object to the object it's set
    // to
    //OUT: RatingList that is the same as the other, but not same address

    void add(int, int);
    // This method adds a rating for the current user with the isbn selected and
    // the rating input
    // IN: isbn of book to rate
    // IN: rating of the book
    // MODIFY: modify the rating of that user's row
    // OUT: none

    int get(int) const;
    // This method gets the rating of the current user at the isbn requested
    // IN: isbn of the book to get the rating for
    // MODIFY: none
    // OUT: integer of the rating for that book

    bool empty();
    // This method returns if the user has 0 books rated
    // IN: none
    // MODIFY: none
    // OUT: boolean of if the user has read any books

    int size() const;
    // This method returns the size of the first dimension of the array
    // IN: none
    // MODIFY: none
    // OUT: size of first dimension of the array

    string to_string() const;
    // This method returns a list of the current user's book ratings
    // IN: none
    // MODIFY: none
    // OUT: string of all the user's books ratings

    int** arrayBuild2D();
    // This method builds a 2D int array and returns the array
    // IN: integer to allocate the size of the array
    // MODIFY: none
    // OUT: 2D int array of the size input

    void delete2D(int**);
    //This method deallocates a 2D int array
    // IN: 2D int array
    // MODIFY: deallocate the entire 2D array
    // OUT: none

    void setCurrentMember(int);
    // This method sets the field of current member
    // IN: integer value for the user's member number
    // MODIFY: set the field of currentMember
    // OUT: none

    void addMember();
    // This method adds a member to the number of members field in order to keep
    // track of members
    // IN: none
    // MODIFY: adds a member to the members field
    // OUT: none

    void addBook();
    // This method adds a book to the number of books field in order to keep
    // track of the books
    // IN: none
    // MODIFY: increment the number of books field
    // OUT: none

    int get(int, int);
    // This get method takes in two integers, one for the member id and one for
    // the isbn
    // IN: isbn to get the rating of
    // IN: user number to get the rating from
    // MODIFY: none
    // OUT: integer for the rating of the book

    int getCurrentMember();
    // This method gets the user number of the current member
    // IN: none
    // MODIFY: none
    // OUT: return the user number of the current member

    bool full();
    //This method returns a boolean of if the user has read all the available
    //books or not
    // IN: none
    // MODIFY: none
    // OUT: boolean of if they have read all the books

private:

    void resizeRow();
    // This method resizes the rows by doubling the amount of row capacity and
    // then creates a new array and moves all the data over
    // IN: none
    // MODIFY: create a new ratings array with double the rows
    // OUT: none

    void resizeCol();
    // This method resizes the columns by doubling the amount of column
    // capacity and then creates a new array and moves all the data over
    // IN: none
    // MODIFY: create a new ratings array with double the columns
    // OUT: none

    //declare an int 2d array pointer for the ratings array
    int** ratings;

    //declare an int for the current member
    int currentMember;

    //declare an int for the number of members
    int numMembers;

    //declare an int for the row capacity
    int capacityRow;

    //declare an int for the number of books
    int numBooks;

    //declare an int for the capacity of columns
    int capacityCol;
};


#endif //P1_RATINGLIST_H
