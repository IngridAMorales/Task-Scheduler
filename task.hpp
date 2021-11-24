#ifndef __TASK_HPP__
#define __TASK_HPP__
#include "tasklist.hpp" 
#include <vector>
#include <algorithm>

class Tasks: public Tasklist {
private:
   std::string classification; 
   int priority;  
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
	subtasks.erase(std::remove(subtasks.begin(), subtasks.end(), task), subtasks.end());
	task->SetParent(nullptr);   
	delete task; 
    }
    virtual void edit_title(Tasklist* task, std::string title) {
	for(int i =0; i< subtasks.size(); ++i){
         if(task ==subtasks.at(i)){ 
	   subtasks.at(i)->set_title(title); 
	 }
        }	
    }
    virtual void set_title(std::string t){
	title = t;
    }
    virtual std::string get_title() { 
	current_task = title; 
	for(int i =0; i< subtasks.size(); ++i){
	 current_task += subtasks.at(i)->get_title();
	}
	return current_task;
    } 
    virtual std::string get_descrip(){ 
        current_task = descrip; 
	for(int i =0; i< subtasks.size(); ++i){
         current_task += subtasks.at(i)->get_descrip();
        }
        return current_task;
    }
    void print_tasks(std::ostream& out) const { 

	out<<title<<" : "<<descrip<<" \n";
	if(!subtasks.empty()){
	for( int i = 0; i < subtasks.size(); ++i){
	   out<<subtasks.at(i)->get_title()<<" : "<<subtasks.at(i)->get_descrip()<<" \n"; 
	}
	}
    }
};

#endif   
