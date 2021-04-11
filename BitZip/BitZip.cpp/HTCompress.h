#pragma once

#include "Huffuman.hpp"
#include <string>

typedef unsigned long long ulg;
typedef unsigned char uch;
struct CharInfo
{
	uch ch_;              //代表的字符
	ulg appearCount_;     //该字符出现的次数
	string strCode_;      //字符对应的编码

	CharInfo(ulg appearCount = 0)
		:appearCount_(appearCount)
	{}

	CharInfo operator+(const CharInfo& c)
	{
		return CharInfo(appearCount_ + c.appearCount_);
	}

	bool operator>(const CharInfo& c)const
	{
		return appearCount_ > c.appearCount_;
	}

	bool operator==(const CharInfo& c)const
	{
		return appearCount_ == c.appearCount_;
	}
};

class HTCompress
{
public:
	HTCompress();
	void GeneteCode(HuffumanTreeNode<CharInfo>* root);       //获取字符对应编码
	void CompressFile(const string& filePath);               //压缩文件
	void WriteHeadInfo(FILE* fOut, const string& filePath);  //记录压缩文件的后缀和字符出现次数等信息
	void UNCompressFile(const string& filePath);             //解压文件
	void GetLine(FILE* fIn, string& s);                      //获取一行字符

private:
	vector<CharInfo> charInfo_;
};