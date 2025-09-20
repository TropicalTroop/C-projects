#include "workoutClass.hpp"

Workout::Workout(){
   name = "";
   intensity = 0;
   duration = 0;
}

Workout::Workout(std::string name, double duration, Time date, int intensity){
   this->name = name;
   this->duration = duration;
   this->date = date;
   this->intensity = intensity;
}

void Workout::addName(){
   std::cin >> name;
}

void Workout::addIntensity(){
   std::cin >> intensity;
}

void Workout::addDuration(){
   std::cin >> duration;
}

void Workout::addDate(){
   int day, month, year, second;
   std::cout << "Enter day: ";
   std::cin >> day;
   std::cout << "Enter month: "'
   std::cin >> month;
   std::cout << "Enter year: ";
   std::cin >> year;
   std::cout << "Enter seconds past midnight: ";
   std::cin >> second;
   date.update(day, month, year, second);
}
