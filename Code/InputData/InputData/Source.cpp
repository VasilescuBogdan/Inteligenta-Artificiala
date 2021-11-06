#include <fstream>

int main()
{
	std::ofstream f("Date10.in");
	srand(time(NULL));

	for (int i = 1; i <= 23; i++)
	{
		f << rand() % 200 + 1;
		f << std::endl;
	}

	for (int i = 1; i <= 2; i++)
	{
		f << rand() % 20;
		f << std::endl;
	}

	f.close();
	

	return 0;
}