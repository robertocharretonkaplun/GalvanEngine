#pragma once

// Librerias STD
#include <string>
#include <sstream>
#include <vector>
#include <thread>

// Third Parties
#include <SFML/Graphics.hpp>

// MACRO for safe release of resources
#define SAFE_PTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

#define MESSAGE( classObj, method, state )   \
{                                            \
   std::ostringstream os_;                   \
   os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
   sf::err() << os_.str();                   \
}                                            \

#define ERROR( classObj, method, errorMSG )  \
{                                            \
   std::ostringstream os_;                   \
   os_ << "ERROR : " << classObj << "::" << method << " : " << "  Error in data from params [" << errorMSG << "] \n"; \
   sf::err() << os_.str();                   \
   throw std::runtime_error(os_.str());      \
}                                            \