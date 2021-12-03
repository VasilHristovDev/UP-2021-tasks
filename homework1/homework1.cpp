#include <iostream>
#include <cstdlib>
#include <ctime>
/*
 * Автор:
 * Васил Христов
 * Фак. номер:
 * 5MI0800128
 */

//ЗАД 0
const double EPSILON = 0.001;
const double CIRCLE_RADIUS = 4;
//Имаме кръг, чийто център е с координати (0,0) и чийто радиус е 4
bool isInsideCircle(double x, double y)
{
    //Прилагаме Питагоровата Теорема за разстоянието
    double result = x * x + y * y;
    return CIRCLE_RADIUS * CIRCLE_RADIUS - result >= EPSILON;
}

//сет от помощни функции за сравняването до 3 знак след дес. запетая
bool isGreaterThan(double a, double b)
{
    return a - b > EPSILON;
}

bool isSmallerThan(double a, double b)
{
    return b - a > EPSILON;
}

int main0()
{
    double x, y;
    const double TRIANGLE_SIDE = sqrt(CIRCLE_RADIUS / 2) * 2;
    std::cout << "Enter x :";
    std::cin >> x;
    std::cout << "Enter y :";
    std::cin >> y;

    if (isInsideCircle(x, y))
    {
        //Проверяваме дали се намира в I квадрант
        if (isGreaterThan(x,0) && y >= EPSILON)
        {
            if (isSmallerThan(x, TRIANGLE_SIDE) && isGreaterThan(x, y))
            {
                std::cout<< "It is in the yellow zone";
            }
            else if (isSmallerThan(x, TRIANGLE_SIDE) && isGreaterThan(y, x))
            {
                std::cout<< "It is in the green zone";
            }
            else if (isGreaterThan(x, TRIANGLE_SIDE))
            {
                std::cout<< "It is in the purple zone";
            }
            else
            {
                std::cout<< "The given point is not in any of the zones";
            }
        }
            //Проверяваме дали се намира във II квадрант y>=0 защото попада в розовата граница
        else if (isSmallerThan(x,0) && y >= EPSILON)
        {
            //Тъй като имаме отрицателен х и ни трябва абсолютната му стойност
            if (isGreaterThan(TRIANGLE_SIDE, abs(x)) && isGreaterThan(abs(x), y))
            {
                std::cout<< "It is in the pink zone";
            }
            else if (isGreaterThan(TRIANGLE_SIDE, abs(x)) && isGreaterThan(y, abs(x)))
            {
                std::cout<< "It is in the red zone";
            }
            else
            {
                std::cout<< "The given point is not in any of the zones";
            }
        }
            //Проверяваме дали се намира в III квадрант
        else if (isSmallerThan(x, 0) && isSmallerThan(y,0))
        {
            if (isGreaterThan(TRIANGLE_SIDE, abs(x)) && isGreaterThan(abs(x), abs(y)))
            {
                std::cout<< "It is in the pink zone";
            }
            else if (isGreaterThan(TRIANGLE_SIDE, abs(x)) && isGreaterThan(abs(y), abs(x)))
            {
                std::cout<< "It is in the blue zone";
            }
            else
            {
                std::cout<< "The given point is not in any of the zones";
            }
        }
            //Проверяваме дали се намира в IV квадрант
        else if (isGreaterThan(x,0) && y <= EPSILON)
        {
            if (isSmallerThan(x, TRIANGLE_SIDE))
            {
                std::cout<< "It is in the yellow zone";
            }
            else if (isGreaterThan(x, TRIANGLE_SIDE))
            {
                std::cout<< "It is in the purple zone";
            }
            else
            {
                std::cout<< "The given point is not in any of the zones";
            }
        }
        else
        {
            std::cout<< "The given point is not in any of the zones";
        }

    }
        //Ако е извън кръга, правим проверка дали се намира в сивия правоъгълник
    else if (isGreaterThan(x,-2) && isSmallerThan(x,2) && isSmallerThan(y,-6) && isGreaterThan(y,-7))
    {
        std::cout << "The point is in the grey area";
    }
    else
    {
        std::cout<< "The given point is not in any of the zones";
    }

    return 0;
}

//Зад.1
int calculateFunctionValue(int fx)
{
    return fx % 2 == 0 ?  fx / 2 :  3 * fx + 1;
}

int main1()
{
    int x;
    std::cout<< "Enter x :";
    std::cin>> x;
    //Валидация
    if(x <= 1)
    {
        std::cerr<< "X must be greater than 1" << std::endl;
        //ако връщаме -1 то потребителя знае, че има проблем
        return -1;
    }
    int fx = x;
    for (int i = 2; i <= 35 ; i++)
    {
        fx = calculateFunctionValue(fx);
    }
    std::cout<< "f(x) = "<<fx<<std::endl;
    return 0;
}

//Зад. 2
//за всеки различен вид мармалад връщаме първата буква
char determineTypeOfJam(int code)
{
    int thousands = code / 10000 % 10;
    int hundreds = code / 1000 % 10;
    int tens = code / 100 % 10;
    int ones = code / 10 % 10;

    int typeOfJam = 1000 * thousands + 100 * hundreds + 10 * tens + ones;
    if (typeOfJam % 7 == 0)
    {
        return 'b';
    }
    else if (typeOfJam % 13 == 0)
    {
        return 'p';
    }
    else if (typeOfJam % 17 == 0)
    {
        return 'h';
    }
    else
    {
        return 'e';
    }
}

int main2()
{
    int n;
    std::cout << "Enter n :";
    std::cin >> n;
    if (n <= 7)
    {
        std::cerr<< "Enter a number greater than 7" << std::endl;
        //ако връщаме -1 то потребителя знае, че има проблем
        return -1;
    }
    int code = 0;
    int numberOfBerriesJam = 0;
    int numberOfPeachJam = 0;
    int numberOfRoseHipJam = 0;
    int tempVar;
    //помощна променлива за конструиране на кода като число с цифри,
    //последователно въведени от входните данни
    int powerOfTen = 10000000;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> tempVar;
        code += powerOfTen * tempVar;
        powerOfTen /= 10;
        if (i % 8 == 0) {
            switch(determineTypeOfJam(code))
            {
                case 'p': numberOfPeachJam++; break;
                case 'b': numberOfBerriesJam++; break;
                case 'h': numberOfRoseHipJam++; break;
                default: break;
            }
            code = 0;
            powerOfTen = 10000000;
        }
    }
    std::cout << "Berries jam: " << numberOfBerriesJam << std::endl;
    std::cout << "Peach Jam: " << numberOfPeachJam << std::endl;
    std::cout << "Rose Hip Jam: " << numberOfRoseHipJam << std::endl;

    return 0;
}
//Зад.3
int main3()
{
    int a, b;
    std::cout << "Enter the interval [a,b] :";
    std::cin >> a >> b;
    if ( a > b )
    {
        std::cerr<<"Invalid interval a <= b"<<std::endl;
        return -1;
    }
    int previousNum;
    int currentNum;
    int sumOfInterestingNumbers = 0;
    //правим предположение, че всяко число е интересно до доказване на противното
    bool isInterestingNumber = true;
    int tempVar;
    for (int i = a; i <= b; i++)
    {
        //на всяко завъртане на цикъла сменяме временната променлива
        tempVar = i;
        //предишната цифра става последната на числото
        previousNum = tempVar % 10;
        //махаме последната
        tempVar /= 10;
        //и отделяме съседната
        currentNum = tempVar % 10;
        while (tempVar != 0)
        {
            //проверка за еднаква четност
            if ((previousNum % 2 == 0 && currentNum % 2 == 0) || (previousNum % 2 != 0 && currentNum % 2 != 0))
            {
                isInterestingNumber = false;
            }
            previousNum = currentNum;
            tempVar /= 10;
            currentNum = tempVar % 10;
        }
        if (isInterestingNumber)
            sumOfInterestingNumbers += i;
        isInterestingNumber = true;
    }
    std::cout << "sumOfInterestingNumbers = " << sumOfInterestingNumbers;
    return 0;
}

//ЗАД 4. Бикове и крави
const int MIN_NUMBER = 1234;
const int MAX_NUMBER = 9876;
int determineNumberOfBullsAndCows(int computerNumber, int playerNumber)
{
    int cowCounter = 0;
    int bullCounter = 0;
    int computerNumberArray[10];
    int playerNumberArray[10];
    //помощна променлива, която ни помага да отделим цифрите на числото правилно
    int powerOfTenHelper = 1000;
    for (int i = 0; i < 4; i++)
    {
        //понеже числата са четирицифрени при първата итерация на цикъла използваме само оператора '/'
        if (i == 0)
        {
            computerNumberArray[i] = computerNumber / powerOfTenHelper;
            playerNumberArray[i] = playerNumber / powerOfTenHelper;
        }
            //при всяка друга итерация използваме и двата оператора '/' и '%'
        else
        {
            computerNumberArray[i] = computerNumber / powerOfTenHelper % 10;
            playerNumberArray[i] = playerNumber / powerOfTenHelper % 10;
        }
        powerOfTenHelper /= 10;
    }
    //проверяваме дали има равни числа на една и съща позиция
    for (int i = 0; i < 4 ; i++)
    {
        if (playerNumberArray[i] == computerNumberArray[i])
        {
            bullCounter++;
        }
    }
    //тук проверяваме дали има две равни цифри на различни позиции
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 4 ; j++)
        {
            if(i != j && computerNumberArray[j] == playerNumberArray[i])
            {
                cowCounter++;
            }
        }
    }

    std::cout<< "Cows found: " << cowCounter << std::endl;
    std::cout<< "Bulls found: " << bullCounter;
    // връщаме броя на бикове, за да знаем, ако играта е приключила ( в случай на MAX_NUMBER_OF_BULLS бика)
    return bullCounter;

}

// помощна функция, с която определяме дали произволно генерираното число от компютъра е валидно
bool isNumberValid(int computerNumber)
{
    //разделяме различните цифри на числото на компютъра
    int thousands = computerNumber / 1000; //хилядни
    int hundreds = computerNumber / 100 % 10; //стотици
    int tens = computerNumber / 10 % 10; //десетици
    int ones = computerNumber % 10; //единици

    bool anyNumberIsZero = (thousands == 0) || (hundreds == 0) || (tens == 0) || (ones == 0);
    bool anyNumbersAreEqual = (thousands == hundreds) || (thousands == tens) || (thousands == ones) || (hundreds == tens) || (hundreds == ones) || (tens == ones);
    bool isNumberInCorrectBorders = computerNumber <= MAX_NUMBER && computerNumber >= MIN_NUMBER;

    //ако няма равни цифри, никое не е нула и числото е в интервала връщаме, че е валидно
    return !anyNumbersAreEqual && !anyNumberIsZero && isNumberInCorrectBorders;
}

// функция за генериране на произволно число за компютъра
int generateRandomNumber()
{
    //задаваме сийд за псевдо произволното число
    std::srand(time(0));
    //използваме псевдо произволни числа от 1234 до 9876
    int computerNumber = (rand() % MAX_NUMBER) + MIN_NUMBER;
    //ако генерираното число е валидно връщаме стойността му
    if (isNumberValid(computerNumber))
    {
        return  computerNumber;
    }
        //ако не е пускаме while цикъл и генерираме ново, докато не изпълнява условията на валидацията
    else
    {
        while (!isNumberValid(computerNumber))
        {
            computerNumber = (rand() % MAX_NUMBER) + MIN_NUMBER;
        }
        return computerNumber;
    }

}

int main()
{
    // задаваме максимален брой ходове за играча
    const int N = 8;
    const int MAX_NUMBER_OF_BULLS = 4;

    //задаваме си помощна променлива, с която да следим колко хода са минали
    int numberOfTurnsPassed = 0;
    int computerNumber;
    int playerNumber;

    //генерираме числото на компютъра
    computerNumber = generateRandomNumber();
    std::cout<< "The game has started!";
    while (numberOfTurnsPassed <= N)
    {
        std::cout<< std::endl;
        std::cout<< "Enter your number:";
        std::cin>> playerNumber;
        while (!isNumberValid(playerNumber))
        {
            std::cout<< "Invalid number entered!\nThe number must be between 1234 and 9876 and it must have four different digits." << std::endl;
            std::cout<< "Enter your number:";
            std::cin>> playerNumber;
        }
        //проверяваме колко бика има играча и ако те са MAX_NUMBER_OF_BULLS играта приключва
        if (determineNumberOfBullsAndCows(computerNumber, playerNumber) == MAX_NUMBER_OF_BULLS)
        {
            std::cout<< std::endl;
            std::cout<< "You win" << std::endl;

            return 0;
        }
        else
        {
            numberOfTurnsPassed++;
        }

    }
    //ако играчът не успее да познае числото на компютъра в рамките на N хода, той губи играта
    std::cout<< std::endl;
    std::cout<< "The number was: " << computerNumber << std::endl;
    std::cout<< "You could not guess the computer number in " << N << " turns!\nBetter luck next time!";

    return 0;
}








