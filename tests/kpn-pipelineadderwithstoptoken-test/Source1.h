#ifndef SOURCE1_H
#define SOURCE1_H

#include "log4cxx/logger.h"
using namespace log4cxx;

#include "Component.h"
#include "Token.h"
//#include "IntToken.h"

using namespace sacre;

class Source1: public Component
{
 public:
  Source1(std::string);
  virtual void* task(void*);
  ~Source1();
};

Source1::Source1(std::string _name): Component(_name)
{
  addOutPort< Token<int> >("out");
}

Source1::~Source1()
{
  LOG4CXX_DEBUG(Logger::getLogger("application"), 
		this->name << " is destructed."
		);
}

void* Source1::task(void* nullarg)
{
  LOG4CXX_DEBUG(Logger::getLogger("application"), 
		this->name << "'s implementation of task thread."
		);

  int data[] = {1, 2, 3, 4, 5};
  
  int i;
  for(i=0; i<5; i++)
    {
      this->outPort< Token<int> >("out")->write( *(new Token<int>(data[i])) );
      LOG4CXX_TRACE(Logger::getLogger("application"), 
		    this->name << " wrote "  << data[i]
		    );
    }

  return NULL;
}

#endif
