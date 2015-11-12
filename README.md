### Building an Ambient Display
## Network Strength Simulation
​An Ambient Display which visually depicts the strength of the wifi signal. It has 2 LED strips. One for indicating the download speed, the other for the upload speed. The upload speed strip has lights flowing upwards in a set of 3, while the download strip has lights trickling down. The speed with which the light flows, indicate the appropriate strength of the signal.

This is how the intuitive color scheme and light mechanism conveys the speed information:
#### Low Speed: Red Lights, Less Brightness, Slow speed in the flow
#### Medium Speed: Yellow Lights, Medium Brightness, Average speed
#### High Speed:
Upload: Blue Lights, Bright Lights, High speed of flow  and Download: Green Lights, Bright Lights, High speed of flow

To mask the LEDs from looking like distinct bulbs, and to also make it more appealing, we have used a water dispenser to create a "Water Wall effect". This is optional and is being only used for aesthetic purposes. (Please note: There is no direct 1-to-1 mapping between the signal strength in bytes/sec to the LED flow. We have identified a range for what can be considered as "High Speed", "Medium Speed", and "Low Speed" based on the standards mentioned here:http://www.speedguide.net/faq/how-does-rssi-dbm-relate-to-signal-quality-percent-439. Based on these ranges, we have set the LED speeds arbitrarily to a value which makes them visually distinguishable)

![Network Strength Simulation](/Components/AmbientDisplayPics.jpg)
Format: ![Network Strength Simulation](/Components/AmbientDisplayPics.jpg)

####[Instructable Article]()

### Components Used
---
##### Kit
Sparkfun Photon Kit

##### Sensors


##### LEDs

[Circuit layouts can be viewed here](https://github.com/nathan5x/IoT-DataViz/tree/master/CircuitLayouts)

### Motivation
---
Inspired by number of dashboards at various places like Airport, Stock Markets, and Weather Monitoring Station.

### API Reference
---
This project is grateful to various Web APIs and JavaScript frameworks. Here are the list of references,

* [jQuery](https://jquery.com/)
 - jQuery for all the DOM Manipulations.

* [Twitter Bootstrap](http://getbootstrap.com/)
 - Elegant CSS and JS framework for building responsive, and mobile first projects.

* [Custom Creative Bootstrap Theme](http://startbootstrap.com/template-overviews/creative/)
 - Custom Bootstrap theme.

### Contributors
---
Want to be one? Drop your GitHub username in comments. I will add you in the list. :)
