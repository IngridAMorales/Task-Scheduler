#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__ 

#include "tasklist.hpp"

class Subtask : public Tasklist {
private:
   std::string title;
   std::string descrip;
public:
   Subtask(const std::string &t, const std::string &d):title(t), descrip(d) {}
   ~Subtask() {}
   virtual void set_title(std::string t){ title = t;}
   virtual std::string get_title() { return title; }
   virtual std::string get_descrip(){ return descrip; }
};


#endif 
