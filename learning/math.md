# Spacecraft Attitude Control — Complete Math Notes (HW1–HW8)

---

# 1. VECTOR MATH (HW1)

## Dot Product

$$
\mathbf{a} \cdot \mathbf{b} = x x' + y y' + z z'
$$

---

## Cross Product

$$
\mathbf{a} \times \mathbf{b} =
\big( y z' - z y',; z x' - x z',; x y' - y x' \big)
$$

---

## Magnitude (Norm)

$$
|\mathbf{v}| = \sqrt{x^2 + y^2 + z^2}
$$

---

## Normalize

$$
\hat{\mathbf{v}} =
\frac{\mathbf{v}}{|\mathbf{v}|}
===============================

\left(
\frac{x}{\sqrt{x^2+y^2+z^2}},
\frac{y}{\sqrt{x^2+y^2+z^2}},
\frac{z}{\sqrt{x^2+y^2+z^2}}
\right)
$$

---

# 2. MATRIX MATH (HW1)

## Matrix-Vector Multiplication

$$
\mathbf{v'} = M \mathbf{v}
$$

---

## Transpose

$$
M^T_{ij} = M_{ji}
$$

---

## Determinant (3×3)

$$
\det(M) =
a(ei - fh) - b(di - fg) + c(dh - eg)
$$

---

## Matrix Inverse (Adjugate)

$$
M^{-1} = \frac{1}{\det(M)} \cdot \text{adj}(M)
$$

---

## Rotation Matrix (Z-axis)

$$
R_z(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \
\sin\theta & \cos\theta & 0 \
0 & 0 & 1
\end{bmatrix}
$$



---

# 3. QUATERNIONS (HW2)

## Quaternion from Axis-Angle

$$
q =
\left(
\cos\frac{\theta}{2},
n_x \sin\frac{\theta}{2},
n_y \sin\frac{\theta}{2},
n_z \sin\frac{\theta}{2}
\right)
$$



---

## Norm

$$
||q|| = \sqrt{w^2 + x^2 + y^2 + z^2}
$$

---

## Normalize Quaternion

$$
q_{unit} = \frac{q}{||q||}
$$

---

## Conjugate

$$
q^* = (w, -x, -y, -z)
$$

---

## Inverse

$$
q^{-1} = \frac{q^*}{||q||^2}
$$

---

## Quaternion Multiplication (Hamilton Product)

$$
w = w_1w_2 - x_1x_2 - y_1y_2 - z_1z_2
$$

$$
x = w_1x_2 + x_1w_2 + y_1z_2 - z_1y_2
$$

$$
y = w_1y_2 - x_1z_2 + y_1w_2 + z_1x_2
$$

$$
z = w_1z_2 + x_1y_2 - y_1x_2 + z_1w_2
$$

---

## Vector Rotation

$$
\mathbf{v'} = q \cdot (0, \mathbf{v}) \cdot q^{-1}
$$

---

## SLERP

$$
\text{slerp}(q_1, q_2, t) =
\frac{\sin((1-t)\theta)}{\sin\theta} q_1 +
\frac{\sin(t\theta)}{\sin\theta} q_2
$$

---

# 4. SENSOR MODELING (HW3)

## Gaussian Noise (Box-Muller)

$$
z = \sqrt{-2\ln(u_1)} \cos(2\pi u_2)
$$

$$
x = \mu + \sigma z
$$



---

## Gyroscope Measurement

$$
\omega_{measured} = \omega_{true} + bias + noise
$$

---

## Bias Random Walk

$$
bias_{new} = bias + noise \cdot \sqrt{dt}
$$

---

## Process Noise Covariance

$$
Q = \sigma^2 \cdot dt \cdot I
$$

---

## Measurement Covariance

$$
R = \sigma^2 \cdot I
$$

---

## Quaternion Kinematics

$$
\dot{q} = \frac{1}{2} q \cdot (0, \omega)
$$

$$
q_{new} = q + \dot{q} \cdot dt
$$

$$
q_{new} = \text{normalize}(q_{new})
$$



---

# 5. KALMAN FILTER (HW4–HW5)

## Predict Step

### State Propagation

$$
\dot{q} = \frac{1}{2} q \cdot (0, \omega)
$$

---

### Covariance Propagation

$$
P = F P F^T + Q
$$

$$
F = I - [\omega]_\times dt
$$

---

## Skew-Symmetric Matrix

$$
[\omega]_\times =
\begin{bmatrix}
0 & -\omega_z & \omega_y \
\omega_z & 0 & -\omega_x \
-\omega_y & \omega_x & 0
\end{bmatrix}
$$



---

## Update Step

### Residual

$$
\delta q = q_{measured} \cdot q_{estimate}^{-1}
$$

$$
\delta \theta = 2(x, y, z)
$$

---

## Kalman Gain

$$
K = P H^T (H P H^T + R)^{-1}
$$

---

## State Correction

$$
\theta_{corr} = K \cdot \delta\theta
$$

---

## Covariance Update

$$
P = (I - K H) P
$$

---

## Mahalanobis Distance

$$
d = \sqrt{\delta\theta^T S^{-1} \delta\theta}
$$

$$
S = HPH^T + R
$$



---

## RMS Error

$$
RMS = \sqrt{\frac{1}{N} \sum (\text{error})^2}
$$

---

## Quaternion Error Angle

$$
\theta = 2 \cos^{-1}(|q_w|)
$$



---

# 6. CONTROL THEORY (HW6)

## Euler’s Rotation Equation

$$
\tau = I\alpha + \omega \times (I\omega)
$$



---

## Angular Acceleration

$$
\alpha = I^{-1}(\tau - \omega \times (I\omega))
$$

---

## PD Control Law

$$
\tau = k_p e - k_d \omega
$$

---

## Error Vector

$$
e = 2(x, y, z)
$$

---

## Saturation

$$
\tau = \hat{\tau} \cdot \tau_{max}
$$

---

# 7. SIMULATION LOOP (HW7)

Closed-loop system:

$$
\text{Dynamics} \rightarrow \text{Sensors} \rightarrow \text{KF} \rightarrow \text{Controller}
$$



---

# 8. FINAL PROJECT (HW8)

## Gravity Gradient Torque

$$
\tau = \frac{3\mu}{r^3} \left( \hat{r} \times (I \hat{r}) \right)
$$

---

## Magnetic Torque

$$
\tau = m \times B
$$

---

## PID Controller

$$
\tau = k_p e + k_i \int e , dt - k_d \omega
$$

---

## Integral Accumulation

$$
I_{term} = \int e , dt
$$

---

## Bias Random Walk (EKF)

$$
bias_{k+1} = bias_k + noise
$$

---

## Augmented State

$$
x =
\begin{bmatrix}
\delta\theta \
\delta bias
\end{bmatrix}
$$

---

# FINAL SUMMARY

Everything reduces to:

### Linear Algebra

* vectors
* matrices
* cross/dot products

### Rotations

* quaternions
* angular velocity

### Estimation

* Kalman filter equations

### Control

* PD / PID laws

### Physics

* torque, angular motion

---

# END
