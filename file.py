import pyautogui as gui
import time

time.sleep(1)

# auto type test data from text file:
with open('inputs.txt', 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1) :
        print(tst[i])
        gui.typewrite(tst[i])
print ("Auto data input completed.")