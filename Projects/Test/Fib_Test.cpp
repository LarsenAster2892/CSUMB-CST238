#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>

long double fib(double n);
char wait;
void main()
{
	double intNumber;
    long double dblNumber;

	cout <<" Enter number to calculate Fib for :";
	cin >> intNumber;
	cout <<endl;
	cout <<" The "<<intNumber<<" Fib is ";
	dblNumber = fib(intNumber);
	cout <<setiosflags( ios::fixed )<<  dblNumber;
	cout <<endl;


}
long double fib(double n)
{
    if ((n==0)||(n==1))
		return 1;

	{
		long double prev_minus_1 = 1;
		long double prev_minus_2 = 0;
		long double new_value = 0;

		for (double x = 2; x <= n; x++)
		{
		new_value = prev_minus_1 + prev_minus_2;
		prev_minus_2 = prev_minus_1;
		prev_minus_1 = new_value;
		}
		return new_value;
	}
}