#include <iostream>
#include <cstdlib>
#include <algoritm>

typedef struct 
{
		double carat;
		double price;
} DIAMOND;

template<typename T, std::size_t N, typename Func>
double mean_carat(const T(&values)[N] values, typename Func);

int main(int argc, char** argv)
{
	DIAMOND values[10] = {
		{300.0, 339.0}, {410.0, 561.0}, {750.0, 2760.0}, {910.0, 2763.0}, {1200.0, 2809.0},
		{1310.0, 3697.0}, {1500.0, 4022.0}, {1740.0, 4677.0}, {1960.0, 6147.0}, {2210.0, 6535.0}
	};
	
	auto getCarat = [](const DIAMOND& diamond) { return diamond.carat; };
	double value_mean_carat = mean(values, getCarat);
	std::cout << "Mean Carat: " << value_mean_carat << std::endl;
	
	return EXIT_SUCCESS;
}

template<typename T, std::size_t N, typename Func>
double mean(const T(&values)[N], Func extractor)
{
	if (N == 0) return 0.0;
	
	double sum = 0.0;
	for (const auto& item: values) {
		sum += extractor(item);
	}
	
	return sum / N;
}

/*double mean_carat(DIAMOND* values, size_t size)
{
		if (size == 0) return 0.0;
		
		double ret = 0.0;
		
		for (size_t i = 0; i < size; ++i) {
			ret += values[i].carat;
		}
		
		return ret / (double) size;
		
}*/



