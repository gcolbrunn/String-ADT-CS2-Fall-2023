//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date: 10/21/23
// Author: Gabe Colbrunn
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////
// REQUIRES: A String object
// ENSURES: Turns string with # chars into an integer
int strToInt(String str) {
    int result = 0;

    // Iterate through each character in the String.
    for (int i = 0; i < str.length(); ++i) {
        // Update the result by multiplying it by 10 and adding the numeric value of the current character.
        result = (result * 10) + (str[i] - '0');
    }

    // Return the resulting integer value.
    return result;
}

////////////////////////////////////////////////////////////////////////////
// REQUIRES: Input String 's' follows a specific format with 10 valid fields.
// ENSURES:  Constructs a LogEntry object with parsed data from 's' or a blank object with default values if the format is invalid.
LogEntry::LogEntry(String s) {

// 131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625

    // Split the input String into fields using whitespace as a delimiter.
    std::vector<String> vec = s.split(' ');

    // Check if there are exactly 10 fields in the log entry
    if (vec.size() != 10) {
        // If not, store a blank logEntry
        host = "";
        date.setday("");
        date.setmonth("");
        date.setyear(0);
        time.sethour(0);
        time.setminute(0);
        time.setsecond(0);
        request = "";
        status = "";
        number_of_bytes = 0;
    } else {
        // 131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625
        host = vec[0];        
        // tempVec = vec[3] = [18/Sep/2002:12:05:25
        // tempVec[1] = 18/Sep/2002:12:05:25
        std::vector<String> tempVec = vec[3].split('[');
        std::vector<String> dateVec = tempVec[1].split('/');
        date.setday(dateVec[0]);
        date.setmonth(dateVec[1]);
        // timeVec = dateVec[2] = 2002:12:05:25
        std::vector<String> timeVec = dateVec[2].split(':');
        date.setyear(strToInt(timeVec[0])); // timeVec[0] = 2002 
        time.sethour(strToInt(timeVec[1]));
        time.setminute(strToInt(timeVec[2])); 
        time.setsecond(strToInt(timeVec[3]));
        
        request = vec[5] + vec[6] + vec[7];
        status = vec[8];
        int num = strToInt(vec[9]);
        if (num >= 0) {
            number_of_bytes = num;
        }
        else {
            number_of_bytes = 0;
        }
    }
}

////////////////////////////////////////////////////////////////////////////
// REQUIRES: The input stream 'in' is properly initialized and points to a valid log file.
// ENSURES: Parses log entries from the input stream and returns a vector of LogEntry objects.
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char* temp = new char[200];

    // Continue reading lines from 'in' until the end of the file is reached.
    while (in.eof() == false) {
        // Read the next line (up to 200 characters) from 'in' into the 'temp' buffer.
        in.getline(temp, 200);
        
        // Convert the line to a String object.
        String str(temp);

        // Create a LogEntry object from the String representation.
        LogEntry entry(str);
        
        // Add the LogEntry to the result vector.
        result.push_back(entry);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////
// REQUIRES: Properly initialized output stream 'out' and a vector 'entries' with valid LogEntry data.
// ENSURES:  Outputs LogEntry objects to 'out' if their 'status' is not empty, separated by newlines.
void output_all(std::ostream& out, const std::vector<LogEntry>& entries) {
    int size = entries.size();

    // Iterate through the LogEntry objects in the 'entries' vector
    for (int i = 0; i < size; ++i) {
        // Check if the 'status' field of the LogEntry is not empty
        if (entries[i].getstatus() != "") {
            // Print the LogEntry to the 'out' stream, followed by a newline character
            out << entries[i] << std::endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////
// REQUIRES: Properly initialized output stream 'out' and a vector 'entries' with valid LogEntry data.
// ENSURES: Writes the 'host' member of each LogEntry to 'out,' one per line, creating a formatted output.
void by_host(std::ostream& out, const std::vector<LogEntry>& entries) {
    int size = entries.size();

    // Iterate through the LogEntry objects in the 'entries' vector
    for (int i = 0; i < size; ++i) {
        // Access and print the 'host' member of each LogEntry to the 'out' stream, followed by a newline character
        const LogEntry& entry = entries[i];
        out << entry.gethost() << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////
// REQUIRES: A vector 'entries' with valid LogEntry data.
// ENSURES:  Calculates and returns the total number of bytes in all LogEntry objects within 'entries.'
int byte_count(const std::vector<LogEntry>& entries) {
    int totalBytes = 0;
    int size = entries.size();

    // Iterate through the LogEntry objects in the 'entries' vector
    for (int i = 0; i < size; ++i) {
        // Add the 'bytes' member of each LogEntry to the 'totalBytes' sum
        totalBytes += entries[i].getbytes();
    }

    return totalBytes;
}

////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.getmonth() << " " << date.getday() << ", " << date.getyear();
    return out;
}

////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << time.gethour() << ":" << time.getminute() << ":" << time.getsecond();
    return out;
}

////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
    out << log.getstatus() << " " << log.gethost() << " made request " << log.getrequest() << " at " << log.gettime() << " on " << log.getdate() << " and received " << log.getbytes() << " bytes.";
    return out;
}





