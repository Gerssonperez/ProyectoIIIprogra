}	

break;		
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
