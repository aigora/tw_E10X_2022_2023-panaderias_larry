#include <stdio.h>


typedef struct
{

  int mes;
  float Ha, Tb, N, C, Fg, M, Tg, Tv, Cc, He, E, Sf, St, O, Cg, Rn, Rr, Total;

}Energia;

float maximo(float datos[],int k);
float minimo(float datos[],int k);
void porcentaje_total_mes_sobre_anio(Energia mes[]);
void sumatorio_tipos(Energia mes[], float* result_sum2021, float* result_sum2022);
void porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[], float res_sum2021[], float res_sum2022[]);
void porcentaje_tipoenergia_sobre_mes(Energia mes[]);


int main()
{
Energia mes[24];
FILE *pf1;
pf1 = fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");

int i = 0, j = 0, k = 0;
char c, d, f;
float datos[1000], t;

if (pf1 == NULL)
{
     printf("Error al abrir el archivo origen.\n");
    return -1;
}
else
  {

    while (fscanf(pf1, "%c", &c) != EOF  )
    {
        if ((c == ',' && f == ',' && d == '-')  || (c == '\n' && f == ',' && d == '-'))
        {
            datos[i] == 0;
            i++;
            k++;
        }

        else if (c == '"' && d == ',')
        {
            fscanf(pf1, "%f", &datos[i]);
            i++;
            k++;

        }
     f = d;
     d = c;
    }
   }
   i--;
   k--;
fclose(pf1);

for ( i = 0; i <= k; i++)
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


 float aux1[17], aux2[17], res_sum2021[17], res_sum2022[17]; 
 sumatorio_tipos(mes, aux1, aux2);
 for (i = 0; i < 17; i++)
 {
    res_sum2021[i] = aux1[i];
    res_sum2022[i] = aux2[i];
   
 } 
porcentaje_tipoenergia_sobre_su_total_anio(mes, res_sum2021, res_sum2022);

    return 0;
}

float maximo(float datos[],int k)
{
    int i;
    float comparacion;
    int fila_usuario=1;
    //printf("�De que quieres saber el maximo?");
/*
    //Maximo total
    comparacion= datos[0];
    for(i=0;i<407;i++)
    {
        if(datos[i]>comparacion)
        {
            comparacion= datos[i];
        }
    }
*/


    //Maximo por tecnologia


/*
    do
    {
        printf("�De que fila quieres saber el maximo?");
        scanf("%i",&fila_usuario);
    }
    while(fila_usuario<0);
    comparacion=datos[(fila_usuario*24)-24];
    for(i=(fila_usuario*24)-23;i<(fila_usuario*24);i++)
        {
        if(datos[i]>comparacion)
            {
            comparacion= datos[i];
            }
        }
*/
    return comparacion;
}
float minimo(float datos[],int k)
{
    int i;
    float comparacion;
    int fila_usuario=4;
    //printf("�De que quieres saber el minimo?");
/*
    //Minimo total
    comparacion= datos[0];
    for(i=0;i<=k;i++)
    {
        if(datos[i]<comparacion)
        {
            comparacion= datos[i];
        }
    }
*/

        //Minimo por tecnologia
/*
    do
    {
        printf("�De que fila quieres saber el minimo?");
        scanf("%i",&fila_usuario);
    }
    while(fila_usuario<0);
    comparacion=datos[(fila_usuario*24)-24];
    for(i=(fila_usuario*24)-23;i<(fila_usuario*24);i++)
        {
        if(datos[i]<comparacion)
            {
            comparacion= datos[i];
            }
        }
*/
    return comparacion;
}
void porcentaje_total_mes_sobre_anio(Energia mes[])
{
    int i;
    float Total2021 = 0, Total2022 = 0;
    float porcentaje_total_mes_sobre_anio[24];
for (i = 0; i < 24; i++)
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
for ( i = 0; i < 24; i++)
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
printf("El porcentaje de energia total generada en un mes respecto de la energia total generada ese anio:\n");
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
    float porcentaje_tipoenergia_sobre_su_total_anio[17][24];
    int i, j;

    for (j = 0; j < 24; j++)
    {

        if (i < 12)
        {
        
        porcentaje_tipoenergia_sobre_su_total_anio[0][i] = mes[i].Ha / 17 * 100;

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

   printf("%f",porcentaje_tipoenergia_sobre_su_total_anio[0][1]);
}
void porcentaje_tipoenergia_sobre_mes(Energia mes[])
{
   float porcentaje_tipoenergia_sobre_mes[17][24];
   int i, j;

    for (i = 0; i < 24; i++)
    {

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
    printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[0].Total, mes[1].Total, mes[2].Total, mes[3].Total, mes[4].Total, mes[5].Total, mes[6].Total, mes[7].Total, mes[8].Total, mes[9].Total, mes[10].Total, mes[11].Total);


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
    printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[12].Total, mes[13].Total, mes[14].Total, mes[15].Total, mes[16].Total, mes[17].Total, mes[18].Total, mes[19].Total, mes[20].Total, mes[21].Total, mes[22].Total,  mes[23].Total);