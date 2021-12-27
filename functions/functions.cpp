#include <iostream>
const int MAX_SIZE = 100;
void printPairs(const int array[], int size, int k)
{
    for (int i = 0; i < size ; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if(array[i] + array[j] == k)
            {
                std::cout<<"Pair "<<array[i]<<" and "<<array[j]<<" has a sum of "<<k<<std::endl;
            }
        }
    }
}
void addNumberOnPosition( int array[], int size, int k, int index)
{
    int helpArray[MAX_SIZE];
    for (int i = 0; i < size ; ++i) {
        helpArray[i] = array[i];
    }
    array[index] = k;
    size++;
    for (int i = 0; i < size ; ++i) {
        if(i >= index + 1)
        {
            array[i] = helpArray[i - 1];
        }

    }
    for (int i = 0; i < size ; ++i) {
        std::cout<<array[i]<<" ";
    }
}
void removeElementAtIndex(int array[], int size, int index)
{
    for (int i = 0; i < size ; ++i) {
        if(i == index)
        {
            size--;
            for (int j = index; j < size; ++j) {
                array[j] = array[j + 1];
            }
        }
    }
    for (int i = 0; i < size ; ++i) {
        std::cout<<array[i]<<" ";
    }
}
int main1()
{
    int array[MAX_SIZE];
    int size, k;
    std::cout<<"Enter size:";
    std::cin>>size;
    for (int i = 0; i < size ; ++i) {
        std::cout<<"Enter array["<<i<<"] =";
        std::cin>>array[i];
    }

    std::cout<<"Enter k:";
    std::cin>>k;
    printPairs(array, size, k);
    return 0;
}
int main2()
{
    int array[MAX_SIZE];
    int size, k, index;
    std::cout<<"Enter size:";
    std::cin>>size;
    for (int i = 0; i < size ; ++i) {
        std::cout<<"Enter array["<<i<<"] =";
        std::cin>>array[i];
    }

    std::cout<<"Enter k:";
    std::cin>>k;
    std::cout<<"Enter index:";
    std::cin>>index;
    addNumberOnPosition(array, size, k , index);
    return 0;
}

int main3()
{
    int array[MAX_SIZE];
    int size, index;
    std::cout<<"Enter size:";
    std::cin>>size;
    for (int i = 0; i < size ; ++i) {
        std::cout<<"Enter array["<<i<<"] =";
        std::cin>>array[i];
    }

    std::cout<<"Enter index:";
    std::cin>>index;
    removeElementAtIndex(array, size, index);
    return 0;
}

bool isSorted(const int array[], int size)
{
    bool bIsSortedASC = true;
    bool bIsSortedDSC = true;

    for (int i = 0; i < size ; ++i) {
        if(array[i] > array[i + 1] && i + 1 < size)
        {
            bIsSortedASC = false;
        }
    }

    for (int i = 0; i < size ; ++i) {
        if(array[i] < array[i + 1] && i + 1 < size)
        {
            bIsSortedDSC = false;
        }
    }

    return bIsSortedASC || bIsSortedDSC;

}
int main4()
{
    int array[MAX_SIZE];
    int size;
    std::cout<<"Enter size:";
    std::cin>>size;
    for (int i = 0; i < size ; ++i) {
        std::cout<<"Enter array["<<i<<"] =";
        std::cin>>array[i];
    }
    std::cout<<(isSorted(array, size)? "The array is sorted!": "The array is not sorted!")<<std::endl;
    return 0;
}
bool isSortedASC(const int array[], int size)
{
    bool bIsSortedASC = true;

    for (int i = 0; i < size ; ++i) {
        if(array[i] > array[i + 1] && i + 1 < size)
        {
            bIsSortedASC = false;
        }
    }
    return bIsSortedASC;
}
void addElement(int array[], int size, int k)
{
    int helpArray[MAX_SIZE];

    for (int i = 0; i < size ; ++i) {
        helpArray[i] = array[i];
    }
    for (int i = 0; i < size; ++i) {
        if(array[i] > k && array[i - 1] < k)
        {
            size++;
            array[i] = k;
            for (int j = i+1; j < size; ++j) {
                array[j] = helpArray[j-1];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        std::cout<<array[i]<<" ";
    }
}
int main5()
{
    int array[MAX_SIZE];
    int size, k;
    std::cout<<"Enter size:";
    std::cin>>size;
    for (int i = 0; i < size ; ++i) {
        std::cout<<"Enter array["<<i<<"] =";
        std::cin>>array[i];
    }

    if(!isSortedASC(array, size))
    {
        std::cerr<<"The array you entered is not sorted!"<<std::endl;
        return -1;
    }
    std::cout<<"Enter k:";
    std::cin>>k;
    addElement(array, size, k);
    return 0;
}
int merge( int array1[],  int array2[], int size1, int size2)
{
    int array3[MAX_SIZE + MAX_SIZE];
    int size3 = size1 + size2;

    for (int i = 0; i <size1 ; ++i) {
        array3[i] = array1[i];
    }
    int k = 0;
    int counterOfElementsCopiedFromTheSecondArray = 0;
    int counterOfElementsCopiedFromTheFirstArray = 0;
    for (int i = 0; i < size1 ; ++i) {
        if(counterOfElementsCopiedFromTheSecondArray == size2 || counterOfElementsCopiedFromTheFirstArray == size1)
            break;
        for (int j = i; j < size2 ; ++j) {
            if(array1[i] <= array2[j])
            {
                array3[k++] = array1[i];
                counterOfElementsCopiedFromTheFirstArray++;
                break;
            }
            else
            {
                counterOfElementsCopiedFromTheSecondArray++;
                array3[k++] = array2[j];
            }
        }
    }
    while(counterOfElementsCopiedFromTheFirstArray <= size1)
    {
        array3[k++] = array1[counterOfElementsCopiedFromTheFirstArray++];
    }
    while(counterOfElementsCopiedFromTheSecondArray <= size2)
    {
        array3[k++] = array2[counterOfElementsCopiedFromTheSecondArray++];
    }

    for (int i = 0; i <size3 ; ++i) {
        std::cout<<array3[i]<<" ";
    }
    std::cout<<std::endl;
    return size3;
}
int main6()
{
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];
    int size1, size2;

    std::cout<<"Enter the size of the first array:";
    std::cin>>size1;

    std::cout<<"Enter the size of the second array:";
    std::cin>>size2;

    for (int i = 0; i < size1; ++i) {
        std::cout<<"array1["<<i<<"] :";
        std::cin>>array1[i];
    }

    for (int i = 0; i < size2; ++i) {
        std::cout<<"array2["<<i<<"] :";
        std::cin>>array2[i];
    }

    if(!isSortedASC(array1, size1) || !isSortedASC(array2, size2))
    {
        std::cerr<<"The arrays you've entered are not sorted in ascending order"<<std::endl;
        return -1;
    }
    std::cout<<merge(array1, array2, size1, size2);
    return 0;
}
int findLongestAscSequence(const int array[], int size)
{
    int counter = 1;
    int maxSequence = 1;
    for (int i = 0; i < size; ++i) {
        if(array[i] <= array[i+1])
        {
            counter++;
        }
        else
        {
            if(maxSequence < counter)
                maxSequence = counter;

            counter = 1;
        }
    }
    return maxSequence;
}
int main()
{
    int array[MAX_SIZE];
    int size;

    std::cout<<"Enter array size:";
    std::cin>>size;

    for (int i = 0; i < size; ++i) {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }
    std::cout<<"The largest sequence of ascending elements is: "<<findLongestAscSequence(array, size);
    return 0;
}