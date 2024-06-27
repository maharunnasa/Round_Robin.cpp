# Process Scheduling - Round Robin and Preemptive Priority Scheduling

This is a C++ program that implements two process scheduling algorithms: Round Robin and Preemptive Priority Scheduling. The program calculates and displays the execution order for Round Robin scheduling and the average waiting time for Priority scheduling.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [Contributing](#contributing)
- [License](#license)

## Overview

This program simulates two process scheduling algorithms:
1. **Round Robin Scheduling**: Processes are executed in a cyclic order with a fixed time quantum.
2. **Preemptive Priority Scheduling**: Processes with higher priority are executed first, and execution can be preempted if a higher priority process arrives.

## Requirements

- A C++ compiler (e.g., g++)
- Standard C++ library

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/maharunnasa/process-scheduling.git
   cd process-scheduling

### Code Explanation
The code is structured as follows:

Structures and Functions:

Process: A structure to represent each process with attributes: process ID (pid), burst time (bt), priority (priority), and remaining burst time (remaining_bt).
ComparePriority: A comparison function for the priority queue to sort processes based on priority.
roundRobinScheduling: Function to simulate Round Robin scheduling.
priorityScheduling: Function to simulate Preemptive Priority scheduling.
Main Function:

Prompts the user to input the number of processes and details for each process.
Calls roundRobinScheduling to perform Round Robin scheduling.
Calls priorityScheduling to perform Preemptive Priority scheduling

###Example Output
   ```bash
Enter the number of processes: 3
Enter details for each process:
Process 1 Burst time: 5
Priority: 2
Process 2 Burst time: 3
Priority: 1
Process 3 Burst time: 8
Priority: 3
Enter the time quantum for Round Robin Scheduling: 2
Executing process 1 for time 2
Executing process 2 for time 2
Executing process 3 for time 2
Executing process 1 for time 2
Executing process 2 for time 1
Executing process 3 for time 2
Executing process 1 for time 1
Executing process 3 for time 2
Executing process 3 for time 2
Average waiting time for Priority Scheduling: 6

