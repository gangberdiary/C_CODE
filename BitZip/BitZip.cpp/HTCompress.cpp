#include "HTCompress.h"

HTCompress::HTCompress()
{
	charInfo_.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		charInfo_[i].ch_ = i;
		charInfo_[i].appearCount_ = 0;
	}

}

void HTCompress::CompressFile(const string& filePath)
{
	//打开文件
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "该文件路径出错！" << endl;
		return;
	}

	//统计有多少个字符
	uch readBuffer[1024];
	while (true)
	{
		size_t size = fread(readBuffer, 1, 1024, fIn);
		if (0 == size)
			break;

		for (size_t i = 0; i < size; ++i)
		{
			charInfo_[readBuffer[i]].appearCount_++;
		}
	}

	//创建哈夫曼树
	HuffumanTree<CharInfo> ht;
	ht.CreatHuffumanTree(charInfo_, CharInfo(0));

	//获取每个字符对应的编码
	GeneteCode(ht.GetRoot());

	//使文件指针回到起始位置
	rewind(fIn);

	//创建压缩文件
	FILE* fOut = fopen("compress.txt", "wb");

	WriteHeadInfo(fOut, filePath);

	//用获取到的编码对原文件进行压缩
	uch chData = 0;
	uch bitCount = 0;
	while (true)
	{
		size_t size = fread(readBuffer, 1, 1024, fIn);
		if (0 == size)
			break;

		for (int i = 0; i < size; ++i)
		{
			//找到对应字符的编码
			string& str_code = charInfo_[readBuffer[i]].strCode_;

			for (int j = 0; j < str_code.size(); ++j)
			{
				chData <<= 1;
				if (str_code[j] == '1')
					chData |= 1;

				bitCount++;
				if (8 == bitCount)
				{
					fputc(chData, fOut);
					bitCount = 0;
					chData = 0;
				}
			}
		}
	}

	if (bitCount > 0 && bitCount < 8)
	{
		chData <<= (8 - bitCount);
		fputc(chData, fOut);
	}

	fclose(fIn);
	fclose(fOut);
}

//走到叶子节点获取编码
void HTCompress::GeneteCode(HuffumanTreeNode<CharInfo>* root)
{
	if (nullptr == root)
		return;

	GeneteCode(root->left_);
	GeneteCode(root->right_);

	if (nullptr == root->left_ && nullptr == root->right_)
	{
		HuffumanTreeNode<CharInfo>* cur = root;
		HuffumanTreeNode<CharInfo>* parent = cur->parent_;

		string& str_code = charInfo_[cur->weight_.ch_].strCode_;
		while (parent)
		{
			if (cur == parent->left_)
				str_code += '0';
			else
				str_code += '1';

			cur = parent;
			parent = cur->parent_;
		}

		reverse(str_code.begin(), str_code.end());
	}
}

void HTCompress::WriteHeadInfo(FILE* fOut, const string& filePath)
{
	//获取文件后缀
	string fileEnd = filePath.substr(filePath.find('.'));
	fileEnd += "\n";

	//字符出现次数总行数
	size_t szCount = 0;

	//字符出现次数的信息，每个占一行
	string chAppear;
	for (size_t i = 0; i < 256; ++i)
	{
		if (0 != charInfo_[i].appearCount_)
		{
			chAppear += charInfo_[i].ch_;
			chAppear += ",";
			chAppear += to_string(charInfo_[i].appearCount_);
			chAppear += "\n";
			szCount++;
		}
	}

	fwrite(fileEnd.c_str(), 1, fileEnd.size(), fOut);

	string strCount;
	strCount = to_string(szCount);
	strCount += "\n";
	fwrite(strCount.c_str(), 1, strCount.size(), fOut);

	fwrite(chAppear.c_str(), 1, chAppear.size(), fOut);
}


void HTCompress::UNCompressFile(const string& filePath)
{
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "文件路径出错！" << endl;
		return;
	}

	//解压缩到的文件
	string filename("2");
	string s;
	GetLine(fIn, s);
	filename += s;

	//获取字节次数的总行数
	s = "";
	GetLine(fIn, s);
	size_t szCount = atoi(s.c_str());

	//读取字符次数的每行信息
	for (size_t i = 0; i < szCount; ++i)
	{
		s = "";
		GetLine(fIn, s);
		//换行符要单独处理
		if ("" == s)
		{
			s += "\n";
			GetLine(fIn, s);
		}
		charInfo_[(uch)s[0]].appearCount_ = atoi(s.c_str() + 2);
	}

	//还原哈夫曼树
	HuffumanTree<CharInfo> ht;
	ht.CreatHuffumanTree(charInfo_, CharInfo(0));

	//解压缩
	FILE* fOut = fopen(filename.c_str(), "wb");
	
	HuffumanTreeNode<CharInfo>* cur = ht.GetRoot();
	uch readBuffer[1024];
	size_t bitCount = 8;
	uch ch;
	ulg fileSize = cur->weight_.appearCount_;
	while (true)
	{
		size_t rdSize = fread(readBuffer, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)
		{
			bitCount = 8;
			ch = readBuffer[i];
			while (bitCount)
			{
				if (ch & 0x80)
					cur = cur->right_;
				else
					cur = cur->left_;

				if (nullptr == cur->left_ && nullptr == cur->right_)
				{
					fputc(cur->weight_.ch_, fOut);
					cur = ht.GetRoot();

					fileSize--;
					if (0 == fileSize)
						break;
				}

				bitCount--;
				ch <<= 1;
			}
		}
	}

	fclose(fIn);
	fclose(fOut);
 }

void HTCompress::GetLine(FILE* fIn, string& s)
{
	uch str;
	while (!feof(fIn))
	{
		str = fgetc(fIn);
		if ('\n' == str)
			break;

		s += str;
	}
}
