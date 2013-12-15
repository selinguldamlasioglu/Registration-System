#include "Student.h"

Student::Student( int ID, string firstname, string lastname ){
     this->ID = ID;
     this->firstname = firstname;
     this->lastname = lastname;
}
                   
bool Student::addCourse( Course c ){
     return courses.insert(c);
}

bool Student::removeCourse(const int courseId){
     return courses.remove(*new Course(courseId,""));
}
     
// Prints all the information about the student object
void Student::print(){
     cout << ID << "\t\t" << firstname << "\t\t" << lastname << endl;
     
     if( courses.getLength() == 0 ){
     }else
     {
          cout << endl << "\tEnrolled Courses: " << endl;
          cout << "\tCourse ID\tCourse Name\n";
          for( int i=1; i<=courses.getLength(); i++ ){
               Course c;
               courses.retrieve(i,c);
               c.print();
          }
          cout << endl << endl;
     }
}

bool Student::hasCourse(const int courseId){
     for( int i=1; i<=courses.getLength(); i++ ){
          Course c;
          courses.retrieve(i,c);
          if( c.getID() == courseId ) return true;
     }
     return false;
}
