

#include "Serializer.hpp"
#include <string>
#include <iostream>



int main()
{

    Data *data = new(Data);

    data->id = 42;
    data->content = 42;
    data->value = 1337;

    std::cout << "------> " << data << std::endl;
    std::cout << "------> " << data->id << std::endl;
    std::cout << "------> " << data->content << std::endl;
    std::cout << "------> " << data->value << std::endl;


    std::cout << "\n---- AFTER SERIALIZATION ----\n" << std::endl;

    


    int *ptr = reinterpret_cast<int *>(data);
    std::cout << "---> data adrss\t" << data << std::endl;
    std::cout << "---> ptr adrss\t" << ptr << std::endl;

    std::cout << "<-------------------------------->" << std::endl;

    std::cout << *ptr << std::endl;

    ptr++;
    data++;
    std::cout << "---> ptr adrss\t" << ptr << std::endl;
    std::cout << "---> data adrss\t" << data << std::endl;
    

    char *chr = reinterpret_cast <char *>(ptr);
    std::cout << *chr << std::endl;

    ptr++;
    std::cout << "---> ptr adrss\t" << ptr << std::endl;
    std::cout << "---> data adrss\t" << data << std::endl;

    std::cout << *reinterpret_cast <float*>(ptr) << std::endl;

    std::cout << "<<<---------------------------->>>" << std::endl;

    
// ---------------------------------------------------------------------------- //

    uintptr_t raw = Serializer::serialize(data);
    


    Data *serialized = Serializer::deserialize(raw);

    std::cout << ">>>>> " << serialized << std::endl;
    std::cout << ">>>>> " << serialized->id << std::endl;
    std::cout << ">>>>> " << serialized->content << std::endl;
    std::cout << ">>>>> " << serialized->value << std::endl;

   


}