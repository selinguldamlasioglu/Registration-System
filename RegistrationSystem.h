#ifndef REGISTRATION_SYSTEM_H

  #define REGISTRATION_SYSTEM_H
  
  #include "SortedDoublyList.h"
  #include <string>
  
  using namespace std;
  
    class RegistrationSystem {
          
          private:
          SortedDoublyList students;
          
          public:
          RegistrationSystem(){}
          ~RegistrationSystem(){}
          
          void addStudent( const int studentId, const string firstName, const string lastName );
          void deleteStudent( const int studentId );
          void addCourse( const int studentId, const int courseId, const string courseName );
          void withdrawCourse( const int studentId, const int courseId );
          void cancelCourse( const int courseId );
          
          void showStudent( const int studentId );
          void showCourse( const int courseId );
          void showAllStudents();
    };

#endif
