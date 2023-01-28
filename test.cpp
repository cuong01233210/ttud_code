#include <iostream>
#include <vector>
using namespace std;
unsigned int removeElement(unsigned int S, int x)
{
  return S & (~(1 << x));
}
int main()
{
  int S = 15;
  for (int j = 0; j < 4; j++)
  {
    cout << "Strc: " << S << " j: " << j << " Ssau: "<< removeElement(S, j) << endl;
  }
  
}