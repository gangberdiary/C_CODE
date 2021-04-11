#pragma once

#include "Huffuman.hpp"
#include <string>

typedef unsigned long long ulg;
typedef unsigned char uch;
struct CharInfo
{
	uch ch_;              //������ַ�
	ulg appearCount_;     //���ַ����ֵĴ���
	string strCode_;      //�ַ���Ӧ�ı���

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
	void GeneteCode(HuffumanTreeNode<CharInfo>* root);       //��ȡ�ַ���Ӧ����
	void CompressFile(const string& filePath);               //ѹ���ļ�
	void WriteHeadInfo(FILE* fOut, const string& filePath);  //��¼ѹ���ļ��ĺ�׺���ַ����ִ�������Ϣ
	void UNCompressFile(const string& filePath);             //��ѹ�ļ�
	void GetLine(FILE* fIn, string& s);                      //��ȡһ���ַ�

private:
	vector<CharInfo> charInfo_;
};