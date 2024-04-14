class Counter:
    #Set the constructor __init__(self)
    #Set the instance variable, in that way you don't need to pass for reset method to initialize the variable _value
    def __init__(self):
        self._value=0
        self._max=0
    def reset(self):
        self._value=0
    def click(self):
        if self._value==self._max:
            print('errore superato il limite, couter=', self._value)
        self._value=self._value+1
    def getValue(self):
        return self._value
    def undo(self):
        if self._value==0:
            print('error the button counter cannot undergo ', self._value)
        if self._value == 1:
            self._value=self._value-1
            print('the value is 0')
        else:
            self._value=self._value-1
    def setLimit(self, max=5):
        self._max=max
