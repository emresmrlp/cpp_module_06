/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:10:16 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/04 13:35:03 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include <exception>
# include <climits>

enum PseudoType
{
	P_NONE,
	P_POS_INF,
	P_NEG_INF,
	P_NAN
};

struct Scalar
{
	double		value;
	PseudoType	pseudoType;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter &operator=(const ScalarConverter &ref);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
		class InvalidLiteralException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif