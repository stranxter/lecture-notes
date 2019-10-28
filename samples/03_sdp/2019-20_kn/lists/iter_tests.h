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

    Sequence<DListIterator<int>> seq(test.begin(),
                                     test.end());

    CHECK(reduce(seq, plus, 0) == 10);

    map (seq,inc);

    CHECK(reduce(seq, plus, 0) == 14);
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

    Sequence<DListIterator<int>> seq (test.begin(), test.end());

    CHECK(reduce(filter(seq,even),plus,0)==6);
    CHECK(reduce(filter(seq, noteven),plus,0) == 4);
}

TEST_CASE("Test MapF")
{

    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    Sequence<DListIterator<int>> seq(test.begin(), test.end());

    CHECK(reduce(mapf(seq,inc),plus,0) == 14);
}

TEST_CASE("Test Map + Filter")
{

    DLList<int> test;
    test.insertAt(0, 1);
    test.insertAt(1, 2);
    test.insertAt(0, 3);
    test.insertAt(1, 4);

    Sequence<DListIterator<int>> seq(test.begin(), test.end());

    CHECK(reduce(mapf(filter(seq,even), inc), plus, 0) == 8);
}
