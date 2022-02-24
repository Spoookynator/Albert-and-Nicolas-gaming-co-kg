#pragma once
#include <iostream>

// This activates debug log mode
// Comment out for release!
// #define DEBUG


#ifdef DEBUG
#define LOG(x) std::cout <<  x << std::endl;
#else
#define LOG(x)
#endif

