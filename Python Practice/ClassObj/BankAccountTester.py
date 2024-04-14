from BankAccountClass import BankAccount
import time
# time.sleep(1)
account1=BankAccount(100)
account1.deposit(20.98)
# account1._amountBalance=2000
#print(account1._amountBalance)
# print(account1._BankAccount__PrivateData)#in this way you can access a private data
account1.withdraw(125.9)
account1.withdraw(450)
