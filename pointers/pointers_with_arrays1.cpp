#include <iostream>

bool isPositive(int number)
{
    return number > 0;
}
int getSmallerNumber(int num1, int num2)
{
    return num1 > num2 ? num2 : num1 ;
}
void printAllNumbersInInterval(int a, int b)
{
    std::cout<<"Numbers in interval [a,b]: "<<std::endl;
    for (int i = a; i <= b ; i++)
    {
        std::cout<<i<<'\t';
    }
    std::cout<<std::endl;
}
const int MAX_SIZE = 100;
int getSmallestNumberInArray(const int array[MAX_SIZE], int n)
{
    int min = array[0];
    for (int i = 1; i < n ; i++)
    {
        if (min > array[i])
            min = array[i];
    }
    return min;
}

int main0()
{
    int positive;
    std::cout<<"Enter a number to check if it is positive or not:";
    std::cin>>positive;
    std::cout<<"The number :"<<positive<<" is"<<(isPositive(positive) ? "" : " not")<<" positive"<<std::endl;
    int num1, num2;
    std::cout<<"Enter two numbers for comparison:";
    std::cin>>num1>>num2;
    std::cout<<"The smaller number "<<getSmallerNumber(num1, num2)<<std::endl;
    int a,b;
    std::cout<<"Enter two numbers to see the numbers between them in the interval:";
    std::cin>>a>>b;
    printAllNumbersInInterval(a,b);
    int array[MAX_SIZE];
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;
    if(n >= MAX_SIZE)
    {
        std::cerr<<"The size exceeds the MAX_SIZE constant!";
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout<<"array["<<i<<"] =";
        std::cin>>array[i];
    }
    std::cout<<"The smallest number in array is: "<<getSmallestNumberInArray(array,n);
    return 0;
}
void printAllNumbersThatHaveSumOfK(const int array[MAX_SIZE], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(array[i] + array[j] == k)
                std::cout<<array[i]<<' '<<array[j]<<std::endl;
        }
    }
}
int main1()
{
    int array[MAX_SIZE];
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;

    if(n >= MAX_SIZE)
    {
        std::cerr<<"The size exceeds the MAX_SIZE constant!";
        return -1;
    }

    for (int i = 0; i < n ; i++)
    {
        std::cout<<"array["<<i<<"] =";
        std::cin>>array[i];
    }

    int k;
    std::cout<<"Enter k:";
    std::cin>>k;

    printAllNumbersThatHaveSumOfK(array,n,k);

    return 0;
}
int* putANumberOnPositionWithIndex(const int array[MAX_SIZE], int &n, int k, int position)
{
    int returnableArray[MAX_SIZE];
    for (int i = 0; i < n ; i++)
    {
        returnableArray[i] = array[i];
    }
    for (int i = 0; i < n ; i++)
    {
        if (i == position)
        {
            n++;
            returnableArray[position] = k;
            for (int j = position + 1; j < n ; j++)
            {
                returnableArray[j] = array[j-1];
            }
            return returnableArray;
        }
    }

    return nullptr;
}

int main2()
{
    int array[MAX_SIZE];
    int n, position, k;
    std::cout<<"Enter array size:";
    std::cin>>n;

    std::cout<<"Enter number to add to the array:";
    std::cin>>k;

    std::cout<<"Enter position:";
    std::cin>>position;

    for (int i = 0; i < n ; i++)
    {
        std::cout<<"array["<<i<<"] =";
        std::cin>>array[i];
    }
    int *pointerToArray = putANumberOnPositionWithIndex(array,n, k, position);
    int returnedArray[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        returnedArray[i] = *(pointerToArray + i);
    }
    for (int i = 0; i < n ; i++)
    {
        std::cout<<returnedArray[i]<<' ';
    }
    return 0;
}

int* removeElementOnIndex(const int array[MAX_SIZE], int &size, int position)
{
    int returnableArray[MAX_SIZE];
    for (int i = 0; i < size; i++)
    {
        returnableArray[i] = array[i];
    }
    for (int i = 0; i < size ; i++)
    {
        if(i == position)
        {
            size--;
            for (int j = position; j < size; j++)
            {
                returnableArray[j] = returnableArray[j + 1];
            }
            return  returnableArray;
        }
    }
    return nullptr;
}

int main3()
{
    int array[MAX_SIZE];
    int n, position, k;
    std::cout<<"Enter array size:";
    std::cin>>n;

    std::cout<<"Enter position:";
    std::cin>>position;

    for (int i = 0; i < n ; i++)
    {
        std::cout<<"array["<<i<<"] =";
        std::cin>>array[i];
    }
    int *pointerToArray = removeElementOnIndex(array,n, position);
    int returnedArray[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        returnedArray[i] = *(pointerToArray + i);
    }
    for (int i = 0; i < n ; i++)
    {
        std::cout<<returnedArray[i]<<' ';
    }
    return 0;
}
bool checkIfIsMonotonous(const int array[MAX_SIZE], int size)
{
    bool isMonotonousInAscendingRow = true;
    bool isMonotonousInDescendingRow = true;
    for (int i = 0; i < size-1 ; i++)
    {
        if(array[i] > array[i + 1])
        {
            isMonotonousInAscendingRow = false;
        }
    }
    for (int i = 0; i < size - 1 ; i++)
    {
        if(array[i] < array[i + 1])
        {
            isMonotonousInDescendingRow = false;
        }
    }
    return  isMonotonousInAscendingRow || isMonotonousInDescendingRow;

}
int main4()
{
    int array[MAX_SIZE];
    int size;
    std::cout<<"Array size:";
    std::cin>>size;

    for (int i = 0; i < size; i++)
    {
        std::cout<<"array["<<i<<"]=";
        std::cin>>array[i];
    }
    std::cout<<(checkIfIsMonotonous(array,size) ? "It is sorted!" : "It is not sorted!")<<std::endl;
    return 0;
}
//зад. 5
int* putNumberInSortedArray(const int array[MAX_SIZE], int &size, int k)
{
    int newArray[MAX_SIZE];
    for (int i = 0; i < size ; ++i) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < size; i++)
    {
        if(newArray[i] >= k)
        {
            size++;
            newArray[i] = k;
            for (int j = i + 1; j < size; j++)
            {
                newArray[j] = array[j-1];
            }
            return newArray;
        }

    }

    newArray[size] = k;
    size++;
    return newArray;
}

bool isMonotonous(const int array[MAX_SIZE], int size)
{
    bool isMonotonousInAscendingRow = true;
    for (int i = 0; i < size-1 ; i++)
    {
        if(array[i] > array[i + 1])
        {
            isMonotonousInAscendingRow = false;
            return isMonotonousInAscendingRow;
        }
    }
    return isMonotonousInAscendingRow;
}

int array[100];
void readArray(int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout<<"array["<<i<<"]=";
        std::cin>>array[i];
    }
}
void printArray(int size)
{
    for (int i = 0; i < size ; i++)
    {
        std::cout<<array[i]<<' ';
    }
}

int main5()
{
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;
    readArray(n);

    int k;
    std::cout<<"Enter a number to be added:";
    std::cin>>k;

    if (!isMonotonous(array,n))
    {
        std::cerr<< "The given array is not sorted in ascending order" <<std::endl;
        //Ако връщаме на потребителя -1, показваме, че има грешка при входните данни
        return -1;
    }

    int *pointerToNewArray = putNumberInSortedArray(array,n, k);
    for (int i = 0; i < n ; i++)
    {
        array[i] = *(pointerToNewArray + i);
    }

    printArray(n);
    return 0;
}
int* merge(const int array1[MAX_SIZE],const  int array2[MAX_SIZE], int size1, int size2)
{
    int* sortedArray = new int [size1 + size2];

    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2 )
    {
        if(array1[i] < array2[j])
            sortedArray[k++] = array1[i++];
        else
            sortedArray[k++] = array2[j++];
    }
    while (i < size1)
        sortedArray[k++] = array1[i++];

    while (j < size2)
        sortedArray[k++] = array2[j++];

    return sortedArray;
}
int main()
{
    int array1[MAX_SIZE], array2[MAX_SIZE];
    int size1, size2;
    std::cout<<"Size 1:";
    std::cin>>size1;

    std::cout<<"Size 2:";
    std::cin>>size2;

    for (int i = 0; i < size1; i++)
    {
        std::cout<<"array1["<<i<<"]:";
        std::cin>>array1[i];
    }

    for (int i = 0; i < size2 ; i++)
    {
        std::cout<<"array2["<<i<<"]:";
        std::cin>>array2[i];
    }
    //Валидация дали масивите са монотонно растящи редици
    if (!isMonotonous(array1, size1))
    {
        std::cerr<<"Array1 is not monotonously growing"<<std::endl;
        return -1;
    }
    if (!isMonotonous(array2, size2))
    {
        std::cerr<<"Array2 is not monotonously growing"<<std::endl;
        return -1;
    }

    int* thirdArray = merge(array1, array2, size1, size2);

    std::cout<<"The size of the new arrays is: "<<size1 + size2<<std::endl;
    std::cout<<"And the new sorted array looks like:"<<std::endl;
    for (int i = 0; i < size1 + size2; i++)
    {
        std::cout<<*(thirdArray + i)<<" ";
    }
    delete thirdArray;
    thirdArray = nullptr;

    return 0;
}
int* findTheLongestSequence(const int array1[MAX_SIZE], int size)
{
    int sequence[MAX_SIZE];
    int counter = 1;
    int maxCounter = 1;
    int endingIndex;

    for (int i = 0; i < size ; i++)
    {
        if (array1[i] <= array1[i + 1])
        {
            counter++;
        }
        else
        {
            if(counter > maxCounter)
            {
                maxCounter = counter;
                endingIndex = i - 1;
            }
            counter = 1;
        }
    }
    int j = 0;
    for (int i = endingIndex - maxCounter; i < maxCounter; i++)
    {
        sequence[j] = array1[i];
        j++;
    }
    return sequence;
}
int main6()
{
    int array1[MAX_SIZE];
    int size;
    std::cout<<"Enter size:";
    std::cin>>size;

    for (int i = 0; i < size ; i++)
    {
        std::cout<<"array1["<<i<<"]=";
        std::cin>>array1[i];
    }

    int sequenceArray[MAX_SIZE];
    int* pointerToSequenceArray = findTheLongestSequence(array1, size);

    for (int i = 0; i < 3; i++)
    {
        sequenceArray[i] = *(pointerToSequenceArray + i);
        std::cout<<sequenceArray[i]<<" ";
    }
    return 0;
}


