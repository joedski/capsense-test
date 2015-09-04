Test Setups
===========



Other notes
-----------

**The Arduino is connected to an *ungrounded* laptop during these tests.  This is noted so that identical test conditions may be reproduced.**

### Using the Frame of the Apiary

The Frame just didn't allow enough build up of charge to be usable at range.  It works on contact, just not at range.  No spooky action, but could be used for something else.  Maybe it changes the light animation.



Conclusions
-----------

### Sensing and Timing

A half-second resolution for sensing should be fine, although a timeout of 1 second should be used.  The baseline should be set during the Apiary's Initial State.  Not sure how the sensor will work while embedded within the box, given its proximity to other metal components, especially grounded or signal-bearing ones.  Perhaps just enough sensitivity that the person can just touch the side of the box to make the 'copter land?  If the range can be farther, then that's good, but I'm not too optimistic.  Still, tests are required.  Perhaps I should do an initial free-roaming trial with some copper tape, then try putting some in the box and see what happens.

> Aside: that it's likely we'll need to rearrange some things in the Apiary to accomodate the second arduino.  Perhaps move the sensor into the middle.  We could recut the hex, but it works well enough already so that's not so necessary.

### Ground Plate

Passive components not connected to any circuits seem to have no effect, so there's no possibility for shielding.  Grounded components see to just form another side of a capacitor, and so cause the hand to have no effect until moving the components themselves closer or father away from eachother.

### Top Dialectric Cover

On the topic of cover, covering both sides of the sensing metal component with a thick dialectric (Setup 3A) seems to make it less sensitive than covering one side with a thick dialectric and the other with a thin one.  However, this wasn't too thorough since the other thick dialectric I used was a 1/4" thick piece of polycarbonate.  *I should see if wood has the same effect.*



Setup 1A
--------

- Materials, top down:
	- Cover: Paper
	- Sensor: Foil (~4.5" x ~1")
	- *No Ground Plate*
	- Table: 3/4" Wood
- Circuit:
	- Signal Pin (4)
	- 5MΩ Resistance
	- Sensor
	- Join:
		- Path 1:
			- Sense Pin (2)
		- Path 2:
			- 100pF Cap
			- Ground
- Config:
	- Timout: 1000ms
	- Samples: 30
- Observed Readings:
	- 191e3 @ 4", 500ms
	- 131e3 @ 1", 350ms
	- 114e3 @ 1/2", 300ms
	- 191e3 @ 0", 500"

This one is curious.  The detection range is farther, upwards of 4", but rather than going up, the values go down as the hand gets closer.  Note that the paper cover is necessary.  Without the paper cover, the value and distance ranges are different. (See *Setup 1B*).

Note: The range works omnidirectionally around sensor, even through the table.

### Setup 1A-1

- Materials:
	- Sensor: Foil (~3.5" x ~1")
- Observed Readings:
	- 100e3 @ ~10~12", 270ms (!)
	- 110e3 @ ~3", 290ms
		- @ 4.5"?
	- 191e3 @ 1", 500ms

Oddly, this one only increases.  It does not decrease in value, like in *1A*.  Hm.

### Setup 1A-2

- Materials:
	- 3/4" MDF Cover
	- Sensor: Foil (~3.25" x ~1")
- Observed Readings:
	- 101e3 @ ~5", 265ms
	- 110e3 @ ~ 2", 290ms
	- 191e3 @ Contact with Cover, 500ms

Like *1A-1*, this one also only increases.  However, all of the *1A* trials have a total difference of nearly 90e3 between the farthest detection threshold and the nearest.



Setup 1B
--------

> Derived from 1A.

- Materials, top down:
	- *No Cover*
	- Sensor: Foil (~4.5" x ~1")
	- *No Ground Plate*
	- Table: 3/4" Wood
- Circuit:
	- Signal Pin (4)
	- 5MΩ Resistance
	- Sensor
	- Join:
		- Path 1:
			- Sense Pin (2)
		- Path 2:
			- 100pF Cap
			- Ground
- Config:
	- Timout: 1000ms
	- Samples: 30
- Observed Readings:
	- 115e3 @ 2", 500ms
	- 109e3 @ 1", 300ms
	- 190e3 @ <1/2", 500ms

The range is reduced, so not as good as 1A.



Setup 2A
--------

> Derived from 1A.

- Materials, top down:
	- Cover: Paper
	- Sensor: Foil (~4.5" x ~1")
	- Separator: Paper
	- Ground Plate: Foil (~11" x 3")
		- *Not* connected to any circuit.
	- Table: 3/4" Wood
- Circuit:
	- Signal Pin (4)
	- 5MΩ Resistance
	- Sensor
	- Join:
		- Path 1:
			- Sense Pin (2)
		- Path 2:
			- 100pF Cap
			- Ground
- Config:
	- Timout: 1000ms
	- Samples: 30
- Observed Readings:
	- 191e3 @ 4", 500ms
	- 135e3 @ 1", 350ms
	- 191e3 @ contact, 300ms

This one seems to work the same as 1A.  Curiously, the disconnected plate does not have any effect when coming from the bottom.



Setup 2B, 2C
------------

> Derived from 2A.

- Materials, top down:
	- Cover: Paper
	- Sensor: Foil (~4.5" x ~1")
	- Separator: Paper
	- Ground Plate: Foil (~11" x 3")
		- Setup 2B: Connected to Arduino's ground.
		- Setup 2C: Connected to Arduino's ground through a 100pF cap.
	- Table: 3/4" Wood
- Circuit: Sensor:
	- Signal Pin (4)
	- 5MΩ Resistance
	- Sensor
	- Join:
		- Path 1:
			- Sense Pin (2)
		- Path 2:
			- 100pF Cap
			- Ground
- Config:
	- Timout: 1000ms
	- Samples: 30
- Observed Readings:
	- 136e3 @ ?, 360ms
	- 191e3 @ press, 500ms

The values do not seem to change appreciably, although curiously, there's about a 1k drop in the observed reading if a hand is within about 8" of the sensor, but the value does not otherwise change appreciably.

Connecting the ground through a capacitor (100pF) made no appreciable difference.



Setup 3A
--------

- Materials, top down:
	- Cover: 1/4" Polycarbonate
	- Sensor: Foil (~4.5" x ~1")
	- *No Ground Plate*
	- Table: 3/4" Wood
- Circuit:
	- Signal Pin (4)
	- 5MΩ Resistance
	- Sensor
	- Join:
		- Path 1:
			- Sense Pin (2)
		- Path 2:
			- 100pF Cap
			- Ground
- Config:
	- Timout: 1000ms
	- Samples: 30
- Observed Readings:
	- (Need to actually write these down.)

The sensitivity is greatly reduced, here, although not inexistent.  Coming from either side, the range is reduced from the 4+" in Setup 1A to about 1/2" to 1".

Need to try a variation which uses wood as the dialectric cover rather than plastic to see what effect that may have.
