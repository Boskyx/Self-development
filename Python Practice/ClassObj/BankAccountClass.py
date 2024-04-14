class BankAccount:
    def __init__(self, initialBalance=0.0):
        self.__amountBalance=initialBalance
        self.__PrivateData='Password'
    def deposit(self, amount):
        self.__amountBalance=self.__amountBalance+amount
    def withdraw(self, amount):
        if self.__amountBalance>=0 and float(amount)>self.__amountBalance:
            penality=10
            print("Balance not sufficient", amount, ">", round(self.__amountBalance))            
            self.__amountBalance=self.__amountBalance-penality
            self.__amountBalance=self.__amountBalance-amount
            print("a penality of ", penality, "is charged")
        if self.__amountBalance < 0:
            return print('Negative Balance')
        
    