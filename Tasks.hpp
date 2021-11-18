#ifndef __TASKS_HPP__
#define __TASKS_HPP__
#include "Tasklist.hpp" 
#include <vector>

class Tasks: public Tasklist {
private: 
    std::string title; 
    std::string descrip;  

    std::vector<Tasklist*> subtasks;	//holds the tasks

    //std::vector<Tasklist*> u; //implements the undo stack 
    //std::stack<TaskList*, std::vector<Tasklist*>> undo;  //holds the actions of the user to undo any operation 
    
public: 
    Tasks(const Tasklist* task, const std::string &t, const std::string &d): Tasklist(task), title(t), descrip(d){} 
   ~Tasks() {} //delete vector pointers & stack 

    virtual void add_task(Tasklist* new_task){	//adds composite tasks and subtasks 
 	subtasks.push_back(new_task);
  	new_task->main_task=this;  	
    }
    virtual void delete_task(Tasklist* task) { 
	subtasks.erase(task);  
	tasks->subtasks.clear(); 
	delete task; 
    }
    //virtual void undo_task() { }
    //virtual void edit_task(Tasklist* new_task) { } 
    virtual std::string get_title() { return subtasks->get_title();}
    virtual std::string get_descrip(){ return subtasks->get_descrip(); }
};

class Subtask: public TaskList {
private: 
   std::string title; 
   std::string descrip; 
public: 
   Subtask(const std::string &t, const std::string &d):title(t), descrip(d) {}
   ~Subtask() {}
 
   //void undo_task() {}
   //void edit_task() {} 
   virtual std::string get_title() { return title; }
   virtual std::string get_descrip(){ return descrip; }
}; 

#endif 
