#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include <string> 
#include <stdexcept> 

class Tasklist { 
public: 
   virtual ~Tasklist() = default;  

   virtual void delete_task(Tasklist* tsk) = 0; 
   virtual void undo_operation() = 0; 
   virtual void edit_task(Tasklist* tsk) = 0; 
   virtual void get_title() = 0;
   virtual void get_descrip() = 0;  
}; 


#endif 
