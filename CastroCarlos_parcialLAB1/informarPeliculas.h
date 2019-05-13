
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
/** \brief swap
 *
 * \param ePelicula[] list
 * \param eFecha[] listFecha
 * \param int i
 * \param int j
 * \return void
 *
 */
void peliculas_ordenamiento(ePelicula[], eFecha[], int, int);
/** \brief Ordenar actores alfabeticamente
 *
 * \param eActores[] listActores
 * \param int len
 * \return void
 *
 */
void peliculas_ordenarVectorActores(eActores[], int);
/** \brief swap
 *
 * \param eActores[] listActores
 * \param int i
 * \param int j
 * \return void
 *
 */
void peliculas_ordenamientoActores(eActores[], int, int);
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
void peliculas_desplegarDatosActores(eActores);
void peliculas_maximoGenero(ePelicula[], eGenero[], int);
void peliculas_maximoActor(ePelicula[], eActores[], int);
void peliculas_maximoAnio(ePelicula[], eFecha[], int);

