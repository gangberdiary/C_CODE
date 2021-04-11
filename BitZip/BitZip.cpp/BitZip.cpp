//#include "Huffuman.hpp"
#include "HTCompress.h"



void Test()
{
	HTCompress htc;
	htc.CompressFile("1.txt");
	htc.UNCompressFile("compress.txt");
}

int main()
{
	Test();
	return 0;
}