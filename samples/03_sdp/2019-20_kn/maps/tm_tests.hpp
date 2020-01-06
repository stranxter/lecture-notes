#include <sstream>

#include "treemap.hpp"

TEST_CASE("TM Simple Key Check")
{
    TreeMap<std::string,int> m;

    m["John"] = 2;
    m["Merry"] = 3;
    CHECK (m["John"] == 2);
    CHECK (m["Merry"] == 3);
}

TEST_CASE("TM Counter Test")
{
    std::stringstream test ("lorem ipsum dolor sit amet consectetur sit adipiscing elit integer blandit bibendum sit mauris sed nisi tortor sodales id mauris nec posuere hendrerit sit sapien nam efficitur risus ipsum sit amet gravida orci sodales sit amet vivamus vel blandit tortor morbi gravida eget nibh vitae rutrum aenean et urna quam integer ornare facilisis varius fusce tincidunt lorem id lorem posuere et semper massa pretium maecenas molestie lobortis scelerisque");

    TreeMap<std::string,int> wordCount;

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

    std::cout << "==========================\n";
    for (std::string key : wordCount)
    {
        std::cout << key << std::endl;
        CHECK (wordCount.hasKey(key));
    }
    std::cout << "==========================\n";
 
    CHECK (!wordCount.hasKey("abra"));
    CHECK (!wordCount.hasKey("cadabra"));
    

    std::cout << "==========================\n";
}
