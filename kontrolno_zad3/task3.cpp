#include <iostream>
bool isARotation( const char array[], char subarray[], int size1, int size2)
{
    int counterChecker = 0;
    int index2 = 0;
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
const int MAX_SIZE = 100;
void isAnyRotation ( char array[], const char subArray[], int size1, int size2)
{
    int counterOfRemovedIndexes = 0;
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
    std::cout<<"Rotation found '";
    for (int i = 0; i < counterOfRemovedIndexes ; i++)
    {
        std::cout<<rotation[i];
    }
    std::cout<<"' "<<std::endl;
    bool itContains = false;
    std::cout<<"Removed indexes ";
    for (int i = 0; i < size1; i++)
    {
        itContains = false;
        for (int j = 0; j < counterOfRemovedIndexes; j++)
        {
            if (array[i] == rotation[j])
            {
                itContains = true;
            }
        }
        if(!itContains)
        {
            std::cout<<i<<" ";
        }
    }
    std::cout<<std::endl;

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
    char copyArray[MAX_SIZE];
    bool foundSubArray = false;
    for (int i = 0; i < sizeSubArray ; i++)
    {
        std::cout<<"subArray["<<i<<"]:";
        std::cin>>subArray[i];
        copyArray[i] = subArray[i];
    }

    for (int i = 0; i < sizeSubArray - 1 ; i++)
    {
        for (int j = 0; j < sizeSubArray ; j++)
        {
            if(j == 0)
            {
                subArray[j] = copyArray[sizeSubArray - 1];
            }
            else
            {
                subArray[j] = copyArray[j - 1];
            }

            std::cout<<subArray[j]<<" ";
        }
        for (int j = 0; j < sizeSubArray ; j++)
        {
            copyArray[j] = subArray[j];
        }
        std::cout<<std::endl;
        if(isARotation(array, subArray, sizeArray, sizeSubArray))
        {
            foundSubArray = true;
        }

    }
    if (!foundSubArray)
    {
        std::cout<<"No rotation found!"<<std::endl;
        isAnyRotation(array, subArray, sizeArray, sizeSubArray);
    }
    return 0;
    
}
