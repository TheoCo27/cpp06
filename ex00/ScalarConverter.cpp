/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:31:57 by theog             #+#    #+#             */
/*   Updated: 2025/06/28 21:39:41 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) 
{
    (void)copy;
    return(*this);
}

void	impossible(void) 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	specialValue( std::string str ) 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void convert_int(std::string str)
{
    int nb;

    std::stringstream ss(str);
    ss >> nb;
    if (ss.fail())
        return(impossible());
    if(std::isprint(nb) == 0)
        std::cout << "char impossible" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(nb) << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
    
}

void	convert_float( std::string str) {

	float	nb;

	if (str == "nan") {
		return specialValue("nan");
	} else if (str == "inf" || str == "+inf") {
		return specialValue("+inf");
	} else if (str == "-inf") {
		return specialValue("-inf");
	} else {
		std::stringstream ss(str);
		ss >> nb;
		if (ss.fail())
			return impossible();
	}

	if (std::isprint(static_cast<char>(nb)) == false)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
    if (nb >= MIN_INT && nb <= MAX_INT)
	    std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl; 
	if (std::floor(nb) == nb) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
		std::cout << "double: "<< std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
	} else {
		std::cout << "float: " << nb << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
	}
}

void	convert_double( std::string str) {

	double	nb;

	if (str == "nan") {
		return specialValue("nan");
	} else if (str == "inf" || str == "+inf") {
		return specialValue("+inf");
	} else if (str == "-inf") {
		return specialValue("-inf");
	} else {
		std::stringstream ss(str);
		ss >> nb;
		if (ss.fail())
			return impossible();
	}

	if (std::isprint(static_cast<char>(nb)) == false)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
   if (nb >= MIN_INT && nb <= MAX_INT)
	    std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl; 
	if (std::floor(nb) == nb) {
        if (nb >= MIN_FLOAT && nb <= MAX_FLOAT)
		    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
        else 
            std:: cout << "float: impossible" << std::endl;
		std::cout << "double: "<< std::fixed << std::setprecision(1) << nb << std::endl;
	} else {
        if (nb >= MIN_FLOAT && nb <= MAX_FLOAT)
		    std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
        else 
            std:: cout << "float: impossible" << std::endl;
		std::cout << "double: " << nb << std::endl;
	}
}

void convert_char(std::string str)
{
    unsigned char c = str[0];
    if (std::isprint(static_cast<int>(c)))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" <<std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (str.empty() == true) {
		std::cout << "Empty argument not allowed" << std::endl;
	}
    if (str.length() == 1)
        convert_char(str);
	else if (str.find('f') != std::string::npos)
		convert_float(str);
    else if(str.find('.') != std::string::npos)
        convert_double(str);
    else
        convert_int(str);
} 