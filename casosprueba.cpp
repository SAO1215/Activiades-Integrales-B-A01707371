#include <iostream>
#include <cstring>
#include <utility> 
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

    Graph casos;
    string prueba;
    
    //En el .txt es un grafo cdonde cada nodo tiene dos conexiones
    casos.cargarLista("casos.txt", 5, 10);
  
    prueba = "vertex 0 : 1 3 vertex 1 : 0 2 vertex 2 : 1 4 vertex 3 : 0 4 vertex 4 : 2 3 ";
    cout <<"Prueba - esperada " << prueba << "\n programa " << casos.printadjLista() << "\n";
    cout <<	(!prueba.compare(casos.printadjLista()) ? "success\n" : "fail\n");

    prueba = " 1 3";
    cout <<"\nPrueba 0.- esperada " << prueba << "\n programa" << casos.cerca(0) << "\n";
    cout <<	(!prueba.compare(casos.cerca(0)) ? "success\n" : "fail\n");

    prueba = " 0 2";
    cout <<"\nPrueba 1.- esperada " << prueba << "\n programa" << casos.cerca(1) << "\n";
    cout <<	(!prueba.compare(casos.cerca(1)) ? "success\n" : "fail\n");

    prueba = " 1 4";
    cout <<"\nPrueba 2.- esperada " << prueba << "\n programa" << casos.cerca(2) << "\n";
    cout <<	(!prueba.compare(casos.cerca(2)) ? "success\n" : "fail\n");

    prueba = " 0 4";
    cout <<"\nPrueba 3.- esperada " << prueba << "\n programa" << casos.cerca(3) << "\n";
    cout <<	(!prueba.compare(casos.cerca(3)) ? "success\n" : "fail\n");

    prueba = " 2 3";
    cout <<"\nPrueba 4.- esperada " << prueba << "\n programa" << casos.cerca(4) << "\n";
    cout <<	(!prueba.compare(casos.cerca(4)) ? "success\n" : "fail\n");

    prueba = "ruta: 0 3 4";
    cout << "\nPrueba 5.- esperada " << prueba << "\n programa " << casos.BFS(0,4) << "\n";
    cout <<	(!prueba.compare(casos.BFS(0,4)) ? "success\n" : "fail\n");

    prueba = "ruta: 1 0 3";
    cout << "\nPrueba 6.- esperada " << prueba << "\n programa " << casos.BFS(1,3) << "\n";
    cout <<	(!prueba.compare(casos.BFS(1,3)) ? "success\n" : "fail\n");
    
    prueba = "ruta: 2 1 0";
    cout << "\nPrueba 7.- esperada " << prueba << "\n programa " << casos.BFS(2,0) << "\n";
    cout <<	(!prueba.compare(casos.BFS(2,0)) ? "success\n" : "fail\n");

    prueba = "ruta: 3 4 2";
    cout << "\nPrueba 8.- esperada " << prueba << "\n programa " << casos.BFS(3,2) << "\n";
    cout <<	(!prueba.compare(casos.BFS(3,2)) ? "success\n" : "fail\n");

    prueba = "ruta: 4 3 0";
    cout << "\nPrueba 9.- esperada " << prueba << "\n programa " << casos.BFS(4,0) << "\n";
    cout <<	(!prueba.compare(casos.BFS(4,0)) ? "success\n" : "fail\n");

    //Completa el grafo y hace que todos los nodos esten conectados entre todos y que el paso
    casos.addLista(0, 2);
    casos.addLista(0, 4);
    casos.addLista(1, 3);
    casos.addLista(1, 4);
    casos.addLista(2, 0);
    casos.addLista(2, 3);
    casos.addLista(3, 1);
    casos.addLista(3, 2);
    casos.addLista(4, 0);
    casos.addLista(4, 1);

    prueba = "vertex 0 : 1 2 3 4 vertex 1 : 0 2 3 4 vertex 2 : 0 1 3 4 vertex 3 : 0 1 2 4 vertex 4 : 0 1 2 3 ";
    cout <<"Prueba 10.- esperada " << prueba << "\n programa " << casos.printadjLista() << "\n";
    cout <<	(!prueba.compare(casos.printadjLista()) ? "success\n" : "fail\n");

    cout << "Pruebas estructura extra: pair" << endl;
    pair <string,string> casoP;

    casoP = make_pair ("10","20");

    string resp;
    resp = casoP.first;
    prueba = "10";

    if(resp == prueba){
      cout << "Prueba 11.- esperada " << prueba << "\nprograma "<< resp << endl;
      cout << "succes" << endl;
    } else{
      cout << "Prueba 11.- esperada " << prueba << "\nprograma "<< resp << endl;
      cout << "fail" << endl;
    }

    resp = casoP.second;
    prueba = "20";

    if(resp == prueba){
      cout << "Prueba 12.- esperada " << prueba << "\nprograma "<< resp << endl;
      cout << "succes" << endl;
    } else{
      cout << "Prueba 12.- esperada " << prueba << "\nprograma "<< resp << endl;
      cout << "fail" << endl;
    }
    
}