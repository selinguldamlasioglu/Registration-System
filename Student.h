#ifndef STUDENT_H
    #define STUDENT_H
    
    #include <iostream>
    #include <string>
    #include "SinglyList.h"
    
    using namespace std;
    
    class Student{
          
          private:
          int     ID;
          string  firstname;
          string  lastname;
          SinglyList courses;
          
          public:
          Student( int ID, string firstname, string lastname );
          Student(){}
          
          int getID(){return ID;}
          string getFirstName(){return firstname;}
          string getLastName(){return lastname;}
          
          bool addCourse( Course c );
          bool hasCourse( const int courseId );
          bool removeCourse(const int courseId);
          void print();
               
    };
    
#endif
