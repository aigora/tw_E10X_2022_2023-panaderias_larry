#include <stdio.h>


typedef struct
{

  int mes;
  float Ha, Tb, N, C, Fg, M, Tg, Tv, Cc, He, E, Sf, St, O, Cg, Rn, Rr, Total;

}Energia;

float maximo(float datos[],int k);
float minimo(float datos[],int k);

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
        mes[i-408].Total = datos[i];
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
    //printf("¿De que quieres saber el maximo?");
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
    //printf("¿De que quieres saber el minimo?");
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
