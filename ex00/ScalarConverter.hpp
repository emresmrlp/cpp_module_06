/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:10:16 by ysumeral          #+#    #+#             */
/*   Updated: 2026/01/30 19:20:58 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &ref);
        ScalarConverter &operator=(const ScalarConverter &ref);
        ~ScalarConverter();
    public:
        static void converter(int value);
};

#endif