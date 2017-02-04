/*
 ============================================================================
 Name        : Fibonnaci_series.c
 Author      : TEJ
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 =========================================================================================================
 In the programming language of your choice, write a program generating the first n Fibonacci numbers F(n), printing
"Buzz" when F(n) is divisible by 3.
"Fizz" when F(n) is divisible by 5.
"FizzBuzz" when F(n) is divisible by 15.
"BuzzFizz" when F(n) is prime.
the value F(n) otherwise.
We encourage you to compose your code for this question in a way that represents the quality of code you produce in the workplace - e.g. tests,
documentation, linting, dependency management (though there's no need to go this far).

Please upload your code to GitHub or bitbucket and post a link to the repo or gist as your answer in the Lever form.
==========================================================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int IsPrime(unsigned int number) {
            if (number <= 3 && number > 1)
                        return 1;            // as 2 and 3 are prime
            else if (number%2==0 || number%3==0)
                        return 0;     // check if number is divisible by 2 or 3
            else {
                        unsigned int i;
                        for (i=5; i*i<=number; i+=6) {
                                    if (number % i == 0 || number%(i + 2) == 0)
                                                return 0;
                       }
                        return 1;
            }
}

long int fib(int n)
{
            /* Declare an array to store Fibonacci numbers. */
           long int f[n+1];
            int i;

            /* 0th and 1st number of the series are 0 and 1*/
            f[0] = 0;
            f[1] = 1;

            for (i = 2; i <= n; i++)
            {
                        /* Add the previous 2 numbers in the series
                        and store it */
                        f[i] = f[i-1] + f[i-2];
            }

            return f[n];
}

void compute(long int n)
{
            if(n/3 == 0)
                        printf("Buzz\n");
            if(n/5 == 0)
            {
                        if(n/15 == 0)
                                    printf("FizzBuzz\n");
                        else
                                    printf("Fizz\n");

            }
            if(IsPrime(n))
            {
                        printf("BuzzFizz\n");
            }
            else
                        printf("%ld\n",n);
}

int main ()
{
           long  int n = 5;
            printf("%ld\n", fib(n));
            compute(fib(n));
            getchar();
            return 0;
}
