#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int	main()
{
    Data data;

    data.number = 42;
    data._data = "hello";

    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);
	std::cout << raw << std::endl;
    Data* restored = Serializer::deserialize(raw);

    std::cout << original << std::endl;
    std::cout << restored << std::endl;

    std::cout << restored->number << std::endl;
    std::cout << restored->_data << std::endl;
}
