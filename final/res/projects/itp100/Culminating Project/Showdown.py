import tkinter
import tkinter.messagebox
class MyGUI: 
    def __init__(self):
        
        self.main_window = tkinter.Tk()
   
        self.label1 = tkinter.Label(self.main_window, \
                                   text = 'Stinky Joes Has Challenged \n'
                                    'you to a showdown! \n'
                                    'Stinky Joes is known for being a horrible shot. \n'
                                    'If you dont have a shootout with him \n'
                                    'you might still get shot by someone else \n'
                                    'or worse, be considered a coward! \n'
                                    'The choice is yours, choice wisely!!!')
        self.my_choice_button1 = tkinter.Button(self.main_window, \
                                    text = 'Walk out of the bar', \
                                    command =self.walkoutofbar)

        self.my_choice_button2 = tkinter.Button(self.main_window, \
                                    text = 'Draw Revolver', \
                                    command = self.drawrevolver)
        self.quit_button = tkinter.Button(self.main_window, \
                                text='Quit', \
                                command=self.main_window.destroy)

        self.label1.pack()
        self.my_choice_button1.pack(side='left')
        self.my_choice_button2.pack(side='right')
        self.quit_button.pack(side = 'bottom')


        tkinter.mainloop()
         
    def walkoutofbar(self):
        tkinter.messagebox.showinfo('Gunned Down', \
                                    'You were shot on the way out.')

    def drawrevolver(self):
        self.windowforfire = tkinter.Tk()
        self.firebutton = tkinter.Button(self.windowforfire, \
                                         text = 'Fire', \
                                         command = self.fire)
        self.firebutton.pack()

    def shots(self):
        shotsfired = 0
        return self.shotsfired
    def fire(self, shotsfired):
        
        FIRESHOT += 1
        
        shotsfired = FIRESHOT
        return shotsfired
        print(shotsfired)
        
        
    
    
        
my_gui = MyGUI()
