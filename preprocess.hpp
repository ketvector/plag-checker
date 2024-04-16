#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include<algorithm>
#include<boost/regex.hpp>
#include<utility>
using namespace std;
// Function Prototypes

// ReadInputFiles reads the Program for which we want to create the fingerprint into memory
string readInputFile(char* inputFile);

// readList will be used to read the keyword and noId words into memory.Read list will be used to read the comment initiators.
unordered_set<string> readList(char* keywords);
vector<string> readListV(char* file);

// function to convery a string to lowercase
void lowerCase(string& a);

// function to strip the file off all comments and store them into a vetor
vector<string> collectComments( string& a ,vector<string>& single , vector<string>& multi);

// function to create whitespace between punctuation symbols
void createSpace(string& a);

// function to replace all identifiers with "v"
string removeIdentifiers(string &a , unordered_set<string>& noId , unordered_set<string>& keywords );

// function to remove all non-newline whitespace from the file
void removeWhiteSpace(string& a);

// helper functions
string trim(string& str,const std::string& whitespace = " \t"); //trim a line off leading and trailing whitespace
vector<string> splitString(string& a); // split a line on whitespaces
void replaceAll(std::string& str, const std::string& from, const std::string& to) ; //replace a substring by another

