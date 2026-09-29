import tkinter as tk
from tkinter import ttk


def tambah():
    A = float(T01.get())
    B = float(Td1.get())
    result = A + B
    result_label_tab1.config(text="Result = " + str(result))


def kurang():
    A = float(T01.get())
    B = float(Td1.get())
    result = A - B
    result_label_tab1.config(text="Result = " + str(result))


def kali():
    A = float(T01.get())
    B = float(Td1.get())
    result = A * B
    result_label_tab1.config(text="Result = " + str(result))


def bagi():
    A = float(T01.get())
    B = float(Td1.get())
    result = A / B
    result_label_tab1.config(text="Result = " + str(result))


def hapus():
    Td1.delete(0, tk.END)
    T01.delete(0, tk.END)
    result_label_tab1.config(text="Result= ")


root = tk.Tk()
root.title("Tab Widget")
tabControl = ttk.Notebook(root)

tab1 = ttk.Frame(tabControl)
tab2 = ttk.Frame(tabControl)

tabControl.add(tab1, text='Tab 1')
tabControl.add(tab2, text='Tab 2')
tabControl.pack(expand=1, fill="both")


# tab 1
label0 = tk.Label(tab1, text="Input form", font=('Arial 20'))
label0.grid(row=1, column=0, pady=15, columnspan=4)

label1 = tk.Label(tab1, text="Nilai A:", font=('Arial 12'))
T01 = tk.Entry(tab1)
label1.grid(row=2, column=0, pady=5)
T01.grid(row=2, column=1, pady=5)

label2 = tk.Label(tab1, text="Nilai B:", font=('Arial 12'))
Td1 = tk.Entry(tab1)
label2.grid(row=3, column=0, pady=5)
Td1.grid(row=3, column=1, pady=5)

result_label_tab1 = tk.Label(tab1, text="Result = ", font=('Arial 20'))
result_label_tab1.grid(row=4, column=0, pady=10, columnspan=4)

btn = tk.Button(tab1, text="+", font=('Arial 12'), command=tambah)
btn.grid(row=5, column=0, padx=10)

btn2 = tk.Button(tab1, text="- ", font=('Arial 12'), command=kurang)
btn2.grid(row=6, column=0, padx=10)

btn3 = tk.Button(tab1, text="* ", font=('Arial 12'), command=kali)
btn3.grid(row=7, column=0, padx=10)

btn4 = tk.Button(tab1, text="/ ", font=('Arial 12'), command=bagi)
btn4.grid(row=8, column=0, padx=10)

btn5 = tk.Button(tab1, text='C', font=('Arial 12'), command=hapus)
btn5.grid(row=5, column=3, padx=10)


# tab2
label0 = tk.Label(tab2, text="Input form", font=('Arial 20'))
label0.grid(row=1, column=0, pady=15, columnspan=4)

label1 = tk.Label(tab2, text="Nilai A:", font=('Arial 12'))
T01_tab2 = tk.Entry(tab2)
label1.grid(row=2, column=0, pady=5)
T01_tab2.grid(row=2, column=1, pady=5)

label2 = tk.Label(tab2, text="Nilai B:", font=('Arial 12'))
Td1_tab2 = tk.Entry(tab2)
label2.grid(row=3, column=0, pady=5)
Td1_tab2.grid(row=3, column=1, pady=5)


result_label_tab2 = tk.Label(tab2, text="Result = ", font=('Arial 20'))
result_label_tab2.grid(row=4, column=0, pady=10, columnspan=4)


def hasilLuas():
    A = float(T01_tab2.get())
    B = float(Td1_tab2.get())
    result = A * B
    result_label_tab2.config(text="Result = " + str(result))


def hasilKeliling():
    A = float(T01_tab2.get())
    B = float(Td1_tab2.get())
    result = 2 * (A + B)
    result_label_tab2.config(text="Result = " + str(result))


btn = tk.Button(tab2, text="Luas", font=('Arial 12'), command=hasilLuas)
btn.grid(row=5, column=0, padx=10)

btn2 = tk.Button(tab2, text="Keliling", font=(
    'Arial 12'), command=hasilKeliling)
btn2.grid(row=10, column=0, padx=10)

# btnhapus = Button(win1, text="C", font=("Arial 12"), command=hapus)
# btnhapus.place(x=500, y=350)

root.mainloop()
