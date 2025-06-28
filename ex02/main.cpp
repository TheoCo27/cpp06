/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:30:52 by theog             #+#    #+#             */
/*   Updated: 2025/06/28 23:11:58 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


Base * generate(void)
{
    int i = rand() % 3;

    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);

}


void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);

    if (a != NULL)
        std::cout << "Object is of type A" << std::endl;
    else if (b != NULL)
        std::cout << "Object is of type B" << std::endl;
    else if (c != NULL)
        std::cout << "Object is of type C" << std::endl;
    else
        std::cout << "Unkown type" << std::endl;
}

void identify(Base& p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Object is of type A" << std::endl;
        return;
    }catch(...){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Object is of type B" << std::endl;
        return;
    }catch(...){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Object is of type C" << std::endl;
        return;
    }catch(...){}
    std::cout << "Unkown type" << std::endl;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
	std::srand(std::time(0));

    // Génération aléatoire d'une instance de A, B ou C
    Base* instance = generate();

    // Identification de l'instance via pointeur
    std::cout << "Identification via pointeur: ";
    identify(instance);

    // Identification de l'instance via référence
    std::cout << "Identification via référence: ";
    identify(*instance);

    // Nettoyage de la mémoire
    delete instance;
    return 0;
}