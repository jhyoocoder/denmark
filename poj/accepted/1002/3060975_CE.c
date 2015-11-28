#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void Trim_PhoneNum(string &temp);
inline void Convert_Digital(char &p);

bool compare(const string left,const string right)
{
	return left < right;
}

void main()
{
	long int n = 0;
	cin >> n;
	string temp;
	vector<string> strpool;
	strpool.reserve(n);
	for(long int i=0;i<n;i++)
	{
		cin >> temp;
		//规格化处理
		Trim_PhoneNum(temp);
		//
		strpool.push_back(temp);
	}

	sort(strpool.begin(),strpool.end(),compare);
	
	long int j = 0;
	bool bFind = false;
	long int count = 1;
	
	while(j < n-1)
	{
		if(strpool[j] == strpool[j+1])
		{
			if(!bFind)
			{
				bFind = true;
			}
			
			count = 2;
			while(j++ < n-1)
			{
				if(strpool[j] == strpool[j+1])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			cout<<strpool[j++]<<" "<<count<<endl;
		}
		else
		{
			j++;
		}
	}
	
	if(!bFind)
	{
		cout << "No duplicates."<< endl;
	}
}

inline void Trim_PhoneNum(string &temp)
{
	const char *phone = temp.c_str();
	const char * p = phone;	

	char Temp[12] = "";
	char * q = Temp;
	int count = 0;
	while(*p != 0)
	{
		if(*p == '-')
		{
			p++;
		}
		else
		{
			count ++;			
			*q = *p;

			//变成数字形式
			Convert_Digital(*q);

			p++;
			q++;
		}
	}

	q++;
	while(count-- >= 3)
	{
		*q = *(q-1);
		q--;
	}
	*q = '-';
	temp = Temp;
}

inline void Convert_Digital(char &p)
{
	if(p >= 'a' && p <= 'z')
	{
		p -= 32;
	}

	if(p >= 'A' && p < 'Q')
	{
		p = (p - 'A')/3 + '2';
	}
	else if(p == 'R' || p == 'S')
	{
		p = '7';
	}
	else if(p >= 'T' && p < 'Z')
	{
		p = (p - 'T')/3 + '8';
	}
}
