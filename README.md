# Smart Parking System 🚗🅿️  

## 📌 Overview  
This project is a **fork** of [Moatasem Elsayed's Smart Parking System](https://github.com/Moatasem-Elsayed/CourseDesignPattern_SmartParking), extended with **TCP-based input handling** and additional refinements. The system efficiently monitors parking availability across multiple floors, allowing real-time updates through a **client-server architecture**.  

## 🚀 Features  
✅ **TCP Input Handling** – Receive parking commands via network sockets  
✅ **Real-Time Parking Updates** – Tracks available spots dynamically  
✅ **Multi-Floor Support** – Handles separate parking zones  
✅ **Optimized with Design Patterns** – Implements SOLID principles  
✅ **Scalable & Modular** – Easy to extend for more floors and features  

## 🛠️ Technologies Used  
- **C++** for backend logic  
- **Yocto** for embedded integration  
- **CMake** for build management  
- **PlantUML** for design visualization  
- **Socket Programming** for TCP communication  

## 📂 Project Structure  
```
Smart-Parking/
│── src/                   # Source files
│   ├── Parking.cpp        # Core parking logic
│   ├── TcpInput.cpp       # TCP input handling
│   ├── Display.cpp        # Output display
│   ├── Updater.cpp        # Parking state updater
│   ├── main.cpp           # Application entry point
│   ├── ...
│── build/                 # Build output
│── CMakeLists.txt         # Build configuration
│── design.puml            # System architecture UML
│── README.md              # Project documentation
```

## 🔧 Installation & Setup  
1. **Clone the repository**  
   ```sh
   git clone https://github.com/waleed-222/Smart-Parking.git
   cd Smart-Parking
   ```

2. **Build the project**  
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Run the application**  
   ```sh
   ./SmartParking
   ```

## 📡 TCP Commands  
| Command     | Description                     |
|------------|---------------------------------|
| CarEnter1  | Car enters on Floor 1          |
| CarEnter2  | Car enters on Floor 2          |
| CarExit1   | Car exits from Floor 1         |
| CarExit2   | Car exits from Floor 2         |
| Quit       | Shutdown the server            |

## 📜 UML Diagram  
The system architecture follows **design patterns** for modularity and efficiency.  

![System UML](design.puml)  

## 🙌 Acknowledgment  
This project is a **fork of** [Moatasem Elsayed's Smart Parking System](https://github.com/Moatasem-Elsayed/CourseDesignPattern_SmartParking). **Thanks to Eng. Moatasem Elsayed for the inspiration!**  

## 🧑‍💻 Author  
Developed & extended by **[Waleed Ebrahem Mohamed](https://www.linkedin.com/in/waleed-ebrahem-46624a1b2/)**  


