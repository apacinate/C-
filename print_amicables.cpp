#include <iostream>
#include <set>
#include <cmath>
int limit;


int sum_proper_divisors(int const number)
{
	int result = 1;
	int const root = static_cast<int>(std::sqrt(number));
	for (int i = 2; i <= root; i++)
	{
		if (number % i == 0)
		{
			result += (i == (number / i)) ? i : (i + number / i);
		}
	}
	return result;
}

void print_amicables(int const limit)
{
	for (int number = 4; number < limit; ++number)
	{
		if (auto sum1 = sum_proper_divisors(number)) {
			if (sum1 < limit){
				if (auto sum2 = sum_proper_divisors(sum1)){
					if(sum2 == number && number != sum1){
						std::cout << number << "," << sum1 << std::endl;
					}
				}	
			}
		}
	}
}

void print_amicables_once(int const limit)
{
	std::set<int> printed;
	for (int number = 4; number < limit; ++number)
	{
		if (printed.find(number) != printed.end()) continue;

		auto sum1 = sum_proper_divisors(number);

		if (sum1 < limit)
		{
			auto sum2 = sum_proper_divisors(sum1);

			if (sum2 == number && number != sum1)
			{
				printed.insert(number);
				printed.insert(sum1);

				std::cout << number << "," << sum1 << std::endl;
			}
		}
	}
}

int main(){
	std::cout << "Upper limit:";
	std::cin >> limit;
	print_amicables(limit); 
	print_amicables_once(limit);
}


