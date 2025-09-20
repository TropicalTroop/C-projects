/* Date and Time Class
Atharva Sonune 09/14/25 */
#include <iostream>
#include <string>

#ifndef timeClass
#define timeClass

class Time{
public:
   Time();
   Time(int, int, int, int);
   std::string formattedDate();
   std::string formatTime();
   void update(int, int, int, int);
private:
   int second;
   int year;
   int month;
   int day;
};

#endif

