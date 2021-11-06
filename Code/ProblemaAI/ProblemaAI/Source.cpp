#include "Graph.h"

int main()
{
    
    string file_name;
    cin >> file_name;
    
    //citire din fisier
    ifstream f(file_name);
    int distances[24], oras1, oras2;
    for (int i = 1; i <= 23; i++)
        f >> distances[i];
    
    // crearea grafului din Figure 2: Romania map
    Graph harta_romaniei(NRORASE);
    harta_romaniei.addEdge(Lugoj, Mehadia, distances[1]);
    harta_romaniei.addEdge(Zerind, Oradea, distances[2]);
    harta_romaniei.addEdge(Arad, Zerind, distances[3]);
    harta_romaniei.addEdge(Mehadia, Drobeta, distances[4]);
    harta_romaniei.addEdge(RamnicuValcea, Sibiu, distances[5]);
    harta_romaniei.addEdge(Bucharest, Urziceni, distances[6]);
    harta_romaniei.addEdge(Hirsova, Eforie, distances[7]);
    harta_romaniei.addEdge(Iasi, Neamt, distances[8]);
    harta_romaniei.addEdge(Bucharest, Giurgiu, distances[9]);
    harta_romaniei.addEdge(Vaslui, Iasi, distances[10]);
    harta_romaniei.addEdge(RamnicuValcea, Pitesti, distances[11]);
    harta_romaniei.addEdge(Urziceni, Hirsova, distances[12]);
    harta_romaniei.addEdge(Sibiu, Fagaras, distances[13]);
    harta_romaniei.addEdge(Pitesti, Bucharest, distances[14]);
    harta_romaniei.addEdge(Timisoara, Lugoj, distances[15]);
    harta_romaniei.addEdge(Arad, Timisoara, distances[16]);
    harta_romaniei.addEdge(Drobeta, Craiova, distances[17]);
    harta_romaniei.addEdge(Craiova, Pitesti, distances[18]);
    harta_romaniei.addEdge(Arad, Sibiu, distances[19]);
    harta_romaniei.addEdge(Urziceni, Vaslui, distances[20]);
    harta_romaniei.addEdge(Craiova, RamnicuValcea, distances[21]);
    harta_romaniei.addEdge(Oradea, Sibiu, distances[22]);
    harta_romaniei.addEdge(Fagaras, Bucharest, distances[23]);

    //Alegerea orasului de plecare a celor 2 prieteni
    f >> oras1;
    f >> oras2;
    
    f.close();
    cin >> file_name;
    ofstream g(file_name);

    //Determinarea drumului minim
    vector<int> path(harta_romaniei.shortestPath(oras1, oras2));

    g << "Drumul cel mai scurt de la " << printCity(oras1) << " la " << printCity(oras2) << " este: [ ";
    for (int i = 0; i < path.size(); i++)
        g << printCity(path[i]) << " ";
    g << "]" << endl;

    //Determinarea orasului de intalnire
    int mijloc = path.size() / 2;
    g << "Cei doi prieteni se vor intalni la " << printCity(path[mijloc]) << endl;
    
    g.close();

    return 0;
}