#ifndef COURSE_H
    #define COURSE_H
    
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    class Course{
          private:
          int     ID;
          string  title;
          
          public:
          Course();
          Course( int ID , string title );
          ~Course();
          
          string getTitle();
          int getID();
          
          void print();
    };
    
#endif
