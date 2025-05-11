#include <iostream>
#include "Bubs.h"

//This programm print how much the ball fell in 5 seconds
int main()
{
	//Hight tower
	int hight_tower;
	hight_tower = Get_value_from_user();

	//Print how much the ball fell in 5 seconds
	int one  {Form_acceleration_of_the_fell(1)} ;
	int two  {Form_acceleration_of_the_fell(2)} ;
	int three{Form_acceleration_of_the_fell(3)} ;
	int four {Form_acceleration_of_the_fell(4)} ;
	int five {Form_acceleration_of_the_fell(5)} ;
	
	//one second
	if (one < hight_tower)
		std::cout << "This ball fell by 1 second " << one << " meters" << std::endl;
	else
		std::cout << "This ball fell by 1 second " << hight_tower << " meters" << std::endl;
	
	//two second
	if (two < hight_tower)
		std::cout << "This ball fell by 2 second " << two << " meters" << std::endl;
	else
		std::cout << "This ball fell by 2 second " << hight_tower << " meters" << std::endl;
	
	//tree second
	if (three < hight_tower)
		std::cout << "This ball fell by 3 second " << three << " meters" << std::endl;
	else
		std::cout << "This ball fell by 3 second " << hight_tower << " meters" << std::endl;
	
	//four second
	if (four < hight_tower)
		std::cout << "This ball fell by 4 second " << four << " meters" << std::endl;
	else
		std::cout << "This ball fell by 4 second " << hight_tower << " meters" << std::endl;
	
	if (five < hight_tower)
		std::cout << "This ball fell by 5 second " << five << " meters" << std::endl;
	else
		std::cout << "This ball fell by 5 second " << hight_tower << " meters" << std::endl;

	//So program not close
	std::cin.clear();
	std::cin.ignore(32767, '/n');
	std::cin.get();

	return 0;
}

