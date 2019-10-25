#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "dllist.h"
#include "dllist.cpp"
#include "slist.cpp"
#include <ctime>

TEST_CASE("Insertion test")
{
    DLList<int> test;
    CHECK(test.insertAt(10,10)==false);
    CHECK(test.insertAt(0, 1)==true);
}

TEST_CASE("Membership and size test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test.member(1));
    CHECK(test.member(2));
    CHECK(test.member(3));
    CHECK(test.member(4));
    CHECK(test.size() == 4);

    CHECK(test.member(-1)==false);
    CHECK(test.member(5)==false);
}

TEST_CASE("Ordering test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test[0] == 3);
    CHECK(test[1] == 4);
    CHECK(test[2] == 1);
    CHECK(test[3] == 2);
}

TEST_CASE("Backwards test")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(test.fromBack (3) == 3);
    CHECK(test.fromBack (2) == 4);
    CHECK(test.fromBack (1) == 1);
    CHECK(test.fromBack (0) == 2);
}

bool lt (const int& x, const int& y)
{
    return x < y;
}

TEST_CASE("Insert Test")
{
    SList<int> test(lt);
    test.insertSorted(10);
    test.insertSorted(0);
    test.insertSorted(20);
    test.insertSorted(10);

    CHECK (test.size () == 4);
}

TEST_CASE("Sorting test")
{
    SList<int> test(lt);
    test.insertSorted(10);
    test.insertSorted(0);
    test.insertSorted(20);
    test.insertSorted(10);
    for (size_t count = 0; count < 20; count++)
    {
        test.insertSorted (21+count);
    }

    CHECK(test[0]==0);
    CHECK(test[1]==10);
    CHECK(test[2]==10);
    CHECK(test[3]==20);

    for (size_t count = 0; count < 20; count++)
    {
        CHECK(test[4+count] == 21 + count);
    }
}

TEST_CASE("Copying test")
{
    SList<int> test(lt);
    test.insertSorted(10);
    test.insertSorted(0);
    test.insertSorted(20);
    test.insertSorted(10);

    SList<int> copy (test);

    CHECK(copy.size() == 4);
    CHECK(copy[0] == 0);
    CHECK(copy[2] == 10);
    CHECK(copy[3] == 20);

    test.insertSorted (-1);
    CHECK (test[0]==-1);
    CHECK (copy[0]==0);
}

TEST_CASE("Member test")
{
    SList<int> test(lt);
    test.insertSorted(10);
    test.insertSorted(0);
    test.insertSorted(20);
    test.insertSorted(10);
    for (size_t count = 0; count < 20; count++)
    {
        test.insertSorted(21 + count);
    }

    test.speedup ();

    CHECK(test.member(0));
    CHECK(test.member(10));
    CHECK(test.member(20));
    CHECK(test.member(21));
    CHECK(test.member(31));
    CHECK(test.member(40));
}

template <class T>
void runSListTest (SList<T> &list, size_t nChunks, size_t nIterations)
{

    const size_t iterationsPerTest = nIterations / nChunks;
    const size_t size = list.size();

    std::cout << "=================================================\n"
              << "Running time test with "
              << size
              << " elements, chunks = "
              << nChunks
              << ", iterations = "
              << nIterations
              << "\n=================================================\n";
    std::cout.flush();

    clock_t start = std::clock();

    for (size_t count = 0; count < nIterations; ++count)
    {
        const int currentChunk = count / iterationsPerTest;

        const int searchFor = (currentChunk + 1) * (size / nChunks) - 1;
        CHECK (list.member(searchFor));

        if ((count + 1) % iterationsPerTest == 0)
        {
            clock_t end = std::clock();
            const long ms = (double)(end - start) /
                            (CLOCKS_PER_SEC / 1000.0);
            std::cout << "Searching for "
                      << searchFor
                      << " took "
                      << ms
                      << "ms."
                      << std::endl;
            std::cout.flush();
            start = std::clock();
        }
    }
}

TEST_CASE("Spped-up test")
{
    SList<int> test(lt);

    const size_t size = 10000000;

    for (size_t count = size; count > 0; --count)
    {
        test.insertSorted(count - 1);
    }

    runSListTest(test, 10, 150);

    test.speedup();

    runSListTest(test, 10, 50000);
}
