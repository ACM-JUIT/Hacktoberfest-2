import tkinter as tk
from forex_python.converter import CurrencyRates

def convertcurr(rate):
	x = amount.get()
	y = currency_from.get()
	z = currency_to.get()
	curr = CurrencyRates()
	f = curr.convert(y,z,x)
	final.set(format(f, '.2f'))

root = tk.Tk()
root.geometry('350x350')
root.title('Currency Converter')

amount = tk.IntVar()
currency_from = tk.StringVar()
currency_to = tk.StringVar()
final = tk.StringVar()

tk.Label(root, text='Input amount').grid(row=0, column=0, columnspan=5)

q = tk.Entry(root, textvariable=amount)
q.grid(row=1, column=1, columnspan=3, sticky='WE', padx=5, pady=5)

tk.Label(root, text='Input Convert From (USD,INR,EUR,GBP etc)').grid(row=2, column=0, columnspan=5)

q = tk.Entry(root, textvariable=currency_from)
q.grid(row=3, column=1, columnspan=3, sticky='WE', padx=5, pady=5)

tk.Label(root, text='Input Convert To (USD,INR,EUR,GBP etc)').grid(row=4, column=0, columnspan=5)

q = tk.Entry(root, textvariable=currency_to)
q.grid(row=5, column=1, columnspan=3, sticky='WE', padx=5, pady=5)


w = tk.Button(root, text='Convert', command=lambda r=1.08: convertcurr(r))
w.grid(row=7, column=2, padx=5, pady=5)


tk.Label(root).grid(row=9, column=0, columnspan=5)

tk.Label(root, text='Converted Amount %s').grid(row=10, column=2, columnspan=2, sticky='WE')

l = tk.Label(root, textvariable=final, relief='raised')
l.grid(row=11, column=2, columnspan=2, sticky='WE')


root.mainloop()
