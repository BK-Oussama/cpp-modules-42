

#include "Serializer.hpp"
#include <string>

int main()
{

    Data data;
    data.id = 42;
    data.content = "for testing porpuses";
    data.value = 1337;


    uintptr_t raw = Serializer::serialize(data);
    Data *serialized = Serializer::deserialize(raw);

    std::cout << serialized->name << std::endl;
    std::cout << serialized->age << std::endl;
    std::cout << serialized->sername << std::endl;
}