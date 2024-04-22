# High-performance 3D printing platform for soft materials

Developed in [_Soft Matter Engineering Lab_](https://www.fst.um.edu.mo/personal/ieklei/), _University of Macau_

**!!!Caution: This repo is a fork of currently not available to the public printer development project without source files for demo only.
For more details please contact:**
<p align="center">dechao.jiang@connect.um.edu.mo</p>
or
<p align="center">dcjiang@berkeley.edu</p>


## Introduction
To utilize the capability of 3D printing to assist in the development and testing of new materials, a customizable platform is required that can accommodate different printing materials and commands. Here, we present the development of an __open-source__, high-performance 3D printing platform that enables printing from CAD designs using __customized soft materials__.

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
| z-axis calibration | manually operated by software |

***


## User Guide
Download the [Release](https://github.com/Cheney823/CP_Printer/releases/tag/CP_Printer) of this repo, and run the program AFTER you read this section.
### Hardware Connection

- Connect Microfluidic Flow Controller through USB cable to PC
  - Establishing Connection between pressure source and Microfluidic Flow Controller: [User Guide OB1 Mk3](https://support.elveflow.com/helpdesk/attachments/48263070075)
  - Please make sure the Microfluidic Flow Controller is activated
  - Please open the pressure channel between the power source and the Microfluidic Flow Controller
- Connect Motion Controller through etherNet to PC
  - Please make sure the positioning system is activated
  - The IP address of the connecting Ethernet port on the PC and Motion Controller should be **on the same segment** (Local IP of Motion Controller: 192.168.0.11). For example, You can [set IP](https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/change-ip-address-network-adapter) of the Ethernet port on Lab PC to 192.168.0.123
 
A self-connection check is performed every time the program starts, A well-established connection outputs the following message in the terminal 

```
HPGS Connected
OB1 Pneumatic Controller initialized!
```

**IF THE TERMINAL OUTPUT OTHER THINGS DURING STARTING PROCESS**
1. Restart the program several times
2. Contact maintainer

### G-Code 
- Please Generate your G-Code using [Slic3r](https://slic3r.org/download/) and limit the size of the model within 200x200x150
![UM_logo in slic](https://github.com/Cheney823/Softmatter_Printer/blob/main/Readme/UM_logo_slic.png)
- **Path to G-Code in program**

  You will be asked for the path to the G-Code in the 3D printing mode of this program, there are two ways to provide the path:
  1. Relative path (easiest way)

     Copy your G-Code to the root directory of the program and simply type the filename.gcode, for example:

     ```
      Please enter the file address
      File Address: UM_logo.gcode
     ```
     Remember to delete the G-Code file when you finish printing for simplicity
  3. Full path
     ```
      Please enter the file address
      File Address: C:\Cheney\Desktop\UM_logo.gcode
     ```
That's all the things you need to know before you start printing! Open my application and try to print something, you will be guided through parameter settings in the application. 

***

## Developer Guide

**THIS SECTION IS NOT YET READY**

The development of this software for the printer was based on Visual Studio C++ 2022, and tested on Windows 11 (2024).

**Key Infos for hardware communication:**
<p align="center">OB1 ID: 02076A25</p>
<p align="center">Stage Controller's local IP address: 192.168.0.11</p>

**Resolve Dependencies**
***
