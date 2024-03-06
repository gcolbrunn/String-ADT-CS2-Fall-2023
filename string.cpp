//File:        string.cpp
//
//Date:        Fall 2023
//Author:      Gabe Colbrunn
//
// Description: Implementation of the String class, representing a dynamic string in C++. 
// Each string is dynamically allocated and can be manipulated with common string operations.
//

#include "string.hpp"

// Default constructor
String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// Constructor with single character
String::String(char ch) {
    if (ch == '\0') {
        str = new char[1];
        str[0] = '\0';
        stringSize = 1;
    }
    else {
        str = new char[2];
        str[0] = ch;
        str[1] = '\0';
        stringSize = 2;
    }
}

// Constructor with character array
// Constructor with character array
String::String(const char ch[]) {
    int lengthCh = 0;
    
    // Determine the length of the input character array
    while (ch[lengthCh] != '\0') {
        lengthCh++;
    }
    
    // Allocate memory for the string, including space for the null terminator
    stringSize = lengthCh + 1; // Size includes the null terminator
    str = new char[stringSize];
    
    // Copy the characters from ch to the dynamically allocated memory
    for (int i = 0; i < lengthCh; ++i) {
        str[i] = ch[i];
    }
    str[stringSize - 1] = '\0'; // Null-terminate the string
}

String::String(const String& other) {
    stringSize = other.stringSize;
    str = new char[stringSize];
    for(int i = 0; i < other.stringSize - 1; ++i) {
        str[i] = other.str[i];
    }
    str[stringSize - 1] = '\0';
}

String::~String() {
    delete[] str;
}

void String::swap(String& other) {
    // Swap the str pointers
    char* tempStr = str;
    str = other.str;
    other.str = tempStr;
    
    // Swap the stringSize values
    int tempSize = stringSize;
    stringSize = other.stringSize;
    other.stringSize = tempSize;
}

String& String::operator=(String other) {
    swap(other);
    return *this;
}

// Max chars that can be stored 
int String::capacity() const {
    return stringSize - 1;
}

// Length of the string
int String::length() const {
    return stringSize - 1;
}

// Accessor/Modifier
char& String::operator[](int index) {
    return str[index];
}

// Accessor
char String::operator[](int index) const {
    return str[index];
}

String& String::operator+=(const String& other) {
    // Calculate the new size for the concatenated string
    int currentLen = length();  // Store the current length
    int newSize = currentLen + other.length();
    // Create a temporary array to hold the concatenated string
    char* temp = new char[newSize + 1];

    // Copy the contents of the current string
    for (int i = 0; i < currentLen; i++) {
        temp[i] = str[i];
    }

    // Copy the contents of the other string
    for (int i = 0; i < other.length(); i++) {
        temp[currentLen + i] = other[i];
    }

    // Null-terminate the concatenated string only if the current string is not empty
    if (currentLen > 0) {
        temp[newSize] = '\0';
    }

    // Deallocate the old string and update str to point to the new string
    delete[] str;
    str = temp;

    // Update the stringSize to match the new size
    stringSize = newSize + 1;

    return *this;
}

// Concatenation overload +
String operator+(String lhs, const String& rhs) {
	return lhs += rhs;
}

// Overload operator== in the String class
bool String::operator==(const String& other) const {
    int i = 0;
    while ((str[i] != '\0') && (other.str[i] != '\0') && (str[i] == other.str[i])) {
        i++;
    }

    return str[i] == other.str[i];
}

// Overload operator< in the String class
bool String::operator<(const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
	return str[i] < rhs.str[i];
}

// Substr function returns a substring from the starting to end specified positions
// REQUIRES: 0 <= start <= end < length()op;'
// ENSURESL  RetVal == str[start,...,end]
String String::substr(int start, int end) const {
    // Handle out-of-bounds indices
    if (start < 0) start = 0;
    if (start >= length()) return String(); // Return an empty string if start is out of bounds
    if (end >= length()) end = length() - 1; // Adjust the end index if it's out of bounds
    if (start > end) return String(); // Return an empty string if start > end

    int substringLength = end - start + 1;
    char* substring = new char[substringLength + 1]; // +1 for the null terminator

    for (int i = 0; i < substringLength; ++i) {
        substring[i] = str[start + i];
    }
    substring[substringLength] = '\0'; // Null-terminate the substring

    String result(substring);
    delete[] substring; // Release the dynamic memory

    return result;
}


// REQUIRES: 0 <= start < length()
// ENSRUES: RetVal; == i where str[i] == key && i >= astart
//        ||RetVal == -1 where key != str[start,...,length()-1]
int String::findch(int start, char ch) const {
	if (start < 0) start = 0;
	if (start >= length()) return -1;
	int i = start;
	while (str[i] != 0) {
		if (str[i] == ch) return i;
		++i;
	}
	return -1;
}

// Finds the location of a specified substring within the string
int String::findstr(int start, const String& subStr) const {
    if (start < 0) start = 0;
    if (start >= length()) return -1;

    int i = start;
    while (str[i] != '\0') {
        bool match = true;

        // Check if the substring matches from the current position
        for (int j = 0; subStr[j] != '\0'; j++) {
            if (str[i + j] != subStr[j]) {
                match = false;
                break; // Not a match, break the inner loop
            }
        }

        if (match) {
            return i; // Found the substring, return its position
        }

        i++;
    }

    return -1; // Substring not found, return -1
}

std::vector<String> String::split(char delimiter) const {
    std::vector<String> result;
    int start = 0;

    // Loop until there are no more delimiters
    while (true) {
        int delimiterPos = findch(start, delimiter);

        // If delimiter not found, break the loop
        if (delimiterPos == -1) {
            break;
        }

        // Extract the substring between the start and delimiter position
        String part = substr(start, delimiterPos - 1);

        // Add the part to the result vector
        result.push_back(part);

        // Update the start position to the character after the delimiter
        start = delimiterPos + 1;
    }

    // Add the remaining part after the last delimiter
    String lastPart = substr(start, length() - 1);
    result.push_back(lastPart);

    return result;
}


// Overload Input operator
std::istream& operator>>(std::istream& in, String& str) {
    char temp[256]; // Create a temporary character array to store the input data.

    // Read input from the input stream into the temporary character array.
    in >> temp;

    // Create a new String object using the data from the temporary array.
    str = String(temp);

    // Return the input stream to allow for chaining input operations.
    return in;
}


// Overload output operator
std::ostream& operator<<(std::ostream& out, const String& rhs) {
	out << rhs.str;
	return out;
}
    

//
//
// Overload operator == 
//
//
// Overload == for (const char[], const String&)
bool operator==(const char lhs[], const String& rhs) {
    String str(lhs); // Create a temporary String from the char array
    return str == rhs; // Delegate to the member function
}

// Overload == for (char, const String&)
bool operator==(char lhs, const String& rhs) {
    String str(lhs); // Create a temporary String from the character
    return str == rhs; // Delegate to the member function
}

//
//
// Overload operator < for all combinations
//
//
// Overload < for (const char[], const String&)
bool operator<(const char lhs[], const String& rhs) {
    String str(lhs); // Create a temporary String from the char array
    return str < rhs; // Delegate to the member function
}

// Overload < for (char, const String&)
bool operator<(char lhs, const String& rhs) {
    String str(lhs); // Create a temporary String from the character
    return str < rhs; // Delegate to the member function
}

//
//
// Overload <= operator 
//
//
// Overload <= for (String, String)
// Overload <= for (String, String)
bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs); // Using the previously defined < operator
}

//
//
// Overload != operator
//
//
// Overload != for (String, String)
bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs); // Using the previously defined == operator
}

//
//
// Overload >= operator
//
//
// Overload >= for (String, String)
bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs); // Using the previously defined < operator
}

//
//
// Overload > operator
//
//
// Overload > for (String, String)
bool operator>(const String& lhs, const String& rhs) {
    return rhs < lhs; // Using the previously defined < operator
}
