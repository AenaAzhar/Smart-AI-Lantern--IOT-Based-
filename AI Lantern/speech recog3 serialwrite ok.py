#install= 1.pip3 install PyAudio 2.pip3 install SpeechRecognition 
import distutils.cmd
import time
import speech_recognition as sr
recognizer = sr.Recognizer()
import serial
ser = serial.Serial('COM3', 9600)
while True:
    print("----------------")
    with sr.Microphone() as source:
        print("Adjusting noise ")
        recognizer.adjust_for_ambient_noise(source, duration=1)
        print("Recording for 4 seconds")
        recorded_audio = recognizer.listen(source, timeout=4)
        print("Done recording")
    try:
        print("Recognizing the text")
        text = recognizer.recognize_google(recorded_audio, language="en-US")
        print("Decoded Text : {}".format(text))
        time.sleep(1)
        print( "sending to arduino")
        res = bytes((text), 'utf-8')
        ser.write(res)
        time.sleep(1)
    except Exception as ex:
        print(ex)
