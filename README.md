# Karve-Split-Keyboard

## What is this?
This is a keyboard, designed to be slightly ergonomic-consious while keeping the orginal layout and familarity of an 80% keyboard. The idea is to create a split keyboard, but with the option to connect the two havles together to create a regular 80% keyboard, inspired from the [Epomaker Split 65](https://epomaker.com/products/epomaker-split-65). Unlike the Split 65, this features an 80% layout with macro keys on the left column, an OLED 0.91 inch screen and rotary encoder on both sides. While making this keyboard, I realized that the format is really similar to the [Keychron Q11](https://www.keychron.com/products/keychron-q11-qmk-custom-mechanical-keyboard) with the macro keys and 80% layout. This keyboard features an unexploded (?) layout, maximizing desk space without comprimising on the number of keys (I need my precious function row). 

Each side of the keyboard is powered by an Pi Pico with an RP2040. The descision behind the RP2040 was due to the number of GPIO pins. Other options such as the nrf52840 and the RP2040-Zero would've worked well for this project, but the number of GPIO pins wouldn't be sufficient for all the switches and the extra features on the keyboard. The OLED screen is a general 0.91 inch 128x32px screen, with optional footprints for pull-up resistors, and the rotary encoder is a regular EC11 push switch. The switches in the keyboard are wired in a matrix with a diode on each switch. The left side is wired as an 8x6 matrix, and the right side is an 9x6 matrix. The switches themselves contain a regular mx hotswap socket which allows for easy switching between switches of the same format.

## How do I get this?
For this keyboard, you need the pcb, switches, stablizers, keycaps, two Pi Picos, two OLED screens and two rotary encoders. You should order the rest of the components using the PCBA option on [JLCPCB](https://jlcpcb.com/). You can order it using the gerbers zip file in the Gerbers file, as well as the [bom.csv](https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/csv%20files/bom.csv) and the [positions-full-pcb-offset.csv](https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/csv%20files/positions-full-pcb-offset.csv). Make sure you choose bottom side assembly. The switches simply slide into the top of the plate and fit into the hotswap sockets on the PCB, the stablizers are plate mounted and can be slotted into the plate, and the keycaps simply go on top of the switches. The OLED screen and Pi Pico must be soldered into the PCB using the pins, making sure they are in the correct orientation. You can set up the firmware direclty using [POG](https://pog.heaper.de/).

## CAD
| <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/full%20assembly%20w%20electronics%20photo.png" width="500"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/full%20case.png" width="500"> |
| - | - |
| <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/left%20case.png" width="500"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/right%20case.png" width="500"> |
| <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/left%20plate.png" width="500"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/right%20plate.png" width="500"> |

This keyboard is printed in two parts, with two different cases for each half of the PCB, as well as two plates for each half.

[ONSHAPE LINK](https://cad.onshape.com/documents/be21bbec0bd274685795aaea/w/a2ca9be3fdf7d240859b7480/e/7d2817619a652fb02e73bd80?renderMode=0&uiState=6a5abe03f499bb71b75dc1e1)



## Schematic
| <img src="https://cdn.hackclub.com/019f52d7-348d-759e-b54a-aca0eda0cbdf/image.png" width="500"> | <img src="https://cdn.hackclub.com/019f52d7-733c-792f-af99-fb6eb998cc4f/image.png" width="500">| 
| - | - |

The schematic contains a matrix for the switches on each side, a simple 4 pin OLED screen with pull-up resistors that can be unpopulated if the screen already has pull-ups, a USB-C UART connector between the two halves, and a fuse and capacitor for the power line. The USB-C UART connections works by splitting the TX and RX lines, as well as passing the 5v through the VSYS and passing the ground through the wire.

## PCB
<img src="https://cdn.hackclub.com/019f6263-ce19-7235-84e5-19c77bb26d97/image.png" width="1000">

The PCB is a simple PCB with traces of varying widths for the purpose of each trace. The power lines and ground lines for the USB-C receptacle were 0.75mm, other ground traces and local power lines are 0.5mm. The PCB also includes M2 holes for the mounting and mousebites so the PCB can be ordered as one part.

## BOM

### JLCPCB BOM
 Qty | References | Component | Manufacturer / Part number | PCB footprint | JLCPCB part | Library |
|---:|---|---|---|---|---|---|
| 2 | `C2, C3` | 10 µF, 50 V, X5R, ±10% ceramic capacitor | Murata `GRM21BR61H106KE43L` | `0805` | [C440198](https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198) | Basic |
| 92 | `D43–D134` | 1 A, 200 V fast-recovery diode | DOWO `ES1D (SOD-123FL)` | `SOD-123FL` | [C22374920](https://jlcpcb.com/partdetail/DOWO-ES1D_SOD_123FL/C22374920) | Extended |
| 2 | `F2, F3` | 500 mA resettable fuse, 33 V | BHFUSE `BSMD1206-050-33V` | `1206` | [C7202014](https://jlcpcb.com/partdetail/BHFUSE-BSMD1206_05033V/C7202014) | Extended |
| 2 | `J2, J3` | USB-C 2.0 receptacle, 16-pin | Korean Hroparts `TYPE-C-31-M-12` | `USB_C_Receptacle_HRO_TYPE-C-31-M-12` | [C165948](https://jlcpcb.com/partdetail/Korean_HropartsElec-TYPE_C_31_M12/C165948) | Extended |
| 2 | `R5, R6` | 47 Ω, ±1%, 100 mW resistor | UNI-ROYAL `0603WAF470JT5E` | `0603` | [C23182](https://jlcpcb.com/partdetail/23909-0603WAF470JT5E/C23182) | Basic |
| 90 | `SW43–SW50`, `SW52–SW92`, `SW94–SW134` | MX-compatible hot-swap socket | HanElectricity `CPG151101S11-16` | See variants below | [C41430893](https://jlcpcb.com/partdetail/HanElectricity-CPG151101S1116/C41430893) | Extended |

<details>
<summary>Hot-swap footprint variants</summary>

| Footprint | Qty |
|---|---:|
| `MX100H` | 77 |
| `MX125H` | 4 |
| `MX150H` | 2 |
| `MX175H` | 2 |
| `MX200H` | 1 |
| `MX225H` | 3 |
| `MX275H` | 1 |
| **Total** | **90** |

</details> 

### PCB and PCBA
| Component | Quantity | Notes / specification | Link | Cost |
|---|---:|---|---|---:|
| Custom split-keyboard PCB set | 1  | Left and right PCB (together) | [JLCPCB](https://jlcpcb.com/) | $64.59 USD |
| Raspberry Pi Pico | 2 | RP2040 USB-C Clone | [LINK](https://www.aliexpress.com/item/1005009245863235.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+11.55%21CAD+11.54%21%21CAD+11.54%21%21%21%402101ca8b17843197791473957e12a8%2112000048456623655%21ct%21CA%213742168056%21%211%210%21) | $8.09 USD |
| Kailh MX-compatible hot-swap socket | 90 | HanElectricity `CPG151101S11-16`; JLCPCB/LCSC `C41430893` | [JLCPCB](https://jlcpcb.com/partdetail/HanElectricity-CPG151101S1116/C41430893) | Included in PCBA |
| Matrix diode | 92 | DOWO `ES1D`, SOD-123FL, 1 A, 200 V; JLCPCB/LCSC `C22374920` | [JLCPCB](https://jlcpcb.com/partdetail/DOWO-ES1D_SOD_123FL/C22374920) | Included in PCBA |
| USB-C 2.0 receptacle | 2 | Korean Hroparts `TYPE-C-31-M-12`; JLCPCB/LCSC `C165948` | [JLCPCB](https://jlcpcb.com/partdetail/TYPE-C-31-M-12/C165948) | Included in PCBA |
| Resettable polyfuse | 2 | BHFUSE `BSMD1206-050-33V`, 500 mA; JLCPCB/LCSC `C7202014` | [JLCPCB](https://jlcpcb.com/partdetail/BHFUSE-BSMD1206_05033V/C7202014) | Included in PCBA |
| 10 µF ceramic capacitor | 2 | Murata `GRM21BR61H106KE43L`, 0805, 50 V, X5R; JLCPCB/LCSC `C440198` | [JLCPCB](https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198) | Included in PCBA |
| 47 Ω resistor | 2 | UNI-ROYAL `0603WAF470JT5E`, 0603, ±1%; JLCPCB/LCSC `C23182` | [JLCPCB](https://jlcpcb.com/partdetail/23909-0603WAF470JT5E/C23182) | Included in PCBA |
| 4.7 kΩ pull-up resistor | 4 optional | Through-hole; only install if the OLED modules do not include I²C pull-ups | Optional | N/A |

### Displays and Controls

| Component | Quantity | Notes / specification | Link | Cost |
|---|---:|---|---|---:|
| 0.91-inch I²C OLED display | 2 | pin order and pull ups | [AliExpress](https://www.aliexpress.com/item/1005008640108394.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+11.39%21CAD+1.42%21%21CAD+1.42%21%21%21%402101ca8b17843197791473957e12a8%2112000046056142550%21ct%21CA%213742168056%21%211%210%21) | $7.70 USD |
| EC11-style rotary encoder with push switch | 2 | EC11 Footprint | [AliExpress](https://www.aliexpress.com/item/1005005622580163.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+4.93%21CAD+1.42%21%21CAD+1.42%21%21%21%402101ca8b17843197791473957e12a8%2112000033780344822%21ct%21CA%213742168056%21%211%210%21) | $3.35 USD |

### Switches and Keycaps

| Component | Quantity | Notes / specification | Link | Cost |
|---|---:|---|---|---:|
| MX-compatible mechanical switch | 90 | 5-pin PCB-mount switches recommendeds | [AliExpress](https://www.aliexpress.com/item/1005005888884109.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+32.19%21CAD+29.12%21%21CAD+29.12%21%21%21%402101ca8b17843197791473957e12a8%2112000034716470009%21ct%21CA%213742168056%21%211%210%21) | $22.53 USD |
| Keycap set | 1 set | Must cover the full split layout and split spacebar | [AliExpress](https://www.aliexpress.com/item/1005009105824301.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+39.22%21CAD+36.74%21%21CAD+36.74%21%21%21%402101ca8b17843197791473957e12a8%2112000047931129388%21ct%21CA%213742168056%21%211%210%21) | $27.45 USD |
| Stabilizers | As required | Required for stabilized keys | [AliExpress](https://www.aliexpress.com/item/1005005793408621.html?spm=a2g0o.cart.0.0.5c6838daXRLmIS&mp=1&pdp_npi=6%40dis%21CAD%21CAD+15.78%21CAD+14.56%21%21CAD+14.56%21%21%21%402101ca8b17843197791473957e12a8%2112000034412755962%21ct%21CA%213742168056%21%211%210%21) | $10.72 USD |

### Case, Plate, and Mounting Hardware

| Component | Quantity | Notes / specification | Link | Cost |
|---|---:|---|---|---:|
| Left keyboard plate | 1 | 3d printed | N/A | N/A |
| Right keyboard plate | 1 | 3d printed | N/A | N/A |
| Left keyboard case | 1 | 3d printed | N/A | N/A |
| Right keyboard case | 1 | 3d printed | N/A | N/A |


### Pico and Display Installation Hardware

| Component | Quantity | Notes / specification | Link | Cost |
|---|---:|---|---|---:|
| 1×20 pin headers | 4 strips | Two rows per Pico if soldering through-hole headers | COMES WITH PI PICO | FREE |
| 1×4 pin headers | 2 | For directly soldering the OLED modules | COMES WITH OLED | FREE |

### Cost Summary

| Category | Cost |
|---|---:|
| PCB fabrication  | $29.90 USD |
| PCB components and assembly | $34.69 USD |
| Picos, displays, and encoders | $19.14 USD |
| Switches and keycaps | $49.98 USD |
| Case, plates, and hardware | N/A |
| Cables and assembly supplies | $10.72 |
| Shipping and taxes | $41.25 USD |
| **Estimated total** | **$185.68 USD** |


## Firmware
The keyboard will use [POG](https://pog.heaper.de/) to generate and configure KMK firmware for the Raspberry Pi Pico.

The final firmware has not yet been generated because POG requires access to the physical Pico and keyboard hardware for setup and testing. Firmware development and validation will be completed after the PCB and components arrive.

Planned firmware features:

- 8/9 × 6 key matrix on each half
- UART communication between the two halves
- Two rotary encoders with push buttons
- Two I²C OLED displays
- Custom keymap and layers
- USB HID keyboard output

After assembly, the generated POG/KMK configuration and installation
instructions will be added to this folder.

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


### Journal #10
I was going through some sensitive information on my JLCPCB account and shipping accounts, so I didn't use Lapse this time.
<img src="https://cdn.hackclub.com/019f723b-a043-755f-b9d6-dcad5ae19d37/image.png" width="1000">
<img src="https://cdn.hackclub.com/019f723b-172d-7410-a7e7-6dc319a93c0e/image.png" width="1000">
I wanted to lower the shipping costs of the PCB, as it was 40% of the total cost of the PCB. I attempted to split the PCB into two separate halves instead of one with mousebites to reduce the total dimensions of the PCB, and update the BOM and CPL of both of the halves. However, despite all these changes, the total cost of the PCBs actually increased, making all the work rather fruitless. I did, however, manage to find a couple of traces that were too close for the tolerances of the pads.