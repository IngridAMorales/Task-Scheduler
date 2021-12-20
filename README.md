# Task Scheduler
 
 > Authors: Viviane Fernando (https://github.com/nwarn003) Ingrid Morales (https://github.com/IngridAMorales) Tracy Vu (https://github.com/uvutracy) Kendrew Christanto(https://github.com/kendrewchris)
 

## Project Description
* As we are all college students, productivity and time management are important skills to have as a student so that we can stay on top of all our tasks. Making an application that keeps track of our assignments along with their priorities, will make sure we succeed in our all our classes.
* We will be using C++, Git and Github to implement our task scheduler. 
* Input would be the task title, description, classifications (school, personal, work), and priority. The user will prioritize each task and classification. Our program sorts our subtasks depending on urgency of the task and the urgency of the classification. 

 
## Class Diagram
![image](https://user-images.githubusercontent.com/68444503/144005199-cd2355f0-9853-4150-a587-ea13e45bec3e.png)


 
 ## Design Patterns
* We will be using the composite pattern to implement our task lists for our task scheduler. We decided to use the composite design pattern because a task list is a hierarchy of tasks that are composed with subtasks. When the user creates a task, they will have the option to extend the task to include subtasks as part of this one task. Subtasks cannot have other subtasks so they are the primitive types of the composite pattern. Implementing the composite design pattern simplified structuring the task lists. 
* We will be using the strategy design pattern to implement the classification for our task scheduler because we want to sort the tasks lists based on priority of each task and the priority of each classification.  Each concrete strategy class displays a different sorted task list.  We decided to use the strategy design pattern because we want the user to be able to change the classification of a task into either "school", "personal", or work" which is defined by numbers 1, 2, and 3.  By ranking the tasks by 1, 2, or 3, it will determine the magnitude of the priority of the classification for each task and rank the tasks for the user.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
![Naming Task List, Adding Task, Adding Subtask Input](https://user-images.githubusercontent.com/51254983/144144861-2d2696a5-545f-44ae-9982-1d52dcd6ba40.png)
![Display Linear Output](https://user-images.githubusercontent.com/51254983/144144886-890847f7-ff63-440c-9985-596c4f1deddd.png)
![Rank Linear Task List Output](https://user-images.githubusercontent.com/51254983/144144991-e7104123-1a4c-47ba-b155-54458c9818df.png)
![Rank Group Task List Input](https://user-images.githubusercontent.com/51254983/144144918-679bd537-1c2d-4269-a3c0-a89ee14c9e2a.png)
![Rank Group Sort Output](https://user-images.githubusercontent.com/51254983/144144927-a40dd4c1-b291-480f-864e-4bf0ce64fc46.png)
![Rank Magnitude Sort Input:Output](https://user-images.githubusercontent.com/51254983/144144947-854fb59d-6d50-4cca-90c0-682d9e32d607.png)
![Delete Input](https://user-images.githubusercontent.com/51254983/144144996-295d8676-89d8-4b6a-bd02-3585353c3a11.png)
![Delete Output](https://user-images.githubusercontent.com/51254983/144145000-cf74b911-9689-42e8-8708-a0343d6fe42b.png)
![Edit Input](https://user-images.githubusercontent.com/51254983/144145004-e9f59704-09a1-4700-8d9c-9e8559e1b002.png)
![Edit Output](https://user-images.githubusercontent.com/51254983/144145010-7e958492-9420-4e32-9212-eee2abcd3541.png)
![Quit Input:Output](https://user-images.githubusercontent.com/51254983/144145013-332dccea-6d19-4c53-ace1-a6b25f17b224.png)


 ## Installation/Usage
* Download all files in master onto your local repository
* Run following commands: cmake3 .  make ./main 
 ## Testing
 * We used unit tests to validate the composite and strategy pattern. 
 
