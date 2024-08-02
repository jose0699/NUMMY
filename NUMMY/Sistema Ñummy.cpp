/* 
Aaron Maximiliano Palacios Quintero - C.I: 28.327.562
Asdrúbal Alejandro Asencio Acosta - C.I: 29.751.577
Guillermo José Mendez Deffit - C.I: 29.555.697
José Luis Lopez Asencio - C.I: 27.392.939
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h> 
#include <unistd.h>
enum Colors {
BLACK=0,BLUE=1,GREEN=2,CYAN=3,RED=4,MAGENTA=5,BROWN=6,LGREY=7,DGREY=8,LBLUE=9,LGREEN=10,LCYAN=11,LRED=12,LMAGENTA=13,YELLOW=14,WHITE=15};
void Color(int Texto,int Fondo){
	int T=0;
	T= Texto + (Fondo*16);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),T); 
}
void ColorB(){
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15); 
}
struct DPI{
    int CodigoPr;
	int Cantidad;
    int Precio;
    struct DPI *prox;
};
struct Pedido{
    int NumFactura;
    int CodigoEm;
    char Fecha[15];
    bool Entregado;
    int Monto;
    struct Pedido *prox;
    struct DPI *DPI;
};
struct Producto{
    int CodigoPr;
    char Descr[20];
    int PrecioCU;
    bool Act;
    struct Producto *prox;
};
struct Empresa{
    int CodigoEm;
    char Nombre[20];
    int Tipo;
    char Telf[12];
    char Dir[40];
    struct Empresa *prox;
    struct Producto *prod;
};
struct Persona{
    long long int Cedula;
    char NyP[20];
    char FechaN[15];
    char CiuN[15];
    char Dir[40];
    struct Persona *prox;
    struct Pedido *ped;
};
///////////////////////////////////////////MENU DE PERSONAS (INICIO)/////////////////////////////////////////////////////////
int existepersona(Persona *l, long long int CI){
	int existe=0;
	while(l){
		if(CI==l->Cedula){
			existe=1;
			break;
		}	
		l=l->prox;	
	}
	return existe;
}
void agregarpersona(Persona **cab){
	Persona *t = new Persona;
	int ao,mes,dia,contador=0;
	char stringfecha[10]="",b[2],c[2];
	strcpy( t->NyP,"") ; 
	strcpy( t->FechaN,"") ; 
	strcpy( t->CiuN,"") ; 
	strcpy( t->Dir,"") ;
	do{
	printf("\n\n\t Por favor indique:\n");
	Color(YELLOW,BLACK);printf("\n\t Cedula de Identidad de la Persona: ");ColorB();
	scanf("%lli", &(t->Cedula));
	    if((t->Cedula)<0){
	      system("cls");
	  	  Color(LRED,BLACK);
	  	  printf("\n\n\t *ERROR: El numero de cedula de una persona debe ser mayor o igual a O...Intente otra vez*");
	  	  ColorB();
	  	  printf("\n\n\t ");
	  	  system("pause");
	  	  system("cls");
	  	  contador++;
	  	    if(contador<3){
	  	  	  Color(YELLOW,BLACK);
		      printf("\n\t MENU PRINCIPAL:");
		      Color(LMAGENTA,BLACK);
		      printf("\n\t\t 1.)MENU DE PERSONAS:");
		      printf("\n\t\t\t 1.1)AGREGAR PERSONA:");
		      ColorB();
		      printf("\n");
			}
	   } else 
	       break;
    } while(contador<3);
	if(!existepersona(*cab,t->Cedula) && contador<3){
		do{
			Color(YELLOW,BLACK);printf("\n\t Nombres y Apellidos (hasta 20 caracteres): ");ColorB();
			fflush(stdin);
			scanf("%[^\n]s",&t->NyP);
			if (!(strlen(t->NyP)>=1 && strlen(t->NyP)<=20)){
				Color(LRED,BLACK);
				printf("\n\n\t *ERROR: Introdujiste un nombre muy largo o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (!(strlen(t->NyP)>=1 && strlen(t->NyP)<=20));
		Color(YELLOW,BLACK);printf("\n\t Indique la Fecha de Nacimiento:");
		do{
			printf("\n\n\t\t Anualidad (entre 1900 y 2100): ");ColorB();
			scanf("%i",&ao);
			if (ao<1900 || ao>2100){
				Color(LRED,BLACK);
				printf("\n\n\t *ERROR: Introdujiste un numero menor a 1900 o mayor a 2100...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (ao<1900 || ao>2100);
		itoa(ao,stringfecha,10);
		strcat(stringfecha,"/");
		do{
			Color(YELLOW,BLACK);printf("\n\t\t Mes (entre 1 y 12): ");ColorB();
			scanf("%i",&mes);
			if (mes<1 || mes>12){
				Color(LRED,BLACK);
				printf("\n\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 12...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (mes<1 || mes>12);
		itoa(mes,b,10);
		strcat(stringfecha,b);
		strcat(stringfecha,"/");
		do{
			Color(YELLOW,BLACK);printf("\n\t\t Dia (entre 1 y 31): ");ColorB();
			scanf("%i",&dia);
			if (dia<1 || dia>31){
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 30...Intentelo otra vez");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (dia<1 || dia>31);
		itoa(dia,c,10);
		strcat(stringfecha,c);
		strcpy(t->FechaN,stringfecha) ;
		fflush( stdin );
		do{
			Color(YELLOW,BLACK);printf("\n\t Ciudad de Nacimiento (hasta 15 caracteres): ");ColorB();
			fflush(stdin);
			scanf("%[^\n]s",&t->CiuN);
			if (!(strlen(t->CiuN)>=1 && strlen(t->CiuN)<=15)){
				Color(LRED,BLACK);
				printf("\n\n\t *ERROR: Introdujiste una ciudad de nombre muy largo o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (!(strlen(t->CiuN)>=1 && strlen(t->CiuN)<=15));
		do{
			Color(YELLOW,BLACK);printf("\n\t Direccion (hasta 40 caracteres): ");ColorB();
			fflush(stdin);
			scanf("%[^\n]s",&t->Dir);
			if (!(strlen(t->Dir)>=1 && strlen(t->Dir)<=40)){
				Color(LRED,BLACK);
				printf("\n\n\t *ERROR: Introdujiste una direccion muy larga o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (!(strlen(t->Dir)>=1 && strlen(t->Dir)<=40));
		t->ped=NULL;
		t->prox=*cab;
		*cab=t;
		Color(LGREEN,BLACK);
		printf("\n\t *PERSONA REGISTRADA CON EXITO*");
	}else{
		system("cls");
		Color(LRED,BLACK);	
		if(contador<3)
		printf("\n\t *ERROR: Actualmente ya se encuentra registrada una persona con ese numero de cedula...Intentelo otra vez*");
		else
		printf("\n\t *ERROR: Usted ha intentado ingresar una cedula invalida mas de dos veces...Intentelo otra vez*");	
		ColorB();	
		delete(t);
	}
}
void mostrarDPI(DPI *P){
	printf("\n\t Detalle de Pedido: \n\n");
	while(P){
		printf("\n\t |CODE#%i %i X %i = $%i| \n", P->CodigoPr,P->Precio,P->Cantidad,P->Precio*P->Cantidad);
		P=P->prox;	
	}
}
void mostrarpersona(Persona *l){
	printf("\n\n\t Los datos de la persona son:\n\n");	
	Color(YELLOW,BLACK);printf("\n\t Cedula de Identidad: ");ColorB();printf("%i \n", l->Cedula);
	Color(YELLOW,BLACK);printf("\n\t Nombres y Apellidos :  ");ColorB();printf("%s \n", l->NyP );	
	Color(YELLOW,BLACK);printf("\n\t Fecha de Nacimiento (anualidad/mes/dia) : ");ColorB();printf("%s \n", l->FechaN);	
	Color(YELLOW,BLACK);printf("\n\t Ciudad de Nacimiento :  ");ColorB();printf("%s \n", l->CiuN);	
	Color(YELLOW,BLACK);printf("\n\t Direccion : ");ColorB();printf("%s \n", l->Dir);
}
void mostrarpedido(Pedido *P){
	while(P){
		printf("\n------------------------------------------------------------\n");
		printf("\n\t Los datos del pedido son: \n\n");
		printf("\n\t Numero de Factura : %i \n", P->NumFactura);
		printf("\n\t Codigo de Empresa : %i \n", P->CodigoEm);
		printf("\n\t Fecha : %s \n", P->Fecha);
		printf("\n\t Entregado : %i \n", P->Entregado);
		printf("\n\t Monto Total : %i \n", P->Monto);
		mostrarDPI(P->DPI);
		P=P->prox;  
	}
	printf("\n------------------------------------------------------------\n");	
}
void modificarpersona(Persona *l){
	long long int CIpersona=0;
	int ao,mes,dia;
	char stringfecha[10]="",b[2],c[2];
	int opcion,salir,op,entro=0;
	int contador=0;
	if(l){
		do{	
			printf("\n\n\t Indique el numero de cedula de la persona: ");
			scanf("%i", &CIpersona); 
			if (!existepersona(l,CIpersona)){
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Numero de cedula invalido...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");
				contador++;	
			}else{
				break;
				system("cls");	
			}
			Color(YELLOW,BLACK);
			printf("\n\t MENU PRINCIPAL:");
			Color(LMAGENTA,BLACK);
			printf("\n\t\t 1.)MENU DE PERSONAS:");
			printf("\n\t\t\t 1.2)MODIFICAR PERSONA:\n\n");
			ColorB();	   
		}while((contador!=3));	
		if(contador==3){
			system("cls");
			Color(LRED,BLACK);	
			printf("\n\t *ERROR: Usted ha intentado ingresar una cedula invalida mas de dos veces...Intentelo otra vez*");	
			ColorB();
		}  
		while(l){
			if (l->Cedula == CIpersona){
				system("cls"); 
					do{
						Color(YELLOW,BLACK);
						printf("\n\t MENU PRINCIPAL:");
						Color(LMAGENTA,BLACK);
						printf("\n\t\t 1.)MENU DE PERSONAS:");
						printf("\n\t\t\t 1.2)MODIFICAR PERSONA:");
						ColorB();
						mostrarpersona(l);			
						printf("\n\n\t Seleccione el campo a modificar:");
						printf("\n\n\t 1.) NOMBRES Y APELLIDOS:"); 
						printf("\n\n\t 2.) FECHA DE NACIMIENTO:"); 
						printf("\n\n\t 3.) CIUDAD DE NACIMIENTO:"); 
						printf("\n\n\t 4.) DIRECCION:");
						printf("\n\n\t 0.) VOLVER:");
						printf("\n\n\t\t Numero de Opcion: ");Color(LMAGENTA,BLACK);
						scanf("%i", &opcion);
						ColorB;
						switch(opcion){
							case 0: break;
							case 1: 
								strcpy(l->NyP,"");
								printf("\n");
								do{
									printf("\n\t Indique los nombres y apellidos (hasta 20 caracteres): ");
									fflush(stdin);
									scanf("%[^\n]s",&l->NyP);
									if (!(strlen(l->NyP)>=1 && strlen(l->NyP)<=20)) {
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste un nombre muy largo o sin ningun caracter...Intentelo otra vez*");
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");	
									}	
								}while(!(strlen(l->NyP)>=1 && strlen(l->NyP)<=20));
								Color(LGREEN,BLACK);
								printf("\n\t*PERSONA MODIFICADA CON EXITO*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
							break;
							case 2: 
								printf("\n\t Indique la Fecha de Nacimiento:");
								do{
									printf("\n\n\t Anualidad (entre 1900 y 2100): ");
									scanf("%i",&ao);
									if (ao<1900 || ao>2100) {
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste un numero menor a 1900 o mayor a 2100*");
										ColorB();
										printf("\n\n\t "); 
										system("pause");
										system("cls");	
									}	
								}while (ao<1900 || ao>2100);
								itoa(ao,stringfecha,10);
								strcat(stringfecha,"/");
								do{
									printf("\n\n\t Mes (entre 1 y 12): ");
									scanf("%i",&mes);
									if (mes<1 || mes>12) {
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 12...Intentelo otra vez*");
										ColorB();
										printf("\n\n\t "); 
										system("pause");
										system("cls");	
									}	
								}while (mes<1 || mes>12);
								itoa(mes,b,10);
								strcat(stringfecha,b);
								strcat(stringfecha,"/");
								do{
									printf("\n\n\t Dia (entre 1 y 31): ");
									scanf("%i",&dia);
									if (dia<1 || dia>31) {
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 30...Intentelo otra vez*");
										ColorB();
										printf("\n\n\t "); 
										system("pause");
										system("cls");	
									}	
								}while (dia<1 || dia>31);
								itoa(dia,c,10);
								strcat(stringfecha,c);
								strcpy(l->FechaN,stringfecha) ;
								Color(LGREEN,BLACK);
								printf("\n\t *PERSONA MODIFICADA CON EXITO*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
							break; 
							case 3: 
								printf("\n");
								strcpy(l->CiuN,"");
								do{	
									printf("\n\t Ciudad de Nacimiento (hasta 15 caracteres): ");
									fflush(stdin);
									scanf("%[^\n]s",&l->CiuN);
									if (!(strlen(l->CiuN)>=1 && strlen(l->CiuN)<=15)) {
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste una ciudad de nombre muy largo o sin ningun caracter...Intentelo otra vez*");
										ColorB();
										printf("\n\n\t "); 
										system("pause");
										system("cls");	
									}	
								}while (!(strlen(l->CiuN)>=1 && strlen(l->CiuN)<=15));
								Color(LGREEN,BLACK);
								printf("\n\t *PERSONA MODIFICADA CON EXITO*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
							break;
							case 4:
								strcpy(l->Dir,"") ;
								do{
									printf("\n\t Direccion (hasta 40 caracteres): ");
									fflush(stdin);
									scanf("%[^\n]s",&l->Dir);
									if (!(strlen(l->Dir)>=1 && strlen(l->Dir)<=40)){
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Introdujiste una direccion muy larga o sin ningun caracter...Intentelo otra vez*");
										ColorB();
										printf("\n\n\t "); 
										system("pause");
										system("cls");	
									}	
								}while (!(strlen(l->Dir)>=1 && strlen(l->Dir)<=40));
								Color(LGREEN,BLACK);
								printf("\n\t *PERSONA MODIFICADA CON EXITO*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
							break;
							default:
								Color(LRED,BLACK);
								printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
								ColorB();
								printf("\n\n\t "); 
								system("pause");
							break;
						}
						system("cls");	
					}while(opcion!=0); 
			}
		   l=l->prox;	
		} 	
	}else{
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Actualmente no hay personas registradas en el sistema...Intentelo otra vez*");
		ColorB();	
	}  	
}
void cambio(char c1[], int longitud){
	int i;
	for(i=0;i<longitud;i++){
		if(c1[i]=='\n')
		   c1[i]='\0';
	}
}
void consultarpersona(Persona *per){
	Persona *aux=per;
	int opcion,cedula,j,booleano=0;
	int contador=0;
	char nombre[20];
	if(per){
		do{
 	        per=aux;
            contador=0;
            booleano=0;
			printf("\n\n\t Indique la forma de consulta:");
			printf("\n\n\t 1.) POR CEDULA:");
			printf("\n\n\t 2.) POR NOMBRE Y APELLIDO:");
			printf("\n\n\t 0.) VOLVER:");
			printf("\n\n\t\t Numero de Opcion: ");Color(LMAGENTA,BLACK); 
			scanf("%i", &opcion);
			ColorB;
			switch(opcion){
				case 0: break;
				case 1:  
					do{
						system("cls");
						Color(YELLOW,BLACK);
						printf("\n\t MENU PRINCIPAL:");
						Color(LMAGENTA,BLACK);
						printf("\n\t\t 1.)MENU DE PERSONAS:");
						printf("\n\t\t\t 1.3)CONSULTA DE PERSONA:\n");
						ColorB();
						printf("\n\t Indique la cedula de identidad: ");
						scanf("%i", &cedula);
						while(per && booleano==0){
							if (per->Cedula == cedula){
								mostrarpersona(per);
							    booleano=1;
								printf("\n\n\t ");
								system("pause");
								break;
							} 
							per=per->prox;	
						}
						if(booleano==0){
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Numero de cedula invalido...Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							contador++;	
						} else 
				           break;	
						if(contador==3){
							system("cls");
							Color(LRED,BLACK);	
							printf("\n\t *ERROR: Usted ha intentado ingresar una cedula invalida mas de dos veces...Intentelo otra vez*");	
							ColorB();
							printf("\n\n\t ");
							system("pause");
						}    
						per=aux;
						booleano=0;
					}while(contador!=3);
				break;
				case 2:   
					do{
						strcpy(nombre,"");
						system("cls");
						Color(YELLOW,BLACK);
						printf("\n\t MENU PRINCIPAL:");
						Color(LMAGENTA,BLACK);
						printf("\n\t\t 1.)MENU DE PERSONAS:");
						printf("\n\t\t\t 1.3)CONSULTA DE PERSONA:");
						ColorB();
						printf("\n\n\t Indique los nombres y apellidos de la persona: ");
						fflush(stdin);
						fgets(nombre,20,stdin);
						cambio(nombre, strlen(nombre));
		                    while(per){	
							    if (strcmp(nombre, per->NyP) == 0){
								    mostrarpersona(per);
							        booleano=1;
								    printf("\n\n\t ");
								    system("pause");
								    break;
							    }  
							  per=per->prox;
						    }
						if(booleano==0){
							Color(LRED,BLACK);
							printf("\n\n\t *ERROR: Nombre y apellido invalido...Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							contador++;	
						} else if(booleano==1) {
		                  break;	
					    }	  	   
						if(contador==3){
							system("cls");
							Color(LRED,BLACK);	
							printf("\n\t *ERROR: Usted ha intentado ingresar un nombre y apellido mas de dos veces...Intentelo otra vez*");	
							ColorB();
							printf("\n\n\t ");
							system("pause");
						}    
						per=aux;
						booleano=0;
					}while(contador!=3);
				break;	
				default: 
					Color(LRED,BLACK);
					printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
				break;  
				}
			system("cls");
			Color(YELLOW,BLACK);
			printf("\n\t MENU PRINCIPAL:");
			Color(LMAGENTA,BLACK);
			printf("\n\t\t 1.)MENU DE PERSONAS:");
			printf("\n\t\t\t 1.3)CONSULTA DE PERSONA:\n");
			ColorB();
		}while (opcion!=0);	
	}else{
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Actualmente no hay personas registradas en el sistema...Intentelo otra vez*");	
		ColorB();
		printf("\n\n\t ");
		system("pause");
	}
}
void eliminar (Persona **p, int cedula){
	Persona *t=*p;
	if (t)
	if (t->Cedula==cedula){
		*p=(*p)->prox;
		delete( t); 
	}
	else{ 
		while ((t->prox)&&(t->prox->Cedula != cedula)) 
		t=t->prox;
		if (t->prox){
			Persona *aux= t->prox;
			t->prox = t->prox->prox;
			delete( aux );
		}
	}
}
void eliminarlistaDPI(DPI **P){
	while(*P){
		DPI *aux=*P;
		delete(aux);
		*P=(*P)->prox;	
	}
}
void eliminarlistaPedido(Pedido **P){
	while(*P){
		Pedido *aux=*P;
		delete(aux);
		*P=(*P)->prox;	
	}
}
void eliminarpersona(Persona **cab){
	Persona *per=*cab;	
	int j,cedula;
	int contador=0;
	if(per){
		do{
			system("cls");   	
			Color(YELLOW,BLACK);
			printf("\n\t MENU PRINCIPAL:");
			Color(LMAGENTA,BLACK);
			printf("\n\t\t 1.)MENU DE PERSONAS:");
			printf("\n\t\t\t 1.4)ELIMINAR PERSONA:");
			ColorB();   
			printf("\n\n\t Indique la cedula de identidad de la persona a eliminar: ");
			scanf("%i", &cedula);
			if(existepersona(per,cedula)){
				if((*cab)->ped){
					eliminarlistaDPI(&(*cab)->ped->DPI);
					eliminarlistaPedido(&(*cab)->ped);	
				}
				eliminar (&*cab,cedula);              
				Color(LGREEN,BLACK);
				printf("\n\t *PERSONA ELIMINADA CON EXITO*");
				break;
			}else{
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Numero de cedula invalido...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				contador++;	
			}	
			if(contador==3){
				system("cls");
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Usted ha intentado ingresar una cedula invalida mas de dos veces...Intentelo otra vez*");	
				ColorB();
				printf("\n\n\t ");
				system("pause");
				break;
			}            
		}while(1);
	}else{
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Actualmente no hay personas registradas en el sistema...Intentelo otra vez*");
		ColorB();
	}	
}
/////////////////////////////////////////////FIN DE MENU DE PERSONAS/////////////////////////////////////////////////////
/////////////////////////////////////////////MENU DE EMPRESAS (INICIO)//////////////////////////////////////////////////
//Inserta en una variable con empresas, una empresa dada
void InsertarEmpresa (Empresa **original, Empresa *nueva) {
Empresa *aux;
aux = *original;	
	if ( *original == NULL  || ((*original)->CodigoEm == -1)) {
	*original = nueva;	
	} else {	
		while (aux->prox) {	
		aux = aux->prox;	
		}		
		aux->prox = nueva;	
	}	
}
//Devuele 1 si existe una empresa con el codigo dado, 0 en el caso contrario
int codigorepetido (Empresa *Original, int Codigo) {
int resultado;
resultado = 0;
	while (Original) {
	if (Original->CodigoEm == Codigo) {	
	resultado = 1;	
	}
	Original = Original->prox;	
	}
return resultado;		
}
void AgregarEmpresa (Empresa **valorempresaoriginal) {	
	Empresa *valorempresa;
	valorempresa = new struct Empresa;
	do{
	Color(YELLOW,BLACK);
	printf("\n\n\t Introduzca el codigo de la empresa: ");
	ColorB();
	scanf("%i",&(valorempresa->CodigoEm));
		if (codigorepetido(*valorempresaoriginal,valorempresa->CodigoEm)) {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Codigo de empresa repetido...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
		}
		if (valorempresa->CodigoEm < 0) {
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Codigo de empresa no valido...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");	
		system("pause");
		system("cls");			
		}		
	}
	while (!(valorempresa->CodigoEm>=0) || (codigorepetido(*valorempresaoriginal,valorempresa->CodigoEm) == 1));
	do {
	Color(YELLOW,BLACK);
	printf("\n\n\t Introduzca el nombre de la empresa: ");
	ColorB();
	fflush(stdin);
	scanf("%[^\n]%*c",valorempresa->Nombre);
		if (!(strlen(valorempresa->Nombre)>=1 && strlen(valorempresa->Nombre)<=20)) {
		printf("\n\t *ERROR: Nombre muy largo o sin ningun caracter...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
		}	
	}
	while (!(strlen(valorempresa->Nombre)>=1 && strlen(valorempresa->Nombre)<=20));
	do {
	Color(YELLOW,BLACK);	
	printf("\n\n\t Introduzca tipo de empresa:");
	printf("\n\n\t\t 1.)EMPRESA DE COMIDAS");
	printf("\n\t\t 2.)EMPRESA DE ALIMENTOS");
	printf("\n\t\t 3.)EMPRESA GENERAL");
	printf("\n\n\t\t Tipo: ");ColorB();
	scanf("%i",&(valorempresa->Tipo));
		if (!(valorempresa->Tipo == 1 || valorempresa->Tipo == 2 || valorempresa->Tipo == 3)) {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");	
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");		
		}	
	} while (!(valorempresa->Tipo == 1 || valorempresa->Tipo == 2 || valorempresa->Tipo == 3));
	do {
	Color(YELLOW,BLACK);
	printf("\n\n\t Introduzca el telefono de la empresa: ");
	ColorB();
	scanf("%s",valorempresa->Telf);
		if (!(strlen(valorempresa->Telf)>=1 && strlen(valorempresa->Telf)<=12)) {
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Numero de telefono muy largo o sin ningun caracter...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
		}	
	}
	while (!(strlen(valorempresa->Telf)>=1 && strlen(valorempresa->Telf)<=12));
	do {
	Color(YELLOW,BLACK);	
	printf("\n\n\t Introduzca la direccion de la empresa: ");
	ColorB();
	fflush(stdin);
	scanf("%[^\n]%*c",valorempresa->Dir);
		if (!(strlen(valorempresa->Dir)>=1 && strlen(valorempresa->Dir)<=40)) {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Direccion muy larga o sin ningun caracter...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
		}	
	}
	while (!(strlen(valorempresa->Dir)>=1 && strlen(valorempresa->Dir)<=40));
	valorempresa->prox = NULL;
	valorempresa->prod = NULL;
	InsertarEmpresa(valorempresaoriginal,valorempresa);
	Color(LGREEN,BLACK);
	printf("\n\t *EMPRESA AGREGADA CON EXITO*");				
}
//Devuelve 1 si hay un producto con el mismo codigo, 0 si no
int ProductoRepetido (Producto *p, int Codigo) {
	while (p) {
		if (p->CodigoPr == Codigo) {
		return 1;	
		}	
	p = p->prox;	
	}
	return 0;
}
//Muestra los datos de la primera empresa que se encuentre en la lista
void ConsultarEmpresa (Empresa valorempresa) {
	printf("\n\n\t Los datos de la empresa son: ");
	Color(YELLOW,BLACK);printf("\n\n\t Codigo: ");ColorB();printf("%i", valorempresa.CodigoEm);
	Color(YELLOW,BLACK);printf("\n\t Nombre: ");ColorB();printf("%s", valorempresa.Nombre);
	Color(YELLOW,BLACK);
		switch (valorempresa.Tipo) {
		case 1: printf("\n\t Tipo: ");ColorB();printf("Comidas (1)"); break;
		case 2: printf("\n\t Tipo: ");ColorB();printf("Alimentos(2)"); break;
		case 3: printf("\n\t Tipo: ");ColorB();printf("General(3)"); break;
		default: printf("\n\t Tipo: ");ColorB();printf("No asociado"); break;
		}
	Color(YELLOW,BLACK);printf("\n\t Telefono: ");ColorB();printf("%s", valorempresa.Telf);
	Color(YELLOW,BLACK);printf("\n\t Direccion: ");ColorB();printf("%s", valorempresa.Dir);			
}
//Modifica cualquier valor especificado de una empresa dada
void ModificarEmpresa (Empresa **valorempresaoriginal,Persona **valorpersona) {
Empresa *valorempresa;
valorempresa = *valorempresaoriginal;
int codigointroducido;
int op;
int codigo;
int salir;
salir = 0;
int intentos;
intentos = 3;
	do {
	do {	
	printf ("\n\n\t Escriba el codigo de la empresa a modificar: ");
	scanf ("%i", &codigo);
		if (codigo < 0) {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
		}
	} while (!(codigo>=0));
	while ((valorempresa) && (valorempresa->CodigoEm != codigo)) {	
	valorempresa = valorempresa->prox;	
	}
	if (valorempresa) {
	intentos = 0;	
		do {
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LCYAN,BLACK);
		printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
		printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
		printf("\n\t\t\t\t 2.1.2)MODIFICAR EMPRESA:");
		ColorB();	
		ConsultarEmpresa(*valorempresa);
		printf("\n\n\t Seleccione el campo a modificar:");
		printf("\n\n\t 1.)NOMBRE:");
		printf("\n\n\t 2.)TIPO:");
		printf("\n\n\t 3.)TELEFONO:");
		printf("\n\n\t 4.)DIRECCION:");
		printf("\n\n\t 0.)VOLVER:");
		printf("\n\n\t\t Numero de Opcion: ");	
		scanf("%i",&op);	
			switch (op) {
			case 1:
			do {	
			Color(YELLOW,BLACK);printf("\n\n\t Introduzca el nombre de la empresa: ");ColorB();
			fflush(stdin);
			scanf("%[^\n]%*c",valorempresa->Nombre);
				if (!(strlen(valorempresa->Nombre)>=1 && strlen(valorempresa->Nombre)<=20)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Nombre muy largo o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}	
			}
			while (!(strlen(valorempresa->Nombre)>=1 && strlen(valorempresa->Nombre)<=20));
			Color(LGREEN,BLACK);
			printf("\n\t *EMPRESA MODIFICADA CON EXITO*");
			salir = 1;		
			break;
			case 2:
			do {
			Color(YELLOW,BLACK);	
			printf("\n\n\t Introduzca tipo de empresa:");
			printf("\n\n\t\t 1.)EMPRESA DE COMIDAS");
			printf("\n\t\t 2.)EMPRESA DE ALIMENTOS");
			printf("\n\t\t 3.)EMPRESA GENERAL");
			printf("\n\n\t\t Tipo: ");ColorB();
			scanf("%i",&(valorempresa->Tipo));
				if (!(valorempresa->Tipo == 1 || valorempresa->Tipo == 2 || valorempresa->Tipo == 3)) {
				Color(LRED,BLACK);	
				printf("\n\t Valor no valido...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");		
				}	
			} while (!(valorempresa->Tipo == 1 || valorempresa->Tipo == 2 || valorempresa->Tipo == 3));
			Color(LGREEN,BLACK);
			printf("\n\t *EMPRESA MODIFICADA CON EXITO*");
			salir = 1;
			break;
			case 3:
			do {	
			Color(YELLOW,BLACK);printf("\n\n\t Introduzca telefono de la empresa: ");ColorB();
			scanf("%s",valorempresa->Telf);
				if (!(strlen(valorempresa->Telf)>=1 && strlen(valorempresa->Telf)<=12)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Numero de telefono muy largo o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}	
			}
			while (!(strlen(valorempresa->Telf)>=1 && strlen(valorempresa->Telf)<=12));
			Color(LGREEN,BLACK);
			printf("\n\t *EMPRESA MODIFICADA CON EXITO*");
			salir = 1;
			break;
			case 4:
			do {	
			Color(YELLOW,BLACK);printf("\n\n\t La direccion de la empresa: ");ColorB();
			fflush(stdin);
			scanf("%[^\n]%*c",valorempresa->Dir);
				if (!(strlen(valorempresa->Dir)>=1 && strlen(valorempresa->Dir)<=40)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Direccion muy larga o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}	
			}
			while (!(strlen(valorempresa->Dir)>=1 && strlen(valorempresa->Dir)<=40));
			Color(LGREEN,BLACK);
			printf("\n\t *EMPRESA MODIFICADA CON EXITO*");
			salir = 1;		
			break;
			case 0: system("pause"); break;	
			default:	
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");
			break;	
			}		
		} while ((op != 0) && (salir != 1));				
	} else {
	Color(LRED,BLACK);	
	printf("\n\t *ERROR: No hay ninguna empresa con ese codigo...Intentelo otra vez*");
	ColorB();
	printf("\n\n\t ");
	intentos = intentos - 1;
	valorempresa = *valorempresaoriginal;
	system("pause");
	system("cls");	
	}
	} while(intentos != 0);
}
//Muestra los datos de una empresa
void ConsultarEmpresa2 (Empresa *valorempresaoriginal){	
	int j,d,comprobacion;
	char nombreEMP[20];
	Empresa *valorempresa;
	valorempresa = valorempresaoriginal;
	int intentos;
	intentos = 3;
		do {			
		printf("\n\n\t Indique la forma de consulta:");
		printf("\n\n\t 1.)NOMBRE:");
		printf("\n\n\t 2.)CODIGO:");
		printf("\n\n\t 0.)VOLVER:");
		printf("\n\n\t\t Numero de la opcion: ");
		scanf ("%i", &j); 
		system("cls");
			switch (j) {
			case 1:
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(LCYAN,BLACK);
				printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
				printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
				printf("\n\t\t\t\t 2.1.3)CONSULTAR EMPRESA:");
				ColorB();
				printf("\n\n\t Introduzca el nombre de la empresa a consultar: ");
				fflush(stdin);
				fgets(nombreEMP,20,stdin);
				cambio(nombreEMP, strlen(nombreEMP));
					while ((valorempresa) && (strcmp(valorempresa->Nombre,nombreEMP) != 0)) {
					valorempresa = valorempresa->prox;	
					}
					if (valorempresa) {
					intentos = 0;	
					printf("\n\n\t Los datos de la empresa son: ");
					Color(YELLOW,BLACK);printf("\n\n\t Codigo: ");ColorB();printf("%i", valorempresa->CodigoEm);
					Color(YELLOW,BLACK);printf("\n\t Nombre: ");ColorB();printf("%s", valorempresa->Nombre);
					Color(YELLOW,BLACK);
						switch (valorempresa->Tipo) {
						case 1: printf("\n\t Tipo: ");ColorB();printf("Comidas (1)"); break;
						case 2: printf("\n\t Tipo: ");ColorB();printf("Alimentos(2)"); break;
						case 3: printf("\n\t Tipo: ");ColorB();printf("General(3)"); break;
						default: printf("\n\t Tipo: ");ColorB();printf("No asociado"); break;
						}
					Color(YELLOW,BLACK);printf("\n\t Telefono: ");ColorB();printf("%s", valorempresa->Telf);
					Color(YELLOW,BLACK);printf("\n\t Direccion: ");ColorB();printf("%s", valorempresa->Dir);
					} else {
					intentos = intentos -1;	
					valorempresa = valorempresaoriginal;
					Color(LRED,BLACK);
					printf("\n\t *ERROR: No existe ninguna empresa con ese nombre...Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
					system("cls");	
					}				
				break;
			case 2:
				do {
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(LCYAN,BLACK);
				printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
				printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
				printf("\n\t\t\t\t 2.1.3)CONSULTAR EMPRESA:");
				ColorB();	
				printf ("\n\n\t Escriba el codigo de la empresa: ");
				scanf ("%i", &d);
					if (d < 0) {
					Color(LRED,BLACK);	
					printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
					system("cls");	
					}				
				} while (!(d>=0));
					while ((valorempresa) && (valorempresa->CodigoEm != d)){	
					valorempresa = valorempresa->prox;	
					}
					if (valorempresa) {
					intentos = 0;
					printf("\n\n\t Los datos de la empresa son: ");
					Color(YELLOW,BLACK);printf("\n\n\t Codigo: ");ColorB();printf("%i", valorempresa->CodigoEm);
					Color(YELLOW,BLACK);printf("\n\t Nombre: ");ColorB();printf("%s", valorempresa->Nombre);
					Color(YELLOW,BLACK);
						switch (valorempresa->Tipo) {
						case 1: printf("\n\t Tipo: ");ColorB();printf("Comidas (1)"); break;
						case 2: printf("\n\t Tipo: ");ColorB();printf("Alimentos(2)"); break;
						case 3: printf("\n\t Tipo: ");ColorB();printf("General(3)"); break;
						default: printf("\n\t Tipo: ");ColorB();printf("No asociado"); break;
						}
					Color(YELLOW,BLACK);printf("\n\t Telefono: ");ColorB();printf("%s", valorempresa->Telf);
					Color(YELLOW,BLACK);printf("\n\t Direccion: ");ColorB();printf("%s", valorempresa->Dir);				
					}else{
					intentos = intentos -1;
					valorempresa = valorempresaoriginal;	
					Color(LRED,BLACK);
					printf("\n\t *ERROR: No existe ninguna empresa con ese nombre...Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
					system("cls");
					}
				break;
			case 0:
			intentos = 0;	
			break;	
			default:
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");		
				break;		
			}
		} while ((!(j == 1 || j == 2 || j == 0))  || (intentos != 0));				
}
//Devuelve 1 si el codigo se encuentra en una lista de facturas, 0 en caso contrario
int SeEncuentraCP (Pedido *p, int Codigo){
int resultado = 0;
Pedido *aux;
aux = p;
	while (aux) {
		if (aux->CodigoEm == Codigo) {
		resultado = 1;	
		}	
	aux = aux->prox;	
	}
	return resultado;	
}
//elimina la factura con el codigo de empresa dado
void eliminarmodfactura (Pedido **p, int x) {
	Pedido *t=*p;
	if (t)
	 if (t->CodigoEm==x){
		*p=(*p)->prox;
		free(t); }
	else { while ((t->prox)&&(t->prox->CodigoEm != x)) t=t->prox;
		if (t->prox){
			Pedido *aux= t->prox;
			t->prox = t->prox->prox;
			free( aux );
			}
	}	
}
//Elimina de facturas de las personas que contengan el codigo de una empresa eliminada
void EliminarEmpresa2(Persona **p, int Codigo) {
Persona *aux;
Pedido *aux2;
Pedido *eliminar;
aux = *p;
	while (aux) {
		while (SeEncuentraCP(aux->ped,Codigo)) {
		eliminarmodfactura(&(aux->ped),Codigo);	
		}
	aux = aux->prox;	
	}	
}
//Elimina la empresa con el codigo de empresa dado
void eliminarmodempresa ( Empresa **p, int x){
	Empresa *t=*p;
	if (t)
	 if (t->CodigoEm==x){
		*p=(*p)->prox;
		free(t); }
	else { while ((t->prox)&&(t->prox->CodigoEm != x)) t=t->prox;
		if (t->prox){
			Empresa *aux= t->prox;
			t->prox = t->prox->prox;
			free( aux );
			}
	}	
}
//Elimina una empresa
void EliminarEmpresa(Empresa **valorempresaoriginal, Persona **valorpersona) {
int codigo;
Empresa *valorempresa;
valorempresa = *valorempresaoriginal;
int intentos;
intentos = 2;
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa: ");
		scanf ("%i", &codigo);
			if (codigo<0) {
			Color(LRED,BLACK);	
			printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");	
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
			}
		} while (!(codigo>=0));
		while ((valorempresa) && (valorempresa->CodigoEm != codigo)) {	
		valorempresa = valorempresa->prox;	
		}
		if (valorempresa) {	
		valorempresa = NULL;
		EliminarEmpresa2(valorpersona,codigo);		
		eliminarmodempresa(valorempresaoriginal,codigo);
		intentos = 0;	
		Color(LGREEN,BLACK);
		printf("\n\t *EMPRESA ELIMINADA CON EXITO*");
		} else {
		intentos = intentos - 1;	
		valorempresa = *valorempresaoriginal;
		Color(LRED,BLACK);
		printf("\n\t *ERROR: No existe ninguna empresa con ese codigo...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");		
		}
	} while (intentos != 0);
}
//Inserta en una variable con productos, un producto dado
void InsertarProducto (Producto **original, Producto *nueva) {
Producto *aux;
aux = *original;	
	if (*original == NULL  || ((*original)->CodigoPr == -1)) {
	*original = nueva;	
	} else {	
		while (aux->prox) {	
		aux = aux->prox;	
		}		
		aux->prox = nueva;	
	}	
}
//Agrega un producto a una empresa dada
void AgregarProducto (Empresa **valorempresaoriginal){
int intentos = 2;
int codigo;	
Empresa *valorempresa;
valorempresa = *valorempresaoriginal;	
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa para agregarle un producto: ");Color(YELLOW,BLACK);
		scanf ("%i", &codigo);ColorB();
			if (codigo<0) {
			Color(LRED,BLACK);	
			printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");	
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
			}
		} while (!(codigo>=0));
		while ((valorempresa) && (valorempresa->CodigoEm != codigo)) {	
		valorempresa = valorempresa->prox;	
		}
		if (valorempresa) {
		intentos = 0;	
		Producto *valorproducto;
		valorproducto = new struct Producto;
		valorproducto->prox = NULL;
			do{
			printf("\n\n\t Introduzca el codigo del producto: ");Color(YELLOW,BLACK);
			scanf("%i",&(valorproducto->CodigoPr));ColorB();
				if (valorproducto->CodigoPr<0) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");	
				system("pause");
				system("cls");
				}
				if ((ProductoRepetido(valorempresa->prod,valorproducto->CodigoPr) == 1)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Codigo de producto repetido...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}						
			} while (!(valorproducto->CodigoPr>=0) || (ProductoRepetido(valorempresa->prod,valorproducto->CodigoPr) == 1));
			do {
			printf("\n\n\t Introduzca la descripcion del producto: ");Color(YELLOW,BLACK);
			fflush(stdin);
			scanf("%[^\n]%*c",valorproducto->Descr);ColorB();
				if (!(strlen(valorproducto->Descr)>=1 && strlen(valorproducto->Descr)<=20)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Descripcion muy larga o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}	
			} while (!(strlen(valorproducto->Descr)>=1 && strlen(valorproducto->Descr)<=20));
			do{	
			printf("\n\n\t Introduzca el precio del producto: $");Color(YELLOW,BLACK);
			scanf("%i",&(valorproducto->PrecioCU));ColorB();
				if (valorproducto->PrecioCU<0) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Valor no valido...Intentelo otra vez*");	
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}					
			} while (!(valorproducto->PrecioCU>=0));
			int activacion;
			do {
			printf("\n\n\t Introduzca estado del producto: ");
			Color(LGREEN,BLACK);printf("\n\n\t\t ACTIVO(1):");
			Color(LRED,BLACK);printf("\n\n\t\t INACTIVO(0):");
			ColorB();
			printf("\n\n\t\t Numero de la opcion: ");Color(YELLOW,BLACK);
			scanf("%i",&activacion);ColorB();
				if (!(activacion == 1 || activacion == 0)) {
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");		
				}	
			} while (!(activacion == 1 || activacion == 0));
			valorproducto->Act = activacion;
			InsertarProducto(&(valorempresa->prod),valorproducto);
			Color(LGREEN,BLACK);
			printf("\n\t *PRODUCTO AGREGADO CON EXITO*");		
		} else {
		Color(LRED,BLACK);	
		printf("\n\t ERROR: No hay ninguna empresa con ese codigo...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		intentos = intentos - 1;
		valorempresa = *valorempresaoriginal;
		system("pause");
		system("cls");	
		}
	} while (intentos != 0);		 		 	
}
//Muestra los datos del primer producto que se encuentre en la lista
void ConsultarProducto (Producto valorproducto) {
	printf("\n\n\t Los datos del producto son: ");
	Color(YELLOW,BLACK);printf("\n\n\t Codigo: ");ColorB();printf("%i", valorproducto.CodigoPr);
	Color(YELLOW,BLACK);printf("\n\t Descripcion: ");ColorB();printf("%s", valorproducto.Descr);
	Color(YELLOW,BLACK);printf("\n\t Precio: ");ColorB();printf("$%i", valorproducto.PrecioCU);
		switch (valorproducto.Act) {
		case 0: Color(LRED,BLACK);printf("\n\t INACTIVO(0):");break;
		case 1: Color(LGREEN,BLACK);printf("\n\t ACTIVO(1):");break;
		default: printf("\n\t El producto no tiene ningun estado de activacion"); break;	
		}	
}
//Modifica cualquier valor especificado de un producto dado
void ModificarProducto (Empresa **valorempresaoriginal,Persona **valorpersona) {
int intentos = 3;
Producto *valorproducto;
Producto *valorproductooriginal;	
Empresa *valorempresa = *valorempresaoriginal;
int CodigoNuevo;
int CodigoEm;
int CodigoPr;
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa cuyo producto va a modificar: ");
		scanf ("%i", &CodigoEm);
		printf("\n\n\t Escriba el codigo del producto a modificar: ");
		scanf ("%i", &CodigoPr);
				if ( (CodigoEm<0) || (CodigoPr<0)) {
				Color(LRED,BLACK);	
				printf("\n\t *ERROR: Codigo o codigos no validos...Intentelo otra vez*");	
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}		
		} while (!((CodigoEm>=0) || (CodigoPr>=0)));
			while ((valorempresa) && (valorempresa->CodigoEm != CodigoEm)) {	
			valorempresa = valorempresa->prox;	
			}
		if (valorempresa) {	
		valorproductooriginal = valorempresa->prod;
		valorproducto = valorproductooriginal;	
			while ((valorproducto) && (valorproducto->CodigoPr != CodigoPr)) {	
			valorproducto = valorproducto->prox;	
			}	
		}
		if (valorempresa && valorproducto) {
		intentos = 0;	
		int op;
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LCYAN,BLACK);
		printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
		printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
		printf("\n\t\t\t\t 2.2.2)MODIFICAR PRODUCTOS:");
		ColorB();
		ConsultarProducto(*valorproducto);
		ColorB();
		printf("\n\n\t Seleccione el campo a modificar:");
		printf("\n\n\t 1.)DESCRIPCION:");
		printf("\n\n\t 2.)PRECIO:");
		printf("\n\n\t 3.)ESTADO DE ACTIVACION:");
		printf("\n\n\t 0.)VOLVER:");
		printf("\n\n\t\t Numero de Opcion: ");	
		scanf("%i",&op);		
			switch(op) {
			case 1:
			do {
			printf("\n\n\t Introduzca la descripcion: ");Color(YELLOW,BLACK);
			fflush(stdin);
			scanf("%[^\n]%*c",valorproducto->Descr);ColorB();
				if (!(strlen(valorproducto->Descr)>=1 && strlen(valorproducto->Descr)<=20)) {
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Descripcion muy larga o sin ningun caracter...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}	
			}
			while (!(strlen(valorproducto->Descr)>=1 && strlen(valorproducto->Descr)<=20));	
			Color(LGREEN,BLACK);
			printf("\n\t *PRODUCTO MODIFICADO CON EXITO*");	
			break;	
			case 2:
			do{	
			printf("\n\n\t Introduzca el precio: $");Color(YELLOW,BLACK);
			scanf("%i",&(valorproducto->PrecioCU));ColorB();
				if (valorproducto->PrecioCU<0) {
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Valor no valida...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}					
			}
			while (!(valorproducto->PrecioCU>=0));
			Color(LGREEN,BLACK);
			printf("\n\t *PRODUCTO MODIFICADO CON EXITO*");
			break;	
			case 3:
			int activacion;	
			do {
			printf("\n\n\t Introduzca estado del producto: ");
			Color(LGREEN,BLACK);printf("\n\n\t\t ACTIVO(1):");
			Color(LRED,BLACK);printf("\n\n\t\t INACTIVO(0):");
			ColorB();
			printf("\n\n\t\t Numero de la opcion: ");Color(YELLOW,BLACK);
			scanf("%i",&activacion);ColorB();
				if (!(activacion == 1 || activacion == 0)) {
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");		
				}	
			} while (!(activacion == 1 || activacion == 0));
			Color(LGREEN,BLACK);
			printf("\n\t *PRODUCTO MODIFICADO CON EXITO*");
			valorproducto->Act = activacion;		
			break;			
			case 0:break;	
			default:
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");
			break;			
			}		
		} else {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Codigo de empresa o producto no existente...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		intentos = intentos - 1;
		valorproducto = valorproductooriginal;
		valorempresa = *valorempresaoriginal;
		system("pause");
		system("cls");	
		}
	} while (intentos != 0);	
}
//Muestra los datos de un producto
void ConsultarProducto2 (Empresa *valorempresaoriginal) {
int intentos = 3;	
int CodigoEm,CodigoPr;
Producto *aux;
Empresa *valorempresa;
valorempresa = valorempresaoriginal;
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa cuyo producto va a consultar: ");
		scanf ("%i", &CodigoEm);
		printf("\n\n\t Escriba el codigo del producto a consultar: ");
		scanf ("%i", &CodigoPr);
				if ( (CodigoEm<0) || (CodigoPr<0)) {
				Color(LRED,BLACK);	
				printf("\n\t Codigo o codigos no validos...Intentelo otra vez*");	
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
				}		
		} while (!((CodigoEm>=0) || (CodigoPr>=0)));
			while ((valorempresa) && (valorempresa->CodigoEm != CodigoEm)) {	
			valorempresa = valorempresa->prox;	
			}
		if (valorempresa) {	
		aux = valorempresa->prod;	
			while ((aux) && (aux->CodigoPr != CodigoPr)) {	
			aux = aux->prox;	
			}	
		}
		if (valorempresa && aux) {
		intentos = 0;
		ConsultarProducto(*aux);
		} else {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Codigo de empresa o producto  no existente...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");			
		intentos = intentos - 1;
		valorempresa = valorempresaoriginal;
		system("pause");
		system("cls");				
		}				
	} while (intentos!=0);	
}
//Sirve de apoyo para la siguiente función, EliminarSobras
void EliminarSobras2 (Pedido **p) {
	Pedido *t=*p;
	if (t)
	 if (t->DPI == NULL){
		*p=(*p)->prox;
		free(t); }
	else { while ((t->prox)&&(t->prox->DPI != NULL)) t=t->prox;
		if (t->prox){
			Pedido *aux= t->prox;
			t->prox = t->prox->prox;
			free( aux );
			}
	}	
}
//Devuelve 1 si un pedido tiene su lista de detalles en nulo, 0 en caso contrario
int HayNulo (Pedido *p) {
	while (p) {
		if (p->DPI == NULL) {
		return 1;	
		}	
	p = p->prox;	
	}
	return 0;
}
//Devuelve 1 si se encuentra un detalle de factura con el codigo de producto dado, 0 en caso contrario
int SeEncuentraCD (DPI *p, int Codigo) {
int resultado = 0;
DPI *aux;
aux = p;
	while (aux) {
		if (aux->CodigoPr == Codigo) {
		resultado = 1;	
		}	
	aux = aux->prox;	
	}
	return resultado;	
} 
//elimina el detalle de pedido con el codigo de producto dado, adicionalmente modifica la variable precio para colocarle el precio de los productos borrados
void eliminarmoddpi (DPI **p, int x, int *Precio, int *Cantidad) {
	DPI *t=*p;
	if (t)
	 if (t->CodigoPr==x){
	 	*Precio = t->Precio;
	 	*Cantidad = t->Cantidad;
		*p=(*p)->prox;
		free(t); }
	else { while ((t->prox)&&(t->prox->CodigoPr != x)) t=t->prox;
		if (t->prox){
			*Precio = t->prox->Precio;	
			*Cantidad = t->prox->Cantidad;	
			DPI *aux= t->prox;
			t->prox = t->prox->prox;
			free( aux );
			}
	}	
}
//Sirve de apoyo para la siguiente función, EliCodigo
void EliCodigoMod(DPI **P, int Codigo, int *Precio, int *Cantidad) {
	while (SeEncuentraCD(*P,Codigo)) {
	eliminarmoddpi(P,Codigo,&*Precio,&*Cantidad);	
	}	
}
//Elimina los detalles de las facturas que contengan el codigo de un producto que se eliminó
void EliCodigo (Persona **valorpersona, int Codigo , int Empresa) {
Persona *aux;	
Pedido *valorpedido;
DPI *valordpi;
aux = *valorpersona;
int Precio, Cantidad;
	while (aux) {
	valorpedido = aux->ped;
		while (valorpedido) {
			if (valorpedido->CodigoEm == Empresa) {	
			EliCodigoMod(&(valorpedido->DPI),Codigo,&Precio, &Cantidad);
			if(!valorpedido->Entregado)
			valorpedido->Monto = valorpedido->Monto - Precio*Cantidad;	
			}	
		valorpedido = valorpedido->prox;	
		}
	aux = aux->prox;	
	}
}
//Des pues del proceso de eliminación de los detalles se invoca esta función para eliminar aquellas facturas sin detalles
void EliminarSobras (Persona **valorpersona) {	
Persona *aux;
Pedido *aux2;
aux = *valorpersona;
	while (aux) {
	aux2 = aux->ped;
		while (HayNulo(aux2)) {
		EliminarSobras2(&aux2);	
		}				
	aux = aux->prox;
	}	
}
//Elimina el producto con el codigo de producto dado
void eliminarmodproducto ( Producto **p, int x){
	Producto *t=*p;
	if (t)
	 if (t->CodigoPr==x){
		*p=(*p)->prox;
		free(t); }
	else { while ((t->prox)&&(t->prox->CodigoPr != x)) t=t->prox;
		if (t->prox){
			Producto *aux= t->prox;
			t->prox = t->prox->prox;
			free( aux );
			}
	}	
}
//Elimina un producto dado para una empresa especifica 
void EliminarProducto (Empresa **valorempresaoriginal,Persona **valorpersona) {
int intentos = 2;
Producto *valorproducto;
Producto *valorproductooriginal;	
Empresa *valorempresa = *valorempresaoriginal;
int CodigoEm;
int CodigoPr;	
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa cuyo producto va a eliminar: ");
		scanf ("%i", &CodigoEm);
		printf("\n\n\t Escriba el codigo del producto a eliminar: ");
		scanf ("%i", &CodigoPr);
		} while (!((CodigoEm>=0) || (CodigoPr>=0)));
			while ((valorempresa) && (valorempresa->CodigoEm != CodigoEm)) {	
			valorempresa = valorempresa->prox;	
			}
		if (valorempresa) {	
		valorproductooriginal = valorempresa->prod;
		valorproducto = valorproductooriginal;	
			while ((valorproducto) && (valorproducto->CodigoPr != CodigoPr)) {	
			valorproducto = valorproducto->prox;	
			}	
		}
		if (valorempresa && valorproducto) {
		intentos = 0;
		valorproductooriginal = NULL;
		valorproducto = NULL;
		EliCodigo(valorpersona,CodigoPr,CodigoEm);
		EliminarSobras(valorpersona);
		eliminarmodproducto(&(valorempresa->prod),CodigoPr);
		Color(LGREEN,BLACK);
		printf("\n\t *PRODUCTO ELIMINADO CON EXITO*");
		} else {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Codigo de empresa o producto que no existe...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		intentos = intentos - 1;
		valorproducto = valorproductooriginal;
		valorempresa = *valorempresaoriginal;
		system("pause");
		system("cls");					
		}
	} while (intentos != 0);		
}
/////////////////////////////////////////////FIN DE MENU DE EMPRESAS Y PRODUCTOS///////////////////////////////////////
///////////////////////////////////////////////////MENU DE ORDENES DE ENVIO (INICIO)///////////////////////////////////
struct Persona *boolPersona(struct Persona **PER,int CI,int x,int Fact){
	struct Persona *aux = *PER;
	struct Pedido *aux2;
	for (  ; aux ; aux=aux->prox ){
		if (x==1)
			if(aux->Cedula==CI)
				return aux;	
		if (x==0){
			aux2 = aux->ped;
			for (  ; aux2 ; aux2=aux2->prox )
				if(aux2->NumFactura==Fact)
					return aux;
		}
	}
}
int boolTipo(struct Empresa **EMP,int T){
	struct Empresa *aux=*EMP;
	for (  ; aux ; aux=aux->prox )
		if(aux->Tipo==T)
		return 1;
		return 0;
}
int boolProducto(struct Empresa *EMP,int COD){
	struct Producto *aux=EMP->prod;
	for (  ; aux ; aux=aux->prox )
		if((aux->CodigoPr==COD) && (aux->Act==1))
		return aux->PrecioCU;
		return 0;
}
struct Pedido *boolNumFact(struct Persona **PER,int FactN){
	struct Persona *Per$ = *PER;
	struct Pedido *aux;
	for (  ; Per$ ; Per$=Per$->prox ){
		aux = Per$->ped;
		for (  ; aux ; aux=aux->prox )
			if (aux->NumFactura==FactN)
				return aux;
	}
	return aux;
}
struct Empresa *boolEmpresa(struct Empresa **EMP,int COD,int T){
	struct Empresa *aux=*EMP;
	for (  ; aux ; aux=aux->prox )
		if((aux->CodigoEm==COD) && (aux->Tipo==T))
		break;
	return aux;	
}
void AgregarDPI(struct Persona **PER,int COD,int Precio,int Cantidad,int Cont){
	struct Persona *Per$=*PER;
	struct Pedido *aux = Per$->ped;
	struct DPI *aux2;
	if (Cont!=0){
		aux2 = aux->DPI;
		for(  ; aux2 ; aux2=aux2->prox )
			if (aux2->CodigoPr==COD){
				aux2->Cantidad+=Cantidad;	
				break;
			}
		if (!aux2){
			aux2 = new struct DPI;
			aux2->prox=aux->DPI;
			aux->DPI=aux2;
			aux2->Cantidad=Cantidad;
			aux2->CodigoPr=COD;
			aux2->Precio=Precio;	
		}
	}else{
		aux = new struct Pedido;
		aux2 = new struct DPI;
		aux->prox=Per$->ped;
		Per$->ped=aux;
		aux->DPI=NULL;
		aux2->prox=aux->DPI;
		aux2->Cantidad=Cantidad;
		aux2->CodigoPr=COD;
		aux2->Precio=Precio;
		aux->DPI=aux2;
	}
}
void AgregarFactura(struct Persona **PER,int CodEMP,int MontoT,int FactN){
	struct Persona *Per$=*PER;
	struct Pedido *aux = Per$->ped;
	aux->CodigoEm=CodEMP;
	aux->Entregado=0;
	aux->Monto=MontoT;
	aux->NumFactura=FactN;
}
void AgregarFechaOE(Pedido *ped){
   int ao,mes,dia;
   char stringfecha[10]="",b[2],c[2];
   Color(YELLOW,BLACK);printf("\n\t Indique la Fecha del Pedido: \n ");
		do{
			printf("\n\t\t Anualidad (entre 1900 y 2100): ");ColorB();
			scanf("%i",&ao);
			if (ao<1900 || ao>2100){
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Introdujiste un numero menor a 1900 o mayor a 2100...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (ao<1900 || ao>2100);
		itoa(ao,stringfecha,10);
		strcat(stringfecha,"/");
		do{
			Color(YELLOW,BLACK);printf("\n\t\t Mes (entre 1 y 12): ");ColorB();
			scanf("%i",&mes);
			if (mes<1 || mes>12){
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 12...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (mes<1 || mes>12);
		itoa(mes,b,10);
		strcat(stringfecha,b);
		strcat(stringfecha,"/");
		do{
			Color(YELLOW,BLACK);printf("\n\t\t Dia (entre 1 y 31): ");ColorB();
			scanf("%i",&dia);
			if (dia<1 || dia>31){
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Introdujiste un numero menor a 1 o mayor a 30...Intentelo otra vez");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}	
		}while (dia<1 || dia>31);
		itoa(dia,c,10);
		strcat(stringfecha,c);
		strcpy(ped->Fecha,stringfecha) ;	
}
void MostrarEmpresaOE(struct Empresa *EMP){
	struct Producto *aux = EMP->prod;
	Color(YELLOW,BLACK);printf( "\n\n\t Codigo: ");ColorB();printf("%i",EMP->CodigoEm);
	Color(YELLOW,BLACK);printf( "\n\t Nombre: ");ColorB();printf("%s",EMP->Nombre);
	Color(YELLOW,BLACK);printf( "\n\t Tipo: ");ColorB();printf("%i",EMP->Tipo);
	Color(YELLOW,BLACK);printf( "\n\t Telefono: ");ColorB();printf("%s",EMP->Telf);
	Color(YELLOW,BLACK);printf( "\n\t Direccion: ");ColorB();printf("%s",EMP->Dir);
	printf( "\n\n\n\t PRODUCTOS:");
	for (  ; aux ; aux=aux->prox ){
		if (aux->Act==1){
			printf( "\n\n--------------------------------------------------------------------------\n\n");
			printf( "\t Codigo: %i",aux->CodigoPr);
			printf( "\n\n\t Descripcion: %s",aux->Descr);
			printf( "\n\n\t El precio por c/u es: $%i",aux->PrecioCU);	
		}
	}
	printf( "\n\n--------------------------------------------------------------------------\n\n");
}
int MostrarListaCompra(struct DPI *LISTA){
	int monto=0;
	struct DPI *aux = LISTA;
	printf("\n\t LISTA DE COMPRA:");
	printf("\n\n######################################################################\n\n");
	for (  ; aux ; aux=aux->prox ){
		printf( "\t CODIGO DEL PRODUCTO: No#%i %i X %i = $%i \n\n",aux->CodigoPr,aux->Precio,aux->Cantidad,aux->Precio*aux->Cantidad);
		monto+=aux->Precio*aux->Cantidad;
	}
	printf("\t MONTO TOTAL: $%i",monto);
	printf("\n######################################################################\n\n");
	return monto;
}
void MostrarFactura(struct Persona *PER,struct Pedido *PED){
	struct Persona *Per$ = PER;
	struct Pedido *aux;
	if (PED){
		aux = PED;
	}else{
		aux = Per$->ped;
	}
	struct DPI *aux2 = aux->DPI;
	printf("\n\n######################################################################\n\n");
	printf("\t CLIENTE: %s", Per$->NyP);
	printf("\n\n\t FACTURA No#%i", aux->NumFactura);
	printf("\n\n\t CODIGO DE LA EMPRESA No#%i", aux->CodigoEm);
	printf("\n\n\t FECHA: %s", aux->Fecha);
	if (aux->Entregado==1){
		printf("\n\n\t ENTREGADO: SI");
	}else{
		printf("\n\n\t ENTREGADO: NO");
	}
	printf("\n\n\n\t LISTA DE PRODUCTOS COMPRADOS:");
	printf( "\n\n----------------------------------------------------------------------\n\n");
	for (  ; aux2 ; aux2=aux2->prox ){
		printf( "\t CODIGO DEL PRODUCTO: No#%i %i X %i = $%i \n\n",aux2->CodigoPr,aux2->Precio,aux2->Cantidad,aux2->Precio*aux2->Cantidad);
	}
	printf("\t MONTO TOTAL: $%i",aux->Monto);
	printf( "\n\n----------------------------------------------------------------------\n\n");
	printf( "\n\n######################################################################\n\n");
}
void AgregarPedido(struct Persona **PER,struct Empresa **EMP){
	bool o=0;
	int op,cont=0,Tipo$,COD$,Cant$,Precio$,Monto$,Fact$,Cont$=0;
	struct Persona *Per$;
	struct Empresa *Emp$;
	struct DPI *Lista$ = NULL;
	while ( (o==0) && (cont<3) ){
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LGREEN,BLACK);
		printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
		printf("\n\t\t\t 3.1)SOLICITAR ENVIO:");
		ColorB();
		printf("\n\n\t Introduzca la cedula de la persona: ");
		scanf("%i",&op);
		system("cls");
		Per$=boolPersona(PER,op,1,0);
		if (Per$){
			Color(YELLOW,BLACK);
			printf("\n\t MENU PRINCIPAL:");
			Color(LGREEN,BLACK);
			printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
			printf("\n\t\t\t 3.1)SOLICITAR ENVIO:");
			ColorB();
			printf("\n\n\t Introduzca el tipo de empresa que busca(Comidas (1), Alimentos(2), General(3)): ");
			scanf("%i",&Tipo$);
			system("cls");
			if (boolTipo(EMP,Tipo$)){
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(LGREEN,BLACK);
				printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
				printf("\n\t\t\t 3.1)SOLICITAR ENVIO:");
				ColorB();
				printf("\n\n\t Introduzca el codigo de la empresa que busca: ");
				scanf("%i",&op);
				system("cls");
				Emp$=boolEmpresa(EMP,op,Tipo$);
				if(Emp$){
					while ((o==0) && (cont<3)){
						Color(YELLOW,BLACK);
						printf("\n\t MENU PRINCIPAL:");
						Color(LGREEN,BLACK);
						printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
						printf("\n\t\t\t 3.1)SOLICITAR ENVIO:");
						ColorB();
						MostrarEmpresaOE(Emp$);
						printf("\n\t Indique la opcion a realizar:");
						printf("\n\n\t 1.)AGREGAR PRODUCTO A LA LISTA DE COMPRA:");
						printf("\n\n\t 2.)VER LISTA DE COMPRA:");
						printf("\n\n\t 3.)TERMINAR PEDIDO:");
						printf("\n\n\t\t Numero de la opcion: ");
						scanf("%i",&op);
						switch (op){
							case 1:
								printf("\n\n\n\t Indique el codigo del producto que desea agregar a su compra: ");
								scanf("%i",&COD$);
								Precio$=boolProducto(Emp$,COD$);
								if (Precio$!=0){
									printf("\n\n\t Indique la cantidad que desea comprar: ");
									scanf("%i",&Cant$);
									if (Cant$>=1){
										AgregarDPI(&Per$,COD$,Precio$,Cant$,Cont$);
										Cont$++;
										Lista$=Per$->ped->DPI;
										system("cls");
									}else{
										cont++;
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Esta cantidad no es valida... Intentelo otra vez*");
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									}
								}else{
									cont++;
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Este producto no esta registrado en esta empresa o no esta activo... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								}
							break;
							case 2:
								Monto$=MostrarListaCompra(Lista$);
								printf("\n\n\t ");
								system("pause");
								system("cls");
							break;
							case 3:
								if (Lista$){
									while((o==0) && (cont<3)){
										system("cls");
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LGREEN,BLACK);
										printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
										printf("\n\t\t\t 3.1)SOLICITAR ENVIO:");
										ColorB();
										Monto$=MostrarListaCompra(Lista$);
										printf("\n\t Introduzca el numero de la factura: ");
										scanf("%i",&Fact$);
										if (!boolNumFact(PER,Fact$)){
											AgregarFactura(&Per$,Emp$->CodigoEm,Monto$,Fact$);
											AgregarFechaOE(Per$->ped);
											system("cls");	
											MostrarFactura(Per$,NULL);
											Color(LGREEN,BLACK);
											printf("\n\t *PEDIDO REGISTRADO CON EXITO*");
											o++;	
										}else{
											cont++;
											Color(LRED,BLACK);
											printf("\n\t *ERROR: Numero de factura ya existente... Intentelo otra vez*");
											ColorB();
											printf("\n\n\t ");
											system("pause");
											system("cls");	
										}
									}
								}else{
									cont++;
									Color(LRED,BLACK);
									printf("\n\t *ERROR: La lista de compra esta vacia... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								}
							break;
							default:
							cont++;
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
							break;
						}
					}
				}else{
					cont++;
					Color(LRED,BLACK);
					printf("\n\t *ERROR: Esta empresa no existe o no es del tipo que buscas... Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
					system("cls");
				}
			}else{
				cont++;
				Color(LRED,BLACK);
				printf("\n\t *ERROR: No hay empresas de este tipo... Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");
			}
		}else{
			cont++;
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Esta persona no existe... Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");
		}
	}
	if (cont==3){
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Exedio la cantidad de intentos disponibles... Intentelo otra vez*");
	}
}
struct Empresa *EmpresaOE(struct Empresa **EMP,int COD){
	struct Empresa *aux=*EMP;
	for (  ; aux ; aux=aux->prox )
		if(aux->CodigoEm==COD)
		break;
	return aux;	
}
void AgregarDPIv2(struct Pedido **PED,int COD,int Precio,int Cantidad){
	struct Pedido *aux = *PED;
	struct DPI *aux2 = aux->DPI;
	for (  ; aux2 ; aux2=aux2->prox )
		if (aux2->CodigoPr==COD){
			aux2->Cantidad+=Cantidad;
			break;	
		}
	if (!aux2){
		aux2 = new struct DPI;
		aux2->prox=aux->DPI;
		aux->DPI=aux2;
		aux2->Cantidad=Cantidad;
		aux2->CodigoPr=COD;
		aux2->Precio=Precio;
	}
}
int EliminarOE(struct Pedido **PED,struct Persona **PER){
	struct Persona *Per$ = *PER;
	struct Pedido *p = Per$->ped;
	struct Pedido *aux = *PED;
	struct DPI *aux2 = aux->DPI;	
	if(aux2->Cantidad==0){
		aux->DPI=aux2->prox;
		delete(aux2);
	}else{
		for (  ; aux2->prox ; aux2=aux2->prox )
			if (aux2->prox->Cantidad==0){
				struct DPI *t = aux2->prox;
				aux2->prox=aux2->prox->prox;
				delete(t);
				break;
			}
	}
	if (!aux->DPI){
		if (Per$->ped==aux){
			Per$->ped=aux->prox;
			delete(aux);
		}else{
			for (  ; p->prox ; p=p->prox )
			if (p->prox=aux){
				p->prox=aux->prox;
				delete(aux);
				break;
			}
		}
		return 1;
	}else{
		return 0;
	}
}
int EliminarDPI(struct Pedido **PED,struct Persona **PER,int COD,int Precio,int Cant){
	struct Pedido *Ped$ = *PED;
	struct DPI *aux = Ped$->DPI;
	struct DPI *t = aux;
	for (  ; aux ; aux=aux->prox )
		if ((aux->CodigoPr==COD)&&(aux->Cantidad>=Cant)){
			aux->Cantidad-=Cant;
			return 1;
		}
	return 0;
}
void ModificarPedido(struct Persona **PER,struct Empresa **EMP){
	int op,cont=0,COD$,Cant$,Precio$,Monto$;
	bool o=0;
	struct Pedido *Fact$;
	struct Empresa *Emp$;
	struct Persona *Per$;
	while((o==0) && (cont<3)){
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LGREEN,BLACK);
		printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
		printf("\n\t\t\t 3.2)MODIFICAR ENVIO:");
		ColorB();
		printf("\n\n\t Introduzca el numero de la factura: ");
		scanf("%i",&op);
		system("cls");
		Fact$=boolNumFact(PER,op);
		if(Fact$){
			if(Fact$->Entregado==0){
				while((o==0) && (cont<3)){
					Color(YELLOW,BLACK);
					printf("\n\t MENU PRINCIPAL:");
					Color(LGREEN,BLACK);
					printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
					printf("\n\t\t\t 3.2)MODIFICAR ENVIO:");
					ColorB();
					Emp$=EmpresaOE(EMP,Fact$->CodigoEm);
					Per$=boolPersona(PER,0,0,Fact$->NumFactura);
					MostrarEmpresaOE(Emp$);
					printf("\n\t Indique la opcion a realizar:");
					printf("\n\n\t 1.)AGREGAR PRODUCTO A LA LISTA DE COMPRA:");
					printf("\n\n\t 2.)QUITAR PRODUCTO DE LA LISTA DE COMPRA:");
					printf("\n\n\t 3.)VER LISTA DE COMPRA:");
					printf("\n\n\t 4.)TERMINAR PEDIDO:");
					printf("\n\n\t\t Numero de la opcion: ");
					scanf("%i",&op);
					switch(op){
						case 1:
							printf("\n\n\n\t Indique el codigo del producto que desea agregar a su compra: ");
							scanf("%i",&COD$);
							Precio$=boolProducto(Emp$,COD$);
							if (Precio$!=0){
								printf("\n\n\t Indique la cantidad que desea comprar: ");
								scanf("%i",&Cant$);
								if (Cant$>=1){
									AgregarDPIv2(&Fact$,COD$,Precio$,Cant$);
									Fact$->Monto=Fact$->Monto+Precio$*Cant$;
									system("cls");
								}else{
									cont++;
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Esta cantidad no es valida... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								}
							}else{
								cont++;
								Color(LRED,BLACK);
								printf("\n\t *ERROR: Este producto no esta registrado en esta empresa o no esta activo... Intentelo otra vez*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
								system("cls");
							}
						break;
						case 2:
							printf("\n\n\n\t Indique el codigo del producto que desea eliminar de su compra: ");
							scanf("%i",&COD$);
							Precio$=boolProducto(Emp$,COD$);
							if (Precio$!=0){
								printf("\n\n\t Indique la cantidad que desea eliminar: ");
								scanf("%i",&Cant$);
								if (Cant$>=1){
									if (EliminarDPI(&Fact$,&Per$,COD$,Precio$,Cant$)){
										Fact$->Monto=Fact$->Monto-Precio$*Cant$;
										system("cls");
										if(EliminarOE(&Fact$,&Per$)){
											system("cls");
											Color(YELLOW,BLACK);
											printf("\n\t MENU PRINCIPAL:");
											Color(LGREEN,BLACK);
											printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
											printf("\n\t\t\t 3.2)MODIFICAR ENVIO:");
											ColorB();
											printf("\n\n\t Usted elimino todos los productos del pedido. El pedido sera eliminado y usted sera re-dirigido al menu pricipal:");
											Color(LGREEN,BLACK);
											printf("\n\n\t *PEDIDO MODIFICADO CON EXITO*");
											o++;
										}
									}else{
										cont++;
										Color(LRED,BLACK);
										printf("\n\t *ERROR: No se encontro este producto con esta cantidad en su lista de compra... Intentelo otra vez*");
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									}
								}else{
									cont++;
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Esta cantidad no es valida... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								}
							}else{
								cont++;
								Color(LRED,BLACK);
								printf("\n\t *ERROR: Este producto no esta registrado en esta empresa o no esta activo... Intentelo otra vez*");
								ColorB();
								printf("\n\n\t ");
								system("pause");
								system("cls");
							}
						break;
						case 3:
							MostrarListaCompra(Fact$->DPI);
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
						case 4:
							system("cls");
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LGREEN,BLACK);
							printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
							printf("\n\t\t\t 3.2)MODIFICAR ENVIO:");
							ColorB();
							MostrarFactura(Per$,Fact$);
							Color(LGREEN,BLACK);
							printf("\n\n\t *PEDIDO MODIFICADO CON EXITO*");
							o++;
						break;
					}
				}
			}else{
				cont++;
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Este pedido ya fue entregado... Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}
		}else{
			cont++;
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Esta numero de factura no existe... Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
		}
	}	
}
void ConsultarPedido(struct Persona **PER){
	int op,cont=0;
	bool o=0;
	struct Persona *Per$;
	struct Pedido *Fact$;
	while((o==0) && (cont<3)){
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LGREEN,BLACK);
		printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
		printf("\n\t\t\t 3.3)CONSULTAR ENVIO:");
		ColorB();
		printf("\n\n\t Introduzca el numero de la factura: ");
		scanf("%i",&op);
		system("cls");
		Fact$=boolNumFact(PER,op);	
		if (Fact$){
			Color(YELLOW,BLACK);
			printf("\n\t MENU PRINCIPAL:");
			Color(LGREEN,BLACK);
			printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
			printf("\n\t\t\t 3.3)CONSULTAR ENVIO:");
			ColorB();
			Per$=boolPersona(PER,0,0,Fact$->NumFactura);
			MostrarFactura(Per$,Fact$);
			o++;
		}else{
			cont++;
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Esta numero de factura no existe... Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
		}
	}
}
void CierrePedido(struct Persona **PER){
	int op,cont=0;
	bool o=0;
	struct Persona *Per$;
	struct Pedido *Fact$;
	while((o==0) && (cont<3)){
		system("cls");
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LGREEN,BLACK);
		printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
		printf("\n\t\t\t 3.4)CIERRE DEL ENVIO:");
		ColorB();
		printf("\n\n\t Introduzca el numero de la factura: ");
		scanf("%i",&op);
		system("cls");
		Fact$=boolNumFact(PER,op);	
		if (Fact$){
			if (Fact$->Entregado==0){
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(LGREEN,BLACK);
				printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
				printf("\n\t\t\t 3.4)CIERRE DEL ENVIO:");
				ColorB();
				Per$=boolPersona(PER,0,0,Fact$->NumFactura);
				Fact$->Entregado=1;
				MostrarFactura(Per$,Fact$);
				Color(LGREEN,BLACK);
				printf("\n\n\t *CIERRE DE PEDIDO HECHO CON EXITO*");
				o++;
			}else{
				cont++;
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Este pedido ya fue entregado... Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}
		}else{
			cont++;
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Esta numero de factura no existe... Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
		}	
	}
}
void EliminarOE(struct Persona **PER,int COD){
	struct Persona *aux = *PER;
	struct Pedido *aux2 = aux->ped,*temp;
	if (aux2->NumFactura==COD){
		aux->ped=aux2->prox;
		free(aux2);
	}else{
		for (  ; aux2->prox ; aux2=aux2->prox )
			if (aux2->prox->NumFactura==COD){
				temp=aux2->prox;
				aux2->prox=aux2->prox->prox;
				free(temp);
			}
	}
}
void EliminarPedido(struct Persona **PER){
	int o=0,op,cont=0,COD$,Cedula$,Fact$;
	struct Persona *Per$;
	struct Pedido *Ped$;
	while ((o==0) && (cont<3)){
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		Color(LGREEN,BLACK);
		printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
		printf("\n\t\t\t 3.5)ELIMINAR ENVIO:");
		ColorB();
		printf("\n\n\t Introduzca el codigo de la empresa que contiene la factura: ");
		scanf("%i",&COD$);
		printf("\n\n\t Introduzca la cedula de la persona relacionada con la factura: ");
		scanf("%i",&Cedula$);
		printf("\n\n\t Introduzca el codigo de la factura: ");
		scanf("%i",&Fact$);
		system("cls");
		Per$=boolPersona(PER,Cedula$,1,0);
		if (Per$){
			if(boolPersona(PER,0,0,Fact$)){
				Ped$=boolNumFact(PER,Fact$);
				if (Ped$->CodigoEm==COD$){
					MostrarFactura(Per$,Ped$);
					EliminarOE(&Per$,Fact$);
					Color(LGREEN,BLACK);
					printf("\n\n\t *PEDIDO ELIMINADO CON EXITO*");
					o++;
				}else{
					cont++;
					Color(LRED,BLACK);
					printf("\n\t *ERROR: El codigo de empresa introducido no coincide con el de la factura... Intentelo otra vez*");
					ColorB();
					printf("\n\n\t ");
					system("pause");
					system("cls");	
				}
			}else{
				cont++;
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Esta numero de factura no existe... Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");	
			}
		}else{
			cont++;
			Color(LRED,BLACK);
			printf("\n\t *ERROR: Esta persona no existe... Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");	
		}
	}
}
//////////////////////////////////////////////////////FIN DE MENU DE ORDENES DE ENVIO/////////////////////////////////
/////////////////////////////////////////////MENU DE CONSULTAS (INICIO)///////////////////////////////////////////////
void mostrarcedulaynombre(Persona *P){
	Color(YELLOW,BLACK);
	printf("\n\t Cedula: %lli \n",P->Cedula);
	printf("\n\t Nombre y apellido: %s \n",P->NyP);
	ColorB();
}
void Consulta414(Persona *y){
	if(y){
		Pedido *s;
		DPI *z;
		Persona *auxNOmayor;
		Persona *auxmayor;
		Persona *auxmayorproductos;
		Persona *auxNOmayorproductos;
		int sihaynoentregados=0, sihayentregados=0;
		Persona *aux=y;
		int contador=0,contador2=0,contadorproductos=0,contadorproductos2=0;
		int mayor=-1,NOmayor=-1,mayorproductos=-1,NOmayorproductos=-1;
		while(aux){
			s=aux->ped;	
			while(s){
				if(s->Entregado){
					sihayentregados=1;
					contador=contador+(s->Monto);
					z=s->DPI;
					while(z){
						contadorproductos+=z->Cantidad;
						z=z->prox;	
					}
				}else{
					sihaynoentregados=1;
					contador2=contador2+(s->Monto); 
					z=s->DPI;
					while(z){
						contadorproductos2+=s->DPI->Cantidad;
						z=z->prox;
					}
				}
				s=s->prox;	
			}
			if(contador>mayor){
				mayor=contador;
				auxmayor=aux;
			}
			if(contadorproductos>mayorproductos){
				mayorproductos=contadorproductos;
				auxmayorproductos=aux;
			}
			if(contador2>NOmayor){
				NOmayor=contador2;
				auxNOmayor=aux;
			}
			if(contadorproductos2>NOmayorproductos){
			    NOmayorproductos=contadorproductos2;
				auxNOmayorproductos=aux;
			}
			contador=0;
			contador2=0;
			contadorproductos=0;
			contadorproductos2=0;	 
			aux=aux->prox;	
		}
	    if(sihayentregados || sihaynoentregados){
	        if(sihayentregados){
	           printf("\n");
		       printf("\n\t Mejor cliente por cantidad total percibida: \n");
		       mostrarcedulaynombre(auxmayor);
		       printf("\n\t Mejor cliente por cantidad total de productos comprados: \n");
		       mostrarcedulaynombre(auxmayorproductos);
	        } else {
	    	   Color(LRED,BLACK);printf("\n\t *Por el momento no hay facturas que hayan sido entregadas* \n");ColorB();
		    }
		    if(sihaynoentregados){
		       printf("\n\t Peor cliente por cantidad total NO percibida: \n");
		       mostrarcedulaynombre(auxNOmayor);
		       printf("\n\t Peor cliente por cantidad total de productos NO comprados: \n");
		       mostrarcedulaynombre(auxNOmayorproductos);	
		   } else
	 	     Color(LRED,BLACK);printf("\n\t *Por el momento no hay facturas que no hayan sido entregadas* \n");ColorB();
	    } else {
	       Color(LRED,BLACK);printf("\n\t *Por el momento no hay facturas en el sistema* \n");ColorB();
		}
	}else{
		system("cls");
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Actualmente no hay personas registradas en el sistema...Intentelo otra vez*");
		ColorB();	
	}
}
struct Consulta415{
   int CodigoPro;	
   int CodigoEm;
   int Cantidad;
   int NOCantidad;
   int Monto;
   int NOMonto;
   Consulta415 *prox;
};
struct Consulta415 *buscarConsulta(Consulta415 *Di, int codigo, int codigoem){
	while(Di){
		if(Di->CodigoPro==codigo && Di->CodigoEm==codigoem){
		break;
		}
		Di=Di->prox;	
	}
	return Di;
}
int existeDPI(Consulta415 *S, int codigo, int codigoem){
	int boolean=0;
	while(S){
		if(S->CodigoPro==codigo && S->CodigoEm==codigoem){
			boolean=1;
			break;
		}
		S=S->prox;	
	}
	return boolean;
}
void Consulta417(Persona *p, Empresa *e){
	int mayorcantidad=-1;
	int mayormonto=-1;
	int menormonto=32767,menorcantidad=32767; // valor maximo de un int
	int codigo,NOcodigo;
	int codigoproducto,NOcodigoproducto;
	int codigoempresa,NOcodigoempresa;
	int codigoempresamonto,NOcodigoempresamonto;
	int monto,cantidad,NOmonto,NOcantidad;
	Pedido *aux;
	DPI *auxDPI;
	Consulta415 *lista=NULL;
	Consulta415 *aux415;
	Consulta415 *w;
	Producto *auxPro;
	char Descripcion[20]="",DescripcionMonto[20]="",NODescripcion[20]="",NODescripcionMonto[20]="";
	while(p){
		aux=p->ped;
		while(aux){
			auxDPI=aux->DPI;
			while(auxDPI){
				if(!existeDPI(lista,auxDPI->CodigoPr,aux->CodigoEm)){
					Consulta415 *nuevoC = new Consulta415;
					nuevoC->CodigoPro=auxDPI->CodigoPr;
					nuevoC->CodigoEm=aux->CodigoEm;
					if(aux->Entregado){
						nuevoC->Cantidad=auxDPI->Cantidad;
						nuevoC->Monto=auxDPI->Precio*auxDPI->Cantidad;
						nuevoC->NOCantidad=0;
						nuevoC->NOMonto=0;	
					}else{
						nuevoC->Cantidad=0;
						nuevoC->Monto=0;
						nuevoC->NOCantidad=auxDPI->Cantidad;
						nuevoC->NOMonto=auxDPI->Precio*auxDPI->Cantidad;	
					}
					nuevoC->prox=lista;
					lista=nuevoC;
				}else{
					aux415=buscarConsulta(lista,auxDPI->CodigoPr,aux->CodigoEm);
					if(aux->Entregado){
						aux415->Cantidad=aux415->Cantidad+auxDPI->Cantidad;
						aux415->Monto=auxDPI->Precio*aux415->Cantidad;
					}else{
						aux415->NOCantidad=aux415->NOCantidad+auxDPI->Cantidad;
						aux415->NOMonto=auxDPI->Precio*aux415->NOCantidad;		
					}
				}	
				auxDPI=auxDPI->prox;
			}
			aux=aux->prox;  			
		}
		p=p->prox;
	} 
	w=lista;
	while(w){
		if(w->Cantidad>mayorcantidad){
			codigo=w->CodigoPro;
			codigoempresa=w->CodigoEm;
			mayorcantidad=w->Cantidad;
			monto=w->Monto;
		}
		if(w->Monto>mayormonto){
			codigoproducto=w->CodigoPro;
			codigoempresamonto=w->CodigoEm;
			mayormonto=w->Monto;
			cantidad=w->Cantidad;
		}
		if(w->NOCantidad<menorcantidad && w->NOCantidad!=0){
			NOcodigo=w->CodigoPro;
			NOcodigoempresa=w->CodigoEm;
			menorcantidad=w->NOCantidad;
			NOmonto=w->NOMonto;
		}
		if(w->NOMonto<menormonto && w->NOMonto!=0){
			NOcodigoproducto=w->CodigoPro;
			NOcodigoempresamonto=w->CodigoEm;
			menormonto=w->NOMonto;
			NOcantidad=w->NOCantidad;	
		}
		w=w->prox;	
	} 
	while(e){
		if(e->CodigoEm==codigoempresa || e->CodigoEm==codigoempresamonto || e->CodigoEm==NOcodigoempresa || e->CodigoEm==NOcodigoempresamonto){
			auxPro=e->prod;
			while(auxPro){
				if(codigo==auxPro->CodigoPr && e->CodigoEm==codigoempresa){
					strcpy(Descripcion,auxPro->Descr); 
				} 
				if(codigoproducto==auxPro->CodigoPr && e->CodigoEm==codigoempresamonto){
					strcpy(DescripcionMonto,auxPro->Descr); 
				} 
				if(NOcodigo==auxPro->CodigoPr && e->CodigoEm==NOcodigoempresa){
					strcpy(NODescripcion,auxPro->Descr); 
				} 
				if(NOcodigoproducto==auxPro->CodigoPr && e->CodigoEm==NOcodigoempresamonto){
					strcpy(NODescripcionMonto,auxPro->Descr); 
				} 
				auxPro=auxPro->prox;
			}
		} 	
		e=e->prox;	
	}
	if(lista){
		if(cantidad){
			printf("\n\n----------------------------------------------------------\n\n");
			printf("\t El producto mas vendido (cantidad) es: \n\n");
			printf("\t La empresa es: %i \n",codigoempresa);
			printf("\t La descripcion del producto es: %s \n", Descripcion);
			printf("\t La cantidad es: %i \n", mayorcantidad);
			printf("\t El monto es: %i \n", monto);
			printf("   ----------------------------------------------------------\n");
			printf("\t El producto con mejor ingreso (monto) es: \n\n");
			printf("\t La empresa es: %i \n",codigoempresamonto);
			printf("\t La descripcion del producto es: %s \n",DescripcionMonto);
			printf("\t La cantidad es: %i \n", cantidad);
			printf("\t El monto es: %i \n", mayormonto);
			printf("\n----------------------------------------------------------\n");
		}else{
			Color(LRED,BLACK);printf("\n\n\t *Por el momento no hay productos que hayan sido entregados*");ColorB();	
		}
		if(menorcantidad!=32767){
			printf("\n\n\t El producto menos vendido (cantidad) al NO ser entregado es: \n\n");
			printf("\t La empresa es: %i \n",NOcodigoempresa);
			printf("\t La descripcion del producto es: %s \n",NODescripcion);
			printf("\t La cantidad es: %i \n", menorcantidad);
			printf("\t El monto es: %i \n", NOmonto);
			printf("----------------------------------------------------------\n\n");	
			printf("\t El producto con peor ingreso(monto) al NO ser entregado es: \n\n");
			printf("\t La empresa es: %i \n",NOcodigoempresamonto);
			printf("\t La descripcion del producto es: %s \n",NODescripcionMonto);
			printf("\t La cantidad es: %i \n", NOcantidad);
			printf("\t El monto es: %i \n", menormonto);
			printf("----------------------------------------------------------\n\n");
		}else{
			Color(YELLOW,BLACK);printf("\n\n\t *Por el momento no hay productos que no han sido entregados* \n");ColorB();
		}
	}	
}
struct GuardarEMP{
  int Codigo;	
  GuardarEMP *prox;	
};
int contarempresas(Empresa *e){
	int cont=0;
	while(e){
		cont++;	
		e=e->prox;	
	}
	return cont;
}
int existeEMP(GuardarEMP *s,int codigo){
	int boolean=0;
	while(s){
		if(s->Codigo==codigo){
			boolean=1;
			break;
		}
		s=s->prox;	
	}
	return boolean;	
}
int MontoTotalNOvendido(Persona *p, int codigoem){
	int contvendidos=0;
	Pedido *aux;
	while(p){
		aux=p->ped;	
		while(aux){
			if(!aux->Entregado && aux->CodigoEm==codigoem){	
				contvendidos+=aux->Monto;
			}	 	
			aux=aux->prox;			
		}  
		p=p->prox;
	}
	return contvendidos;
}
int cantidadproductosvendidos(Persona *p, int codigoem){
	int contvendidos=0;
	Pedido *aux;
	DPI *aux2;
	while(p){
		aux=p->ped;	
		while(aux){
			if(aux->Entregado && aux->CodigoEm==codigoem){	
				aux2=aux->DPI;	
				while(aux2){
					contvendidos+=aux2->Cantidad;
					aux2=aux2->prox;
				}
			}	 	
			aux=aux->prox;			
		}  
		p=p->prox;
	}
	return contvendidos;
}
int MontoTotal(Persona *p, int codigoem){
	int contvendidos=0;
	Pedido *aux;
	while(p){
		aux=p->ped;	
		while(aux){
			if(aux->Entregado && aux->CodigoEm==codigoem){	
				contvendidos+=aux->Monto;
			}	 	
			aux=aux->prox;			
		}  
		p=p->prox;
	}
	return contvendidos;
}
void Consulta431(Empresa *e, Persona *p){
	if(e->Tipo!=-1){	
		int cont=contarempresas(e);
		int cantidadpro,tipo,cantidad,monto;
		char nombre[20]="";
		Empresa *aux;
		GuardarEMP *l=NULL;
		int mayor=-1;
		printf("\n");
		printf("\n\t Las empresas con mayores ingresos logrados (orden descendiente) son:\n");	
		while(cont){
			aux=e;
			GuardarEMP *empresa=new GuardarEMP; 
			while(aux){
				cantidadpro=MontoTotal(p,aux->CodigoEm);
				if(cantidadpro>mayor && !existeEMP(l,aux->CodigoEm)){
					mayor=cantidadpro;
					empresa->Codigo=aux->CodigoEm;
					tipo=aux->Tipo;
					strcpy(nombre,aux->Nombre);
				} 
				aux=aux->prox;	
			}
			printf("\n\t Nombre: %s \n", nombre);	
			switch (tipo) {
				case 1: printf("\n\t Tipo: Comidas (1) \n"); break;
				case 2: printf("\n\t Tipo: Alimentos(2) \n"); break;
				case 3: printf("\n\t Tipo: General(3) \n"); break;
				default: printf("\n\t Tipo: No asociado \n"); break;
			}	
			printf("\n\t Ingresos: ");Color(LGREEN,BLACK);printf("$%i",mayor);Color(LRED,BLACK);printf("($%i) \n", -1*MontoTotalNOvendido(p,empresa->Codigo));ColorB();	  
			printf("\n\t Cantidad de productos vendidos: %i \n", cantidadproductosvendidos(p, empresa->Codigo));
			printf("\n");
			empresa->prox=l;
			l=empresa;	
			mayor=-1;
			cont--;	
		}
	}else{
		system("cls");
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Actualmente no hay empresas registradas en el sistema...Intentelo otra vez*");
		ColorB();
	} 
}
int cantidadproductosNOvendidos(Persona *p, int codigoem){
	int contnovendidos=0;
	Pedido *aux;
	DPI *aux2;
	while(p){
		aux=p->ped;	
		while(aux){
			if(!aux->Entregado && aux->CodigoEm==codigoem){	
				aux2=aux->DPI;	
				while(aux2){
					contnovendidos+=aux2->Cantidad;
					aux2=aux2->prox;
				}
			}	 	
			aux=aux->prox;			
		}  
		p=p->prox;
	}
	return contnovendidos;
}
void Consulta432(Empresa *e, Persona *p){
	if(e->Tipo!=-1){	
		int cont=contarempresas(e);
		int cantidadpro,tipo,cantidad,monto;
		char nombre[20]="";
		Empresa *aux;
		GuardarEMP *l=NULL;
		int mayor=-1;
		printf("\n");
		printf("\n\t Las empresas con mayor cantidad de productos vendidos (orden descendiente) son:\n");	
		while(cont){
			aux=e;
			GuardarEMP *empresa=new GuardarEMP; 
			while(aux){
				cantidadpro=cantidadproductosvendidos(p,aux->CodigoEm);
				if(cantidadpro>mayor && !existeEMP(l,aux->CodigoEm)){
					mayor=cantidadpro;
					empresa->Codigo=aux->CodigoEm;
					tipo=aux->Tipo;
					strcpy(nombre,aux->Nombre);
				} 
				aux=aux->prox;	
			}
			printf("\n\t Nombre: %s \n", nombre);	
			switch (tipo){
				case 1: printf("\n\t Tipo: Comidas (1) \n"); break;
				case 2: printf("\n\t Tipo: Alimentos(2) \n"); break;
				case 3: printf("\n\t Tipo: General(3) \n"); break;
				default: printf("\n\t Tipo: No asociado \n"); break;
			}	
			printf("\n\t Cantidad de productos vendidos: ");Color(LGREEN,BLACK);printf("%i",mayor);Color(LRED,BLACK);printf("(%i) \n",-1*cantidadproductosNOvendidos(p,empresa->Codigo) );ColorB();	  	
			printf("\n\t Monto Total: $%i \n",MontoTotal(p,empresa->Codigo));
			printf("\n");
			empresa->prox=l;
			l=empresa;	
			mayor=-1;
			cont--;	
		}
	}else{
		system("cls");
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Actualmente no hay empresas registradas en el sistema...Intentelo otra vez*");
		ColorB();
	} 
}
//Devuelve los productos entregados por una empresa
int C411PE (int Empresa, Persona *Per) {
int Resultado = 0;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while (aux) {
			if ((aux->CodigoEm == Empresa) && (aux->Entregado == 1)) {
			Resultado = Resultado + 1;	
			}
		aux = aux->prox;	
		}	
	Per = Per->prox;	
	}
return Resultado;		
}
//Devuelve los productos no entregados por una empresa
int C411PNE (int Empresa, Persona *Per) {
int Resultado = 0;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while (aux) {
			if ((aux->CodigoEm == Empresa) && (aux->Entregado == 0)) {
			Resultado = Resultado + 1;	
			}
		aux = aux->prox;	
		}	
	Per = Per->prox;	
	}
return Resultado;		
}
//Devuelve los clientes atendidos por una empresa
int C411CA (int Codigo, Persona *Per) {
int Resultado = 0;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while ((aux) && (aux->CodigoEm != Codigo)) {					
		aux = aux->prox;	
		}
		if ((aux) && (aux->Entregado == 1)) {
		Resultado = Resultado + 1;	
		}		
	Per = Per->prox;	
	}
return Resultado;		
}
//Devuelve el ingreso total vendido por una empresa
int C411ITV (int Codigo, Persona *Per) {
int Resultado = 0;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while (aux) {
			if ((aux->Entregado == 1) && (aux->CodigoEm == Codigo)) {
			Resultado = Resultado + aux->Monto;	
			}	
		aux = aux->prox;	
		}		
	Per = Per->prox;	
	}
return Resultado;		
}
//Devuelve el promedio gastado por cliente de una empresa
int C411PG (int Codigo, Persona *Per) {
int Resultado = 0;
int CantidadClientes = 0;
bool clienteunico = 1;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while (aux) {
			if ((aux->Entregado == 1) && (aux->CodigoEm == Codigo)) {
			Resultado = Resultado + aux->Monto;
				if (clienteunico == 1) {
				CantidadClientes = CantidadClientes + 1;
				clienteunico = 0;	
				}	
			}	
		aux = aux->prox;	
		}		
	Per = Per->prox;
	clienteunico = 1;	
	}
	if (CantidadClientes != 0) {
	Resultado = Resultado / CantidadClientes;	
	}	
return Resultado;		
}
//Devuelve la cantidad total de clientes UNICOS atendidos
int C411CLIENTESATENDIDOS (Persona *P) {
int Resultado = 0;
bool atendido = 0;
Pedido *aux;
	while (P) {
	aux = P->ped;
		while (aux && !(atendido == 1))	{
			if (aux->Entregado == 1) {
			Resultado = Resultado + 1;
			atendido = 1;	
			}
		aux = aux->prox;	
		}
	P = P->prox;
	atendido = 0;	
	}
return Resultado;		
}
//Consulta 4.1.1
void C411 (Persona *Per,Empresa *Emp) {
int PE = 0;
int PNE = 0;
int CA = 0;
int ITV = 0;
int PG = 0;	
	while (Emp) {
	printf("\n\n---------------------------------------------------------\n");	
	printf("\n\t Empresa: %s \n\n",Emp->Nombre);
	printf("\n\t Cantidad de pedidos: %i \n", C411PE(Emp->CodigoEm,Per) + C411PNE(Emp->CodigoEm,Per));
	printf("\n\t Cantidad de pedidos entregados: %i \n", C411PE(Emp->CodigoEm,Per));
	printf("\n\t Cantidad de pedidos NO entregados: %i \n", C411PNE(Emp->CodigoEm,Per));
	printf("\n\t Cantidad de clientes atendidos: %i \n", C411CA(Emp->CodigoEm,Per));
	printf("\n\t Ingreso total vendido: %i \n",C411ITV(Emp->CodigoEm,Per));
	printf("\n\t Promedio gastado por cada cliente: %i \n",C411PG(Emp->CodigoEm,Per));
	printf("\n---------------------------------------------------------\n\n");
	PE = PE + C411PE(Emp->CodigoEm,Per);
	PNE = PNE + C411PNE(Emp->CodigoEm,Per);
	ITV = ITV + C411ITV(Emp->CodigoEm,Per);
	PG = PG + C411PG(Emp->CodigoEm,Per);	
	Emp = Emp->prox;	
	}
	printf("\n\n---------------------------------------------------------\n");
	printf("\n\t Mostrando el renglon final con las sumas totales: \n\n");
	printf("\n\t Total de pedidos: %i \n",PE + PNE);
	printf("\n\t Total de pedidos entregados: %i \n",PE);
	printf("\n\t Total de pedidos NO entregados: %i \n",PNE);
	printf("\n\t Total de clientes atendidos: %i \n",C411CLIENTESATENDIDOS(Per));
	printf("\n\t Total de ingreso vendido: %i \n",ITV);
	printf("\n\t Suma de los promedios gastados: %i \n",PG);
	printf("\n---------------------------------------------------------\n");		
}
//Devuelve el ingreso no entregado de una empresa
int C412INE (int Codigo, Persona *Per) {
int Resultado = 0;
Pedido *aux;
	while (Per) {
	aux = Per->ped;
		while (aux) {
			if ((aux->Entregado == 0) && (aux->CodigoEm == Codigo)) {
			Resultado = Resultado + aux->Monto;	
			}	
		aux = aux->prox;	
		}		
	Per = Per->prox;	
	}	
return Resultado;	
}
//Devuelve el promedio de productos por factura de una empresa
int C412PP (int Codigo, Persona *Per) {
int Resultado = 0;
int CantidadFacturas = 0;
Pedido *aux;
DPI *aux2;
	while (Per) {
	aux = Per->ped;
		if (aux->CodigoEm == Codigo) {
		CantidadFacturas = CantidadFacturas + 1;	
		}
		while (aux) {
		aux2 = aux->DPI;
			while (aux2) {
				if (aux->CodigoEm == Codigo) {
				Resultado = Resultado + aux2->Cantidad;	
				}	
			aux2 = aux2->prox;	
			}	
		aux = aux->prox;	
		}	
	Per = Per->prox;	
	}
	if (CantidadFacturas != 0) {
	Resultado = Resultado / CantidadFacturas;	
	}	
return Resultado;	
}
//Devuelve el total facturado
int C412TF (Persona *P) {
Pedido *aux = P->ped;
DPI *aux2;
int Resultado = 0;
		while (aux) {
			if (aux->Entregado == 1) {
			Resultado = Resultado + aux->Monto;	
			}	
		aux = aux->prox;		
		}
return Resultado;			
}
//Devuelve el total de pedidos entregados
int C412PE (Persona *Per) {
int Resultado = 0;
Pedido *aux = Per->ped;
DPI *aux2;
		while (aux) {
		aux2 = aux->DPI;
			while (aux2) {
				if (aux->Entregado == 1) {
				Resultado = Resultado + aux2->Cantidad;	
				}	
			aux2 = aux2->prox;	
			}	
		aux = aux->prox;	
		}	
return Resultado;		
}
//Devuelve el total de pedidos no entregados
int C412PNE (Persona *Per) {
int Resultado = 0;
Pedido *aux = Per->ped;
DPI *aux2;
		while (aux) {
		aux2 = aux->DPI;
			while (aux2) {
				if (aux->Entregado == 0) {
				Resultado = Resultado + aux2->Cantidad;	
				}	
			aux2 = aux2->prox;	
			}	
		aux = aux->prox;	
		}	
return Resultado;		
}
//Inserta en una variable dada, todos los datos de los detalles de facturas de las personas dadas
void insertarpersona4(DPI **cab, int CodigoPr, int Cantidad, int Precio) {	
DPI *t;
t = new struct DPI;
t->CodigoPr = CodigoPr;
t->Cantidad = Cantidad;
t->Precio = Precio;
t->prox = *cab;
*cab = t;	
}
//Inserta en una variable dada, todos los datos de las facturas de las personas dadas
void insertarpersona3(Pedido **cab, int NumFactura, int CodigoEm, char Fecha[20], bool Entregado, int Monto, DPI *dp)  {	
Pedido *t;
t = new struct Pedido;
t->NumFactura = NumFactura;
t->CodigoEm = CodigoEm;
strcpy(t->Fecha,Fecha);
t->Entregado = Entregado;
t->Monto = Monto;
t->DPI = NULL;
	while (dp) {		
	insertarpersona4(&(t->DPI),dp->CodigoPr,dp->Cantidad,dp->Precio);	
	dp= dp->prox;	
	}
t->prox = *cab;
*cab = t;
}
//Devuelve 1 si en una factura se encuentra el codigo dado, 0 en caso contrario
int escliente (Pedido *P, int Codigo) {
	while (P) {
		if (P->CodigoEm == Codigo) {
		return 1;	
		}
	P = P->prox;	
	}
return 0;	
}
//Inserta en una variable dada, todos los datos de las personas dadas 
void insertarpersona2 ( Persona **cab, long long int Cedula, char NyP [20], char FechaN[15], char CiuN [15], char Dir [40], Pedido *ped, int Codigo){
Persona *t;  
t= new struct Persona;
t->Cedula = Cedula;
strcpy(t->NyP,NyP);
strcpy(t->FechaN,FechaN);
strcpy(t->CiuN,CiuN);
strcpy(t->Dir,Dir);
t->ped = NULL; 
	while (ped) {
		if (ped->CodigoEm == Codigo) {
		insertarpersona3(&(t->ped),ped->NumFactura,ped->CodigoEm,ped->Fecha,ped->Entregado,ped->Monto,ped->DPI);	
		}
	ped = ped->prox;	
	}
t->prox = *cab;
*cab = t;		
}
//Intercambia los valores de dos personas
void intercambiarpersonasg(Persona *n1, Persona *n2)
{	
Persona *aux = new struct Persona;
aux->Cedula = n1->Cedula;
strcpy(aux->NyP,n1->NyP);
strcpy(aux->FechaN,n1->FechaN);
strcpy(aux->CiuN,n1->CiuN);
strcpy(aux->Dir,n1->Dir);
aux->ped = NULL;
	while (n1->ped) {
	insertarpersona3(&(aux->ped),n1->ped->NumFactura,n1->ped->CodigoEm,n1->ped->Fecha,n1->ped->Entregado,n1->ped->Monto,n1->ped->DPI);
	n1->ped = n1->ped->prox;	
	}	
n1->Cedula = n2->Cedula;
strcpy(n1->NyP,n2->NyP);
strcpy(n1->FechaN,n2->FechaN);
strcpy(n1->CiuN,n2->CiuN);
strcpy(n1->Dir,n2->Dir);
n1->ped = NULL;
	while (n2->ped) {
	insertarpersona3(&(n1->ped),n2->ped->NumFactura,n2->ped->CodigoEm,n2->ped->Fecha,n2->ped->Entregado,n2->ped->Monto,n2->ped->DPI);
	n2->ped = n2->ped->prox;	
	}
n2->Cedula = (aux)->Cedula;
strcpy(n2->NyP,(aux)->NyP);
strcpy(n2->FechaN,(aux)->FechaN);
strcpy(n2->CiuN,(aux)->CiuN);
strcpy(n2->Dir,(aux)->Dir);
n2->ped = NULL;
	while ((aux)->ped) {
	insertarpersona3(&(n2->ped),(aux)->ped->NumFactura,(aux)->ped->CodigoEm,(aux)->ped->Fecha,(aux)->ped->Entregado,(aux)->ped->Monto,(aux)->ped->DPI);
	(aux)->ped = (aux)->ped->prox;	
	}			
}
//Ordena las personas por cedula de menor a mayor
void ordIntercambiopersonascedulag(struct Persona *l)
{
	struct Persona *aux;
	if(l)
	{
		for( ; l->prox; l = l->prox)
			for(aux = l->prox; aux; aux = aux->prox)
				if(l->Cedula > aux->Cedula)
					intercambiarpersonasg(l, aux);
	}
}
//Ordena las personas por cantidad de pedidos totales de mayor a menor
void ordIntercambiopersonascantidadpedidosg(struct Persona *l)
{
	struct Persona *aux;
	if(l)
	{
		for( ; l->prox; l = l->prox)
			for(aux = l->prox; aux; aux = aux->prox)
				if( (C412PE(l) + C412PNE(l)) < (C412PE(aux) + C412PNE(aux)))
					intercambiarpersonasg(l, aux);
	}
}
//Consulta 4.1.2
void C412 (Persona *Per,Empresa *Emp) {
int intentos = 3;
Empresa *valorempresa = Emp;
int CodigoEm;
Persona *valorpersona = NULL;
Persona *reserva = Per;		
	do {
		do {
		printf ("\n\n\t Escriba el codigo de la empresa a consultar: ");
		scanf ("%i", &CodigoEm);
			if (CodigoEm < 0) {
			printf("\n\t *ERROR: Codigo no valido...Intentelo otra vez*");
			system("pause");
			system("cls");			
			}
		} while (!(CodigoEm>=0));
			while ((valorempresa) && (valorempresa->CodigoEm != CodigoEm)) {	
			valorempresa = valorempresa->prox;	
			}
		if (valorempresa) {	
		intentos = 0;
		int MetodoOrdenamiento;
			do {
			printf("\n\n\t Indique la forma de ordenamiento:");
			printf("\n\n\t 0.)CEDULA (menor a mayor)");
			printf("\n\n\t 1.)CANTIDAD DE PEDIDOS (mayor a menor)");
			printf("\n\n\t\t Numero de Opcion: ");
			scanf("%i",&MetodoOrdenamiento);
				if (!(MetodoOrdenamiento == 1 || MetodoOrdenamiento == 0)) {
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Opcion no valida...Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");				
				}
			} while (!(MetodoOrdenamiento == 1 || MetodoOrdenamiento == 0));
		Emp = valorempresa;
		printf("\n\n---------------------------------------------------------\n");
		printf("\n\t Empresa: %s \n\n",Emp->Nombre);
		printf("\n\t Cantidad total de ventas: %i \n",C411PE(Emp->CodigoEm,Per));
		printf("\n\t Ingreso total vendido: %i \n",C411ITV(Emp->CodigoEm,Per));
		printf("\n\t Ingreso NO entregado: %i \n",C412INE(Emp->CodigoEm,Per));
		printf("\n\t Promedio de productos por factura: %i \n",C412PP(Emp->CodigoEm,Per));
		printf("\n---------------------------------------------------------\n");
			while (Per) {
				if (escliente(Per->ped,Emp->CodigoEm)) {
				insertarpersona2(&valorpersona,Per->Cedula,Per->NyP,Per->FechaN,Per->CiuN,Per->Dir,Per->ped,Emp->CodigoEm);	
				}	
			Per = Per->prox;	
			}
		Per = reserva;
			if (MetodoOrdenamiento == 0) {
			ordIntercambiopersonascedulag(valorpersona);	
			} else {
			ordIntercambiopersonascantidadpedidosg(valorpersona);	
			}	
			if (valorpersona) {
			printf("\n\t Mostrando los datos de sus clientes: \n\n");	
			}
			while (valorpersona) {
			printf("\n---------------------------------------------------------\n");	
			printf("\n\t Nombre del cliente: %s \n",valorpersona->NyP);
			printf("\n\t Cedula del cliente: %i \n",valorpersona->Cedula);
			printf("\n\t Total facturado por el cliente: %i \n",C412TF(valorpersona));
			printf("\n\t Cantidad de productos asociados al cliente: %i \n",C412PE(valorpersona) + C412PNE(valorpersona));
			printf("\n\t Cantidad de productos entregados al cliente: %i \n",C412PE(valorpersona));
			printf("\n\t Cantidad de productos NO entregados al cliente: %i \n",C412PNE(valorpersona));	
			valorpersona = valorpersona->prox;	
			}
			printf("\n---------------------------------------------------------\n");		
		} else {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Introdujo un codigo de empresa que no existe...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		intentos = intentos - 1;
		valorempresa = Emp;
		system("pause");
		system("cls");					
		}
	} while (intentos != 0);	
}
//Muestra los datos del primer detalle de factura dado
void ConsultarDetalleG (DPI P) {
printf("\n\t Codigo del producto: %i ",P.CodigoPr);
printf("\n\t Cantidad del producto: %i ",P.Cantidad);
printf("\n\t Precio por el total de productos: $%i \n",P.Precio);	
}
//Muestra todos los detalles de las facturas de una persona dada
void C413MD (Persona *P) {
Pedido *aux = P->ped;
DPI *aux2;
		while (aux) {
		aux2 = aux->DPI;
			while (aux2) {
			printf("\n---------------------------------------------------------\n");
			ConsultarDetalleG(*aux2);
			aux2 = aux2->prox;	
			}
			printf("\n---------------------------------------------------------\n");
		aux = aux->prox;		
		}	
}
//Consulta 4.1.3
void C413 (Persona *Per) {
int intentos = 2;
Persona *valorpersona = Per;
int Cedula;	
	do {
		do {
		printf ("\n\n\t Escriba la cedula de la persona a consultar: ");
		scanf ("%i", &Cedula);
			if (Cedula < 0) {
			Color(LRED,BLACK);	
			printf("\n\t *ERROR: Cedula no valida...Intentelo otra vez*");
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");			
			}		
		} while (!(Cedula>=0));
			while ((valorpersona) && (valorpersona->Cedula != Cedula)) {	
			valorpersona = valorpersona->prox;	
			}
		if (valorpersona) {	
		intentos = 0;
		Per = valorpersona;
		printf("\n---------------------------------------------------------\n");
		printf("\n\t Nombre de la persona: %s \n",Per->NyP);
		printf("\n\t Cedula de la persona: %i \n",Per->Cedula);
		printf("\n\t Mostrando los detalles de sus pedidos: \n\n");
		C413MD(Per);
		printf("\n\t Mostrando las sumas totales: \n\n");
		printf("\n\t Ingreso percibido: %i \n",C412TF(Per));
		printf("\n\t Cantidad de productos asociados al cliente: %i \n",C412PE(Per) + C412PNE(Per));
		printf("\n\t Cantidad de productos entregados: %i \n",C412PE(Per));
		printf("\n\t Cantidad de productos no entregados: %i \n",C412PNE(Per));		
		printf("\n---------------------------------------------------------\n");
		} else {
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Cedula no existente...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		intentos = intentos - 1;
		valorpersona = Per;
		system("pause");
		system("cls");					
		}
	} while (intentos != 0);	
}
Persona *buscarpersona(Persona *p, int cedu){
	while(p){
		if(p->Cedula==cedu){
		 break;
		}
     p=p->prox;	
    }
	return p;
}
Empresa *buscarempresa(Empresa *e, int codigo){
	while(e){
		if(e->CodigoEm==codigo){
		 break;
		}
     e=e->prox;	
    }
	return e;
}
void imprimirempresaconsultas(Empresa *emp){
	printf("\t Empresa: %i, %s, %i, %s, %s",emp->CodigoEm,emp->Nombre,emp->Tipo,emp->Telf,emp->Dir); 	
}
void imprimirfacturasconsultas(Pedido *ped){
	char siono[2];
	if(ped->Entregado)
	  strcpy(siono,"SI");
	else 
	  strcpy(siono,"NO");  
	printf("\t Pedido: %i, %i, %s, %s, $%i",ped->NumFactura,ped->CodigoEm,ped->Fecha,siono,ped->Monto);
}
void case421A(Persona *l, int CI) {
	Pedido *aux2;
	Pedido*aux4;
	DPI* aux3;
	int a=0,b=0,c=0,f=0,g=0;	
	aux2=l->ped;
		while (aux2){		 
		  aux3= aux2->DPI;
		  a++;
		   if (aux2->Entregado){ 
		      c+=aux2->Monto;
		        while (aux3){
		  	      b+=aux3->Cantidad;
		  	      aux3= aux3->prox;
		        }
		    } else{
		        f+=aux2->Monto;
		        while (aux3){
		  	      g+= aux3->Cantidad;
		  	      aux3= aux3->prox;
		        }	
			}
		   aux2=aux2->prox;
	    }
	   printf("\n\t Total de facturas: %i \n",a);
	   printf("\n\t Cantidad total de productos: ");Color(LGREEN,BLACK);printf("%i",b);Color(LRED,BLACK);printf("(%i) \n",-1*g);ColorB();	   
	   printf("\n\t Monto total de productos: ");Color(LGREEN,BLACK);printf("$%i",c);Color(LRED,BLACK);printf("(%i) \n",-1*f);ColorB();	  
}  
void j(Persona *p, int c){
 Persona*aux=p;
 Pedido*aux2;
 DPI *aux3;
 int facturasentregadas=0, facturasNOentregadas=0, productosentregados=0, productosNOentregados=0;
	  aux2=aux->ped;
 	  while(aux2){
    	  if ((aux2->Entregado) && (aux2->CodigoEm==c)){			   			      			
	          facturasentregadas++;	 
			  aux3=aux2->DPI;         
	            while(aux3){
	          	  productosentregados+=aux3->Cantidad;
	          	  aux3=aux3->prox;
			    }
           } else if((!aux2->Entregado) && (aux2->CodigoEm==c)) {
           	   facturasNOentregadas++;
           	   aux3=aux2->DPI;         
	                while(aux3){
	                  productosNOentregados+=aux3->Cantidad;
	                  aux3=aux3->prox;
			        }
           }
	       aux2=aux2->prox;
		}	   
       aux=aux->prox;       
	   	
	printf("\n\n\t Total de facturas: %i",facturasentregadas+facturasNOentregadas);	
	printf("\n\t Cantidades de productos: ");Color(LGREEN,BLACK);printf("%i",productosentregados);Color(LRED,BLACK);printf("(%i)",-1*productosNOentregados);ColorB();	  
}
int personalecomproaempresa(Persona *p, int codigoempresa){
   Pedido *aux=p->ped;	
   int sicompro=0;
    while(aux){
        if(aux->CodigoEm==codigoempresa){
     	  sicompro=1;
          break;
	    }	
   	 aux=aux->prox;
	}
  return sicompro;
}
void contarproducto( Persona*p,Empresa*emp){	
	Persona*aux;
	Pedido*aux2;
	Empresa*auxemp=emp;
	Producto *auxprod;	
	int c,d,e;	
	while (auxemp){
		d=0;
	    c=0;
	    e=0; 
	    aux=p;	
	    if(personalecomproaempresa(aux,auxemp->CodigoEm)){
	      imprimirempresaconsultas(auxemp);	 	
		  c=MontoTotal(aux,auxemp->CodigoEm);	
		  d=MontoTotalNOvendido(aux,auxemp->CodigoEm);
		  j(aux,auxemp->CodigoEm);
		  //ConsultarEmpresa(auxemp);
		  printf("\n\t Montos total: ");Color(LGREEN,BLACK);printf("$%i",c);Color(LRED,BLACK);printf("($%i)",-1*d);ColorB();			
		  printf("\n----------------------------------------------------------\n");			
		}
		auxemp=auxemp->prox;
	}	
}
void menucase421 (Persona*p, Empresa*emp){ 
  int CI;  
  if (p && emp){
      printf("\n\n\t Introduzca la cedula de la persona: ");  	  
      scanf ("%i",&CI);
      system ("cls");
      Persona *t=buscarpersona(p,CI);
        if(t) {
           printf("\n\t NOTA: \n");
           Color(LRED,BLACK);
           printf("\n\t- Las Cantidades negativas y entre parentesis () pertenecen a las facturas NO entregadas \n");
           printf("\n\t- Solo se mostraran las empresas que esten asociadas a algun pedido de la Persona \n");
           ColorB();
           printf("\n\n\t");
           system("pause");
           system("cls");
           mostrarpersona(t);
           printf("\n");
           case421A(t, CI);    
           printf("\n----------------------------------------------------------\n");	
           contarproducto(t,emp);
		}else{ 
			system("cls");
			Color(LRED,BLACK);
			printf("\n\t *ERROR: La persona que selecciono no existe...Intentelo otra vez*"); 
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");
		}     
   } else {
		Color(LRED,BLACK);
		printf("\n\t *ERROR: Campo vacio...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system ("pause");
		system("cls");
   }
}
void imprimirtotales(Empresa*emp, Persona*p){
    Pedido*aux;      
    DPI*aux2;
    int sientra=0;
    Empresa*emp2=emp;
    int cont=0,cont2=0,cont3=0;
	aux=p->ped;
	   while(aux){
	  	  if(aux->CodigoEm==emp2->CodigoEm){
	  	  	  sientra=1;
	  	  	  printf("\n#################################################\n");
	  	  	  imprimirfacturasconsultas(aux);
	  	  	  printf("\n");
	  	  	  aux2=aux->DPI;
	  	  	  mostrarDPI(aux2);
	  	      cont++;
	  	      cont3+=aux->Monto;
	  	        while (aux2){
	  	          cont2+=aux2->Cantidad;
	  	          aux2=aux2->prox;
			    }      	  	      
	        }
			aux=aux->prox;	   	
		}
		if(sientra)
		printf("\n#################################################\n");
	    if(sientra){
	       printf("\n\t TOTALES DEL CLIENTE: \n");	
		   printf("\n\t    Cantidad de facturas: %i",cont);
           printf("\n\t    Monto total: $%i",cont3);
           printf("\n\t    Cantidad de producto total: %i",cont2);
	    } else {
	      	Color(LRED,BLACK);printf("\n\t *Actualmente no hay facturas asociadas a esta persona y empresa* \n");ColorB();
		}		
}
void Menu422 (Empresa *emp, Persona*p){
  Persona*aux2=p;
  Persona *aux3=aux2;
  Producto*aux=emp->prod;  
  int	CI,cd;	
   if (p && emp){	
     //Capturando CI -------------------------------		
      printf("\n\n\t Indique la Cedula de la Persona: ");
      scanf ("%i",&CI);
      Persona *t=buscarpersona(p,CI);
        if(t){
          //Consultando empresa--------------------------		 
          printf("\n\n\t Indique el Codigo de la Empresa: ");		
  	      scanf("%i", &cd);
  	      Empresa *e=buscarempresa(emp,cd);
  	        if(e){
  	          system("cls"); 
  	          mostrarpersona(t);	    	     
              imprimirtotales(e,t);
			} else {
				system("cls"); 
				Color(LRED,BLACK);
				printf("\n\t *ERROR: La empresa que selecciono no existe...Intentelo otra vez*");
				printf("\n\n\t ");
				system("pause");
				system("cls");
			}
  	    } else {	
  	      	system("cls");
  	      	Color(LRED,BLACK);
			printf("\n\t *ERROR: la persona que selecciono no existe...Intentelo otra vez*");	
			ColorB();
			printf("\n\n\t ");
			system("pause");
			system("cls");
		}
    } else {    
		Color(LRED,BLACK);	
		printf("\n\t *ERROR: Campo vacio... Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");
	}	  
}
struct LC433 {
	int po;
	int ne;
	long long int Cedula;
	char NyP[20];
	struct LC433 *prox;
};
void intercambiarC433(int *poa,int *nea,int *pob,int *neb,long long int *CedulaA,long long int *CedulaB){
	int aux = *poa;
	*poa = *pob;
	*pob = aux;
	aux = *nea;
	*nea = *neb;
	*neb = aux;
	aux = *CedulaA;
	*CedulaA = *CedulaB;
	*CedulaB = aux;
}
void ordIntercambioC433(struct LC433 *l){
	struct LC433 *aux;
	char N[20];
		for(  ; l->prox ; l=l->prox)
			for(aux=l->prox; aux ; aux = aux->prox)
				if( ((l->po < aux->po) || (l->po < aux->ne)) && ((l->ne < aux->po) || (l->ne < aux->ne)) ){
					intercambiarC433(&(l->po),&(l->ne),&(aux->po),&(aux->ne),&(l->Cedula),&(aux->Cedula));
					strcpy(N,l->NyP);
					strcpy(l->NyP,aux->NyP);
					strcpy(aux->NyP,N);
				}	
}
void AgregarLC433(int po,int ne,long long int Cedula,struct LC433 **l){
	struct LC433 *temp = new struct LC433;
	temp->po = po;
	temp->ne = ne;
	temp->Cedula = Cedula;
	temp->prox = *l;
	*l = temp; 
}
void C433 (struct Persona *PER){
	int po,ne;
	struct LC433 *AUX = NULL;
	struct Persona *Per$ = PER;
	struct Pedido *Ped$;
	if (Per$){
		for (  ; Per$ ; Per$=Per$->prox ){
			Ped$ = Per$->ped;
			po=0;ne=0;
			for (  ; Ped$ ; Ped$=Ped$->prox ){
				if (Ped$->Entregado==1)
					po+=Ped$->Monto;
				if (Ped$->Entregado==0)
					ne+=Ped$->Monto;
			}
			AgregarLC433(po,ne,Per$->Cedula,&AUX);
			strcpy(AUX->NyP,Per$->NyP);
		}
		ordIntercambioC433(AUX);
		printf("\n\n\t Mostrando a todos los clientes junto a su total gastado (orden descendiente): ");
		for (  ; AUX ; AUX=AUX->prox ){
		printf("\n\n------------------------------------------\n\n");
		printf("\n\t Nombre y apellido: %s",AUX->NyP);
		printf("\n\n\t Cedula: %i",AUX->Cedula);
		Color(LGREEN,BLACK);printf("\n\n\t $%i",AUX->po);Color(LRED,BLACK);printf("($-%i)",AUX->ne);ColorB();		
		}
		printf("\n\n------------------------------------------\n\n");
	}else{
		Color(LRED,BLACK);
		printf("\n\t *ERROR: No hay personas registradas...Intentelo otra vez*");
		ColorB();
		printf("\n\n\t ");
		system("pause");
		system("cls");	
	}
}
void C434(struct Persona *PER){
	int po,ne;
	struct Persona *Per$ = PER;
	struct Pedido *Ped$;
	struct DPI *DPI$;
	printf("\n\n\t Mostrando a todos los clientes junto a su total de productos comprados: ");
	for (  ; Per$ ; Per$=Per$->prox ){
		Ped$ = Per$->ped;
		po=0;ne=0;
		for (  ; Ped$ ; Ped$=Ped$->prox ){
			DPI$ = Ped$->DPI;
			for (  ; DPI$ ; DPI$=DPI$->prox ){
				if (Ped$->Entregado==1)
					po+=DPI$->Cantidad;
				if (Ped$->Entregado==0)
					ne+=DPI$->Cantidad;
			}
		}
		printf("\n\n------------------------------------------\n\n");
		printf("\n\t Nombre y apellido: %s",Per$->NyP);
		printf("\n\n\t Cedula: %i",Per$->Cedula);
		Color(LGREEN,BLACK);printf("\n\n\t %i",po);Color(LRED,BLACK);printf("(-%i)",ne);ColorB();	
	}
	printf("\n\n------------------------------------------\n\n");	
}

void intercambiar(int *n1, int *n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void intercambiarfecha(char string1[], char string2[]){
	char aux[11];
	strcpy(aux,string1);
	strcpy(string1,string2);
	strcpy(string2,aux);
}

void calcularstring(char string[], int *anualidad, int *mes, int *dia){
	int longitud=strlen(string);
	int i=0,cont=0;
	for(i=0; i!=longitud; i++){
		if(string[i]!='/'){
			if(!cont)
			*anualidad= *anualidad*10 + (string[i]-'0');
			else if(cont==1) {
			*mes=*mes*10+(string[i]-'0');	
			}
			else if(cont==2){
				*dia = *dia*10 +(string[i]-'0');;
			}
			
	    } else {
	      cont++;
		}
	}
}



int mayorfecha(char string1[], char string2[]){
	int mayor=0;
	int anualidad=0, mes=0, dia=0, anualidad2=0, mes2=0, dia2=0;

	calcularstring(string1,&anualidad,&mes,&dia);
	calcularstring(string2,&anualidad2,&mes2,&dia2);
	
	if(anualidad>anualidad2)
		mayor=1;
	else if(anualidad==anualidad2){
		if(mes>mes2)
		  mayor=1;
	    else if(mes==mes2){
			if (dia>dia2)
			  mayor=1;
		}
	}
	return mayor;
}



void ordIntercambiomonto(Pedido *l, int tipo)
{
	Pedido *aux;
	if(l)
	{
		for( ; l->prox; l = l->prox){
			for(aux = l->prox; aux; aux = aux->prox){
				if((l->Monto < aux->Monto && tipo==1) || (!(mayorfecha(l->Fecha, aux->Fecha)) && tipo==2)){
					intercambiar(&(l->NumFactura), &(aux->NumFactura));
					intercambiar(&(l->Monto), &(aux->Monto));
					intercambiar(&(l->CodigoEm), &(aux->CodigoEm));
					intercambiarfecha((l->Fecha),(aux->Fecha));
				}
		   } 
	   }
	}
}

void mostrarpedidoC435(Pedido *ped, Empresa *e){
    while(ped){
      printf("\n     ------------------------------------------------------------") ;	
   	  printf("\n\tNumero de Factura: %i \n", ped->NumFactura);
      printf("\n\t  Codigo de Empresa: %i", ped->CodigoEm);
	  printf("\n\t  Tipo de Empresa: %i", buscarempresa(e,ped->CodigoEm)->Tipo);   	
	  printf("\n\t  Monto: $%i", ped->Monto);   	 
	  printf("\n\t  Fecha: %s", ped->Fecha);   	
   	  ped=ped->prox;
   }
    printf("\n     ------------------------------------------------------------\n"); 	
}


void Consulta435(Persona *p, Empresa *e){
	Pedido *Aux=NULL, *nuevopedido;
	Pedido *auxrecorrido;
	int opcion;
	
	while(p){
		auxrecorrido=p->ped;
		while(auxrecorrido){
			if(auxrecorrido->Entregado){
				nuevopedido=new Pedido;
				nuevopedido->NumFactura=auxrecorrido->CodigoEm;
				nuevopedido->CodigoEm=auxrecorrido->CodigoEm;
				nuevopedido->Monto=auxrecorrido->Monto;
				strcpy(nuevopedido->Fecha,auxrecorrido->Fecha);
				nuevopedido->DPI=NULL;
				nuevopedido->prox=Aux;
				Aux=nuevopedido;
			}
			auxrecorrido=auxrecorrido->prox;
		}
		p=p->prox;
	}
	//ordenamos
	printf("\n\n\tDe que forma desea ordenar? \n");
	printf("\n\t  1. Por Monto Total");
	printf("\n\t  2. Por Fecha de Emision");
	printf("\n\t         Numero de opcion: "); scanf("%i",&opcion);
    switch(opcion){
	   case 1:
	   ordIntercambiomonto(Aux,1);
	   mostrarpedidoC435(Aux,e);
	   break;
	   case 2:
	   ordIntercambiomonto(Aux,2);
	   mostrarpedidoC435(Aux,e);	
	   break;
	   default:
	   system("cls");
	   printf("\n\tOpcion invalida, intentelo otra vez...");
	   break;	 	
	}
}

////////////////////////////////////////////////////FIN DEL MENU DE CONSULTAS//////////////////////////////////////////
///////////////////////////////////////////MENU DE ARCHIVOS (INICIO)///////////////////////////////////////////////////
int existepedido(Pedido *ped, int factura){
    int boolean=0;
    while(ped){
	    if(ped->NumFactura==factura){
	  	  boolean=1;
		  break;  	
	    }
	   ped=ped->prox; 
    }
    return boolean;
}
void CrearA (struct Persona *P, struct Empresa *E) {
	FILE *A;
	FILE *B;
	struct Empresa *aux2;
	struct Producto *aux3;
	aux2=E;
	remove("ARCHIVOEMPRESA.txt");
	B=fopen("ARCHIVOEMPRESA.txt","at");
	for (  ; aux2 ; aux2=aux2->prox ){
		fprintf(B,"EMPRESA\n");
		fprintf(B,"%i\n",aux2->CodigoEm);
		fprintf(B,"%s\n",aux2->Nombre);
		fprintf(B,"%i\n",aux2->Tipo);
		fprintf(B,"%s\n",aux2->Telf);
		fprintf(B,"%s\n",aux2->Dir);
		fprintf(B,"------------------------------------------------------------\n");
		aux3 = aux2->prod;
		for (  ; aux3 ; aux3=aux3->prox ) {
			fprintf(B,"PRODUCTO\n");
			fprintf(B,"%i\n",aux3->CodigoPr);
			fprintf(B,"%s\n",aux3->Descr);
			fprintf(B,"%i\n",aux3->PrecioCU);
			fprintf(B,"%i\n",aux3->Act);	
			fprintf(B,"------------------------------------------------------------\n");
		}
	}
	fclose(B);
	struct Persona *aux;
	struct Pedido *aux4;
	struct DPI *aux5;	
	aux=P;
	remove("ARCHIVOPERSONA.txt");
	A=fopen("ARCHIVOPERSONA.txt","at");
	for (  ; aux ; aux=aux->prox ){
		fprintf(A,"PERSONA\n");
		fprintf(A,"%i\n",aux->Cedula);
		fprintf(A,"%s\n",aux->NyP);
		fprintf(A,"%s\n",aux->FechaN);
		fprintf(A,"%s\n",aux->CiuN);
		fprintf(A,"%s\n",aux->Dir);
		fprintf(A,"------------------------------------------------------------\n");
		aux4 = aux->ped;
		for (  ; aux4 ; aux4=aux4->prox ) {
			fprintf(A,"FACTURA\n");
			fprintf(A,"%i\n",aux4->NumFactura);
			fprintf(A,"%i\n",aux4->CodigoEm);
			fprintf(A,"%s\n",aux4->Fecha);
			fprintf(A,"%i\n",aux4->Entregado);
			fprintf(A,"%i\n",aux4->Monto);
			fprintf(A,"------------------------------------------------------------\n");
			aux5 = aux4->DPI;
				for (  ; aux5 ; aux5=aux5->prox ) {
				fprintf(A,"DPI\n");
				fprintf(A,"%i\n",aux5->CodigoPr);
				fprintf(A,"%i\n",aux5->Cantidad);
				fprintf(A,"%i\n",aux5->Precio);	
				fprintf(A,"------------------------------------------------------------\n");
				}
		}
	}
	fclose(A);
}
//Inserta un producto en la variable dada (inserta diferente a insertarproducto para que pueda funcionar correctamente dentro del subprograma para leer archivos)
void insertarempresaE2 (Producto **cab, int CodigoPr, char Descr[20], int PrecioCU, bool Act) {
Producto *t;
t = new struct Producto;
t->CodigoPr = CodigoPr;
strcpy(t->Descr,Descr);
t->PrecioCU = PrecioCU;
t->Act = Act;
t->prox = *cab;
*cab = t;	
}
//Inserta una empresa en la variable dada (sin los productos) (inserta diferente a insertarempresa para que pueda funcionar correctamente dentro del subprograma para leer archivos)
void insertarempresaE1 (Empresa **cab, int CodigoEm, char Nombre[20],int Tipo, char Telf[12], char Dir[40]) {
Empresa *t;
t = new struct Empresa;
t->CodigoEm = CodigoEm;
strcpy(t->Nombre,Nombre);
t->Tipo = Tipo;
strcpy(t->Telf,Telf);
strcpy(t->Dir,Dir);
t->prod = NULL;
t->prox = *cab;
*cab = t;	
}
//Inserta un pedido en la variable dada, pero no sus detalles
void insertarpersonaE2 (Pedido **cab, int NumFactura, int CodigoEm, char Fecha[20], bool Entregado, int Monto)  {	
Pedido *t;
t = new struct Pedido;
t->NumFactura = NumFactura;
t->CodigoEm = CodigoEm;
strcpy(t->Fecha,Fecha);
t->Entregado = Entregado;
t->Monto = Monto;
t->DPI = NULL;
t->prox = *cab;
*cab = t;
}
//Inserta una persona en la variable dada, pero no sus facturas
void insertarpersonaE1 ( Persona **cab, long long int Cedula, char NyP [20], char FechaN[15], char CiuN [15], char Dir [40]){
Persona *t;  
t= new struct Persona;
t->Cedula = Cedula;
strcpy(t->NyP,NyP);
strcpy(t->FechaN,FechaN);
strcpy(t->CiuN,CiuN);
strcpy(t->Dir,Dir);
t->ped = NULL;	
t->prox = *cab;
*cab = t;		
}
//Devuelve 1 si se encuentra con la cedula dada, 0 en caso contrario
int personarepetida (Persona *Original, int Cedula) {
int resultado;
resultado = 0;
	while (Original) {
	if (Original->Cedula == Cedula) {
	resultado = 1;	
	}
	Original = Original->prox;	
	}
return resultado;		
}
//Lee y recupera los datos en los archivos, no recupera aquellas personas con cedulas iguales y empresas con codigos iguales para evitar la duplicidad 
void LeerA(struct Persona **P,struct Empresa **E){
	FILE *A;
	FILE *B;
	struct Persona *aux = new struct Persona;
	struct Empresa *aux2 = new struct Empresa;
	A=fopen("ARCHIVOPERSONA.txt","at");
	fclose(A);
	B=fopen("ARCHIVOEMPRESA.txt","at");
	fclose(B);
	char Lin[100];
	char StringAux[100];
	Persona *R = NULL;
	while (*P) {
	insertarpersonaE1(&R,(*P)->Cedula,(*P)->NyP,(*P)->FechaN,(*P)->CiuN,(*P)->Dir);	
		while ((*P)->ped) {
		insertarpersonaE2(&(R->ped),(*P)->ped->NumFactura,(*P)->ped->CodigoEm,(*P)->ped->Fecha,(*P)->ped->Entregado,(*P)->ped->Monto);
			while ((*P)->ped->DPI) {
			insertarpersona4(&(R->ped->DPI),(*P)->ped->DPI->CodigoPr,(*P)->ped->DPI->Cantidad,(*P)->ped->DPI->Precio);
			(*P)->ped->DPI = (*P)->ped->DPI->prox;	
			}
		(*P)->ped = (*P)->ped->prox;			
		}
	*P = (*P)->prox;	
	}
	*P = R;	
	A=fopen("ARCHIVOPERSONA.txt","rt");
	fgets(Lin,100,A); strtok(Lin,"\n");	
	while (strcmp(Lin,"PERSONA") == 0){	
		fgets(StringAux,100,A); 
		aux->Cedula = atoi(StringAux);
		fgets(aux->NyP,20,A);
		strtok(aux->NyP,"\n");
		fgets(aux->FechaN,100,A);
		strtok(aux->FechaN,"\n");
		fgets(aux->CiuN,20,A);
		strtok(aux->CiuN,"\n");
		fgets(aux->Dir,40,A);
		strtok(aux->Dir,"\n");
		fgets(Lin,100,A);
		fgets(Lin,100,A); strtok(Lin,"\n");
		aux->prox = NULL;
		aux->ped = NULL;
		if (personarepetida(*P,aux->Cedula) == 0) {
		insertarpersonaE1(P,aux->Cedula,aux->NyP,aux->FechaN,aux->CiuN,aux->Dir);			
			while (strcmp(Lin,"FACTURA") == 0)	{
			aux->ped = new struct Pedido;	
			fgets(StringAux,100,A);
			aux->ped->NumFactura = atoi(StringAux);
			fgets(StringAux,100,A);
			aux->ped->CodigoEm = atoi(StringAux);	
			fgets(aux->ped->Fecha,100,A);
			strtok(aux->ped->Fecha,"\n");
			fgets(StringAux,100,A);
			aux->ped->Entregado = atoi(StringAux);				
			fgets(StringAux,100,A);
			aux->ped->Monto = atoi(StringAux);			
			fgets(Lin,100,A);
			fgets(Lin,100,A); strtok(Lin,"\n");			
			aux->ped->prox = NULL;
			aux->ped->DPI = NULL;
			insertarpersonaE2(&((*P)->ped),aux->ped->NumFactura,aux->ped->CodigoEm,aux->ped->Fecha,aux->ped->Entregado,aux->ped->Monto);
				while (strcmp(Lin,"DPI") == 0) {
				aux->ped->DPI = new struct DPI;
				fgets(StringAux,100,A);
				aux->ped->DPI->CodigoPr = atoi(StringAux);
				fgets(StringAux,100,A);
				aux->ped->DPI->Cantidad = atoi(StringAux);
				fgets(StringAux,100,A);
				aux->ped->DPI->Precio = atoi(StringAux);	
				fgets(Lin,100,A);
				fgets(Lin,100,A); strtok(Lin,"\n");
				aux->ped->DPI->prox = NULL;
				insertarpersona4(&((*P)->ped->DPI),aux->ped->DPI->CodigoPr,aux->ped->DPI->Cantidad,aux->ped->DPI->Precio);
				aux->ped->DPI = NULL;					
				}
			aux->ped = NULL;
			}		
		}
		aux = NULL;
		aux = new struct Persona;							
	}
	fclose(A);
	R = NULL;
	while (*P) {
	insertarpersonaE1(&R,(*P)->Cedula,(*P)->NyP,(*P)->FechaN,(*P)->CiuN,(*P)->Dir);	
		while ((*P)->ped) {
		insertarpersonaE2(&(R->ped),(*P)->ped->NumFactura,(*P)->ped->CodigoEm,(*P)->ped->Fecha,(*P)->ped->Entregado,(*P)->ped->Monto);
			while ((*P)->ped->DPI) {
			insertarpersona4(&(R->ped->DPI),(*P)->ped->DPI->CodigoPr,(*P)->ped->DPI->Cantidad,(*P)->ped->DPI->Precio);
			(*P)->ped->DPI = (*P)->ped->DPI->prox;	
			}
		(*P)->ped = (*P)->ped->prox;			
		}
	*P = (*P)->prox;	
	}
	*P = R;		
	fflush( stdin );
	Empresa *R2 = NULL;
	while (*E) {
	insertarempresaE1(&R2,(*E)->CodigoEm,(*E)->Nombre,(*E)->Tipo,(*E)->Telf,(*E)->Dir);
		while ((*E)->prod) {
		insertarempresaE2(&(R2->prod),(*E)->prod->CodigoPr,(*E)->prod->Descr,(*E)->prod->PrecioCU,(*E)->prod->Act);	
		(*E)->prod = (*E)->prod->prox;	
		}	
	*E = (*E)->prox;	
	}
	*E = R2;	
	B=fopen("ARCHIVOEMPRESA.txt","rt");
	fgets(Lin,100,B); strtok(Lin,"\n");
	while (strcmp(Lin,"EMPRESA") == 0) {
		fgets(StringAux,100,B);
		aux2->CodigoEm = atoi(StringAux);
		fgets(aux2->Nombre,20,B);
		strtok(aux2->Nombre,"\n");
		fgets(StringAux,100,B);
		aux2->Tipo = atoi(StringAux);
		fgets(aux2->Telf,13,B);
		strtok(aux2->Telf,"\n");
		fgets(aux2->Dir,40,B);
		strtok(aux2->Dir,"\n");
		aux2->prox = NULL;
		aux2->prod = NULL;		
		fgets(Lin,100,B);
		fgets(Lin,100,B); strtok(Lin,"\n");
		if (codigorepetido(*E,aux2->CodigoEm) == 0) {
		insertarempresaE1(E,aux2->CodigoEm,aux2->Nombre,aux2->Tipo,aux2->Telf,aux2->Dir);
			while (strcmp(Lin,"PRODUCTO") == 0) {
			aux2->prod = new struct Producto;	
			fgets(StringAux,100,B);
			aux2->prod->CodigoPr = atoi(StringAux);
			fgets(aux2->prod->Descr,20,B);
			strtok(aux2->prod->Descr,"\n");
			fgets(StringAux,100,B);
			aux2->prod->PrecioCU = atoi(StringAux);
			fgets(StringAux,100,B);
			aux2->prod->Act = atoi(StringAux);			
			fgets(Lin,100,B);
			fgets(Lin,100,B); strtok(Lin,"\n");	
			aux2->prod->prox = NULL;
			insertarempresaE2(&((*E)->prod),aux2->prod->CodigoPr,aux2->prod->Descr,aux2->prod->PrecioCU,aux2->prod->Act);
			aux2->prod = NULL;
			}							
		}
		aux2 = NULL;
		aux2 = new struct Empresa;
	}	
	fclose(B);
	R2 = NULL;
	while (*E) {
	insertarempresaE1(&R2,(*E)->CodigoEm,(*E)->Nombre,(*E)->Tipo,(*E)->Telf,(*E)->Dir);
		while ((*E)->prod) {
		insertarempresaE2(&(R2->prod),(*E)->prod->CodigoPr,(*E)->prod->Descr,(*E)->prod->PrecioCU,(*E)->prod->Act);	
		(*E)->prod = (*E)->prod->prox;	
		}	
	*E = (*E)->prox;	
	}
	*E = R2;	
}
////////////////////////////////////////////////FIN DEL MENU DE ARCHIVOS/////////////////////////////////////////
////////////////////////////////////////////////MENU PRINCIPAL (INICIO)/////////////////////////////////////////
int main(){
	struct Empresa *EMP = NULL;
    struct Persona *PER = NULL;
    LeerA(&PER,&EMP);
	bool m=0,o;
	int op;
	Color(LGREEN,BLACK);
	printf("\n\t\t Universidad Catolica Andres Bello");
	ColorB();
	printf("\n\n\t\t Escuela de Ingenieria Informatica");
	printf("\n\n\t\t Catedra: Algoritmo y Programacion II");
	Color(YELLOW,BLACK);
	printf("\n\n\n\n\n\t INTEGRANTES:");
	ColorB();
	printf("\n\n\t Aaron Palacios");
	printf("\n\t Asdrubal Asencio");
	printf("\n\t Jose Luis Lopez");
	printf("\n\t Guillermo Mendez");
	printf("\n\n\n\n\n\t\t\t");
	system("pause");
	system("cls");
	while (m==0){
		o=0;
		Color(YELLOW,BLACK);
		printf("\n\t MENU PRINCIPAL:");
		ColorB();
		printf("\n\n\t 1.)PERSONAS:");
		printf("\n\n\t 2.)EMPRESAS Y PRODUCTOS:");
		printf("\n\n\t 3.)ORDENES DE ENVIO:");
		printf("\n\n\t 4.)CONSULTAS:");
		printf("\n\n\t 5.)GUARDAR ARCHIVO");
	    printf("\n\n\t 6.)LEER ARCHIVO");
		printf("\n\n\t 0.)SALIR:");
		printf("\n\n\t\t Numero de la opcion: ");Color(YELLOW,BLACK);
		scanf("%i",&op);
		system("cls");
		switch(op){
			case 1:
				while(o==0){
					Color(YELLOW,BLACK);
					printf("\n\t MENU PRINCIPAL:");
					Color(LMAGENTA,BLACK);
					printf("\n\t\t 1.)MENU DE PERSONAS:");
					ColorB();
					printf("\n\n\t 1.)AGREGAR PERSONA");
					printf("\n\n\t 2.)MODIFICAR PERSONA");
					printf("\n\n\t 3.)CONSULTAR PERSONA");
					printf("\n\n\t 4.)ELIMINAR PERSONA");
					printf("\n\n\t 0.)VOLVER");
					printf("\n\n\t\t Numero de la opcion: ");Color(LMAGENTA,BLACK);
					scanf("%i",&op);
					system("cls");
					switch(op){
						case 1:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LMAGENTA,BLACK);
							printf("\n\t\t 1.)MENU DE PERSONAS:");
							printf("\n\t\t\t 1.1)AGREGAR PERSONA:");
							ColorB();
							agregarpersona(&PER);//Funcion agregar persona
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");	
						break;
						case 2:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LMAGENTA,BLACK);
							printf("\n\t\t 1.)MENU DE PERSONAS:");
							printf("\n\t\t\t 1.2)MODIFICAR PERSONA:");
							ColorB();
							modificarpersona(PER);//Funcion modificar persona
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");		
						break;
						case 3:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LMAGENTA,BLACK);
							printf("\n\t\t 1.)MENU DE PERSONAS:");
							printf("\n\t\t\t 1.3)CONSULTA DE PERSONA:");
							ColorB();
							consultarpersona(PER);//Funcion Consultar Persona
							ColorB();
							system("cls");		
						break;
						case 4:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LMAGENTA,BLACK);
							printf("\n\t\t 1.)MENU DE PERSONAS:");
							printf("\n\t\t\t 1.4)ELIMINAR PERSONA:");
							ColorB();
							eliminarpersona(&PER);//Funcion Eliminar Persona
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
						case 0:
							system("cls");
							o++;
						break;
						default:
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
					}		
				}	
			break;
			case 2:
				while (o==0){
					Color(YELLOW,BLACK);
					printf("\n\t MENU PRINCIPAL:");
					Color(LCYAN,BLACK);
					printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
					ColorB();
					printf("\n\n\t 1.)MENU DE EMPRESAS:");	
					printf("\n\n\t 2.)MENU DE PRODUCTOS:");
					printf("\n\n\t 0.)VOLVER:");
					printf("\n\n\t\t Numero de la opcion: ");Color(LCYAN,BLACK);
					scanf("%i",&op);
					system("cls");
					switch(op){
						case 1:
							while(o==0){
								Color(YELLOW,BLACK);
								printf("\n\t MENU PRINCIPAL:");
								Color(LCYAN,BLACK);
								printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
								printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
								ColorB();
								printf("\n\n\t 1.)AGREGAR EMPRESA:");
								printf("\n\n\t 2.)MODIFICAR EMPRESA:");
								printf("\n\n\t 3.)CONSULTAR EMPRESA:");
								printf("\n\n\t 4.)ELIMINAR EMPRESA:");
								printf("\n\n\t 0.)VOLVER");
								printf("\n\n\t\t Numero de la opcion: ");Color(LCYAN,BLACK);
								scanf("%i",&op);
								system("cls");
								switch(op){
									case 1:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
										printf("\n\t\t\t\t 2.1.1)AGREGAR EMPRESA:");
										ColorB();
										AgregarEmpresa(&EMP);//Funcion Agregar empresa 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									break;
									case 2:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
										printf("\n\t\t\t\t 2.1.2)MODIFICAR EMPRESA:");
										ColorB();
										ModificarEmpresa(&EMP,&PER);//Funcion Modificar empresa 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
										break;
									break;
									case 3:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
										printf("\n\t\t\t\t 2.1.3)CONSULTAR EMPRESA:");
										ColorB();
										ConsultarEmpresa2(EMP);//Funcion Consultar empresa 
										ColorB();
										printf("\n\n\t ");
									    system("pause");
										system("cls");
									break;
									case 4:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.1)MENU DE EMPRESAS:");
										printf("\n\t\t\t\t 2.1.4)ELIMINAR EMPRESA:");
										ColorB();
										EliminarEmpresa(&EMP,&PER);//Funcion Eliminar Empresa 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");		
									break;
									case 0:
										system("cls");
										o++;
									break;
									default:
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									break;	
								}
							}
							o=0;
						break;
						case 2:
							while(o==0){
								Color(YELLOW,BLACK);
								printf("\n\t MENU PRINCIPAL:");
								Color(LCYAN,BLACK);
								printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
								printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
								ColorB();
								printf("\n\n\t 1.)AGREGAR PRODUCTOS:");
								printf("\n\n\t 2.)MODIFICAR PRODUCTOS:");
								printf("\n\n\t 3.)CONSULTAR PRODUCTOS:");
								printf("\n\n\t 4.)ELIMINAR PRODUCTOS:");
								printf("\n\n\t 0.)VOLVER:");
								printf("\n\n\t\t Numero de la opcion: ");Color(LCYAN,BLACK);
								scanf("%i",&op);
								system("cls");
								switch(op){
									case 1:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
										printf("\n\t\t\t\t 2.2.1)AGREGAR PRODUCTOS:");
										ColorB();
										AgregarProducto(&EMP);//Funcion Agregar producto 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									break;
									case 2:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
										printf("\n\t\t\t\t 2.2.2)MODIFICAR PRODUCTOS:");
										ColorB();
										ModificarProducto(&EMP,&PER);//Funcion Modificar producto 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
										break;
									break;
									case 3:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
										printf("\n\t\t\t\t 2.2.3)CONSULTAR PRODUCTOS:");
										ColorB();
										ConsultarProducto2(EMP);//Funcion Consultar producto 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									break;
									case 4:
										Color(YELLOW,BLACK);
										printf("\n\t MENU PRINCIPAL:");
										Color(LCYAN,BLACK);
										printf("\n\t\t 2.)MENU DE EMPRESAS Y PRODUCTOS:");
										printf("\n\t\t\t 2.2)MENU DE PRODUCTOS:");
										printf("\n\t\t\t\t 2.2.4)ELIMINAR PRODUCTOS:");
										ColorB();
										EliminarProducto(&EMP,&PER);//Funcion Eliminar producto 
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");	
									break;
									case 0:
										system("cls");
										o++;
									break;
									default:
										Color(LRED,BLACK);
										printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
										ColorB();
										printf("\n\n\t ");
										system("pause");
										system("cls");
									break;	
								}
							}
							o=0;
						break;
						case 0:
							system("cls");
							o++;
						break;
						default:
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
					}
				}	
			break;
			case 3:
				while(o==0){
					Color(YELLOW,BLACK);
					printf("\n\t MENU PRINCIPAL:");
					Color(LGREEN,BLACK);
					printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
					ColorB();
					printf("\n\n\t 1.)SOLICITAR ENVIO:");
					printf("\n\n\t 2.)MODIFICAR ENVIO:");
					printf("\n\n\t 3.)CONSULTAR ENVIO:");
					printf("\n\n\t 4.)CIERRE DEL ENVIO:");
					printf("\n\n\t 5.)ELIMINAR ENVIO:");
					printf("\n\n\t 0.)VOLVER:");
					printf("\n\n\t\t Numero de la opcion: ");Color(LGREEN,BLACK);
					scanf("%i",&op);
					system("cls");
					switch(op){
						case 1:
							AgregarPedido(&PER,&EMP);//Funcion Solicitar Envio
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
						case 2:
							ModificarPedido(&PER,&EMP);//Funcion Modificar Envio
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");		
						break;
						case 3:
							ConsultarPedido(&PER);//Funcion Consultar Envio
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");		
						break;
						case 4:
							CierrePedido(&PER);//Funcion Cierre del Envio
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");	
						break;
						case 5:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LGREEN,BLACK);
							printf("\n\t\t 3.)MENU DE ORDENES DE ENVIO:");
							printf("\n\t\t\t 3.5)ELIMINAR ENVIO:");
							ColorB();
							EliminarPedido(&PER);//Funcion Eliminar Envio
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");	
						break;
						case 0:
							system("cls");	
							o++;
						break;
						default:
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
					}	
				}
			break;
			case 4:
				while(o==0){
					Color(YELLOW,BLACK);
					printf("\n\t MENU PRINCIPAL:");
					Color(LBLUE,BLACK);
					printf("\n\t\t 4.)MENU DE CONSULTAS:");
					ColorB();
					printf("\n\n\t 1.)CONSULTA DE EMPRESAS:");
					printf("\n\n\t 2.)CONSULTA DE PERSONAS:");
					printf("\n\n\t 3.)CONSULTA DE SISTEMA:");
					printf("\n\n\t 0.)VOLVER:");
					printf("\n\n\t\t Numero de la opcion: ");Color(LBLUE,BLACK);
					scanf("%i",&op);
					system("cls");	
					switch(op){
						case 1:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LBLUE,BLACK);
							printf("\n\t\t 4.)MENU DE CONSULTAS:");
							printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
							ColorB();
							printf("\n\n\t 1.)OPCION 4.1.1:");
							printf("\n\n\t 2.)OPCION 4.1.2:");
							printf("\n\n\t 3.)OPCION 4.1.3:");
							printf("\n\n\t 4.)OPCION 4.1.4:");
							printf("\n\n\t 5.)OPCION 4.1.5:");
							printf("\n\n\t 0.)VOLVER:");
							printf("\n\n\t\t Numero de la opcion: ");Color(LBLUE,BLACK);
							scanf("%i",&op);
							system("cls");	
							switch(op){
								case 1:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
									printf("\n\t\t\t\t 4.1.1)OPCION 4.1.1:");
									ColorB();
									C411(PER,EMP);//Funcion de la opcion 4.1.1
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								break;
								case 2:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
									printf("\n\t\t\t\t 4.1.2)OPCION 4.1.2:");
									ColorB();
									C412(PER,EMP);//Funcion de la opcion 4.1.2
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								break;
								case 3:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
									printf("\n\t\t\t\t 4.1.3)OPCION 4.1.3:");
									ColorB();
									C413(PER);//Funcion de la opcion 4.1.3
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								break;
								case 4:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
									printf("\n\t\t\t\t 4.1.4)OPCION 4.1.4:");
									ColorB();
									Consulta414(PER);//Funcion de la opcion 4.1.4
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								break;
								case 5:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.1)CONSULTA DE EMPRESAS:");
									printf("\n\t\t\t\t 4.1.5)OPCION 4.1.5:");
									ColorB();
									Consulta417(PER,EMP);//Funcion de la opcion 4.1.5
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");	
								break;
								case 0:
									system("cls");	
								break;
								default:
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
							}
						break;
						case 2:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LBLUE,BLACK);
							printf("\n\t\t 4.)MENU DE CONSULTAS:");
							printf("\n\t\t\t 4.2)CONSULTA DE PERSONAS:");
							ColorB();
							printf("\n\n\t 1.)OPCION 4.2.1:");
							printf("\n\n\t 2.)OPCION 4.2.2:");
							printf("\n\n\t 0.)VOLVER:");
							printf("\n\n\t\t Numero de la opcion: ");Color(LBLUE,BLACK);
							scanf("%i",&op);
							system("cls");	
							switch(op){
								case 1:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.2)CONSULTA DE PERSONAS:");
									printf("\n\t\t\t\t 4.2.1)OPCION 4.2.1:");
									ColorB();
									menucase421(PER,EMP);//Funcion de la opcion 4.2.1
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 2:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.2)CONSULTA DE PERSONAS:");
									printf("\n\t\t\t\t 4.2.2)OPCION 4.2.2:");
									ColorB();
									Menu422(EMP,PER);//Funcion de la opcion 4.2.2
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 0:
									system("cls");
								break;
								default:
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
							}
						break;
						case 3:
							Color(YELLOW,BLACK);
							printf("\n\t MENU PRINCIPAL:");
							Color(LBLUE,BLACK);
							printf("\n\t\t 4.)MENU DE CONSULTAS:");
							printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
							ColorB();
							printf("\n\n\t 1.)OPCION 4.3.1:");
							printf("\n\n\t 2.)OPCION 4.3.2:");
							printf("\n\n\t 3.)OPCION 4.3.3:");
							printf("\n\n\t 4.)OPCION 4.3.4:");
							printf("\n\n\t 5.)OPCION 4.3.5:");
							printf("\n\n\t 0.)VOLVER:");
							printf("\n\n\t\t Numero de la opcion: ");Color(LBLUE,BLACK);
							scanf("%i",&op);
							system("cls");	
							switch(op){
								case 1:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
									printf("\n\t\t\t\t 4.3.1)OPCION 4.3.1:");
									ColorB();
									Consulta431(EMP,PER);//Funcion de la opcion 4.3.1
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 2:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
									printf("\n\t\t\t\t 4.3.2)OPCION 4.3.2:");
									ColorB();
									Consulta432(EMP,PER);//Funcion de la opcion 4.3.2
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 3:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
									printf("\n\t\t\t\t 4.3.3)OPCION 4.3.3:");
									ColorB();
									C433(PER);//Funcion de la opcion 4.3.3
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 4:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
									printf("\n\t\t\t\t 4.3.4)OPCION 4.3.4:");
									ColorB();
									C434(PER);//Funcion de la opcion 4.3.4
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 5:
									Color(YELLOW,BLACK);
									printf("\n\t MENU PRINCIPAL:");
									Color(LBLUE,BLACK);
									printf("\n\t\t 4.)MENU DE CONSULTAS:");
									printf("\n\t\t\t 4.3)CONSULTA DE SISTEMA:");
									printf("\n\t\t\t\t 4.3.5)OPCION 4.3.5:");
									ColorB();
									Consulta435(PER, EMP);
									//Funcion de la opcion 4.3.5
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
								case 0:
									system("cls");
								break;
								default:
									Color(LRED,BLACK);
									printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
									ColorB();
									printf("\n\n\t ");
									system("pause");
									system("cls");
								break;
							}
						break;
						case 0:
							system("cls");
							o++;
						break;
						default:
							Color(LRED,BLACK);
							printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
							ColorB();
							printf("\n\n\t ");
							system("pause");
							system("cls");
						break;
						}
					}	
			break;
			case 5:
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(BROWN,BLACK);
				printf("\n\t\t 5.)GUARDAR ARCHIVO:");
				Color(LGREEN,BLACK);
				printf("\n\n\t *ARCHIVO GUARDADO CON EXITO*");
				ColorB();
				CrearA(PER,EMP);
				printf("\n\n\t ");
				system("pause");
				system("cls");
			break;
			case 6:
				Color(YELLOW,BLACK);
				printf("\n\t MENU PRINCIPAL:");
				Color(BROWN,BLACK);
				printf("\n\t\t 6.)LEER ARCHIVO:");
				Color(LGREEN,BLACK);
				printf("\n\n\t *ARCHIVO LEIDO CON EXITO*");
				ColorB();
				LeerA(&PER,&EMP);
				printf("\n\n\t ");
				system("pause");
				system("cls");
			break;	
			case 0:
				CrearA(PER,EMP);
				system("cls");
				m++;	
			break;
			default:
				Color(LRED,BLACK);
				printf("\n\t *ERROR: Opcion no valida... Intentelo otra vez*");
				ColorB();
				printf("\n\n\t ");
				system("pause");
				system("cls");
			break;
		}
	}		
return 0;}
////////////////////////////////////////////////FIN MENU PRINCIPAL///////////////////////////////////////////////
