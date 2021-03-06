

#ifndef _IDF_HPP
#define _IDF_HPP

#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <utility>
#include <stdlib.h>
using namespace std;

class IDF
{
public:
	IDF(const string path)
	{
		ifstream ifs(path.c_str(),ios::in);
		string line;
		string str;
		pair<string,double> p;
		while(getline(ifs,line),!ifs.eof())
		{
			istringstream iss(line);
			int pos = 0;
			while(iss>>str)
			{
				if(pos == 0)
				{
					p.first = str;	
				}
				else if(pos == 1)
				{
					p.second = atof(str.c_str());
				}
				pos++;
			}
			idf_.insert(p);
		}
		ifs.close();
	}

	double idf(string word)
	{
		double ret = 0;//如果idf_中不存在，默认返回0
		map<string,double>::iterator pos;
		pos = idf_.find(word);
		if(pos!=idf_.end())
			ret = pos->second;
		return ret;
	}

private:
	map<string,double> idf_;
};
#endif
