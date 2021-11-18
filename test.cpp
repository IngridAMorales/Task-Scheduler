#include "Tasks.hpp"

TEST(Tasks, AddingSubtasks){
  Tasklist* task; 
  Tasklist* test = new Subtasks("Final Project", "Task Scheduler"); 
  EXPECT_EQ(test->get_title(), "Final Project"); 
  
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
