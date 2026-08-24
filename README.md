# Karve-Split-Keyboard

## What is this?
This is a keyboard, designed to be slightly ergonomic-consious while keeping the orginal layout and familarity of an 80% keyboard. The idea is to create a split keyboard, but with the option to connect the two havles together to create a regular 80% keyboard, inspired from the [Epomaker Split 65](https://epomaker.com/products/epomaker-split-65). Unlike the Split 65, this features an 80% layout with macro keys on the left column, an OLED 0.91 inch screen and rotary encoder on both sides. While making this keyboard, I realized that the format is really similar to the [Keychron Q11](https://www.keychron.com/products/keychron-q11-qmk-custom-mechanical-keyboard) with the macro keys and 80% layout. This keyboard features an unexploded (is that the right term) layout, maximizing desk space without comprimising on the number of keys (I need my precious function row). 

Each side of the keyboard is powered by an Pi Pico with an RP2040. The descision behind the RP2040 was due to the number of GPIO pins. Other options such as the nrf52840 and the RP2040-Zero would've worked well for this project, but the number of GPIO pins wouldn't be sufficient for all the switches and the extra features on the keyboard. The OLED screen is a general 0.91 inch 128x32px screen, with optional footprints for pull-up resistors, and the rotary encoder is a regular EC11 push switch. The switches in the keyboard are wired in a matrix with a diode on each switch. The left side is wired as an 8x6 matrix, and the right side is an 9x6 matrix. The switches themselves contain a regular mx hotswap socket which allows for easy switching between switches of the same format.

## How do I get this?
For this keyboard, you need the pcb, switches, stablizers, keycaps, two Pi Picos, two OLED screens and two rotary encoders. You should order the rest of the components using the PCBA option on [JLCPCB](https://jlcpcb.com/). You can order it using the gerbers zip file in the Gerbers file, as well as the [bom.csv](https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/csv%20files/bom.csv) and the [positions-full-pcb-offset.csv](https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/csv%20files/positions-full-pcb-offset.csv). Make sure you choose bottom side assembly. The switches simply slide into the top of the plate and fit into the hotswap sockets on the PCB, the stablizers are plate mounted and can be slotted into the plate, and the keycaps simply go on top of the switches. The plate uses spacers to attach to both the PCB and the case using self-tapping screws through the plate, without the need for unnessecary mounting holes on the thin plate, which may degrade it's strength. The OLED screen and Pi Pico must be soldered into the PCB using the pins, making sure they are in the correct orientation. You can set up the firmware direclty using [POG](https://pog.heaper.de/).

## CAD
| <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/full%20assembly%20w%20electronics%20photo.png" width="500"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/full%20case.png" width="500"> |
| - | - |

| <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/left%20case.png" width="200"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/right%20case.png" width="200"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/Spacer.png" width="200"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/left%20plate.png" width="200"> | <img src="https://github.com/oSnwy/Karve-Split-Keyboard/blob/main/photos/right%20plate.png" width="200"> |
| - | - | - | - | - |

This keyboard is printed in two parts, with two different cases for each half of the PCB, as well as two plates for each half the plate and pcb are seperated by 3.5mm spacers, which are screwed in from the top of the plate to the PCB mounting holes.

[ONSHAPE LINK](https://cad.onshape.com/documents/be21bbec0bd274685795aaea/w/a2ca9be3fdf7d240859b7480/e/7d2817619a652fb02e73bd80?renderMode=0&uiState=6a5abe03f499bb71b75dc1e1)


## Schematic
| <img src="https://cdn.hackclub.com/019f52d7-348d-759e-b54a-aca0eda0cbdf/image.png" width="500"> | <img src="https://cdn.hackclub.com/019f52d7-733c-792f-af99-fb6eb998cc4f/image.png" width="500">| 
| - | - |

The schematic contains a matrix for the switches on each side, a simple 4 pin OLED screen with pull-up resistors that can be unpopulated if the screen already has pull-ups, a USB-C UART connector between the two halves, and a fuse and capacitor for the power line. The USB-C UART connections works by splitting the TX and RX lines, as well as passing the 5v through the VSYS and passing the ground through the wire.

## PCB
<img src="https://cdn.hackclub.com/01a031b7-44f2-780c-9453-a04667f5d790/image.png" width="1000">

The PCB is a simple PCB with traces of varying widths for the purpose of each trace. The power lines and ground lines for the USB-C receptacle were 0.75mm, other ground traces and local power lines are 0.5mm. The PCB also includes M2 holes for the mounting and mousebites so the PCB can be ordered as one part.
| <img src="https://cdn.hackclub.com/01a031b8-2ff8-75bb-b7ff-ea9e0aa844e6/image.png" width="500"> | <img src="https://cdn.hackclub.com/01a0311c-c991-7987-8c09-45606f55c8e7/image.png" width="500">| 
| - | - |

The silkscreen art is put togetrher in a way that (hopefully) will show a full image of the tree when the split halves are put together.
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
| Spacers | 16 | 3d pritned | N/A | N/A |


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
This firmware is the preliminary firmware, and may be changed for the final finished build. It uses QMK, and can be flashed using UF2 and QMK commands.
I used this repositry as a reference: https://github.com/aminch/c64p/tree/main, as well as a couple other websites.

The firmware is grouped under the firmware file in the repositry.
It includes:
| File | Purpose |
| - | - |
| info.json | tells the computer what keyboard/mcu, as well as the USB type. |
| rules.mk | tells the computer what QMK features should be used, such as the I2C OLED. |
| mcuconf.h | enables the rp2040 I2C hardware for the OLED screens. |
| halconf.h | also used to enable the I2C for the OLED screens. |
| config.h | used to define all the pins on the picos for both the left and right split halves, as well as other features such as debounce time, OLED brightness, etc. |
| keymap.c | used to define the keymap as well as the OLED, encoders, as well as layers. |

### rules.mk: 
``` C
MCU = RP2040
BOARD = GENERIC_RP_RP2040
BOOTLOADER = rp2040

ENCODER_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c
```
These lines are used to define the MCU, board, as well as enable rotary encoders and OLED screens.

### config.h: 
``` C
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { GP8, GP9, GP10, GP11, GP12, GP13 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, NO_PIN }

#define MATRIX_ROW_PINS_RIGHT { GP5, GP4, GP3, GP2, GP1, GP0 }
#define MATRIX_COL_PINS_RIGHT { GP14, GP13, GP12, GP11, GP10, GP9, GP8, GP7, GP6 }

#define ENCODER_A_PINS { GP20 }
#define ENCODER_B_PINS { GP21 }
#define ENCODER_A_PINS_RIGHT { GP20 }
#define ENCODER_B_PINS_RIGHT { GP21 }

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP16
#define SERIAL_USART_RX_PIN GP17

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP18
#define I2C1_SCL_PIN GP19
```
This is used to define what each pin is used for, such as the matrix, encoders, as bwell as TX/RX and pins used for the OLED screen etc. The RX/TX are crossed through the USB port, so both sides can have the same RX/TX pins. 

``` C
#define EE_HANDS
```
This means that both of the source codes are the same for both the left and right side.

### keymap.c:
``` C
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = {
        { KC_MUTE, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO },
        { KC_F13,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_NO },
        { KC_F14,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,   KC_NO },
        { KC_F15,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,   KC_NO },
        { KC_F16,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO },
        { KC_F17,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO },
        { KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,  KC_MUTE },
        { KC_NO,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP },
        { KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN },
        { KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME },
        { KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END },
        { KC_NO,   KC_SPC,  KC_RALT, KC_RGUI, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT }
    },
    [_FN] = {
        { _______, QK_BOOT, _______, _______, _______, _______, _______, _______, KC_NO },
        { _______, _______, _______, _______, _______, _______, _______, _______, KC_NO },
        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },
        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },
        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },
        { _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO },
        { _______, _______, _______, _______, _______, _______, _______, _______, _______ },
        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, _______, _______, _______, _______, _______, _______, _______, _______ },
        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },
        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },
        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ }
    }
};
```
The keymap file allows us to assign each matrix to a specific key by using these arrays, as well as the function layer. Right now these keys are in a tentative map, but it can easily be changed later.

``` C
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise){
            tap_code(KC_PGDN);
        }else{
            tap_code(KC_PGUP);
        }
    } else {
        if (clockwise){
            tap_code(KC_VOLU);
        }else{
            tap_code(KC_VOLD);
        }
    } 
    return false;
}
```
This simply assigns the rotary encoders left and right turns to a key.

``` C
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("KARVE"), false);

    if (is_keyboard_left()) {
        oled_write_ln_P(PSTR("LEFT"), false);
    } else {
        oled_write_ln_P(PSTR("RIGHT"), false);
    }

    if (is_keyboard_master()) {
        oled_write_ln_P(PSTR("MASTER"), false);
    } else {
        oled_write_ln_P(PSTR("SLAVE"), false);
    }

    oled_write_P(PSTR("LAYER "), false);
    oled_write_char('0' + get_highest_layer(layer_state), false);

    return false;
}

#endif
```
This displays "KARVE LEFT MASTER" or "KARVE RIGHT SLAVE" on the OLED screens depending on the split half. This is can easily changed to other options later.