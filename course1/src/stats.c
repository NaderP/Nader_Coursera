/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Week 1 assignment >
 *
 * <It is a simple code for eight functions that will
 *           -Sort An array
 *           -Find minimum number
 *           -Find maximum number
 *           -Find median  number
 *           -Find mean    number
 *           -Print the array
 *           -Print the statistics "minimum,maximum,median,mean"
 *           -Main function to control them
 * >
 *
 * @author <Nader Tosson>
 * @date <20/07/2018 >
 *
 */



#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
 void print_statistics(int*,int);
 void print_array( int*,int);
 float find_median(int*,int);
 float find_mean(int*,float);
 int find_maximum(int*,int);
 int find_minimum(int*, int);
 void sort_array(int*, int);
 int main()
{
  int SIZE=40;
  int test[40] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  int*test1;
      test1=test;


/* Statistics and Printing Functions Go Here */

print_array(test,SIZE);

sort_array(test,SIZE);

printf("\n After sorting \n \n");

print_array(test,SIZE);

print_statistics(test,SIZE);


}

/* Add other Implementation File Code Here */


void print_array(int*Data, int SIZE)
{
 int i;
 for(i=0;i<SIZE;i++)
 {
     printf("Data[%d] \t %d \n",i+1,Data[i]);

 }

return ;
}


void sort_array(int*Data,int SIZE)
{
   int i,temp,x;

   for(i=0;i<SIZE;i++)
   {
       for(x=i+1;x<SIZE;x++)
       {
           if(Data[i]<Data[x]) {temp=Data[i];
                                 Data[i]=Data[x];
                                 Data[x]=temp;}
       }
   }
   return ;
}

int find_maximum(int*Data,int SIZE)
{
    int i,max,temp;
    max = Data[0];

    for(i=0;i<SIZE;i++)
    {
        if(Data[i]>max) max=Data[i];
    }
    return max;
}

int find_minimum(int*Data,int SIZE)
{
    int i,min,temp;
    min = Data[0];

    for(i=0;i<SIZE;i++)
    {
        if(Data[i]<min) min=Data[i];
    }
    return min;
}

float find_mean(int*Data,float SIZE)
{
    int i,sum;
    int Avg;
    sum = 0;

    for(i=0;i<SIZE;i++)
    {
        sum = sum + Data[i];
    }
    Avg = (sum/SIZE);

  return Avg;
}

float find_median(int*Data,int SIZE)
{
    if(SIZE % 2 == 0) return (Data[(SIZE/2)-1]+Data[(SIZE/2)])/2;

    else return Data[(SIZE/2)] ;
}

void print_statistics(int*Data,int SIZE)
{
    int max,min;
float Avg,median;
max = find_maximum(Data,SIZE);
min = find_minimum(Data,SIZE);
Avg = find_mean(Data,SIZE);
median = find_median(Data,SIZE);
printf("Maximum = %d \t Minimum = %d \t Mean = %f \t Median = %f \n",max,min,Avg,median);
    return;
}

