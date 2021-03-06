#include <iostream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "graph.h"
#include "extra.h"

using namespace std;

void bienvenida(){
  cout << "\n=====================¿TE PERDIS-TEC?=====================" << endl;
  cout << "Si es tu primera vez dentro del TEC o tu guia te estaba siguiendo a ti y no tu a el como el sentido comun manda."<<endl;
  cout << "No te preocupes, espero que esta guia te resulte util."<<endl;
  cout << "\nAsignamos un numero a cada locación del area de profesional:"<<endl;
}

int main(int argc, char* argv[]) {
  
  Graph mapa;
  int origen, meta;

  mapa.cargarLista("mapa.txt", 16, 67);

  int opc;
  bienvenida();
  do{
    guia();

    cout<<"\nOpciones:"<<endl;;
    cout<<"1.- Ver que hay cerca"<<endl;
    cout<<"2.- Llegar a un lugar en especifico"<<endl;
    cout<<"3.- Cerrar";
    cout<<"\n\nIngresa una opción: ";

    cin>>opc;

        switch(opc){
            case 1:
                 cout << "\nSegun la guia ingresa donde te encuentas: ";
                 cin >> origen;
                 cout << "\nLos sitios más cercanos a tu ubicación son: ";
                 cout <<	mapa.cerca(origen)<< endl;
            break;
                
            case 2:
                 cout << "\nIngresa donde te encuentas: ";
                 cin >> origen;
                 cout << "Ingresa a donde quieres llegar: ";
                 cin >> meta;
                 cout << "Tu ";
                 cout << mapa.BFS(origen,meta) << endl;
            break;

        }
    } 
    while(opc != 3);
    cout<<"Espero te haya servido!!";

    return 0;
}