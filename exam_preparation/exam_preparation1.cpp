#include <iostream>

bool contains(int n, int k)
{
    if(n % 10 == k)
        return true;
    if(n == 0 )
        return false;
    return contains(n/10,k);

}
int changeNumber(int n, int k, int m)
{

    if (n < 0)
        return -changeNumber(-n, k, m);

    if (n == 0)
        return 0;

    int newBeginning = changeNumber(n / 10, k, m);

    int lastDigit = n % 10;
    if (lastDigit == k)
    {
        return newBeginning * 10 + m;
    }

    return newBeginning * 10 + lastDigit;
}
int main1()
{
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    int k;
    std::cout<<"Enter k:";
    std::cin>>k;
    int m;
    std::cout<<"Enter m:";
    std::cin>>m;

    std::cout<<(contains(n,k)? "YES": "NO")<<std::endl;
    if(contains(n,k))
       std::cout<< changeNumber(n,k,m)<<std::endl;

    return 0;
}
int sumInterval(int a, int b , int k)
{
    if(a > b)
        return 0;
    return a + sumInterval(a + k,b,k);
}
int main2()
{
    int a,b,k;
    std::cout<<"Enter a and b:";
    std::cin>>a>>b;
    std::cout<<"Enter k:";
    std::cin>>k;

    std::cout<<sumInterval(a,b,k)<<std::endl;

    return 0;

}
bool DAC(int array[], int size, int start, int end, int k)
{
    if(size == 0)
        return false;
    if(k == array[(size - 1)/2])
        return true;
    if(k > array[(size - 1)/2])
        return DAC(array, size/2, (size - 1)/2, end, k);
    return  DAC(array, size/2, start, (size - 1)/2 , k);
}
int main7()
{
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    int array[100];
    std::cout<<"Enter sorted ASC array:";

    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }

    int k;
    std::cout<<"Enter k:";
    std::cin>>k;

    std::cout<<(DAC(array,n,0,n-1, k)? "It is inside":"It is not inside array")<<std::endl;

    return 0;
}
int maxElement(int array[], int start, int end)
{
    if(start == end)
    {
        return array[start];
    }
    int middle = start + (end - start)/2;
    int maxLeftSide = maxElement(array,  start, middle);
    int maxRightSide = maxElement(array, middle + 1, end);
    return maxLeftSide > maxRightSide ? maxLeftSide : maxRightSide;
}
int main8()
{
    int array[100];
    int n;
    std::cout<<"enter n:";
    std::cin>>n;

    std::cout<<"Enter array:";
    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }
    std::cout<<maxElement(array, 0, n);
    return 0;
}
bool areASC(const int array[], int n)
{
    if (n == 0)
        return true;
    if(array[n - 1] > array[n])
        return false;
    return areASC(array, n - 1);
}
int main9()
{
    int array[100];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
    }
    std::cout<<(areASC(array,n - 1) ? "YES": "NO")<<std::endl;

    return 0;
}
bool exists(const int array[], int n, int x)
{
    if(n <= 0)
        return false;
    if(array[n - 1] == x)
        return true;
    return exists(array, n - 1, x);
}
bool areDifferent(int array[], int n)
{
    if(n <= 1)
        return true;
    if(exists(array, n - 1, array[n - 1]))
        return false;

    return areDifferent(array, n - 1);
}
int main10()
{
    int array[100];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
    }
    std::cout<<(areDifferent(array,n) ? "YES": "NO")<<std::endl;

    return 0;
}
/* 5
 * 1 2 3 4 6 7 8 9
 */
void addElement(int * array, int &n, int element, int current)
{
    if(current <= 1)
        return;
    if(array[current - 1] <= element)
    {
        array[current] = element;
        n++;
    }
    else
    {
        array[current] = array[current - 1];
        addElement(array,n,element, current - 1);
    }

}
int main11()
{
    int array[100];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }
    int k;
    std::cout<<"enter k:";
    std::cin>>k;

    addElement(array, n, k, n);
    for (int i = 0; i < n; ++i) {
        std::cout<<array[i]<<" ";
    }
    return 0;
}
bool isOperation(char c)
{
    return c == '+' || c == '*' || c == '-';
}
double calculate(double left, char op, double right)
{
    switch (op) {
        case '+':
            return left + right;
        case '*':
            return left * right;
        case '-':
            return left - right;
        case '/':
            return right == 0? 0 : left / right;
        default:
            return 0;
    }
}
double calculateExpression(char  *& expression)
{
    if(*expression - '0' >= 0 && *expression - '0' <= 9)
        return *expression++ - '0';
    double left = calculateExpression(++expression);
    char op = *expression;
    double right = calculateExpression(++expression);

    expression++;
    return calculate(left, op, right);

}
int main12()
{
    char expression[100];
    std::cin>>expression;

    char * ptrToExpr = expression;
    std::cout<<calculateExpression(ptrToExpr);

    return 0;
}
int findXY(int sum, int difference, int firstDigit, int secondDigit)
{
    if(secondDigit > 9)
    {
        secondDigit = ++firstDigit;
    }
    if (firstDigit > 9)
        return 0;
    if(firstDigit + secondDigit == sum)
        return ((secondDigit * 10 + firstDigit) - (firstDigit * 10 + secondDigit) == difference) ? firstDigit*10 + secondDigit : findXY(sum,difference,firstDigit,secondDigit+1);
    else
        return findXY(sum,difference,firstDigit,secondDigit + 1);
}
int main13()
{
    int xPLUSy;
    int yxMINUSxy;

    std::cout<<"Enter x + y:";
    std::cin>>xPLUSy;

    std::cout<<"Enter yx - xy:";
    std::cin>>yxMINUSxy;
    int result = findXY(xPLUSy, yxMINUSxy, 0,0);
    if(result == 0)
        std::cout<<"wrong data"<<std::endl;
    else
        std::cout<<result<<std::endl;

    return 0;

}



