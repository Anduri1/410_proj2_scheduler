/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"


void Scheduler::add(PCB p) { // What is p here??
	sort(); // Think this goes here? Does it call child func?

	if(p.isEmpty()) {
		PCB x;
		ready_q->push(x);
	} else {

	}

	//if (preemptive) {
		//ready_q->push(p);
	//} else {
		//PCB np;
		//ready_q->push(p);
	//}
}

PCB Scheduler::getNext() {
	PCB x;
	x = ready_q->front();
	//ready_q->pop();
	return x; // New PCB object that equals first ready_q;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) { // for preemptive modulo time slice by tick count if == 0, watch out for edge case where when first put on CPU it will also be 0
	if (p.remaining_cpu_time == 0) {
		getNext();
		return true;
	} else if (preemptive) { // time slice should = 0, which should be false, so !0 = true
		if ((p.arrival_time == p.start_time)) {
			return false;
		} else if (time_slice % tick_count == 0) {
			getNext();
			return true;
		}
	}
	return false;
}
