# PID Control
---

## Reflection
---
### PID Componets
P or "Proportional" indicates the current cte (Cross Track Error). The car is controlled in proportion to the distance of the car from the center of the lane, and when P error is large, it vibrates greatly and reacts quickly to the input.

I or "Integral" is used to eliminate states that no longer match the target value when approaching the target value. An error that does not match the target value over time is referred to as 'Offset', and the error of the vehicle's controller not reaching the target value can be eliminated.

D or "Differential" brakes on sudden changes in output, while a high coefficient helps reduce overshoot and helps keep the car in the center.

### Parameter Tuning
Tuned by the Ziegler-Nichols method. Ki and Kd were set to 0 and gradually increased Kp until the difference was oscillated. Next, Kd increases the value to quickly reach the reference, and Ki is set to a value as small as possible since there is no steering bias.

Final Parameter
```c++
steer_pid.Init(.1, .0001, 3.);
```

**Note**
▻ Use KP to decrease the rise time.
▻ Use KD to reduce the overshoot and settling time.
▻ Use KI to eliminate the steady-state error.

Jinghua Zhong (Spring 2006). "PID Controller Tuning: A Short Tutorial" (PDF). Retrieved 2011-04-04.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).
