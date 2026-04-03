# C++ Notes — Object-Oriented Programming (OOP) Master Guide

---

## Table of Contents

1. Introduction to C++
2. Core OOP Concepts
3. Classes and Objects
4. Constructors & Destructors
5. Encapsulation & Access Control
6. Abstraction
7. Inheritance
8. Polymorphism
9. Virtual Functions & vtable
10. Operator Overloading
11. Friend Functions
12. Static Members
13. Composition vs Inheritance
14. Memory Management
15. Rule of 3 / 5
16. Advanced OOP Concepts
17. Best Practices
18. Common Pitfalls
19. Interview Questions
20. Practice Problems

---

# 1. Introduction to C++

C++ is a **multi-paradigm language**:

* Procedural
* Object-Oriented
* Generic (Templates)

Why OOP?

* Models real-world systems
* Improves scalability
* Encourages reusable code

---

# 2. Core OOP Concepts

### 1. Encapsulation

Wrap data + methods together

### 2. Abstraction

Hide implementation details

### 3. Inheritance

Reuse existing classes

### 4. Polymorphism

Same interface, different behavior

---

# 3. Classes and Objects

## Class = Blueprint

```cpp
class Car {
public:
    string brand;
    int speed;

    void drive() {
        cout << "Driving..." << endl;
    }
};
```

## Object = Instance

```cpp
Car c1;
c1.brand = "Tesla";
c1.speed = 120;
c1.drive();
```

---

# 4. Constructors & Destructors

## Constructor

* Runs automatically when object is created

```cpp
class Car {
public:
    string brand;

    Car(string b) {
        brand = b;
    }
};
```

## Types of Constructors

* Default
* Parameterized
* Copy constructor

```cpp
Car(const Car& other) {
    brand = other.brand;
}
```

## Destructor

```cpp
~Car() {
    cout << "Destroyed" << endl;
}
```

* Automatically called when object goes out of scope

---

# 5. Encapsulation & Access Control

## Access Specifiers

| Specifier | Meaning                 |
| --------- | ----------------------- |
| public    | Accessible everywhere   |
| private   | Only inside class       |
| protected | Class + derived classes |

## Example

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

---

# 6. Abstraction

Hide complexity from the user

```cpp
class Car {
public:
    void start() {
        ignite();
    }

private:
    void ignite() {
        cout << "Engine started" << endl;
    }
};
```

User only sees `start()`, not internal logic.

---

# 7. Inheritance

```cpp
class Animal {
public:
    void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Woof" << endl;
    }
};
```

## Types of Inheritance

* Single
* Multiple
* Multilevel
* Hierarchical

---

# 8. Polymorphism

## Compile-Time (Overloading)

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

---

## Runtime (Overriding)

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof" << endl;
    }
};
```

---

# 9. Virtual Functions & vtable

```cpp
Animal* a = new Dog();
a->speak(); // Calls Dog version
```

### How it works:

* Uses **vtable (virtual table)**
* Decides function at runtime

---

# 10. Operator Overloading

```cpp
class Complex {
public:
    int real, imag;

    Complex operator+(Complex obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
};
```

---

# 11. Friend Functions

```cpp
class Box {
private:
    int width;

public:
    friend void printWidth(Box b);
};

void printWidth(Box b) {
    cout << b.width;
}
```

---

# 12. Static Members

```cpp
class Counter {
public:
    static int count;

    Counter() {
        count++;
    }
};

int Counter::count = 0;
```

---

# 13. Composition vs Inheritance

## Inheritance → "is-a"

Dog is an Animal

## Composition → "has-a"

```cpp
class Engine {};

class Car {
private:
    Engine engine;
};
```

✅ Composition is usually better (more flexible)

---

# 14. Memory Management

## Stack vs Heap

```cpp
Car c1;              // Stack
Car* c2 = new Car(); // Heap
```

## Deallocation

```cpp
delete c2;
```

⚠️ Forgetting delete = memory leak

---

# 15. Rule of 3 / 5

If using dynamic memory:

### Rule of 3

1. Destructor
2. Copy Constructor
3. Copy Assignment

### Rule of 5 adds:

4. Move Constructor
5. Move Assignment

---

# 16. Advanced OOP Concepts

## Abstract Classes

```cpp
class Shape {
public:
    virtual void draw() = 0;
};
```

Cannot instantiate

---

## Interface (C++ style)

Pure abstract class:

```cpp
class Printable {
public:
    virtual void print() = 0;
};
```

---

## Multiple Inheritance

```cpp
class A {};
class B {};
class C : public A, public B {};
```

⚠️ Can cause ambiguity (diamond problem)

---

# 17. Best Practices

* Keep variables **private**
* Use **constructors** for initialization
* Prefer **composition over inheritance**
* Use **const correctness**
* Avoid raw pointers (use smart pointers)

---

# 18. Common Pitfalls

❌ Forgetting virtual destructor
❌ Memory leaks
❌ Object slicing

```cpp
Animal a = Dog(); // slicing occurs
```

---

# 19. Interview Questions

### Difference between class and struct?

* struct → public default
* class → private default

---

### What is virtual destructor?

```cpp
virtual ~Base() {}
```

Prevents memory issues in inheritance

---

### Deep vs Shallow Copy

* Shallow → copies pointer
* Deep → copies actual data

---

### What is polymorphism?

Same function name, different behavior

---

# 20. Practice Problems

### Easy

* Create a `Student` class with name + GPA

### Medium

* Build:
  `Vehicle → Car → ElectricCar`

### Hard

* Implement:

  * Operator overloading
  * Dynamic memory class with Rule of 3

---

# FINAL SUMMARY

Master these to dominate OOP in C++:

* Classes & Objects
* Encapsulation
* Inheritance
* Polymorphism
* Memory Management

---

# END
