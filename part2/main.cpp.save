/***************************************************************
 *                                                             *
 * file: main.cpp                                              *
 *                                                             *
 * @Author  Skerdi Basha                         		   	   *
 * @Version 1-12-2020                             			   *
 * @email   sbash@csd.uoc.gr                                   *
 *                                                             *
 * @brief   Main function and implemetantion of among_us.h     *
 *          for the needs of CS-240 project 2020               *
 *                                                             *
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>

#include <assert.h>

#include "among_us.h"

unsigned int primes_g[650] = { 
                                 179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                                 233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
                                 283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
                                 353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
                                 419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
                                 467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
                                 547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
                                 607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
                                 661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
                                 739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
                                 811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
                                 877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
                                 947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
                                1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
                                1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151, 
                                1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223, 
                                1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291, 
                                1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373, 
                                1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451, 
                                1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511, 
                                1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583, 
                                1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657, 
                                1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733, 
                                1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811, 
                                1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889, 
                                1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987, 
                                1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053, 
                                2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129, 
                                2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213, 
                                2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287, 
                                2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357, 
                                2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423, 
                                2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531, 
                                2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617, 
                                2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687, 
                                2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741, 
                                2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819, 
                                2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903, 
                                2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999, 
                                3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079, 
                                3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181, 
                                3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257, 
                                3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331, 
                                3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413, 
                                3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511, 
                                3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571, 
                                3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643, 
                                3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727, 
                                3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821, 
                                3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907, 
                                3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989, 
                                4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057, 
                                4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139, 
                                4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231, 
                                4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297, 
                                4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409, 
                                4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493, 
                                4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583, 
                                4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657, 
                                4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751, 
                                4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831, 
                                4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937, 
                                4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003, 
                                5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087, 
                                5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179, 
                            };

//////////////////////////
//TESTED ON SYKO!!!!!////
//TESTED ON SYKO!!!!////
///////////////////////


/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */

Player *player_sentinel = NULL;
int a , b , p=-1;

void print_tasks_list(int id);
void inorder_of_tasks_only(Task* root);

int initialize() {
	//create the sentinel of the Players
	Player* players_sentinel = new Player();
	players_sentinel->pid = -1;
	players_sentinel->is_alien = 0;
	players_sentinel->evidence = 0;
	players_sentinel->tasks = NULL;
	players_sentinel->parrent = NULL;
	players_sentinel->lc = nullptr;
	players_sentinel->rc = nullptr;
	players_tree = players_sentinel;
	player_sentinel = players_sentinel;

	//creating the p number for the hash function
	for(int i=0; i<650; i++){
		if(primes_g[i] > max_tid_g){
			p = primes_g[i];
			break;
		}
	}

	//creating the 2 random numbers
	srand(time(NULL));
	a = rand() % p + 1;
	if(a == p) a--;
	b = rand() % p;

	//creating the hash table
	general_tasks_ht.tasks = new HT_Task *[max_tasks_g](); 
	general_tasks_ht.tasks[1]= NULL;

	//creating the completed tasks priority queue
	completed_tasks_pq = new Completed_Tasks_PQ();
	completed_tasks_pq->tasks = new HT_Task[max_tasks_g]();
	completed_tasks_pq->size = 0;

    return 1;
}

void add_player(int pid, int is_alien){
	Player* Q;
	Player* P = players_tree;
	Player* Prev = NULL;
	while (P->pid != -1){
		Prev = P;
		if(pid < P->pid) P = P->lc;
		else P = P->rc;
	}
	Q = new Player();
	Q->pid = pid;
	Q->is_alien = is_alien;
	Q->evidence = 0;
	Q->tasks = NULL;
	Q->parrent = NULL;
	Q->lc = player_sentinel;
	Q->rc = player_sentinel;
	if(Prev == NULL){
		players_tree = Q;
	}else if(pid < Prev->pid){
		Prev->lc = Q;
		Q->parrent = Prev;
	}else{
		Prev->rc = Q;
		Q->parrent = Prev;
	}
}


/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {
	add_player(pid , is_alien);
	print_players();
    return 1;
}

/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */

//creating the hash_function
int hash_f(int tid){
	return (((a*tid)+b) % p) % max_tasks_g;
}

//creating a function to add tasks to a list
void add_Tasks(int id, int tid, int difficulty){
	HT_Task* newTask = new HT_Task();
	newTask->difficulty = difficulty;
	newTask->tid = tid;
	newTask->next = general_tasks_ht.tasks[id];
	general_tasks_ht.tasks[id] = newTask;
}

void print_tasks_with_chain(){
	for(int i=0; i<max_tasks_g; i++){
		std::cout <<"Chain " << i << ": ";
		print_tasks_list(i);
	}
}

int insert_task(int tid, int difficulty) {
	general_tasks_ht.count++;
	add_Tasks(hash_f(tid) , tid, difficulty);
	print_tasks_with_chain();
	return 1;
}

//create the function to add the tasks to the list of a player
Task* insert_player_task(Task* root, int tid, int difficulty){
    Task* prev = root;
	Task *p = NULL;

	while(1){
		if(root == NULL){
			root = new Task();
			root->tid = tid;
			root->difficulty = difficulty;
			root->lcnt = 0;
			return root;
		}

		if(tid < prev->tid){
			prev->lcnt++;
			p= prev->lc;
			if(p == NULL){
				p = new Task();
				p->lcnt = 0;
				p->tid = tid;
				p->difficulty = difficulty;
				prev->lc = p;
				return root;
			}
		}

		if(tid > prev->tid){
			p = prev->rc;
			if(p == NULL){
				p = new Task();
				p->tid = tid;
				p->difficulty = difficulty;
				p->lcnt = 0;
				prev->rc = p;
				return root;
			}
		}
		prev = p;
	}
}

//ftiaxnw 2 variables gia na kserw p eimai to hash table
int ht_cell;
HT_Task* ht_list;
bool not_added;
int tasks_distributed;

void inorder_D_event(Player* &root){
	if(root->pid != -1){
		inorder_D_event(root->lc);
		if(tasks_distributed >= max_tasks_g) return;
		not_added = true;
		if(!root->is_alien){
			while(not_added){
				if(ht_list == NULL){
					ht_cell++;
					ht_list = general_tasks_ht.tasks[ht_cell];
				}else{
					root->tasks = insert_player_task(root->tasks, ht_list->tid, ht_list->difficulty);
					tasks_distributed++;
					not_added = false;
					ht_list = ht_list->next;
				}
			}

		}
		inorder_D_event(root->rc);
	}
}


/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {
	ht_cell = 0;
	ht_list = general_tasks_ht.tasks[0];
	tasks_distributed = 0;
	while(tasks_distributed < max_tasks_g){
		inorder_D_event(players_tree);
	}
	print_double_tree();
    return 1;
}


//a function to add ellements to the correct order at the priority queue
void insert_pq(int tid , int difficulty){	
	int size = completed_tasks_pq->size;
	completed_tasks_pq->size++;
	completed_tasks_pq->tasks[size].tid = tid;
	completed_tasks_pq->tasks[size].difficulty = difficulty;
	int key , i;
	for(int j=1; j<size+1; j++){
		key = completed_tasks_pq->tasks[j].difficulty;
		tid = completed_tasks_pq->tasks[j].tid;
		i = j-1;
		while(i>=0 && completed_tasks_pq->tasks[i].difficulty < key){
			completed_tasks_pq->tasks[i+1].difficulty = completed_tasks_pq->tasks[i].difficulty;
			completed_tasks_pq->tasks[i+1].tid = completed_tasks_pq->tasks[i].tid;
			i--;
		}
		completed_tasks_pq->tasks[i+1].difficulty = key;
		completed_tasks_pq->tasks[i+1].tid = tid;
	}

}

//a function to delete and return the first element of the priority queue
void delete_pq(int &tid, int &difficulty){
	tid = completed_tasks_pq->tasks[0].tid;
	difficulty = completed_tasks_pq->tasks[0].difficulty;
	for(int i= 0; i<completed_tasks_pq->size-1; i++ ){
		completed_tasks_pq->tasks[i].tid = completed_tasks_pq->tasks[i+1].tid;
		completed_tasks_pq->tasks[i].difficulty = completed_tasks_pq->tasks[i+1].difficulty; 
	}
	completed_tasks_pq->size--;
}

//a function to search the binaryTree
Player* BinarySearch_Players( Player* root, int pid){
	Player* P = root;
	while(P!=player_sentinel && pid != P->pid){
		if(pid < P->pid) P = P->lc;
		else P = P->rc;
	}
	return P;
}

Task* BinarySearch_Tasks(Task* root, int tid){
	Task* P = root;
	while(P!=NULL && tid != P->tid){
		if(tid < P->tid) P = P->lc;
		else P = P->rc;
	}
	return P;
}

Task* TaskParent(Task* root, int tid){
	Task* P = root;
	Task* parent = NULL;
	while(P!=NULL && tid != P->tid){
		parent = P;
		if(tid < P->tid) P = P->lc;
		else P = P->rc;
	}
	return parent;
}

Task* maxValueNode(Task* root){
	Task* t = root;
	Task* prev = NULL;
	while(t){
		prev = t;
		t = t->rc;
	}
	return prev;
}

//a function to find the next to the inorder
Task* minValueNode(Task* task){
	Task* current = task;
	while(current && current->lc!=NULL){
		current = current->lc;
	}
	return current;
}

int delete_players_task(Player* p, int tid){
	Task* t = BinarySearch_Tasks(p->tasks, tid);
	
	if(!t) 	return 0;

	Task* t_parent = TaskParent(p->tasks, tid);
	Task* new_child;

	if(t->lc && t->rc){
		maxValueNode(t->lc)->rc = t->rc;
		new_child = t->lc;
	}
	else if(t->lc){
		new_child = t->lc;;
	}
	else if(t->rc){
		new_child = t->rc;
	}
	else{
		new_child = NULL;
	}

	if(!t_parent){
		p->tasks = new_child;
	}
	else {
		if(t_parent->lc == t){
			t_parent->lc = new_child;
			t_parent->lcnt--;
		}
		else{
			t_parent->rc = new_child;
		}
	}
	insert_pq(t->tid, t->difficulty);
	return 1;
}

void inorder_to_make_zero(Task* root){
	if(root != NULL){
		inorder_to_make_zero(root->lc);
		root->lcnt = 0;
		inorder_to_make_zero(root->rc);
	}
}

int ln=0;
int inoder_to_fix_lcnt(Task* root){
	if(root == NULL){
        return 0;
    }
   root->lcnt = inoder_to_fix_lcnt(root->lc);
   return root->lcnt + 1 + inoder_to_fix_lcnt(root->rc);
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid) {
	Player* main_player = BinarySearch_Players(players_tree, pid);
	
	if(main_player->is_alien) return 0;

	if(main_player == player_sentinel){
		printf("Player doesn't exist.\n");
		return 0;
	}

	Task* check = BinarySearch_Tasks(main_player->tasks , tid);
	if(check == NULL){
		std::cout << "Task doesn't exist" << std::endl;
		return 0;
	}
	delete_players_task(main_player , tid);


	inoder_to_fix_lcnt(main_player->tasks);
	print_double_tree();
    return 1;
}

//a function to find the next to the inorder -- WITHOUT THE SENTINEL
Player* minValueNodePlayer(Player* player){
	Player* current = player;
	while(current != player_sentinel && current->lc!=player_sentinel){
		current = current->lc;
	}
	return current;
}

//a function to delete a player
Player* delete_player(Player* root ,int pid){
	if(root == player_sentinel) return root;

	if(pid < root->pid)
		root->lc = delete_player(root->lc, pid);
	else if(pid > root->pid)
		root->rc = delete_player(root->rc, pid);
	else{
		//node with no child
		if(root->lc->pid == -1 && root->rc->pid == -1){
			root = player_sentinel;
		}
		//one child
		else if(root->lc->pid == -1){
			root->rc->parrent = root->parrent;
			root = root->rc;
		}else if(root->rc->pid == -1){
			root->lc->parrent = root->parrent;
			root = root->lc;
		}
		//2 child
		else{
			Player* temp = minValueNodePlayer(root->rc);
			root->pid = temp->pid;
			root->is_alien = temp->is_alien;
			root->tasks = temp->tasks;
			root->evidence = temp->evidence;
			root->rc = delete_player(root->rc , temp->pid);
		}
		
	}
	return root;
}	

//a function to count the nodes of an BST ~~ need that to create an array to add all 
//elements of an BST and then merge the 2 arrays
int count_nodes(Task* root){
	int lc, rc;
	if(root == NULL){return 0;}
	lc = count_nodes(root->lc);
	rc = count_nodes(root->rc);
	return (lc + rc +1);
}

int count;
//function to add all elements of an BST to an array
void createArray(Task* root, Task array[]){
	if (root != NULL){
		createArray(root->lc , array);
		array[count] = *root;
		count++;
		createArray(root->rc , array);
	}
}

//a function to merge the 2 arrays into one
void mergeArrays(Task arr1[], Task arr2[] , Task arr3[] , int n1, int n2){
	int i=0, j=0, k=0;
	while(i<n1 && j<n2){
		if(arr1[i].tid < arr2[j].tid){
			arr3[k++] = arr1[i++];
		}
		else{
			arr3[k++] = arr2[j++];
		}
	}

	while(i < n1){
		arr3[k++] = arr1[i++];
	}
	while(j < n2){
		arr3[k++] = arr2[j++];
	}
}

Task* Tasks_tree;

//a function to create the tree of a sorted array
void create_tree(Task* root, Task array[],int start, int end){
	int middle = (start+end)/2;
	Task* q = new Task();

	if(start > end) return;

	*q = array[middle];
	q->rc = NULL;
	q->lc = NULL;
	if(root != NULL){
		if(q->tid > root->tid){
			root->rc = q;
		}else{ 
		root->lc = q;
		}
	}else{
		Tasks_tree = q;
	}
	create_tree(q, array, middle+1, end);
	create_tree(q, array, start, middle-1);

}


Task* final_merge(Task* players_tasks1, Task* players_tasks2){
	int n1 = count_nodes(players_tasks1);
	int n2 = count_nodes(players_tasks2);
	Task* array1 = new Task[n1];
	Task* array2 = new Task[n2];
	Task* array3 = new Task[n1+n2]; //TODO na dw gt o vohthos to eixe +2
	count = 0;
	createArray(players_tasks1,array1);
	count =0;
	createArray(players_tasks2, array2);
	mergeArrays(array1,array2,array3,n1,n2);
	create_tree(NULL, array3, 0, n1+n2-1);
	return Tasks_tree;
}


/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2) {
	//find the correct player who gona be ejected
	Player* dead = BinarySearch_Players(players_tree, pid_1);
	
	//find the correct player who gonna take the tasks
	Player* unlucky = BinarySearch_Players(players_tree, pid_2);
	if(dead == player_sentinel || unlucky == player_sentinel){
		return 0;
	}
	
	//merge the 2 players tasks
	if(!dead->is_alien){
	unlucky->tasks = final_merge(dead->tasks, unlucky->tasks);
	ln=0;
		inorder_to_make_zero(unlucky->tasks);
		inoder_to_fix_lcnt(unlucky->tasks);
	}
	//delete the player
	players_tree = delete_player(players_tree, pid_1);
	print_double_tree();
    return 1;
}


std::string text1;
//function to print with inorder all tasks of the players
void inorder_of_tasks_only_with_evidence(Task* root){
	if(root != NULL){
		inorder_of_tasks_only_with_evidence(root->lc);
		text1 +="<";
		text1 += std::to_string(root->tid);
		text1+= ",";
		text1 += std::to_string(root->difficulty);
		text1+=">,";
		inorder_of_tasks_only_with_evidence(root->rc);
	}
}

//function to print with inorder all the players with the tasks together
void inorder_with_tasks_with_evidence(Player* root){
	if(root->pid != -1){
		inorder_with_tasks_with_evidence(root->lc);
		std::cout << "<Player" << root->pid <<"," << root->evidence << ">" <<"=";
		text1 = "";
		inorder_of_tasks_only_with_evidence(root->tasks);
		text1 = text1.substr(0 , text1.length()-1);
		std::cout<< text1 <<std::endl;
		inorder_with_tasks_with_evidence(root->rc);
	}
}

void print_double_tree_with_evidence(Player* root){
	inorder_with_tasks_with_evidence(root);
}

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses){
	//Find the correct player who gona be ejected
	Player* dead = BinarySearch_Players(players_tree, pid_1);
	Player* impostor = BinarySearch_Players(players_tree , pid_a);
	Player* unlucky = BinarySearch_Players(players_tree, pid_2);
	//an den yparxei kapoio ap ayta
	if(dead == player_sentinel || impostor == player_sentinel || unlucky == player_sentinel) {
		return 0;
	}
	//change the impostor witness
	impostor->evidence += number_of_witnesses;

	if(!dead->is_alien){
		unlucky->tasks = final_merge(dead->tasks , unlucky->tasks);
		inorder_to_make_zero(unlucky->tasks);
		inoder_to_fix_lcnt(unlucky->tasks);
	}
	players_tree = delete_player(players_tree, pid_1);

	print_double_tree_with_evidence(players_tree);
    return 1;
}


//function to find the minimum in the tree of players//
Player* FindMinimumPlayer(Player* root){
	Player* search = root;
	while(search->lc!= player_sentinel){
		search = search->lc;
	}
	return search;
}

//function to find the maximum in the tree of players
Player* FindMaximumPlayer(Player* root){
	Player* search = root;
	while(search->rc!= player_sentinel){
		search = search->rc;
	}
	return search;
}


Player* FindInorderPredecessor(Player* root){
	//an mas dwsei ton continel
	if (root == player_sentinel) return root;
	//an mas dwsei ton minimum
	if(root == FindMinimumPlayer(players_tree)) return FindMaximumPlayer(players_tree);

	//case 1: Node has left subtree
	if(root->lc != player_sentinel){
		Player* find = root->lc;
		while(find->rc != player_sentinel){
			find = find->rc;
		}
		return find;
	}
	//Case 2: Node hasnt left subtree
	else
	{
		Player* parent = root->parrent;
		while(parent->pid > root->pid){
			parent = parent->parrent;
		}
		return parent;
	}

}

Player* FindInorderSuccessor(Player* root){
	//an mas dwsei ton centinel
	if (root == player_sentinel) return root;
	//an mas dwsei ton maximum
	if(root == FindMaximumPlayer(players_tree)) return FindMinimumPlayer(players_tree);

	 //case 1: Node has right subtree
	if(root->rc != player_sentinel){
		Player* find = root->rc;
		while(find->lc != player_sentinel){
			find = find->lc;
		}
		return find;
	}
	//Case 2: Node hasnt right subtree
	else
	{
		Player* parent = root->parrent;
		while(parent->pid < root->pid){
			parent = parent->parrent;
		}
		return parent;
	}
}



/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid) {

	if(number_of_tasks > completed_tasks_pq->size){
		number_of_tasks = completed_tasks_pq->size;
	}

	if(number_of_tasks == 0){
		return 0;
	}

	//o paixths pou mas dinei to pid
	Player* searched = BinarySearch_Players(players_tree, pid);
	if(searched == player_sentinel){
		return 0;
	}

	//o paixths p tha parei task
	Player* given_task_Player = searched;

	//vriskw poios tha parei to prwto task
	int tasks = number_of_tasks / 2;
	for(int i=0; i<tasks; i++){
		given_task_Player = FindInorderPredecessor(given_task_Player);
	}
	//vriskw poios tha parei tlk to prwto task pou den einai impostor
	while(given_task_Player->is_alien){
		given_task_Player = FindInorderPredecessor(given_task_Player);
	}
	int tid , difficulty;
	delete_pq(tid, difficulty);
	insert_player_task(given_task_Player->tasks , tid , difficulty);
	
	//vazw ta ypoloipa tasks
	int remain_tasks = number_of_tasks - 1;
	while(remain_tasks >= 1){
		given_task_Player = FindInorderSuccessor(given_task_Player);
		if(!given_task_Player->is_alien){
			delete_pq(tid, difficulty);
			insert_player_task(given_task_Player->tasks , tid , difficulty);
			remain_tasks--;
		}
	}
	
	print_double_tree();
    return 1;
}

void max_evidence(Player* root, Player* &maxEvPlayer){
	if(root == player_sentinel) return;
	max_evidence(root->lc , maxEvPlayer);
	if(root->evidence > maxEvPlayer->evidence) maxEvPlayer = root;
	max_evidence(root->rc , maxEvPlayer);
}

/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence) {
	Player* player1 = BinarySearch_Players(players_tree, pid_1);
	
	// an den yparxei o paixths 1
	if(player1 == player_sentinel){
		return 0;
	}

	player1->evidence += vote_evidence;

	//find the player with the max Evidence
	Player* maxEv = players_tree;
	max_evidence(players_tree , maxEv);
	
	//find the unlucky player
	Player* unlucky = BinarySearch_Players(players_tree, pid_2);

	if(!maxEv->is_alien){
		ln=0;
		unlucky->tasks = final_merge(maxEv->tasks , unlucky->tasks);
		inorder_to_make_zero(unlucky->tasks);
		inoder_to_fix_lcnt(unlucky->tasks);
	}
	players_tree = delete_player(players_tree, maxEv->pid);

	print_double_tree_with_evidence(players_tree);

    return 1;
}

//function to find all nodes of a tree
int find_total_nodes(Task* root){
	int sum = 0;
	while(root){
		sum += root->lcnt +1;
		root = root->rc;
	}
	return sum;
}

//function to split a tree to 2 others
void Split(Task* &D1 , Task* &D2 , Task* root, int nodes){


	Task* p1 = NULL;
	Task* p2 = NULL;
	Task* q = root;
	Task* prev = NULL;

	int sum = 0;

	while(q!= NULL && sum < nodes){
		if(sum + q->lcnt + 1 <= nodes){
			if (D1 == NULL){
				D1 = q;
				p1 = q;
			}else{
				p1->rc = q;
				p1 = q;
			}
			if (D2 == NULL && sum + q->lcnt +1 == nodes){
				D2 = q->rc;
			}
			sum += q->lcnt + 1;
			prev = q;
			q = q->rc;
			prev->rc = NULL;
		}
		else {
			if(D2 == NULL){
				D2 = q;
				p2 = q;
			}else{
				p2->lc = q;
				p2 = q;
			}
			prev = q;
			q = q->lc;
			prev->lc = NULL;
		}
	}
}

/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2) {
	//find the pid_1
	Player* chill = BinarySearch_Players(players_tree , pid_1);
	
	//an den yparxei o typos
	if(chill == player_sentinel) {
		return 0;
	}

	int splited_nodes = find_total_nodes(chill->tasks) / 2;

	//an exei mono 1 node mesa
	if(splited_nodes == 0){
		std::cout << "Not many tasks to split" << std::endl;
		return 0;
	}

	//add the 2nd player
	add_player(pid_2, 0);

	//find the pid_2
	Player* unlucky = BinarySearch_Players(players_tree , pid_2);

	Task* chill_tasks = NULL;
	Task* unlucky_tasks = NULL;

	Split(chill_tasks , unlucky_tasks , chill->tasks , splited_nodes);

	chill->tasks = chill_tasks;
	inorder_to_make_zero(chill->tasks);
	inoder_to_fix_lcnt(chill->tasks);
	unlucky->tasks = unlucky_tasks;
	inorder_to_make_zero(unlucky->tasks);
	inoder_to_fix_lcnt(unlucky->tasks);

	print_double_tree();


    return 1;
}

int aliens_count = 0;
int crewmates_count = 0;
void check_for_aliens(Player* root){
	if(root == player_sentinel) return;
	check_for_aliens(root->lc);
	if(root->is_alien) aliens_count++;
	else crewmates_count += 1;
	check_for_aliens(root->rc);
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {

	check_for_aliens(players_tree);
	if(aliens_count > crewmates_count) {
		std::cout << "Aliens win." << std::endl;
	}
	else if(aliens_count == 0){
		std::cout << "Crewmates win." << std::endl;
	}
	else if(completed_tasks_pq->size == max_tasks_g){
		std::cout << "Crewmates win." << std::endl;
	}
	return 1;
}

//function to print with inorder the players
void inorder(Player* root){
	if(root->pid != -1){
		inorder(root->lc);
		std::cout << "<" << root->pid << ":" << root->is_alien <<">";
		inorder(root->rc);
	}
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
	std::cout << "Players = " ;
	inorder(players_tree);
	std::cout << std::endl;
    return 1;
}


//function to print a list of tasks
void print_tasks_list(int id){
	HT_Task* p = general_tasks_ht.tasks[id];
	while (p != NULL)
	{
		std::cout << "<" << p->tid << "," << p->difficulty << ">";
		if(p->next != NULL) std::cout<<",";
		p = p->next;
	}
	std::cout<<std::endl;
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
	for(int i=0; i<max_tasks_g; i++){
		std::cout <<"Index " << i << ": ";
		print_tasks_list(i);
	}
    return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq() {
	std::cout << "Completed Tasks= ";
	for(int i=0; i< completed_tasks_pq->size; i++){
		std::cout << "<" << completed_tasks_pq->tasks[i].tid << "," << completed_tasks_pq->tasks[i].difficulty << ">";
	}
	std::cout << std::endl;

    return 1;
}

std::stringstream ss;
std::string text;
//function to print with inorder all tasks of the players
void inorder_of_tasks_only(Task* root){
	if(root != NULL){
		inorder_of_tasks_only(root->lc);
		text +="<";
		text += std::to_string(root->tid);
		text+= ",";
		text += std::to_string(root->difficulty);
		text+=">,";
		inorder_of_tasks_only(root->rc);
	}
}

//function to print with inorder all the players with the tasks together
void inorder_with_tasks(Player* root){
	if(root->pid != -1){
		inorder_with_tasks(root->lc);
		std::cout << "Player" << root->pid << "=";
		text = "";
		inorder_of_tasks_only(root->tasks);
		text = text.substr(0 , text.length()-1);
		std::cout<< text <<std::endl;
		inorder_with_tasks(root->rc);
	}
}
/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree() {
	inorder_with_tasks(players_tree);
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void) {
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
	char buff[BUFFER_SIZE], event='\0';

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

	// Read max enemy soldiers' number
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tasks_g);
	DPRINT("Max number of tasks: %d\n", max_tasks_g)

	// Read max enemy soldiers' ID
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tid_g);
	DPRINT("Max task tid: %d\n", max_tid_g)

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

		/* Register Player
		 * P <pid> <is_alien> */
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

		/* Insert Task
		 * T <tid> <difficulty>  */
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
		 * I <pid> <tid> */
		case 'I':
		{
			int pid, tid;

			sscanf(buff, "%c %d %d", &event, &pid, &tid);
			DPRINT("%c %d %d \n", event, pid, tid);

			if (implement_task(pid, tid))
			{
				DPRINT("%c %d %d succeeded\n", event, pid, tid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid, tid);
			}

			break;
		}

		/* Eject Player
		 * E <pid_1> <pid_2>*/
		case 'E':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (eject_player(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
			}

			break;
		}

		/* Witness Ejection
		 * W <pid> <pid_a> <number_of_witnesses>
		 */
		case 'W':
		{
			int pid_1, pid_2 ,pid_a ,number_of_witnesses;

			sscanf(buff, "%c %d %d %d %d", &event, &pid_1, &pid_2, &pid_a, &number_of_witnesses);
			DPRINT("%c %d %d %d %d\n", event, pid_1, pid_2, pid_a, number_of_witnesses);

			if (witness_eject(pid_1, pid_2, pid_a, number_of_witnesses))
			{
				DPRINT("%c %d %d %d %d succeded\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d %d failed\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}

			break;
		}

		/* Sabotage
		 * S <number_of_tasks> <pid> */
		case 'S':
		{
			int number_of_tasks, pid;

			sscanf(buff, "%c %d %d\n", &event, &number_of_tasks, &pid);
			DPRINT("%c %d %d\n", event, number_of_tasks, pid);

			if (sabotage(number_of_tasks, pid))
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
		 * V <pid_1> <pid_2> <vote_evidence> */
		case 'V':
		{
			int pid_1, pid_2, vote_evidence;

			sscanf(buff, "%c %d %d %d\n", &event, &pid_1, &pid_2, &vote_evidence);
			DPRINT("%c %d %d %d\n", event, pid_1, pid_2, vote_evidence);

			if (vote(pid_1, pid_2, vote_evidence))
			{
				DPRINT("%c %d %d %d succeeded\n", event, pid_1, pid_2, vote_evidence);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d failed\n", event, pid_1, pid_2, vote_evidence);
			}

			break;
		}

		/* Give Away Work
		 * G <pid_1> <pid_2> */
		case 'G':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (give_work(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
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

		/* Print Priority Queue
		 * Z */
		case 'Z':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_pq())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Players & Tasks tree
		 * F */
		case 'U':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_double_tree())
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
