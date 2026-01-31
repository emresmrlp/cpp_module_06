/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:10:16 by ysumeral          #+#    #+#             */
/*   Updated: 2026/01/31 22:29:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>

enum LiteralType
{
	L_CHAR,
	L_INT,
	L_FLOAT,
	L_DOUBLE,
	L_PSEUDO,
	L_INVALID
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
};

#endif