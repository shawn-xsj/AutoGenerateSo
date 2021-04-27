# This Python file uses the following encoding: utf-8
import os
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider, QVBoxLayout, QApplication,QMainWindow, QPushButton, QLabel)
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import QFileDialog
from PyQt5.QtWidgets import QTextEdit
from PyQt5.QtWidgets import QVBoxLayout, QHBoxLayout
from PyQt5.QtWidgets import QLineEdit
from GenSoUi import Ui_GenSo



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
        
        self.show_file_path = QLineEdit(self)
        self.show_save_path = QLineEdit(self)
        self.save_button = QPushButton(self)
        self.save_button.setText("choose save path")
        self.save_button.clicked.connect(self.SavePath)
        self.show_result = QLabel(self)
        self.show_result.setText("Ready")

        hBox1 = QHBoxLayout()
        hBox1.addWidget(self.show_file_path)
        hBox1.addWidget(self.choose_button)
 
        hBox2 = QHBoxLayout()
        hBox2.addWidget(self.show_save_path)
        hBox2.addWidget(self.save_button)
        hBox3 = QHBoxLayout()
        hBox3.addWidget(self.show_result)
        hBox3.addWidget(self.generate_button)
        vbox1 = QVBoxLayout()
        vbox1.addLayout(hBox1)
        vbox1.addLayout(hBox2)
        vbox1.addLayout(hBox3)   
        self.setLayout(vbox1)
        self.resize(400,250)
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
        self.show_result.setText("finished")

class MyWidgets(QWidget,Ui_GenSo):
    def __init__(self, parent=None):
        super(MyWidgets, self).__init__(parent)
        self.ui = Ui_GenSo()
        self.ui.setupUi(self)
        self.ui.choose_button.clicked.connect(self.GetPath)
        self.ui.save_button.clicked.connect(self.SavePath)
        self.ui.generate_button.clicked.connect(self.Generate)
      
    def GetPath(self):
        self.directory = QFileDialog.getExistingDirectory(self, "choose file path","./")
        self.ui.show_file_path.setText(self.directory)
    def SavePath(self):
        self.save_directory = QFileDialog.getExistingDirectory(self, "choose file path","./")
        self.ui.show_save_path.setText(self.save_directory)

    def Generate(self):
        """
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
        self.ui.show_result.setText("finished")
        """
        command = "g++ "
        parameter = "-shared -fPIC -o "
        LIB = "/lib"
        module = "USS"
        type = ".so"
        print(self.directory)
        for file in os.listdir(self.directory):
            if file != "IS31_UserMemMap.h":
                command = command + self.directory +"/"+ file +" "
        command = command +parameter + self.save_directory + LIB+ module + type
        print(command)
        os.system(command)
        self.ui.show_result.setText("finished")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    w = MyWidgets()
    w.resize(600, 400)
    w.move(400, 200)
    w.show()
    sys.exit(app.exec_())



