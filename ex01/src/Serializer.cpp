/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:29:33 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/03 13:50:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &ref)
{
	(void)ref;
}

Serializer &Serializer::operator=(const Serializer &ref)
{
	(void)ref;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data*	result;

	result = reinterpret_cast<Data *>(raw);
	return (result);
}
