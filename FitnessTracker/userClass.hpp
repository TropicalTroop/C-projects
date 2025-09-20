/* Class Definition for the User 
Atharva Sonune 09/14/25 */

#ifndef userClass
#define userClass

#include <iostream>
#include "workoutClass.hpp"

class User{
public:
   User();
   User(std::string, double, double, double):
   addWorkout();
private:
   std::string name;
   double age;
   double weight;
   double height;
}

#endif
