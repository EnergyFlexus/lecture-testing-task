#include <iostream>
#include <chrono>

#include "../src/stack.h"

int main(int argc, char* argv[])
{
	Stack stack;
	initStack(&stack);

	const int data = 1;
	const size_t steps = 7;
	size_t limit = 10;

	for (size_t s = 0; s < steps; ++s)
	{
		std::chrono::time_point<std::chrono::steady_clock> start_time;
		std::chrono::time_point<std::chrono::steady_clock> end_time;
		std::chrono::milliseconds elapsed;

		std::cout << "Pushing "<< limit << " elements in stack" << std::endl;

		start_time = std::chrono::steady_clock::now();
		for (size_t i = 0; i < limit; ++i) push(&stack, data);
		end_time = std::chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		std::cout << "Time is " << elapsed.count() << " ms" << std::endl;

		std::cout << "Popping "<< limit << " elements from stack" << std::endl;

		start_time = std::chrono::steady_clock::now();
		for (size_t i = 0; i < limit; ++i) pop(&stack);
		end_time = std::chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		std::cout << "Time is " << elapsed.count() << " ms" << std::endl;

		limit *= 10;
		std::cout << std::endl;
	}
	destroyStack(&stack);
	return 0;
}