//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	
	int err;
	
	// Estructura especial para almacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int identificador;
	char nombre[15];
	char consulta [80];
	
	//Creamos una conexion al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n",
		mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","user", "pass", "personas",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiￃﾳn: %u %s\n",
		mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
// consulta SQL para obtener una tabla con todos los datos
// de la base de datos
	err=mysql_query (conn, "SELECT * FROM campeonato");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
		mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
//recogemos el resultado de la consulta. El resultado de la
//consulta se devuelve en una variable del tipo puntero a
//MYSQL_RES tal y como hemos declarado anteriormente.
//Se trata de una tabla virtual en memoria que es la copia
//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	
		
	// Ahora vamos a buscar el nombre de la persona cuyo nombre es uno
	// dado por el usuario
	printf ("Dame el nombre de la persona que quieres buscar\n");
	scanf ("%s", nombre);
	
	// construimos la consulta SQL
	strcpy (consulta,"SELECT identificador FROM personas WHERE nombre = '");
	strcat (consulta, nombre);
	strcat (consulta,"'");
	
	// hacemos la consulta
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
		mysql_errno(conn), mysql_error(conn));
		exit (1);
		}
		
	//recogemos el resultado de la consulta
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	

	
	// hacemos la consulta
	err=mysql_query (conn, consulta);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		// El resultado debe ser una matriz con una sola fila
		// y una columna que contiene el nombre
		printf ("Puntos de la persona: %d\n", row[3]);
		
		
	// cerrar la conexion con el servidor MYSQL
	mysql_close (conn);
	exit(0);
}