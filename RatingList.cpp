// Stewart Kerns
// File: RatingList.cpp
// Date: 10/12/2022
// Purpose: This class holds all the methods and fields in order to create a 2D
// array of ratings that corresponds to users

#include "RatingList.h"
#include <string>
using namespace std;

RatingList::RatingList(){
    //create a constant for the array size
    capacityRow = 100;
    capacityCol = capacityRow;
    //build a 2D array to hold the ratings
    ratings = arrayBuild2D();

    //set the currentMember value to no one
    currentMember = -1;
    numMembers = 0;
    numBooks = 0;

}

RatingList::~RatingList(){

    //deallocate each of the arrays in the array
    for (int i = 0; i < capacityRow; i++){
        delete[] ratings[i];
    }

    //deallocate the array
    delete[] ratings;
}

RatingList::RatingList(const RatingList &obj){
    //copy over all the fields
    capacityRow = obj.capacityRow;
    capacityCol = obj.capacityCol;
    currentMember = obj.currentMember;
    numMembers = obj.numMembers;
    numBooks = obj.numBooks;

    //create a new ratings array of the same capacityRow
    ratings = arrayBuild2D();

    //copy over all the data from the obj's array
    for (int i = 0; i < capacityRow; i++){
        for (int j = 0; j < capacityCol; j++){
            ratings[i][j] = obj.ratings[i][j];
        }
    }
}

RatingList& RatingList::operator=(const RatingList &obj){
//as long as they aren't currently the same, start setting them equal
    if (this != &obj){

        //delete the current structArray
        delete2D(ratings);

        //set the capacityRow and numMembers to the input object's capacityRow,
        //numMembers, numBooks, and capacityCol
        capacityRow = obj.capacityRow;
        numMembers = obj.numMembers;
        numBooks = obj.numBooks;
        capacityRow = obj.capacityCol;

        //create a new ratings array of the same capacityRow
        ratings = arrayBuild2D();

        //copy over all the data from the obj's array
        for (int i = 0; i < capacityRow; i++){
            for (int j = 0; j < capacityCol; j++){
                ratings[i][j] = obj.ratings[i][j];
            }
        }
    }
    //return the copied BookList object
    return *this;
}

void RatingList::add(int bookNumber, int rating){

    //if the capacity of the rows has been reached, resize the array
    if (numMembers >= capacityRow) {
        resizeRow();
    }

    //if the capacity of the columns has been reached, resize the array
    else if (numBooks >= capacityCol){
        resizeCol();
    }
    //set the rating for the book for the current member
    ratings[currentMember][bookNumber - 1] = rating;
}

int RatingList::get(int bookNumber) const{

    //return the rating for the isbn requested for the current member
    return ratings[currentMember][bookNumber - 1];
}

int RatingList::get(int userNumber, int bookNumber){

    //return the rating for the isbn requested for the user requested
    return ratings[userNumber - 1][bookNumber - 1];
}

bool RatingList::empty(){

    //if there is a rating anywhere by the user, return false
    for (int i = 0; i < numBooks; i++){
        if (ratings[currentMember][i] != 0){
            return false;
        }
    }

    //if the user has rated no books, return true
    return true;
}

int RatingList::size() const{

    //return the capacity of the rows
    return capacityRow;
}

string RatingList::to_string() const{

    //create a stringstream object
    stringstream ss;

    //send out each of the member's book ratings to ss
    for(int i = 0; i < numBooks; i++){
        ss << ratings[currentMember][i] << " ";
    }
    ss << endl;

    //return the stringstream string
    return ss.str();
}

void RatingList::setCurrentMember(int currentMember) {

    //set the current member to the requested member number
    this->currentMember = currentMember - 1;
}

void RatingList::addMember() {

    //increment the number of members
    numMembers++;
}

void RatingList::addBook() {

    //increment the number of books
    numBooks++;
}

void RatingList::resizeRow() {

    //double the capacity
    capacityRow *= 2;

    //create a new 2d temp array
    int** temp = arrayBuild2D();

    //copy over all the data into the temp array
    for (int i = 0; i < numMembers; i++){
        for (int j = 0; j < numBooks; j++){
            temp[i][j] = ratings[i][j];
        }
    }

    //delete the old array
    for (int i = 0; i < numMembers; i++){
        delete[] ratings[i];
    }
    delete[] ratings;

    //move the pointer
    ratings = temp;
}

void RatingList::resizeCol(){
    //double the capacity of the columns
    capacityCol *= 2;

    //create a new 2d temp array
    int** temp = arrayBuild2D();

    //copy over all the data
    for (int i = 0; i < numMembers; i++){
        for (int j = 0; j < numBooks; j++){
            temp[i][j] = ratings[i][j];
        }
    }

    //delete the old array
    for (int i = 0; i < numMembers; i++){
        delete[] ratings[i];
    }
    delete[] ratings;

    //move the pointer over
    ratings = temp;
}

int RatingList::getCurrentMember(){

    //return the current member number
    return currentMember + 1;
}

void RatingList::delete2D(int** array){

    //deallocate each of the arrays in the array
    for (int i = 0; i < capacityRow; i++){
        delete[] array[i];
    }

    //deallocate the array
    delete[] array;
}

int** RatingList::arrayBuild2D(){

    //declare a pointer for a 2D array
    int** array2Dim;

    //declare a new array of pointers of arraySize
    array2Dim = new int*[capacityRow];

    //create a new array for each pointer
    for (int i = 0; i < capacityRow; i++){
        array2Dim[i] = new int[capacityCol];
    }

    //return the 2D array
    return array2Dim;
}

bool RatingList::full() {
    //if there is a 0 rating anywhere by the user, return false
    for (int i = 0; i < numBooks; i++){
        if (ratings[currentMember][i] == 0){
            return false;
        }
    }

    //if the user has no unrated books, return true
    return true;
}
