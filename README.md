_This project has been created as part of the 42 curriculum by maryaada_

# Philosophers

## Description

Philosophers is a multithreading and synchronization project meant to solve the Dining Philosophers problem. A number of philosophers sit at a round table with one fork between each pair of them. Each philosopher repeatedly eats, sleeps, and thinks, but eating requires picking up both the fork to their left and the fork to their right at the same time. A philosopher who goes too long without eating starves and dies, ending the simulation.

The goal is to simulate this without any philosopher starving, without two philosophers sharing a fork at once, without data races, and without memory leaks, using only threads and mutexes.

Each philosopher runs as its own thread. A fork is represented by a `pthread_mutex_t`: "picking up" a fork means locking its mutex preventing another thread from accessing and modifying it, "putting it down" means unlocking it. A separate monitor thread continuously checks whether any philosopher has starved (time since their last meal exceeds `time_to_die`) or, if a meal limit was given, whether everyone has eaten enough times to stop the simulation.

To avoid deadlock, philosophers don't all pick up forks in the same order. Even-numbered philosophers pick up their right fork first; odd-numbered philosophers pick up their left fork first. This breaks the circular wait that causes deadlock.

## Instructions

### Compilation

run make to create the philo program. Make sure you are inside the ../philo directory as required by the subject
```bash
make
```

Builds the `philo` program using using the usual 42 flags + `-pthread` to compile the pthread.h library.

### To run the program
it needs a specific number of arguments, error handling is 

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers` — how many philosophers (and forks) are at the table.
- `time_to_die` (ms) — if a philosopher doesn't start eating within this many ms of their last meal (or the start of the simulation), they die.
- `time_to_eat` (ms) — how long a philosopher holds both forks while eating.
- `time_to_sleep` (ms) — how long a philosopher sleeps after eating.
- `number_of_times_each_philosopher_must_eat` (optional) — if given, the simulation stops once every philosopher has eaten at least this many times. If omitted, the simulation runs until a philosopher dies.

Examples:
```bash
./philo 5 800 200 200        # 5 philosophers, runs until one starves
./philo 5 800 200 200 7      # stops once everyone has eaten 7 times
./philo 1 800 200 200        # single philosopher, only one fork exists, always dies
```

Every state change is logged as:
```
[ timestamp_in_ms ] [ philosopher_id ] has taken a fork
[ timestamp_in_ms ] [ philosopher_id ] is eating
[ timestamp_in_ms ] [ philosopher_id ] is sleeping
[ timestamp_in_ms ] [ philosopher_id ] is thinking
[ timestamp_in_ms ] [ philosopher_id ] died
```

## Resources

- [42 Philosophers subject PDF]
- [POSIX Threads Programming (LLNL tutorial)](https://hpc-tutorials.llnl.gov/posix/)
- The man.
- [pthread functions overview](www.geeksforgeeks.org/c/thread-functions-in-c-c/)
- [Portfolio Courses Youtube Videos on pthread functions](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Oceano Youtube](https://www.youtube.com/watch?v=zOpzGHwJ3MU&)
- [Philosophers project resources compiled playlist](https://www.youtube.com/watch?v=kCGaRdArSnA&list=PLGU1kcPKHMKi41Py2kqxdvqYE3M9VhCHe)
- 42 Students

### AI usage

Claude was used during development and review for:
- Reviewing the finished implementation against the subject and the 42 evaluation sheet, and running the eval sheet's required test cases (single-philosopher death, no-death cases, exact meal-limit stopping, 2-philosopher death timing precision, and output scrambling checks with 100 philosophers).
- Running and interpreting `valgrind --tool=helgrind`, `--tool=drd`, and `--leak-check=full` output to confirm no data races or memory leaks.
- Generating test cases when needed.
- General final check and review.