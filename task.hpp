#ifndef __TASKS_HPP__
#define __TASKS_HPP__
#include "Tasklist.hpp" 
#include <vector>

class Tasks: public Tasklist {
private: 
   std::string title; 
   std::string descrip;  
   std::string current_task; 
   std::vector<Tasklist*> subtasks;
public: 
   Tasks(const std::string &t, const std::string &d): title(t), descrip(d){} 
   ~Tasks() {} 
   virtual void add_task(Tasklist* new_task){	//adds composite tasks and subtasks 
 	subtasks.push_back(new_task);
  	new_task->SetParent(this);  	
    }
    virtual void delete_task(Tasklist* task) { 
	subtasks.erase(task);
	task->SetParent(nullptr);   
	delete task; 
    }
    virtual std::string get_title() { 
	for(int i =0; i< subtasks.size(); ++i){
	 current_task = subtasks.at(i)->get_title();
	}
	return current_task;
    } 
    virtual std::string get_descrip(){ 
	for(int i =0; i< subtasks.size(); ++i){
         current_task = subtasks.at(i)->get_descrip();
        }
        return current_task;
    }
};

class Subtask: public TaskList {
private: 
   std::string title; 
   std::string descrip; 
public: 
   Subtask(const std::string &t, const std::string &d):title(t), descrip(d) {}
   ~Subtask() {}
   virtual std::string get_title() { return title; }
   virtual std::string get_descrip(){ return descrip; }
}; 
#endif   
