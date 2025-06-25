# Ragbee Ring Firmware

Welcome to the **Ragbee Ring Firmware** repository!  
This project powers the Ragbee Ring: a gesture-controlled smart ring that recognizes hand gestures and communicates with a mobile app via BLE.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Getting Started](#getting-started)
- [Working with Git and GitHub](#working-with-git-and-github)
  - [1. Clone the Repository](#1-clone-the-repository)
  - [2. Create a New Branch](#2-create-a-new-branch)
  - [3. Make Changes Locally](#3-make-changes-locally)
  - [4. Commit and Push Changes](#4-commit-and-push-changes)
  - [5. Create a Pull Request](#5-create-a-pull-request)
- [Development Guidelines](#development-guidelines)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

---

## Project Overview

The Ragbee Ring firmware is written in C++ for embedded platforms (such as nRF52 with Arduino).  
It includes gesture recognition, BLE communication, battery management, and integration with a mobile app.

---

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/)
- Board support for your hardware (e.g., Adafruit nRF52)
- [Git](https://git-scm.com/downloads)
- A GitHub account

---

## Working with Git and GitHub

### 1. Clone the Repository

Open a terminal and run:

```
git clone https://github.com/<main-org-or-user>/ragbee-ring-firmware.git
cd ragbee-ring-firmware
```

### 2. Create a New Branch

Always create a new branch for your feature or bugfix:

```
git checkout -b <your-feature-branch>
```

Example:

```
git checkout -b add-gesture-support
```

### 3. Make Changes Locally

- Open the project in your IDE (e.g., VS Code).
- Make your changes and test them on your hardware.

### 4. Commit and Push Changes

```
git add .
git commit -m "Describe your changes"
git push origin <your-feature-branch>
```

### 5. Create a Pull Request

- Go to the repository on GitHub.
- Click **Compare & pull request**.
- Add a clear description of your changes.
- Submit the pull request to the main repository.

The maintainers will review your PR and may request changes before merging.

---

## Development Guidelines

- **Write clear, modular code.**
- **Comment your code** for clarity.
- **Test** your changes on hardware before submitting.
- **Do not commit build artifacts** (e.g., `.hex`, `.bin`, or `build/` folders).
- **Follow the existing code style**.

---

## Project Structure

```
Rugbee_Firmware_Harsh_10/
├── Ragbee_Firmware_Harsh_10.ino      # Main firmware entry point
├── Ragbee_extensions.h               # All main includes
├── Variable.h                        # Global variables and thresholds
├── Gesture_Status.h                  # Gesture state flags and helpers
├── Primary_Gesture.h                 # Primary gesture logic
├── Secondary_Gesture.h               # Secondary gesture logic
├── Tertiary_Gesture.h                # Tertiary gesture logic
├── Quaternary_Gesture.h              # Quaternary gesture logic
├── Ragbee_BLE.h                      # BLE setup and callbacks
├── Ragbee_BLE_message_received.h     # BLE message parsing
├── Ragbee_info.h                     # Device info and versioning
├── Ragbee_internal.h                 # Internal flash storage
├── Ragbee_LED.h                      # LED control
├── Power_mode.h                      # Battery management
├── Mouse_movement.h                  # Mouse emulation logic
├── LSM6DS3_Sensor.h                  # IMU sensor setup
├── ...                               # Other supporting files
```

---

## Contributing

We welcome contributions!  
Please open an issue for bugs or feature requests before starting major work.

**Pull Request Checklist:**
- Code compiles and runs on hardware.
- No merge conflicts.
- Clear commit messages.
- Description of what and why you changed.

---

## License

This project is licensed under the MIT License.  
See [LICENSE](LICENSE) for details.

---

**Happy Hacking!**  
If you have questions, open an issue or contact the maintainers.
