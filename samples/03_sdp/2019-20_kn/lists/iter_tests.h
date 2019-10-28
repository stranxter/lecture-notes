TEST_CASE("Test DList Iterator")
{
    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    int sum = 0;

    /*for (auto it = test.begin(); 
         it != test.end(); 
         ++it)
    {
        sum += *it;
    }*/

    for (int i : test)
    {
        sum += i;
    }

    CHECK(sum == 10);
}


TEST_CASE("Test Map Inc")
{

    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    CHECK(reduce(test.begin(), 
                 test.end(),
                 plus,
                 0) == 10);

    map (test.begin(),test.end(),inc);

    CHECK(reduce(test.begin(),
                 test.end(),
                 plus,
                 0) == 14);
}

template <class T>
using FilteredDListIterator = FilterIterator<DListIterator<T>, T>;

TEST_CASE("Test Filter")
{

    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    couple<FilteredDListIterator<int>> 
         filtered = filter(test.begin(),
                    test.end(),
                    even);

    CHECK(reduce(filtered.first,
                 filtered.second,
                 plus,
                 0) == 6);

    filtered = filter(test.begin(),
                      test.end(),
                      noteven);

    CHECK(reduce(filtered.first,
                 filtered.second,
                 plus,
                 0) == 4);
}
