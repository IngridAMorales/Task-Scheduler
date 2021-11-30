#include "gtest/gtest.h"
#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"
#include "linear.hpp"
#include "magnitude.hpp" 

TEST(Linear, TaskList) {
	Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
	Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"School");
	Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"Work"); 
	Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"Personal");
	test->add_task(task); 
	test->add_task(subtask1); 
	test->add_task(subtask2);
	Classification* sort1 = new Linear(); 
	test->set_strat(sort1);
 	test->printAll(); 
 
	EXPECT_EQ(test->printAll(), “Title: Cs100 \n”);

}


