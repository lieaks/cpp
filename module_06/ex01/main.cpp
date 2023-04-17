#include "Data.hpp"
#include <iostream>

int main ()
{
	Data *data1 = new Data;
	data1->name = "david";
	data1->value = 30;
	std::cout << "adress of data1: "<< data1 << " name:" << data1->name << " value: " << data1->value << std::endl;

	Data *data2 = Serializer::deserialize(Serializer::serialize(data1));
	std::cout << "adress of data2: "<< data2 << " name:" << data2->name << " value: " << data2->value << std::endl;

	delete data1;
	return 0;
};