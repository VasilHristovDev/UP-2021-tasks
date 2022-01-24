#include <iostream>
#include <cstring>
#include <cmath>

int powerOfTen (int power)
{
    int powTen = 1;
    for (int i = 0; i < power ; ++i) {
        powTen*=10;
    }
    return powTen;
}

int parseToInt(char * string)
{
    if(strcmp(string, "one") == 0)
    {
        return 1;
    }
    else if(strcmp(string, "two") == 0)
    {
        return 2;
    }
    else if(strcmp(string, "three") == 0)
    {
        return 3;
    }
    else if(strcmp(string, "four") == 0)
    {
        return 4;
    }
    else if(strcmp(string, "five") == 0)
    {
        return 5;
    }
    else if(strcmp(string, "six") == 0)
    {
        return 6;
    }
    else if(strcmp(string, "seven") == 0)
    {
        return 7;
    }
    else if(strcmp(string,"eight") == 0)
    {
        return 8;
    }
    else if(strcmp(string, "nine") == 0)
    {
        return 9;
    }
    else if(strcmp(string, "zero") == 0)
    {
        return 0;
    }
}
char * reverseNumber(int number)
{
    int tempVar = number;
    int countDigits = 0;
    while(tempVar!=0)
    {
        countDigits++;
        tempVar/=10;
    }
    char * returnable = new char [countDigits];
    int occupiedCharactersInReturnable = 0;
    if(number < 0)
    {
        returnable[occupiedCharactersInReturnable++] = '-';
        number *= -1;
    }
    int tempHelper = 1;
    for (int i = countDigits; i > 0; --i) {
        returnable[occupiedCharactersInReturnable++] = (number / powerOfTen(i-1)) % 10 + '0';
    }
    returnable[occupiedCharactersInReturnable] = '\0';
    return returnable;
}
void parseStrings(char *& expression)
{
    int currentChar = 0;
    char * collector = new char [6];
    int collectorOccupied = 0;
    char ** arrayWithNumbersAndOperations = new char * [100];
    int occupiedRows = 0;
    while(expression[currentChar])
    {
        collector[collectorOccupied++] = expression[currentChar];
        if(collectorOccupied == 3)
        {
            if(strstr(collector, "one") || strstr(collector, "two")  || strstr(collector, "six") )
            {
                arrayWithNumbersAndOperations[occupiedRows] = new char [3];
                for (int i = 0; i < 3 ; ++i) {
                    arrayWithNumbersAndOperations[occupiedRows][i] = collector[i];
                }
                arrayWithNumbersAndOperations[occupiedRows][3] = '\0';
                occupiedRows++;
                collectorOccupied = 0;
            }
        }
        else if( collectorOccupied == 4)
        {
            if(strstr(collector, "four")  || strstr(collector, "five")  || strstr(collector, "nine") || strstr(collector, "zero")||
                    strstr(collector, "plus"))
            {
                arrayWithNumbersAndOperations[occupiedRows] = new char [4];
                for (int i = 0; i < 4 ; ++i) {
                    arrayWithNumbersAndOperations[occupiedRows][i] = collector[i];
                }
                arrayWithNumbersAndOperations[occupiedRows][4] = '\0';
                occupiedRows++;
                collectorOccupied = 0;
            }
        }
        else if(collectorOccupied == 5)
        {
            if(strstr(collector, "three") || strstr(collector, "seven") || strstr(collector, "eight") || strstr(collector, "minus") )
            {
                arrayWithNumbersAndOperations[occupiedRows] = new char [5];
                for (int i = 0; i < 5 ; ++i) {
                    arrayWithNumbersAndOperations[occupiedRows][i] = collector[i];
                }
                arrayWithNumbersAndOperations[occupiedRows][5] = '\0';
                occupiedRows++;
                collectorOccupied = 0;
            }
        }
        currentChar++;
    }

    int sum = 0;
    char operation = '0';
    for (int i = 0; i < occupiedRows; ++i) {

        if(strcmp(arrayWithNumbersAndOperations[i], "minus") != 0 && strcmp(arrayWithNumbersAndOperations[i], "plus"))
        {
            int tempIterator = i;
            int counter = 0;
            bool flag = false;
            while( tempIterator < occupiedRows && !flag)
            {
                if(strcmp(arrayWithNumbersAndOperations[tempIterator], "minus") == 0 || strcmp(arrayWithNumbersAndOperations[tempIterator], "plus") == 0 )
                {
                    flag = true;
                }
                else
                {
                    counter++;
                    tempIterator++;
                }
            }
            if(operation != '-')
                sum+= parseToInt(arrayWithNumbersAndOperations[i]) * powerOfTen(counter - 1);
            else
                sum-= parseToInt(arrayWithNumbersAndOperations[i]) * powerOfTen(counter -1 );
        }
        else {
            if(strcmp(arrayWithNumbersAndOperations[i], "minus") == 0)
            {
                operation = '-';
            }
            else
            {
                operation = '+';
            }
        }
    }
    delete [] expression;
    expression = reverseNumber(sum);

    delete [] arrayWithNumbersAndOperations;
    arrayWithNumbersAndOperations = nullptr;
    delete [] collector;
    collector = nullptr;


}
int main()
{
    const int MAX_SIZE_EXPRESSION = 1024;
    char * expression = new char [MAX_SIZE_EXPRESSION];

    std::cin>>expression;
    unsigned length = strlen(expression);
    for (int i = 0; i < length; ++i) {
        if(expression[i] == ' ')
        {
            std::cerr<<"No intervals allowed!"<<std::endl;
            return -1;
        }
    }
    parseStrings(expression);
    std::cout<<expression<<std::endl;
    return 0;
}
