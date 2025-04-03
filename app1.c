#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)

//10 distintas metricas
//Pizza mas vendida
void pms() {
   printf("Llamaste a pms\n");
}
void pls() {
   printf("Llamaste a pls\n");
}
void dms() {
   printf("Llamaste a dms\n");
}
void dls() {
   printf("Llamaste a dls\n");
}
void dmsp() {
   printf("Llamaste a dmsp\n");
}
void dlsp() {
   printf("Llamaste a dlsp\n");
}
void apo() {
   printf("Llamaste a apo\n");
}
void apd() {
   printf("Llamaste a apd\n");
}
void ims() {
   printf("Llamaste a ims\n");
}
void hp() {
   printf("Llamaste a hp\n");
}

//Un struct por cada linea que tenga el csv
typedef struct {
   double PizzaId;
   double OrdenId;
   char PizzaNameId[50];
   double Cantidad;
   char Fecha[50];
   char Hora[50];
   double PrecioUnitario;
   double PrecioTotal;
   char Tamanio[50];
   char Categoria[100];
   char Ingredientes[300];
   char Nombre[100];
} Compra;

int main(int argc, char *argv[]) {
   //declaracion de variables
   int args = argc;
   char **argArr = argv;
   char lenLinea[800];
   int len = 0;
   int registro = 0;

   //proceso para tener una variable que muestre la cantidad de lineas que tiene el csv (len)
   FILE *lala;
   lala = fopen("datos.csv","r");
   fgets(lenLinea, sizeof(lenLinea), lala);
   while (fgets(lenLinea, sizeof(lenLinea), lala)) {
      len++;
   }
   fclose(lala);

   //proceso para leer cada linea del csv, y almacenarlas en structs, donde cada atributo del mismo es una columna del csv
   Compra compras[len-1];
   FILE *data;
   data = fopen("datos.csv","r");
   int skip = 1;
   do
   {
      if(skip == 1){
         skip = 0;
         continue;
      }
      fscanf(data, "%lf, %lf, %49[^,], %lf, %49[^,], %49[^,], %lf, %lf, %49[^,], %49[^,]\n", 
         &compras[registro].PizzaId, 
         &compras[registro].OrdenId, 
         compras[registro].PizzaNameId, 
         &compras[registro].Cantidad, 
         compras[registro].Fecha, 
         compras[registro].Hora, 
         &compras[registro].PrecioUnitario, 
         &compras[registro].PrecioTotal,
         compras[registro].Tamanio, 
         compras[registro].Categoria);
      if(registro == len-1){
         break;
      }
      registro++;
   } while (fgets(lenLinea, sizeof(lenLinea), data));
   printf("makako\n");

   //procesar el(los) input(s) del usuario, y llamar a la(s) funcion(es)
   for (int i = 1; i < args; i++) {
      if (strcmp(argArr[i], "pms") == 0) {
         pms();
      } else if (strcmp(argArr[i], "pls") == 0) {
         pls();
      } else if (strcmp(argArr[i], "dms") == 0) {
         dms();
      } else if (strcmp(argArr[i], "dls") == 0) {
         dls();
      } else if (strcmp(argArr[i], "dmsp") == 0) {
         dmsp();
      } else if (strcmp(argArr[i], "dlsp") == 0) {
         dlsp();
      } else if (strcmp(argArr[i], "apo") == 0) {
         apo();
      } else if (strcmp(argArr[i], "apd") == 0) {
         apd();
      } else if (strcmp(argArr[i], "ims") == 0) {
         ims();
      } else if (strcmp(argArr[i], "hp") == 0) {
         hp();
      }  else {
         printf("%s No es un comando\n", argArr[i]);
      }
   }
   fclose(data);
   return 0;
}