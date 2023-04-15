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
        size_t _year, _month, _day;

    public: 
        
        date(size_t year = 1, size_t month = 1, size_t day = 1): _year(year), _month(month), _day(day) {}
        date(const date& d): _year(d._year),  _month(d._month), _day(d._day) { }
        

        void operator=(const date& d);
        date operator+(int increasement);
        date& operator+=(int increasement);
        date operator-(int decrease);
        int operator-(const date& d);
        date& operator-=(int decrease);

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