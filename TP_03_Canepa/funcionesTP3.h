
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[512];
    int puntaje;
    char linkImagen[256];
    //int id;
    int isEmpty;
}EMovie;


/** \brief desplega menu y solicita una opcion
 * \param item Es el texto desplegado en el menu
 * \return devuelve un entero que representa la opción elegida
 *
 */

int menu (char* item);

/**
 *  Agrega una pelicula al archivo binario
 *  @param pMovie la estructura a ser agregada al archivo
 *  @param length cantidad de indices ene l array de estructuras
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* pMovie);

/**
 *  Busca si una pelicula del archivo binario ya existe con el mismo titulo
 *  @param movie la estructura a ser buscada en el archivo
 *  @param *titulo string del titulo
 *  @return retorna -1 o 0 de acuerdo a si se encontro la pelicula o no
 */
int checkPelicula(EMovie* pMovie, char* titulo);

/**
 *  Modifica una pelicula del archivo binario
 *  @param pMovie la estructura a ser modificada al archivo
 *  @param length cantidad de indices en el array de estructuras
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie* pMovie, char* titulo);

/**
 *  Borra una pelicula del archivo binario
 *  @param pMovie la estructura a ser eliminada al archivo
 *  @param length cantidad de indices ene l array de estructuras
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* pMovie,char* titulo);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param pMovie la estructura que se va a utilizar para escribir el HTML.
 *  @param fileBin el nombre para el archivo binario donde se encuentran los datos.
 *  @param fileHtml el nombre para el archivo html donde se generará la página.
 */
int generarPagina(EMovie* pMovie, char*fileBin, char *fileHtml);


