#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

namespace stl {

    template<class T>
    class DSU {
        private:
            
    };


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
        void show();


        
        bool operator<(const date& d);
        bool operator<=(const date& d);
        bool operator==(const date& d);
        bool operator>(const date& d);
        bool operator>=(const date& d);
        
        ~date() {}
    };
// class date end
} 