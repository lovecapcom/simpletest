#pragma once
#include <iostream>
#include <cstring>


class MyString
{
private:
     char * str;             // pointer to string
     int len;                // length of string
     static int num_strings; // String类对象数量
     static const int CINLIM = 80;  // cin input limit   输入限制
 public:
 // constructors and other methods
     MyString(const char* c); // constructor
     MyString();               // default constructor
     MyString(const MyString& s); // copy constructor
     ~MyString();              // destructor
     int length () const { return len; }
     int size() const { return len; }
 // overloaded operator methods    
     MyString& operator=(const MyString& s);
     MyString& operator=(const char* c);
     char& operator[](int i);
     const char& operator[](int i) const;
     MyString& operator+(const MyString& st);
     MyString& operator+(const char* s);
 // overloaded operator friends
     friend bool operator<(const MyString& st, const MyString& st2);
     friend bool operator>(const MyString& st1, const MyString& st2);
     friend bool operator==(const MyString& st, const MyString& st2);
     friend bool operator==(const MyString& st, const char* st2);
     friend std::ostream & operator<<(std::ostream& os, const MyString& st);
     friend std::istream & operator>>(std::istream& is, MyString& st);
 // static function
     static int HowMany();
 public:
     //功能函数
     void append(const MyString& st);  //追加字符串
     void append(const char* s);      //追加字符串
     void push_back(const char ch);  //追加字符
     void swap(char* s);             //交换值
     void swap(MyString& st);          //交换值
     int find(const char*s, std::size_t index);   //寻找字符串
     int find(const MyString& st, std::size_t index);//寻找字符串
 };
