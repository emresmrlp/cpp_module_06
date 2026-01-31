/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:10:13 by ysumeral          #+#    #+#             */
/*   Updated: 2026/01/31 22:29:45 by ysumeral         ###   ########.fr       */
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

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void printPseudo()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;	
}

static bool	hasWhitespace(const std::string &literal)
{
	unsigned char c;

	for (size_t i = 0; i < literal.size(); i++)
	{
		c = static_cast<unsigned char>(literal[i]);
		if (c ==  ' ' || c == '\t' || c == '\n' || c == '\r'
			|| c == '\v' || c == '\f')
			return (true);
	}
	return (false);
}

static bool	isPseudo(const std::string &literal)
{
	if (literal == "+inf" || literal == "-inf"
		|| literal == "+inff" || literal == "-inff"
		|| literal == "nan" || literal == "nanf")
		return (true);
	return (false);
}

static LiteralType detectLiteralType(const std::string &literal)
{
	if (literal.size() == 0 || hasWhitespace(literal))
		return (L_INVALID);
	if (isPseudo(literal))
		return (L_PSEUDO);
	return (L_INVALID);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (detectLiteralType(literal) == L_INVALID)
		printImpossible();
	if (detectLiteralType(literal) == L_PSEUDO)
		printPseudo();
}