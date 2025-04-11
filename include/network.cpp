#include "network.h"

// Graph Adjacency List Building
Graph Graph::sort_edges() const {
    Graph sorted;
    sorted.numVertices = this->numVertices;
    sorted.resize(numVertices);
    
    EdgeList all_edges;

    for (const EdgeList& edgelist: *this) {
        for (const Edge& edge: edgelist) {
            all_edges.push_back(edge);
        }
    }

    std::sort(all_edges.begin(), all_edges.end(), [](const Edge& a, const Edge& b) {return a.weight < b.weight;});

    for (const Edge& edge : all_edges) {
        sorted[edge.u].push_back(edge);
    }

    return sorted;
}

VertexList Graph::edges_from(Vertex vertex) const {
    VertexList neighbors;
    
    for (const EdgeList& edgelist: *this) {
        for (const Edge& edge: edgelist) {
            if (edge.u == vertex) {
                neighbors.push_back(edge.v);
            }
        }
    }
    
    return neighbors;
}