/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:29:27 by ysumeral          #+#    #+#             */
/*   Updated: 2026/01/31 22:29:47 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cerr << "Correct usage: ./converter <value>" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
}