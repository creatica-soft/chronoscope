# Chronoscope
Arduino-based simple chronoscope

It uses two pairs of red laser + photodiode receiver for less than a buck each connected to an Arduino board (MEGA in my case but can be any other). The laser+receiver pairs are 10cm apart. When an object (such as BB, for example) crosses a laser beam, an interrupt routine is invoked and reads the time in microseconds using micros() function. Knowing the delay between crossing the first and the second beam, and the distance between them, we calculate the speed: speed in m/s = (distance in meters * 1000000) / (delay in microsec).

![Chronoscope](Chronoscope.jpg)

It can be used to measure a muzzle velocity of an airsoft gun. For example, I struggled to find the spec for a spring model of Tokyo Marui USP. Using this device, which is much cheaper than the commercial products, I measured it. Using 5.95mm 0.2 gramm BBs, the velocity was between 63 and 64 m/s or in kinetic energy (m x v^2)/2 = 0.4 joule. In comparison, gas models of Tokyo Marui BB guns have around 1 joule (or 100 m/s). 

![TM USP spring BB gun](TM-USP-spring-BB-gun.jpg)
