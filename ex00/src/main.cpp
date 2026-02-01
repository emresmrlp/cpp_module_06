/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:29:27 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/01 19:23:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Correct usage: ./converter <value>" << std::endl;
        return (1);
    } 
    else
    {
        try
        {
            ScalarConverter::convert(argv[1]);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return (1);
        }
    }
    return (0);
}