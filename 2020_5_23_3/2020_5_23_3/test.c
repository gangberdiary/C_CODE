#include <stdio.h>
#include <windows.h>

int main()
{
	for (int A = 1; A < 6; A++)
	{
		for (int B = 1; B < 6; B++)
		{
			for (int C = 1; C < 6; C++)
			{
				for (int D = 1; D < 6; D++)
				{
					for (int E = 1; E < 6; E++)
					{
						if ((((B == 2) + (A == 3) == 1)
							&& ((B == 2) + (E == 4) == 1)
							&& ((C == 1) + (D == 2) == 1)
							&& ((C == 5) + (D == 3) == 1)
							&& ((E == 4) + (A == 1) == 1))
							&& (A * B * C * D * E == 120))
						{
							printf("A = %d B = %d C = %d D = %d E = %d", A, B, C, D, E);
							printf("\n");
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}