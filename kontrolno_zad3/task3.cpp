#include <iostream>
const int MAX_SIZE = 100;

// функция за завъртане на подмасива
// последния елемент става първи, а останалите елементи се изместват с една позиция напред
// Пример: 'j', 'o', 's' -> 's', 'j', 'o'
char * rotate(const char array[], int size)
{
    char* rotation = new char[MAX_SIZE];
    rotation[0] = array[size - 1];
    for (int j = 1; j < size ; j++)
    {
        rotation[j] = array[j - 1];
    }
    //връщаме указател към първия елемент на масива в паметта
    return rotation;
}
//Проверка дали даден масив е валидна ротация на друг
bool isValidRotationOfArray(const char array[], const char rotation[], int sizeArray)
{
    char checkArray[MAX_SIZE];
    int elementsOnTheSamePositionCounter = 0;
    char * pointerToRotation;

    for (int i = 0; i < sizeArray; i++)
    {
        if(array[i] == rotation[i])
            elementsOnTheSamePositionCounter++;
    }
    if(elementsOnTheSamePositionCounter == sizeArray)
        return true;

    for (int i = 0; i < sizeArray - 1; i++)
    {
        elementsOnTheSamePositionCounter = 0;
         pointerToRotation = rotate(rotation, sizeArray);
        for (int j = 0; j < sizeArray; j++)
        {
            checkArray[j] = *(pointerToRotation + j);
        }
        for (int j = 0; j < sizeArray; j++)
        {
            if(array[j] == checkArray[j])
                elementsOnTheSamePositionCounter++;
        }
        if(elementsOnTheSamePositionCounter == sizeArray)
        {
            delete pointerToRotation;
            return true;
        }

    }

    delete pointerToRotation;
    return false;
}
bool isSubArray( const char array[], char subarray[], int size1, int size2)
{
    int counterChecker;
    int index2;
    for (int i = 0; i < size1; i++)
    {
        counterChecker = 0;
        index2 = 0;
        for (int j = i; j < i + size2 ; j++)
        {
            if(array[j] == subarray[index2++])
            {
                counterChecker++;
            }
        }
        if(counterChecker == size2)
        {
            std::cout<<"Rotation '";
            for (int j = 0; j < size2 ; j++)
            {
                std::cout<<subarray[j];
            }
            std::cout<<"' found after deleting "<<i<<" characters from the start and "<<size1 - size2 - i <<" characters from the end"<<std::endl;
            return true;
        }
    }
    return false;
}

//Ако втория масив не е подмасив на първия проверяваме дали
//След изтриването на дадени елементи се получава валидна ротация на подмасива
bool isAnyRotation ( const char array[], const char subArray[], int size1, int size2)
{
    int counterOfRemovedIndexes = 0;
    //тук записваме ротацията на елементите в първия масив, съвпадащи на елементите от втория
    char rotation[MAX_SIZE];

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (array[i] == subArray[j])
            {
                rotation[counterOfRemovedIndexes++] = array[i];
            }
        }
    }
    if(isValidRotationOfArray(rotation, subArray, size2) && counterOfRemovedIndexes == size1 - size2)
    {
        std::cout<<"Rotation found '";
        for (int i = 0; i < counterOfRemovedIndexes ; i++)
        {
            std::cout<<rotation[i];
        }
        std::cout<<"' "<<std::endl;
        //Проверка кои са индексите, които трябва да се изтрият, за да се получи ротацията
        bool isRotationIndex = false;

        std::cout<<"Removed indexes ";
        for (int i = 0; i < size1; i++)
        {
            isRotationIndex = false;
            for (int j = 0; j < counterOfRemovedIndexes; j++)
            {
                if (array[i] == rotation[j])
                {
                    isRotationIndex = true;
                }
            }
            if(!isRotationIndex)
            {
                std::cout<<i<<" ";
            }
        }
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    char subArray [MAX_SIZE];
    char array [MAX_SIZE];
    
    int sizeArray;
    int sizeSubArray;
    
    std::cout<< "Size of array:";
    std::cin>>sizeArray;

    std::cout<< "Size of sub array:";
    std::cin>>sizeSubArray;
    //валидация
    if(sizeSubArray > sizeArray)
    {
        std::cerr<<"The size of sub array cannot be bigger than the size of the array!";
        return -1;
    }

    for (int i = 0; i < sizeArray ; i++)
    {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }
    //помощен масив, който ще ни помогне да проверим, ако втория масив не е подмасив на първия
    //дали някоя ротация на втория се съдържа в първия
    char checkAnyRotationArray[MAX_SIZE];
    bool foundSubArray = false;

    for (int i = 0; i < sizeSubArray ; i++)
    {
        std::cout<<"subArray["<<i<<"]:";
        std::cin>>subArray[i];
        checkAnyRotationArray[i] = subArray[i];
    }

    char* pointerToRotation;
    for (int i = 0; i < sizeSubArray - 1 ; i++)
    {
        pointerToRotation = rotate(subArray, sizeSubArray);
        for (int j = 0; j < sizeSubArray ; j++) {
            subArray[j] = *(pointerToRotation + j);
        }
        std::cout<<std::endl;
        if(isSubArray(array, subArray, sizeArray, sizeSubArray))
        {
            foundSubArray = true;
        }
    }
    if (!foundSubArray)
    {
       if(!isAnyRotation(array,  checkAnyRotationArray, sizeArray, sizeSubArray))
       {
           std::cout<<"No rotation found!"<<std::endl;
       }
    }
    delete pointerToRotation;
    return 0;
}
