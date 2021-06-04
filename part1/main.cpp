/***************************************************************
 *                                                             *
 * file: main.cpp                                              *
 *                                                             *
 * @Author  Antonios Peris                         		   	   *
 * @Version 20-10-2020                             			   *
 * @email   csdp1196@csd.uoc.gr                                *
 *                                                             *
 * @brief   Main function for the needs of cs-240 project 2020 *
 *                                                             *
 ***************************************************************
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>


#include "among_us.h"
/***************************************************
 *                                                 *
 * file: among_us.cpp                              *
 *                                                 *
 * @Author  Antonios Peris                         *
 * @Version 20-10-2020                             *
 * @email   csdp1196@csd.uoc.gr                    *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */

///////////////////////////
//TESTED AT SYKO SERVER///
/////////////////////////


int initialize()
{
	//Create the header of the Players list
	Players* Head = new Players();
	players_head = Head;
	players_head->evidence=-1;
	players_head->is_alien=-1;
	players_head->pid=-1;
	players_head->next=NULL;
	players_head->prev=NULL;
	players_head->tasks_sentinel=NULL;
	players_head->tasks_head=NULL;

	//Create the header of the tasks List
	tasks_head = new Head_GL();
	tasks_head->head = NULL;

	//Create the header of the completed task stack
	Head_Completed_Task_Stack* stack = new Head_Completed_Task_Stack();
	tasks_stack = stack;
	tasks_stack->count = 0;
	tasks_stack->head = NULL; 

	return 1;
}

void print_double_list_with_evidence(){
	Players* printP;
	printP = players_head->next;
	while(printP != players_head){
		Tasks* printT;
		printT = printP->tasks_head;
		std::cout <<"<Player" << printP->pid << "," << printP->evidence << ">" <<"=";
		while(printT != printP->tasks_sentinel){
			if(printT->next == printP->tasks_sentinel){
			std::cout << "<" <<  printT->tid << "," << printT->difficulty << ">";
			}else{
			std::cout << "<" <<  printT->tid << "," << printT->difficulty << ">,";
			}
			printT=printT->next;
		}
		std::cout<<std::endl;
		printP = printP->next;
	}
}

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien)
{
	Players* newPlayer = new Players();
	Tasks* newTasksSentinel = new Tasks();

	newPlayer->evidence = 0;
	newPlayer ->is_alien = is_alien;
	newPlayer ->pid = pid;

	newPlayer->tasks_head = newTasksSentinel; //to ebales meta gia na deixnei h arxh toy tasks_head sto prwto task (to opoio edw einai to sentinel)
	newPlayer->tasks_sentinel = newTasksSentinel;
	newPlayer->tasks_sentinel->difficulty = 0;
	newPlayer->tasks_sentinel->tid = -1;
	newPlayer->tasks_sentinel->next=newPlayer->tasks_head;

	if(players_head->prev == NULL){
		players_head->next = newPlayer;
		players_head->prev = newPlayer;
		newPlayer->next = players_head;
		newPlayer->prev = players_head;
	}else{
		newPlayer->prev =  players_head->prev;
		players_head->prev->next = newPlayer;
		players_head->prev = newPlayer;
		newPlayer->next = players_head;
	}

	std::cout << "Players=";
	Players* q = players_head->next;
	while(q != players_head){
		std::cout << "<" << q->pid << ":" << q->is_alien << ">";
		q = q->next; 
	}
	std::cout << std::endl;
	std::cout << "DONE" << std::endl;
	return 1;
}

/**
 * @brief Insert task in the general task list
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty)
{

	tasks_head->tasks_count[difficulty-1]++;

	Tasks* newTask = new Tasks();
	newTask->tid = tid;
	newTask->difficulty = difficulty;

	if(tasks_head->head == NULL){
		tasks_head->head = newTask;
		newTask->next = NULL;
	}else{
		Tasks* pq = NULL;
		Tasks* q = NULL;
		q = tasks_head->head;
		while ((q!=NULL) && (q->difficulty < newTask->difficulty)){
			pq = q;
			q = q->next;
		}
		if(pq == NULL){
			newTask->next = q;
			tasks_head->head = newTask;
		}else{
			newTask->next = q;
			pq->next= newTask;
		}
		//newTask->next = q->next;
		//q->next = newTask;
	}

	std::cout<<"Tasks=";
	Tasks* search = tasks_head->head;
	while (search != NULL){
		std::cout<< "<" << search->tid << "," <<search->difficulty<<">";
		search = search->next;
	}
	std::cout << std::endl << "DONE" << std::endl; 

	return 1;
}

/**
 * @brief Distribute tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks()
{
	int total_tasks = tasks_head->tasks_count[0] + tasks_head->tasks_count[1] + tasks_head->tasks_count[2];

	Players* search;  //pointer at the current player
	search = players_head->next;
	Tasks* tasksSearch = new Tasks; //pointer at the current task of tasks_head list
	tasksSearch = tasks_head->head;

	int i = 0;
	while(i<total_tasks){
		if(!(search->is_alien) && (search != players_head)){
			Tasks* addTask =  new Tasks(); //create a new task to have the same values as the tasksSearch
			memcpy(addTask , tasksSearch , sizeof(Tasks));
			addTask->next = search->tasks_sentinel;
			if(search->tasks_head == search->tasks_sentinel){
				search->tasks_sentinel->next = addTask;
				search->tasks_head = addTask;
			}else{
			search->tasks_sentinel->next->next = addTask;
			search->tasks_sentinel->next = addTask;
			}
			tasksSearch = tasksSearch->next;
			i++;
			
		}
		search = search->next;

		
	}

	print_double_list();

	return 1;
}


/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty)
{
	//search for the correct player 
	Players* search;
	search = players_head->next;
	while(search->pid != pid && search!=players_head){
		search = search->next;
	}
	if(search==players_head){ return 1; }

	
	if(search->tasks_head == search->tasks_sentinel){return 1;}
	if(search->tasks_head->next == search->tasks_sentinel || search->tasks_head->difficulty == difficulty) { 
		Tasks* temp = new Tasks();
		memcpy(temp , search->tasks_head , sizeof(Tasks));

		search->tasks_head = search->tasks_head->next;

		temp->next = tasks_stack->head;
		tasks_stack->head = temp;
		tasks_stack->count++;
	}
	else{
		Tasks* searchTasks = search->tasks_head->next;
		Tasks* prevTask = search->tasks_head;

		int last_task_diff = search->tasks_sentinel->next->difficulty;
		search->tasks_sentinel->next->difficulty = difficulty;
		while(searchTasks->difficulty != difficulty){
			prevTask = searchTasks;
			searchTasks = searchTasks->next;
		}
		prevTask->next = searchTasks->next;
		search->tasks_sentinel->next->difficulty = last_task_diff;

		// checks for adjusting the sentinel node
		if(searchTasks == search->tasks_sentinel->next){ // we reached the last task
			search->tasks_sentinel->next = prevTask;
		}

		//push here
		Tasks* temp = searchTasks;
		temp->next = tasks_stack->head;
		tasks_stack->head = temp;
		tasks_stack->count++;

	}

	print_double_list();

	return 1;
}

/**
 * @brief Eject Player
 * 
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid)
{
	Players* search = players_head ->next; //use to find the player that should be removed
	Players* pid_min = players_head -> next; //set this as the current player with less tasks
	Players* minP = NULL;  //the pointer to the current player with less tasks
	Players* searchP = players_head->next; //to xrhsimopoiw gia na vrw ton enan me ta ligotera tasks	
	int min = -1; // the current minimum tasks players tasks

	//find the player that should be removed
	while(search != players_head && search->pid != pid){
		search = search->next;
	}
	if(search == players_head) {return 1;}
	if(search->is_alien == 1) {return 1;}
	
	//if the player which i should remove has 0 tasks , I just remove him
	if(search->tasks_head == search->tasks_sentinel){ 
		search->prev->next = search->next;
		search->next->prev = search->prev;
		print_double_list();
		return 1; 
	}

	//search every player and find the player with the least tasks
	while(searchP != players_head){
		int tasks = 0;
		if(searchP->is_alien==1 || searchP->pid == pid){
			searchP = searchP->next;
			continue;
		}
		Tasks* searchTasks = searchP->tasks_head;
		while(searchTasks != searchP->tasks_sentinel){
			tasks++;
			searchTasks = searchTasks->next;
		}
		if(min == -1){
			min = tasks;
			minP = searchP;
		}else if((tasks < min)){
			min = tasks;
			minP = searchP;
		}
		searchP = searchP->next;
	}

	Tasks* l1  = minP->tasks_head;
	Tasks* l2 = search->tasks_head;
	Tasks* fake = new Tasks();
	fake->difficulty = -10;
	Tasks* last = fake;

	while(l1 != minP->tasks_sentinel && l2!= search->tasks_sentinel){
		if(l1->difficulty < l2->difficulty){
			last->next = l1;
			last = l1;
			l1 = l1->next;
		}else{
			last->next = l2;
			last = l2;
			l2 = l2->next;
		}
	}
	if(l1 != minP->tasks_sentinel){
		last->next = l1;
	}
	if(l2 != search->tasks_sentinel){
		last->next = l2;
	}
	minP->tasks_head = fake->next;

	Tasks* searchSentinel = fake->next;
	Tasks* prevSearchSentinel = NULL;
	while( searchSentinel->tid != -1){
		prevSearchSentinel = searchSentinel;
		searchSentinel = searchSentinel->next;
	}
	minP->tasks_sentinel = searchSentinel;
	minP->tasks_sentinel->next = prevSearchSentinel;

	//edw kanw remove ton dead paikth
	search->prev->next = search->next;
	search->next->prev = search->prev; 

	print_double_list();

	return 1;
}

/**
 * @brief Witness Eject Player
 *
 * @param pid_a The alien's pid
 * 
 * @param pid The crewmate's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid, int pid_a, int number_of_witnesses)
{
	//find the impostor and change his evidense
	Players* impostor = players_head->next;
	while((impostor->pid != pid_a) && impostor != players_head ){
		impostor = impostor->next;
	}
	if(impostor == players_head || impostor->is_alien == 0) return 1;

	impostor->evidence = number_of_witnesses;

	//start to remove the pid player
	Players* search = players_head ->next; //use to find the player that should be removed
	Players* pid_min = players_head -> next; //set this as the current player with less tasks
	Players* minP = NULL;  //the pointer to the current player with less tasks
	Players* searchP = players_head->next; //to xrhsimopoiw gia na vrw ton enan me ta ligotera tasks	
	int min = -1; // the current minimum tasks players tasks

	//find the player that should be removed
	while(search != players_head && search->pid != pid){
		search = search->next;
	}
	if(search == players_head) {return 1;}
	if(search->is_alien == 1) {return 1;}
	
	//if the player which i should remove has 0 tasks , I just remove him
	if(search->tasks_head == search->tasks_sentinel){ 
		search->prev->next = search->next;
		search->next->prev = search->prev;
		print_double_list();
		return 1; 
	}

	//search every player and find the player with the least tasks
	while(searchP != players_head){
		int tasks = 0;
		if(searchP->is_alien==1 || searchP->pid == pid){
			searchP = searchP->next;
			continue;
		}
		Tasks* searchTasks = searchP->tasks_head;
		while(searchTasks != searchP->tasks_sentinel){
			tasks++;
			searchTasks = searchTasks->next;
		}
		if(min == -1){
			min = tasks;
			minP = searchP;
		}else if((tasks < min)){
			min = tasks;
			minP = searchP;
		}
		searchP = searchP->next;
	}

	Tasks* l1  = minP->tasks_head;
	Tasks* l2 = search->tasks_head;
	Tasks* fake = new Tasks();
	fake->difficulty = -10;
	Tasks* last = fake;

	while(l1 != minP->tasks_sentinel && l2!= search->tasks_sentinel){
		if(l1->difficulty < l2->difficulty){
			last->next = l1;
			last = l1;
			l1 = l1->next;
		}else{
			last->next = l2;
			last = l2;
			l2 = l2->next;
		}
	}
	if(l1 != minP->tasks_sentinel){
		last->next = l1;
	}
	if(l2 != search->tasks_sentinel){
		last->next = l2;
	}
	minP->tasks_head = fake->next;

	Tasks* searchSentinel = fake->next;
	Tasks* prevSearchSentinel = NULL;
	while( searchSentinel->tid != -1){
		prevSearchSentinel = searchSentinel;
		searchSentinel = searchSentinel->next;
	}
	minP->tasks_sentinel = searchSentinel;
	minP->tasks_sentinel->next = prevSearchSentinel;

	//edw kanw remove ton dead paikth
	search->prev->next = search->next;
	search->next->prev = search->prev; 

	print_double_list_with_evidence();

	return 1;
}

/**
 * @brief Sabbotage
 *
 * @param pid The player's id
 *
 * @param number_of_tasks The number of tasks to be popped
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabbotage(int pid, int number_of_tasks)
{
	//find the given pid player
	Players* searchP = players_head->next;
	while((searchP->pid != pid) && (searchP!=players_head)){
		searchP = searchP->next;
	}
	if(searchP==players_head) return 1;

	//find the first player to add the first task
	int i=1;
	Players* firstTaskPlayer = searchP->prev;
	while(i < number_of_tasks/2){
		if(firstTaskPlayer != players_head) i++;
		firstTaskPlayer = firstTaskPlayer->prev;
	}

	//Pop every time one task and add it to the player
	int j=0;
	while(j<number_of_tasks){ 
		//pop one task
		if(tasks_stack->head == NULL) break;
		tasks_stack->count--;
		Tasks* newTask = tasks_stack->head;
		tasks_stack->head = tasks_stack->head->next;
		while(firstTaskPlayer->is_alien || firstTaskPlayer == players_head){ //here I check if the player I found is alien and if it is I change it
			firstTaskPlayer = firstTaskPlayer->next;
		}
		//add the task to the current player
		Tasks* searchT ;
		searchT = firstTaskPlayer ->tasks_head;
		if(searchT == firstTaskPlayer->tasks_sentinel){
			newTask->next = firstTaskPlayer->tasks_sentinel;
			firstTaskPlayer->tasks_sentinel->next = newTask;
			firstTaskPlayer->tasks_head = newTask;
		}else{
			while(searchT->next != firstTaskPlayer->tasks_sentinel && searchT->next->difficulty < newTask->difficulty ){
				searchT = searchT->next;
			}
			newTask->next = searchT->next;
			searchT->next = newTask;	
			if(newTask->next == firstTaskPlayer->tasks_sentinel){
				firstTaskPlayer->tasks_sentinel->next = newTask;
			}
		}
		firstTaskPlayer = firstTaskPlayer->next;
		j++;
	}

	print_double_list();
	return 1;
}

/**
 * @brief Vote
 *
 * @param pid The player's id
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid, int vote_evidence)
{
	//Edw vriskw ton player p prepei na votarw kai allazw to evidence tou
	Players* voted = players_head->next;
	while(voted->pid != pid && voted != players_head){
		voted = voted->next;
	}
	if(voted == players_head) return 1;
	voted->evidence = vote_evidence;

	//edw vriskw ton player me to megalytero evidence genika
	int maxVotes = -1;
	Players* searchP = players_head->next; //to xrhsimopoiw gia na brw ton ena me to max evidence
	Players* maxP = NULL; //the pointer to the current player with less tasks

	while(searchP != players_head){
		if(searchP->evidence > maxVotes){
			maxP = searchP;
			maxVotes = searchP->evidence;
		}
		searchP = searchP->next;
	}

	if(maxP->is_alien || maxP->tasks_head == maxP->tasks_sentinel){
		maxP->next->prev = maxP->prev;
		maxP->prev->next = maxP->next;
	}else{
		Players* pid_min = players_head -> next; //set this as the current player with less tasks
		Players* minP = NULL;  //the pointer to the current player with less tasks
		searchP = players_head->next; //to xrhsimopoiw gia na vrw ton enan me ta ligotera tasks	
		int min = -1; // the current minimum tasks players tasks

		//search every player and find the player with the least tasks
		while(searchP != players_head){
			int tasks = 0;
			if(searchP->is_alien==1 || searchP->pid == pid){
				searchP = searchP->next;
				continue;
			}
			Tasks* searchTasks = searchP->tasks_head;
			while(searchTasks != searchP->tasks_sentinel){
				tasks++;
				searchTasks = searchTasks->next;
			}
			if(min == -1){
				min = tasks;
				minP = searchP;
			}else if((tasks < min)){
				min = tasks;
				minP = searchP;
			}
			searchP = searchP->next;
		}

		Tasks* l1  = minP->tasks_head;
		Tasks* l2 = maxP->tasks_head;
		Tasks* fake = new Tasks();
		fake->difficulty = -10;
		Tasks* last = fake;

		while(l1 != minP->tasks_sentinel && l2!= maxP->tasks_sentinel){
			if(l1->difficulty < l2->difficulty){
				last->next = l1;
				last = l1;
				l1 = l1->next;
			}else{
				last->next = l2;
				last = l2;
				l2 = l2->next;
			}
		}
		if(l1 != minP->tasks_sentinel){
			last->next = l1;
		}
		if(l2 != maxP->tasks_sentinel){
			last->next = l2;
		}
		minP->tasks_head = fake->next;

		Tasks* searchSentinel = fake->next;
		Tasks* prevSearchSentinel = NULL;
		while( searchSentinel->tid != -1){
			prevSearchSentinel = searchSentinel;
			searchSentinel = searchSentinel->next;
		}
		minP->tasks_sentinel = searchSentinel;
		minP->tasks_sentinel->next = prevSearchSentinel;

		//edw kanw remove ton dead paikth
		maxP->prev->next = maxP->next;
		maxP->next->prev = maxP->prev; 

	}
	
	print_double_list_with_evidence();
	return 1;
}

/**
 * @brief Give Away Work
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work()
{
	Players* searchP = players_head->next;
	Players* pmin;
	Players* pmax;
	int min = -1;
	int max = -1;

	//edw vriskw ta pmin kai pmax
	while(searchP != players_head){
		int tasks = 0;
		if(searchP->is_alien){
			searchP = searchP->next;
			continue;
		}
		Tasks* searchTasks = searchP->tasks_head;
		while(searchTasks != searchP->tasks_sentinel){
			tasks++;
			searchTasks = searchTasks->next;
		}
		if(min == -1){
			min = tasks;
			pmin = searchP;
		}else if(tasks < min){
			min = tasks;
			pmin = searchP;
		}
		if(tasks > max){
			max = tasks;
			pmax = searchP;
		}
		searchP = searchP->next;
	}

	//an ta pmin kai pmax einai ta idia dn kanw tpt
	if(pmax == pmin){
		print_double_list();
		return 1;
	}

	//an to pmax einai 0 tote pali vgainw
	if(max == 0 || max == 1){
		print_double_list();
		return 1;
	}

	//kserw hdh oti o pmax exei mesa max tasks
	//ara pairnw ta max/2 tasks tou pmax kai ta vazw se mia nea lista
	//kai meta kanw merge thn nea lista me thn lista tou pmin

	Tasks* sentinel = new Tasks();
	sentinel->difficulty = 0;
	sentinel->tid = -1;

	Tasks* l3 = pmax->tasks_head;
	pmax->tasks_head = pmax->tasks_head->next;
	l3->next = sentinel;
	sentinel->next = l3;

	Tasks* temp;
	for(int j=1; j<max/2; j++){
		temp = pmax->tasks_head;
		pmax->tasks_head = pmax->tasks_head->next;
		temp->next = l3;
		l3 = temp;
	}

	//ksekinaei to merge
	Tasks* l1  = pmin->tasks_head;
	Tasks* l2 = l3;
	Tasks* fake = new Tasks();
	fake->difficulty = -10;
	Tasks* last = fake;

	while(l1 != pmin->tasks_sentinel && l2->difficulty != 0){
		if(l1->difficulty < l2->difficulty){
			last->next = l1;
			last = l1;
			l1 = l1->next;
		}else{
			last->next = l2;
			last = l2;
			l2 = l2->next;
		}
	}
	if(l1 != pmin->tasks_sentinel){
		last->next = l1;
	}
	if(l2->difficulty != 0 ){
		last->next = l2;
	}
	pmin->tasks_head = fake->next;

	Tasks* searchSentinel = fake->next;
	Tasks* prevSearchSentinel = NULL;
	while( searchSentinel->tid != -1){
		prevSearchSentinel = searchSentinel;
		searchSentinel = searchSentinel->next;
	}
	pmin->tasks_sentinel = searchSentinel;
	pmin->tasks_sentinel->next = prevSearchSentinel;
	
	print_double_list();


	return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate()
{
	Players* search = players_head->next;
	int aliens = 0;
	int crewmates = 0;
	while(search != players_head){
		if(search->is_alien) aliens++;
		else crewmates++;
		search = search->next;
	}
	if(aliens > crewmates){
		std::cout<< "Aliens win." << std::endl;
		return 1;
	}
	if(aliens==0 || tasks_stack->count == (tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2])){
		std::cout << "Crewmates win." <<std::endl;
		return 1;
	}

	return 1;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players()
{
	std::cout << "Players=";
	Players* q = players_head->next;
	while(q != players_head){
		std::cout << "<" << q->pid << ":" << q->is_alien << ">";
		q = q->next; 
	}
	std::cout << std::endl;
	std::cout << "DONE" << std::endl;
	
	return 1;
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks()
{
	std::cout<<"List_Tasks=";
	Tasks* search = tasks_head->head;
	while (search != NULL){
		std::cout<< "<" << search->tid << "," <<search->difficulty<<">";
		search = search->next;
	}
	std::cout << std::endl << "DONE" << std::endl; 
	return 1;
}

/**
 * @brief Print Stack
 *
 * @return 1 on success
 *         0 on failure
 */
int print_stack()
{
	//create a new temporary stack to add all tasks
	Head_Completed_Task_Stack* tempStack = new Head_Completed_Task_Stack();
	tempStack->count = 0;
	tempStack->head = NULL;

	std::cout << "Stack_Tasks=" ;
	while(tasks_stack->count > 0){
		std::cout<<"<" << tasks_stack->head->tid << "," << tasks_stack->head->difficulty << ">";
		tasks_stack->count--;
		
		//pop the task from the tasks_stack
		Tasks* tempTask;
		tempTask = tasks_stack->head;
		tasks_stack->head = tasks_stack->head->next;

		//push the task to the temp stack
		tempTask->next = tempStack->head;
		tempStack->head = tempTask;
		tempStack->count++;

		

	} 

	while(tempStack->count > 0){
		//pop the task from the temp stack
		Tasks* tempTask;
		tempTask = tempStack->head;
		tempStack->head = tempStack->head->next;

		//push the task to the tasks_stack
		tempTask->next = tasks_stack->head;
		tasks_stack->head = tempTask;
		tasks_stack->count++;

		tempStack->count--;
	}
	std::cout<<std::endl;

	return 1;
}

/**
 * @brief Print Players & Task List
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_list()
{
	Players* printP;
	printP = players_head->next;
	while(printP != players_head){
		Tasks* printT;
		printT = printP->tasks_head;
		std::cout <<"Player" << printP->pid <<"=";
		while(printT != printP->tasks_sentinel){
			if(printT->next == printP->tasks_sentinel){
			std::cout << "<" <<  printT->tid << "," << printT->difficulty << ">";
			}else{
			std::cout << "<" <<  printT->tid << "," << printT->difficulty << ">,";
			}
			printT=printT->next;
		}
		std::cout<<std::endl;
		printP = printP->next;
	}
	return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void)
{
	return 1;
}

#define BUFFER_SIZE 1024 /* Maximum length of a line in input file */

/* Uncomment the following line to enable debugging prints 
 * or comment to disable it */
#define DEBUG
#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */

/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char **argv)
{
	FILE *fin = NULL;
	char buff[BUFFER_SIZE], event = '\0';

	/* Check command buff arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input_file> <>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* Open input file */
	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
		perror("Opening test file\n");
		return EXIT_FAILURE;
	}

	/* Initializations */
	initialize();

	/* Read input file buff-by-buff and handle the events */
	while (fgets(buff, BUFFER_SIZE, fin))
	{

		DPRINT("\n>>> Event: %s", buff);

		switch (buff[0])
		{

		/* Comment */
		case '#':
			break;

		/* Register player
			 * P <pid><is_alien> */
		case 'P':
		{
			int pid;
			int is_alien;
			sscanf(buff, "%c %d %d", &event, &pid, &is_alien);
			DPRINT("%c %d %d\n", event, pid, is_alien);

			if (register_player(pid, is_alien))
			{
				DPRINT("P %d %d succeeded\n", pid, is_alien);
			}
			else
			{
				fprintf(stderr, "P %d %d failed\n", pid, is_alien);
			}

			break;
		}

		/* Insert task
			 * T <tid><difficulty>  */
		case 'T':
		{
			int tid, difficulty;

			sscanf(buff, "%c %d %d", &event, &tid, &difficulty);
			DPRINT("%c %d %d\n", event, tid, difficulty);

			if (insert_task(tid, difficulty))
			{
				DPRINT("%c %d %d succeded\n", event, tid, difficulty);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, tid, difficulty);
			}

			break;
		}

		/* Distribute Tasks
			 * D */
		case 'D':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (distribute_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Implement Task
			 * I <pid> <difficulty> */
		case 'I':
		{
			int pid, difficulty;

			sscanf(buff, "%c %d %d", &event, &pid, &difficulty);
			DPRINT("%c %d %d \n", event, pid, difficulty);

			if (implement_task(pid, difficulty))
			{
				DPRINT("%c %d %d succeeded\n", event, pid, difficulty);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid, difficulty);
			}

			break;
		}

		/* Eject Player
			 * E <pid>*/
		case 'E':
		{
			int pid;

			sscanf(buff, "%c %d", &event, &pid);
			DPRINT("%c %d\n", event, pid);

			if (eject_player(pid))
			{
				DPRINT("%c %d succeeded\n", event, pid);
			}
			else
			{
				fprintf(stderr, "%c %d failed\n", event, pid);
			}

			break;
		}

			/* Witness Ejection
                 * W <pid> <pid_a> <number_of_witnesses>
                 */
		case 'W':
		{
			int pid, pid_a, number_of_witnesses;

			sscanf(buff, "%c %d %d %d", &event, &pid, &pid_a, &number_of_witnesses);
			DPRINT("%c %d %d %d\n", event, pid, pid_a, number_of_witnesses);

			if (witness_eject(pid, pid_a, number_of_witnesses))
			{
				DPRINT("%c %d %d %d succeded\n", event, pid, pid_a, number_of_witnesses);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d failed\n", event, pid, pid_a, number_of_witnesses);
			}

			break;
		}

		/* Sabbotage
			 * S <number_of_tasks><pid> */
		case 'S':
		{
			int pid, number_of_tasks;

			sscanf(buff, "%c %d %d\n", &event, &number_of_tasks, &pid);
			DPRINT("%c %d %d\n", event, number_of_tasks, pid);

			if (sabbotage(pid, number_of_tasks))
			{
				DPRINT("%c %d %d succeeded\n", event, number_of_tasks, pid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, number_of_tasks, pid);
			}

			break;
		}

		/* Vote
			 * V <pid> <vote_evidence> */
		case 'V':
		{
			int pid, vote_evidence;

			sscanf(buff, "%c %d %d\n", &event, &pid, &vote_evidence);
			DPRINT("%c %d %d\n", event, pid, vote_evidence);

			if (vote(pid, vote_evidence))
			{
				DPRINT("%c %d %d succeeded\n", event, pid, vote_evidence);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid, vote_evidence);
			}

			break;
		}

		/* Give Away Work
			 * G */
		case 'G':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (give_work())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Terminate
			 * F */
		case 'F':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (terminate())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}
		/* Print Players
			 * X */
		case 'X':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_players())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}
		/* Print Tasks
			 * Y */
		case 'Y':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}
		/* Print Stack
			 * Z */
		case 'Z':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_stack())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}
		/* Print Players & Tasks list
			 * F */
		case 'U':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_double_list())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}
		/* Empty line */
		case '\n':
			break;

		/* Ignore everything else */
		default:
			DPRINT("Ignoring buff: %s \n", buff);

			break;
		}
	}

	free_all();
	return (EXIT_SUCCESS);
}
