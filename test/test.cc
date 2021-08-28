#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include "../so1/mystring.h"
#include "../so1/myhashmap.hpp"


class Basic {
public:
    Basic(const std::string str, int i = 0) : name(str), count(i) {
        std::cout << this->name << " constructure invoked!" << std::endl;
     }
    Basic(const Basic& b) { this->name = b.name; }
    Basic& add() {
        this->count++;
        return *this;
    }
    int getCount() {
        return this->count;
    }
    ~Basic() { 
        std::cout << this->name << " destructure invoded!" << std::endl;
    }
private:
    std::string name;
    int count;
};

const double PI = 3.14;

double area(double radius) {
    return PI * radius * radius;
}

double circumference(double radius) {
    return PI * radius * 2;
}

int main() {
    
//    MyString s1 = "123";
//    MyString s2("abc");
//    MyString* s3 = new MyString("xyz");
//     //赋值
//    s1 = s2;   //相比C strcpy 更方便
//     //比较
//    if (s1 == s2)
//    {
//        std::cout << "s1 = s2" << std::endl;
//    }
//    std::cout << "===========拼接字符串============" << std::endl;
//    s1 = s1 + "456";
//    std::cout << s1 << std::endl;
//    s1.append("789");
//    std::cout << s1 << std::endl;
//    s1.push_back('!');
//    std::cout << s1 << std::endl;
//    //交换
//    std::cout << s1 << " " << s2 << std::endl;
//    std::cout << "===========交换字符串============" << std::endl;
//    s1.swap(s2);
//    std::cout << s1 << " " << s2 << std::endl;
//    //字符串长度
//    std::cout << s2.size() << std::endl;
//    //查找 替换
//
//    std::cout << "===========寻找字符串============" << std::endl << s2.find("456", 0) << std::endl;


//	MyHashMap<std::string, std::string, HashFunc, EqualKey> hashmap(100);
//
//    hashmap.insert("hello", "world");
//    hashmap.insert("why", "dream");
//    hashmap.insert("c++", "good");
//    hashmap.insert("welcome", "haha");
//
//    
//    std::cout << "after insert:" << std::endl;
//    std::cout << hashmap.find("welcome").c_str() << std::endl;
//    std::cout << hashmap.find("c++").c_str() << std::endl;
//    std::cout << hashmap["why"].c_str() << std::endl;
//    std::cout << hashmap["hello"].c_str() << std::endl;
//
//    if (hashmap.del("hello"))
//        std::cout << "remove is ok" << std::endl;    //remove is ok
//    std::cout << hashmap.find("hello").c_str() << std::endl; //not exist print NULL
//
//    hashmap["why"] = "love";
//    std::cout << hashmap["why"].c_str() << std::endl;

    
    int a = 0;
    int b = a + 1 + 1;
    std::cout << b << std::endl;

    return 0;
}
