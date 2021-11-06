#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <math.h>
using namespace std;

#define NRORASE 20

// Pentru usurinta atribuim fiecarui nod-oras un numar intreg din intervalul [0, 19]
#define Arad            0
#define Zerind          1
#define Sibiu           2
#define Timisoara       3
#define Oradea          4
#define Fagaras         5
#define RamnicuValcea   6
#define Lugoj           7
#define Bucharest       8
#define Pitesti         9
#define Craiova         10
#define Mehadia         11
#define Drobeta         12
#define Giurgiu         13
#define Urziceni        14
#define Vaslui          15
#define Hirsova         16
#define Iasi            17
#define Neamt           18
#define Eforie          19

// Functie utila pentru afisarea oraselor conform definirii de mai sus
inline string printCity(int city)
{
    switch (city)
    {
    case Arad: return "Arad";
    case Zerind: return "Zerind";
    case Sibiu: return "Sibiu";
    case Timisoara: return "Timisoara";
    case Oradea: return "Oradea";
    case Fagaras: return "Fagaras";
    case RamnicuValcea: return "RamnicuVilcea";
    case Lugoj: return "Lugoj";
    case Bucharest: return "Bucharest";
    case Pitesti: return "Pitesti";
    case Craiova: return "Craiova";
    case Mehadia: return "Mehadia";
    case Drobeta: return "Drobeta";
    case Giurgiu: return "Giurgiu";
    case Urziceni: return "Urziceni";
    case Vaslui: return "Vaslui";
    case Hirsova: return "Hirsova";
    case Iasi: return "Iasi";
    case Neamt: return "Neamt";
    case Eforie: return "Eforie";
    }
}