/*	Created by Mark Brown
 *	On 11/3/2019
 *	To practice getting array sizes as const during compilation
 *
 */
 
#include <iostream>
#include <array>

template<class T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {	return N;	};


int main(int argc, char* argv[]){

	int keyVals[] = { 1, 2, 3, 7, 9, 11, 22, 35};
	
	int mappedVals[arraySize(keyVals)];
	
	std::array<int, arraySize(keyVals)> mappedVals2;
	
	
	std::cout << "Number of mappedVals: " << arraySize(mappedVals) << std::endl;
	std::cout << "Number of mappedVals2: " << mappedVals2.size() << std::endl;
	
	
	// declares x as std::initializer_list<int> -> This must then be allowed because initializer_list must be part of STD namespace...
	auto x = {27};
	
	for (auto tmp : x)
		std::cout << "Inilializer-list x has value of " << x[0] << " of size " << x.size() <<std::endl;
	
	return 0;
}