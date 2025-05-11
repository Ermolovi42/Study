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












