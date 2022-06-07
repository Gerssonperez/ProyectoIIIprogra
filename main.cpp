#include<iostream>
#include<mysql.h>
//2#include<mysql_error.h>
#include<locale.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
/*Un CRUD es:
	CREATE	: CREAR REGISTROS
	READ	: LEER REGISTROS 
	UPDATE	: MODIFICAR REGISTRO (UPDATE O ACTUALIZAR)
	DELETE	: ELIMINAR REGISTROS 
 */
 
//using std::cout; using std::cin;
//using std::endl; using std::string;

void menu();

using namespace std;
	class conne{
		
		public:
		MYSQL *obj;
		
		char* conectar(char *server, char *user, char *pw, char *database){
			
				if(!(obj=mysql_init(0)))
					{
						return "Error Create Objeto";
					}
					if(!mysql_real_connect(obj,server,user,pw,database,3306,NULL,0))
					{
						return (char*)mysql_error(obj);
					}else
					{
						return "++++++++ Base de Datos en Uso ++++++++";
					}
		}
		
		void desconectar(){
			mysql_close(obj);
		}
	};
	
	conne conexion;
	
	struct stalumno{
	char carnet[8];
    char nombre[20];
	char apellido[20];
	char correo [25];
	char fecha[10];
	char telefono[9];
	char codigoc[10];
	char fechaingreso[10];
	
		
	}alu;
/////////////////////////////////////memoria virtual insert///////////////////////////////////////////
	struct nodo{
       int nro;     
	   string nombre ;
	   string apellido, correo,fechan, telefono, codigoc, fechaingreso; 
	  	
	   		  // en este caso es un numero entero
       struct nodo *sgte;
};
  
typedef struct nodo *Tlista;
  
void insertarInicio(Tlista &lista, int valor, string nombre, string apellido, string correo, string fecha,  string telefono, string codigoc, string fechaingreso  )
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->nombre = nombre ;
    q->apellido = apellido;
    q->correo  = correo;
    q->fechan  = fecha;
    q->telefono= telefono;
    q->codigoc= codigoc;
    q->fechaingreso=fechaingreso ;
   
    q->sgte = lista;
    lista  = q;
	cout<<"Datos Guarddos en Memoria Correctamente"<<endl;         
}

void reportarLista(Tlista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << "-->"<<  lista->nombre <<"-->"<< lista->apellido <<"-->"<< lista->correo <<"-->"<< lista->fechan << "-->"<<lista->telefono<<"-->"<< lista->codigoc<<"-->"<<lista->fechaingreso<<endl ;
          lista = lista->sgte;
          i++;
           
     }
     menu();
}

void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..! no existen elementos en memoria en este momento";
}

void buscarElemento(Tlista lista, int valor)
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
			
	};
	
	void salir(){
		cout<<"Programa Finalizado\n";
	}
	
	void menu(){
		
		 Tlista lista = NULL;
	//int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    char _nombre [20] ;
	char  _apellido[20];
	char  _correo[25];
	char  _fechan [20];
	char _telefono[9];
	char _codigoc[10];
	char _fechaingreso[10];
	
	string nombre;
	string apellido;
	string correo;
	string fecha;
	string telefono;
	string codigoc;
	string fechaingreso;
	
			
    int pos;    // posicion a insertar
				
		int opcion;
		clalumno op;
		cout<<"                   Presentado por: PROYECTO 3 PROGRAMACION   ";
		do{
		cout<<"                                                                 ";
		cout<<"              												    "<<endl;
		cout<<"             	   SISTEMA DE ALUMNOS EN MEMORIA BD             "<<endl;
		cout<<"															        "<<endl;
		cout<<"                        Seleccione una Opcion  				    "<<endl;
		cout<<"                   1.- Crear Registros de alumnos Memoria /BD  			    "<<endl;
		cout<<"                   2.- Eliminar Registros  Memoria / BD		    "<<endl;
		cout<<"                   3.- Modificar Registros Memoria / BD						"<<endl;
		cout<<"                   4.- Ver Registros base de datos My SQL        		"<<endl;
		cout<<"                   5.- Ver registros en memoria Virtual			"<<endl;
		cout<<"                   6.- Buscar alumno por id lista memoria        "<<endl;
		cout<<"                   9.- Salir de Programa							"<<endl;
		cout<<"                                                                 "<<endl;
		
		clalumno x;
		cin>>opcion;
		
		switch(opcion)
		{
		
				case 1:		
						{
																																																																
					cout<<"Ingrese Datos de Alumnos \n";
					cout<<"Ingrese ID : ";
					cin>>alu.carnet; _dato = atoi(alu.carnet); 
					cout<<"Ingrese Nombre: "; 
				    cin>>alu.nombre; strcpy(_nombre ,alu.nombre); nombre= _nombre;
					cout<<"Ingrese Apellido: ";
					cin>>alu.apellido; strcpy(_apellido,alu.apellido); apellido = _apellido ;
					cout<<"Ingrese Correo Electronico: ";
					cin>>alu.correo; strcpy(_correo,alu.correo);  correo = _correo ;
					cout<<"Ingrese Fecha: ";
					cin>>alu.fecha; strcpy(_fechan,alu.fecha); fecha = _fechan;
					cout<<"Ingrese Telefono: ";
					cin>>alu.telefono; strcpy(_telefono,alu.telefono); telefono = _telefono;
					cout<<"Ingrese Codigo de Carrera: ";
					cin>>alu.codigoc; strcpy(_codigoc,alu.codigoc); codigoc = _codigoc;
					cout<<"Ingrese el Año o periodo: ";
					cin>>alu.fechaingreso; strcpy(_fechaingreso,alu.fechaingreso); fechaingreso = _fechaingreso;
														
					//insertarInicio(lista, _dato, nombre, apellido, correo, fecha, telefono, codigoc, fechaingreso ); ///insert memoria virtual
					cout<< _dato << "-->"<<  nombre <<"-->"<< apellido <<"-->"<< correo <<"-->"<< fecha << "-->"<< telefono <<"-->"<<codigoc <<"-->"<< fechaingreso <<endl ; 
					cout<< _dato<< nombre << apellido << correo << fecha<< telefono<<endl;
					cout<<" Intruccion base de datos SQL"<<endl;				
				     bool  pregunta = false;
				     cout<<" Desea guardar esta informacion en Base de datos ingrese 0 No / 1 si  "<<endl;
				     cin >> pregunta; 
				
						if 	(pregunta == true)
						
						{
								op.insertar(alu);
								cout<<op.resultado;
						}
						else
						{
						         cout<<"Datos guardados unicamente en memoria"<<endl;
						         insertarInicio(lista, _dato, nombre, apellido, correo, fecha, telefono, codigoc, fechaingreso );
						}
	
	
				}break;
				
				case 2:	
					{
																																																																														
					clalumno op;
					
					cout<<"Ingrese Código de Alumno a Eliminar: ";
					cin>>alu.carnet; _dato = atoi(alu.carnet);
					
					cout<<" Intruccion base de datos SQL"<<endl;				
				     bool  pregunta = false;
				     cout<<" Desea eliminar esta informacion en Base de datos ingrese 0 No / 1 si  "<<endl;
				     cin >> pregunta; 
				
						if 	(pregunta == true)
						
						{
								op.eliminar(alu);
								cout<<op.resultado;
						}
						else
						{
								 eliminarElemento(lista, _dato);	
						         cout<<"se ha eliminado unicamente en memoria"<<endl;
						}						
                																	
				    	}
				break;
				
				case 3:
					{
					
					cout<<"Modificar Datos de Alumno\n";
					cout<<"Ingrese ID : ";
					cin>>alu.carnet; _dato = atoi(alu.carnet);
					
					
					bool pregunta = false;
					
					if (pregunta== true )
					
					
					
					
					cout<<"Modificar Datos de Alumno\n";
					cout<<"Ingrese ID : ";
					cin>>alu.carnet;
					cout<<"\nModificará Registros del Alumno con ID "<<alu.carnet<<endl;
					cout<<"\nIngrese Nuevo Nombre: ";
					cin>>alu.nombre;
					cout<<"Ingrese Nuevo Apellido Paterno: ";
					cin>>alu.apellido;
					op.modificar(alu);
					cout<<op.resultado;
			}
				break;
				
				case 4:
					
				{
				
					op.mostrar();
			}
				break;
				
				case 5:
					{
					
					 cout << "\n\n MOSTRANDO LISTA\n\n";
                 	 reportarLista(lista);
                 	 
					}break;
				
				case 6:
					{
					
					 cout<<"\n Valor a buscar: "; cin>> _dato;
                     buscarElemento(lista, _dato);
                 	 
					}break;
				
				
				case 9: 
				{
				
				salir();
				
				}break;
				default:
				{
					
				cout<<"Opción Incorrecta\n";
			}
		}
		} while(opcion!=8);
	}//while(opcion!=5);
		
	
int main() {
	///setlocale(LC_CTYPE,"Spanish");
	menu();
	return 0;
}
