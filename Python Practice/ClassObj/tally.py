from counter import Counter
tally=Counter()
limit=int(input('Inserire valore massimo:'))
tally.setLimit(limit)
tally.click()
tally.click()
print("the value is", tally.getValue())
tally.undo()
print("the value is", tally.getValue())
tally.undo()
#tally.undo()
for i in range(6):
    tally.click()
    print(tally.getValue())