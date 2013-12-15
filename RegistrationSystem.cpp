#include "RegistrationSystem.h"

void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName ){
     if( !students.add( * new Student(studentId, firstName, lastName) ) ){
         cout << "Student " << studentId << " already exists" << endl;
     }else cout << "Student " << studentId << " is added" << endl;
}

void RegistrationSystem::deleteStudent( const int studentId ){
     if( !students.remove( *new Student( studentId,"","") ) ){
         cout << "Student " << studentId << " does not exist" << endl;
     }else cout << "Student " << studentId << " has been deleted" << endl;
}

void RegistrationSystem::showAllStudents(){
     if( students.getLength() == 0 ){
         cout << "There are no students in the system" << endl;
     }
     else{
         cout << "All Students: " << endl;
         cout << "ID\t\tFirst Name\tLast Name" << endl;
         for( int i=1; i<=students.getLength(); i++ ){
              Student *s;
              students.retrieve(i,&s);
              s->print();
         }
     }
}

void RegistrationSystem::showStudent( const int studentId ){
     cout << "Student info " << endl;
     cout << "ID\t\tFirst Name\tLast Name" << endl;
     int ind;
     if(    (ind = students.find( *new Student(studentId,"","") ))  != -1     ){
            Student *s;
            students.retrieve(ind,&s);
            s->print();
     }
     else{
           cout << "Student " << studentId << " does not exist" << endl;
     }
}



void RegistrationSystem::addCourse( const int studentId, const int courseId, const string courseName ){
     int ind;
     if( (ind = students.find( *new Student(studentId,"","") ))  != -1 ){
            Student *s;
            students.retrieve(ind,&s);
            Course c(courseId, courseName);
            if( !(s->addCourse(c)) ) cout << "Student " << studentId << " is already enrolled in course " 
                                          << courseId << endl;
            else cout << "Student " << studentId << " has been enrolled in course " 
                      << courseId << endl;
     }
     else{
           cout << "Student " << studentId << " does not exist" << endl;
     }
}




void RegistrationSystem::withdrawCourse( const int studentId, const int courseId ){
     int ind;
     if( (ind = students.find( *new Student(studentId,"","") ))  != -1 ){
            Student *s;
            students.retrieve(ind,&s);
            if( !(s->removeCourse(courseId)) ) cout << "Student " << studentId << " is not enrolled in course " 
                                          << courseId << endl;
            else cout << "Course " << courseId << " has been removed from courses of student " 
                      << studentId << endl;
     }
     else{
           cout << "Student " << studentId << " does not exist" << endl;
     }
}

void RegistrationSystem::cancelCourse( const int courseId ){
     bool flag = false;
     for( int i=1; i<=students.getLength(); i++ ){
              Student *s;
              students.retrieve(i,&s);
              if( s->removeCourse(courseId) ) flag = true;
              
     }
     if( !flag ) cout << "There is no course with course id " << courseId << endl;
     else cout << "Course " << courseId << " has been canceled\n";
}
          

void RegistrationSystem::showCourse( const int courseId ){
     
     bool firstTime = true;
     for( int i=1; i<=students.getLength(); i++ ){
              Student *s;
              students.retrieve(i,&s);
              if( s->hasCourse(courseId) ) {
                  if( firstTime ){
                      cout << "Student id\tFirst name\tSecond name\n";
                      firstTime = false; 
                  }
                  cout << s->getID() << "\t\t" << s->getFirstName() << "\t" << s->getLastName() << endl;
              }
     }
     if( firstTime == true ){
         cout << "There is no course with id " << courseId << endl;
     }
}
          
