//
// File:        logentry.hpp
//
// Version:     1.0
// Date: 10/21/23
// Author: Gabe Colbrunn
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

class Date {
public:
            Date() {};
            
    void    setday   (String line) { day = line; };
    void    setmonth (String line) { month = line; };
    void    setyear  (int line)    { year = line; };
    String  getday   () const      { return day; };
    String  getmonth () const      { return month; };
    int     getyear  () const      { return year; };

private:
    String  day, month;
    int     year;
};


class Time {
  public:
            Time() { hour = 0; minute = 0; second = 0; };

    void    sethour   (int line) { hour = line; };
    void    setminute (int line) { minute = line; };
    void    setsecond (int line) { second = line; };
    int     gethour   () const   { return hour; };
    int     getminute () const   { return minute; };
    int     getsecond () const   { return second; };
    
  private:
    int     hour, minute, second;
};



class LogEntry {
public:
    String  gethost()    const { return host; };
    int     getbytes()   const { return number_of_bytes; }; 
    Date    getdate()    const { return date; };
    Time    gettime()    const { return time; };
    String  getrequest() const { return request; };
    String  getstatus()  const { return status; };

            LogEntry() {};
            LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
int                     strToInt    (String str);

#endif

