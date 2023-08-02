
#define host "localhost"
#define port 3306
#define username "root"
#define password "alan"
#define database "embedded"

int conectar(MYSQL **conexion);
void ejecutar_consultar(MYSQL *conexion, char *consulta);

int conectar(MYSQL **conexion){
	
	*conexion=mysql_init(NULL);
	int error;
	
	if(mysql_real_connect(*conexion,host,username,password,database,port,NULL,0) != NULL){
		
		printf("Se establecio la conexxion con la base de datos\n");
		error=0;
		
	}else{
		
		printf("Error en la conexion de la base de datos\n");
		error=1;
	}
	
	
	return error;
}

void ejecutar_consultar(MYSQL *conexion, char *consulta){
	int error, filas, columnas, i, j;
	MYSQL_RES *res_ptr;
	MYSQL_FIELD *campo;
	MYSQL_ROW res_fila;
	
	error = mysql_query(conexion, consulta);
	if(!error){
		res_ptr = mysql_store_result(conexion);
		if(res_ptr){
			filas = mysql_num_rows(res_ptr);
			columnas = mysql_num_fields(res_ptr);
			
			while(campo = mysql_fetch_field(res_ptr)){
				printf("%15s", campo->name);
			}
			printf("\n");
			
			for(i=1; i<=filas; i++){
				res_fila = mysql_fetch_row(res_ptr);
				for(j=0; j<columnas; j++){
					printf("%15s", res_fila[j]);
				}
				printf("\n");
			}
		}
	}
	else{
		printf("Ocurrio un error al ejecutar la consulta SQL\n");
	}
}
