#include "Graph.h"

// Alocam memorie pentru lista de adiacenta
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    // Se actualizeaza lista de adiacenta in urma inserarii muchiei / drumului direct
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::createPath(vector<int> parent, vector<int>& path, int v)
{
    // cat timp nu se ajunge la sursa, se parcuge si se insereaza nodul curent, apoi se trece la nodul "parinte" 
    if (parent[v] != NULL)
    {
        path.push_back(parent[v]);
        createPath(parent, path, parent[v]);
    }
}

// Returneaza cel mai scurt drum de la src la dest
vector<int> Graph::shortestPath(int src, int dest)
{
    // Memoram aici varfurile (orasele) pe care le vizitam 
    set< pair<int, int> > setds;

    // Creem un vector pentru distante si le initializam la infinit
    vector<int> dist(V, INT_MAX);

    // Creem un vector pentru nodul "parinte" in drumul cel mai scurt
    vector<int> parent(V, NULL);

    // Adaugam nodul sursa in set si intializam distanta cu 0
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    // Parcurgem pana cand nu mai avem noduri(orase) nevizitate
    while (!setds.empty())
    {
        // Primul nod in Set este nodul de distanta minima ce se extrage din set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // stocam numarul nodului pe care-l vizitam
        int u = tmp.second;

        // cautam prin toti vecinii lui u
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // stocam nr si valoarea vecinului i din multimea vecinilor lui u
            int v = (*i).first;
            int weight = (*i).second;

            // Verificam daca drumul prin u este mai scurt
            if (dist[v] > dist[u] + weight)
            {
                // Daca v este deja in set trebuie scos si adaugat din nou cu noua distanta minima
                if (dist[v] != INT_MAX)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Actualizam distanta minima
                dist[v] = dist[u] + weight;
                // Actualizam "parintele" lui v in drumul minim
                parent[v] = u;
                // Adaugam in set nodul v cu noua distanta minima
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // acum se creeaza drumul minim
    vector<int> path;
    path.push_back(dest);
    // se creeaza drumul minim de la dest la src
    createPath(parent, path, dest);
   
    return path;
}