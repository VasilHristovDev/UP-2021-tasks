#include <iostream>
#include <cstring>


int countMaxSteps(const char * sequence, int currIndex )
{
    int counter = 0;

    while(sequence[currIndex] && sequence[currIndex] != 'r')
    {
        if(sequence[currIndex] == 'g')
        {
            counter++;
            currIndex++;
        }
        else if(sequence[currIndex] == 'y')
        {
            counter++;
            while(sequence[currIndex] != 'g' && sequence[currIndex])
            {
                currIndex++;
            }
            if(currIndex > strlen(sequence) - 1)
            {
                counter--;
            }
        }

    }
    return counter;
}
int main()
{
    const int MAX_CAPACITY = 1024;
    char sequence[MAX_CAPACITY];
    std::cout<<"Enter sequence of colors:";
    std::cin>>sequence;

    unsigned length = strlen(sequence);

    for (int i = 0; i < length ; ++i) {
        if(sequence[i] != 'r' && sequence[i]!= 'g' && sequence[i] != 'y')
        {
            std::cerr<<"Wrong data entered!"<<std::endl;
            return -1;
        }
    }
    int maxCounter = 0;
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        counter = countMaxSteps(sequence, i);
        if(counter > maxCounter)
            maxCounter = counter;
    }
    std::cout<<"Max number of steps is :"<<std::endl;
    std::cout<<maxCounter<<std::endl;

    return 0;

}
