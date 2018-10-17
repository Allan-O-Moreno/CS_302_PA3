#ifndef PRECOND_VIOLATED_EXCEPT_H_
#define PRECOND_VIOLATED_EXCEPT_H_

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");  // : logic_error("PrecondViolatedExcept" + message)
	//{}
};	// end PrecondViolatedExcept
#endif /*PRECONDVIOLATEDEXCEPT_H_*/
