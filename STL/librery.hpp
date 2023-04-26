#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <assert.h>
#include <climits>


#ifndef LIBRERY_HPP
#define LIBRERY_HPP


namespace stl {

    template<class T>
    class DSU {
        private:
            
    };

// class string
    class string {
    private:
        static const size_t npos;
        char *_str;
        size_t _size;
        size_t _capacity;
    public:

        // friend std::ostream& operator<<(std::ostream& os, const string &str);
        friend std::istream& operator>>(std::istream& is, stl::string &str);
        typedef char* iterator;
        iterator begin() {
            return _str;
        }
        iterator end() {
            return _str + _size;
        }

        string() {
            _str = new char[1];
            _size = 0;
            _str[0] = '\0';
            _capacity = 1;

        }
        string(const string& str, size_t begin = 0, size_t len = npos) {
                        printf("str\n");
            size_t l = begin, r = len;
            if (len == npos) {
                r = str.size();
            }
            else r = std::min(str.size(), r);

            assert(l <= r);
            _str = new char[r - l + 1];
            _size = r - l;
            _capacity = r - l + 1;
            for (size_t i = l, j = 0;i < r;j ++ , i ++ ) {
                _str[j] = str[i];
            }
            _str[_size] = '\0';
        }

        string(const char* str, size_t len = npos) {
            int sz = 0;
            printf("char*\n");
            if (len == npos) sz = strlen(str);
            else sz = std::min(strlen(str), npos);
            _str = new char[sz + 1];

            for (size_t i = 0;i < sz;i ++ ) {
                _str[i] = str[i];
            }
            _str[sz] = '\0'; 
            _size = sz;
            _capacity = sz + 1;
        
        }

        // string(size_t n, char ch) {

        // }


        void show() {
            std::cout << (this->_str) << std::endl;
        }

        const size_t& size()const {
            return this->_size;
        }

        string& insert(size_t pos, const string &str);
        string& insert(size_t pos, const string &str, size_t begin, int len = npos);
        string& insert(size_t pos, const char* str);
        string& insert(size_t pos, const char* str, int len = npos);
        
        

        // string.substr(1, 3)
        string substr(const int begin,const int len);

        string operator=(const string& str);
        string operator=(const char * str);
        string operator=(const char ch);

        string operator+(const string& str);
        string operator+(const char* str);
        string operator+(const char ch);

        string& operator+=(const string& str);
        string& operator+=(const char *str);
        string& operator+=(const char ch);

        char& back();
        char& front();
        void pop_back();
        void push_back(const char ch);
        void append(const char *str);
        void append(const char ch);
        int find(const char ch);

        const char& operator[](const size_t _index) const;
        char& operator[](const size_t _index);



        ~string() {
            delete[] _str;
        }
        

    };


// end  

// class date 
    class date {

    private:
        int _year, _month, _day;

    public: 
        friend std::ostream& operator<<(std::ostream& os, const date& d);
        date(int year = 1, int month = 1, int day = 1) {
            day = std::max(1, day);
 
            year = std::max(1, year);
            month = std::max(1, month);
            if (month == 2) {       
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ) {
                    day = std::min(29, day);
                }
                else day = std::min(28, day);
            }
            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) day = std::min(31, day);
            else day = std::min(30, day);
            month = std::min(12, month);
            _year = year;
            _day  = day;
            _month = month;
        }


        date(const date& d): _year(d._year),  _month(d._month), _day(d._day) { }
        

        date operator=(const date& d);
        date operator+(int increasement);
        date& operator+=(int increasement);
        date operator-(int decrease);
        int operator-(const date& d);
        date& operator-=(int decrease);
        date& operator++(); // 前置 ++ 
        date operator++(int); // 后置 ++ 
        date& operator--(); // 前置 -- 
        date operator--(int); // 后置 -- 

        date* operator&() {
            return this;
        }
        const date* operator&() const{
            return this;
        }

        void show();


        
        bool operator<(const date& d) const;
        bool operator<=(const date& d) const;
        bool operator==(const date& d) const;
        bool operator>(const date& d) const;
        bool operator>=(const date& d) const;
        
        ~date() {}
    };
// class date end
} 


#endif