#include <stdio.h>
#include <cs50.h>

void create_brick(int height);
int input_height(void);

int main(void)
{

    int height = input_height();
    create_brick(height);

}

int input_height(void)
{
    // ask user for pyramid height and check if it is between 0 and 9
    int height;

    do
    {
        height = get_int("enter pyramid height: ");

    }
    while (height < 1 || height > 8);
    return height;
}



void create_brick(int height)
{
    // create pyramids with users input of height

    for (int i = 1; i <= height; i++)
    {
       int left_count = i;
       int right_count = i;

       int left_space = height - i;

        // space out left pyramid
       do
       {
           if(left_space > 0)
           {
               printf(" ");
               left_space -= 1;

           }
       }
       while (left_space > 0);

        // create left pyramid
       do
       {
            printf("#");
            left_count -= 1;
       }
       while (left_count > 0);


        // create space between left and right pyramid
        printf("  ");


        // create right pyramid
        do
        {
            printf("#");
            right_count -= 1;
       }
       while (right_count > 0);

        printf("\n");

    }
}