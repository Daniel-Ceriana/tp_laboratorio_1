#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED
#endif // OPERACIONES_H_INCLUDED



/** \brief Suma dos numeros enteros
 *
 * \param primer entero ingresado
 * \param segundo entero ingresado
 * \return retorna la suma de los dos numeros enteros
 *
 */
int sumar(int a, int b);



/** \brief resta de dos numeros enteros
 *
 * \param primer entero ingresado
 * \param segundo entero ingresado
 * \return retorna la resta de dos numeros enteros ingresados
 *
 */
int restar(int a, int b);



/** \brief multiplicacion de dos numeros enteros
 *
 * \param primer entero ingresado
 * \param segundo entero ingresado
 * \return retorna el producto de dos numeros enteros ingresados
 *
 */
int multiplicar(int a, int b);



/** \brief Divide dos enteros
 *
 * \param primer entero ingresado
 * \param segundo entero ingresado
 * \return resultado flotante de la division
 *
 */
float dividir(int a, int b);



/** \brief factorial del numero ingresado
 *
 * \param numero entero ingresado menor o igual a 20 y mayor a -1
 * \return retorna el factorial del numero entero ingresado, en caso de ser negativo  o mayor a 20 el retorno sera = 0, si el numero a factorizar es 0, el retorno es = 1
 *
 */
long long int factorial(long long int a);


/** \brief muestra un menu de opciones
 *
 * \param valor del primer entero
 * \param valor del segundo entero
 * \param indica si el primero entero esta en uso = 1, sino 0
 * \param indica si el segundo entero esta en uso = 1, sino 0
 *
 */
void mostrarMenu(int a, int b, int usadoA, int usadoB);

