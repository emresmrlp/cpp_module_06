/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:08:26 by ysumeral          #+#    #+#             */
/*   Updated: 2026/02/03 18:21:21 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

static Base * generate(void)
{
    int randValue;

    randValue = (std::rand() % 3);
    if (randValue == 0)
        return (new A());
    if (randValue == 1)
        return (new B());
    return (new C());
}

static void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "*Identify: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "*Identify: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "*Identify: C" << std::endl;
    else
        std::cout << "*Identify: ???" << std::endl;
}

static void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "&Identify: A" << std::endl;
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "&Identify: B" << std::endl;
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "&Identify: C" << std::endl;
        return ;
    }
    catch(...) {}
}

int main()
{
    std::srand(std::time(NULL));
    Base *ptr;

    for (int i = 0; i < 5; i++)
    {
        ptr = generate();
        std::cout << "----------------------" << std::endl;
        identify(ptr);
        identify(*ptr);
        delete (ptr);
    }
    std::cout << "----------------------" << std::endl;
}