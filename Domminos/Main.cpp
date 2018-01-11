//
//potentially handy includes - google the C++ documentation for details
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
 
using namespace std;
 
// FOR ALL THE FUNCTION DECLARATIONS BELOW, YOU MAY USE VECTORS INSTEAD OF LISTS BUT BEAR IN MIND THE DIFFERENCE IN EFFICIENCY MAY REQUIRE YOU TO ALTER THE IMPLEMENTATION A BIT
 
/*
This function reads a file and stores each line in a list of strings, you should use <fstream> to achieve this
@param  l: the list of strings
@param  s: the filename
@return true if the file was read successfully, false otherwise
*/
void readFile(list<string>& l, string fileName)
{
    ifstream file(fileName);
    string line;
 
 
    while (getline(file, line))
    {
        l.push_back(line);
    }
 
 
 
 
 
}
string toLower(string in) //makes string lower case
{
    string firstLower;
    for (int i = 0; i < in.length(); ++i) {
        firstLower += tolower(in[i]);
    }
    return firstLower;
}
 
/*
This function returns true if a specified string is contained in a list
@param  l: the list of strings
@param  s: the string to be checked
@return true if s is a member of l, false otherwise
*/
 
bool isIn(list<string> l, string s)
{
    for (string word : l)
    {
       
        if (toLower(s) == toLower(word))
            return true;
 
 
    }
    return false;
 
}

 
/*
This function returns true if the last letter of one string matches the first letter of another
@param  first:  the string whose first character is to be checked
@param  last:   the string whose last character to be checked
@return true if first and last characteras are equal, regardless of case
*/
 
bool match(string first, string last)
{
 
    if (last.empty()) { return true; }
    string firstLower = toLower(first);
    string lastLower = toLower(last);
 
    return firstLower[0] == lastLower[lastLower.length() - 1];
 
 
 
}

bool hasWordsLeft(list<string>l, string lastWord)
{
	for (string s : l)
	{
		if (match(s, lastWord))
		{
			return true;
		}
	}
	return false;
}


void erase(list<string> &l, string s)
{
	string sLower = toLower(s);

	for (auto i = l.begin(); i != l.end(); i++)
	{
		string iLower = toLower(*i);

		if (iLower == sLower)
		{
			l.erase(i);
			break;
		}
	}
}

void turn (string player, list<string> &words, string &lastWord)
{
    string playerWord = "";

	while (true)
    {
        cout << "Okay " << player << " please enter your element" << endl;
        getline(cin, playerWord);
 
        bool in = isIn(words, playerWord);
        bool isMatch = match(playerWord, lastWord);
 
 
        if (in  && isMatch)
        {
            cout << "Next move" << endl;
			erase(words, playerWord);
            break;
        }
        else
        {
			cout << "Please enter a correct element" << endl;
        }
    }
 
	
    lastWord = playerWord;
}
 

 
 
 
 
 
//insert program here...
int main()
{
 
    list<string> words;
    readFile(words, "Elements.txt");
 
   
    cout << "Hello player One please enter your name" << endl;
    string playerOne = "";
    getline(cin, playerOne);
 
 
    cout << "Hello player Two please enter your name" << endl;
    string playerTwo = "";
    getline(cin, playerTwo);
 
 
 
    bool playerOneTurn = true;
    string lastWrod;
    while (true)
    {
		if (playerOneTurn)
        {
			if (!hasWordsLeft(words, lastWrod))
			{
				cout << "You lost " << playerOne << endl;
				break;
			}
			turn(playerOne, words, lastWrod);
 
        }
        else
        {
			if (!hasWordsLeft(words, lastWrod))
			{
				cout << "You lost " << playerTwo << endl;
				break;
			}
            turn(playerTwo, words, lastWrod);
        }
        playerOneTurn = !playerOneTurn;
    }
 
   
   
   
   
   
    system("pause");
 
    return 0;
}
