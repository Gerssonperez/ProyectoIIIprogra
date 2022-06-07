void buscarElemento(char Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
 
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
//







			
	class clalumno{
		public:
			char *resultado;
			void insertar(struct stalumno x){
				try{
				conexion.conectar("localhost","root","Abc123**","angela");
				char *consulta;
				char sentencia[]="INSERT INTO ALUMNO (ID,NOMBRE,APELLIDO,CORREO,FECHA,TELEFONO,CODIGOC,FECHAINGRESO) VALUES (\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\') ";
				consulta=new char[strlen(sentencia)+sizeof(stalumno)]-sizeof(int);
				sprintf(consulta,sentencia,alu.carnet,alu.nombre,alu.apellido, alu.correo, alu.fecha, alu.telefono, alu.codigoc, alu.fechaingreso );
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Ingresado Correctamente en la base de datos MYSQL\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void modificar(struct stalumno x){
				try{
				conexion.conectar("localhost","root","Abc123**","angela");
				char *consulta;
				char sentencia[]="UPDATE ALUMNO SET NOMBRE=\'%s\',APELLIDO=\'%s\' WHERE ID=\'%s\' ";
				consulta=new char[strlen(sentencia)+sizeof(stalumno)]-sizeof(int);
				sprintf(consulta,sentencia,alu.nombre,alu.apellido,alu.carnet);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Modificado\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void eliminar(struct stalumno x){
				try{
				conexion.conectar("localhost","root","Abc123**","angela");
				char *consulta;
				char sentencia[]="DELETE from ALUMNO WHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stalumno)]-sizeof(int);
				sprintf(consulta,sentencia,alu.carnet);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro ELiminado Correctamente en la base de datos \n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void mostrar(){//Esta es Otra Forma en un solo metodo
				   MYSQL           *objDatos;
				   MYSQL_RES       *res;
				   MYSQL_ROW        row;
				   MYSQL_FIELD     *columna;
				   int              i, j, k, l;
				   unsigned long   *lon;
				   MYSQL_ROW_OFFSET pos;
				   if(!(objDatos = mysql_init(0))) {
				      cout<<"Error Objeto"<<endl;
				      rewind(stdin);
				      getchar();	      
					}
				   if(!mysql_real_connect(objDatos,"localhost", "root", "Abc123**", "angela", 3306, NULL, 0)) {
				      cout<<"Error BD"<<MYSQL_PORT<<" Error: "<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_select_db(objDatos, "angela")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_query(objDatos, "SELECT * FROM ALUMNO")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				if((res=mysql_store_result(objDatos))){
					i=(int)mysql_num_rows(res);
					j=(int)mysql_num_fields(res);
					cout<<endl<<"		Datos de Todos Los Alumnos"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(res);
						lon=mysql_fetch_lengths(res);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<"	";
					}
				}cout<<endl;
			    mysql_free_result(res);
			   }
			   mysql_close(objDatos);
			   rewind(stdin);
			   cout<<endl;
			}
