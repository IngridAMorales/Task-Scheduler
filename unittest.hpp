#include "gtest/gtest.h"
#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"
#include "linear.hpp"
<<<<<<< HEAD
#include "magnitude.hpp" 

TEST(Linear, TaskList) {
=======
#include "magnitude.hpp"
#include "group.hpp" 

TEST(Magnitude, Display) {
>>>>>>> ccad483aa416509833dcace5a2d33866f33dbf03
	Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
	Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"School");
	Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"Work"); 
	Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"Personal");
	test->add_task(task); 
	test->add_task(subtask1); 
	test->add_task(subtask2);
<<<<<<< HEAD
	Classification* sort1 = new Linear(); 
	test->set_strat(sort1);
 	test->printAll(); 
 
	EXPECT_EQ(test->printAll(), “Title: Cs100 \n”);
=======
	Classification* sort1 = new Magnitude(1,1,3); 
	test->set_strat(sort1); 
	test->printAll();
	
	std::vector<Tasklist*> compare;
	
	compare.push_back(subtask1);
	compare.push_back(task);
	compare.push_back(subtask2);

	EXPECT_EQ(test->get_Subtasks(), compare);
	
	delete test;

}

TEST(Group, Display) {
	Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
        Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"School");
        Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"Work");
        Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"Personal");
        test->add_task(task);
        test->add_task(subtask1);
        test->add_task(subtask2);
        Classification* sort1 = new Group(1,1,3);
        test->set_strat(sort1);
        test->printAll();

        std::vector<Tasklist*> compare;

        compare.push_back(task);
        compare.push_back(subtask2);
        compare.push_back(subtask1);

        EXPECT_EQ(test->get_Subtasks(), compare);
	
	delete test;
>>>>>>> ccad483aa416509833dcace5a2d33866f33dbf03

}


