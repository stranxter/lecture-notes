#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "bintree.h"
#include "bintree.hpp"
#include "tree_functions.hpp"
#include "botree.hpp"

#include "tree_tests.hpp"


    /**************************************
    **    КОМАНДЕН РЕД ЗА GRAPHVIZ       **
    **                                   **
    ** >dot tree.dot -Tpdf -o tree.pdf   **
    **                                   **
    **************************************/

void BOTtests ()
{
    BOTree<int> bot;

    bot.insert (100)
       .insert (50)
       .insert (200)
       .insert (150)
       .insert (22332)
       .insert (24)
       .insert (75)
       .insert (8821)
       .insert (175);

    std::ofstream out ("bot1.dot");
    bot.dottyPrint (out);
    out.close();

    bot.remove (100);

    out.open ("bot2.dot");
    bot.dottyPrint (out);

}

int main ()
{

    BOTtests();

    // пускане на тестовете
    doctest::Context().run();
}