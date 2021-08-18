#include "mystring.h"



int MyString::num_strings = 0;

 // static method
 int MyString::HowMany()
 {
     return num_strings;
 }

 void MyString::append(const MyString& st)
 {
     strcat(this->str, st.str);
     this->len = strlen(this->str);
     return;
 }

 void MyString::append(const char* s)
 {
     strcat(this->str, s);
     this->len = strlen(this->str);
     return;
 }

 void MyString::push_back(const char ch)
 {
     strcat(this->str, &ch);
     this->len = strlen(this->str);
     return;
 }

 void MyString::swap(char* s)
 {
     char temp[CINLIM];
     strcpy(temp, this->str);
     strcpy(this->str,s);
     strcpy(s, temp);
     this->len = strlen(this->str);
     return;
 }

 void MyString::swap(MyString& st)
 {
     char temp[CINLIM];
     strcpy(temp, this->str);
     strcpy(this->str, st.str);
     strcpy(st.str, temp);
     this->len = strlen(this->str);
     st.len = strlen(st.str);
     return;
 }

 int MyString::find(const char* s, std::size_t index)
 {
     int length = strlen(s);
     for (int this_index = index; this_index < this->len; this_index++)
     {
         if (this->str[this_index] == s[0])
         {
             for (int s_index = 0; s_index < length; s_index++)
             {
                 if (this->str[this_index + s_index] != s[s_index])
                     break;
                 if (s_index == length - 1)  //匹配字符串
                     return this_index;
             }
         }
     }
     return -1;
 }

 int MyString::find(const MyString& st, std::size_t index)
 {
     int length = strlen(st.str);
     for (int this_index = index; this_index < this->len; this_index++)
     {
         if (this->str[this_index] == st.str[0])
         {
             for (int s_index = 0; s_index < length; s_index++)
             {
                 if (this->str[this_index + s_index] != st.str[s_index])
                     break;
                 if (s_index == length - 1)  //匹配字符串
                     return this_index;
             }
         }
     }
     return -1;
 }

 // class methods
 MyString::MyString(const char* s)     // construct String from C string
 {
     len = std::strlen(s);          // set size
     str = new char[len + 1];       // allot storage
     std::strcpy(str, s);           // initialize pointer
     num_strings++;                 // set object count
 }

 MyString::MyString()                   // default constructor
 {
     len = 4;
     str = new char[1];
     str[0] = '\0';                 // default string
     num_strings++;
 }

 MyString::MyString(const MyString& st)
 {
     num_strings++;             // handle static member update
     len = st.len;              // same length
     str = new char [len + 1];  // allot space
     std::strcpy(str, st.str);  // copy string to new location
 }

 MyString::~MyString()                     // necessary destructor
 {
     --num_strings;                    // required
     delete [] str;                    // required
 }

 // overloaded operator methods    

 // assign a String to a String
 MyString& MyString::operator=(const MyString& st)
 {
     if (this == &st)
         return *this;
     delete [] str;
     len = st.len;
     str = new char[len + 1];
     std::strcpy(str, st.str);
     return *this;
 }

 // assign a C string to a String
 MyString& MyString::operator=(const char* s)
 {
     delete [] str;
     len = std::strlen(s);
     str = new char[len + 1];
     std::strcpy(str, s);
     return *this;
}
 // read-write char access for non-const String
 char& MyString::operator[](int i)
 {
     return str[i];
 }

 // read-only char access for const String
 const char& MyString::operator[](int i) const
 {
     return str[i];
 }

 MyString& MyString::operator+(const MyString& st)
 {
     // TODO: 在此处插入 return 语句
     strcat(this->str, st.str);
     return *this;
 }

 MyString& MyString::operator+(const char * s)
 {
     // TODO: 在此处插入 return 语句
     strcat(this->str, s);
     return *this;
 }

 // overloaded operator friends

 bool operator<(const MyString& st1, const MyString& st2)
 {
     return (std::strcmp(st1.str, st2.str) < 0);
 }

 bool operator>(const MyString& st1, const MyString& st2)
 {
     return st2 < st1;
 }

 bool operator==(const MyString& st1, const MyString& st2)
 {
     return (std::strcmp(st1.str, st2.str) == 0);
 }

 bool operator==(const MyString& st, const char* st2)
 {
     return (std::strcmp(st.str, st2) == 0);
 }

 // simple String output
 std::ostream& operator<<(std::ostream& os, const MyString& st)
 {
     os << st.str;
     return os; 
 }

     // quick and dirty String input
 std::istream& operator>>(std::istream& is, MyString& st)
 {
     char temp[MyString::CINLIM];
     is.get(temp, MyString::CINLIM);
     if (is)
         st = temp;
     while (is && is.get() != '\n')
         continue;
     return is; 
 }
