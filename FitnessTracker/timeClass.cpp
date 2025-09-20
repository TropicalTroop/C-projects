#include "timeClass.hpp"

Time::Time(){
   year = 0;
   month = 0;
   day = 0;
   second = 0;
}

Time::Time(int year, int month, int day, int second){
   this->year = year;
   this->month = month;
   this->day = day;
   this->second = second;
};

void Time::update(int day, int month, int year, int second){
   this->year = year;
   this->month = month;
   this->day = day;
   this->second = second;
};

std::string Time::formattedDate(){
   std::string date;
   std::string monthString;

   switch(month){
   case 1:
      monthString = "January";
   case 2:
      monthString = "February";
   case 3:
      monthString = "March";
   case 4:
      monthString = "April";
   case 5:
      monthString = "May";
   case 6:
      monthString = "June";
   case 7:
      monthString = "July";
   case 8:
      monthString = "August";
   case 9:
      monthString = "September";
   case 10:
      monthString = "October";
   case 11:
      monthString = "November";
   case 12:
      monthString = "December";
   }
/*
   switch(day){
   case 1:
      dayString = "Sunday";
   case 2:
      dayString = "Monday";
   case 3:
      dayString = "Tuesday";
   case 4:
      dayString = "Wednesday";
   case 5:
      dayString = "Thursday";
   case 6:
      dayString = "Friday";
   case 7:
      dayString = "Saturday";
   }
*/

   std::string dayString = std::to_string(day);
   std::string yearString = std::to_string(year);

   date = monthString + " " + dayString + " " + yearString;

   date += " " + this->formatTime();
   return date;
}

std::string Time::formatTime(){
   int hour, minute, tempSeconds;
   std::string formattedTime;

   hour = second/3600;
   minute = (second%3600)/60;
   tempSeconds = (second%3600)%60;

   formattedTime = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(tempSeconds);

   return formattedTime;
}

