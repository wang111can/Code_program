#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>

namespace stl {

    template<class T>
    class DSU {
        private:
            
    };

// class string
    class string {
    private:
        static const int npos = -1;
        char *_str;
        size_t _size;
    public:

        // friend std::ostream& operator<<(std::ostream& os, const string &str);
        friend std::istream& operator>>(std::istream& is, stl::string &str);
        // string("xxxxxx")
        string(const char * str = "") {
            int len = std::strlen(str);
            _str = new char(len + 1);
            for (int i = 0;i < len;i ++ ) {
                _str[i] = str[i];
            }
            _str[len] = '\0';
            _size = len;
        }

        //string('x')
        string(const char ch) {
            _str = new char[1];
            _str[0] = ch;
            _str[1] = '\0';
            _size = 1;
        }

        //string(10, 'x');
        string(const int x,  const char &ch) {
            _str = new char(x + 1);
            _size = x;
            for (int i = 0;i < x;i ++ ) _str[i] = ch;
            _str[x] = '\0'; 
        }

        //string(str, 1, 5);
        string(const string &str, int begin = 0, int len = npos) {
            
            if (begin >= str._size) {
                this->_str = new char(1);
                _str[0] = '\0';
                this->_size = 0;
            }
            else {                
                int end = 0 ;
                if (len == -1) {
                    end = str._size;
                }
                else end = std::min(begin + len, (int)str._size);

                this->_size = len; 
                this->_str = new char(this->_size + 1);
                for (int i = begin;i < end;i ++ ) this->_str[i] = str._str[i];
                this->_str[_size] = '\0';
            }

            
        }

        void show() {
            std::cout << *(this->_str) << std::endl;
        }

        const int& size()const {
            return this->_size;
        }
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

        const char& operator[](const int _index) const;
        char& operator[](const int _index);



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

