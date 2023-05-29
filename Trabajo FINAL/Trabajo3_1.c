#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
//Estructura para cada mes, cada float es un tipo de generacion de energia, siendo el float la energia generada con ese tipo.
  int mes;
  float Ha, Tb, N, C, Fg, M, Tg, Tv, Cc, He, E, Sf, St, O, Cg, Rn, Rr, Total;

}Energia;

float maximo(float datos[],int k);
float minimo(float datos[],int k);
void porcentaje_total_mes_sobre_anio(Energia mes[]);
void sumatorio_tipos(Energia mes[], float* result_sum2021, float* result_sum2022);
void porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[], float res_sum2021[], float res_sum2022[]);
void porcentaje_tipoenergia_sobre_mes(Energia mes[]);
void media_generacion_al_meses(Energia mes[]);
void media_generacion_tipos(Energia mes[], float res_sum2021[], float res_sum2022[]);
void relacion_ren_noren();
void balance_energia();
void precio_energia();
void imprimir_datos(float datos[]);
void menu(float datos[],Energia mes[],int k,float res_sum2021[], float res_sum2022[]);

int main()
{
Energia mes[24]; 
FILE *pf1;  //Abrimos el fichero en el que estan guardados todos los datos
pf1 = fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");

int i = 0, j = 0, k = 0;
char c, d, f; // Serviran para ir escaneando el fichero, c es el ultimo caracter escaneado, d el penultimo y f el antepenultimo
float datos[1000], t;// Para guardar inicialmentelos datos

if (pf1 == NULL)
{
     printf("Error al abrir el archivo origen.\n");
    return -1;
}
else
  {

    while (fscanf(pf1, "%c", &c) != EOF  ) 
    {
        if ((c == ',' && f == ',' && d == '-')  || (c == '\n' && f == ',' && d == '-'))//Para analizar los datos del fuel gas que aparecian como "-", y necesitamos tenerlos como 0 en el vector
        {
            datos[i] == 0;
            i++;
            k++;
        }

        else if (c == '"' && d == ',') //en el fichero todos los datos aparecen entre comillas y despues de una coma, con esta condicion, cuando el programa lea una coma y luego unas comillas escaneara un float
        {
            fscanf(pf1, "%f", &datos[i]);
            i++;
            k++;

        }
     f = d;//para que funcione lo del antepenultimo y penultimo
     d = c;
    }
   }
   i--;
   k--;
fclose(pf1);

for ( i = 96; i < 120; i++) //Para confirmar que en fuel gas es 0 ya que algunas veces se me quedaba pillado
{
   if (i != 102)
   {
    datos[i] = 0.0;
   }


}

for ( i = 0; i <= k; i++) //Asignar cada dato a su lugar correspondiente en la estructura
{
    if (i <= 23)
    {
        mes[i].Ha = datos[i];
    }
    else if (i > 23 && i <= 47)
    {
        mes[i-24].Tb = datos[i];
    }
    else if (i > 47 && i <= 71)
    {
        mes[i-48].N = datos[i];
    }
    else if (i > 71 && i <= 95)
    {
        mes[i-72].C = datos[i];
    }
    else if (i > 95 && i <= 119)
    {
        mes[i-96].Fg = datos[i];
    }
    else if (i > 119 && i <= 143)
    {
        mes[i-120].M = datos[i];
    }
    else if (i > 143 && i <= 167)
    {
        mes[i-144].Tg = datos[i];
    }
    else if (i > 167 && i <= 191)
    {
        mes[i-168].Tv = datos[i];
    }
    else if (i > 191 && i <= 215)
    {
        mes[i-192].Cc = datos[i];
    }
    else if (i > 215 && i <= 239)
    {
        mes[i-216].He = datos[i];
    }
    else if (i > 239 && i <= 263)
    {
        mes[i-240].E = datos[i];
    }
    else if (i > 263 && i <= 287)
    {
        mes[i-264].Sf = datos[i];
    }
    else if (i > 287 && i <= 311)
    {
        mes[i-288].St = datos[i];
    }
    else if (i > 311 && i <= 335)
    {
        mes[i-312].O = datos[i];
    }
    else if (i > 335 && i <= 359)
    {
        mes[i-336].Cg = datos[i];
    }
    else if (i > 359 && i <= 383)
    {
        mes[i-360].Rn = datos[i];
    }
    else if (i > 383 && i <= 407)
    {
        mes[i-384].Rr = datos[i];
    }
    else if (i > 407 && i <= 431)
    {
        mes[i-408].Total = datos[i];
    }

}

for (i = 0; i <= 23; i++)
{
    mes[i].mes = i + 1;
}


 float aux1[17], aux2[17], res_sum2021[17], res_sum2022[17];  //Llamado a la funcion sumatorio y pasando los vectores resultados a otros vectores para poder usar el sumatori en otras funciones
 sumatorio_tipos(mes, aux1, aux2);
 for (i = 0; i < 17; i++)
 {
    res_sum2021[i] = aux1[i];
    res_sum2022[i] = aux2[i];

 }
 menu(datos, mes,k,res_sum2021,res_sum2022); //LLamada al menu
//imprimir_datos(datos);
    return 0;
}

float maximo(float datos[],int k)
{
    int i;
    float maximo;
    int fila_usuario=1;

    //Maximo por tecnologia

    printf("\n      MENU DE MAXIMO POR TECNOLOGIA     \n\n");
    printf("De que tecnologia quieres saber el maximo?\n");
    printf(" 1. HIDRAULICA\n 2. TURBINACION BOMBEO\n 3. NUCLEAR\n 4. CARBON\n 5. FUEL + GAS\n 6. MOTORES DIESEL\n 7. TURBINA DE GAS\n 8. TURBINA DE VAPOR\n 9. CICLO COMBINADO\n 10. HIDROEOLICA\n 11. EOLICA\n 12. SOLAR FOTOVOLTAICA\n 13. SOLAR TERMICA\n 14. OTRAS RENOVABLES\n 15. COGENERACION\n 16. RESIDUOS NO RENOVABLES\n 17. RESIDUOS RENOVABLES\n");

    do
    {
        printf(" Elija una opcion:\n");
        scanf("%i",&fila_usuario);
    }
    while(fila_usuario<0||fila_usuario>17);
    for(i=0;i<18;i++)
    {
        maximo=datos[(fila_usuario*24)-24];
    }
    for(i=(fila_usuario*24)-23;i<(fila_usuario*24);i++)
        {
        if(datos[i]>maximo)
            {
            maximo= datos[i];
            }
        }

    printf("El maximo de la tecnologia elegida es: %.2f",maximo);

    return maximo;
}
float minimo(float datos[],int k)
{
    int i;
    float comparacion;
    int fila_usuario=4;


        //Minimo por tecnologia

        printf("\n      MENU DE MINIMO POR TECNOLOGIA     \n\n");
        printf("De que tecnologia quieres saber el minimo?\n");
        printf(" 1. HIDRAULICA\n 2. TURBINACION BOMBEO\n 3. NUCLEAR\n 4. CARBON\n 5. FUEL + GAS\n 6. MOTORES DIESEL\n 7. TURBINA DE GAS\n 8. TURBINA DE VAPOR\n 9. CICLO COMBINADO\n 10. HIDROEOLICA\n 11. EOLICA\n 12. SOLAR FOTOVOLTAICA\n 13. SOLAR TERMICA\n 14. OTRAS RENOVABLES\n 15. COGENERACION\n 16. RESIDUOS NO RENOVABLES\n 17. RESIDUOS RENOVABLES\n");


    do
    {
        printf(" Elija una opcion:\n");
        scanf("%i",&fila_usuario);
    }
    while(fila_usuario<0||fila_usuario>17);
    comparacion=datos[(fila_usuario*24)-24];
    for(i=(fila_usuario*24)-23;i<(fila_usuario*24);i++)
        {
        if(datos[i]<comparacion)
            {
            comparacion= datos[i];
            }
        }
    printf("El minimo de la tecnologia elegida es: %.2f",comparacion);
    return comparacion;
}
void porcentaje_total_mes_sobre_anio(Energia mes[])
{
    // El porcentaje de energia total generada en un mes respecto de la energia total generada ese anio
    int i;
    float Total2021 = 0, Total2022 = 0;
    float porcentaje_total_mes_sobre_anio[24];
for (i = 0; i < 24; i++) //Sumamos los totales de los mes para  el total de cada año
{
    if (i <= 11)
    {
        Total2021 = Total2021 + mes[i].Total;
    }
    else if (i > 11 && i <24)
    {
        Total2022 = Total2022 + mes[i].Total;
    }

}
for ( i = 0; i < 24; i++) //dividimos el total del cada mes entre el total del año*100 para el porcentaje
{
    if (i <= 11)
    {
       porcentaje_total_mes_sobre_anio[i] = mes[i].Total / Total2021 * 100;
    }
     else if (i > 11 && i <24)
    {
        porcentaje_total_mes_sobre_anio[i] = mes[i].Total / Total2022 * 100;
    }
}
printf("\n\nEl porcentaje de energia total generada en un mes respecto de la energia total generada ese anio:\n\n");
for ( i = 0; i < 24; i++)
{
    if (i < 11)
    {
         printf("El porcentaje del mes %i del anio 2021 es: %.1f%%\n", i+1 ,porcentaje_total_mes_sobre_anio[i]);
    }
    else if (i == 11)
    {
        printf("El porcentaje del mes %i del anio 2021 es: %.1f%%\n\n", i+1 ,porcentaje_total_mes_sobre_anio[i]);
    }

    else if (i > 11 && i <24)
   {
        printf("El porcentaje del mes %i del anio 2022 es: %.1f%%\n", i-11 ,porcentaje_total_mes_sobre_anio[i]);
   }

}


}
void sumatorio_tipos(Energia mes[], float* sum_energia2021, float* sum_energia2022)
{
    int i, j;
//sumatirio de cuanta energia se genera con cada tipo de generacion al año que nos sera util para mediasy porcentajes futuros

    for ( i = 0; i < 12; i++)
    {
        sum_energia2021[0] = sum_energia2021[0] + mes[i].Ha;

        sum_energia2021[1] = sum_energia2021[1] + mes[i].Tb;

        sum_energia2021[2] = sum_energia2021[2] + mes[i].N;

        sum_energia2021[3] = sum_energia2021[3] + mes[i].C;

        sum_energia2021[4] = sum_energia2021[4] + mes[i].Fg;



        sum_energia2021[10] = sum_energia2021[10] + mes[i].E;

        sum_energia2021[11] = sum_energia2021[11] + mes[i].Sf;

        sum_energia2021[12] = sum_energia2021[12] + mes[i].St;

        sum_energia2021[13] = sum_energia2021[13] + mes[i].O;

        sum_energia2021[14] = sum_energia2021[14] + mes[i].Cg;

        sum_energia2021[15] = sum_energia2021[15] + mes[i].Rn;

        sum_energia2021[16] = sum_energia2021[16] + mes[i].Rr;
    }
// estos sumatorioss se quedaban pillados de vez en cuando asi que los hice manual y ya funcionan siempre
   sum_energia2021[6] = mes[0].Tg + mes[1].Tg + mes[2].Tg + mes[3].Tg + mes[4].Tg + mes[5].Tg + mes[6].Tg + mes[7].Tg + mes[8].Tg + mes[9].Tg + mes[10].Tg + mes[11].Tg;

   sum_energia2021[8] = mes[0].Cc + mes[1].Cc + mes[2].Cc + mes[3].Cc + mes[4].Cc + mes[5].Cc + mes[6].Cc + mes[7].Cc + mes[8].Cc + mes[9].Cc + mes[10].Cc + mes[11].Cc;

   sum_energia2021[5] = mes[0].M + mes[1].M + mes[2].M + mes[3].M + mes[4].M + mes[5].M + mes[6].M + mes[7].M + mes[8].M + mes[9].M + mes[10].M + mes[11].M;

   sum_energia2021[7] = mes[0].Tv + mes[1].Tv + mes[2].Tv + mes[3].Tv + mes[4].Tv + mes[5].Tv + mes[6].Tv + mes[7].Tv + mes[8].Tv + mes[9].Tv + mes[10].Tv + mes[11].Tv;

   sum_energia2021[9] = mes[0].He + mes[1].He + mes[2].He + mes[3].He + mes[4].He + mes[5].He + mes[6].He + mes[7].He + mes[8].He + mes[9].He + mes[10].He + mes[11].He;


    for ( i = 12; i < 24; i++)
    {
        sum_energia2022[0] = sum_energia2022[0] + mes[i].Ha;

        sum_energia2022[1] = sum_energia2022[1] + mes[i].Tb;

        sum_energia2022[2] = sum_energia2022[2] + mes[i].N;

        sum_energia2022[3] = sum_energia2022[3] + mes[i].C;

        sum_energia2022[5] = sum_energia2022[5] + mes[i].M;

        sum_energia2022[6] = sum_energia2022[6] + mes[i].Tg;

        sum_energia2022[7] = sum_energia2022[7] + mes[i].Tv;



        sum_energia2022[9] = sum_energia2022[9] + mes[i].He;

        sum_energia2022[10] = sum_energia2022[10] + mes[i].E;

        sum_energia2022[11] = sum_energia2022[11] + mes[i].Sf;



       sum_energia2022[13] = sum_energia2022[13] + mes[i].O;

        sum_energia2022[14] = sum_energia2022[14] + mes[i].Cg;

        sum_energia2022[15] = sum_energia2022[15] + mes[i].Rn;

        sum_energia2022[16] = sum_energia2022[16] + mes[i].Rr;
    }
    sum_energia2022[4] = 0;

    sum_energia2022[8] = mes[12].Cc + mes[13].Cc + mes[14].Cc + mes[15].Cc + mes[16].Cc + mes[17].Cc + mes[18].Cc + mes[19].Cc + mes[20].Cc + mes[21].Cc + mes[22].Cc + mes[23].Cc;

    sum_energia2022[12] = mes[12].St + mes[13].St + mes[14].St + mes[15].St + mes[16].St + mes[17].St + mes[18].St + mes[19].St + mes[20].St + mes[21].St + mes[22].St + mes[23].St;

}
void porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[], float* res_sum2021, float* res_sum2022)
{
    //caunata energia genera cada tipo cada mes respecto de lo que genera ese tipo al año
    float porcentaje_tipoenergia_sobre_su_total_anio[17][24];
    int i, j;

    for (i = 0; i < 24; i++)
    {
//el mes de cada tipo entre el total del tipo al año *100
        if (i < 12)
        {

        porcentaje_tipoenergia_sobre_su_total_anio[0][i] = mes[i].Ha / res_sum2021[0] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[1][i] = mes[i].Tb / res_sum2021[1] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[2][i] = mes[i].N / res_sum2021[2] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[3][i] = mes[i].C / res_sum2021[3] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[4][i] = mes[i].Fg / res_sum2021[4] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[5][i] = mes[i].M / res_sum2021[5] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[6][i] = mes[i].Tg / res_sum2021[6] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[7][i] = mes[i].Tv / res_sum2021[7] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[8][i] = mes[i].Cc / res_sum2021[8] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[9][i] = mes[i].He / res_sum2021[9] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[10][i] = mes[i].E / res_sum2021[10] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[11][i] = mes[i].Sf / res_sum2021[11] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[12][i] = mes[i].St / res_sum2021[12] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[13][i] = mes[i].O / res_sum2021[13] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[14][i] = mes[i].Cg / res_sum2021[14] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[15][i] = mes[i].Rn / res_sum2021[15] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[16][i] = mes[i].Rr / res_sum2021[16] * 100;

        }

       else
      {

        porcentaje_tipoenergia_sobre_su_total_anio[0][i] = mes[i].Ha / res_sum2022[0] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[1][i] = mes[i].Tb / res_sum2022[1] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[2][i] = mes[i].N / res_sum2022[2] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[3][i] = mes[i].C / res_sum2022[3] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[4][i] = mes[i].Fg / res_sum2022[4] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[5][i] = mes[i].M / res_sum2022[5] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[6][i] = mes[i].Tg / res_sum2022[6] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[7][i] = mes[i].Tv / res_sum2022[7] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[8][i] = mes[i].Cc / res_sum2022[8] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[9][i] = mes[i].He / res_sum2022[9] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[10][i] = mes[i].E / res_sum2022[10] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[11][i] = mes[i].Sf / res_sum2022[11] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[12][i] = mes[i].St / res_sum2022[12] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[13][i] = mes[i].O / res_sum2022[13] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[14][i] = mes[i].Cg / res_sum2022[14] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[15][i] = mes[i].Rn / res_sum2022[15] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[16][i] = mes[i].Rr / res_sum2022[16] * 100;

    }

}

   printf("\nANIO 2021:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[0][0], porcentaje_tipoenergia_sobre_su_total_anio[0][1], porcentaje_tipoenergia_sobre_su_total_anio[0][2], porcentaje_tipoenergia_sobre_su_total_anio[0][3], porcentaje_tipoenergia_sobre_su_total_anio[0][4], porcentaje_tipoenergia_sobre_su_total_anio[0][5], porcentaje_tipoenergia_sobre_su_total_anio[0][6], porcentaje_tipoenergia_sobre_su_total_anio[0][7], porcentaje_tipoenergia_sobre_su_total_anio[0][8], porcentaje_tipoenergia_sobre_su_total_anio[0][9], porcentaje_tipoenergia_sobre_su_total_anio[0][10], porcentaje_tipoenergia_sobre_su_total_anio[0][11]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[1][0], porcentaje_tipoenergia_sobre_su_total_anio[1][1], porcentaje_tipoenergia_sobre_su_total_anio[1][2], porcentaje_tipoenergia_sobre_su_total_anio[1][3], porcentaje_tipoenergia_sobre_su_total_anio[1][4], porcentaje_tipoenergia_sobre_su_total_anio[1][5], porcentaje_tipoenergia_sobre_su_total_anio[1][6], porcentaje_tipoenergia_sobre_su_total_anio[1][7], porcentaje_tipoenergia_sobre_su_total_anio[1][8], porcentaje_tipoenergia_sobre_su_total_anio[1][9], porcentaje_tipoenergia_sobre_su_total_anio[1][10], porcentaje_tipoenergia_sobre_su_total_anio[1][11]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%    %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[2][0], porcentaje_tipoenergia_sobre_su_total_anio[2][1], porcentaje_tipoenergia_sobre_su_total_anio[2][2], porcentaje_tipoenergia_sobre_su_total_anio[2][3], porcentaje_tipoenergia_sobre_su_total_anio[2][4], porcentaje_tipoenergia_sobre_su_total_anio[2][5], porcentaje_tipoenergia_sobre_su_total_anio[2][6], porcentaje_tipoenergia_sobre_su_total_anio[2][7], porcentaje_tipoenergia_sobre_su_total_anio[2][8], porcentaje_tipoenergia_sobre_su_total_anio[2][9], porcentaje_tipoenergia_sobre_su_total_anio[2][10], porcentaje_tipoenergia_sobre_su_total_anio[2][11]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   porcentaje_tipoenergia_sobre_su_total_anio[3][0], porcentaje_tipoenergia_sobre_su_total_anio[3][1], porcentaje_tipoenergia_sobre_su_total_anio[3][2], porcentaje_tipoenergia_sobre_su_total_anio[3][3], porcentaje_tipoenergia_sobre_su_total_anio[3][4], porcentaje_tipoenergia_sobre_su_total_anio[3][5], porcentaje_tipoenergia_sobre_su_total_anio[3][6], porcentaje_tipoenergia_sobre_su_total_anio[3][7], porcentaje_tipoenergia_sobre_su_total_anio[3][8], porcentaje_tipoenergia_sobre_su_total_anio[3][9], porcentaje_tipoenergia_sobre_su_total_anio[3][10], porcentaje_tipoenergia_sobre_su_total_anio[3][11]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[4][0], porcentaje_tipoenergia_sobre_su_total_anio[4][1], porcentaje_tipoenergia_sobre_su_total_anio[4][2], porcentaje_tipoenergia_sobre_su_total_anio[4][3], porcentaje_tipoenergia_sobre_su_total_anio[4][4], porcentaje_tipoenergia_sobre_su_total_anio[4][5], porcentaje_tipoenergia_sobre_su_total_anio[4][6], porcentaje_tipoenergia_sobre_su_total_anio[4][7], porcentaje_tipoenergia_sobre_su_total_anio[4][8], porcentaje_tipoenergia_sobre_su_total_anio[4][9], porcentaje_tipoenergia_sobre_su_total_anio[4][10], porcentaje_tipoenergia_sobre_su_total_anio[4][11]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[5][0], porcentaje_tipoenergia_sobre_su_total_anio[5][1], porcentaje_tipoenergia_sobre_su_total_anio[5][2], porcentaje_tipoenergia_sobre_su_total_anio[5][3], porcentaje_tipoenergia_sobre_su_total_anio[5][4], porcentaje_tipoenergia_sobre_su_total_anio[5][5], porcentaje_tipoenergia_sobre_su_total_anio[5][6], porcentaje_tipoenergia_sobre_su_total_anio[5][7], porcentaje_tipoenergia_sobre_su_total_anio[5][8], porcentaje_tipoenergia_sobre_su_total_anio[5][9], porcentaje_tipoenergia_sobre_su_total_anio[5][10], porcentaje_tipoenergia_sobre_su_total_anio[5][11]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[6][0], porcentaje_tipoenergia_sobre_su_total_anio[6][1], porcentaje_tipoenergia_sobre_su_total_anio[6][2], porcentaje_tipoenergia_sobre_su_total_anio[6][3], porcentaje_tipoenergia_sobre_su_total_anio[6][4], porcentaje_tipoenergia_sobre_su_total_anio[6][5], porcentaje_tipoenergia_sobre_su_total_anio[6][6], porcentaje_tipoenergia_sobre_su_total_anio[6][7], porcentaje_tipoenergia_sobre_su_total_anio[6][8], porcentaje_tipoenergia_sobre_su_total_anio[6][9], porcentaje_tipoenergia_sobre_su_total_anio[6][10], porcentaje_tipoenergia_sobre_su_total_anio[6][11]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[7][0], porcentaje_tipoenergia_sobre_su_total_anio[7][1], porcentaje_tipoenergia_sobre_su_total_anio[7][2], porcentaje_tipoenergia_sobre_su_total_anio[7][3], porcentaje_tipoenergia_sobre_su_total_anio[7][4], porcentaje_tipoenergia_sobre_su_total_anio[7][5], porcentaje_tipoenergia_sobre_su_total_anio[7][6], porcentaje_tipoenergia_sobre_su_total_anio[7][7], porcentaje_tipoenergia_sobre_su_total_anio[7][8], porcentaje_tipoenergia_sobre_su_total_anio[7][9], porcentaje_tipoenergia_sobre_su_total_anio[7][10], porcentaje_tipoenergia_sobre_su_total_anio[7][11]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[8][0], porcentaje_tipoenergia_sobre_su_total_anio[8][1], porcentaje_tipoenergia_sobre_su_total_anio[8][2], porcentaje_tipoenergia_sobre_su_total_anio[8][3], porcentaje_tipoenergia_sobre_su_total_anio[8][4], porcentaje_tipoenergia_sobre_su_total_anio[8][5], porcentaje_tipoenergia_sobre_su_total_anio[8][6], porcentaje_tipoenergia_sobre_su_total_anio[8][7], porcentaje_tipoenergia_sobre_su_total_anio[8][8], porcentaje_tipoenergia_sobre_su_total_anio[8][9], porcentaje_tipoenergia_sobre_su_total_anio[8][10], porcentaje_tipoenergia_sobre_su_total_anio[8][11]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[9][0], porcentaje_tipoenergia_sobre_su_total_anio[9][1], porcentaje_tipoenergia_sobre_su_total_anio[9][2], porcentaje_tipoenergia_sobre_su_total_anio[9][3], porcentaje_tipoenergia_sobre_su_total_anio[9][4], porcentaje_tipoenergia_sobre_su_total_anio[9][5], porcentaje_tipoenergia_sobre_su_total_anio[9][6], porcentaje_tipoenergia_sobre_su_total_anio[9][7], porcentaje_tipoenergia_sobre_su_total_anio[9][8], porcentaje_tipoenergia_sobre_su_total_anio[9][9], porcentaje_tipoenergia_sobre_su_total_anio[9][10], porcentaje_tipoenergia_sobre_su_total_anio[9][11]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[10][0], porcentaje_tipoenergia_sobre_su_total_anio[10][1], porcentaje_tipoenergia_sobre_su_total_anio[10][2], porcentaje_tipoenergia_sobre_su_total_anio[10][3], porcentaje_tipoenergia_sobre_su_total_anio[10][4], porcentaje_tipoenergia_sobre_su_total_anio[10][5], porcentaje_tipoenergia_sobre_su_total_anio[10][6], porcentaje_tipoenergia_sobre_su_total_anio[10][7], porcentaje_tipoenergia_sobre_su_total_anio[10][8], porcentaje_tipoenergia_sobre_su_total_anio[10][9], porcentaje_tipoenergia_sobre_su_total_anio[10][10], porcentaje_tipoenergia_sobre_su_total_anio[10][11]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[11][0], porcentaje_tipoenergia_sobre_su_total_anio[11][1], porcentaje_tipoenergia_sobre_su_total_anio[11][2], porcentaje_tipoenergia_sobre_su_total_anio[11][3], porcentaje_tipoenergia_sobre_su_total_anio[11][4], porcentaje_tipoenergia_sobre_su_total_anio[11][5], porcentaje_tipoenergia_sobre_su_total_anio[11][6], porcentaje_tipoenergia_sobre_su_total_anio[11][7], porcentaje_tipoenergia_sobre_su_total_anio[11][8], porcentaje_tipoenergia_sobre_su_total_anio[11][9], porcentaje_tipoenergia_sobre_su_total_anio[11][10], porcentaje_tipoenergia_sobre_su_total_anio[11][11]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[12][0], porcentaje_tipoenergia_sobre_su_total_anio[12][1], porcentaje_tipoenergia_sobre_su_total_anio[12][2], porcentaje_tipoenergia_sobre_su_total_anio[12][3], porcentaje_tipoenergia_sobre_su_total_anio[12][4], porcentaje_tipoenergia_sobre_su_total_anio[12][5], porcentaje_tipoenergia_sobre_su_total_anio[12][6], porcentaje_tipoenergia_sobre_su_total_anio[12][7], porcentaje_tipoenergia_sobre_su_total_anio[12][8], porcentaje_tipoenergia_sobre_su_total_anio[12][9], porcentaje_tipoenergia_sobre_su_total_anio[12][10], porcentaje_tipoenergia_sobre_su_total_anio[12][11]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[13][0], porcentaje_tipoenergia_sobre_su_total_anio[13][1], porcentaje_tipoenergia_sobre_su_total_anio[13][2], porcentaje_tipoenergia_sobre_su_total_anio[13][3], porcentaje_tipoenergia_sobre_su_total_anio[13][4], porcentaje_tipoenergia_sobre_su_total_anio[13][5], porcentaje_tipoenergia_sobre_su_total_anio[13][6], porcentaje_tipoenergia_sobre_su_total_anio[13][7], porcentaje_tipoenergia_sobre_su_total_anio[13][8], porcentaje_tipoenergia_sobre_su_total_anio[13][9], porcentaje_tipoenergia_sobre_su_total_anio[13][10], porcentaje_tipoenergia_sobre_su_total_anio[13][11]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[14][0], porcentaje_tipoenergia_sobre_su_total_anio[14][1], porcentaje_tipoenergia_sobre_su_total_anio[14][2], porcentaje_tipoenergia_sobre_su_total_anio[14][3], porcentaje_tipoenergia_sobre_su_total_anio[14][4], porcentaje_tipoenergia_sobre_su_total_anio[14][5], porcentaje_tipoenergia_sobre_su_total_anio[14][6], porcentaje_tipoenergia_sobre_su_total_anio[14][7], porcentaje_tipoenergia_sobre_su_total_anio[14][8], porcentaje_tipoenergia_sobre_su_total_anio[14][9], porcentaje_tipoenergia_sobre_su_total_anio[14][10], porcentaje_tipoenergia_sobre_su_total_anio[14][11]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[15][0], porcentaje_tipoenergia_sobre_su_total_anio[15][1], porcentaje_tipoenergia_sobre_su_total_anio[15][2], porcentaje_tipoenergia_sobre_su_total_anio[15][3], porcentaje_tipoenergia_sobre_su_total_anio[15][4], porcentaje_tipoenergia_sobre_su_total_anio[15][5], porcentaje_tipoenergia_sobre_su_total_anio[15][6], porcentaje_tipoenergia_sobre_su_total_anio[15][7], porcentaje_tipoenergia_sobre_su_total_anio[15][8], porcentaje_tipoenergia_sobre_su_total_anio[15][9], porcentaje_tipoenergia_sobre_su_total_anio[15][10], porcentaje_tipoenergia_sobre_su_total_anio[15][11]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[16][0], porcentaje_tipoenergia_sobre_su_total_anio[16][1], porcentaje_tipoenergia_sobre_su_total_anio[16][2], porcentaje_tipoenergia_sobre_su_total_anio[16][3], porcentaje_tipoenergia_sobre_su_total_anio[16][4], porcentaje_tipoenergia_sobre_su_total_anio[16][5], porcentaje_tipoenergia_sobre_su_total_anio[16][6], porcentaje_tipoenergia_sobre_su_total_anio[16][7], porcentaje_tipoenergia_sobre_su_total_anio[16][8], porcentaje_tipoenergia_sobre_su_total_anio[16][9], porcentaje_tipoenergia_sobre_su_total_anio[16][10], porcentaje_tipoenergia_sobre_su_total_anio[16][11]);
    //printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[0].Total, mes[1].Total, mes[2].Total, mes[3].Total, mes[4].Total, mes[5].Total, mes[6].Total, mes[7].Total, mes[8].Total, mes[9].Total, mes[10].Total, mes[11].Total);


printf("\n\n\nANIO 2022:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[0][12], porcentaje_tipoenergia_sobre_su_total_anio[0][13], porcentaje_tipoenergia_sobre_su_total_anio[0][14], porcentaje_tipoenergia_sobre_su_total_anio[0][15], porcentaje_tipoenergia_sobre_su_total_anio[0][16], porcentaje_tipoenergia_sobre_su_total_anio[0][17], porcentaje_tipoenergia_sobre_su_total_anio[0][18], porcentaje_tipoenergia_sobre_su_total_anio[0][19], porcentaje_tipoenergia_sobre_su_total_anio[0][20], porcentaje_tipoenergia_sobre_su_total_anio[0][21], porcentaje_tipoenergia_sobre_su_total_anio[0][22], porcentaje_tipoenergia_sobre_su_total_anio[0][23]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[1][12], porcentaje_tipoenergia_sobre_su_total_anio[1][13], porcentaje_tipoenergia_sobre_su_total_anio[1][14], porcentaje_tipoenergia_sobre_su_total_anio[1][15], porcentaje_tipoenergia_sobre_su_total_anio[1][16], porcentaje_tipoenergia_sobre_su_total_anio[1][17], porcentaje_tipoenergia_sobre_su_total_anio[1][18], porcentaje_tipoenergia_sobre_su_total_anio[1][19], porcentaje_tipoenergia_sobre_su_total_anio[1][20], porcentaje_tipoenergia_sobre_su_total_anio[1][21], porcentaje_tipoenergia_sobre_su_total_anio[1][22], porcentaje_tipoenergia_sobre_su_total_anio[1][23]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[2][12], porcentaje_tipoenergia_sobre_su_total_anio[2][13], porcentaje_tipoenergia_sobre_su_total_anio[2][14], porcentaje_tipoenergia_sobre_su_total_anio[2][15], porcentaje_tipoenergia_sobre_su_total_anio[2][16], porcentaje_tipoenergia_sobre_su_total_anio[2][17], porcentaje_tipoenergia_sobre_su_total_anio[2][18], porcentaje_tipoenergia_sobre_su_total_anio[2][19], porcentaje_tipoenergia_sobre_su_total_anio[2][20], porcentaje_tipoenergia_sobre_su_total_anio[2][21], porcentaje_tipoenergia_sobre_su_total_anio[2][22], porcentaje_tipoenergia_sobre_su_total_anio[2][23]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   porcentaje_tipoenergia_sobre_su_total_anio[3][12], porcentaje_tipoenergia_sobre_su_total_anio[3][13], porcentaje_tipoenergia_sobre_su_total_anio[3][14], porcentaje_tipoenergia_sobre_su_total_anio[3][15], porcentaje_tipoenergia_sobre_su_total_anio[3][16], porcentaje_tipoenergia_sobre_su_total_anio[3][17], porcentaje_tipoenergia_sobre_su_total_anio[3][18], porcentaje_tipoenergia_sobre_su_total_anio[3][19], porcentaje_tipoenergia_sobre_su_total_anio[3][20], porcentaje_tipoenergia_sobre_su_total_anio[3][21], porcentaje_tipoenergia_sobre_su_total_anio[3][22], porcentaje_tipoenergia_sobre_su_total_anio[3][23]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[4][12], porcentaje_tipoenergia_sobre_su_total_anio[4][13], porcentaje_tipoenergia_sobre_su_total_anio[4][14], porcentaje_tipoenergia_sobre_su_total_anio[4][15], porcentaje_tipoenergia_sobre_su_total_anio[4][16], porcentaje_tipoenergia_sobre_su_total_anio[4][17], porcentaje_tipoenergia_sobre_su_total_anio[4][18], porcentaje_tipoenergia_sobre_su_total_anio[4][19], porcentaje_tipoenergia_sobre_su_total_anio[4][20], porcentaje_tipoenergia_sobre_su_total_anio[4][21], porcentaje_tipoenergia_sobre_su_total_anio[4][22], porcentaje_tipoenergia_sobre_su_total_anio[4][23]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[5][12], porcentaje_tipoenergia_sobre_su_total_anio[5][13], porcentaje_tipoenergia_sobre_su_total_anio[5][14], porcentaje_tipoenergia_sobre_su_total_anio[5][15], porcentaje_tipoenergia_sobre_su_total_anio[5][16], porcentaje_tipoenergia_sobre_su_total_anio[5][17], porcentaje_tipoenergia_sobre_su_total_anio[5][18], porcentaje_tipoenergia_sobre_su_total_anio[5][19], porcentaje_tipoenergia_sobre_su_total_anio[5][20], porcentaje_tipoenergia_sobre_su_total_anio[5][21], porcentaje_tipoenergia_sobre_su_total_anio[5][22], porcentaje_tipoenergia_sobre_su_total_anio[5][23]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[6][12], porcentaje_tipoenergia_sobre_su_total_anio[6][13], porcentaje_tipoenergia_sobre_su_total_anio[6][14], porcentaje_tipoenergia_sobre_su_total_anio[6][15], porcentaje_tipoenergia_sobre_su_total_anio[6][16], porcentaje_tipoenergia_sobre_su_total_anio[6][17], porcentaje_tipoenergia_sobre_su_total_anio[6][18], porcentaje_tipoenergia_sobre_su_total_anio[6][19], porcentaje_tipoenergia_sobre_su_total_anio[6][20], porcentaje_tipoenergia_sobre_su_total_anio[6][21], porcentaje_tipoenergia_sobre_su_total_anio[6][22], porcentaje_tipoenergia_sobre_su_total_anio[6][23]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[7][12], porcentaje_tipoenergia_sobre_su_total_anio[7][13], porcentaje_tipoenergia_sobre_su_total_anio[7][14], porcentaje_tipoenergia_sobre_su_total_anio[7][15], porcentaje_tipoenergia_sobre_su_total_anio[7][16], porcentaje_tipoenergia_sobre_su_total_anio[7][17], porcentaje_tipoenergia_sobre_su_total_anio[7][18], porcentaje_tipoenergia_sobre_su_total_anio[7][19], porcentaje_tipoenergia_sobre_su_total_anio[7][20], porcentaje_tipoenergia_sobre_su_total_anio[7][21], porcentaje_tipoenergia_sobre_su_total_anio[7][22], porcentaje_tipoenergia_sobre_su_total_anio[7][23]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[8][12], porcentaje_tipoenergia_sobre_su_total_anio[8][13], porcentaje_tipoenergia_sobre_su_total_anio[8][14], porcentaje_tipoenergia_sobre_su_total_anio[8][15], porcentaje_tipoenergia_sobre_su_total_anio[8][16], porcentaje_tipoenergia_sobre_su_total_anio[8][17], porcentaje_tipoenergia_sobre_su_total_anio[8][18], porcentaje_tipoenergia_sobre_su_total_anio[8][19], porcentaje_tipoenergia_sobre_su_total_anio[8][20], porcentaje_tipoenergia_sobre_su_total_anio[8][21], porcentaje_tipoenergia_sobre_su_total_anio[8][22], porcentaje_tipoenergia_sobre_su_total_anio[8][23]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[9][12], porcentaje_tipoenergia_sobre_su_total_anio[9][13], porcentaje_tipoenergia_sobre_su_total_anio[9][14], porcentaje_tipoenergia_sobre_su_total_anio[9][15], porcentaje_tipoenergia_sobre_su_total_anio[9][16], porcentaje_tipoenergia_sobre_su_total_anio[9][17], porcentaje_tipoenergia_sobre_su_total_anio[9][18], porcentaje_tipoenergia_sobre_su_total_anio[9][19], porcentaje_tipoenergia_sobre_su_total_anio[9][20], porcentaje_tipoenergia_sobre_su_total_anio[9][21], porcentaje_tipoenergia_sobre_su_total_anio[9][22], porcentaje_tipoenergia_sobre_su_total_anio[9][23]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[10][12], porcentaje_tipoenergia_sobre_su_total_anio[10][13], porcentaje_tipoenergia_sobre_su_total_anio[10][14], porcentaje_tipoenergia_sobre_su_total_anio[10][15], porcentaje_tipoenergia_sobre_su_total_anio[10][16], porcentaje_tipoenergia_sobre_su_total_anio[10][17], porcentaje_tipoenergia_sobre_su_total_anio[10][18], porcentaje_tipoenergia_sobre_su_total_anio[10][19], porcentaje_tipoenergia_sobre_su_total_anio[10][20], porcentaje_tipoenergia_sobre_su_total_anio[10][21], porcentaje_tipoenergia_sobre_su_total_anio[10][22], porcentaje_tipoenergia_sobre_su_total_anio[10][23]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[11][12], porcentaje_tipoenergia_sobre_su_total_anio[11][13], porcentaje_tipoenergia_sobre_su_total_anio[11][14], porcentaje_tipoenergia_sobre_su_total_anio[11][15], porcentaje_tipoenergia_sobre_su_total_anio[11][16], porcentaje_tipoenergia_sobre_su_total_anio[11][17], porcentaje_tipoenergia_sobre_su_total_anio[11][18], porcentaje_tipoenergia_sobre_su_total_anio[11][19], porcentaje_tipoenergia_sobre_su_total_anio[11][20], porcentaje_tipoenergia_sobre_su_total_anio[11][21], porcentaje_tipoenergia_sobre_su_total_anio[11][22], porcentaje_tipoenergia_sobre_su_total_anio[11][23]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[12][12], porcentaje_tipoenergia_sobre_su_total_anio[12][13], porcentaje_tipoenergia_sobre_su_total_anio[12][14], porcentaje_tipoenergia_sobre_su_total_anio[12][15], porcentaje_tipoenergia_sobre_su_total_anio[12][16], porcentaje_tipoenergia_sobre_su_total_anio[12][17], porcentaje_tipoenergia_sobre_su_total_anio[12][18], porcentaje_tipoenergia_sobre_su_total_anio[12][19], porcentaje_tipoenergia_sobre_su_total_anio[12][20], porcentaje_tipoenergia_sobre_su_total_anio[12][21], porcentaje_tipoenergia_sobre_su_total_anio[12][22], porcentaje_tipoenergia_sobre_su_total_anio[12][23]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[13][12], porcentaje_tipoenergia_sobre_su_total_anio[13][13], porcentaje_tipoenergia_sobre_su_total_anio[13][14], porcentaje_tipoenergia_sobre_su_total_anio[13][15], porcentaje_tipoenergia_sobre_su_total_anio[13][16], porcentaje_tipoenergia_sobre_su_total_anio[13][17], porcentaje_tipoenergia_sobre_su_total_anio[13][18], porcentaje_tipoenergia_sobre_su_total_anio[13][19], porcentaje_tipoenergia_sobre_su_total_anio[13][20], porcentaje_tipoenergia_sobre_su_total_anio[13][21], porcentaje_tipoenergia_sobre_su_total_anio[13][22], porcentaje_tipoenergia_sobre_su_total_anio[13][23]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_su_total_anio[14][12], porcentaje_tipoenergia_sobre_su_total_anio[14][13], porcentaje_tipoenergia_sobre_su_total_anio[14][14], porcentaje_tipoenergia_sobre_su_total_anio[14][15], porcentaje_tipoenergia_sobre_su_total_anio[14][16], porcentaje_tipoenergia_sobre_su_total_anio[14][17], porcentaje_tipoenergia_sobre_su_total_anio[14][18], porcentaje_tipoenergia_sobre_su_total_anio[14][19], porcentaje_tipoenergia_sobre_su_total_anio[14][20], porcentaje_tipoenergia_sobre_su_total_anio[14][21], porcentaje_tipoenergia_sobre_su_total_anio[14][22], porcentaje_tipoenergia_sobre_su_total_anio[14][23]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[15][12], porcentaje_tipoenergia_sobre_su_total_anio[15][13], porcentaje_tipoenergia_sobre_su_total_anio[15][14], porcentaje_tipoenergia_sobre_su_total_anio[15][15], porcentaje_tipoenergia_sobre_su_total_anio[15][16], porcentaje_tipoenergia_sobre_su_total_anio[15][17], porcentaje_tipoenergia_sobre_su_total_anio[15][18], porcentaje_tipoenergia_sobre_su_total_anio[15][19], porcentaje_tipoenergia_sobre_su_total_anio[15][20], porcentaje_tipoenergia_sobre_su_total_anio[15][21], porcentaje_tipoenergia_sobre_su_total_anio[15][22], porcentaje_tipoenergia_sobre_su_total_anio[15][23]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_su_total_anio[16][12], porcentaje_tipoenergia_sobre_su_total_anio[16][13], porcentaje_tipoenergia_sobre_su_total_anio[16][14], porcentaje_tipoenergia_sobre_su_total_anio[16][15], porcentaje_tipoenergia_sobre_su_total_anio[16][16], porcentaje_tipoenergia_sobre_su_total_anio[16][17], porcentaje_tipoenergia_sobre_su_total_anio[16][18], porcentaje_tipoenergia_sobre_su_total_anio[16][19], porcentaje_tipoenergia_sobre_su_total_anio[16][20], porcentaje_tipoenergia_sobre_su_total_anio[16][21], porcentaje_tipoenergia_sobre_su_total_anio[16][22], porcentaje_tipoenergia_sobre_su_total_anio[16][23]);
    //printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[12].Total, mes[13].Total, mes[14].Total, mes[15].Total, mes[16].Total, mes[17].Total, mes[18].Total, mes[19].Total, mes[20].Total, mes[21].Total, mes[22].Total,  mes[23].Total);
}
void porcentaje_tipoenergia_sobre_mes(Energia mes[])
{
    //cuanto genera cada tipo de eenrgia respecto del total generado ese mes
   float porcentaje_tipoenergia_sobre_mes[17][24];
   int i, j;

    for (i = 0; i < 24; i++)
    {
//lo generado ese mes por un tipo de generacion / total generado ese mes*100
        porcentaje_tipoenergia_sobre_mes[0][i] = mes[i].Ha / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[1][i] = mes[i].Tb / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[2][i] = mes[i].N / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[3][i] = mes[i].C / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[4][i] = mes[i].Fg / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[5][i] = mes[i].M / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[6][i] = mes[i].Tg / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[7][i] = mes[i].Tv / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[8][i] = mes[i].Cc / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[9][i] = mes[i].He / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[10][i] = mes[i].E / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[11][i] = mes[i].Sf / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[12][i] = mes[i].St / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[13][i] = mes[i].O / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[14][i] = mes[i].Cg / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[15][i] = mes[i].Rn / mes[i].Total * 100;

        porcentaje_tipoenergia_sobre_mes[16][i] = mes[i].Rr / mes[i].Total * 100;


    }

printf("\nANIO 2021:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[0][0], porcentaje_tipoenergia_sobre_mes[0][1], porcentaje_tipoenergia_sobre_mes[0][2], porcentaje_tipoenergia_sobre_mes[0][3], porcentaje_tipoenergia_sobre_mes[0][4], porcentaje_tipoenergia_sobre_mes[0][5], porcentaje_tipoenergia_sobre_mes[0][6], porcentaje_tipoenergia_sobre_mes[0][7], porcentaje_tipoenergia_sobre_mes[0][8], porcentaje_tipoenergia_sobre_mes[0][9], porcentaje_tipoenergia_sobre_mes[0][10], porcentaje_tipoenergia_sobre_mes[0][11]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[1][0], porcentaje_tipoenergia_sobre_mes[1][1], porcentaje_tipoenergia_sobre_mes[1][2], porcentaje_tipoenergia_sobre_mes[1][3], porcentaje_tipoenergia_sobre_mes[1][4], porcentaje_tipoenergia_sobre_mes[1][5], porcentaje_tipoenergia_sobre_mes[1][6], porcentaje_tipoenergia_sobre_mes[1][7], porcentaje_tipoenergia_sobre_mes[1][8], porcentaje_tipoenergia_sobre_mes[1][9], porcentaje_tipoenergia_sobre_mes[1][10], porcentaje_tipoenergia_sobre_mes[1][11]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[2][0], porcentaje_tipoenergia_sobre_mes[2][1], porcentaje_tipoenergia_sobre_mes[2][2], porcentaje_tipoenergia_sobre_mes[2][3], porcentaje_tipoenergia_sobre_mes[2][4], porcentaje_tipoenergia_sobre_mes[2][5], porcentaje_tipoenergia_sobre_mes[2][6], porcentaje_tipoenergia_sobre_mes[2][7], porcentaje_tipoenergia_sobre_mes[2][8], porcentaje_tipoenergia_sobre_mes[2][9], porcentaje_tipoenergia_sobre_mes[2][10], porcentaje_tipoenergia_sobre_mes[2][11]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   porcentaje_tipoenergia_sobre_mes[3][0], porcentaje_tipoenergia_sobre_mes[3][1], porcentaje_tipoenergia_sobre_mes[3][2], porcentaje_tipoenergia_sobre_mes[3][3], porcentaje_tipoenergia_sobre_mes[3][4], porcentaje_tipoenergia_sobre_mes[3][5], porcentaje_tipoenergia_sobre_mes[3][6], porcentaje_tipoenergia_sobre_mes[3][7], porcentaje_tipoenergia_sobre_mes[3][8], porcentaje_tipoenergia_sobre_mes[3][9], porcentaje_tipoenergia_sobre_mes[3][10], porcentaje_tipoenergia_sobre_mes[3][11]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[4][0], porcentaje_tipoenergia_sobre_mes[4][1], porcentaje_tipoenergia_sobre_mes[4][2], porcentaje_tipoenergia_sobre_mes[4][3], porcentaje_tipoenergia_sobre_mes[4][4], porcentaje_tipoenergia_sobre_mes[4][5], porcentaje_tipoenergia_sobre_mes[4][6], porcentaje_tipoenergia_sobre_mes[4][7], porcentaje_tipoenergia_sobre_mes[4][8], porcentaje_tipoenergia_sobre_mes[4][9], porcentaje_tipoenergia_sobre_mes[4][10], porcentaje_tipoenergia_sobre_mes[4][11]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[5][0], porcentaje_tipoenergia_sobre_mes[5][1], porcentaje_tipoenergia_sobre_mes[5][2], porcentaje_tipoenergia_sobre_mes[5][3], porcentaje_tipoenergia_sobre_mes[5][4], porcentaje_tipoenergia_sobre_mes[5][5], porcentaje_tipoenergia_sobre_mes[5][6], porcentaje_tipoenergia_sobre_mes[5][7], porcentaje_tipoenergia_sobre_mes[5][8], porcentaje_tipoenergia_sobre_mes[5][9], porcentaje_tipoenergia_sobre_mes[5][10], porcentaje_tipoenergia_sobre_mes[5][11]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[6][0], porcentaje_tipoenergia_sobre_mes[6][1], porcentaje_tipoenergia_sobre_mes[6][2], porcentaje_tipoenergia_sobre_mes[6][3], porcentaje_tipoenergia_sobre_mes[6][4], porcentaje_tipoenergia_sobre_mes[6][5], porcentaje_tipoenergia_sobre_mes[6][6], porcentaje_tipoenergia_sobre_mes[6][7], porcentaje_tipoenergia_sobre_mes[6][8], porcentaje_tipoenergia_sobre_mes[6][9], porcentaje_tipoenergia_sobre_mes[6][10], porcentaje_tipoenergia_sobre_mes[6][11]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[7][0], porcentaje_tipoenergia_sobre_mes[7][1], porcentaje_tipoenergia_sobre_mes[7][2], porcentaje_tipoenergia_sobre_mes[7][3], porcentaje_tipoenergia_sobre_mes[7][4], porcentaje_tipoenergia_sobre_mes[7][5], porcentaje_tipoenergia_sobre_mes[7][6], porcentaje_tipoenergia_sobre_mes[7][7], porcentaje_tipoenergia_sobre_mes[7][8], porcentaje_tipoenergia_sobre_mes[7][9], porcentaje_tipoenergia_sobre_mes[7][10], porcentaje_tipoenergia_sobre_mes[7][11]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[8][0], porcentaje_tipoenergia_sobre_mes[8][1], porcentaje_tipoenergia_sobre_mes[8][2], porcentaje_tipoenergia_sobre_mes[8][3], porcentaje_tipoenergia_sobre_mes[8][4], porcentaje_tipoenergia_sobre_mes[8][5], porcentaje_tipoenergia_sobre_mes[8][6], porcentaje_tipoenergia_sobre_mes[8][7], porcentaje_tipoenergia_sobre_mes[8][8], porcentaje_tipoenergia_sobre_mes[8][9], porcentaje_tipoenergia_sobre_mes[8][10], porcentaje_tipoenergia_sobre_mes[8][11]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[9][0], porcentaje_tipoenergia_sobre_mes[9][1], porcentaje_tipoenergia_sobre_mes[9][2], porcentaje_tipoenergia_sobre_mes[9][3], porcentaje_tipoenergia_sobre_mes[9][4], porcentaje_tipoenergia_sobre_mes[9][5], porcentaje_tipoenergia_sobre_mes[9][6], porcentaje_tipoenergia_sobre_mes[9][7], porcentaje_tipoenergia_sobre_mes[9][8], porcentaje_tipoenergia_sobre_mes[9][9], porcentaje_tipoenergia_sobre_mes[9][10], porcentaje_tipoenergia_sobre_mes[9][11]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[10][0], porcentaje_tipoenergia_sobre_mes[10][1], porcentaje_tipoenergia_sobre_mes[10][2], porcentaje_tipoenergia_sobre_mes[10][3], porcentaje_tipoenergia_sobre_mes[10][4], porcentaje_tipoenergia_sobre_mes[10][5], porcentaje_tipoenergia_sobre_mes[10][6], porcentaje_tipoenergia_sobre_mes[10][7], porcentaje_tipoenergia_sobre_mes[10][8], porcentaje_tipoenergia_sobre_mes[10][9], porcentaje_tipoenergia_sobre_mes[10][10], porcentaje_tipoenergia_sobre_mes[10][11]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[11][0], porcentaje_tipoenergia_sobre_mes[11][1], porcentaje_tipoenergia_sobre_mes[11][2], porcentaje_tipoenergia_sobre_mes[11][3], porcentaje_tipoenergia_sobre_mes[11][4], porcentaje_tipoenergia_sobre_mes[11][5], porcentaje_tipoenergia_sobre_mes[11][6], porcentaje_tipoenergia_sobre_mes[11][7], porcentaje_tipoenergia_sobre_mes[11][8], porcentaje_tipoenergia_sobre_mes[11][9], porcentaje_tipoenergia_sobre_mes[11][10], porcentaje_tipoenergia_sobre_mes[11][11]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[12][0], porcentaje_tipoenergia_sobre_mes[12][1], porcentaje_tipoenergia_sobre_mes[12][2], porcentaje_tipoenergia_sobre_mes[12][3], porcentaje_tipoenergia_sobre_mes[12][4], porcentaje_tipoenergia_sobre_mes[12][5], porcentaje_tipoenergia_sobre_mes[12][6], porcentaje_tipoenergia_sobre_mes[12][7], porcentaje_tipoenergia_sobre_mes[12][8], porcentaje_tipoenergia_sobre_mes[12][9], porcentaje_tipoenergia_sobre_mes[12][10], porcentaje_tipoenergia_sobre_mes[12][11]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[13][0], porcentaje_tipoenergia_sobre_mes[13][1], porcentaje_tipoenergia_sobre_mes[13][2], porcentaje_tipoenergia_sobre_mes[13][3], porcentaje_tipoenergia_sobre_mes[13][4], porcentaje_tipoenergia_sobre_mes[13][5], porcentaje_tipoenergia_sobre_mes[13][6], porcentaje_tipoenergia_sobre_mes[13][7], porcentaje_tipoenergia_sobre_mes[13][8], porcentaje_tipoenergia_sobre_mes[13][9], porcentaje_tipoenergia_sobre_mes[13][10], porcentaje_tipoenergia_sobre_mes[13][11]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[14][0], porcentaje_tipoenergia_sobre_mes[14][1], porcentaje_tipoenergia_sobre_mes[14][2], porcentaje_tipoenergia_sobre_mes[14][3], porcentaje_tipoenergia_sobre_mes[14][4], porcentaje_tipoenergia_sobre_mes[14][5], porcentaje_tipoenergia_sobre_mes[14][6], porcentaje_tipoenergia_sobre_mes[14][7], porcentaje_tipoenergia_sobre_mes[14][8], porcentaje_tipoenergia_sobre_mes[14][9], porcentaje_tipoenergia_sobre_mes[14][10], porcentaje_tipoenergia_sobre_mes[14][11]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[15][0], porcentaje_tipoenergia_sobre_mes[15][1], porcentaje_tipoenergia_sobre_mes[15][2], porcentaje_tipoenergia_sobre_mes[15][3], porcentaje_tipoenergia_sobre_mes[15][4], porcentaje_tipoenergia_sobre_mes[15][5], porcentaje_tipoenergia_sobre_mes[15][6], porcentaje_tipoenergia_sobre_mes[15][7], porcentaje_tipoenergia_sobre_mes[15][8], porcentaje_tipoenergia_sobre_mes[15][9], porcentaje_tipoenergia_sobre_mes[15][10], porcentaje_tipoenergia_sobre_mes[15][11]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[16][0], porcentaje_tipoenergia_sobre_mes[16][1], porcentaje_tipoenergia_sobre_mes[16][2], porcentaje_tipoenergia_sobre_mes[16][3], porcentaje_tipoenergia_sobre_mes[16][4], porcentaje_tipoenergia_sobre_mes[16][5], porcentaje_tipoenergia_sobre_mes[16][6], porcentaje_tipoenergia_sobre_mes[16][7], porcentaje_tipoenergia_sobre_mes[16][8], porcentaje_tipoenergia_sobre_mes[16][9], porcentaje_tipoenergia_sobre_mes[16][10], porcentaje_tipoenergia_sobre_mes[16][11]);
    //printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[0].Total, mes[1].Total, mes[2].Total, mes[3].Total, mes[4].Total, mes[5].Total, mes[6].Total, mes[7].Total, mes[8].Total, mes[9].Total, mes[10].Total, mes[11].Total);


printf("\n\n\nANIO 2022:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[0][12], porcentaje_tipoenergia_sobre_mes[0][13], porcentaje_tipoenergia_sobre_mes[0][14], porcentaje_tipoenergia_sobre_mes[0][15], porcentaje_tipoenergia_sobre_mes[0][16], porcentaje_tipoenergia_sobre_mes[0][17], porcentaje_tipoenergia_sobre_mes[0][18], porcentaje_tipoenergia_sobre_mes[0][19], porcentaje_tipoenergia_sobre_mes[0][20], porcentaje_tipoenergia_sobre_mes[0][21], porcentaje_tipoenergia_sobre_mes[0][22], porcentaje_tipoenergia_sobre_mes[0][23]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[1][12], porcentaje_tipoenergia_sobre_mes[1][13], porcentaje_tipoenergia_sobre_mes[1][14], porcentaje_tipoenergia_sobre_mes[1][15], porcentaje_tipoenergia_sobre_mes[1][16], porcentaje_tipoenergia_sobre_mes[1][17], porcentaje_tipoenergia_sobre_mes[1][18], porcentaje_tipoenergia_sobre_mes[1][19], porcentaje_tipoenergia_sobre_mes[1][20], porcentaje_tipoenergia_sobre_mes[1][21], porcentaje_tipoenergia_sobre_mes[1][22], porcentaje_tipoenergia_sobre_mes[1][23]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[2][12], porcentaje_tipoenergia_sobre_mes[2][13], porcentaje_tipoenergia_sobre_mes[2][14], porcentaje_tipoenergia_sobre_mes[2][15], porcentaje_tipoenergia_sobre_mes[2][16], porcentaje_tipoenergia_sobre_mes[2][17], porcentaje_tipoenergia_sobre_mes[2][18], porcentaje_tipoenergia_sobre_mes[2][19], porcentaje_tipoenergia_sobre_mes[2][20], porcentaje_tipoenergia_sobre_mes[2][21], porcentaje_tipoenergia_sobre_mes[2][22], porcentaje_tipoenergia_sobre_mes[2][23]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   porcentaje_tipoenergia_sobre_mes[3][12], porcentaje_tipoenergia_sobre_mes[3][13], porcentaje_tipoenergia_sobre_mes[3][14], porcentaje_tipoenergia_sobre_mes[3][15], porcentaje_tipoenergia_sobre_mes[3][16], porcentaje_tipoenergia_sobre_mes[3][17], porcentaje_tipoenergia_sobre_mes[3][18], porcentaje_tipoenergia_sobre_mes[3][19], porcentaje_tipoenergia_sobre_mes[3][20], porcentaje_tipoenergia_sobre_mes[3][21], porcentaje_tipoenergia_sobre_mes[3][22], porcentaje_tipoenergia_sobre_mes[3][23]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%%\n ", porcentaje_tipoenergia_sobre_mes[4][12], porcentaje_tipoenergia_sobre_mes[4][13], porcentaje_tipoenergia_sobre_mes[4][14], porcentaje_tipoenergia_sobre_mes[4][15], porcentaje_tipoenergia_sobre_mes[4][16], porcentaje_tipoenergia_sobre_mes[4][17], porcentaje_tipoenergia_sobre_mes[4][18], porcentaje_tipoenergia_sobre_mes[4][19], porcentaje_tipoenergia_sobre_mes[4][20], porcentaje_tipoenergia_sobre_mes[4][21], porcentaje_tipoenergia_sobre_mes[4][22], porcentaje_tipoenergia_sobre_mes[4][23]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[5][12], porcentaje_tipoenergia_sobre_mes[5][13], porcentaje_tipoenergia_sobre_mes[5][14], porcentaje_tipoenergia_sobre_mes[5][15], porcentaje_tipoenergia_sobre_mes[5][16], porcentaje_tipoenergia_sobre_mes[5][17], porcentaje_tipoenergia_sobre_mes[5][18], porcentaje_tipoenergia_sobre_mes[5][19], porcentaje_tipoenergia_sobre_mes[5][20], porcentaje_tipoenergia_sobre_mes[5][21], porcentaje_tipoenergia_sobre_mes[5][22], porcentaje_tipoenergia_sobre_mes[5][23]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[6][12], porcentaje_tipoenergia_sobre_mes[6][13], porcentaje_tipoenergia_sobre_mes[6][14], porcentaje_tipoenergia_sobre_mes[6][15], porcentaje_tipoenergia_sobre_mes[6][16], porcentaje_tipoenergia_sobre_mes[6][17], porcentaje_tipoenergia_sobre_mes[6][18], porcentaje_tipoenergia_sobre_mes[6][19], porcentaje_tipoenergia_sobre_mes[6][20], porcentaje_tipoenergia_sobre_mes[6][21], porcentaje_tipoenergia_sobre_mes[6][22], porcentaje_tipoenergia_sobre_mes[6][23]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[7][12], porcentaje_tipoenergia_sobre_mes[7][13], porcentaje_tipoenergia_sobre_mes[7][14], porcentaje_tipoenergia_sobre_mes[7][15], porcentaje_tipoenergia_sobre_mes[7][16], porcentaje_tipoenergia_sobre_mes[7][17], porcentaje_tipoenergia_sobre_mes[7][18], porcentaje_tipoenergia_sobre_mes[7][19], porcentaje_tipoenergia_sobre_mes[7][20], porcentaje_tipoenergia_sobre_mes[7][21], porcentaje_tipoenergia_sobre_mes[7][22], porcentaje_tipoenergia_sobre_mes[7][23]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[8][12], porcentaje_tipoenergia_sobre_mes[8][13], porcentaje_tipoenergia_sobre_mes[8][14], porcentaje_tipoenergia_sobre_mes[8][15], porcentaje_tipoenergia_sobre_mes[8][16], porcentaje_tipoenergia_sobre_mes[8][17], porcentaje_tipoenergia_sobre_mes[8][18], porcentaje_tipoenergia_sobre_mes[8][19], porcentaje_tipoenergia_sobre_mes[8][20], porcentaje_tipoenergia_sobre_mes[8][21], porcentaje_tipoenergia_sobre_mes[8][22], porcentaje_tipoenergia_sobre_mes[8][23]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[9][12], porcentaje_tipoenergia_sobre_mes[9][13], porcentaje_tipoenergia_sobre_mes[9][14], porcentaje_tipoenergia_sobre_mes[9][15], porcentaje_tipoenergia_sobre_mes[9][16], porcentaje_tipoenergia_sobre_mes[9][17], porcentaje_tipoenergia_sobre_mes[9][18], porcentaje_tipoenergia_sobre_mes[9][19], porcentaje_tipoenergia_sobre_mes[9][20], porcentaje_tipoenergia_sobre_mes[9][21], porcentaje_tipoenergia_sobre_mes[9][22], porcentaje_tipoenergia_sobre_mes[9][23]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[10][12], porcentaje_tipoenergia_sobre_mes[10][13], porcentaje_tipoenergia_sobre_mes[10][14], porcentaje_tipoenergia_sobre_mes[10][15], porcentaje_tipoenergia_sobre_mes[10][16], porcentaje_tipoenergia_sobre_mes[10][17], porcentaje_tipoenergia_sobre_mes[10][18], porcentaje_tipoenergia_sobre_mes[10][19], porcentaje_tipoenergia_sobre_mes[10][20], porcentaje_tipoenergia_sobre_mes[10][21], porcentaje_tipoenergia_sobre_mes[10][22], porcentaje_tipoenergia_sobre_mes[10][23]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[11][12], porcentaje_tipoenergia_sobre_mes[11][13], porcentaje_tipoenergia_sobre_mes[11][14], porcentaje_tipoenergia_sobre_mes[11][15], porcentaje_tipoenergia_sobre_mes[11][16], porcentaje_tipoenergia_sobre_mes[11][17], porcentaje_tipoenergia_sobre_mes[11][18], porcentaje_tipoenergia_sobre_mes[11][19], porcentaje_tipoenergia_sobre_mes[11][20], porcentaje_tipoenergia_sobre_mes[11][21], porcentaje_tipoenergia_sobre_mes[11][22], porcentaje_tipoenergia_sobre_mes[11][23]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[12][12], porcentaje_tipoenergia_sobre_mes[12][13], porcentaje_tipoenergia_sobre_mes[12][14], porcentaje_tipoenergia_sobre_mes[12][15], porcentaje_tipoenergia_sobre_mes[12][16], porcentaje_tipoenergia_sobre_mes[12][17], porcentaje_tipoenergia_sobre_mes[12][18], porcentaje_tipoenergia_sobre_mes[12][19], porcentaje_tipoenergia_sobre_mes[12][20], porcentaje_tipoenergia_sobre_mes[12][21], porcentaje_tipoenergia_sobre_mes[12][22], porcentaje_tipoenergia_sobre_mes[12][23]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[13][12], porcentaje_tipoenergia_sobre_mes[13][13], porcentaje_tipoenergia_sobre_mes[13][14], porcentaje_tipoenergia_sobre_mes[13][15], porcentaje_tipoenergia_sobre_mes[13][16], porcentaje_tipoenergia_sobre_mes[13][17], porcentaje_tipoenergia_sobre_mes[13][18], porcentaje_tipoenergia_sobre_mes[13][19], porcentaje_tipoenergia_sobre_mes[13][20], porcentaje_tipoenergia_sobre_mes[13][21], porcentaje_tipoenergia_sobre_mes[13][22], porcentaje_tipoenergia_sobre_mes[13][23]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  porcentaje_tipoenergia_sobre_mes[14][12], porcentaje_tipoenergia_sobre_mes[14][13], porcentaje_tipoenergia_sobre_mes[14][14], porcentaje_tipoenergia_sobre_mes[14][15], porcentaje_tipoenergia_sobre_mes[14][16], porcentaje_tipoenergia_sobre_mes[14][17], porcentaje_tipoenergia_sobre_mes[14][18], porcentaje_tipoenergia_sobre_mes[14][19], porcentaje_tipoenergia_sobre_mes[14][20], porcentaje_tipoenergia_sobre_mes[14][21], porcentaje_tipoenergia_sobre_mes[14][22], porcentaje_tipoenergia_sobre_mes[14][23]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[15][12], porcentaje_tipoenergia_sobre_mes[15][13], porcentaje_tipoenergia_sobre_mes[15][14], porcentaje_tipoenergia_sobre_mes[15][15], porcentaje_tipoenergia_sobre_mes[15][16], porcentaje_tipoenergia_sobre_mes[15][17], porcentaje_tipoenergia_sobre_mes[15][18], porcentaje_tipoenergia_sobre_mes[15][19], porcentaje_tipoenergia_sobre_mes[15][20], porcentaje_tipoenergia_sobre_mes[15][21], porcentaje_tipoenergia_sobre_mes[15][22], porcentaje_tipoenergia_sobre_mes[15][23]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", porcentaje_tipoenergia_sobre_mes[16][12], porcentaje_tipoenergia_sobre_mes[16][13], porcentaje_tipoenergia_sobre_mes[16][14], porcentaje_tipoenergia_sobre_mes[16][15], porcentaje_tipoenergia_sobre_mes[16][16], porcentaje_tipoenergia_sobre_mes[16][17], porcentaje_tipoenergia_sobre_mes[16][18], porcentaje_tipoenergia_sobre_mes[16][19], porcentaje_tipoenergia_sobre_mes[16][20], porcentaje_tipoenergia_sobre_mes[16][21], porcentaje_tipoenergia_sobre_mes[16][22], porcentaje_tipoenergia_sobre_mes[16][23]);
    //printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[12].Total, mes[13].Total, mes[14].Total, mes[15].Total, mes[16].Total, mes[17].Total, mes[18].Total, mes[19].Total, mes[20].Total, mes[21].Total, mes[22].Total,  mes[23].Total);
}
void media_generacion_al_meses(Energia mes[])
{
    //energia generada de media al mes
    int i;
    float Total2021 = 0, Total2022 = 0, media_meses2021, media_meses2022;
for (i = 0; i < 24; i++)
{
    //total de energia de cada año para el calculo ahora
    if (i <= 11)
    {
        Total2021 = Total2021 + mes[i].Total;
    }
    else if (i > 11 && i <24)
    {
        Total2022 = Total2022 + mes[i].Total;
    }
}

media_meses2021 = Total2021 / 12;

media_meses2022 = Total2022 / 12;

printf(" \n\nEn 2021 se generaron una media de %.2f GWh al mes\n\n", media_meses2021);
printf("En 2022 se generaron una media de %.2f GWh al mes\n\n", media_meses2022);
}
void media_generacion_tipos(Energia mes[], float res_sum2021[], float res_sum2022[])
{
  int i, j;
 float media_generacion_tipos2021[17], media_generacion_tipos2022[17];
//Usamos el sumatorio y dividido entre 12 nos da la cantidad media de energia generada por cada tipo de generacion de energia
 for ( i = 0; i < 17; i++)
 {
   media_generacion_tipos2021[i] = res_sum2021[i] / 12;
   media_generacion_tipos2022[i] = res_sum2022[i] / 12;
 }

 printf("\nEn 2021 se generaron de media tantos GWh al mes con este tipo de generacion de energia:\n\n Hidraulica:\t\t %.2f GWh\n Turbinacion bombeo:\t %.2f GWh\n Nuclear:\t\t %.2f GWh\n Carbon:\t\t %.2f GWh\n Fuel + Gas:\t\t %.2f GWh\n Motores diesel:\t %.2f GWh\n Turbina de gas:\t %.2f GWh\n Turbina de vapor:\t %.2f GWh\n Ciclo combinado:\t %.2f GWh\n Hidroelectrica:\t %.2f GWh\n Eolica:\t\t %.2f GWh\n Solar fotovoltaica:\t %.2f GWh\n Solar termica:\t\t %.2f GWh\n Otras renovables:\t %.2f GWh\n Cogeneracion:\t\t %.2f GWh\n Residuos No renovables: %.2f GWh\n Residuos renovables:\t %.2f GWh\n", media_generacion_tipos2021[0], media_generacion_tipos2021[1], media_generacion_tipos2021[2], media_generacion_tipos2021[3], media_generacion_tipos2021[4], media_generacion_tipos2021[5], media_generacion_tipos2021[6], media_generacion_tipos2021[7], media_generacion_tipos2021[8], media_generacion_tipos2021[9], media_generacion_tipos2021[10], media_generacion_tipos2021[11], media_generacion_tipos2021[12], media_generacion_tipos2021[13], media_generacion_tipos2021[14], media_generacion_tipos2021[15], media_generacion_tipos2021[15]);

 printf("\nEn 2022 se generaron de media tantos GWh al mes con este tipo de generacion de energia:\n\n Hidraulica:\t\t %.2f GWh\n Turbinacion bombeo:\t %.2f GWh\n Nuclear:\t\t %.2f GWh\n Carbon:\t\t %.2f GWh\n Fuel + Gas:\t\t %.2f GWh\n Motores diesel:\t %.2f GWh\n Turbina de gas:\t %.2f GWh\n Turbina de vapor:\t %.2f GWh\n Ciclo combinado:\t %.2f GWh\n Hidroelectrica:\t %.2f GWh\n Eolica:\t\t %.2f GWh\n Solar fotovoltaica:\t %.2f GWh\n Solar termica:\t\t %.2f GWh\n Otras renovables:\t %.2f GWh\n Cogeneracion:\t\t %.2f GWh\n Residuos No renovables: %.2f GWh\n Residuos renovables:\t %.2f GWh\n", media_generacion_tipos2022[0], media_generacion_tipos2022[1], media_generacion_tipos2022[2], media_generacion_tipos2022[3], media_generacion_tipos2022[4], media_generacion_tipos2022[5], media_generacion_tipos2022[6], media_generacion_tipos2022[7], media_generacion_tipos2022[8], media_generacion_tipos2022[9], media_generacion_tipos2022[10], media_generacion_tipos2022[11], media_generacion_tipos2022[12], media_generacion_tipos2022[13], media_generacion_tipos2022[14], media_generacion_tipos2022[15], media_generacion_tipos2022[15]);

}
void relacion_ren_noren()
{
    //relacion en porcentaje de cuanta energai es renovavle y cuanta no  en intervalos mensuales, Ej: enero 2021 45% renovable 55% no renovable
FILE *pfren;
pfren = fopen("evolucion-renovable-no-renovable_01-2021_12-2022.csv", "r");//Abrimos el fichero igual que en el main y lo leemos igual

int i = 0, j = 0, k = 0;
char c, d, f;
float datosren[1000];

if (pfren == NULL)
{
     printf("Error al abrir el archivo origen.\n");

}
else
  {

    while (fscanf(pfren, "%c", &c) != EOF  )
    {
        if ((c == ',' && f == ',' && d == '-')  || (c == '\n' && f == ',' && d == '-'))
        {
            datosren[i] == 0;
            i++;
            k++;
        }

        else if (c == '"' && d == ',')
        {
            fscanf(pfren, "%f", &datosren[i]);
            i++;
            k++;

        }
     f = d;
     d = c;
    }
   }
fclose(pfren);

printf("\n\nLas energia renovables son: la hidraulica, hidroelectrica, eolica, solar fotovoltaica, solar termica, otras renovables y residuos renovables\n\n");

printf("En el anio 2021 la relacion entre energias renovables y no renovables fue del:\n\n");

printf("Tipo/Mes \t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\nRenovables:\t");
for (i = 0; i < 12; i++)// Hay 24 datos al año, los 12 primeros de removable, los 12 siguientes de no renovable
{

    printf("%.1f%%\t", datosren[i]);


}
printf("\nNO renovables:\t");
   for (i = 24; i < 36; i++)
{

    printf("%.1f%%\t", datosren[i]);


}
printf("\n\nEn el anio 2022 la relacion entre energias renovables y no renovables fue del:\n\n");

printf("Tipo/Mes \t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\nRenovables:\t");
for (i = 12; i < 24; i++)
{

    printf("%.1f%%\t", datosren[i]);


}
printf("\nNO renovables:\t");
   for (i = 36; i < 48; i++)
{

    printf("%.1f%%\t", datosren[i]);


}

}
void balance_energia()
{
FILE *pfbal;
pfbal = fopen("balance-electrico_01-2021_12-2022.csv", "r");//Abrimos el fichero igual que en el main y lo leemos igual

int i = 0, j = 0, k = 0;
char c, d, f;
float datosbal[1000];

if (pfbal == NULL)
{
     printf("Error al abrir el archivo origen.\n");

}
else
  {

    while (fscanf(pfbal, "%c", &c) != EOF  )
    {
        if ((c == ',' && f == ',' && d == '-')  || (c == '\n' && f == ',' && d == '-'))
        {
            datosbal[i] == 0;
            i++;
            k++;
        }

        else if (c == '"' && d == ',')
        {
            fscanf(pfbal, "%f", &datosbal[i]);
            i++;
            k++;

        }
     f = d;
     d = c;
    }
   }
fclose(pfbal);

printf("\n\n\nLas energia renovables son: la hidraulica, hidroelectrica, eolica, solar fotovoltaica, solar termica, otras renovables y residuos renovables\n\n");

printf("En el anio 2021 el balance de la relacion entre energias renovables, no renovables y exportaciones e importaciones fue del:\n\n");

printf("Tipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nGen renovable:\t\t");
/*El fichero nos da mas datos pero no nos interesan ya que son repetidos por eso las "i" parecenn tener numeros raros, cogeos solo el total de energias renovables, el total de no renovables, las importaciones y exportacione(a veces es negativo) y el balance = ren + no ren + exp e imp*/
for (i = 168; i < 180; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nGen NO renovable:\t");
   for (i = 432; i < 444; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nSaldo impor y expor:\t");
   for (i = 672; i < 684; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nBalance total:\t\t");
   for (i = 696; i < 708; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\n\nEn el anio 2022 el balance de la relacion entre energias renovables, no renovables y exportaciones e importaciones fue del:\n\n");

printf("Tipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nGen renovable:\t\t");
for (i = 180; i < 192; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nGen NO renovable:\t");
   for (i = 444; i < 456; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nSaldo impor y expor:\t");
   for (i = 684; i < 696; i++)
{

    printf("%.1f\t", datosbal[i]);


}
printf("\nBalance total:\t\t");
   for (i = 708; i < 720; i++)
{

    printf("%.1f\t", datosbal[i]);


}
}
void precio_energia()
{
FILE *pfpre;
pfpre = fopen("componentes-precio-energia-cierre-desglose-nuevo_01-2021_12-2022.csv", "r");//Abrimos el fichero igual que en el main y lo leemos igual

int i = 0, j = 0, k = 0;
char c, d, f;
float datospre[1000];

if (pfpre == NULL)
{
     printf("Error al abrir el archivo origen.\n");

}
else
  {

    while (fscanf(pfpre, "%c", &c) != EOF  )
    {
        if ((c == ',' && f == ',' && d == '-')  || (c == '\n' && f == ',' && d == '-'))
        {
            datospre[i] == 0;
            i++;
            k++;
        }

        else if (c == '"' && d == ',')
        {
            fscanf(pfpre, "%f", &datospre[i]);
            i++;
            k++;

        }
     f = d;
     d = c;
    }
   }
fclose(pfpre);

//Igual, en el fichero vienen muchso datos de los cuales solo nos interesan esto pocos. en este caso por que los otros son mucho mas avanzados, usaremos el precio del mercado diario, el servicio de ajuste y el precio total= mercado diario + servicio de ajuste

printf("\n\n\nEl precio de la energia consiste del precio del mercado diario mas los servicies de ajuste:\n\n");

printf("En el anio 2021 el precio promedio de la energia cada mes fue (euros/MWh):\n\n");

printf("Tipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nMercado diario:\t\t");
for (i = 0; i < 12; i++)
{

    printf("%.1f\t", datospre[i]);


}
printf("\nServicio ajuste:\t");
   for (i = 240; i < 252; i++)
{

    printf("%.1f\t", datospre[i]);


}
printf("\nPrecio total:\t\t");
   for (i = 312; i < 324; i++)
{

    printf("%.1f\t", datospre[i]);


}

printf("\n\nEn el anio 2022 el precio promedio de la energia cada mes fue (euros/MWh):\n\n");

printf("Tipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nMercado diario:\t\t");
for (i = 12; i < 24; i++)
{

    printf("%.1f\t", datospre[i]);


}
printf("\nServicio ajuste:\t");
   for (i = 252; i < 264; i++)
{

    printf("%.1f\t", datospre[i]);


}
printf("\nPrecio total:\t\t");
   for (i = 324; i < 336; i++)
{

    printf("%.1f\t", datospre[i]);


}

}
void imprimir_datos(float datos[])
{
    //imprimir todos los datos iniciales en caso de que la persona qyee vea el menu quiera tener acceso a ellos
    int i;

    printf("\n\n\n\nAqui podemos ver los datos de cuando energia se ha generado (en GWh) cada mes y el tipo de generacion de energia que se uso,la primera tabla 2021,la segunda 2022");
    printf("\n\n\nTipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nHidraulica:\t\t");
for (i = 0; i < 12; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbinacion bombeo:\t");
   for (i = 24; i < 36; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nNuclear:\t\t");
   for (i = 48; i < 60; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCarbon:\t\t\t");
   for (i = 72; i < 84; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nFuel+gas:\t\t");
for (i = 96; i < 108; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nMotores diesel:\t\t");
for (i = 120; i < 132; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbina de gas:\t\t");
for (i = 144; i < 156; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbina de vapor:\t");
for (i = 168; i < 180; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCiclo combinado:\t");
for (i = 192; i < 204; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nHidroelectrica:\t\t");
for (i = 216; i < 228; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nEolica:\t\t\t");
for (i = 240; i < 252; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nSolar fotovoltaica:\t");
for (i = 264; i < 276; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nSolar termica:\t\t");
for (i = 288; i < 300; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nOtras renovables:\t");
for (i = 312; i < 324; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCogeneracion:\t\t");
for (i = 336; i < 348; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nRediduos renovables:\t");
for (i = 360; i < 372; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nResiduos no renovables:\t");
for (i = 384; i < 396; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\n\nGeneracion total:\t");
for (i = 408; i < 420; i++)
{

    printf("%.1f\t", datos[i]);


}

printf("\n\n\nTipo/Mes \t\t ene\t feb\t mar\t abr\t may\t jun\t nul\t ago\t sep\t oct\t nov\t dic\t");
printf("\n\nHidraulica:\t\t");
for (i = 12; i < 24; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbinacion bombeo:\t");
   for (i = 36; i < 48; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nNuclear:\t\t");
   for (i = 60; i < 72; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCarbon:\t\t\t");
   for (i = 84; i < 96; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nFuel+gas:\t\t");
for (i = 108; i < 120; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nMotores diesel:\t\t");
for (i = 132; i < 144; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbina de gas:\t\t");
for (i = 156; i < 168; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nTurbina de vapor:\t");
for (i = 180; i < 192; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCiclo combinado:\t");
for (i = 204; i < 216; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nHidroelectrica:\t\t");
for (i = 228; i < 240; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nEolica:\t\t\t");
for (i = 252; i < 264; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nSolar fotovoltaica:\t");
for (i = 276; i < 288; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nSolar termica:\t\t");
for (i = 300; i < 312; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nOtras renovables:\t");
for (i = 324; i < 336; i++)
{

    printf("%.1f\t", datos[i]);


}
printf("\nCogeneracion:\t\t");
for (i = 348; i < 360; i++)
{

    printf("%.1f\t", datos[i]);

}
printf("\nRediduos renovables:\t");
for (i = 372; i < 384; i++)
{

    printf("%.1f\t", datos[i]);

}
printf("\nResiduos no renovables:\t");
for (i = 396; i < 408; i++)
{

    printf("%.1f\t", datos[i]);

}
printf("\nGeneracion total:\t");
for (i = 420; i < 432; i++)
{

    printf("%.1f\t", datos[i]);

}
}
void menu(float datos[],Energia mes[],int k,float res_sum2021[], float res_sum2022[])
{
    int opcion, elegir;
//En el menu se daran 2 opciones mas la de salir, segun elija una opcion u otra, le saldran mas subopciones entre las que elegir

    /* code */


    printf("\n      MENU DE INICIO     \n\n");
    printf(" Bienvenido al menu principal.\n\n Datos a visualizar:\n\n");
    printf(" 1. DATOS REALES\n 2. CALCULOS MATEMATICOS\n 3. SALIR\n");

    do{
    printf(" Elija una opcion (ingrese su numero correspondinete):\n");
    scanf("%i", &opcion);
    }
    while (opcion < 1 || opcion > 3);


switch(opcion)
{

case 1:
while (true)
{
    
    printf("\n\n 1. Datos de 2021 y 2022\n 2. Precio medio mensual de la energia\n 3. Balance mensual de la energia\n 4. Relacion entre renovables y no renovables\n 5. SALIR: ");
    do{
        printf("\n Elige un dato(ingrese su numero correspondinete):\n");
        scanf("%i", &elegir);
        }
        while (elegir < 1 || elegir > 5);

  
    switch(elegir){
    case 1:
        //datos de 2021 a 2023
        imprimir_datos(datos);
        break;

    case 2:
        //precio energia
        precio_energia(datos);
        break;

    case 3:
        //balance energia
        balance_energia(datos);
        break;
    case 4:
        relacion_ren_noren(datos);
        break;
    case 5:
        exit(0);
        break;
    }

}
    break;


case 2:
while (true)
{
    /* code */


printf(" \nOPERACIONES MATEMATICAS \n\n");
    printf(" 1. Energia generada cada mes respecto del total del anio\n 2. Energia generada con cada tipo de generacion respecto a su total del anio\n 3. Energia generada con cada tipo de generacion respecto al total del mes\n 4. Media de energia generada al mes\n 5. Media mensual de generacion de cada tecnologia\n 6. Maximo\n 7. Minimo\n 8. SALIR");
    do{
        printf("\n Elige un dato(ingrese su numero correspondinete):\n");
        scanf("%i",&elegir);}while(elegir<1||elegir>8);
    switch(elegir){
    case 1:
        //Porcentaje total de mes sobre anio
        porcentaje_total_mes_sobre_anio(mes);
        break;

    case 2:
        //Porcentaje tipo de energia sobre su total en el anio
        porcentaje_tipoenergia_sobre_su_total_anio(mes,res_sum2021,res_sum2022);
        break;

    case 3:
    //Porcentaje tipo de energia sobre mes
    porcentaje_tipoenergia_sobre_mes(mes);
    break;

    case 4:
        //Media al mes
        media_generacion_al_meses(mes);
        break;

    case 5:
        //Media de cada tecnologia
        media_generacion_tipos(mes,res_sum2021,res_sum2022);
        break;

    case 6:
        //maximo
        maximo(datos,k);
        break;
    case 7:
        //minimo
        minimo(datos,k);
        break;
    case 8:
     exit(0);
     break;
    }
    }
    break;

case 3:
    printf("SALIENDO\n");
    exit(0);
    break;

}

}