#pragma once

#include <functional>

class IntRange
{
    public:
    int start, finish;
    std::function<bool(int)> filter;

    class Iterator
    {
        public:
        Iterator(int, int, std::function<bool(int)>);

        int operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator&) const;

        private:
        int current, finish;
        std::function<bool(int)> filter;

    };

    Iterator begin();
    Iterator end();


};