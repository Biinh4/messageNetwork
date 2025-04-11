#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using Vertex = int;
constexpr int INF = std::numeric_limits<int>::max();
constexpr int UNDEFINED = -1;

void error (std::string message);

struct Edge {
    Vertex u, v;
    int weight;

    Edge(int src = 0, int dest = 0, int w = 0) : u(src), v(dest), weight(w) {}

    inline friend std::istream& operator >>(std::istream& in, Edge & e)
    {
        return in >> e.u >> e.v >> e.weight;
    }

    inline friend std::ostream& operator <<(std::ostream& out, const Edge & e)
    {
       return out << "(" << e.u << ","  << e.v << ","  << e.weight << ")" ;
    }
};

using EdgeList = std::vector<Edge>;

using VertexList = std::vector<Vertex>;

struct Graph: public std::vector<EdgeList>
{
    int numVertices = 0;

    Graph sort_edges() const;
    VertexList edges_from(Vertex vertex) const;

    inline friend std::istream& operator >>(std::istream& in, Graph & G)
    {
        if (!(in >> G.numVertices))
            error("unable to find input file");

        G.resize(G.numVertices); // resize to hold adjacency list for each vertex

        for (Edge e; in >> e;)
        {
            G[e.u].push_back(e); // Add to adjacency list of u
        }

        return in;
    }
};

int sum_weights(EdgeList const& L); // important for testing - the total cost of MST
void file_to_graph(std::string filename, Graph & G);
VertexList bfs(const Graph& graph, Vertex startVertex);


// class QuickSorter {
//     static int select_pivot(EdgeList & edgelist, int low, int high);
//     static int partition(EdgeList& edgelist, int low, int high);
//     static void quick_sort(EdgeList& edgelist, int low, int high);
//     void sort();
// };


#endif
