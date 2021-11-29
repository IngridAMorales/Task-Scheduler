#ifndef __TASK_HPP__
#define __TASK_HPP__
#include "tasklist.hpp" 
#include <vector>
#include <algorithm>
#include <string>
class Tasks: public Tasklist {
private:
   
   std::string classif; 
   int priority; 
   std::string prior;  
   std::string title; 
   std::string descrip;  
   std::vector<std::string> current_task;
   std::vector<std::string> data;  
   std::vector<Tasklist*> subtasks;
public: 
   Tasks(const std::string &t, const std::string &d, int p, const std::string &c): title(t), descrip(d), priority(p), classif(c){} 
   
   ~Tasks() {
   	for( int i = 0; i < subtasks.size(); i++){ 
	   Tasklist* task = subtasks.at(i); 
	   delete task; 
	}
	subtasks.clear(); 
   } 

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
    virtual void edit_descrip(Tasklist* task, std::string descrip) {
        for(int i =0; i< subtasks.size(); ++i){
         if(task ==subtasks.at(i)){
           subtasks.at(i)->set_descrip(descrip);
         }
        }
    }
    virtual void edit_priority(Tasklist* task, int p) {
        for(int i =0; i< subtasks.size(); ++i){
         if(task ==subtasks.at(i)){
           subtasks.at(i)->set_priority(p);
         }
        }
    }
    virtual void edit_classif(Tasklist* task, std::string c) {
        for(int i =0; i< subtasks.size(); ++i){
         if(task ==subtasks.at(i)){
           subtasks.at(i)->set_classif(c);
         }
        }
    }

    virtual void set_title(std::string t){ title = t; }
    virtual void set_descrip(std::string d){ descrip = d; }
    virtual void set_priority(int p){ priority = p; }
    virtual void set_classif(std::string c){ classif = c; }

    virtual std::vector<std::string> get_data() { 
        prior = std::to_string(priority); 
	current_task = {title, descrip, prior, classif};    
	for(int i =0; i< subtasks.size(); ++i){
	  data = subtasks.at(i)->get_data();  
	}
	for(int i =0; i< data.size(); ++i){
          current_task.push_back(data.at(i));
        }
	
	return current_task;
    }
};

#endif   
