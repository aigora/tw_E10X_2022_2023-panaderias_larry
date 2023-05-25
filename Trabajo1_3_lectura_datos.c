#include <stdio.h>

int main()
{
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
fclose(pf1);

for (i = 0; i < k; i++)
{

    printf("%f\t", datos[i]); 
    
    printf("\n");
    
    j++; 

    if (j == 24)
            {
                printf("\n\n\n");
                j = j - 24;
            }

            
}
    return 0;

}