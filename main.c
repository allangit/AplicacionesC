
#include <stdio.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <stdlib.h>
#include "funciones.h"


int main(){
	
	
	int error,i=0;
	system("color 9");
	printf("Trabajando con Bases de Datos\n\n");

	char *consulta[]={"drop database embedded","create database embedded","use embedded","create table sensores(nombre varchar(100),ubicacion varchar(100))",
					  "insert into sensores(nombre,ubicacion) values(%s,%s),"};
	MYSQL *conexion;
	error=conectar(&conexion);
	
	if(!error){
		
		for(i; i<4; i++){
			
				ejecutar_consultar(conexion,consulta[i]);
		}
	
	}

	return 0;	
}














