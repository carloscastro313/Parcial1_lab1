typedef struct
{
    int id;
    char actorName[51];
    char origen[51];

}eActores;

typedef struct
{
    int id;
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char genero[21];

}eGenero;


typedef struct
{
    int id;
    int idActor;
    int idGenero;
    char name[51];
    int isEmpty;

}ePelicula;

/** \brief Inicializar estructura ePelicula
 *
 * \param ePelicula[] list
 * \param int   len
 * \return void
 *
 */
void peliculas_initFilms(ePelicula[], int);

/** \brief Pedir pelicula
 *
 * \param ePelicula[]   list
 * \param eFecha[]  listFecha
 * \param int   len
 * \param int   flag
 * \return int flag+1
 *
 */
int peliculas_alta(ePelicula[], eFecha[], eActores[],int, int);
/** \brief Buscar vector libre
 *
 * \param ePelicula[] list
 * \param int len
 * \return int indice
 *
 */
int peliculas_buscarLibre(ePelicula[], int);
/** \brief hardcordear datos
 *
 * \param ePelicula[]   list
 * \param eFecha[]  listFecha
 * \param int   len
 * \return void
 *
 */
void peliculas_hardcodearDatos(ePelicula[], eFecha[], int);

/** \brief
 *
 * \param ePelicula[]   list
 * \param eFecha[]  listFecha
 * \param int len
 * \param int   flag
 * \return void
 *
 */
void peliculas_modificar(ePelicula[], eFecha[], int, int);
/** \brief Buscar id
 *
 * \param ePelicula[]   list
 * \param int   len
 * \param int   id
 * \return int indice
 *
 */
int peliculas_findFilmsById(ePelicula[], int, int);
/** \brief opciones de cambio
 *
 * \param ePelicula[] list
 * \param eFecha[]  listFecha
 * \param int   indice
 * \param char  opcion
 * \return void
 *
 */
void peliculas_opcionesCambio(ePelicula[], eFecha[], int, char);

/** \brief baja de peliculas
 *
 * \param ePelicula[] list
 * \param eFecha[]  listFecha
 * \param int len
 * \param int  flag
 * \return int r
 *
 */
int peliculas_baja(ePelicula[], eFecha[], int, int);
/** \brief buscar pelicula para dar de baja
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param int len
 * \param int id
 * \return int loEncontro
 *
 */
int peliculas_remove(ePelicula[], eFecha[], int, int);


;

