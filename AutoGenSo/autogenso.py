# This Python file uses the following encoding: utf-8
import os
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider, QVBoxLayout, QApplication,QMainWindow, QPushButton, QLabel)
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import QFileDialog
from PyQt5.QtWidgets import QTextEdit
from PyQt5.QtWidgets import QVBoxLayout, QHBoxLayout



class SigSlot(QWidget):
    def __init__(self,parent=None):
        QWidget.__init__(self)
        self.setWindowTitle('Auto Generate .So File')
        self.choose_button = QPushButton(self)
        self.choose_button.setObjectName("choose")
        self.choose_button.setText("choose file path")
        self.choose_button.clicked.connect(self.GetPath)
        # self.choose_button.move(200, 200)
        self.generate_button = QPushButton(self)
        self.generate_button.setText("Generate so")
        self.generate_button.clicked.connect(self.Generate)
        # self.generate_button.move(250, 250)
        
        self.show_file_path = QTextEdit(self)
        self.show_save_path = QTextEdit(self)
        self.save_button = QPushButton(self)
        self.save_button.setText("save so file")
        self.save_button.clicked.connect(self.SavePath)
        self.show_result = QLabel(self)
        vbox1 = QVBoxLayout()
        vbox1.addWidget(self.choose_button)
        vbox1.addWidget(self.save_button)
        vbox1.addWidget(self.generate_button)

        vbox2 = QVBoxLayout()
        vbox2.addWidget(self.show_file_path)
        vbox2.addWidget(self.show_save_path)
        vbox2.addWidget(self.show_result)

        hbox = QHBoxLayout()
        hbox.addLayout(vbox2)
        hbox.addLayout(vbox1)

        
        self.setLayout(hbox)
        self.resize(350,250)
    def GetPath(self):
        self.directory = QFileDialog.getExistingDirectory(self, "choose file path","./")
        self.show_file_path.setText(self.directory)
    def SavePath(self):
        self.save_directory = QFileDialog.getExistingDirectory(self, "choose file path","./")
        self.show_save_path.setText(self.save_directory)
    def Generate(self):
        command = "g++ "
        parameter = "-shared -fPIC -o lib"
        module = "USS"
        type = ".so"
        print(self.directory)
        for file in os.listdir(self.directory):
            if file != "IS31_UserMemMap.h":
                command = command + self.directory +"/"+ file +" "
        command = command +parameter + module + type
        os.system(command)
        print("ok")




app = QApplication(sys.argv)
qb = SigSlot()
qb.show()
sys.exit(app.exec_())
#if __name__ == "__main__":
#    app = QApplication(sys.argv)
#    win = AutoGenSo()
#    win.show()



