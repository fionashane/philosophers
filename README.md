
# philosophers - 42 Project

![philosophers](https://img.shields.io/badge/philosophers-42-success)
![Project Grade](https://img.shields.io/badge/Project_Grade-100%2F100-informational)

The **philosophers** project is part of the curriculum at [42 Adelaide](https://www.42adel.org.au), challenging students to implement the dining philosophers problem using multithreading concepts in C. The project aims to develop skills in concurrent programming, synchronisation, and thread management.

## Project Objectives

The main objectives of the Philosophers project are:

- Implement a solution to the dining philosophers problem in C.
- Utilise multithreading concepts to model the philosophers as concurrent threads.
- Implement proper synchronisation mechanisms to avoid deadlock and resource contention.
- Explore the use of mutexes and semaphores for thread coordination.
- Gain hands-on experience with concurrent programming challenges.

## How to Use

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/fionashane/philosophers.git
    ```

2. Go to the philo directory:

    ```bash
    cd philo
    ```

3. Compile the project using the provided Makefile:

    ```bash
    make
    ```

4. Run the philosophers executable:

    ```bash
    ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals]
    ```

    Replace the placeholders with appropriate values for the simulation.

5. Observe the dining philosophers simulation.

## Program Arguments

- **number_of_philosophers**: Number of philosophers at the table.
- **time_to_die**: Time in milliseconds a philosopher can survive without eating.
- **time_to_eat**: Time in milliseconds it takes for a philosopher to eat.
- **time_to_sleep**: Time in milliseconds a philosopher sleeps after eating or thinking.
- **number_of_meals**: Optional - Number of meals a philosopher must eat before the simulation ends (optional).

## Features

- **Multithreading**: Utilise threads to model individual philosophers concurrently.
- **Synchronisation**: Implement proper synchronisation mechanisms to prevent race conditions and deadlock.
- **Thread Management**: Use mutexes and semaphores to coordinate actions between philosophers.
- **Simulation Control**: Control various aspects of the simulation using command-line arguments.
- **Program Output**: Display information about the state and actions of each philosopher during the simulation.
