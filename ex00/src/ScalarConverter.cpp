/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:10:13 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/03 12:26:46 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	(void)ref;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::InvalidLiteralException::what() const throw()
{
	return ("Error: Invalid literal!");
}

static bool	hasWhitespace(const std::string &literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::isspace(static_cast<unsigned char>(literal[i])))
			return (true);
	}
	return (false);
}

static bool	isPseudo(const std::string &literal)
{
	if (literal == "+inf" || literal == "-inf"
		|| literal == "inf" || literal == "inff"
		|| literal == "+inff" || literal == "-inff"
		|| literal == "nan" || literal == "nanf")
		return (true);
	return (false);
}

static void printChar(const Scalar &scalar)
{
	unsigned char ucValue;

	if (scalar.pseudoType != P_NONE
		|| scalar.value < 0.0 || scalar.value > 255.0)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	ucValue = static_cast<unsigned char>(scalar.value);
	if (std::isprint(ucValue))
		std::cout << "char: \'" << static_cast<char>(ucValue) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	return ;
}

static void printInt(const Scalar &scalar)
{
	int intValue;

	if (scalar.pseudoType != P_NONE)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (scalar.value > static_cast<double>(INT_MAX)
		|| scalar.value < static_cast<double>(INT_MIN))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	intValue = static_cast<int>(scalar.value);
	std::cout << "int: " << intValue << std::endl;
	return ;
}

static void printFloat(const Scalar &scalar)
{
	float floatValue;

	if (scalar.pseudoType != P_NONE)
	{
		if (scalar.pseudoType == P_NAN)
			std::cout << "float: nanf" << std::endl;
		else if (scalar.pseudoType == P_POS_INF)
			std::cout << "float: +inff" << std::endl;
		else if (scalar.pseudoType == P_NEG_INF)
			std::cout << "float: -inff" << std::endl;
		return ;
	}
	floatValue = static_cast<float>(scalar.value);
	std::cout << std::fixed << std::setprecision(1)
		<< "float: " << floatValue << "f" << std::endl;
	return ;
}

static void printDouble(const Scalar &scalar)
{
	double doubleValue;

	if (scalar.pseudoType != P_NONE)
	{
		if (scalar.pseudoType == P_NAN)
			std::cout << "double: nan" << std::endl;
		else if (scalar.pseudoType == P_POS_INF)
			std::cout << "double: +inf" << std::endl;
		else if (scalar.pseudoType == P_NEG_INF)
			std::cout << "double: -inf" << std::endl;
		return ;
	}
	doubleValue = static_cast<double>(scalar.value);
	std::cout << std::fixed << std::setprecision(1)
		<< "double: " << doubleValue << std::endl;
	return ;
}

static Scalar parseLiteral(const std::string &literal)
{
	Scalar		scalar;
	const char	*start;
	char		*end;
	bool		parser;

	end = NULL;
	scalar.pseudoType = P_NONE;
	scalar.value = 0.0;
	if (isPseudo(literal))
	{
		if (literal == "nan" || literal == "nanf")
			scalar.pseudoType = P_NAN;
		if (literal == "+inf" || literal == "+inff"
			|| literal == "inf" || literal == "inff")
			scalar.pseudoType = P_POS_INF;
		if (literal == "-inf" || literal == "-inff")
			scalar.pseudoType = P_NEG_INF;
		return (scalar);
	}
	if (literal.size() == 1 && !isdigit(static_cast<unsigned char>(literal[0])))
	{
		scalar.value = static_cast<double>(literal[0]);
		return (scalar);
	}
	start = literal.c_str();
	scalar.value = std::strtod(start, &end);
	if (start == end)
		throw ScalarConverter::InvalidLiteralException();
	parser = false;
	if (*end == '\0')
		parser = true;
	else if (*end == 'f' && *(end + 1) == '\0')
		parser = true;
	else
		parser = false;
	if (!parser)
		throw ScalarConverter::InvalidLiteralException();
	if (scalar.value != scalar.value)
		scalar.pseudoType = P_NAN;
	return (scalar);
}

void ScalarConverter::convert(const std::string &literal)
{
	Scalar scalar;

	if (literal.size() == 0 || hasWhitespace(literal))
		throw ScalarConverter::InvalidLiteralException();
	scalar = parseLiteral(literal);
	printChar(scalar);
	printInt(scalar);
	printFloat(scalar);
	printDouble(scalar);
}
