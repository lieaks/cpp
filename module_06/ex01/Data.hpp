#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <stdint.h>

struct Data
{
	std::string name;
	int value;
};

class Serializer
{
public:
	~Serializer();
	static uintptr_t serialize(Data* ptr) {
		return (reinterpret_cast<uintptr_t>(ptr)); };
	static Data* deserialize(uintptr_t raw) {
		return (reinterpret_cast<Data *>(raw)); };

private:
	Serializer();
	Serializer(const Serializer &);
	Serializer & operator = (const Serializer &);
};

#endif //DATA_HPP