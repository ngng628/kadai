# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

// グローバル。注意
std::vector<int> primeNumbers;

int FindPrimeNumber(int max = 1000)
{
	std::vector<int> integers;
	
	for (int i = 2; i <= max; ++i)
	{
		integers.push_back(i);
	}
	
	
	for (int i = 0; i < integers.size(); ++i)
	{
		auto rmvIter = std::remove_if(integers.begin()+i+1,integers.end(),
			[&](int num){
				return (num % integers[i]) == 0;
			}
		);
		
		integers.erase(rmvIter, integers.end());
	}
	
	primeNumbers = integers;
	
	return 0;
}

int rad(int value)
{
	std::vector<int> primeFactors;
	
	const int primeNumbersSize = primeNumbers.size();
	for (int i = 0; i < primeNumbersSize; ++i)
	{
		if (value % primeNumbers[i] == 0)
		{
			while (value % primeNumbers[i] == 0)
			{
				value /= primeNumbers[i];
			}
			primeFactors.push_back(primeNumbers[i]);
			--i;
		}
	}
	
	int num_rad = 1;
	for(int i = 0; i < primeFactors.size(); ++i)
	{
		num_rad *= primeFactors[i];
	}
	
	return num_rad;
}

double quality(int a, int b, int c)
{
	return log(c) / log(rad(a*b*c));
}


int gcd(int a, int b)
{
	if(a % b == 0)
	{
		return b;
	}
	return gcd(b, a % b);
}

int main()
{
	FindPrimeNumber(10000);
	
	int a, b, c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	
	
	std::cout << quality(a, b, c);
	
	
	return 0;
}
