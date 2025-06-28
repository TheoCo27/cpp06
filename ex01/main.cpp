/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:56:46 by theog             #+#    #+#             */
/*   Updated: 2025/06/28 22:13:17 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Serializer.hpp"

int main() {

	Data		*data = new Data;
	uintptr_t	tmp;

	int	content = 42;

	data->content = content;

	std::cout << "content: " << data->content << std::endl;

	tmp = Serializer::serialize(data);
	data = Serializer::deserialize(tmp);

	std::cout << "content: " << data->content << std::endl;

	delete data;
    return 0;
}