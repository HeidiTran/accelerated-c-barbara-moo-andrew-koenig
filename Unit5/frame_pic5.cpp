//This program draw a character-picture
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// find the length of the longest string in the vector
string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back( "* " + v[i] + 
			string(maxlen - v[i].size(), ' ') + " *");
	}

	// write the bottom border 
	ret.push_back(border);
	return ret;
}

int main()
{
	string s;

	//vector<string> message = { "LUCK", "Is what happens", "When", "Preparation meets Opportunity!" };
	vector<string> message;

	// Take input by get line
	while (getline(cin, s))
	{
		message.push_back(s);
	}

	vector<string> pic = frame(message);

	// print results
	for (vector<string>::size_type i = 0; i < pic.size(); i++)
	{
		cout << pic[i] << endl;
	}

	cout << endl;

	return 0;
}