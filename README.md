# 🍝 Philosophers

> A 42 project simulating the classic **Dining Philosophers Problem** using **threads** and (optionally) **processes**.
> The project explores concurrency, race conditions, and deadlock prevention.

## 🧠 Objective

The goal of this project is to implement a simulation of philosophers who alternately eat, think, and sleep — while sharing forks (resources) — and ensuring that the simulation:

* Avoids **deadlocks**
* Handles **race conditions**
* Terminates on death or condition completion
* Works precisely with **timing**

---

## 🔧 How to Build

### ✅ Mandatory (Thread version)

```bash
cd philo
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### 🧪 Example

```bash
./philo 5 800 200 200
```

This will run 5 philosophers with:

* 800ms to die if they don't eat
* 200ms to eat
* 200ms to sleep

---

### ✨ Bonus (Process + Semaphore version)

```bash
cd philo_bonus
make
./philo_bonus 5 800 200 200
```

> The bonus version uses processes and named semaphores instead of threads and mutexes.

---

## 💡 Program Rules

* A philosopher must **take two forks** to eat.
* Only one philosopher can hold a fork at a time (mutex/semaphore).
* Each action is printed with a timestamp.
* Simulation ends when:

  * A philosopher dies (misses `time_to_die`)
  * All philosophers have eaten `n` times (if specified)

---

## 📘 Allowed Functions

* `pthread_create`, `pthread_join`, `pthread_mutex_*`
* `usleep`, `gettimeofday`, `write`, `malloc`, `free`
* In bonus: `fork`, `waitpid`, `sem_open`, `sem_wait`, etc.

---

## 🧹 Norm & Memory

* 100% **Norminette-compliant**
* No memory leaks or race conditions (validated with `valgrind` and `fsanitize`)
