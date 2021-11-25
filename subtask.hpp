#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__ 

#include "tasklist.hpp"
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>

class Subtask : public Tasklist {
private:
   int priority;
   std::string prior; 
   std::string classif; 
   std::string title;
   std::string descrip;
   std::vector<std::string> data;
public:
   Subtask(const std::string &t, const std::string &d, int p, const std::string &c):title(t), descrip(d), priority(p), classif(c) {}
   ~Subtask() {}
   virtual void set_title(std::string t){ title = t;}
    virtual void set_descrip(std::string d){ descrip = d; }
    virtual void set_priority(int p){ priority = p; }
    virtual void set_classif(std::string c){ classif = c; }
   virtual std::vector<std::string> get_data() {
   	prior = std::to_string(priority);
	data ={title, descrip,prior, classif}; 
	return data; 
   }
  
};


#endif 
