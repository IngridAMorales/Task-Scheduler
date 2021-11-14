#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

class Tasklist {
private: 
   std::string title; 
   std::string descrip; 
public: 
   Tasklist(std::string t, std::string d ) {
	title = t; 
	descrip = d; 
   }

   virtual ~Tasklist() { } 

   virtual void add_task(); 
   virtual void delete_task() = 0; 
   virtual void undo_operation() = 0; 
   virtual void edit_task() = 0; 
   virtual void display_task() = 0; 
}; 


#endif 
