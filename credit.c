#include <stdio.h>
#include <cs50.h>

string check_card(long card_num);
bool check_sum(int length_card, long card_num);
string check_type(int length_card, long card_num);
int check_length(long card_num);
int second_seq(int number);
long power(int number, int power);


int main(void)
{
    // input credit card number
    long card_num;
    do
    {
        card_num = get_long("enter card number: ");
    }
    while (card_num < 0);

    // check if card is valid
    string card_type = check_card(card_num);

    // print if it is a visa or mastercard or american express
    printf("%s\n",card_type);

}


// check the card for its length, checksum and type
string check_card(long card_num)
{
    int length_card = check_length(card_num);

    // printf("card length- %i\n",length_card);

    if(length_card == 13 || length_card == 15 || length_card == 16){

        // checksum of card
        bool valid_sequence = check_sum(length_card, card_num);


        // check card type if checksum is valid
        if (valid_sequence){

            string card_type = check_type(length_card, card_num);

            return card_type;

        }
    }

    return "INVALID";

}


// check the sumation algorith of the digits
bool check_sum(int length_card, long card_num)
{
    // printf("checksum\n");


    // sequence checks which rule to use in summation
    int sequence = 0;

    long current_value = card_num;
    int total_sum = 0;


    for (int i = 1; i <= length_card; i++)
    {
        // get next digit
        long a = power(10,i);
        long b = power(10,i-1);
        int digit = (card_num % a / b);

        // printf("%ld\n %ld\n", a, b);
        // printf("%i\n",digit);

        // first rule of summation
        if (sequence == 0){
            sequence = 1;
        }

        // second rule of summation
        else if (sequence == 1){
            sequence = 0;
            digit = second_seq(digit);
        }

        total_sum += digit;
    }

    // printf("%i\n",total_sum);

    // if last digit of total is 0 then the card is valid
    if (total_sum % 10 == 0){
        return true;
    }

    return false;
}

// checks and returns the type of card
string check_type(int length_card, long card_num)
{

    // printf("check type\n");


    // get length of card
    // check against length of credit card

    long tens = power(10,length_card-2);

    // printf("%ld\n",tens);

    int startswith = card_num / tens;

    // printf("%i\n", startswith);

    if (length_card == 13)
    {
        // check for Visa

        startswith = startswith/10;
        // printf("%i\n",startswith);

        if (startswith == 4){
            return "VISA";
        }

    }

    else if (length_card == 15)
    {
        // check for American Express
        if (startswith == 34 || startswith == 37)
        {
            return "AMEX";

        }
    }

    else if (length_card == 16)
    {
        // Check for Master Card
        if (startswith == 51 || startswith == 52 || startswith == 53 || startswith == 54 || startswith == 55)
        {

            return "MASTERCARD";
        }

        // check for VISA
        else
        {
            startswith = startswith/10;

            if (startswith == 4){
                return "VISA";
            }

        }

    }

    return "INVALID";
}


// checks the length of a number
int check_length(long card_num){
    int count = 0;
    long current_value = card_num;

    if (current_value == 0){
        return count;
    }

    // loop and eliminate individual digits until number is 0
    do{
        current_value = current_value/10;
        count += 1;
        // printf("%li\n",current_value);
    }

    while (current_value > 0);
    return count;
}


// the rule for every other number of the card
int second_seq(int number){

    // multiply the number by 2
    int multiply = number * 2;

    // add the individual digits together
    int first_digit = multiply % 10;
    int second_digit = multiply / 10;

    int result = first_digit + second_digit;

    return result;
}


// takes in a number and its exponent power and returns result
long power(int number, int power)
{
    // if exponent is 0 return 1
    if (power == 0){
        return 1;
    }


    // multiplies the number by itself according to the exponent power
    long result = 1;

    for (int i = 1; i <= power; i++)
    {
        result *= number;

    }
    return result;
}


