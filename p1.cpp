// Stewart Kerns
// File:
// Date: 10/12/2022
// Purpose: The purpose of this program is hold data of books for users,
// hold the users ratings of those books, and hold data on the users through
// the use of other classes. The users can then interact with a UI to get info
// and get recommendations on books
// Input: the text files to read the data from
// Process: Walk the user through the UI and provide them with recommendations
// of books
// Output: Different data on the books or recommendations depending on the user
// input

#include <iostream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
#include <string>
using namespace std;
#include <sstream>
#include <iostream>
#include <fstream>

string firstScreen();
// This method outputs the formatting for the first option screen
// IN: none
// MODIFY: none
// OUT: UI for the first option screen

string secondScreen();
// This method creates the formatting for the second option screen
// IN: none
// MODIFY: none
// OUT: UI for the second option screen

string takeInput();
// This method takes in input and then returns the string value of it
// IN: none
// MODIFY: none
// OUT: return string of the input from the standard input

void secondOptionScreen(BookList*, MemberList*, RatingList*);
// This method prints the second option screen and allows for the user to make
// a multitude of choices
// IN: Booklist object to pull methods from
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: none
// OUT: none

void firstOptionScreen(BookList*, MemberList*, RatingList*);
// This method provides the first option screen and allows the user to make a
// multitude of choices
// IN: Booklist object to pull methods from
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: none
// OUT: none

void openFile(ifstream&, string);
// This method uses getFilePath to ask the user for a filepath and then
// continues to request it until a valid path is given
// IN: ifstream object for opening
// IN: string of the file type to be opened for informing the user
// MODIFY: use ifstream to open the file
// OUT: the string of the filepath

string getFilepath(string);
// The method prompts the user for a filepath to return as a string
// IN: none
// MODIFY: none
// OUT: String containing the filepath

void addMembersRatings(ifstream&, MemberList*,
                       RatingList*);
// This method uses the opened file to write all the data to the MemberList and
// the RatingList
// IN: ifstream object that contains the file to be read
// IN: MemberList object to have the data written to
// IN: RatingList object to have the data written to
// MODIFY: Add the data to the MemberList and RatingList
// OUT: none

void addBooks(ifstream&, BookList*);
// This method uses the opened file to write all the data to the BookList object
// IN: ifstream object that contains the file to read
// IN: BookList object to have the data written to
// MODIFY: Add the data to the BookList
// OUT: none

string addMember(MemberList*, RatingList*);
//
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY:
// OUT:

string addBook(BookList*, RatingList*);
// This method adds a book to the BookList as well as updates the number of
// books in the RatingList object
// IN: Booklist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: Add the book data to the BookList object and update the max books in
// the RatingList object
// OUT: string of the book added

int addRating(BookList*, RatingList*);
// This method adds a rating for a book for the logged-in user
// IN: Booklist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: Add a rating to the chosen book by the member
// OUT: rating that the user chose

string getRatings(BookList*, MemberList*, RatingList*);
// This method gets each of the books and ratings for the logged-in user
// IN: Booklist object to pull methods from
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: none
// OUT: string of each of the books in the system and the given rating by the
// logged-in user

void login(MemberList*, RatingList*);
// This method logs the user in by setting the current user in the RatingList
// object and the MemberList object
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: Set the current user in the two input objects
// OUT: none

int takeIntInput();
// This method takes an integer input and checks that it is actually an integer
// IN: none
// MODIFY: none
// OUT: integer input by the user from the standard input

string recommendBooks(BookList*, MemberList*, RatingList*);
// This method recommends books to the logged-in user based off of their tastes
// by comparing their taste to others
// IN: Booklist object to pull methods from
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: none
// OUT: string of a list of books the user might like

void logoutUser(MemberList*, RatingList*);
// This method logs the user out by setting the current user in the MemberList
// and RatingList objects to -1
// IN: Memberist object to pull methods from
// IN: Rating list object to pull methods from
// MODIFY: Se the current users to -1 in the objects
// OUT: none

int main(){
    BookList* books = new BookList();
    MemberList* members = new MemberList();
    RatingList* ratings = new RatingList();

    //declare an ifstream object for reading
    ifstream inFile;

    //ask the user for the file they would like to read from for the ratings
//    openFile(inFile, "ratings");
    inFile.open("C:\\Users\\Stewart\\Desktop\\CPSC5005\\p1\\ratings.txt");
    //add the data from the file into the members and ratings objects
    addMembersRatings(inFile, members, ratings);

    //close the input file
    inFile.close();

    //ask the user for the file they would like to read from for the books
//    openFile(inFile, "books");
    inFile.open("C:\\Users\\Stewart\\Desktop\\CPSC5005\\p1\\books.txt");

    //add the data from the file into the books object
    addBooks(inFile, books);

    //close the input file
    inFile.close();

    //run the first option screen for the user
    firstOptionScreen(books, members, ratings);

    return 0;
}

void firstOptionScreen(BookList* books, MemberList* members,
                       RatingList* ratings){
    //create a flag to quit the program with
    int quit = 0;

    do {
        //print the first screen options
        cout << firstScreen();

        //take the user's input for what they would like to choose
        int numChoice = takeIntInput();

        //run a switch statement for all the choices possible
        switch (numChoice) {

            //add a member to the members list and update the number of members
            //in ratings, also tell the user what their number is
            case 1:
                cout << addMember(members, ratings) << "\n" << endl;
                break;

                //add a book and tell the user what book they added
            case 2:
                cout <<addBook(books, ratings) << " has been added!\n"
                << endl;
                break;

                //allow the user to login if they have their user number
            case 3:
                login(members, ratings);

                //continue to the second option screen with member specific
                // items
                secondOptionScreen(books, members, ratings);
                break;

                //quit the application
            case 4:
                cout << "Quitting application!" << endl;
                quit = 1;
                break;

                //inform the user they chose an invalid number
            default:
                cout << "That is not a valid option. Please choose a valid "
                        "integer\n" << endl;
        }

        //run the program until the user decides to quit
    } while(quit == 0);
}

void secondOptionScreen(BookList* books, MemberList* members,
                        RatingList* ratings){

    //create a logout flag
    int logout = 0;

    //declare a newRating integer for use in printing
    int newRating;

    //ignore the stored characters
    cin.ignore();

    //inform the user by name that they have been logged in
    cout << members->get(ratings->getCurrentMember())
    << ", you have been logged in!\n\n";

    do {
        //print the second screen options
        cout << secondScreen();

        //take in the user's input
        int numChoice = takeIntInput();

        //run a switch to decide what to do with the user input
        switch (numChoice) {

            //add a member and inform the member of their new user number
            case 1:
                cout << addMember(members, ratings) << "\n" << endl;
                break;

                //add a book and inform the user what book they added
            case 2:
                cout <<addBook(books, ratings) << " has been added!\n" << endl;
                break;

                //add a rating and print out to the user what book they rated
                //with the updated rating
            case 3:
                newRating = addRating(books, ratings);
                cout << "Rating has been added!\n\nYour new rating is as "
                        "follows:\n" << books->getBookData(newRating) <<
                        " => rating: " << ratings->get(newRating) << "\n"
                        << endl;

                break;

                //print all of the user's book ratings
            case 4:
                cout << getRatings(books, members, ratings) << endl;
                break;

                //run the recommend method to recommend books to the user
            case 5:
                cout << recommendBooks(books, members, ratings) << endl;
                break;

                //log the user out
            case 6:
                cout << "Logging out!" << endl;
                logoutUser(members, ratings);
                logout = 1;
                break;

                //inform the user they chose an invalid selection
            default:
                cout << "That is not a valid option. Please choose a valid "
                        "integer\n" << endl;
        }

    //run until the user chooses to log out
    }while(logout == 0);
}

string takeInput(){

    //declare a string to take in a line
    string line;

    //use getline to take in input from the standard input
    getline(cin, line);

    //return the string
    return line;
}

int takeIntInput(){

    //declare an int that will store input
    int num;

    //take in the input form the standard input
    cin >> num;

    //verify that the input is an integer
    while (!cin.good()){
        cin.clear();
        cin.ignore();

        //inform the user if it isn't an integer
        cout << "That's not a valid selection. Please choose a valid integer: ";
        cin >> num;
    }

    //return the integer
    return num;
}

string firstScreen(){

    //create a screen to display to the user
    string display = "************** MENU **************\n"
                     "* 1. Add a new member            *\n"
                     "* 2. Add a new book              *\n"
                     "* 3. Login                       *\n"
                     "* 4. Quit                        *\n"
                     "**********************************\n"
                     "\nPlease choose an option: ";

    //return the display
    return display;
}

string secondScreen(){

    //create a screen to display for the user
    string display = "************** MENU **************\n"
                     "* 1. Add a new member            *\n"
                     "* 2. Add a new book              *\n"
                     "* 3. Rate book                   *\n"
                     "* 4. View ratings                *\n"
                     "* 5. See recommendations         *\n"
                     "* 6. Logout                      *\n"
                     "**********************************\n"
                     "\nPlease choose an option: ";

    //return the display
    return display;
}

void openFile(ifstream &inFile, string fileType){
    //declare a filepath string
    string filePath;

    //prompt the user for a filepath and if the file doesn't open, continue to
    //prompt them
    do {
        //use the getFilepath method to get a filepath from the user
        filePath = getFilepath(fileType);

        //open the file
        inFile.open(filePath);

        //if the file doesn't open, tell the user
        if (!inFile.is_open()){
            cout << "\nFilepath does not exist, please use a valid " <<
                 "filepath.\n";
        }
    } while( !inFile.is_open());
}

string getFilepath(string fileType){
    //declare a string filePath
    string filePath;

    //prompt the user to inter the filepath they would like to choose
    cout << "Please input the file path of the " << fileType <<
    " you would like to read from: ";
    getline(cin, filePath);

    //return the filepath from the user
    return filePath;
}

void addMembersRatings(ifstream &inFile, MemberList* members,
                       RatingList* ratings){

    //declare strings for the current member and their ratings
    string member;
    int rating;
    string line;
    int currentMem = 1;

    //while there is another line in inFile, get the next line and assign it to
    //member
    while (getline(inFile, member)) {

        //assign the member to the next spot in the members array
        members->add(member);
        ratings->addMember();

        //set the current member in ratings
        ratings->setCurrentMember(currentMem);


        //if there is another line in inFile, assign the string to rating
        if (getline(inFile, line)) {
            istringstream ss(line);

            //create a bookNumber
            int bookNumber = 1;

            //while there is data in ss, write it to rating
            while(ss >> rating){

                //add each rating into the RatingList object
                ratings->add(bookNumber++, rating);

                //keep track of how many books have been added in ratings
                if(currentMem == 1){
                    ratings->addBook();
                }
            }

        //increment the current member
        currentMem++;
        }

    }
}

void addBooks(ifstream &inFile, BookList* books){

    //declare a string object for a book to be parsed
    string book;

    //declare a string object for the author name, title of the book, and the
    // year or years the book(s) were published
    string author;
    string title;
    string years;

    //step through each line of the file until there are no more lines, writing
    //each line to book
    while (getline(inFile, book)) {

        //create an istringstream object using book from getline
        istringstream ss(book);

        //parse the line into author, title, and years
        getline(ss, author, ',');
        getline(ss, title, ',');
        getline(ss, years, ',');

        //add the new book data into a new slot in the array
        books->add(title, author, years);
    }

}

string addMember(MemberList* members, RatingList* ratings){
    //ignore the stored characters
    cin.ignore();

    //declare a member name
    string memberName;

    //ask the user for the name of the member they would like to add
    cout << "Please enter the name of the member you would like to add: ";

    //take the input and add it to members
    memberName = members->add(takeInput());

    //update the number of members in ratings
    ratings->addMember();

    //return the string made by members
    return memberName;
}

string addBook(BookList* books, RatingList* ratings){
    //declare strings for the name, author and year published
    string bookName, bookAuthor, bookYear;

    //declare a stringstream object
    stringstream ss;

    //ignore the stored characters
    cin.ignore();

    //prompt and take in the name of the book or series
    cout << "Please enter the name of the book or series you would like to "
            "add: ";

    //take in the user input
    bookName = takeInput();

    //prompt and take in the name of the author
    cout << "Please enter the name of the book's author: ";
    bookAuthor = takeInput();

    //prompt and take in the year published
    cout << "Please enter the year or years the book or series was published: ";
    bookYear = takeInput();

    //add the book to the BookList object
    books->add(bookName, bookAuthor, bookYear);

    //update the number of books in ratings
    ratings->addBook();

    //send the name, author, and year published to the ss
    ss << bookName << ", " << bookAuthor << ", " << bookYear;

    //return the stringstream string
    return ss.str();

}

int addRating(BookList* books, RatingList* ratings){

    //declare ints for the rating and isbn
    int rating, isbn;

    //ignore the stored characters
    cin.ignore();

    //declare a character for skipping rating a book over
    char skipRating;

    //for formatting
    cout << "\n";

    //ask the user to enter the isbn of the book they want to rate
    do {
        cout << "Please enter the ISBN of the book in the system you "
                "would like to rate: ";

        //take in the user input
        isbn = takeIntInput();

        //do so until they enter a valid isbn
    } while (isbn <= 0 || isbn > books->size());

    //if the user entered an isbn they've already rated, ask them if they want
    // to rate it again
    if (ratings->get(isbn) != 0){
        cout << "You have already rated this book. Would you like to "
                "re-submit a rating for:\n" << books->getBookData(isbn)
                << " => rating: " << ratings->get(isbn)
                << "\n\nIf you would like to re-rate this book? (y/n): ";

        //if they enter anything other than Y or y, skip the rating
        cin >> skipRating;
        if (tolower(skipRating) != 'y'){
            return 0;
        }

    }


    //ask the user to enter a rating on the provided scale
    cout << "\nEnter a rating on the following scale:\n-5: Hated it!"
            "\n-3: Didn't like it\n1: OK - neutral opinion\n3: Liked it!"
            "\n5: Really liked it!\n\nPlease choose a valid rating: ";
    cin >> rating;

    //if they don't enter a valid input or valid rating, inform the user and
    //have them re-enter it
    while(rating != 1 && rating != 3 && rating != 5 && rating != -3 &&
    rating != -5 || !cin.good()){
        cin.clear();
        cin.ignore();
        cout << "That's not a valid input. Please choose one of the valid "
                "integers: ";
        cin >> rating;
    }

    //add the rating to the ratings
    ratings->add(isbn, rating);

    //return the number of the book they rated
    return isbn;
}

string getRatings(BookList* books, MemberList* members, RatingList* ratings) {

    //declare a stringstream object
    stringstream ss;

    //add each of the member's ratings to the stringstream, whether or not the
    // book has been rated yet
    ss <<"\n" << members->get(ratings->getCurrentMember())
    << ", your ratings are as follows:\n\n";
    for (int i = 1; i <= books->size(); i++){
        ss << books->getBookData(i) << " => rating: " << ratings->get(i)
        << endl;
    }

    //return the stringstream string
    return ss.str();

}

void login(MemberList* members, RatingList* ratings){
    //declare an int for the user number
    int userNum;

    //ask the user to input their user number and verify that it is a valid
    // number
    do {
        cout << "\nPlease enter your user number: ";
        userNum = takeIntInput();
    }while(userNum <= 0 || userNum > members->size());

    //set the current user numbers in members and ratings
    members->setCurrentMember(userNum);
    ratings->setCurrentMember(userNum);
}

string recommendBooks(BookList* books, MemberList* members,
                      RatingList* ratings){
    //declare and create sum, max, alike user integers, bad user integers,
    // and the number of books recommended
    int sum, max, alikeUser = 0, badUserInt = 0, numBooksRecd = 0;

    //create two stringstream object to hold recommendations
    stringstream ss5, ss3;

    //create an array of "bad users" that have already been run through for
    //recommendations unsuccessfully
    int* badUsers = new int[members->size()];

    //set the first bad user as the current user in the array
    badUsers[badUserInt] = ratings->getCurrentMember();

    //increment the counter used to keep track of the number of bad users
    badUserInt++;

    //if the user hasn't read any books, inform them that they must rate a book
    //to get recommendations
    if (ratings->empty()){
        return "You haven't rated any books yet!\nPlease rate a book first "
               "to get recommendations!\n";
    }

    //if the user has read all the books in the system, inform them that there
    // are no more books to read
    else if (ratings->full()){
        return "You have read all the books in our system, there are no more "
               "to recommend!\n";
    }

    do {
        //clear the stringstream objects
        ss3.str("");
        ss5.str("");

        //reset the max to 0
        max = 0;

        //loop through each of the users to compare ratings to
        for (int i = 1; i <= members->size(); i++) {
            //reset the sum to 0
            sum = 0;

            //loop through the bad users array to make sure the user should
            // be checked
            for(int k = 0; k < badUserInt; k++) {

                //if the current user to compare to is not in the bad users
                // array, start the comparison
                if (i != badUsers[k]) {

                    //add the dot product of each comparison or ratings to
                    // the sum
                    for (int j = 1; j <= books->size(); j++) {
                        sum += ratings->get(j) * ratings->get(i, j);
                    }

                    //if the sum is larger than the max, update the max value
                    // and set the alike user
                    if (sum > max) {
                        max = sum;
                        alikeUser = i;
                    }
                }
            }
        }
            //Add a string to the stringstream that tells the user what books
            // their most alike person really liked
            ss5 << "Your tastes are most similar to " << members->get(alikeUser)
            << "! They liked these books and so might you!\n\nThese are the "
               "books they really liked:\n";

            //add a string to the other stringstream telling the user what
            // books their most alike person liked
            ss3 << "\nThese are the books they liked:\n";

        //Loop through each of books ratings
        for (int i = 1; i <= books->size(); i++) {
            //if the alike user has read the book and the current user hasn't,
            // move to the switch statement
            if (ratings->get(alikeUser, i) != 0 && ratings->get(i) == 0) {

                //use a switch to choose which stringstream the book data goes
                // to
                switch (ratings->get(alikeUser, i)) {
                    case 5: {
                        ss5 << books->getBookData(i) << "\n";

                        //increment the number of books recommended
                        numBooksRecd++;
                        break;
                    }
                    case 3: {
                        ss3 << books->getBookData(i) << "\n";

                        //increment the number of books recommended
                        numBooksRecd++;
                        break;
                    }
                }
            }
        }

        //add the last alike user to the bad users array signifying that they
        // should not be gone through again
        badUsers[badUserInt] = alikeUser;

        //increment the number of bad users
        badUserInt++;

    //run the while loop while there have been no recommendations to the user
    }while (numBooksRecd == 0);

    //combine the second stringstream into the first one
    ss5 << ss3.str();

    //deallocate the bad users array
    delete[] badUsers;

    //return the string of the ss5 stringstream
    return ss5.str();
}

void logoutUser(MemberList* members, RatingList* ratings){

    //set both of the object's current users to -1 to signify no one
    members->setCurrentMember(-1);
    ratings->setCurrentMember(-1);
}
