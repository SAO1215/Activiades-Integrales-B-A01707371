/*
 *
 * Programación de estructuras de datos y algoritmos fundamentales (TC1031.2)
 * Formativa 4.1 - Grafo como matriz de Adyacencia y recorridos (DFS BFS)
 * Olivia Araceli Morales Quezada
 * A01707371
 *
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int arcosLista;
		//int edgesMat;
		int nodos;
    vector<int> *adjLista;
		//int *adjMatrix;
		//vector<Type> *vect = new vector<Type>

public:
		Graph(int);
		Graph();
    void addLista(int, int);
    string printadjLista();
    string cerca(int);
		bool contains(list<int>, int);

    //Metodos
    void cargarLista(string, int, int);
    string BFS(int, int);

    //Auxiliares
    string BFS_help(int, int, queue<int>&, list<int>&, vector<vector<int>>&);
    string print_ruta(vector<vector<int>>&, int, int);
    string print_visitados(list<int>);
    
    
};

Graph::Graph() {
	arcosLista = 0;
}

Graph::Graph(int n) {
  nodos = n;
	adjLista = new vector<int>[nodos];
	arcosLista = 0;
}


bool Graph::contains(list<int> ls, int nodo){
		list<int>::iterator it;
		it = find(ls.begin(), ls.end(), nodo);
		if(it != ls.end())
			return true;
		else
			return false;
}

void Graph::addLista(int u, int v){
	adjLista[v].push_back(u);
	//adjLista[u].push_back(v);
	arcosLista++;
}

void Graph::cargarLista(string nombre, int a, int b){
	adjLista = new vector<int> [a];
  nodos = a;

	string line;
	ifstream lee (nombre);
  int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1));
				v = stoi(line.substr(4));
				addLista(u,v);
			}
			lee.close();
		} else {
			cout << "Unable to open file";
		}
}

string Graph::printadjLista(){
	  stringstream aux;
    for (int i = 0; i < nodos; i++){
		sort(adjLista[i].begin(),adjLista[i].end());
	  }
		for (int i = 0; i < nodos; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjLista[i].size(); j++){
							 aux << " " << adjLista[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

string Graph::cerca(int origen){
  stringstream aux;
  for (int j = 0; j < adjLista[origen].size(); j++){
							 aux << " " << adjLista[origen][j];
					}
  return aux.str();
}

string Graph::BFS(int origen, int meta){
  stringstream aux;
	queue <int> qu;
	list <int> visitados;
  vector <vector<int>> ruta(nodos, vector<int>(0));
	qu.push(origen);
  BFS_help(origen, meta, qu, visitados, ruta);
  //aux << print_visitados(visitados); 
  aux << print_ruta(ruta, origen, meta);
  return aux.str();
}

string Graph::BFS_help(int origen, int meta, queue<int> &qu, list<int> &visitados, vector<vector<int>> &ruta){
  stringstream aux;
	if(origen == meta){
			print_visitados(visitados);
		} else if(qu.empty()){
			cout << " nodo not found";
		}	else {
			origen = qu.front();
			qu.pop();
			visitados.push_back(origen);
			for(int  i = 0; i < adjLista[origen].size(); i++)
				if(!contains(visitados, adjLista[origen][i])){
					qu.push(adjLista[origen][i]);
					ruta[adjLista[origen][i]].push_back(origen);
				}
			BFS_help(origen, meta, qu, visitados, ruta);
		}
  return aux.str();
}

string Graph::print_ruta(vector<vector <int>> &ruta, int origen, int meta){
  stringstream aux;
	int nodo =  ruta[meta][0];
	stack<int> reverse;
	reverse.push(meta);
	aux << "ruta:";
	while (nodo != origen) {
		reverse.push(nodo);
    nodo = ruta[nodo][0];
  }
	reverse.push(origen);
	while (!reverse.empty()) {
		aux << " " << reverse.top();
		reverse.pop();
  }
  
  return aux.str();
  
}

string Graph::print_visitados(list<int> visitados){
	stringstream aux;
  aux << "visitados: ";
	while (!visitados.empty()){
    aux << visitados.front() << " ";
    visitados.pop_front();
  }
  
  return aux.str();
}
#endif /* Graph_H_ */