Registration-System
===================

Registration system which uses sorted linear doubly linked list and linear singly linked list
CS 201, Fall 2010
Homework Assignment 4
Due: 18:00, December 23, 2010

In this assignment, you will implement a simple registration system by using linked lists. The regis-
tration system stores information about students and courses. For each student, the system stores an id, first name, last name, and a list of her/his course enrollments. Each course is represented by its id and
title. This system MUST use a sorted linear doubly linked list with no dummy head node to store the
students, and for each student, a linear singly linked list with no dummy head node to store the course
enrollments for that student. The students are stored in ascending order of their ids. The courses are
stored in an unsorted list.

The registration system will have the following functionalities; the details of these functionalities are
given below:

1. Add a student
2. Delete a student
3. Add a course for a student
4. Withdraw a student from a course
5. Cancel a course
6. Show detailed information about a particular student
7. Show detailed information about a particular course
8. Show all students

class RegistrationSystem { 

public:

RegistrationSystem();

~RegistrationSystem();

void addStudent( const int studentId, const string firstName, const string lastName );

void deleteStudent( const int studentId

int addCourse( const int studentId, const int courseId, const string courseName );

void withdrawCourse( const int studentId, const int courseId );

void cancelCourse( const int courseId );

void showStudent( const int studentId );

void showCourse( const int courseId );

void showAllStudents();

};


 
