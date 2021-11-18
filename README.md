# ¿TE PERDIS-TEC? Integral B Avance 1 (Grafos)
Olivia Araceli Morales Quezada (A01707371)

La finalidad de este proyecto es implementar grafos por medio de un programa que mapea el area de profesional del TEC y crea un grafo con el que podemos ver los sitios mas cercanos a nuesta ubicación y en caso de querer llegar a un lugar en especifico la ruta más optima. 

Imagenes del mapa del TEC y el grafo generado:

![mapa TEC](mapa_TEC.png)
![grafo_TEC](graph.png)

## Competencias a evaluar

### SICT0301B: Evalúa los componentes

**Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa**

Aun no se hace, pero se planea hacer.

### SICT0302B: Toma decisiones

**Usa grafos para hacer analisis de información** 

En el archivo _mapa.txt_ se encuentran las relaciones adyacentes de los lugares del TEC, estos van a guardarse en una lista de adyacencia ya que su proposito es mostrar rutas generadas a partir de las busquedas del grafo con esta información. 

**Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema**

Para esta situación el algoritmo de búsqueda seleccionado fue un BFS, a diferencia del DFS este te muestra el camino más corto, y es el adecuado para mostrarte la ruta más óptima para llegar a donde quieras. 

### SICT0303B: Implementa acciones científicas (Ya calificada en Integral A)

**Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.** 

Se leen los datos del archivo "mapa.txt", este proceso se encuentra en la funcion _cargarLista()_, implementada en la linea 42 de _main.cpp_.

## Consideraciones
- Solo ingresar los numeros que corresponden a cada lugar, no el nombre.
- Puedo contar con una mano las veces que he pisado el TEC, y casi me perdí con el guia (@AudibleP) es posible que existan algunos errores o carencias, es solo un ejemplo que se me ocurrio para implementar grafos.

**Referencias**

- Pagina para generar el grapho: https://csacademy.com/app/graph_editor/ 
