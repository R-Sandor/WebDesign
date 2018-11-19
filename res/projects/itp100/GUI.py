import tkinter
import tkinter.messagebox



class MyGUI:
    def __init__(self):
        self.main_window = tkinter.Tk()
        
        self.label1 = tkinter.Label(self.main_window, \
                                   text = 'This is a western showdown. \n'
                                    'You are callenged to this showdown by Dirty Joe, \n'
                                    'If you dont have a shootout with him \n'
                                    'You might still get shot by someone else \n'
                                    'or worse, be considered a coward! \n'
                                    'The choice is yours, choice wisely!!! \n'
                                    '\n'
                                    'To win: You must fire 6 shots before your opponet! \n'
                                    ' \n'
                                    'To fire enter the required key followed by the enter key.')
        self.my_choice_button1 = tkinter.Button(self.main_window, \
                                    text = 'Walk out of the bar', \
                                    command =self.walkoutofbar)

        self.my_choice_button2 = tkinter.Button(self.main_window, \
                                    text = 'Accept Showdown', \
                                    command = self.main_window.destroy)
        

        self.label1.pack()
        self.my_choice_button1.pack(side='left')
        self.my_choice_button2.pack(side='right')
        


        tkinter.mainloop()
    def walkoutofbar(self):
        tkinter.messagebox.showinfo('Gunned Down', \
                                    'You were shot on the way out.')

        

        
            
my_gui = MyGUI()
