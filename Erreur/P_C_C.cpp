#include "P_C_C.h"

std::ostream &operator<<(std::ostream & flux, P_C_C const & v)
{
	std::string mess = v.toString();
	flux << mess << std::endl;
	return flux;
}

std::string operator+(P_C_C const &v, std::string a)
{
	std::string mess = v.toString();
	return(mess + a);
}
std::string operator+(std::string a, P_C_C const &v)
{
	std::string mess = v.toString();
	return(a + mess);
}