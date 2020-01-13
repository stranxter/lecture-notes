
Graph<std::string,double> createGraph ()
{
    Graph<std::string,double> g;

    g.addVertex (1,"Sofia").
      addVertex (2,"Plovdiv").
      addVertex (3,"Pleven"). 
      addVertex (4,"Dragoman").

      addEdge (1,2,1.0).
      addEdge (2,3,2.0).
      addEdge (3,1,3.0).
      addEdge (1,4,4.0);

    return g;
}

TEST_CASE("Create Graph")
{

    Graph<std::string,double> g = createGraph();

    CHECK (g.hasEdge(1,2)==true);
    CHECK (g.hasEdge(2,4)==false);

    CHECK (g.getEdge(1,2)==1.0);

    CHECK (g.hasVertex (1) == true);
    CHECK (g.hasVertex (5) == false);

    CHECK (g.getVertex (1) == "Sofia");
    g.getVertex (1) = "New York";
    CHECK (g.getVertex (1) == "New York");


    for (uint neighbour : g.neighbours(1))
    {
        CHECK ((neighbour == 2 || neighbour == 4));
    }

}
