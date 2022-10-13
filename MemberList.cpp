// Stewart Kerns
// File: MemberList.cpp
// Date: 10/12/2022
// Purpose:

#include "MemberList.h"
#include <string>
#include <sstream>
using namespace std;

MemberList::MemberList(){
    //create the membersArray for the object
    capacity = 100;
    membersArray = new Members[capacity];

    //initialize the currentMemNum and numMembers fields
    currentMemNum = -1;
    numMembers = 0;
}

MemberList::~MemberList() {

    //delete the membersArray
    delete[] membersArray;
}

MemberList::MemberList(const MemberList &obj){

    //set all the fields the same
    capacity = obj.capacity;
    numMembers = obj.numMembers;
    currentMemNum = obj.currentMemNum;

    //create a new membersArray of the same size
    membersArray = new Members[capacity];

    //copy over all the data from the obj's memberArray
    for (int i = 0; i < numMembers; i++){
        membersArray[i] = obj.membersArray[i];
    }

}

MemberList& MemberList::operator=(const MemberList &obj){
//as long as they aren't currently the same, start setting them equal
    if (this != &obj){

        //delete the current membersArray
        delete[] membersArray;

        //set the capacityRow and numMembers to the input object's capacityRow and
        //numMembers
        capacity = obj.capacity;
        numMembers = obj.numMembers;

        //create a new membersArray that will be returned
        membersArray = new Members[capacity];

        //copy over all the data from the input object's membersArray
        for (int i = 0; i < capacity; i++){
            membersArray[i] = obj.membersArray[i];
        }
    }
    //return the copied BookList object
    return *this;
}

string MemberList::add(string name){

    //if the capacity is reached, resize the array
    if (numMembers >= capacity){
        resize();
    }

    //set the memberName and memberNumber for the element
    membersArray[numMembers].memberName = name;
    membersArray[numMembers].memberNumber = numMembers + 1;

    //increment the number of members
    numMembers++;

    //create a stringstream to pass a string about who was added and their num
    stringstream newMember;
    newMember << membersArray[numMembers - 1].memberName << ", your number is "
    << membersArray[numMembers - 1].memberNumber;

    //return the string of the stringstream
    return newMember.str();

}

string MemberList::get(int memberNum) const{

    //return the name of the member of the input number
    return membersArray[memberNum - 1].memberName;
}

void MemberList::setCurrentMember(int memberNum) {

    //set the current member number
    currentMemNum = memberNum - 1;
}

void MemberList::resize() {

    //update the capacity
    capacity *= 2;

    //create a new Members array of double the capacity
    Members* temp = new Members[capacity];

    //copy all the data over
    for (int i = 0; i < numMembers; i++){
        temp[i] = membersArray[i];
    }

    //delete the old array
    delete[] membersArray;

    //move the pointer to the temp array
    membersArray = temp;
}

bool MemberList::empty(){

    //return if there are no members
    return numMembers == 0;
}

int MemberList::size() const{

    //return how many members are in the array
    return numMembers;
}

string MemberList::to_string() const {

    //declare a stringstream object
    stringstream membersNamesNums;

    //write each of the members names and numbers to the object
    for (int i = 0; i < numMembers; i++){
        membersNamesNums << membersArray[i].memberNumber << ": "
        << membersArray[i].memberName << "\n";
    }

    //return the string
    return membersNamesNums.str();
}



