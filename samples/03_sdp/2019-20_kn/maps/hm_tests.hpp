
#include <sstream>

size_t stringhash (const std::string &key, size_t htsize)
{
    size_t sum = 0;
    for (char c: key)
    {
        sum += c;
    }
    return sum % htsize;
}

TEST_CASE("Simple Key Check")
{
    HashMap<std::string,int> m (stringhash,100);

    m["John"] = 2;
    m["Merry"] = 3;
    CHECK (m["John"] == 2);
    CHECK (m["Merry"] == 3);
}

TEST_CASE("Counter Test")
{
    std::stringstream test ("lorem ipsum dolor sit amet consectetur sit adipiscing elit integer blandit bibendum sit mauris sed nisi tortor sodales id mauris nec posuere hendrerit sit sapien nam efficitur risus ipsum sit amet gravida orci sodales sit amet vivamus vel blandit tortor morbi gravida eget nibh vitae rutrum aenean et urna quam integer ornare facilisis varius fusce tincidunt lorem id lorem posuere et semper massa pretium maecenas molestie lobortis scelerisque");

    HashMap<std::string,int> wordCount (stringhash,5);

    std::string word;
    while (test >> word)
    {
        if (!wordCount.hasKey (word))
        {
            wordCount[word] = 0;
        }
        wordCount[word]++;
    }

    CHECK (wordCount["lorem"] == 3);
    CHECK (wordCount["sit"] == 6);

    for (std::string key : wordCount)
    {
        CHECK (wordCount.hasKey(key));
    }
 
    CHECK (!wordCount.hasKey("abra"));
    CHECK (!wordCount.hasKey("cadabra"));
    
}
