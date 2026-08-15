# Philosophers

**Philosophers** is a 42 school project that introduces the basics of threading a process. You will learn how to create threads and discover mutexes.

## The Dining Philosophers Problem
- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
- While they are eating, they are not thinking nor sleeping;
- While thinking, they are not eating nor sleeping;
- And, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

## Getting Started

### Prerequisites
- GCC compiler
- GNU Make

### Compilation
To compile the project, run:
```bash
cd philo
make
```

### Usage
Run the executable with the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers**: The number of philosophers and also the number of forks.
- **time_to_die** (in milliseconds): If a philosopher didn’t start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- **time_to_eat** (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- **time_to_sleep** (in milliseconds): The time a philosopher will spend sleeping.
- **number_of_times_each_philosopher_must_eat** (optional argument): If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Examples
A philosopher should not die:
```bash
./philo 5 800 200 200
```
A philosopher should die:
```bash
./philo 4 310 200 100
```
Simulation should stop after each philosopher has eaten 7 times:
```bash
./philo 5 800 200 200 7
```

## Authors
- JNTHNN
