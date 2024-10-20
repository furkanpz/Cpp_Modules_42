#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Contructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter Copy Contructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter Copy Assigment Contructor Called!" << std::endl;
	(void)other;
	return *this;	 
}

static void InvalidArg(void)
{
	std::cerr << "Invalid Arguments" << std::endl;
}

static void IsChar(char c)
{
	std::cout << "Char: ";
	if (std::isprint(c))
		std::cout << "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "int: " << (static_cast<int>(c)) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(c)) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(c)) << std::endl;
}

static void IsSpecial(std::string &str)
{
	if (!str.compare("+inff") || str.compare("-inff"))
	{
		std::cout << "Char: imposibble" << std::endl;

	}
}

static bool IsInt(const std::string &str)
{
	long i;
	char *c;

	if (str.length() < 12)
	{
		if (str[0] == '-' || str[0] == '+' || std::isdigit(str[0]))
		{
			for (size_t i = 1; i < str.length(); i++)
			{
				if (!std::isdigit(str[i]))
					return (false);
			}
			i = std::strtol(str.c_str(), &c, 10);
			if (i >= INT_MIN && i <= INT_MAX)
				return (true);
		}
	}

	return (false);
}

static bool IsFloat(const std::string &str)
{
	int dot = 0;
	float b;

	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return (true);
	if (str.length() < 2)
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dot += 1;
	}
	if (dot != 1 || str[str.length() - 1] != 'f')
		return (false);
	if (str[0] == '-' || str[0] == '+' || std::isdigit(str[0]))
	{
		for (size_t i = 1; i < str.length() - 1; i++)
		{
			if (!std::isdigit(str[i]) && (str[i] != '.' && std::isdigit(str[i - 1])))
				return (false);
		}
		b = std::atof(str.c_str());
		if (b < std::numeric_limits<float>::lowest() || b > std::numeric_limits<float>::max())
            return false;
		return true;
	}
	return false;
}

static bool IsDouble(const std::string &str)
{
	double	db;
	int		dot = 0;

	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return (true);
	if (str.length() < 2)
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dot += 1;
	}
	if (dot != 1)
		return (false);
	if (str[0] == '-' || str[0] == '+' || std::isdigit(str[0]))
	{
		for (size_t i = 1; i < str.length() - 1; ++i)
		{
			if (!std::isdigit(str[i]) && (str[i] != '.' && std::isdigit(str[i - 1])))
				return (false);
		}
		if (db < std::numeric_limits<double>::lowest() || db > std::numeric_limits<double>::max())
			return (false);
		return (true);
	}
	return (false);
}

static void IsIntPrint(int i)
{
	{
	std::cout << "char: ";
	if (i >= 0 && i < 256 && isprint(i))
		std::cout << "\'" << (static_cast<char>(i)) << "\'" << std::endl;
	else if (i < 256)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(i)) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(i)) << std::endl;
}
}

static void IsFloatPrint(float f)
{
	std::cout << "Char: ";
	if (f >= 0 && f < 256 && static_cast<int>(f) - f == 0.0 && std::isprint(f))
		std::cout << "\'" << (static_cast<char>(f)) << "\'" << std::endl;
	else if (f < 256 && floor(f) == f)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (static_cast<double>(f) >= INT_MIN && static_cast<double>(f) <= INT_MAX)
		std::cout << (static_cast<int>(f)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (f == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: +" << f << "f" << std::endl;
	else if (static_cast<int>(f) - f == 0.0)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(7) << "float: " << f << "f" << std::endl;
		if (f == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "double: +" << (static_cast<double>(f)) << std::endl;
	else if (static_cast<int>(f) - f == 0.0)
		std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(f)) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(15) << "double: " << (static_cast<double>(f)) << std::endl;
}

static void	IsDoublePrint(double d)
{
	std::cout << "char: ";
	if (d >= 0 && d < 256 && static_cast<int>(d) - d == 0.0 && std::isprint(d))
		std::cout << "\'" << (static_cast<char>(d)) << "\'" << std::endl;
	else if (d < 256 && static_cast<int>(d) - d  == 0.0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << (static_cast<int>(d)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (d == std::numeric_limits<double>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: +" << (static_cast<float>(d)) << "f" << std::endl;
	else if ((static_cast<float>(d)) == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: " << "impossible" << std::endl;
	else if ((static_cast<float>(d)) == d - (d - static_cast<float>(d)))
		std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(d)) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(7) << "float: " << (static_cast<float>(d)) << "f" << std::endl;
	if (d == std::numeric_limits<double>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "double: +" << d << std::endl;
	else if (d == floor(d))
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	else
		std::cout << std::fixed << std::setprecision(15) << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		InvalidArg();
		return ;
	}
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		IsChar(str[1]);
	else if (str.length() == 1 && std::isdigit(str[0]))
		IsChar(str[0]);
	else if (IsInt(str))
		IsIntPrint(std::atoi(str.c_str()));
	else if (IsFloat(str))
		IsFloatPrint(std::atof(str.c_str()));
	else if (IsDouble(str))

	
}
