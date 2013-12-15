#include "Course.h"  

Course::Course( ){
   this->ID = 0;
   this->title = *new string("");
}

Course::~Course(){}

Course::Course( int ID = 0, string title = *new string("")){
      this->ID = ID;
      this->title = title;
}

string Course::getTitle(){
       return this->title;
}

int Course::getID(){
       return this->ID;
}
            
void Course::print(){
     cout << "\t" << ID << "\t\t" << title << endl;
}
