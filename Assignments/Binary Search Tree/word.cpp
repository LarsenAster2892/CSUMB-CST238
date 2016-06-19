#include <string.h>
#include "word.h"

bool word::isEmpty()
{
	return (strlen(this->name)==0);

}

bool word::operator<(word & rhs)
{
	if(strcmp(this->name, rhs.name)<0)
		return true;
	else
		return false;
}

bool word::operator>(word & rhs)
{
	if(strcmp(this->name, rhs.name)>0)
		return true;
	else
		return false;
}

