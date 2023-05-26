#include <stdio.h>


typedef struct
{

  int mes;
  float Ha, Tb, N, C, Fg, M, Tg, Tv, Cc, He, E, Sf, St, O, Cg, Rn, Rr, Total;

}Energia;

float maximo(float datos[],int k);
float minimo(float datos[],int k);
float porcentaje_total_mes_sobre_anio(Energia mes[]);
float sumatorio_tipos(Energia mes[]);
float porcentaje_tipoenergia_sobre_su_total_anio(Energia mes[], float sum_energia2021[], float sum_energia2022[]);
float porcentaje_tipoenergia_sobre_mes(Energia mes[]);

int main()
{
Energia mes[24];
FILE *pf1;
pf1 = fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");

int i = 0, j = 0, k = 0;
char c, d, f;
float datos[1000];

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
    else if (i > 383 && i <= 404)
    {
        mes[i-384].Rr = datos[i];
    }
    else if (i > 404 && i <= 428)
    {
        mes[i-405].Total = datos[i];
    }

}

for (i = 0; i <= 23; i++)
{
    mes[i].mes = i + 1;
}

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
float porcentaje_total_mes_sobre_anio(Energia mes[])
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
    else 
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
    else
    {
        porcentaje_total_mes_sobre_anio[i] = mes[i].Total / Total2022 * 100;
    }
}
return porcentaje_total_mes_sobre_anio[24];
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
float porcentaje_tipoenergia_sobre_mes(Energia mes[])
{
   float porcentaje_tipoenergia_sobre_mes[17][24];
   int i, j;

    for (j = 0; j < 24; j++)
    {

        if (i < 12)
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
        
       else
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
}return porcentaje_tipoenergia_sobre_mes[17][24];
}





