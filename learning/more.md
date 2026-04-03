# C++ Operator Overloading & Exceptions (Throws) — Beginner to Project Level

---

# 1. Operator Overloading — What It Is

Operator overloading lets you redefine how operators like:

```
+  -  *  ==  << 
```

work for your own classes.

---

## Why You Need This (for your project)

Instead of writing:

```
addVectors(v1, v2)
```

You can write:

```
v1 + v2
```

👉 Makes math code readable (VERY important for physics + matrices)

---

# 2. Mental Model

When you write:

```
v1 + v2
```

C++ internally calls:

```
v1.operator+(v2)
```

---

# 3. Example — Vector Addition

### Math:

[
(x_1, y_1, z_1) + (x_2, y_2, z_2)
=================================

(x_1 + x_2,; y_1 + y_2,; z_1 + z_2)
]

### Code Concept:

```cpp
Vec3 operator+(const Vec3& other) const
```

👉 Means:

* take another vector
* return a new vector

---

# 4. Common Operators You Will Use

## Addition

```
v1 + v2
```

## Subtraction

```
v1 - v2
```

## Scalar Multiplication

```
v * 2
```

## Equality

```
v1 == v2
```

---

# 5. Important Pattern (VERY IMPORTANT)

Operator functions should:

👉 NOT modify original objects
👉 Return a NEW object

Think:

```
result = v1 + v2
```

NOT:

```
v1 changes itself ❌
```

---

# 6. Const in Operator Overloading

```cpp
Vec3 operator+(const Vec3& other) const
```

Two important things:

### `const Vec3& other`

* don’t copy (efficient)
* don’t modify input

### `const` at the end

* don’t modify current object

---

# 7. Special Case — Scalar on Left Side

This won’t work by default:

```
2 * v
```

Because:

* `2` is not a class

So you define a **non-member operator**

---

# 8. Output Operator (VERY USEFUL)

This:

```
cout << v
```

Is actually:

```
operator<<(cout, v)
```

---

# 9. Operator Overloading Summary

| Operator | Purpose         |
| -------- | --------------- |
| +        | vector addition |
| -        | subtraction     |
| *        | scaling         |
| ==       | comparison      |
| <<       | printing        |

---

# 10. Common Mistakes

❌ Modifying the original object
❌ Forgetting `const`
❌ Returning wrong type
❌ Passing by value instead of reference

---

# 11. Exceptions (Throws) — What They Are

Exceptions handle errors safely.

Instead of crashing:

👉 You **throw an error**

---

# 12. Basic Idea

```
throw → something went wrong  
try → attempt code  
catch → handle error  
```

---

# 13. Real Example (Math Problem)

### Problem:

Normalize zero vector

[
(0,0,0)
]

Magnitude:

[
\sqrt{0^2 + 0^2 + 0^2} = 0
]

Then:

[
\frac{x}{0} ❌
]

👉 Undefined

---

# 14. So You Throw an Error

Concept:

```
if (norm is 0)
    throw error
```

---

# 15. Catching the Error

```
try {
    // risky operation
}
catch (error) {
    // handle problem
}
```

---

# 16. Why This Matters for Your Project

You MUST throw errors for:

* Zero vector normalization
* Matrix inverse with det = 0
* Invalid operations

---

# 17. Example Cases from Your Homework

### Vec3 Normalize

[
\text{if } ||v|| < 10^{-12} \rightarrow \text{throw}
]

---

### Matrix Inverse

[
\text{if } |\det(M)| < 10^{-12} \rightarrow \text{throw}
]

---

# 18. Exception Types

## Runtime Error

Used for logic/math problems

## Out of Range

Used for bad indexing

---

# 19. When to Throw

Ask:

👉 “Is this mathematically invalid?”

If yes → throw

---

# 20. When NOT to Throw

Don’t throw for:

* normal operations
* expected cases

Only throw for:

* impossible / undefined states

---

# 21. Key Philosophy

Operator Overloading:
👉 makes your code look like math

Exceptions:
👉 protect your code from invalid math

---

# 22. How They Work Together

Example thinking:

```
Vec3 v = (0,0,0)
v.normalize() → throws error
```

Operator:

```
v1 + v2 → clean math
```

---

# FINAL SUMMARY

Operator Overloading:

* turns code into math
* improves readability
* returns new objects

Exceptions:

* handle invalid states
* prevent crashes
* enforce correctness

---

# MASTER THIS FOR YOUR PROJECT

You will use:

* operator+ for vectors
* operator* for matrices
* throw for invalid math
* try/catch for safety

---

# END
