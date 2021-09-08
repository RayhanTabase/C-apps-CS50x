#include <stdio.h>
#include <cs50.h>
#include <stdio.h>

int check_min_int(string message,int minimum);
int calc_years(int start_size,int end_size);

int main(void){
    int start_size = check_min_int("enter start size: ", 9);
    int end_size = check_min_int("enter end size: ", start_size);
    int num_years = calc_years(start_size, end_size);
    printf("Years: %i\n", num_years);
}

int check_min_int(string message, int minimum){
    // takes in a message string and a minimum integer
    // keep asking for int if int is not equal or greater than minimum
    // else return the integer
    int num;
    do{
        num = get_int("%s", message);

    }
    while(num < minimum);
    return num;
}


int calc_years(int start_size,int end_size){
    // keep calculating the yearly population change using the start size until it reaches the end size
    // each loop adds adds 1 year to the beginning year which is 0
    // return the number of years it takes to get to the end size

    int current_size = start_size;
    int years = 0;

    if(start_size == end_size){
        return 0;
    }

    do{
        float growth_rate = current_size / 3;
        float shrink_rate = current_size / 4;
        current_size = current_size + growth_rate - shrink_rate;
        years += 1;
    }

    while(current_size < end_size);

    return years;
}
