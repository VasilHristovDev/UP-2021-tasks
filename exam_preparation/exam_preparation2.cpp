#include <iostream>

bool isDone(int k)
{
    int sum = 0;
    for (int i = 1; i < k; ++i) {
        if(k % i == 0)
            sum+=i;
    }
    return k + 2 == sum;
}
bool sumMakesElement(int sequence[], int n, int element, int iterator)
{
    if(iterator >= n)
    {
        return false;
    }
    if(element == 0)
    {
        return true;
    }
    bool sumWith = sumMakesElement(sequence, n, element - sequence[iterator], iterator + 1);
    bool sumWithout = sumMakesElement(sequence, n, element, iterator + 1);

    return sumWith || sumWithout;
}
int main()
{
    int array[100];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    std::cout<<"Enter array:";
    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
    }
    int k;
    std::cout<<"Enter k:";
    std::cin>>k;

    std::cout<<sumMakesElement(array,n,k, 0)<<std::endl;


    return 0;
}