## Journals 
TOTAL TIME: 31.8h

### Journal #1: Left Schematic 1.1h
Jul 10, 2026, 11:39 PM

LAPSE LINK: https://lapse.hackclub.com/timelapse/AHXKs98OKrFT

I used the Pi Pico to wire the left side of my split keyboard PCB. The idea is to have a normal 80% keyboard that can be split into two separate halves when needed. I plan to have a rotary encoder and an OLED screen on each side, which uses a lot of GPIO pins, hence the need for the Pi Pico. I plan to use a USB-C cable to connect each half, as well as a USB-C clone of the Pi Pico. However, I may change the interconnect to prevent any accidents with frying any electronics it's plugged into while live, as the interconnect would be 5V, which can damage certain electronics.
<img src="https://cdn.hackclub.com/019f4f42-89a0-7cf3-873e-cb5913b6bec0/image.png" width="1000">

### Journal #2 : Finished Right side schematic! and fixed left side too. - 1.7h
Jul 11, 2026, 4:22 PM
LAPSE LINK: https://lapse.hackclub.com/timelapse/Qn_e6l_58baJ

RESOURCES USED:
| Resource | LINK |
| - | - |
| Pico split keyboard example | https://github.com/akaenner/picosplit/tree/main/Images |
| OLED with Pi Pico | https://www.instructables.com/How-to-Use-an-OLED-Display-With-Raspberry-Pi-Pico/ |
| Raspberry Pi Pico pinouts | https://learn.adafruit.com/getting-started-with-raspberry-pi-pico-circuitpython/pinouts |
| Pi Pico Power | https://www.penguintutor.com/electronics/pico-power |
| How to use UCB C interconnect | https://forums.raspberrypi.com/viewtopic.php?t=370405 |
| How to power two Pi Pico with one connection | https://forums.raspberrypi.com/viewtopic.php?t=362588 |
| Hackclub keeb tutorial | https://keeb.hackclub.com/docs/pcb-design/ |

While creating the right side of the split, I realized that my split interconnect was off. I deleted the resistors from the CC pins, as it's an interconnect rather than a device. I also added resistors and capacitors to the interconnect to make it more reliable. I fixed the UART connectors, as I used the SPI ones instead of the UART for the interconnect... oops. I considered using 4P4C connectors instead of the USB-C interconnect, as I don't want to accidentally plug the keyboard in with the wrong connector, but other types of connectors have the chance to short while being plugged in, which is a risk I would rather not take. I also fixed some incorrect labelling with the rotary encoders.
<img src="https://cdn.hackclub.com/019f52d7-348d-759e-b54a-aca0eda0cbdf/image.png" width="1000">
<img src="https://cdn.hackclub.com/019f52d7-733c-792f-af99-fb6eb998cc4f/image.png" width="1000">


### Journal #3 : PCB TIME! - 5.7h
Jul 12, 2026, 10:38 PM
LAPSE LINK: https://lapse.hackclub.com/timelapse/Nm9sm-tdtZRg

Longest session of the project (so far)! It wasn't so bad as it was tedious. 
Unfortunately, the left side of the schematic was corrupted, and I had to redo it. I now have backups. I also added all the footprints, but changed the pull-up resistor diodes from SMD to THT, just in case I order an OLED screen that already contains pull-up resistors. I finalized the layout too (80% split with row of macro keys on the left).
<img src="https://cdn.hackclub.com/019f594c-6b06-76fc-b9f9-014be6704611/image.png" width="1000">
Many of the traces were lapping, and as I wanted the form factor to be minimized, I ended up having to reroute a lot of the traces. Something that helped was rerouting some of the GPIO pins in the schematic and putting them in more favourable areas in the PCB. I added breakouts to the PCB, so I can order the entire keyboard with one PCB. It's a little larger than I would have liked, but the overall layout is the same as I imagined when I started this project. Each side of the keyboard contains an OLED screen, rotary encoder, and USB-C receptacle for the interconnect, as well as a Pi Pico each for the MCU. The wiring of the traces was a little difficult, but enough VIAs and anything will work. Mostly it was just tedious.  
<img src="https://cdn.hackclub.com/019f5948-9a0f-7dfe-aad9-1a1c04ce2e91/image.png" width="1000">

### Journal #4 : PCB editing! - 1.2h
Jul 13, 2026, 1:20 PM
Unfortunately, the LAPSE session errored out on the server side, so no link today.
I switched out the PCB traces for the VSYS and GND with larger-width traces (0.4mm to 0.75mm) so the traces could withstand the current coming to and from the power sources. I also rerouted the GND and power traces to be wired in parallel rather than series, in order to reduce the current in the traces. I had to rewire some other traces to make room for the wider ones, but there was enough room that no significant changes were needed.
<img src="https://cdn.hackclub.com/019f5c75-edc9-7085-a2e0-a4afb617a5a7/image.png" width="1000">

### Journal #5 : PCB editing (final time?) - 2.3h
Jul 13, 2026, 7:35 PM
LAPSE LINK: https://lapse.hackclub.com/timelapse/eDsbnPfNF0BU
<img src="https://cdn.hackclub.com/019f5dd0-99e4-7eb8-8661-d0d53e917574/image.png" width="1000">
To make the PCB ready for assembly, I moved 100+ vias off of pads, choosing to use "dog bone" connections instead. I added solder paste to all the footprints of the key switches for the hotswap sockets, as it is needed for the PCBA. I also moved all the PCBA objects like the fuse, USB-C connector and other objects to be on the bottom of the PCB, rather than the top, so that the PCBA can be assembled on one side only.
<img src="https://cdn.hackclub.com/019f5dd5-4e25-7dfe-90f1-5bf55ff4a913/image.png" width="1000">

I tried to add the hotswap sockets, but they are misaligned with the holes of the switch footprints. The CPL file needs to be edited so that the positions of the hotswap sockets are offset to the correct values.
<img src="https://cdn.hackclub.com/019f5dd5-7741-7659-964d-6bd3d19d1374/image.png" width="1000">

### Journal #6 : gotta edit them all (CPL this time) - 0.6h
Jul 13, 2026, 9:10 PM
I forgot to start lapse :( no link this time. Luckily, it was only trial and error and didn't take too long.
Due to differences between the switch socket and the footprint, I had to offset the switch footprint and the center of the hotswap sockets to match the pads on the back of the PCB. If anyone needs the exact numbers, I offset the switch X by -0.635mm and the Y by 3.81mm, and rotated them 180 degrees. This was basically educated guesswork, using trial and error with the dimensions of the two footprints until it looked about right.
<img src="https://cdn.hackclub.com/019f5e29-aa09-7762-8a17-64d8ba3a0ed2/image.png" width="1000">

### Journal #7 : 3D Modeling and PCB editing - 2.8h
Jul 14, 2026, 4:53 PM
LAPSE LINK: https://lapse.hackclub.com/timelapse/LoeWm3Z8hO0E

PCB Editing!.. For the last time. No promises.
<img src="https://cdn.hackclub.com/019f6263-ce19-7235-84e5-19c77bb26d97/image.png" width="1000">

I wanted to make the total dimensions of the PCB footprint smaller, so I changed the position of the mousebites to be on the opposite side, so that the left and right PCBs were swapped in production. This really didn't change the price much, unfortunately. I also added some mounting holes for the PCB to attach to the case or an optional plate. I did have to rewire some traces to make room for the mounting holes, though.

<img src="https://cdn.hackclub.com/019f6265-8b70-7f4d-bde1-ed830bc276ae/image.png" width="1000">

I also made the cases in OnShape. These cases are just simple covers for the bottom of the PCB. The PCB sits on little studs on the bottom of the case, and the rest of the items can be mounted on top of the PCB.

### Journal #8 : 3d modeling 2.0 - 1.2h
Jul 14, 2026, 9:34 PM
LAPSE LINK:https://lapse.hackclub.com/timelapse/20pD51KX2Rlz
<img src="https://cdn.hackclub.com/019f6368-ae3f-7192-b541-90e2c6df831f/image.png" width="1000">

Using this keyboard layout editor and ai03's plate generator, I generated a DXF file for the two plates needed for the keyboard. Using the DFX, I imported the sketch into Onshape and adjusted certain elements of the generated DFX sketch, such as the areas where the two halves meet and the space for the rotary encoder. It was pretty straightforward, but I did accidentally deleted one of the sketches by accident, and both sides' layout had to be changed a tiny bit.
| Resource | LINK |
| - | - |
| Layout Editor | https://www.keyboard-layout-editor.com/#/ |
| Plate Generator | https://kbplate.ai03.com/ |

### Journal #9 : BOM and CPL editing - 1.7h
Jul 16, 2026, 9:26 PM
No lapse link today cause I thought this would take less time than it did :(. Turns out everything takes longer when you think it's straightforward.
Because I changed the layout of the mousebites on the PCB, I had to change the offset of the positions of the CPL again... I gotta write a script to automate this. It's such a pain. I also edited the BOM of the PCB through JLCPCB, which includes the link, part number, etc. Despite that being pretty easy, JLCPCB allows download of the BOM after choosing the parts, but only in .xls format. Converting this from .xls to .csv is pretty straightforward, as long as you can view the .xls format. I used a random online editor for the .xls and VS Code for the .csv file.
<img src="https://cdn.hackclub.com/019f6dac-b1d0-7429-9852-7c5f95cf1bf9/image.png" width="1000">


### Journal #10 : PCB editing for shipping costs - 2.4h
Jul 17, 2026, 6:53 PM
I was going through some sensitive information on my JLCPCB account and shipping accounts, so I didn't use Lapse this time.
<img src="https://cdn.hackclub.com/019f723b-a043-755f-b9d6-dcad5ae19d37/image.png" width="1000">
<img src="https://cdn.hackclub.com/019f723b-172d-7410-a7e7-6dc319a93c0e/image.png" width="1000">
I wanted to lower the shipping costs of the PCB, as it was 40% of the total cost of the PCB. I attempted to split the PCB into two separate halves instead of one with mousebites to reduce the total dimensions of the PCB, and update the BOM and CPL of both of the halves. However, despite all these changes, the total cost of the PCBs actually increased, making all the work rather fruitless. I did, however, manage to find a couple of traces that were too close for the tolerances of the pads.

### Journal #11 : Github - 3.5h
Jul 17, 2026, 9:12 PM
I'm not sure if this counts towards hours worked, but it makes sense to journal it anyway. 
![image](https://cdn.hackclub.com/019f72c3-30f1-724e-80d4-d0f6d92c540a/image.png)
I updated the entire README, as well as added the BOM and CPL. I also added all the photos, as well as created a BOM in the README, including links, prices, notes/specifications, and a short tutorial on how to create the keyboard, as well as my process. The README contains all the resources used, as well as photos of all the files and the process.

### Journal #11 : Ship Changes - 5.6h
Aug 7, 2026, 6:59 PM
I wrote some preliminary firmware for the keyboard, including some temporary placeholders for the OLED screens and rotary encoder behaviours. The keyboard firmware uses QMK, as well as UF2 to flash the firmware.
![image](https://cdn.hackclub.com/019fde6d-d3f3-7ea8-87e4-22408c497c9d/image.png)
I added some spacers, as well as changed the case of the PCB to make the mounting holes recessed rather than pins. This way, the plate can be directly screwed in using tap-in screws from the top of the plate all the way through the spacers and into the plate, mounting the plate and PCB together.
![image](https://cdn.hackclub.com/019fde6f-b7a8-75db-a981-f872e0e6b947/image.png)

### Journal #12 : Silkscreen - 2h
I added some silkscreen art, but most of the time came from trying to draw it out. I had a couple of ideas, but eventually ended with this tree design.
![image](https://cdn.hackclub.com/01a0311c-92fb-76a3-b519-d71221671ada/image.png)
![image](https://cdn.hackclub.com/01a0311c-c991-7987-8c09-45606f55c8e7/image.png)