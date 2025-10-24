This is a complete set of instructions to install and configure your environment to use **SDL2**, **SDL2\_image**, and **SDL2\_ttf** on Windows 11, primarily using the command line (`winget` and `pacman`).

The core of the setup is using **MSYS2** as it provides the easiest command-line installation and linking for MinGW-w64 and the SDL extension libraries.

-----

## Part 1: Install Core Tools via Command Line

Open a standard **Command Prompt (CMD)** or **PowerShell** for these steps.

### 1\. Install C++ Compiler and Package Manager (MinGW/MSYS2)

We use MSYS2 to get the MinGW-w64 toolchain, which includes the `g++` compiler, and to manage the SDL libraries.

1.  **Install MSYS2:**

    ```powershell
    winget install MSYS2.MSYS2
    ```

2.  **Launch MSYS2 and Update:**

      * Open the Windows Start Menu and launch **MSYS2 MinGW 64-bit**. This opens a special terminal.

      * Run the following commands to update and ensure the system is current:

        ```bash
        pacman -Syu
        # If prompted, close the terminal, re-open MSYS2 MinGW 64-bit, and run:
        pacman -Su
        ```

3.  **Install MinGW-w64 Toolchain and SDL Libraries:**

      * Still in the **MSYS2 MinGW 64-bit** terminal, install the **C/C++ toolchain** (`g++`) and the **SDL2**, **SDL2\_image**, and **SDL2\_ttf** development packages for 64-bit Windows (`x86_64`):

        ```bash
        pacman -S --needed mingw-w64-x86_64-toolchain mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_image mingw-w64-x86_64-SDL2_ttf
        ```

      * Press **Enter** to select all members of the `toolchain` group, and then type **'y'** to proceed with the installation.

### 2\. Install Git

```powershell
winget Git.Git
```

### 3\. Configure System PATH (for `g++`)

You need to add the MinGW `bin` directory to your system's PATH so the `g++` command works from any terminal, including the standard Windows Command Prompt.

1.  Open a new standard **Command Prompt** (not the MSYS2 terminal).

2.  Add the compiler directory to the system PATH. The default location is: `C:\msys64\mingw64\bin`.

    ```powershell
    setx PATH "%PATH%;C:\msys64\mingw64\bin"
    ```

3.  **Crucial:** You must **close and re-open** your Command Prompt or PowerShell for the new PATH to take effect.

-----

## Part 2: Project Setup and Code

### 1\. Create Project Directory and Sample Program

1.  Open a new standard **Command Prompt** and create your project folder:

    ```powershell
    mkdir C:\inro-to-programming
    cd C:\inro-to-programming
    ```

2.  Download the course repository and copy the sampe files from lectures:

    ```powershell
    git clone https://github.com/stranxter/lecture-notes
    robocopy '.\lecture-notes\samples\01_programming 101\2025-26-kn\drawing' . /E
    ```


### 2\. Copy SDL DLLs (Runtime Binaries)

For your executable to run, it needs the dynamic-link libraries (`.dll` files) in the same directory. Copy them from the MSYS2 installation path:

In your **Command Prompt** in the `C:\intro-to-programming` directory:

```powershell
copy C:\msys64\mingw64\bin\SDL2.dll C:\intro-to-programming
copy C:\msys64\mingw64\bin\SDL2_image.dll C:\intro-to-programming
copy C:\msys64\mingw64\bin\SDL2_ttf.dll C:\intro-to-programming
```

-----

## Part 3: Compilation and Execution

### 1\. Compile the Program with `g++`

Use `g++` to compile and link your program. You must include the new linker flags for `SDL2_image` and `SDL2_ttf`.

In your **Command Prompt** in the `C:\intro-to-programming` directory:

```powershell
g++ main.cpp draw/sdlwrapper.cpp -o my_sdl_program.exe -std=c++17 -Wall -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
```

**Important Linker Order:** The libraries are listed in order of dependency. The primary SDL libraries must come *after* `SDL2main`.

### 2\. Run the Executable

Execute your program from the Command Prompt:

```powershell
.\my_sdl_program.exe
```

