#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

void bienvenida(){
  int start, goal;
  cout << "\n=====================¿TE PERDIS-TEC?=====================" << endl;
  cout << "Si es tu primera vez dentro del TEC o tu guia te estaba\nsiguiendo a ti y no tu a el como el sentido comun manda."<<endl;
  cout << "No te preocupes, espero que esta guia te resulte util."<<endl;
  cout << "\nAsignamos un numero a cada locación del area de profesional:"<<endl;
}

void guia(){
  cout << "\tAcceso Epigmenio --> 0"<<endl;
  cout << "\tAcceso Soriana --> 1"<<endl;
  cout << "\tServicios Escolares --> 2"<<endl;
  cout << "\tCafeteria Central --> 3"<<endl;
  cout << "\tTEC Store --> 4"<<endl;
  cout << "\tStarbucks --> 5"<<endl;
  cout << "\tBiblioteca --> 6"<<endl;
  cout << "\tEdificio IV --> 7"<<endl;
  cout << "\tCentro de Medios --> 8"<<endl;
  cout << "\tEdificio V --> 9"<<endl;
  cout << "\tOXXO --> 10"<<endl;
  cout << "\tEstacionamiento --> 11"<<endl;
  cout << "\tEdificio III --> 12"<<endl;
  cout << "\tEdificio II --> 13"<<endl;
  cout << "\tCentro de Bioingenieria --> 14"<<endl;
  cout << "\tEdificio I --> 15"<<endl;
}

int main(int argc, char* argv[]) {
  Graph mapa;
  int origen, meta;

  mapa.cargarLista("mapa.txt", 16, 67);
  //mapa.loadGraphMat("mapa.txt", 16, 100);

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
                 cout << "Tu ruta: ";
                 cout << mapa.BFS(origen,meta) << endl;
            break;

        }
    } 
    while(opc != 3);
    cout<<"Espero te haya servido!!";

    return 0;
}