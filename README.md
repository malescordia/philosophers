# philosophers

Welcome to the philosophers project repository by malescordia.

## Overview
The Dining Philosophers project is a classic synchronization and concurrency problem often used in computer science education. This project challenges participants to develop a solution for a scenario where a number of philosophers sit around a dining table, alternating between thinking and eating, while sharing a limited number of forks.

## Project Highlights
- Concurrency Management: Implements a solution to manage concurrent activities of philosophers, preventing deadlock and ensuring fair access to forks.
- Thread Synchronization: Utilizes threading concepts and synchronization mechanisms, such as mutexes, to control access to shared resources.
- Philosopher Actions: Defines the actions of philosophers, including thinking, eating, and waiting, with proper synchronization to avoid conflicts.
- The project is implemented in the C programming language, providing participants with a deep understanding of low-level concepts related to concurrency and synchronization.

## How to Use
1. Clone the repository: `git clone https://github.com/malescordia/philosophers.git`
2. Navigate to the project folder: `cd philosophers/philo`
3. Compile the program: `make`
4. Run with a list of integers: `./philo 5 800 200 200 7`
