#include <iostream>

const int MAX_SIZE = 100;

int main()
{
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];

    int n1,n2;
    int m1,m2;

    std::cout<<"Enter the sizes of the first matrix (nxm):";
    std::cin>>n1>>m1;

    std::cout<<"Enter the first matrix:"<<std::endl;

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            std::cin>>matrix1[i][j];
        }
    }

    std::cout<<"Enter the sizes of the second matrix (nxm):";
    std::cin>>n2>>m2;

    std::cout<<"Enter the second matrix:"<<std::endl;

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            std::cin>>matrix2[i][j];
        }
    }

}

// дължина на стринг
unsigned length(const char number[])
{

    unsigned i = 0;
    while(number[i])
    {
        i++;
    }
    return i;
}
//обръщане на стринг
void reverse(char * &str)
{
    char helper[MAX_SIZE];
    for (int i = 0; i < length(str) ; ++i) {
        helper[i] = str[i];
    }
    for (int i = 0; i < length(str) ; ++i) {
        str[i] = helper[length(str) - i - 1];
    }
}

int parseNumber(char chr)
{
    if( chr >= '0' && chr <= '9')
        return chr - '0';
    else if(chr >= 'a' && chr <= 'z')
        return chr - 'a' + 10;
    else if(chr >= 'A' && chr <= 'Z')
        return chr - 'A' + 10;
    else
        return 0;
}
//ако има число по-голямо или равно на 10 да се превърне в буква
char parseChar(int num)
{
    return (char)(num - 10 + 'A');
}
//parse
char toChar(int number)
{
    return char(number + '0');
}

char * calculateStr(char number1[],char number2[], int k)
{
    char * result = new char [MAX_SIZE];

    //обръщаме двата стринга и започваме да събираме елементите по индекси
    reverse(number1);
    reverse(number2);


    bool isBigger = length(number1) > length(number2);

    int flag = 0;
    int currentIndex = 0;
    int occupiedIndex = 0;

    if(isBigger)
    {
        while(number1[currentIndex])
        {
            if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) + flag >= k)
            {
                if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag >= 10)
                    result[occupiedIndex++] = parseChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag);
                else
                    result[occupiedIndex++] =  toChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag);
                flag = 1;
            }
            else
            {
                if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) + flag >= 10)
                    result[occupiedIndex++] = parseChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex])  + flag);
                else
                    result[occupiedIndex++] = toChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex])  + flag);
                flag = 0;
            }
            currentIndex++;
        }
    }

    else
    {
        while(number2[currentIndex])
        {
            if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) + flag >= k)
            {
                if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag >= 10)
                    result[occupiedIndex++] = parseChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag);
                else
                    result[occupiedIndex++] =  toChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) - k + flag);
                flag = 1;
            }
            else
            {
                if(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) + flag >= 10)
                    result[occupiedIndex++] = parseChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]) + flag);
                else
                    result[occupiedIndex++] = toChar(parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex])+ flag);
                flag = 0;
            }
            currentIndex++;
        }

    }

    //ако е останал флаг 1 го прибавяме към стринга
    if(flag == 1)
    {
        result[occupiedIndex++] = toChar(flag);
    }
    //слагаме последния символ
    result[occupiedIndex++] = '\0';
    reverse(result);

    return result;

}
int main2_TERC()
{
    char number1[MAX_SIZE],number2[MAX_SIZE];
    std::cout<<"Enter number 1:";
    std::cin>>number1;

    std::cout<<"Enter number 2:";
    std::cin>>number2;

    int k;
    std::cout<<"Enter the numeric system:";
    std::cin>>k;
    //валидация
    if(k < 2 || k > 36)
    {
        std::cerr<<"Enter a valid numeric system!";
        return -1;
    }
    int tempIndex = 0;

    //проверка дали има символи непринадлежащи на бройната  система
    while(number1[tempIndex])
    {
        if(parseNumber(number1[tempIndex]) >= k)
        {
            std::cerr<<"Bad input data!";
            return -1;
        }
        tempIndex++;
    }
    tempIndex = 0;

    while(number2[tempIndex])
    {
        if(parseNumber(number2[tempIndex]) >= k)
        {
            std::cerr<<"Bad input data!";
            return -1;
        }
        tempIndex++;
    }

   char * ptrToResult = calculateStr(number1, number2,k);
   std::cout<<ptrToResult<<std::endl;
   delete [] ptrToResult;
   ptrToResult = nullptr;

   return 0;
}