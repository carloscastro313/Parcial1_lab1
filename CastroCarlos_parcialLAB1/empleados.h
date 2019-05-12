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
/** \brief funcion repetitiva de opcines
 *
 * \param char[] mensaje
 * \return char opcion
 *
 */
char peliculas_opciones(char[]);


/** \brief Pedir pelicula
 *
 * \param ePelicula[]   list
 * \param eFecha[]  listFecha
 * \param int   len
 * \param int   flag
 * \return int flag+1
 *
 */
int peliculas_alta(ePelicula[], eFecha[], int, int);
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


/** \brief Funciones repetitiva de ingresar palabra
 *
 * \param char[] buffer
 * \param char[] mensaje
 * \return void
 *
 */
void peliculas_ingresoPalabra(char[], char[]);
/** \brief Mayusculas
 *
 * \param char[] buffer
 * \return void
 *
 */
void peliculas_correctorPalabras(char[]);
/** \brief Funciones repetitiva de ingresar numero
 *
 * \param char[] mensaje
 * \return int bufferN
 *
 */
int peliculas_ingresoNumero(char[]);

/** \brief mostrar datos de peliculas
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param eActores[] listActores
 * \param eGenero[] listGeneros
 * \param int len
 * \param int flag
 * \return void
 *
 */
void peliculas_mostrar(ePelicula[], eFecha[], eActores[], eGenero[], int, int);
/** \brief Ordenar por fecha
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param int len
 * \return void
 *
 */
void peliculas_ordenarVector(ePelicula[], eFecha[], int);
/** \brief Intercambio
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param int i
 * \param int j
 * \return void
 *
 */
void peliculas_ordenamiento(ePelicula[], eFecha[], int, int);

/** \brief Verifica datos si es FALSE va de desplegar dato,TRUE va a continuar
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param eActores[] listActores
 * \param eGenero[] listGeneros
 * \param int len
 * \return void
 *
 */
void peliculas_cargarDatos(ePelicula[], eFecha[], eActores[], eGenero[], int);
/** \brief Desplegar datos en pantalla
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param eActores[] listActores
 * \param eGenero[] listGeneros
 * \return void
 *
 */
void peliculas_desplegarDatos(ePelicula, eFecha, eActores[], eGenero[]);

/** \brief Desplegar actores
 *
 * \param eActores[] listActores
 * \return void
 *
 */
void peliculas_cargarDatosActores(eActores[]);

