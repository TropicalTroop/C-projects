
#include "userClass.hpp"

User::User(){
   name = "";
   age = 0;
   weight = 0;
   height = 0;
}

User::User(std::string name, double age, double weight, double height){
   this->name = name;
   this->age = age;
   this->weight = weight;
   this->height = height;
}

void User::addWorkout(){
   Workout newWorkout;
   std::cout << "You will now enter workout details." << endl;
   std::cout << "Please Enter Name of Workout: ";
   newWorkout.addName();
   std::cout << "Please Enter Intensity from 1 to 5: ";
   newWorkout.addIntensity();
   std::cout << "Please Enter Duration in Minutes: ";
   newWorkout.addDuration();
   std::cout << "Date of Workout: ";
   newWorkout.addDate();
}
