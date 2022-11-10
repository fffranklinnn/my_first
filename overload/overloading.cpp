#include<math.h>
#include<iostream>
#include<string>
using namespace std;
class Integer {
	int value;
public:
	Integer(void) { this->value = 0; }
	Integer(int v = 0)
	{
		this->value = v;
	}
	Integer(float d = 0.0)
	{
		this->value = (int)d;
	}
	Integer(const char* c_str)
	{
		value = atoi(c_str);
	}
	Integer(const string& str)
	{
		value = atoi(str.c_str());
	}
	Integer(const Integer& rhs)
	{
		this->value = rhs.value;
	}
	Integer& operator=(const Integer& rhs)
	{
		this->value = rhs.value;
		return *this;
	}
	Integer& operator=(int rhs)
	{
		this->value = rhs;
		return *this;
	}
	string toString() const
	{
		return to_string(this->value);
	}
	int  intValue() const
	{
		return this->value;
	}
	operator int() const
	{
		return this->value;
	}
	operator double() const
	{
		return (double)this->value;
	}
	operator char()  const
	{
		return (char)this->value;
	}
	int cmp(const Integer& rhs)
	{
		if (this->value > rhs.value)
		{
			return 1;
		}
		else if (this->value == rhs.value)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	bool operator==(const Integer& rhs)
	{
		return (this->value == rhs.value);
	}
	bool operator!=(const Integer& rhs)
	{
		return !(this->value == rhs.value);
	}
	bool operator>(const Integer& rhs)
	{
		return (this->value > rhs.value);
	}
	bool operator>=(const Integer& rhs)
	{
		return (this->value >= rhs.value);
	}
	bool operator<(const Integer& rhs)
	{
		return (this->value < rhs.value);
	}
	bool operator<=(const Integer& rhs)
	{
		return (this->value <= rhs.value);
	}
	static int parse(const char* c_str)
	{
		return atoi(c_str);
	}
	static int parse(const std::string& str) 
	{
		return parse(str.c_str());
	}
	Integer& operator+=(Integer rhs)
	{
		this->value += rhs.value;
		return *this;
	}
	Integer& operator+=(int v)
	{
		this->value += v;
		return *this;
	}
	Integer& operator-=(Integer rhs)
	{
		this->value -= rhs.value;
		return *this;
	}
	Integer& operator-=(int v)
	{
		this->value -= v;
		return *this;
	}
	Integer& operator*=(Integer rhs)
	{
		this->value *= rhs.value;
		return *this;
	}
	Integer& operator*=(int v)
	{
		this->value *= v;
		return *this;
	}
	Integer& operator/=(Integer rhs)
	{
		if (rhs.value == 0)
		{
			cout << "error!½ûÖ¹³ıÁã" << endl;
			system("pause");
			exit(-1);
		}
		this->value /= rhs.value;
		return *this;
	}
	Integer& operator/=(int v)
	{
		if (v == 0)
		{
			cout << "error!½ûÖ¹³ıÁã" << endl;
			system("pause");
			exit(-1);
		}
		this->value /= v;
		return *this;
	}
	Integer& operator+(Integer rhs)
	{
		this->value += rhs.value;
		return *this;
	}
	Integer& operator-(Integer rhs)
	{
		this->value -= rhs.value;
		return *this;
	}
	Integer& operator++()
	{
		*this+=1;
		return *this;
	}
	Integer& operator--()
	{
		*this-=1;
		return *this;
	}
	friend Integer operator + (Integer& a, Integer& b)
	{
		return Integer(a.value + b.value);
	}
	friend Integer operator + (Integer& a, int b)
	{
		return Integer(a.value + b);
	}
	friend Integer operator + (int a, Integer& b)
	{
		return Integer(a + b.value);
	}

	friend Integer operator - (Integer& a, Integer& b)
	{
		return Integer(a.value - b.value);
	}
	friend Integer operator - (Integer& a, int b)
	{
		return Integer(a.value - b);
	}
	friend Integer operator - (int a, Integer& b)
	{
		return Integer(a - b.value);
	}

	friend Integer operator * (Integer& a, Integer& b)
	{
		return Integer(a.value + b.value);
	}
	friend Integer operator * (Integer& a, int b)
	{
		return Integer(a.value * b);
	}
	friend Integer operator * (int a, Integer& b)
	{
		return Integer(a * b.value);
	}

	friend Integer operator / (Integer& a, Integer& b)
	{
		if (b.value == 0)
		{
			cout << "error!½ûÖ¹³ıÁã" << endl;
			system("pause");
			exit(-1);
		}
		return Integer(a.value / b.value);
	}
	friend Integer operator / (Integer& a, int b)
	{
		if (b == 0)
		{
			cout << "error!½ûÖ¹³ıÁã" << endl;
			system("pause");
			exit(-1);
		}
		return Integer(a.value / b);
	}
	friend Integer operator / (int a, Integer& b)
	{
		if (b.value == 0)
		{
			cout << "error!½ûÖ¹³ıÁã" << endl;
			system("pause");
			exit(-1);
		}
		return Integer(a / b.value);
	}

	friend ostream& operator << (ostream& output, const Integer& v)
	{
		output << v.value << endl;
		return output;
	}
	friend istream& operator >> (istream& input, Integer& v)
	{
		input >> v.value;
		return input;
	}
};
int main()
{
	Integer a = Integer(1);
	Integer b=a;
	Integer c("0");
	b = 123;
	cout << a;
	cout << b ;
	cout << c;
	cout << a.cmp(b)<<endl;
	cout << a.cmp(c)<<endl;
	a += b;
	cout << a;
	a*=3;
	cout << a;
	b *= a;
	cout << b;
	Integer d = a / c;
	//cout << d;
	return 0;
}