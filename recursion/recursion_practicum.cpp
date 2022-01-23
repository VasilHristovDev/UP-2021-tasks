#include <iostream>

void printNumbers(int n)
{
    if(n < 1)
        return;
    printNumbers(n - 1);
    std::cout<<n<<" ";
}
bool isSorted(int array[], int  n)
{
     if(n == 1)
        return true;
    return array[n - 2] <= array[n - 1] && isSorted(array, n - 1);
}
bool exists(int number, int array[], int n)
{
    if(n == 0)
        return false;
    return array[n - 1] == number || exists(number, array, n - 1);
}
bool areDifferent(int array[], int n)
{
    if(n <= 1)
        return true;
    if(exists(array[n-1],array,n-1))
        return false;
    return areDifferent(array, n - 1);
}
int sumArray(int array[], int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return array[0];
    return array[0] + sumArray(array + 1, n - 1);
}
int productArray (int array[], int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return array[0];
    return array[0] * productArray(array + 1,  n - 1);
}
int sumDigits(int n)
{
    if(n <= 9)
        return n;
    return n%10 + sumDigits(n/10);
}
int countNumbersInChar(char *& string)
{
    if(*string == '\0')
        return 0;
    if(*string >= '0' && *string <= '9')
        return 1 + countNumbersInChar(++string);
    return countNumbersInChar(++string);
}
int fact(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return n * fact(n - 1);
}
int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n - 2) + fib(n - 1);

}
int main()
{
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;
    std::cout<<fact(n)<<std::endl;
    std::cout<<fib(n);
    return 0;
//      char string[100];
//      char * ptrToString = string;
//      std::cout<<"Enter string:";
//      std::cin>>string;
//      std::cout<<countNumbersInChar(ptrToString);
//    int array[100];
//
//    for (int i = 0; i < n ; ++i) {
//        std::cin>>array[i];
//    }
//
//    std::cout<<"Is array sorted? "<<(isSorted(array,n)? "yes": "no")<<std::endl;
//    std::cout<<"Are different? "<<(areDifferent(array,n)? "yes": "no")<<std::endl;
//    std::cout<<"Sum of array is :"<<sumArray(array, n)<<std::endl;
//    std::cout<<"Product of array is :"<<productArray(array, n);
//      std::cout<<sumDigits(n)<<std::endl;

}
