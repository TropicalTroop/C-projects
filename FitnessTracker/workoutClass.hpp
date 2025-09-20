/* Definition for Workout Class
Atharva Sonune 09/14/25 */
#include <iostream>
#include "timeClass.hpp"

#ifndef workoutClass
#define workoutClass

class Workout 
public:
   Workout();
   Workout(std::string, double, Time, int);
   void addCondition();
   void addName();
   void addDate();
   void addDuration();

   std::string getWorkout;

private:
   std::string name;
   int intensity;
   double duration;
   Time date;
};

#endif
