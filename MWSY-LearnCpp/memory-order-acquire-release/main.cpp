#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<bool> x, y;
std::atomic<int> z;

int count1 = 0;
int count2 = 0;

void write_x()
{
	x.store(true, std::memory_order_release);
}

void write_y()
{
	y.store(true, std::memory_order_release);
}

void read_x_then_y()
{
	while (!x.load(std::memory_order_acquire));
	if (y.load(std::memory_order_acquire))
		++z;
}

void read_y_then_x()
{
	while (!y.load(std::memory_order_acquire));
	if (x.load(std::memory_order_acquire))
		++z;
}

int count = 0;

int main()
{
	for (int i = 0; i < 100000000; i++)
	{
		x = false;
		y = false;
		z = 0;
		std::thread a(write_x);
		std::thread b(write_y);
		std::thread c(read_x_then_y);
		std::thread d(read_y_then_x);
		a.join();
		b.join();
		c.join();
		d.join();
		//assert(z.load() != 0);
		int num = z.load();
		if (num != 0)
		{
			//count++;
			//std::cout << "num:" << num << std::endl;
			count++;
			if (num == 1)
			{
				count1++;
			}

			if (num == 2)
			{
				count2++;
			}
		}
		if (i % 1000000 == 0)
		{
			std::cout << i/1000000 << "%" << std::endl;
		}
	}
	std::cout << "the end count<" << count << ">" <<  std::endl;
	std::cout << "the end count1<" << count1 << ">" << std::endl;
	std::cout << "the end count2<" << count2 << ">" << std::endl;

}
