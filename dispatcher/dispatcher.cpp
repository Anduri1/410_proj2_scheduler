/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

//#include "PCB.h";
//#include "CPU.h"
#include "../includes/dispatcher.h";

PCB Dispatcher::get_from_CPU() {

	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB  &process) {
	cpu->put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}
