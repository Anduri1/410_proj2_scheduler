/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/scheduler.h";

void Scheduler::add(PCB p) {
	if (preemptive) {
		ready_q->push(p);
	} else {
		PCB np;
		ready_q->push(np);
	}
	sort(); // Think this goes here? Does it call child func?
}

PCB Scheduler::getNext() {
	return ready_q->pop();
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time == 0) {
		return true;
	} else if (preemptive && !time_slice) { // time slice should = 0, which should be false, so !0 = true
		return true;
	}
	return false;
}
