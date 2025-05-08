#include <iostream>
#include "Bubs.h"
#include "myConstants.h"
#include  <cmath>

int Get_value_from_user()
{
	std::cout << "Enter your hight tower :" << std::endl;
	//Get value
	int hight_tower;
	std::cin >> hight_tower;
	return hight_tower;
}

int Form_acceleration_of_the_fell(int second)
{
	//The hight fell
	int hight_fell;
    hight_fell = myConstants::Acceleration_of_the_fell_K * pow(second, 2)/2;
	return hight_fell;
}

void Calculates_len_fell(int hight_tower)
{
	//calculats fall for x_second
	std::cout << "From 0 second fell";
	std::cout << Form_acceleration_of_the_fell(0) << std::endl;
	
	/
	std::cout << "From 1 second fell";
	std::cout << Form_acceleration_of_the_fell(1) << std::endl;
	
	std::cout << "From 2 second fell";
	std::cout << Form_acceleration_of_the_fell(2) << std::endl;
	
	std::cout << "From 3 second fell";
	std::cout << Form_acceleration_of_the_fell(3) << std::endl;
	
	std::cout << "From 4 second fell";
	std::cout << Form_acceleration_of_the_fell(4) << std::endl;
	
	std::cout << "From 5 second fell";
	std::cout << Form_acceleration_of_the_fell(5) << std::endl;
	
}












