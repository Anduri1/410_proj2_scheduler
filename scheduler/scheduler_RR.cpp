/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */


#include "../includes/scheduler_RR.h"

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	//return Scheduler::time_to_switch_processes(tick_count, p);
	if (time_slice % tick_count == 0) {
		//get_process_off_core();
		//put_process_on_core();
		return true;
	}
	return false;
}

void Scheduler_RR::sort() {}
