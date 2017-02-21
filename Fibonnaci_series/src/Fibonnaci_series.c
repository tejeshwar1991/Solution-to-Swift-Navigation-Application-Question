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

#define debugging 0

void compute(long int n);

/*
 *    Function to compute whether a number is prime or not.
 */
int IsPrime(unsigned int number) {
            if (number <= 3 && number > 1)
                        return 1;                                                                // as 2 and 3 are prime
            else if (number%2==0 || number%3==0)
                        return 0;                                                               // check if number is divisible by 2 or 3
            else {
                        unsigned int i;
                        for (i=5; i*i<=number; i+=6) {
                                    if (number % i == 0 || number%(i + 2) == 0)
                                                return 0;
                        }
                        return 1;
            }
}

/*
 *    Computes the Fibonnaci series for a given 'n' value.
 */

void fibonacci_numbers(int n)
{
            int f1 = 0, f2 = 1, i;
            int next = 0;

            if (n ==1){
                        compute(n);
            }

            for (i = 1; i <n; i++)
            {
                        next = f1 + f2;
                        compute(next);
#if debugging
                        printf("%d\n", next);
#endif
                        f1 = f2;
                        f2 = next;
            }
}

/*
 *    Function to identify every number as Fizz, Buzz, FizzBuzz, BuzzFizz, Prime and if even just prints the number.
 */
void compute(long int n)
{
            if(n%15 == 0)
                        printf("FizzBuzz\n");
            else if(n%3 == 0)
                        printf("Buzz\n");
            else if(n%5 == 0)
                        printf("Fizz\n");
            else if(IsPrime(n))
                        printf("BuzzFizz\n");
            else
                        printf("%ld\n",n);
}

int main ()
{
            int n = 10;
            fibonacci_numbers(n);
            getchar();
            return 0;
}
