# 🏥 Touch-Based Device Control System for Bedridden Patients

An **Embedded C-based assistive device control system** developed using the **LPC2148 ARM7 Microcontroller**. The system enables bedridden or physically challenged patients to control connected devices through a **resistive touch screen**.

The system provides **password-based authentication**, **EEPROM password storage**, **LCD status display**, **device control**, and an **emergency buzzer** to improve accessibility and patient safety.

---

## 📌 Table of Contents

* [Project Overview](#-project-overview)
* [Objectives](#-objectives)
* [Features](#-features)
* [System Architecture](#-system-architecture)
* [Hardware Requirements](#-hardware-requirements)
* [Software Requirements](#-software-requirements)
* [Working Principle](#-working-principle)
* [System Workflow](#-system-workflow)
* [Block Diagram](#-block-diagram)
* [Project Structure](#-project-structure)
* [Technologies Used](#-technologies-used)
* [Applications](#-applications)
* [Advantages](#-advantages)
* [Future Enhancements](#-future-enhancements)
* [How to Run](#-how-to-run)
* [Author](#-author)

---

## 📌 Project Overview

Bedridden patients may have difficulty operating household electrical devices independently. This project provides an easy-to-use embedded control system that allows patients to operate connected devices using a **touch-based interface**.

The **LPC2148 ARM7 microcontroller** acts as the main controller and communicates with the touch screen, keypad, LCD, EEPROM, and output devices.

Before accessing the device-control interface, the user must enter a valid password using a **4×4 matrix keypad**. The password is compared with the password stored in **AT25LC512 EEPROM**.

After successful authentication, the patient can use the resistive touch screen to control devices such as LEDs or other connected appliances. An emergency buzzer is also provided for assistance.

---

## 🎯 Objectives

The main objectives of this project are:

* To provide an easy-to-use control system for bedridden patients.
* To allow patients to control electrical devices independently.
* To provide password-protected access to the system.
* To store the password permanently using EEPROM.
* To provide a touch-based user interface.
* To provide an emergency buzzer for patient assistance.
* To display system status and messages on a 16×2 LCD.
* To demonstrate peripheral interfacing using an ARM7 microcontroller.

---

## ✨ Features

* 🔒 Password-protected system
* 📱 Resistive touch screen interface
* 💾 EEPROM-based password storage
* 🖥️ 16×2 LCD display
* ⌨️ 4×4 matrix keypad
* 💡 Device 1 ON/OFF control
* 💡 Device 2 ON/OFF control
* 🚨 Emergency buzzer
* 🔄 Password change facility
* 📡 UART communication
* 🔌 SPI-based EEPROM communication
* ⚙️ GPIO-based device control
* 👨‍⚕️ Designed for bedridden and physically challenged patients

---

# 🏗️ System Architecture

The **LPC2148 ARM7 microcontroller** is the central processing unit of the system.

It receives input from:

* 4×4 keypad
* Resistive touch screen

It communicates with:

* AT25LC512 EEPROM
* 16×2 LCD
* UART interface

It controls:

* Device 1
* Device 2
* Emergency buzzer

---

# 🛠️ Hardware Requirements

| Component                  | Description                                |
| -------------------------- | ------------------------------------------ |
| **LPC2148 ARM7**           | Main microcontroller                       |
| **Resistive Touch Screen** | Touch-based user input                     |
| **4×4 Matrix Keypad**      | Password entry and menu selection          |
| **16×2 LCD**               | Displays system messages and device status |
| **AT25LC512 EEPROM**       | Non-volatile password storage              |
| **LED 1**                  | Represents/controls Device 1               |
| **LED 2**                  | Represents/controls Device 2               |
| **Buzzer**                 | Emergency alert                            |
| **3.3V Power Supply**      | System power supply                        |
| **Connecting Wires**       | Hardware connections                       |

> **Note:** In an actual appliance-control implementation, LEDs can be replaced with suitable relay/driver circuits to control AC appliances safely.

---

# 💻 Software Requirements

| Software / Technology | Purpose                                  |
| --------------------- | ---------------------------------------- |
| **Embedded C**        | Application and peripheral programming   |
| **Keil µVision**      | Development and compilation              |
| **Flash Magic**       | Programming/flashing the microcontroller |
| **Proteus**           | Circuit simulation and testing           |
| **ARM7 LPC2148**      | Target microcontroller                   |

---

# 🔌 Communication Interfaces

## SPI

The **AT25LC512 EEPROM** is interfaced with the LPC2148 using **SPI communication**.

SPI is used for:

* Writing passwords to EEPROM
* Reading passwords from EEPROM
* Updating stored passwords

### Basic communication flow

```text
LPC2148
   |
   | SPI
   |
   v
AT25LC512 EEPROM
```

---

## UART

UART can be used for:

* Debug messages
* Monitoring system operation
* Sending status information to a PC
* Troubleshooting during development

Example:

```text
LPC2148 ---- UART ----> PC / Serial Terminal
```

---

## GPIO

GPIO pins are used to interface and control:

* LEDs
* Buzzer
* LCD control/data signals
* Keypad
* Other digital peripherals

---

# 📖 Working Principle

## Step 1: System Initialization

When the system is powered ON, the LPC2148 initializes the required peripherals.

```text
Power ON
   ↓
Initialize GPIO
   ↓
Initialize LCD
   ↓
Initialize UART
   ↓
Initialize SPI / EEPROM
   ↓
Initialize Keypad
   ↓
Initialize Touch Screen
```

The LCD displays the initial system message.

---

## Step 2: Password Entry

The patient enters the password using the **4×4 matrix keypad**.

The entered password is temporarily stored in the microcontroller's memory.

Example:

```text
LCD:

Enter Password:
****
```

---

## Step 3: Password Verification

The LPC2148 reads the stored password from the **AT25LC512 EEPROM** through SPI communication.

The entered password is compared with the stored password.

### If the password is incorrect:

```text
Access Denied
Try Again
```

The user is asked to enter the password again.

### If the password is correct:

```text
Access Granted
Touch Enabled
```

The touch-control interface becomes available.

---

# 📱 Step 4: Touch-Based Device Control

After successful authentication, the patient can touch predefined areas of the resistive touch screen.

For example:

```text
+---------------------------+
|                           |
|       DEVICE 1            |
|        ON/OFF             |
|                           |
|       DEVICE 2            |
|        ON/OFF             |
|                           |
|       EMERGENCY           |
|        BUZZER             |
|                           |
+---------------------------+
```

The LPC2148 detects the touch position and determines which function the patient selected.

---

# 💡 Step 5: Device Control

When the patient selects **Device 1**, the LPC2148 changes the corresponding GPIO output.

```text
Touch Device 1
      ↓
LPC2148
      ↓
GPIO Output
      ↓
Device 1 ON/OFF
```

Similarly, Device 2 can be controlled.

In the prototype, LEDs can be used to represent the connected devices.

---

# 🚨 Step 6: Emergency Buzzer

The system provides an emergency button/area on the touch screen.

When the patient selects the emergency option:

```text
Touch Emergency
       ↓
     LPC2148
       ↓
   GPIO Output
       ↓
     Buzzer
       ↓
 Emergency Alert
```

The buzzer provides an audible indication that assistance is required.

---

# 🔄 Step 7: Password Change

The system can provide a password-update facility.

The user enters the current password first. After successful verification, a new password can be entered.

```text
Current Password
       ↓
Verification
       ↓
Enter New Password
       ↓
Write to EEPROM
       ↓
Password Updated
```

The new password remains stored in EEPROM even after the system is powered OFF.

---

# 🔁 System Workflow

```text
                +----------------+
                |    POWER ON    |
                +-------+--------+
                        |
                        v
              +-------------------+
              | Initialize System |
              | LCD, GPIO, UART   |
              | SPI, Keypad, Touch|
              +---------+---------+
                        |
                        v
              +-------------------+
              | Enter Password    |
              | Using 4×4 Keypad  |
              +---------+---------+
                        |
                        v
              +-------------------+
              | Verify Password   |
              | With EEPROM Data  |
              +---------+---------+
                        |
              +---------+---------+
              |                   |
             NO                  YES
              |                   |
              v                   v
       +-------------+    +------------------+
       | Access      |    | Enable Touch    |
       | Denied      |    | Interface       |
       +------+------+    +--------+---------+
              |                    |
              |                    v
              |           +------------------+
              |           | Select Function |
              |           +--------+---------+
              |                    |
              |          +---------+---------+
              |          |         |         |
              |          v         v         v
              |       Device 1  Device 2  Emergency
              |       ON/OFF    ON/OFF    Buzzer
              |          |         |         |
              |          +---------+---------+
              |                    |
              |                    v
              |           +------------------+
              |           | Password Change  |
              |           | Optional         |
              |           +--------+---------+
              |                    |
              +--------------------+
```

---

# 📊 Block Diagram

```text
                         +------------------+
                         |    4×4 Keypad    |
                         +--------+---------+
                                  |
                                  |
                         +--------v---------+
                         |                  |
                         |     LPC2148      |
                         |     ARM7 MCU      |
                         |                  |
                         +--+----+----+----+
                            |    |    |    |
                  GPIO -----+    |    |    +----- UART
                                 |    |
                                SPI  GPIO
                                 |    |
                    +------------+    +----------------+
                    |                                 |
           +--------v--------+                +-------v-------+
           |  AT25LC512      |                |   16×2 LCD   |
           |    EEPROM       |                +---------------+
           +-----------------+
                   
                         +-------------------+
                         | Resistive Touch   |
                         |     Screen        |
                         +---------+---------+
                                   |
                                   |
                              LPC2148
                                   |
                    +--------------+--------------+
                    |              |              |
                    v              v              v
              +----------+   +----------+   +----------+
              | Device 1 |   | Device 2 |   |  Buzzer  |
              |   LED    |   |   LED    |   | Emergency|
              +----------+   +----------+   +----------+
```

---

# 📂 Project Structure

```text
Touch-Based-Device-Control/
│
├── main.c
│
├── lcd.c
├── lcd.h
│
├── keypad.c
├── keypad.h
│
├── uart.c
├── uart.h
│
├── touch.c
├── touch.h
│
├── eeprom.c
├── eeprom.h
│
├── delay.c
├── delay.h
│
└── README.md
```

### File Description

| File       | Purpose                      |
| ---------- | ---------------------------- |
| `main.c`   | Main application program     |
| `lcd.c`    | LCD driver implementation    |
| `lcd.h`    | LCD function declarations    |
| `keypad.c` | Keypad driver                |
| `keypad.h` | Keypad declarations          |
| `uart.c`   | UART driver                  |
| `uart.h`   | UART declarations            |
| `touch.c`  | Touch-screen interface       |
| `touch.h`  | Touch-screen declarations    |
| `eeprom.c` | EEPROM read/write operations |
| `eeprom.h` | EEPROM declarations          |
| `delay.c`  | Delay functions              |
| `delay.h`  | Delay declarations           |

---

# 🧰 Technologies Used

* **Embedded C**
* **ARM7 LPC2148**
* **GPIO Programming**
* **UART Communication**
* **SPI Communication**
* **EEPROM Interfacing**
* **LCD Interfacing**
* **4×4 Keypad Interfacing**
* **Resistive Touch Screen**
* **Interrupt Programming**
* **Keil µVision**
* **Proteus**
* **Flash Magic**

---

# 🎯 Applications

This system can be used in:

* 🏥 Hospitals
* 🏠 Home healthcare
* 🛏️ Smart patient rooms
* 👨‍⚕️ Nursing homes
* ♿ Assisted living facilities
* 🧑‍🦽 Rehabilitation centers
* 🏥 Medical automation systems

---

# ✅ Advantages

* Simple and user-friendly interface
* Reduces dependence on caregivers for basic device operation
* Provides password-based security
* Password is retained using non-volatile EEPROM
* Provides emergency alert functionality
* Demonstrates multiple embedded peripheral interfaces
* Can be extended to control real electrical appliances

---

# 🚀 Future Enhancements

The project can be enhanced by adding:

* 📱 Android mobile application
* 🌐 Wi-Fi-based monitoring
* ☁️ IoT cloud integration
* 🎙️ Voice-command control
* 📡 GSM emergency notifications
* 🔌 Relay-based AC appliance control
* 👆 Fingerprint authentication
* 🔋 Battery backup
* 📊 Remote patient monitoring
* 📲 Caregiver notification system

---

# ⚙️ How to Run the Project

## 1. Open the Project

Open the project in **Keil µVision**.

## 2. Add Source Files

Add all `.c` and `.h` files to the Keil project.

```text
main.c
lcd.c
keypad.c
uart.c
touch.c
eeprom.c
delay.c
```

## 3. Configure the LPC2148

Select the appropriate **LPC2148 ARM7 microcontroller** as the target device.

## 4. Compile the Project

Build the project in Keil µVision.

Check for compilation errors and warnings.

## 5. Generate HEX File

After successful compilation, generate the `.hex` file from the Keil project settings.

## 6. Simulate in Proteus

Open the Proteus circuit and connect the required components:

```text
LPC2148
LCD
4×4 Keypad
Touch Screen
EEPROM
LEDs
Buzzer
```

Load the generated HEX file into the LPC2148 component in Proteus.

## 7. Test the System

Perform the following tests:

```text
Power ON
   ↓
Enter Password
   ↓
Verify Password
   ↓
Access Touch Screen
   ↓
Control Device 1
   ↓
Control Device 2
   ↓
Test Emergency Buzzer
   ↓
Test Password Update
```

---

# 🧪 Testing

The following functions should be tested:

| Test Case          | Expected Result                   |
| ------------------ | --------------------------------- |
| Power ON           | System initializes correctly      |
| Correct password   | Access granted                    |
| Incorrect password | Access denied                     |
| Device 1 touch     | Device 1 changes state            |
| Device 2 touch     | Device 2 changes state            |
| Emergency touch    | Buzzer activates                  |
| Password change    | New password stored in EEPROM     |
| Power OFF/ON       | Stored password remains available |

---

# 🔐 Security

The password provides an authentication layer before allowing access to the device-control interface.

The password is stored in **non-volatile EEPROM**, allowing it to remain available after power is removed.

For a production medical device, additional security, fail-safe behavior, electrical isolation, and formal safety validation would be required.

---

# 📌 Project Summary

The **Touch-Based Device Control System for Bedridden Patients** is an embedded assistive technology project based on the **LPC2148 ARM7 microcontroller**.

The system combines a **4×4 keypad, resistive touch screen, LCD, EEPROM, UART, SPI, LEDs, and emergency buzzer** to provide secure and accessible control of connected devices.

The project demonstrates practical concepts of **Embedded C, ARM7 programming, GPIO, SPI, UART, EEPROM interfacing, LCD interfacing, keypad interfacing, touch-screen input, and interrupt programming**.

---

# 👨‍💻 Author

**desalinka veera venkata kondrajulu**

### Skills

* Embedded C
* ARM7 LPC2148
* Device Driver Development
* GPIO Programming
* UART
* SPI
* EEPROM
* LCD Interfacing
* Keypad Interfacing
* Touch Screen Interfacing
* Linux
* Embedded Systems

---

## ⭐ Project Highlights

```text
Microcontroller : LPC2148 ARM7
Programming     : Embedded C
Input           : Resistive Touch Screen + 4×4 Keypad
Display         : 16×2 LCD
Memory          : AT25LC512 EEPROM
Communication   : SPI + UART
Output          : Device 1 + Device 2 + Emergency Buzzer
IDE             : Keil µVision
Simulation      : Proteus
Programming Tool: Flash Magic
```

---

## 📜 License

This project is intended for **educational and academic purposes**. The source code and hardware design can be modified and extended for learning, prototyping, and research.
