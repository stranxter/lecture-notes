#include <iostream>
#include <fstream>
#include "string.h"
//#include "vector.cpp"
#include <vector>
#include <cassert>


struct WordCounter
{
    String word;
    unsigned int counter;
};

void updateCounters (std::vector<WordCounter>&v, const String& w)
{
    size_t i;
    for (i = 0; i < v.size() && v[i].word != w; i++);

    if (i < v.size())
    {
        ++v[i].counter;
    } else {
        WordCounter newCounter;
        newCounter.word = w;
        newCounter.counter = 1;
        v.push_back (newCounter);
    }
}

size_t findMostCommonWord(const std::vector<WordCounter> &v)
{
    assert (v.size() > 0);

    size_t maxCounterIndex = 0;
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i].counter > v[maxCounterIndex].counter)
        {
            maxCounterIndex = i;
        }
    }

    return maxCounterIndex;
}

void simplerTest ()
{
    String s1 ("Hello"),
           s2 ("World");
    
    assert ((s1 + s2)[5] == 'W');
    std::cout << (s1 + s2);
}

int main ()
{
    std::ifstream f ("file.txt");
    std::vector<WordCounter> allWords;

    char s[100];

    while (f >> s)
    {
        std::cout << s << std::endl;
        String word (s);
        updateCounters (allWords,word);
    }

    size_t mostCommonWord = findMostCommonWord (allWords);

    std::cout << "The most common word " 
              << allWords[mostCommonWord].word
              << " has "
              << allWords[mostCommonWord].counter
              << " occurances.\n";


    simplerTest ();

}