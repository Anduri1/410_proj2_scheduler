/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */


#include "../includes/scheduler_FIFO.h"

//Scheduler_FIFO::Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED) {}

bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_FIFO::sort(){};
