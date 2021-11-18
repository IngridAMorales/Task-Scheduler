#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include <string> 
#include <stdexcept> 

class Tasklist {
private: 
   Tasklist* main_task; 
public: 
   Tasklist() { main_task = nullptr; } 
   virtual ~Tasklist() = default;  

   // virtual void undo_operation() = 0; 
   //virtual void edit_task(Tasklist* tsk) = 0; 
   virtual std::string get_title() = 0;
   virtual std::string get_descrip() = 0;  
}; 


#endif 
