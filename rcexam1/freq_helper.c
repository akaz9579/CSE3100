#include <assert.h>

unsigned firstDigit(unsigned k)
{
    int digit = k;
    while (digit >=10)
    {
        digit = (int)digit/10;
    }
    return digit;

}

void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{
    int num =0;
    for(int i = 0; i<10; i++)
    {
        freq[i] = 0;
    }
    for(int j = 0; j<n; j++)
    {
        num = firstDigit(a[j]);
        freq[num] = freq[num] + 1;
    }
}