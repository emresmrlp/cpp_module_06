/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:08:33 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/04 12:58:39 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int main()
{
	Data		data;
	uintptr_t	ptr;
	Data		*raw;
	
	data.id = 42;
	data.name = "Forty Two";
	ptr = Serializer::serialize(&data);
	raw = Serializer::deserialize(ptr);
	std::cout << "Original data (id-name): ("
		<< data.id << "-" << data.name << ")" << std::endl;
	std::cout << "Serialized data (id-name): ("
		<< raw->id << "-" << raw->name << ")" << std::endl;
	std::cout << "Result: " << (&data == raw ? "OK" : "KO" ) << std::endl;
	return (0);
}