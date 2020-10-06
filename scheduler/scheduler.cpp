/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

int last_switch_time = 0;

void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort(); // sort for SRTF
}

PCB Scheduler::getNext() {
	PCB pcb;
	pcb = ready_q->front();
	ready_q->pop();
	return pcb;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}
// Need to fix this......... As long as all other scheduler time_to_switch are handled here, I'll be fine
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (preemptive) {
		if (((tick_count - last_switch_time) >= time_slice) || (p.remaining_cpu_time <= 0)) {
			last_switch_time = tick_count;
			return true;
		}
		return false;
	}
	return (p.remaining_cpu_time <= 0);
}
