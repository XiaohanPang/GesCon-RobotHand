import cv2
import mediapipe as mp
import serial
import time

# Find the correct port for your Arduino
arduino_port = '/dev/cu.usbserial-1240'  # Change this based on your Arduino's port
baud_rate = 9600


import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
for port in ports:
    print(f"Device: {port.device}, Description: {port.description}")

try:
    arduino = serial.Serial(arduino_port, baud_rate, timeout=1)
    time.sleep(2)  # Wait for Arduino to initialize
    print("Connected to Arduino")
except serial.SerialException:
    print("Error: Could not connect to Arduino. Check the port.")
    arduino = None


# Initialize Mediapipe Hand Tracking
mp_hands = mp.solutions.hands
mp_draw = mp.solutions.drawing_utils
hands = mp_hands.Hands(min_detection_confidence=0.7)

# Open webcam
cap = cv2.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Convert image to RGB for Mediapipe
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(rgb_frame)

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

            # Get landmark positions
            thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP].x
            index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].x

            # Check if Arduino is connected before sending data
            if arduino:
                if thumb_tip > index_tip:
                    arduino.write(b'C')
                    print("Python close hand")
                    time.sleep(3)
                else:
                    arduino.write(b'O')
                    print("Python open hand")
                    time.sleep(3)
    # Show the webcam feed
    cv2.imshow("Gesture Control", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    time.sleep(0.1)
# Cleanup
cap.release()
cv2.destroyAllWindows()
if arduino:
    arduino.close()