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
 * @file <stats.h> 
 * @brief <first week assignment >
 *
 * It is a simple code for eight functions that will
 *           -Sort An array
 *           -Find minimum number
 *           -Find maximum number
 *           -Find median  number
 *           -Find mean    number
 *           -Print the array
 *           -Print the statistics "minimum,maximum,median,mean"
 *           -Main function to control them
 * @author <Nader Tosson>
 * @date <20/7/2018 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_array( int*,int);
/**
 * @brief <It is a function to print the array's data>
 *
 * <the function prints the data via pointer and loop>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <Doesn't return anything>
 */

void sort_array(int*, int);

/**
 * @brief <It is a function to sort the Array>
 *
 * <It is consisted of a nested loop were the outer loop
 * is used to go throw all the array locations while the
 * inside loop compare the current location with all other
 * locations to make sure the array is sorted>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <Doesn't retun anything>
 */

float find_median(int*,int);

/**
 * @brief <A function to find the median Number>
 *
 * <After the function is sorted the program will search
 *  for the median number location and return it>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <The median of numbers provided>
 */

float find_mean(int*,float); 

/**
 * @brief <A function to find the mean Value>
 *
 * <The function add all the numbers and divide them by their count>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <Return the mean value of numbers provided>
 */

int find_minimum(int*, int); 

/**
 * @brief <It is a function to find the maximum number>
 *
 * <The function put the first number in the array as a default maximum
 *  then compare it with each number to find the real maximum number>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <Retun the maximum number of numbers provided>
 */

int find_minimum(int*, int); 

/**
 * @brief <It is a function to find the minimum number>
 *
 * <The function put the first number in the array as a default minimum
 *  then compare it with each number to find the real minimum number>
 *
 * @param <unsigned char *Data> <is A pointer to the array of data>
 * @param <unsigned int Size> <is the size of the array>
 *
 * @return <Retun the minimum number of numbers provided>
 */

void print_statistics(int*,int);

/**
 * @brief <It is a function to print statistics >
 *
 * <it print Mean,Median,Maximum and Minimum>
 *
 * @param <Mean>     <The Mean value>
 * @param <Median>   <The Median number>
 * @param <Maximum>  <The Maximum number>
 * @param <Minimum>  <The Minimum number>
 *
 * @return <It doesn't return anything>
 */
#endif /* __STATS_H__ */
