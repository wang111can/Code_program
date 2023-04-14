#include <iostream>
#include <cstring>
#include <string>


namespace stl {
    std::string Creator_name = "Wanglaos";

    template<class T>
    class DSU {
        private:
            
    };
    class date {

    private:
        size_t _year, _month, _day;
        
    public: 
        
        date(size_t year = 1, size_t month = 1, size_t day = 1): _year(year), _month(month), _day(day) {}
        
        void reset(size_t year = 1, size_t month = 1, size_t day = 1);
        
        
        
        ~date() {}


    };

}