// Stewart Kerns
// File: BookList.cpp
// Date: 10/04/2022
// Purpose: This class holds all the methods and fields needed to create an
// array of structs that hold book data for a book list

#include "BookList.h"
#include <string>
#include <sstream>
using namespace std;

static int isbnInt = 1;

BookList::BookList() {
    //create the structArray for the object
    capacity = 100;
    structArray = new Book[capacity];

    //initialize the numElement int
    numElements = 0;

}

BookList::~BookList() {

    //delete the structArray array
    delete[] structArray;
}

BookList::BookList(const BookList &obj) {

    //set the capacityRow and numElements to the input object's capacityRow and
    //numElements
    capacity = obj.capacity;
    numElements = obj.numElements;

    //create a new structArray of the same capacityRow
    structArray = new Book[capacity];

    //copy over all the data from the structArray of the input object
    for(int i = 0; i < numElements; i++){
        structArray[i] = obj.structArray[i];
    }
}

BookList& BookList::operator=(const BookList &obj) {

    //as long as they aren't currently the same, start setting them equal
    if (this != &obj){

        //delete the current structArray
        delete[] structArray;

        //set the capacityRow and numElements to the input object's capacityRow and
        //numElements
        capacity = obj.capacity;
        numElements = obj.numElements;

        //create a new structArray that will be returned
        structArray = new Book[capacity];

        //copy over all the data from the input object's structArray
        for (int i = 0; i < capacity; i++){
            structArray[i] = obj.structArray[i];
        }
    }
    //return the copied BookList object
    return *this;
}

void BookList::add( string title, string author, string year) {
    //if the number of elements is at capacityRow, call the resize method to
    //increase the size of the array
    if (numElements >= capacity){
        resize();
    }

    //set the structArray's element isbn and increments afterwards
    structArray[numElements].isbn = isbnInt++;

    //set the structArray's element author to the author name input
    structArray[numElements].author = author;

    //set the structArray's element to the title input
    structArray[numElements].title = title;

    //set the structArray's element to the year input
    structArray[numElements].year = year;

    //increment the element number for the next add function
    numElements++;
}

bool BookList::empty() const {

    //return if the array is empty
    return numElements == 0;
}

int BookList::size() const {

    //return the number of elements that have data in them
    return numElements;
}

int BookList::get(int isbn) const {

    //search through the struct array for the isbn of the book
    for (int i = 0; i < numElements; i++) {

        if (structArray[i].isbn == isbn)
            //return the element where the isbn was found
            return i;
    }

    //if not found, it returns -1
    return -1;
}

void BookList::resize() {

    //set the capacityRow to double the current value
    capacity *= 2;

    //create a temporary array
    Book* tempArray = new Book[capacity];

    //copy the data from the structArray into the tempArray
    for (int i = 0; i < numElements; i++){
        tempArray[i] = structArray[i];
    }

    //delete the structArray
    delete[] structArray;

    //move the tempArray to the structArray
    structArray = tempArray;
}

string BookList::to_string() const {

    //create a stringstream object
    stringstream ss;

    //add each element in the array to the stringstream object, formatted with
    //spaces and commas
    for (int i = 0; i < numElements; i++){
        ss << structArray[i].isbn << ", " << structArray[i].author << ", "
           << structArray[i].title << ", " << structArray[i].year << endl;
    }

    //return the string of the stringstream
    return ss.str();
}

string BookList::getBookData(int bookElement){
    //declare a stringstream object
    stringstream ss;

    //write each of the pieces of data from the book element input to the
    // stringstream
    ss << structArray[bookElement - 1].isbn << ": " <<
    structArray[bookElement - 1].title << ", " << structArray[bookElement - 1].author
    << ", " << structArray[bookElement - 1].year;

    //return the string of the stringstream
    return ss.str();
}

