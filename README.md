Fusion
======

Fusion is an ANSI C99 compliment sensor fusion library for sensor arrays of gyroscopes, accelerometers, and magnetometers.  Fusion was specifically developed for use with embedded systems and has been optimised for execution speed.  The library includes modules for: attitude and heading reference system (AHRS) sensor fusion, gyroscope bias correction, and a tilt-compensated compass.

AHRS sensor fusion algorithm
----------------------------

The AHRS sensor fusion algorithm to combines gyroscope, accelerometer, and magnetometer measurements into a single measurement of orientation relative to the Earth (NWU convention).

The algorithm can be used with only gyroscope and accelerometer measurements, or only gyroscope measurements.  Measurements of orientation obtained without magnetometer measurements can be expected to drift in the yaw component of orientation only.  Measurements of orientation obtained without magnetometer and accelerometer measurements can be expected to drift in all three degrees of freedom.

The algorithm also provides a measurement of linear acceleration and Earth acceleration.  Linear acceleration is equal to the accelerometer  measurement with the 1 g of gravity subtracted.  Earth acceleration is a measurement of linear acceleration in the Earth coordinate frame.

The algorithm outputs a quaternion describing the Earth relative to the sensor.  The library includes a quaternion conjugate function for converting this to a quaternion describing the sensor relative to the Earth, as well as functions for converting a quaternion to a rotation matrix and Euler angles.

Gyroscope bias correction algorithm
-----------------------------------

The gyroscope bias correction algorithm provides an estimate of the gyroscope bias to achieve run-time calibration.  The algorithm will detect when the gyroscope is stationary for a set period of time and then begin to sample the gyroscope output to calculate the bias as an average.

This algorithm is intended to be used in conjunction with the AHRS sensor fusion algorithm to improve the accuracy of the gyroscope measurements provided to the AHRS sensor fusion algorithm.

Tilt-compensated compass
------------------------

The tilt-compensated compass calculates an angular heading relative to magnetic north using an accelerometer and magnetometer (NWU convention).
