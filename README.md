# SimpleOS GUI Application

## Overview

SimpleOS is a lightweight GUI application that serves as a basic desktop environment. It provides a simple interface with buttons to open a file explorer and a web browser. The application demonstrates the use of Windows API for creating and managing a basic GUI, including handling COM objects to embed a web browser control.

## Features

- **Open File Explorer:** Launches the Windows File Explorer.
- **Open Web Browser:** Opens an embedded web browser within the application.
- **Basic GUI Components:** Includes buttons and text output.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- **Visual Studio 2022** with C++ development tools installed.
- **Windows Operating System** (Windows 10 or later recommended).
- **Visual C++ Build Tools** for compiling the application.

## Installation

Follow these steps to set up and run the SimpleOS application:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/DieAtzen/SimpleOS.git
   ```

2. **Navigate to the Project Directory:**

   ```bash
   cd SimpleOS
   ```

3. **Ensure Visual Studio Build Tools are Installed:**

   Make sure you have Visual Studio Build Tools installed, including the C++ development tools. If `atlbase.h` is missing, install the required components using the Visual Studio Installer:
   
   - Open the Visual Studio Installer.
   - Modify your Visual Studio installation.
   - Go to the "Individual components" tab.
   - Ensure "C++ ATL" and "Windows SDK" are checked.

4. **Build the Application:**

   Open the Developer Command Prompt for Visual Studio and navigate to the project directory. Then, run:

   ```bash
   cl /EHsc /Fe:SimpleGUI.exe SimpleGUI.cpp user32.lib gdi32.lib shell32.lib comctl32.lib ole32.lib
   ```

5. **Run the Application:**

   Execute the compiled application:

   ```bash
   SimpleGUI.exe
   ```

## Usage

- **Open File Explorer:** Click the "Open File Explorer" button to launch the Windows File Explorer.
- **Open Web Browser:** Click the "Open Browser" button to open an embedded web browser within the application.

## Troubleshooting

- **Missing `atlbase.h`:** Ensure you have installed the required components via the Visual Studio Installer.
- **Build Errors:** Verify that all necessary libraries are included and properly referenced.

## Contributing

Feel free to contribute to this project by submitting issues, feature requests, or pull requests. Ensure to follow the coding standards and test your changes before submitting.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For any questions or feedback, please contact us at [atzen@post.com](mailto:atzen@post.com).
