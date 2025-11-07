#include <iostream>
#include <stdexcept>
#include <string>

// 1. Define custom exception classes, inheriting from std::exception
class LowFuelException : public std::exception
{
public:
    // Override the virtual what() method inherited from std::exception
    // In C++98, we must add the 'throw()' specification.
    virtual const char *what() const throw()
    {
        return "LowFuelException: Cannot start trip. Fuel level is below 10 liters.";
    }
};

class EmptyTankException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "EmptyTankException: Tank is completely empty. Please refuel immediately.";
    }
};

// Function that simulates starting a trip and checks the fuel level
void startTrip(int fuelLevelLiters)
{
    // If the fuel is 0, throw the most critical exception
    if (fuelLevelLiters == 0)
    {
        throw EmptyTankException();
    }
    // If the fuel is below the safe threshold (e.g., 10 liters), throw the 'low' exception
    else if (fuelLevelLiters < 10)
    {
        throw LowFuelException();
    }
    // Otherwise, the trip can start normally
    else
    {
        std::cout << "Fuel check successful. Starting trip with " << fuelLevelLiters << " liters." << std::endl;
    }
}

int main()
{
    // Case 1: Trip starts successfully (No Exception)
    std::cout << "--- Test 1: Sufficient Fuel (50L) ---" << std::endl;
    try
    {
        startTrip(50);
    }
    catch (const std::exception &e)
    {
        // This catch block will only execute if an exception is thrown
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Low Fuel (5L) ---" << std::endl;
    // Case 2: LowFuelException is thrown
    try
    {
        startTrip(5);
    }
    // catch (const  &e)
    // {
    //     // We catch the specific type for a targeted response
    //     std::cerr << "Caught Low Fuel Exception: " << e.what() << std::endl;
    //     std::cout << "Action: Switching to 'Find Nearest Gas Station' mode." << std::endl;
    // }
    catch (const std::exception &e)
    {
        // A generic catch block is good practice for any unexpected std exceptions
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Empty Tank (0L) ---" << std::endl;
    // Case 3: EmptyTankException is thrown
    try
    {
        startTrip(0);
    }
    catch (const std::exception &e)
    {
        // We can also catch all custom exceptions as std::exception&
        // This is often used to simplify error handling, just like the subject requires.
        std::cerr << "Caught exception (Generic Catch): " << e.what() << std::endl;
        std::cout << "Action: Calling Roadside Assistance." << std::endl;
    }

    return 0;
}