#include "problemconfiguration.h"

// Clasa ce reprezinta un graf (in problema noastra, graful este reprezentata de harta romaniei)
class Graph
{
    int V;    // Numar de varfuri(orase)

    // lista de adiacenta pentru graful(harta) noastra
    list< pair<int, int> >* adj;

public:
    Graph(int V);  // Constructor

    // functie pentru adaugarea unei muchii (drum direct intre doua orase)
    void addEdge(int u, int v, int w);

    // cauta cel mai scurt drum de la un oras s la un oras d folosind dijkstra
    vector<int> shortestPath(int s, int d);

    // functie utila reursiva pentru a crea drumul cel mai scurt
    void createPath(vector<int> parent, vector<int>& path, int v);
};

