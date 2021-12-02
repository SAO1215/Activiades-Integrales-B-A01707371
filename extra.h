/*
 *
 * Programación de estructuras de datos y algoritmos fundamentales (TC1031.2)
 * Algoritmo/estructura Extra
 * Olivia Araceli Morales Quezada
 * A01707371
 *
*/
#ifndef EXTRA_H_
#define EXTRA_H_

#include <utility> 

void guia(){
  pair<string, int> lugares;
  int num_lugar;
  string nom_lugar;
  string buffer;
  
  ifstream tec("tec.txt");
  
  while(tec.good()){
  getline(tec,buffer,' '); 
  stringstream nombre(buffer);
  nombre >> nom_lugar;

  getline(tec,buffer); 
  stringstream entero(buffer);
  entero >> num_lugar;

  lugares = make_pair(nom_lugar, num_lugar);
  cout << lugares.first << " ---> " << lugares.second << endl;
} 
tec.close();
}
#endif