#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__


class Tasklist {
private: 
   Tasklist* main_task; 
public: 
   virtual ~Tasklist() {}
   void SetParent(Tasklist* task) { 
	this->main_task = task; 
   } 
   virtual void set_title(std::string t) = 0; 
   // virtual void undo_operation() = 0; 
   //virtual void edit_task(Tasklist* tsk) = 0; 
   virtual std::string get_title() = 0;
   virtual std::string get_descrip() = 0;  
}; 
#endif 
