#include <vector>
using namespace std;

template <class Comparable> 
void InsertionSort(vector<Comparable> &a)
{
    for (unsigned int p = 1; p < a.size(); p++)
    {
		Comparable tmp = a[p];
		int j;
		for (j = p; ((j > 0) && (tmp < a[j-1])); j--)
		{
		   a[j] = a[j-1];
		}
		a[j] = tmp;
    } 
}
