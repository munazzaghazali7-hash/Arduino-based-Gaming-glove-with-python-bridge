import serial
import time
from pynput.keyboard import Controller, Key

# Create keyboard controller
keyboard = Controller()

# Connect to correct COM port (your Arduino's port)
ser = serial.Serial('COM8', 9600)  # You said it's COM7
time.sleep(2)

print("🔌 Listening for glove input on COM7...\n")

try:
    while True:
        if ser.in_waiting > 0:
            # Use Latin-1 to avoid decode errors
            data = ser.readline().decode('latin-1').strip()
            print(f"📨 Received: '{data}'")

            # Match exact strings from Arduino
            if data == 'LEFT':
                print("👈 Pressing LEFT ARROW")
                keyboard.press(Key.left)
                keyboard.release(Key.left)
            elif data == 'RIGHT':
                print("👉 Pressing RIGHT ARROW")
                keyboard.press(Key.right)
                keyboard.release(Key.right)
            elif data == 'UP':
                print("👆 Pressing UP ARROW")
                keyboard.press(Key.up)
                keyboard.release(Key.up)
            elif data == 'DOWN':
                print("👇 Pressing DOWN ARROW")
                keyboard.press(Key.down)
                keyboard.release(Key.down)
            else:
                print(f"❓ Unknown command: '{data}'")

        time.sleep(0.01)  # Chill so CPU doesn't fry

except KeyboardInterrupt:
    print("\n🛑 Ctrl+C pressed. Exiting...")
finally:
    ser.close()
    print("🔒 Serial port closed.")

