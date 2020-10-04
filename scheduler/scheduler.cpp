/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"


void Scheduler::add(PCB p) {

	ready_q->push(p);
	sort(); // sort for SRTF
}

PCB Scheduler::getNext() {
	PCB x;
	x = ready_q->front();
	ready_q->pop();
	return x;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}
// Need to fix this......... As long as all other scheduler time_to_switch are handled here, I'll be fine
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) { // for preemptive modulo time slice by tick count if == 0, watch out for edge case where when first put on CPU it will also be 0
	if ((p.arrival_time == p.start_time)) {
		return false; // Think this is good
	} else if (preemptive) {
		//if ((p.arrival_time == p.start_time)) {
				//return false;
		//}
		if (time_slice % tick_count == 0) { //think can do !(expression) cuz 0 is false in c++
			return true;
		}
		//return true;
	} else if (p.remaining_cpu_time == 0) { //think can do !(expression) cuz 0 is false in c++
		return true;
	}
	return false;
}
