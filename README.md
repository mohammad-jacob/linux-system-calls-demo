# 📚 Linux System Calls

System calls are the interface between user programs and the operating system kernel. They allow a program to request services such as process creation, execution, and termination from the OS.

In Linux, system calls are essential for process management, which includes creating, executing, synchronizing, and terminating processes.

---

## 🔹 1. `fork()`

### 📖 Definition
The `fork()` system call is used to create a new process. The newly created process is called the **child process**, and the original process is called the **parent process**.

### ⚙️ Working
- When `fork()` is called, the OS creates an exact copy of the parent process  
- Both processes continue execution from the same point  
- `fork()` returns:
  - `0` in the child process  
  - Process ID (PID) of child in parent  
  - `-1` if creation fails  

### 🧠 Key Points
- Both parent and child run concurrently  
- They have separate memory spaces  

---

## 🔹 2. `exec()`

### 📖 Definition
The `exec()` system call is used to replace the current process with a new program.

### ⚙️ Working
- After calling `exec()`, the existing process code is replaced  
- The process ID (PID) remains the same  
- Execution starts from the new program  

### 🧠 Key Points
- Does not create a new process  
- Used after `fork()` to run a different program  

👉 Common variants: `execl()`, `execp()`, `execv()`

---

## 🔹 3. `wait()`

### 📖 Definition
The `wait()` system call is used by a parent process to wait for its child process to finish execution.

### ⚙️ Working
- Parent process is suspended until child terminates  
- Returns the process ID of the terminated child  

### 🧠 Key Points
- Prevents creation of zombie processes  
- Ensures proper process synchronization  

---

## 🔹 4. `exit()`

### 📖 Definition
The `exit()` system call is used to terminate a process.

### ⚙️ Working
- Ends the execution of a process  
- Returns a status value to the parent process  

### 🧠 Key Points
- Frees resources used by the process  
- Status can be checked by parent using `wait()`  

---

## 🔄 Overall Flow

```text
fork() → creates a child process  
exec() → loads a new program into child (optional)  
wait() → parent waits for child to finish  
exit() → process terminates  