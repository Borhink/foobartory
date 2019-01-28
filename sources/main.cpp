#include <ctime>
#include <chrono>
#include <thread>

#include "Factory.h"

#define UPS (1.0f / 60.0f)

int main ()
{
	srand((unsigned)time(0));

	Factory oFactory;

	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	float elapsed = 0.0f;
	float total = 0.0f;

	while (1)
	{
		begin = std::chrono::high_resolution_clock::now();
		if (oFactory.Update(elapsed))
			break;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		end = std::chrono::high_resolution_clock::now();
		auto dur = end - begin;
		elapsed = static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()) / 1000.0f;
		total += elapsed;
	}
	printf("Time : %fs", total);
}