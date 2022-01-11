#include <iostream>
const int MAX_SIZE = 100;
unsigned myStrLen (const char str[])
{
    unsigned i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int getValue(int values[MAX_SIZE], const char letters[MAX_SIZE], int n, char letter)
{
    for (int i = 0; i < n; ++i) {
        if(letter == letters[i])
            return values[i];
    }
    return 0;
}
int calculate(int values[MAX_SIZE], char letters[MAX_SIZE], char equation[MAX_SIZE], int n)
{
    int currentChar = 0;
    int currProd = 1;
    int sum = 0;
    while(equation[currentChar])
    {
        if(equation[currentChar + 1] == '.' || equation[currentChar - 1] == '.')
        {
            currProd *= getValue(values,letters,n,equation[currentChar]);
        }
        else if(equation[currentChar + 1] == '+')
        {
            sum += currProd;
            currProd = 1;
        }
        else if(equation[currentChar - 1] == '+' && equation[currentChar + 1] != '.')
        {
            sum+= getValue(values,letters,n,equation[currentChar]);
        }

         if(currentChar + 1 >= myStrLen(equation))
        {
            sum+=currProd;
        }

        currentChar++;

    }
    return sum;

}
int main()
{
    int values[MAX_SIZE];
    char letters[MAX_SIZE];

    int n;
    std::cout<<"Enter n:";
    std::cin>>n;
    char equation[MAX_SIZE];

    for (int i = 0; i < n; ++i) {
        std::cout<<"Enter a letter:";
        std::cin>>letters[i];
    }
    for (int i = 0; i < n ; ++i) {
        std::cout<<"value for "<<letters[i]<<" :";
        std::cin>>values[i];
    }

    std::cout<<"Enter the equation:";
    std::cin>>equation;

    std::cout<<calculate(values, letters, equation, n)<<std::endl;

}