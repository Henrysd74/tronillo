//PROGRAMA QUE CAPTURA UNA CADENA DE CARACTERES DE MAXIMO 200 ELEMENTOS Y
//CREA UN ARBOL DE BUSQUEDA CON LOS CARACTERES DE LA CADENA Y REALIZA RECORRIDOS
// EN PREORDEN,ENTREORDEN Y POSTORDEN.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct articulo {
    int codigo;
    int idproveedor;
    int precio;
    string nombre;
    
};

struct proveedor {
    int idproveedor;
    string nombre;
    string telefono;
    int sd;

}provehedores[50];

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
struct nodoarbol {                        //ESTRUCTURA DEL ARBOL
    struct nodoarbol* izqnodo;
    articulo p;
    //proveedor h;
    struct nodoarbol* dernodo;
};


typedef struct nodoarbol NODO;    //DEFINICION DE TIPO NODO
typedef NODO* ARBOL;               //DECLARACION DE VARIABLE PUNTERO A NODO
//typedef NODO* ARBOL2;


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void insertanodonuevo(ARBOL*, articulo);    //DECLARACION DE FUNCIONES
//void insertanodonuevo2(ARBOL2*, proveedor);
void inorden(ARBOL);
void preorden(ARBOL);
void postorden(ARBOL);
void treefree(ARBOL);
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-----------------------<FUNCION PRINCIPAL>--------------------------------*/
int main() {

    int i, selec;
    int op = 0;                          //CONTADOR
    int op1 = 0;
    int cont = 0;
    int aux;
    bool encotrado = false;
    char newnod, elementos;    //DECLARACION DE CADENA,BANDERA Y VARIABLE QUE CONTIENE EL NUEVO VALOR A INSERTAR EN EL ARBOL
    ARBOL raiz = NULL;
    //ARBOL2 raiz2 = NULL;
    //DECLARACION DE VARIABLE DE TIPO ARBOL
    articulo p;
    proveedor h;

    do {
        system("cls");
        cout << "\nSeleccione la opcion que desea realizar\n";
        cout << "1: Ingreso del Proveedor" << endl;
        cout << "2: Ingreso del Articulo" << endl;
        cout << "3: Ver articulos" << endl;
        cout << "4: Salir" << endl;
        cin >> selec;

        switch (selec)
        {
        case 1:

            
            do
            {
                system("cls");

                cout << "Ingrese el Idproveedor: ";
                cin >> provehedores[cont].idproveedor;
                cout << "Ingrese el nombre del proveedor: ";
                cin >> provehedores[cont].nombre;
                cout << "Ingrese el telefono: ";
                cin >> provehedores[cont].telefono;
                cout << "Desea continuar ?" << endl;
                cout << "Presicone 0 si desea continuar";
                cin >> op1;
                if (op1 == 0) {
                    cont++;
                }
                

            } while (op1 == 0);

           

            break;


        case 2:

            if (provehedores[0].idproveedor != NULL) {

                do
                {
                    system("cls");
                    

                    cout << "Lista de proveedores " << endl;
                    for (int i = 0; i < cont+1; i++) {
                        cout <<"Id: "<<provehedores[i].idproveedor;
                        cout <<"\tNombre: "<<provehedores[i].nombre;
                        cout <<"\tTelefono: "<<provehedores[i].telefono << endl;
                    }

                    cout << "Ingrese el Idproveedor: ";
                    cin >> aux;
                    
                    for (int i = 0; i < cont + 1; i++) {
                        if (aux == provehedores[i].idproveedor) {
                            encotrado = true;
                        }
                    }
                    
                    if (encotrado) {

                        p.idproveedor = aux;
                        cout << "Ingrese el codigo: ";
                        cin >> p.codigo;
                        cout << "Ingrese el nombre del producto: ";
                        cin >> p.nombre;
                        cout << "Ingrese el precio: ";
                        cin >> p.precio;
                        insertanodonuevo(&raiz, p);
                        cout << "Desea continuar ?" << endl;
                        cout << "Presicone 0 si desea continuar";
                        cin >> op;
                        encotrado = false;

                    }else {
                            cout << "Proveedor no valido " << endl;
                            _getch();
                            
                        }
                    

                } while (op == 0);

            }
            else {

                cout << "No tiene ningun proveedor ingresado\n" << endl;
                break;
            }
            
            break;
            

        case 3:

            printf("\n\n preorden ¯¯\t");
            preorden(raiz);                 //LLAMADO A FUNCION DE RECORRIDO EN PREORDEN
            printf("\n\n inorden  ¯¯\t");
            inorden(raiz);                  //LLAMADO A FUNCION DE RECORRIDO EN INORDEN
            printf("\n\n postorden ¯¯\t");
            postorden(raiz);                //LLAMADO A FUNCION DE RECORRIDO EN POSTORDEN
            //treefree(raiz);            //LIBERACION DE MEMORIA DEL ARBOL.
            //raiz = NULL;                  //ASIGNACION DE UN VALOR NULO A LA RAIZ.
            _getch();
            break;


        }
   

    } while (selec != 4);


    return 0;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-CREA UN NUEVO NODO Y COLOCA LOS VALORES DEL NUEVO ELEMENTO EN LA POSICION CORRESPONDIENTE */

void insertanodonuevo(ARBOL* rarbol, articulo nuevo) {
    if (*rarbol == NULL) {                          //CREACION DE UN NUEVO NODO
        *rarbol = new NODO;
        if (*rarbol != NULL) {
            //ASIGNACION DE VALORES NUEVOS EN EL NODO NUEVO
            (*rarbol)->p.codigo = nuevo.codigo;
            (*rarbol)->p.nombre = nuevo.nombre;
            (*rarbol)->p.precio = nuevo.precio;
            (*rarbol)->p.idproveedor = nuevo.idproveedor;
            (*rarbol)->izqnodo = NULL;
            (*rarbol)->dernodo = NULL;
        }
        else {
            printf("\n­­­­ Memoria No Disponible !!!!\n");
        }
    }
    else
        if (nuevo.codigo < (*rarbol)->p.codigo)  //checa si el elemento nuevo es mayor que el elemento padre
            insertanodonuevo(&((*rarbol)->izqnodo), nuevo);  //coloca el elemento a la izquierda del padre o raiz
        else
            if (nuevo.codigo > (*rarbol)->p.codigo)  //checa si el elemento nuevo es menor que el elemento padre
                insertanodonuevo(&((*rarbol)->dernodo), nuevo);  //coloca el elemento a la derecha del padre o raiz
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//FUNCION ITERATIVA LA CUAL RECORRE EL ARBOL IMPRIMIENDO SIEMPRE EL VALOR
//QUE CONTIENE LA RAIZ,DESPUES LA RAMA IZQUIERDA,LUEGO LA RAMA DERECHA,SIEMPRE
//Y CUANDO LA RAIZ SEA DIFERENTE DE UN VALOR NULO, SI ES NULO SALTA A LA SIGUIENTE INSTRUCCION.

void preorden(ARBOL rarbol) {
    
    if (rarbol != NULL) {
        cout << "Codigo: " << rarbol->p.codigo << "  ";
        cout << "Nombre: " << rarbol->p.nombre << "  ";
        cout << "Precio: " << rarbol->p.precio << "  ";
        cout << "Idproveedor" << rarbol->p.idproveedor << "  ";
        preorden(rarbol->izqnodo);
        preorden(rarbol->dernodo);
        
        
    }
    
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//FUNCION ITERATIVA LA CUAL RECORRE EL ARBOL BUSCANDO EL NODO MAS IZQUIERDO
//QUE CONTIENE EL ARBOL O SEA HASTA QUE LA RAMA DEL ULTIMO NODO SEA NULO,LUEGO LA IMPRIME,DESPUES
//DESPUES LA RAIZ DEL SUB-ARBOL,Y LUEGO EL NODO DE LA DERECHA..

void inorden(ARBOL rarbol) {
    

    if (rarbol != NULL) {
        inorden(rarbol->izqnodo);
        cout << "Codigo: " << rarbol->p.codigo << "  ";
        cout << "Nombre: " << rarbol->p.nombre << "  ";
        cout << "Precio: " << rarbol->p.precio << "  ";
        cout << "Idproveedor" << rarbol->p.idproveedor << "  ";
        inorden(rarbol->dernodo);  
    }
    
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//FUNCION ITERATIVA LA CUAL RECORRE EL ARBOL BUSCANDO EL NODO QUE ESTA MAS A LA IZQUIERDA
//LUEGO EL NODO DE LA DERECHA Y LUEGO LA RAIZ DE ESE SUB-ARBOL

void postorden(ARBOL rarbol) {
    
    if (rarbol != NULL) {
        postorden(rarbol->izqnodo);
        
        postorden(rarbol->dernodo);
        cout << "Codigo: " << rarbol->p.codigo << "  ";
        cout << "Nombre: " << rarbol->p.nombre << "  ";
        cout << "Precio: " << rarbol->p.precio << "  ";
        cout << "Idproveedor" << rarbol->p.idproveedor << "  ";
        
    }
    
}

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//FUNCION ITERATIVA IDENTICA AL RECORRIDO EN POSTORDEN LA UNICA DIFERENCIA
//ES QUE EN VEZ DE IMPRIMIR EN PANTALLA EL VALOR DE UN NODO ESTE ES
//ELIMINADO DEL ARBOL LIBERANDO LA MEMORIA CON LA FUNCION free(), ELEGI ESTA
//FORMA YA QUE SE ELIMINA PRIMERO LOS NODOS HIJO DE EL SUB-ARBOL Y LUEGO LA RAIZ
//YA QUE SI SE ELIMINA LA RAIZ PRIMERO, LOS DATOS DE LOS HIJOS SE DESCONECTAN
//DEL ARBOL PERO LA MEMORIA QUE OCUPABAN SIGUE SIENDO UTILIZADA Y DE ESTA FORMA
//SE ELIMINA EL ARBOL DE ABAJO HACIA ARRIBA (O SEA DE LOS HIJOS A LA RAIZ).

void treefree(ARBOL rarbol) {
    if (rarbol != NULL) {
        treefree(rarbol->izqnodo);
        treefree(rarbol->dernodo);
        free(rarbol);
    }
}