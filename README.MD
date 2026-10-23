# Model Railway
Control system for my 00 gauge model railway. It is a pre-grouping colliery set on the LNWR.

# Docs and whatnot
This is just for me because idk what im doing

## Relay and isolation
Sections of the layout are electrically isolated then togglable via relays. I use an UD23A08 8-Channel Serial Relay Controller.

On the left-hand side of it there are three pins for data transfer which are used to give the commands to the relay: `GND` `TXD` `RXD`. On the Arduino Uno then pin 11 goes to `RXD` and pin 10 goes to `TXD`. `GND` goes to `GND` too.

On the right-hand side of the it there are two pins for power input: `GND` `VIN`. This takes 12v and will probably want to be powered differently to the train controller (that's for trains *only*)