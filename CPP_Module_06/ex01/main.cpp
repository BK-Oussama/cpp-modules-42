

#include "Serializer.hpp"
#include <string>
#include <iostream>



// struct Data
// {
//     int id;
//     char content;
//     float value;
// };



int main()
{

    Data *data = new(Data);

    data->id = 42;
    data->content = 42;
    data->value = 1337;

    std::cout << data << std::endl;
    std::cout << data->id << std::endl;
    std::cout << data->content << std::endl;
    std::cout << data->value << std::endl;

    
    int *ptr = reinterpret_cast<int *>(data);
    std::cout << ptr << std::endl;

    std::cout << "<-------------------------------->" << std::endl;

    std::cout << *ptr << std::endl;

    ptr++;
    std::cout << ptr << std::endl;

    char *chr = reinterpret_cast <char *>(ptr);
    std::cout << *chr << std::endl;
    ptr++;
    std::cout << ptr << std::endl;

    std::cout << *reinterpret_cast <float*>(ptr) << std::endl;

    std::cout << "<<<---------------------------->>>" << std::endl;



    uintptr_t raw = Serializer::serialize(data);
    

    int *x = reinterpret_cast<int*>(&data);

    std::cout << "the serialized values:\t" << x << std::endl;
    std::cout << "------> \t" << static_cast<int>(*x) << std::endl;

    double *b = reinterpret_cast<double *>(x);
    std::cout << "------> \t" <<  *b << std::endl;
    std::cout << "------> \t" << *reinterpret_cast<float *>(x + 2) << std::endl;




    Data *serialized = Serializer::deserialize(raw);

    std::cout <<  serialized << std::endl;
    std::cout << serialized->id << std::endl;
    std::cout << serialized->content << std::endl;
    std::cout << serialized->value << std::endl;

    std::cout << "size of Data: " << sizeof(data) << std::endl;
    std::cout << "size of uintptr_t: " << sizeof(uintptr_t) << std::endl;
    std::cout << "size of char: " << sizeof(uintptr_t) << std::endl;


}