#include <iostream>
#include <exception>
#include <thread>
#include <chrono>
#include <string>
import runtime;
int main()
{
	try
	{
		auto fn = [](double t)
			{
				std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<60>>(t));
				return std::string{ " (sec) passed.\n" };
			};
		auto [r, dt] = runtime(fn, 1.5);
		std::cout << "\n\t" << dt << r << std::endl;
		return 0;
	}
	catch (const std::exception& xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return 1;
	}
}