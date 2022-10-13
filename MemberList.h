// Stewart Kerns
// File: MemberList.h
// Date: 10/12/2022
// Purpose: This is the header file for the MemberList.cpp file and holds all
// the methods and fields for the class

#ifndef P1_MEMBERLIST_H
#define P1_MEMBERLIST_H
#include <string>
using namespace std;


class MemberList {

public:
    MemberList();
    // The constructor initializes all the fields and sets up the members
    // array
    // IN: none
    // MODIFY: set up the members array, initialize all fields
    // OUT: none

    ~MemberList();
    //This destructor deletes the object after the program is done
    //IN: none
    //MODIFY: delete the object
    //OUT: none

    MemberList(const MemberList &);
    //This copy constructor copies the fields of a passed in RatingList
    //IN: RatingList with fields to copy
    //MODIFY: Set fields to that of the passed in RatingList
    //OUT: none

    MemberList& operator=(const MemberList &);
    //This method overloads the = sign and allows for a copy to be made
    //IN: MemberList to copy
    //MODIFY: Set all the values of the MemberList object to the object it's set
    // to
    //OUT: MemberList that is the same as the other, but not same address

    string add(string);
    // This method adds a new member name to the array
    // IN: string for the username
    // MODIFY: adds the name to the next spot on the array
    // OUT: none

    string get(int) const;
    // This method gets the username for a given user number
    // IN: int value of the user number
    // MODIFY: none
    // OUT: string of the user's name

    bool empty();
    // This method returns a boolean of if there are no members in the list or
    // not
    // IN: none
    // MODIFY: none
    // OUT: boolean of if there are no members

    int size() const;
    // This method returns how many members are in the array
    // IN: none
    // MODIFY: none
    // OUT: The number of members in the array

    string to_string() const;
    // This method returns a string of all the member names and their numbers
    // IN: none
    // MODIFY: none
    // OUT: string of all the member name and numbers

    void setCurrentMember(int);
    // This method sets the current member number
    // IN: member number value to set the current member to
    // MODIFY: set the currentMemNum field
    // OUT: none

private:
    //create a struct that will hold the data needed for the members
    struct Members{
        int memberNumber;
        string memberName;
    };

    void resize();
    // The resize method doubles the capacity of the array, creates a new array
    // of that size and moves the point over to that array with the data copied
    // IN: none
    // MODIFY: create new array and move over all the data
    // OUT: none

    //declare a point for a Members array
    Members* membersArray;

    //declare an int for the array capacity
    int capacity;

    //declare an int for the number of the current member
    int currentMemNum;

    //declare an int for the number of members
    int numMembers;
};
#endif //P1_MEMBERLIST_H
