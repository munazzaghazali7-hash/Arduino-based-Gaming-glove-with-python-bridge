# 🎮 Arduino Gaming Glove

This project turns a DIY glove into a game controller!
You can play games like Subway Surfers using hand gestures.

## ✨ Features

- Detects LEFT / RIGHT / UP / DOWN with Arduino
- Sends commands via serial communication
- Python script uses `pynput` to simulate arrow key presses

## ⚙️ Tech Stack

- Arduino Uno + Sensors
- Python (pynput, pyserial)
- Serial Communication

## Circuit Diagram

Note- Ignore the purple wire

![Arduino Glove Circuit](images/circuit.png)

## 🚀 How to Run

1. Upload `main_code` to your Arduino board.
2. Install Python dependencies:

   ```bash
   pip install pynput pyserial
   ```

3. Connect your Arduino to your PC and check the COM port (e.g., COM3).
4. Update the Python script with the correct COM port if needed.
5. Run the Python script:

   ```bash
   python python-controller.py
   ```

6. Open your favorite game (Subway Surfers, Temple Run, etc.) and control it with gestures!

## 📸 Demo

Check out the glove in action on YouTube:

[![Arduino Glove Demo](https://img.youtube.com/vi/6svY-ZWW7ZY/0.jpg)](https://www.youtube.com/watch?v=6svY-ZWW7ZY)

---
