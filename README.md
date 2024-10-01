# High-performance 3D printing platform for soft materials

Developed in [_Soft Matter Engineering Lab_](https://www.fst.um.edu.mo/personal/ieklei/), _University of Macau_

Explore this printer in my [blog](https://dechaojiang.github.io/projects/fdm_printer/)

**!!!Caution: This repo is a fork of currently not available to the public printer development project without source files for demo only.

Lab community who seeking further improvement of this project can go to [Developer Guide](https://github.com/Cheney823/CP_Printer/blob/main/Readme/developer_guide.md)
(restricted access, _Soft Matter Engineering Lab_ members only)

## Introduction
To utilize the capability of 3D printing to assist in the development and testing of new materials, a customizable platform is required that can accommodate different printing materials and commands. Here, we present the development of an __open-source__, high-performance 3D printing platform that enables printing from CAD designs using __customized soft materials__.

**CLICK BELOW TO SEE DEMO VIDEO**

[![High-performance 3D printing platform for Advanced Functional Materials](https://img.youtube.com/vi/20_SUIoQqQw/0.jpg)](https://www.youtube.com/watch?v=20_SUIoQqQw)

This 3D printing platform using 
- [Microfluidic Flow Controller OB1](https://www.elveflow.com/microfluidic-products/microfluidics-flow-control-systems/ob1-pressure-controller/) by _Eleveflow_: Printing extrusion of materials using pneumatic force
- 3-set of [ABB servo motors and E530 servo drive](https://new.abb.com/products/3AXD50001013349/e530-ec0s-1kw0-1): Actuator of motion in x,y,z axis
-  [ZMotion ECI2418 Motion Controller](http://www.zmotionglobal.com/pro_info_144.html): Computer communication and advanced motion control
-  Customized structures of guide rail and printhead

For more technical details: dechao.jiang@connect.um.edu.mo

### Capabilities of the Printer
| Functions | Capabilities |
| --- | :---: |
| Positioning repeatability | 2 μm (single axis) |
| Travel range | 200mm x 200mm x 150 mm |
| Travel Speed | 0 ~ 300 mm/s|
| Motion acceleration | 1.0 G |
| Multimatertial support | 2 channels |
| Material extrusion pressure | 0 ~ 8000 mPa|
| G-Code Reading | 100,000 lines limit & accept linear description (G1) only |
| z-axis calibration | manually setting by software |

### Printing Samples
![samples](https://github.com/Cheney823/Softmatter_Printer/blob/main/Readme/Printing%20samples.png)

***


# User Guide
## Installation
Lab users can refer to this part when they need to reallocate this printer, daily user can directly goes to [Embedded Printing and Direct-ink-writting](https://github.com/Cheney823/CP_Printer/edit/main/README.md#embedded-printing-and-direct-ink-writting)
### Hardware Connection

**Settle two Communication Cables**
- Connect Microfluidic Flow Controller (OB1) through USB cable to PC
- Connect Motion Controller (HPGS Controller) through etherNet to PC

**Pressurize the system**
1. Establishing Connection from the pressure source to the pressure inlet of Microfluidic Flow Controller OB1: [User Guide OB1 Mk3](https://support.elveflow.com/support/solutions/articles/48001225594-user-guide-ob1-mk3-))
2. Design and connect the pressure path from the OB1 outlet to the printhead based on your need.
3. Open the pressure channel between the power source and the Microfluidic Flow Controller

### Software and Environmental Settings

**For Microfluidic Flow Controller OB1:**
1. Download [Elveflow SDK](https://www.elveflow.com/microfluidic-products/microfluidics-software/elveflow-software-sdk/)
2. Install Elveflow Smart Interface (ESI)
3. Install the Extra install for x64 Libraries (included in Elveflow SDK download)

**For High-performance gantry stage:**
- [Change the TCP/IP settings](https://support.microsoft.com/en-us/windows/change-tcp-ip-settings-bd0a07af-15f5-cd6a-363f-ca2b6f391ace#WindowsVersion=Windows_11) to the same segment of Motion Controller
  - The Local IP address of the motion controller: 192.168.0.11
  - You can set the IP address of the corresponding EthernNET port to static 192.168.0.123 (for example)
 
### System self-check
1. Turn on OB1 and HPGS after those steps above
2. Download the [Release](https://github.com/Cheney823/CP_Printer/releases/tag/CP_Printer) of this repo, and run the program.
 
A self-check is performed every time the program starts, A system that has well-established connection outputs the following message in the terminal 

```
HPGS Connected
OB1 Pneumatic Controller initialized!
```

**IF THE TERMINAL OUTPUT OTHER THINGS DURING STARTING PROCESS**
1. Restart the program several times
2. Contact maintainer
***

## Embedded Printing and Direct-ink-writing
### G-Code 
- Please Generate your G-Code using [Slic3r](https://slic3r.org/download/) and limit the size of the model within 200x200x150

<img src="https://github.com/Cheney823/CP_Printer/blob/main/Readme/UM_logo_slic.png" width="500">

- **Path to G-Code in program**

  You will be asked for the path to the G-Code in the 3D printing mode of this program, please drag the generated G-Code into the window
  
     ```
      For example:
      Please enter the file address
      File Address: C:\Cheney\Desktop\UM_logo.gcode
     ```
### Calibration
Perform the Calibration inside my software with caution!

That's all the things you need to know before you start printing! Open my application and try to print something, you will be guided through parameter settings in the application. 
***

For more details, please reach out!
![contact_info](https://github.com/Cheney823/Softmatter_Printer/blob/main/Readme/contact_info_pic.png)
