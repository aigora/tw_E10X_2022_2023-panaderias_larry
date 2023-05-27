#include <stdio.h>


typedef struct
{

  int mes;
  float Ha, Tb, N, C, Fg, M, Tg, Tv, Cc, He, E, Sf, St, O, Cg, Rn, Rr, Total;

}Energia;

float maximo(float datos[],int k);
float minimo(float datos[],int k);
void porcentaje_total_mes_sobre_anio(Energia mes[]);
float sumatorio_tipos(Energia mes[]);
float porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[], float sum_energia2021[], float sum_energia2022[]);
void ptesm(Energia mes[]);


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

   
   ptesm(mes);
   
   
   
   
   
    return 0;
}

float maximo(float datos[],int k)
{
    int i;
    float comparacion;
    //printf("�De que quieres saber el maximo?");
    //Maximo total
    comparacion= datos[0];
    for(i=0;i<407;i++)
    {
        if(datos[i]>comparacion)
        {
            comparacion= datos[i];
        }
    }
    return comparacion;
}
float minimo(float datos[],int k)
{
    int i;
    float comparacion;
    //printf("�De que quieres saber el minimo?");
    //Minimo total
    comparacion= datos[0];
    for(i=0;i<=k;i++)
    {
        if(datos[i]<comparacion)
        {
            comparacion= datos[i];
        }
    }
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
printf("\n\n\n%f %f %f", mes[0].Total,  mes[1].Total,  mes[2].Total );

}
float sumatorio_tipos(Energia mes[])
{
    int i, j;
    float sum_energia2021[17], sum_energia2022[17];

    for ( i = 0; i < 12; i++)
    {
        sum_energia2021[0] = sum_energia2021[0] + mes[i].Ha;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[1] = sum_energia2021[1] + mes[i].Tb;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[2] = sum_energia2021[2] + mes[i].N;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[3] = sum_energia2021[3] + mes[i].C;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[4] = sum_energia2021[4] + mes[i].Fg;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[5] = sum_energia2021[5] + mes[i].M;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[6] = sum_energia2021[6] + mes[i].Tg;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[7] = sum_energia2021[7] + mes[i].Tv;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[8] = sum_energia2021[8] + mes[i].Cc;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[9] = sum_energia2021[9] + mes[i].He;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[10] = sum_energia2021[10] + mes[i].E;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[11] = sum_energia2021[11] + mes[i].Sf;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[12] = sum_energia2021[12] + mes[i].St;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[13] = sum_energia2021[13] + mes[i].O;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[14] = sum_energia2021[14] + mes[i].Cg;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[15] = sum_energia2021[15] + mes[i].Rn;
    }
      for ( i = 0; i < 12; i++)
    {
        sum_energia2021[16] = sum_energia2021[16] + mes[i].Rr;
    }

    for ( i = 12; i < 24; i++)
    {
        sum_energia2022[0] = sum_energia2022[0] + mes[i].Ha;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[1] = sum_energia2022[1] + mes[i].Tb;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[2] = sum_energia2022[2] + mes[i].N;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[3] = sum_energia2022[3] + mes[i].C;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[4] = sum_energia2022[4] + mes[i].Fg;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[5] = sum_energia2022[5] + mes[i].M;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[6] = sum_energia2022[6] + mes[i].Tg;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[7] = sum_energia2022[7] + mes[i].Tv;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[8] = sum_energia2022[8] + mes[i].Cc;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[9] = sum_energia2022[9] + mes[i].He;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[10] = sum_energia2022[10] + mes[i].E;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[11] = sum_energia2022[11] + mes[i].Sf;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[12] = sum_energia2022[12] + mes[i].St;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[13] = sum_energia2022[13] + mes[i].O;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[14] = sum_energia2022[14] + mes[i].Cg;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[15] = sum_energia2022[15] + mes[i].Rn;
    }
      for ( i = 12; i < 24; i++)
    {
        sum_energia2022[16] = sum_energia2022[16] + mes[i].Rr;
    }
    
    return sum_energia2021[17], sum_energia2022[17];
}
float porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[],float sum_energia2021[], float sum_energia2022[])
{
    float porcentaje_tipoenergia_sobre_su_total_anio[17][24];
    int i, j;

    for (j = 0; j < 24; j++)
    {

        if (i < 12)
        {
        
        porcentaje_tipoenergia_sobre_su_total_anio[0][i] = mes[i].Ha / sum_energia2021[0] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[1][i] = mes[i].Tb / sum_energia2021[1] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[2][i] = mes[i].N / sum_energia2021[2] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[3][i] = mes[i].C / sum_energia2021[3] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[4][i] = mes[i].Fg / sum_energia2021[4] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[5][i] = mes[i].M / sum_energia2021[5] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[6][i] = mes[i].Tg / sum_energia2021[6] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[7][i] = mes[i].Tv / sum_energia2021[7] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[8][i] = mes[i].Cc / sum_energia2021[8] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[9][i] = mes[i].He / sum_energia2021[9] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[10][i] = mes[i].E / sum_energia2021[10] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[11][i] = mes[i].Sf / sum_energia2021[11] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[12][i] = mes[i].St / sum_energia2021[12] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[13][i] = mes[i].O / sum_energia2021[13] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[14][i] = mes[i].Cg / sum_energia2021[14] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[15][i] = mes[i].Rn / sum_energia2021[15] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[16][i] = mes[i].Rr / sum_energia2021[16] * 100;

        }
        
       else
      { 
        
        porcentaje_tipoenergia_sobre_su_total_anio[0][i] = mes[i].Ha / sum_energia2022[0] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[1][i] = mes[i].Tb / sum_energia2022[1] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[2][i] = mes[i].N / sum_energia2022[2] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[3][i] = mes[i].C / sum_energia2022[3] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[4][i] = mes[i].Fg / sum_energia2022[4] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[5][i] = mes[i].M / sum_energia2022[5] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[6][i] = mes[i].Tg / sum_energia2022[6] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[7][i] = mes[i].Tv / sum_energia2022[7] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[8][i] = mes[i].Cc / sum_energia2022[8] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[9][i] = mes[i].He / sum_energia2022[9] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[10][i] = mes[i].E / sum_energia2022[10] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[11][i] = mes[i].Sf / sum_energia2022[11] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[12][i] = mes[i].St / sum_energia2022[12] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[13][i] = mes[i].O / sum_energia2022[13] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[14][i] = mes[i].Cg / sum_energia2022[14] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[15][i] = mes[i].Rn / sum_energia2022[15] * 100;

        porcentaje_tipoenergia_sobre_su_total_anio[16][i] = mes[i].Rr / sum_energia2022[16] * 100;

    }  
}
return porcentaje_tipoenergia_sobre_su_total_anio[17][24];
}
void ptesm(Energia mes[])
{
   float ptesm[17][24];
   int i, j;

    for (i = 0; i < 24; i++)
    {

        ptesm[0][i] = mes[i].Ha / mes[i].Total * 100;

        ptesm[1][i] = mes[i].Tb / mes[i].Total * 100;

        ptesm[2][i] = mes[i].N / mes[i].Total * 100;

        ptesm[3][i] = mes[i].C / mes[i].Total * 100;

        ptesm[4][i] = mes[i].Fg / mes[i].Total * 100;

        ptesm[5][i] = mes[i].M / mes[i].Total * 100;

        ptesm[6][i] = mes[i].Tg / mes[i].Total * 100;

        ptesm[7][i] = mes[i].Tv / mes[i].Total * 100;

        ptesm[8][i] = mes[i].Cc / mes[i].Total * 100;

        ptesm[9][i] = mes[i].He / mes[i].Total * 100;

        ptesm[10][i] = mes[i].E / mes[i].Total * 100;

        ptesm[11][i] = mes[i].Sf / mes[i].Total * 100;

        ptesm[12][i] = mes[i].St / mes[i].Total * 100;

        ptesm[13][i] = mes[i].O / mes[i].Total * 100;

        ptesm[14][i] = mes[i].Cg / mes[i].Total * 100;

        ptesm[15][i] = mes[i].Rn / mes[i].Total * 100;

        ptesm[16][i] = mes[i].Rr / mes[i].Total * 100;


    }

printf("\nANIO 2021:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[0][0], ptesm[0][1], ptesm[0][2], ptesm[0][3], ptesm[0][4], ptesm[0][5], ptesm[0][6], ptesm[0][7], ptesm[0][8], ptesm[0][9], ptesm[0][10], ptesm[0][11]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[1][0], ptesm[1][1], ptesm[1][2], ptesm[1][3], ptesm[1][4], ptesm[1][5], ptesm[1][6], ptesm[1][7], ptesm[1][8], ptesm[1][9], ptesm[1][10], ptesm[1][11]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[2][0], ptesm[2][1], ptesm[2][2], ptesm[2][3], ptesm[2][4], ptesm[2][5], ptesm[2][6], ptesm[2][7], ptesm[2][8], ptesm[2][9], ptesm[2][10], ptesm[2][11]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   ptesm[3][0], ptesm[3][1], ptesm[3][2], ptesm[3][3], ptesm[3][4], ptesm[3][5], ptesm[3][6], ptesm[3][7], ptesm[3][8], ptesm[3][9], ptesm[3][10], ptesm[3][11]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[4][0], ptesm[4][1], ptesm[4][2], ptesm[4][3], ptesm[4][4], ptesm[4][5], ptesm[4][6], ptesm[4][7], ptesm[4][8], ptesm[4][9], ptesm[4][10], ptesm[4][11]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[5][0], ptesm[5][1], ptesm[5][2], ptesm[5][3], ptesm[5][4], ptesm[5][5], ptesm[5][6], ptesm[5][7], ptesm[5][8], ptesm[5][9], ptesm[5][10], ptesm[5][11]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[6][0], ptesm[6][1], ptesm[6][2], ptesm[6][3], ptesm[6][4], ptesm[6][5], ptesm[6][6], ptesm[6][7], ptesm[6][8], ptesm[6][9], ptesm[6][10], ptesm[6][11]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[7][0], ptesm[7][1], ptesm[7][2], ptesm[7][3], ptesm[7][4], ptesm[7][5], ptesm[7][6], ptesm[7][7], ptesm[7][8], ptesm[7][9], ptesm[7][10], ptesm[7][11]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[8][0], ptesm[8][1], ptesm[8][2], ptesm[8][3], ptesm[8][4], ptesm[8][5], ptesm[8][6], ptesm[8][7], ptesm[8][8], ptesm[8][9], ptesm[8][10], ptesm[8][11]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[9][0], ptesm[9][1], ptesm[9][2], ptesm[9][3], ptesm[9][4], ptesm[9][5], ptesm[9][6], ptesm[9][7], ptesm[9][8], ptesm[9][9], ptesm[9][10], ptesm[9][11]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[10][0], ptesm[10][1], ptesm[10][2], ptesm[10][3], ptesm[10][4], ptesm[10][5], ptesm[10][6], ptesm[10][7], ptesm[10][8], ptesm[10][9], ptesm[10][10], ptesm[10][11]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[11][0], ptesm[11][1], ptesm[11][2], ptesm[11][3], ptesm[11][4], ptesm[11][5], ptesm[11][6], ptesm[11][7], ptesm[11][8], ptesm[11][9], ptesm[11][10], ptesm[11][11]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[12][0], ptesm[12][1], ptesm[12][2], ptesm[12][3], ptesm[12][4], ptesm[12][5], ptesm[12][6], ptesm[12][7], ptesm[12][8], ptesm[12][9], ptesm[12][10], ptesm[12][11]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[13][0], ptesm[13][1], ptesm[13][2], ptesm[13][3], ptesm[13][4], ptesm[13][5], ptesm[13][6], ptesm[13][7], ptesm[13][8], ptesm[13][9], ptesm[13][10], ptesm[13][11]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[14][0], ptesm[14][1], ptesm[14][2], ptesm[14][3], ptesm[14][4], ptesm[14][5], ptesm[14][6], ptesm[14][7], ptesm[14][8], ptesm[14][9], ptesm[14][10], ptesm[14][11]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[15][0], ptesm[15][1], ptesm[15][2], ptesm[15][3], ptesm[15][4], ptesm[15][5], ptesm[15][6], ptesm[15][7], ptesm[15][8], ptesm[15][9], ptesm[15][10], ptesm[15][11]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[16][0], ptesm[16][1], ptesm[16][2], ptesm[16][3], ptesm[16][4], ptesm[16][5], ptesm[16][6], ptesm[16][7], ptesm[16][8], ptesm[16][9], ptesm[16][10], ptesm[16][11]);
    printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[0].Total, mes[1].Total, mes[2].Total, mes[3].Total, mes[4].Total, mes[5].Total, mes[6].Total, mes[7].Total, mes[8].Total, mes[9].Total, mes[10].Total, mes[11].Total);








printf("\n\n\nANIO 2022:\n\n");
    printf("Tipo/Mes:            \t 1  \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10 \t 11 \t 12\n");
    printf("Hidraulica:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[0][12], ptesm[0][13], ptesm[0][14], ptesm[0][15], ptesm[0][16], ptesm[0][17], ptesm[0][18], ptesm[0][19], ptesm[0][20], ptesm[0][21], ptesm[0][22], ptesm[0][23]);
    printf("Turbinacion bombeo:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[1][12], ptesm[1][13], ptesm[1][14], ptesm[1][15], ptesm[1][16], ptesm[1][17], ptesm[1][18], ptesm[1][19], ptesm[1][20], ptesm[1][21], ptesm[1][22], ptesm[1][23]);
    printf("Nuclear:              \t %.1f%% \t %.1f%% \t %.1f%%  %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[2][12], ptesm[2][13], ptesm[2][14], ptesm[2][15], ptesm[2][16], ptesm[2][17], ptesm[2][18], ptesm[2][19], ptesm[2][20], ptesm[2][21], ptesm[2][22], ptesm[2][23]);
    printf("Carbon:               \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",   ptesm[3][12], ptesm[3][13], ptesm[3][14], ptesm[3][15], ptesm[3][16], ptesm[3][17], ptesm[3][18], ptesm[3][19], ptesm[3][20], ptesm[3][21], ptesm[3][22], ptesm[3][23]);
    printf("Fuel + Gas:           \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%% \t 0.0%%\n ", ptesm[4][12], ptesm[4][13], ptesm[4][14], ptesm[4][15], ptesm[4][16], ptesm[4][17], ptesm[4][18], ptesm[4][19], ptesm[4][20], ptesm[4][21], ptesm[4][22], ptesm[4][23]);
    printf("Motores diesel:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[5][12], ptesm[5][13], ptesm[5][14], ptesm[5][15], ptesm[5][16], ptesm[5][17], ptesm[5][18], ptesm[5][19], ptesm[5][20], ptesm[5][21], ptesm[5][22], ptesm[5][23]);
    printf("Turbina de gas:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[6][12], ptesm[6][13], ptesm[6][14], ptesm[6][15], ptesm[6][16], ptesm[6][17], ptesm[6][18], ptesm[6][19], ptesm[6][20], ptesm[6][21], ptesm[6][22], ptesm[6][23]);
    printf("Turbina de vapor:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[7][12], ptesm[7][13], ptesm[7][14], ptesm[7][15], ptesm[7][16], ptesm[7][17], ptesm[7][18], ptesm[7][19], ptesm[7][20], ptesm[7][21], ptesm[7][22], ptesm[7][23]);
    printf("Ciclo combinado:      \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[8][12], ptesm[8][13], ptesm[8][14], ptesm[8][15], ptesm[8][16], ptesm[8][17], ptesm[8][18], ptesm[8][19], ptesm[8][20], ptesm[8][21], ptesm[8][22], ptesm[8][23]);
    printf("Hidroelectrica:       \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[9][12], ptesm[9][13], ptesm[9][14], ptesm[9][15], ptesm[9][16], ptesm[9][17], ptesm[9][18], ptesm[9][19], ptesm[9][20], ptesm[9][21], ptesm[9][22], ptesm[9][23]);
    printf("Eolica:              \t %.1f%% \t %.1f%% \t %.1f%%   %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[10][12], ptesm[10][13], ptesm[10][14], ptesm[10][15], ptesm[10][16], ptesm[10][17], ptesm[10][18], ptesm[10][19], ptesm[10][20], ptesm[10][21], ptesm[10][22], ptesm[10][23]);
    printf("Solar fotovoltaica:   \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[11][12], ptesm[11][13], ptesm[11][14], ptesm[11][15], ptesm[11][16], ptesm[11][17], ptesm[11][18], ptesm[11][19], ptesm[11][20], ptesm[11][21], ptesm[11][22], ptesm[11][23]);
    printf("Solar termica:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[12][12], ptesm[12][13], ptesm[12][14], ptesm[12][15], ptesm[12][16], ptesm[12][17], ptesm[12][18], ptesm[12][19], ptesm[12][20], ptesm[12][21], ptesm[12][22], ptesm[12][23]);
    printf("Otras renovables:     \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[13][12], ptesm[13][13], ptesm[13][14], ptesm[13][15], ptesm[13][16], ptesm[13][17], ptesm[13][18], ptesm[13][19], ptesm[13][20], ptesm[13][21], ptesm[13][22], ptesm[13][23]);
    printf("Cogeneracion:         \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  ptesm[14][12], ptesm[14][13], ptesm[14][14], ptesm[14][15], ptesm[14][16], ptesm[14][17], ptesm[14][18], ptesm[14][19], ptesm[14][20], ptesm[14][21], ptesm[14][22], ptesm[14][23]);
    printf("Residuos NO ren:      \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[15][12], ptesm[15][13], ptesm[15][14], ptesm[15][15], ptesm[15][16], ptesm[15][17], ptesm[15][18], ptesm[15][19], ptesm[15][20], ptesm[15][21], ptesm[15][22], ptesm[15][23]);
    printf("Residuos ren:        \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ", ptesm[16][12], ptesm[16][13], ptesm[16][14], ptesm[16][15], ptesm[16][16], ptesm[16][17], ptesm[16][18], ptesm[16][19], ptesm[16][20], ptesm[16][21], ptesm[16][22], ptesm[16][23]);
    printf("Generacion total:    \t %.1f%% \t %.1f%% \t %.1f%%  \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%% \t %.1f%%\n ",  mes[12].Total, mes[13].Total, mes[14].Total, mes[15].Total, mes[16].Total, mes[17].Total, mes[18].Total, mes[19].Total, mes[20].Total, mes[21].Total, mes[22].Total,  mes[23].Total);

}





