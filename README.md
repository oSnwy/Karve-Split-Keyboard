# Karve-Split-Keyboard

## What is this?
This is a keyboard, designed to be slightly ergonomic-consious while keeping the orginal layout and familarity of an 80% keyboard. The idea is to create a split keyboard, but with the option to connect the two havles together to create a regular 80% keyboard, inspired from the [Epomaker Split 65](https://epomaker.com/products/epomaker-split-65). Unlike the Split 65, this features an 80% layout with macro keys on the left column, an OLED 0.91 inch screen and rotary encoder on both sides. While making this keyboard, I realized that the format is really similar to the [Keychron Q11](https://www.keychron.com/products/keychron-q11-qmk-custom-mechanical-keyboard) with the macro keys and 80% layout. This keyboard features an unexploded (?) layout, maximizing desk space without comprimising on the number of keys (I need my precious function row). 


## Journals


### Journal #1
LAPSE LINK: https://lapse.hackclub.com/timelapse/AHXKs98OKrFT

I used the Pi Pico to wire the left side of my split keyboard PCB. The idea is to have a normal 80% keyboard that can be split into two separate halves when needed. I plan to have a rotary encoder and an OLED screen on each side, which uses a lot of GPIO pins, hence the need for the Pi Pico. I plan to use a USB-C cable to connect each half, as well as a USB-C clone of the Pi Pico. However, I may change the interconnect to prevent any accidents with frying any electronics it's plugged into while live, as the interconnect would be 5V, which can damage certain electronics.
<img src="https://cdn.hackclub.com/019f4f42-89a0-7cf3-873e-cb5913b6bec0/image.png" width="1000">

### Journal #2
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


### Journal #3
LAPSE LINK: https://lapse.hackclub.com/timelapse/Nm9sm-tdtZRg

Longest session of the project (so far)! It wasn't so bad as it was tedious. 
Unfortunately, the left side of the schematic was corrupted, and I had to redo it. I now have backups. I also added all the footprints, but changed the pull-up resistor diodes from SMD to THT, just in case I order an OLED screen that already contains pull-up resistors. I finalized the layout too (80% split with row of macro keys on the left).
<img src="https://cdn.hackclub.com/019f594c-6b06-76fc-b9f9-014be6704611/image.png" width="1000">
Many of the traces were lapping, and as I wanted the form factor to be minimized, I ended up having to reroute a lot of the traces. Something that helped was rerouting some of the GPIO pins in the schematic and putting them in more favourable areas in the PCB. I added breakouts to the PCB, so I can order the entire keyboard with one PCB. It's a little larger than I would have liked, but the overall layout is the same as I imagined when I started this project. Each side of the keyboard contains an OLED screen, rotary encoder, and USB-C receptacle for the interconnect, as well as a Pi Pico each for the MCU. The wiring of the traces was a little difficult, but enough VIAs and anything will work. Mostly it was just tedious.  
<img src="https://cdn.hackclub.com/019f5948-9a0f-7dfe-aad9-1a1c04ce2e91/image.png" width="1000">

### Journal #4
Unfortunately, the LAPSE session errored out on the server side, so no link today.
I switched out the PCB traces for the VSYS and GND with larger-width traces (0.4mm to 0.75mm) so the traces could withstand the current coming to and from the power sources. I also rerouted the GND and power traces to be wired in parallel rather than series, in order to reduce the current in the traces. I had to rewire some other traces to make room for the wider ones, but there was enough room that no significant changes were needed.
<img src="https://cdn.hackclub.com/019f5c75-edc9-7085-a2e0-a4afb617a5a7/image.png" width="1000">

### Journal #5
LAPSE LINK: https://lapse.hackclub.com/timelapse/eDsbnPfNF0BU
<img src="https://cdn.hackclub.com/019f5dd0-99e4-7eb8-8661-d0d53e917574/image.png" width="1000">
To make the PCB ready for assembly, I moved 100+ vias off of pads, choosing to use "dog bone" connections instead. I added solder paste to all the footprints of the key switches for the hotswap sockets, as it is needed for the PCBA. I also moved all the PCBA objects like the fuse, USB-C connector and other objects to be on the bottom of the PCB, rather than the top, so that the PCBA can be assembled on one side only.
<img src="https://cdn.hackclub.com/019f5dd5-4e25-7dfe-90f1-5bf55ff4a913/image.png" width="1000">

I tried to add the hotswap sockets, but they are misaligned with the holes of the switch footprints. The CPL file needs to be edited so that the positions of the hotswap sockets are offset to the correct values.
<img src="https://cdn.hackclub.com/019f5dd5-7741-7659-964d-6bd3d19d1374/image.png" width="1000">

### Journal #6
I forgot to start lapse :( no link this time. Luckily, it was only trial and error and didn't take too long.
Due to differences between the switch socket and the footprint, I had to offset the switch footprint and the center of the hotswap sockets to match the pads on the back of the PCB. If anyone needs the exact numbers, I offset the switch X by -0.635mm and the Y by 3.81mm, and rotated them 180 degrees. This was basically educated guesswork, using trial and error with the dimensions of the two footprints until it looked about right.
<img src="https://cdn.hackclub.com/019f5e29-aa09-7762-8a17-64d8ba3a0ed2/image.png" width="1000">

### Journal #7
LAPSE LINK: https://lapse.hackclub.com/timelapse/LoeWm3Z8hO0E

PCB Editing!.. For the last time. No promises.
<img src="https://cdn.hackclub.com/019f6263-ce19-7235-84e5-19c77bb26d97/image.png" width="1000">

I wanted to make the total dimensions of the PCB footprint smaller, so I changed the position of the mousebites to be on the opposite side, so that the left and right PCBs were swapped in production. This really didn't change the price much, unfortunately. I also added some mounting holes for the PCB to attach to the case or an optional plate. I did have to rewire some traces to make room for the mounting holes, though.

<img src="https://cdn.hackclub.com/019f6265-8b70-7f4d-bde1-ed830bc276ae/image.png" width="1000">

I also made the cases in OnShape. These cases are just simple covers for the bottom of the PCB. The PCB sits on little studs on the bottom of the case, and the rest of the items can be mounted on top of the PCB.

### Journal #8
LAPSE LINK:https://lapse.hackclub.com/timelapse/20pD51KX2Rlz
<img src="https://cdn.hackclub.com/019f6368-ae3f-7192-b541-90e2c6df831f/image.png" width="1000">

Using this keyboard layout editor and ai03's plate generator, I generated a DXF file for the two plates needed for the keyboard. Using the DFX, I imported the sketch into Onshape and adjusted certain elements of the generated DFX sketch, such as the areas where the two halves meet and the space for the rotary encoder. It was pretty straightforward, but I did accidentally deleted one of the sketches by accident, and both sides' layout had to be changed a tiny bit.
| Resource | LINK |
| - | - |
| Layout Editor | https://www.keyboard-layout-editor.com/#/ |
| Plate Generator | https://kbplate.ai03.com/ |

### Journal #9
No lapse link today cause I thought this would take less time than it did :(. Turns out everything takes longer when you think it's straightforward.
Because I changed the layout of the mousebites on the PCB, I had to change the offset of the positions of the CPL again... I gotta write a script to automate this. It's such a pain. I also edited the BOM of the PCB through JLCPCB, which includes the link, part number, etc. Despite that being pretty easy, JLCPCB allows download of the BOM after choosing the parts, but only in .xls format. Converting this from .xls to .csv is pretty straightforward, as long as you can view the .xls format. I used a random online editor for the .xls and VS Code for the .csv file.
<img src="https://cdn.hackclub.com/019f6dac-b1d0-7429-9852-7c5f95cf1bf9/image.png" width="1000">
