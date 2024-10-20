#include <cs50.h>
#include <stdio.h>
#include <math.h>

int digits(long n);
char valid(int n, long num);
void card_type(int n, long num);

int main(void)
{
    long number = get_long("Number: ");
    int d = digits(number);
    if (valid(d, number) == 'v')
    {
        card_type(d, number);
    }
    else
    {
        printf("INVALID\n");
    }
}

int digits(long number)
{
    long num = number;
    int d = 0;
    do
    {
        d++;
        num = num / 10;
    }
    while (num != 0);
    return d;
}

char valid(int n, long num)
{
    char result = 'f';
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        long p = pow(10, i);
        long temp = num / p % 10;
        if (i % 2 == 0 || i == 0)
        {
            sum = sum + temp;
        }
        else
        {
            if (temp * 2 >= 10)
            {
                sum2 = sum2 + (temp * 2 / 10) + ((temp * 2) % 10) ;
            }
            else
            {
                sum2 = sum2 + temp * 2;
            }
        }
    }
    if ((sum + sum2) % 10 == 0)
    {
        result = 'v';
    }
    return result;
}

void card_type(int n, long num)
{
    int f = num / pow(10, n - 2);
    if (n == 15 && (f == 34 || f == 37))
    {
        printf("AMEX\n");
    }
    else if (n == 16 && (f >= 51 && f <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((n == 13 || n == 16) && f / 10 == 4)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}

