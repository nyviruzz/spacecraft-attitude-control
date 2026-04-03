# C++ Basics for Writing Code (Beginner → OOP Ready)

---

# 1. What Does a C++ Program Look Like?

Every C++ program starts like this:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    return 0;
}
```

### What this means:

* `#include <iostream>` → lets you print stuff
* `using namespace std;` → avoids typing `std::`
* `main()` → where your program runs
* `cout` → prints output

---

# 2. Variables (Storing Data)

```cpp
int x = 5;
double y = 3.14;
string name = "Visula";
```

### Types:

* `int` → whole numbers
* `double` → decimals
* `string` → text

---

# 3. Writing Your First Function

A function is just a **block of code that does something**

## Basic Function

```cpp
int add(int a, int b) {
    return a + b;
}
```

### How to use it:

```cpp
int main() {
    int result = add(2, 3);
    cout << result << endl; // prints 5
}
```

---

## Function Breakdown

```cpp
int add(int a, int b)
```

* `int` → return type (what it gives back)
* `add` → function name
* `(int a, int b)` → inputs (parameters)

---

# 4. Functions That Don’t Return Anything

```cpp
void sayHello() {
    cout << "Hello!" << endl;
}
```

Call it:

```cpp
sayHello();
```

---

# 5. If Statements (Decision Making)

```cpp
int x = 10;

if (x > 5) {
    cout << "x is big" << endl;
} else {
    cout << "x is small" << endl;
}
```

---

# 6. Loops (Repeating Code)

## For Loop

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

## While Loop

```cpp
int i = 0;

while (i < 5) {
    cout << i << endl;
    i++;
}
```

---

# 7. Creating Your First Class

A class = a custom data type

```cpp
class Car {
public:
    string brand;
    int speed;
};
```

---

# 8. Using a Class (Creating an Object)

```cpp
int main() {
    Car myCar;

    myCar.brand = "Tesla";
    myCar.speed = 120;

    cout << myCar.brand << endl;
}
```

---

# 9. Adding Functions Inside a Class

```cpp
class Car {
public:
    string brand;
    int speed;

    void drive() {
        cout << "Driving at " << speed << endl;
    }
};
```

Use it:

```cpp
myCar.drive();
```

---

# 10. Constructor (Automatic Setup)

```cpp
class Car {
public:
    string brand;

    Car(string b) {
        brand = b;
    }
};
```

Use it:

```cpp
Car myCar("Tesla");
```

---

# 11. Private vs Public (VERY IMPORTANT)

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};
```

### Why?

* Protects your data
* Prevents bad changes

---

# 12. Passing Objects to Functions

## By Value (copy)

```cpp
void printCar(Car c) {
    cout << c.brand << endl;
}
```

## By Reference (better)

```cpp
void printCar(Car& c) {
    cout << c.brand << endl;
}
```

👉 Use reference to avoid copying

---

# 13. Pointers (Intro)

```cpp
int x = 10;
int* ptr = &x;

cout << *ptr << endl; // prints 10
```

### Key Symbols:

* `&` → address of
* `*` → value at address

---

# 14. Dynamic Objects (Heap)

```cpp
Car* c = new Car("Tesla");

cout << c->brand << endl;

delete c;
```

👉 `->` is used for pointers

---

# 15. Simple Example (Putting It Together)

```cpp
#include <iostream>
using namespace std;

class Player {
public:
    string name;
    int health;

    Player(string n, int h) {
        name = n;
        health = h;
    }

    void takeDamage(int dmg) {
        health -= dmg;
    }

    void print() {
        cout << name << " has " << health << " HP" << endl;
    }
};

int main() {
    Player p("Hero", 100);

    p.takeDamage(20);
    p.print();

    return 0;
}
```

---

# 16. How This Connects to Your Physics Engine

You’ll be doing things like:

* Writing classes → objects in your world
* Writing functions → behaviors (update, move, etc.)
* Using variables → store position, velocity, etc.
* Using loops → update every frame

---

# 17. Practice (DO THIS)

### Task 1

Make a class:

* Name: `Object`
* Variables: position (int), velocity (int)

---

### Task 2

Add a function:

* Updates position using velocity

---

### Task 3

Create object in `main`

* Call update multiple times

---

# FINAL MINDSET

Coding = writing instructions step by step

If stuck:

1. Write what you want in plain English
2. Translate to code line by line

---

# END
