


/** \brief desplega menu y solicita una opcion
 * \param item Es el texto desplegado en el menu
 * \return devuelve un entero que representa la opción elegida
 *
 */

int menu (char* item)
{
    int choice; //Almacena la opción del menú elegida por el usuario
    printf(item);
    printf("\n\nSeleccione una opci%cn: ", 162);
    scanf("%d",&choice);

    return choice;

}
