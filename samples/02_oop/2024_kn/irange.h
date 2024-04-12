#pragma once

#include <functional>

class IRange
{
    private:
    int start;
    int finish;
    std::function<bool(int)> filter;

    public:

    using value_type = int;

    IRange(int,int,std::function<bool(int)>);

    class Iterator
    {
        public:

        Iterator(int,int,std::function<bool(int)>);

        Iterator& operator++();
        int operator*();
        bool operator !=(const Iterator&);

        private:
        int current;
        std::function<bool(int)> filter;
        int finish;

    };

    Iterator begin();
    Iterator end();

};