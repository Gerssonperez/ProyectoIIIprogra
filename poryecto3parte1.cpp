#include<iostream>
#include<mysql.h>
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
