# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GenSo.ui'
#
# Created by: PyQt5 UI code generator 5.15.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_GenSo(object):
    def setupUi(self, GenSo):
        GenSo.setObjectName("GenSo")
        GenSo.setWindowModality(QtCore.Qt.WindowModal)
        GenSo.resize(600, 400)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(GenSo.sizePolicy().hasHeightForWidth())
        GenSo.setSizePolicy(sizePolicy)
        self.formLayout = QtWidgets.QFormLayout(GenSo)
        self.formLayout.setSizeConstraint(QtWidgets.QLayout.SetNoConstraint)
        self.formLayout.setFieldGrowthPolicy(QtWidgets.QFormLayout.ExpandingFieldsGrow)
        self.formLayout.setFormAlignment(QtCore.Qt.AlignCenter)
        self.formLayout.setObjectName("formLayout")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setSpacing(0)
        self.gridLayout.setObjectName("gridLayout")
        self.generate_button = QtWidgets.QPushButton(GenSo)
        self.generate_button.setObjectName("generate_button")
        self.gridLayout.addWidget(self.generate_button, 6, 3, 1, 1)
        self.save_button = QtWidgets.QPushButton(GenSo)
        self.save_button.setObjectName("save_button")
        self.gridLayout.addWidget(self.save_button, 2, 3, 1, 1)
        self.ModelName = QtWidgets.QComboBox(GenSo)
        self.ModelName.setEditable(True)
        self.ModelName.setSizeAdjustPolicy(QtWidgets.QComboBox.AdjustToMinimumContentsLength)
        self.ModelName.setIconSize(QtCore.QSize(10, 16))
        self.ModelName.setObjectName("ModelName")
        self.ModelName.addItem("")
        self.ModelName.setItemText(0, "")
        self.ModelName.addItem("")
        self.ModelName.addItem("")
        self.ModelName.addItem("")
        self.ModelName.addItem("")
        self.ModelName.addItem("")
        self.ModelName.addItem("")
        self.ModelName.setItemText(6, "")
        self.gridLayout.addWidget(self.ModelName, 6, 0, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(20, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 1, 3, 1, 1)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem1, 3, 3, 1, 1)
        self.show_save_path = QtWidgets.QLineEdit(GenSo)
        self.show_save_path.setObjectName("show_save_path")
        self.gridLayout.addWidget(self.show_save_path, 2, 0, 1, 1)
        self.choose_button = QtWidgets.QPushButton(GenSo)
        self.choose_button.setAutoExclusive(True)
        self.choose_button.setObjectName("choose_button")
        self.gridLayout.addWidget(self.choose_button, 0, 3, 1, 1)
        self.show_file_path = QtWidgets.QLineEdit(GenSo)
        self.show_file_path.setObjectName("show_file_path")
        self.gridLayout.addWidget(self.show_file_path, 0, 0, 1, 1)
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem2, 2, 2, 1, 1)
        spacerItem3 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem3, 6, 2, 1, 1)
        spacerItem4 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem4, 0, 2, 1, 1)
        self.gridLayout.setColumnStretch(0, 1)
        self.gridLayout.setRowStretch(0, 1)
        self.formLayout.setLayout(1, QtWidgets.QFormLayout.SpanningRole, self.gridLayout)
        self.show_result = QtWidgets.QLabel(GenSo)
        self.show_result.setAlignment(QtCore.Qt.AlignCenter)
        self.show_result.setObjectName("show_result")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.show_result)

        self.retranslateUi(GenSo)
        QtCore.QMetaObject.connectSlotsByName(GenSo)

    def retranslateUi(self, GenSo):
        _translate = QtCore.QCoreApplication.translate
        GenSo.setWindowTitle(_translate("GenSo", "GenSo V0.1"))
        self.generate_button.setText(_translate("GenSo", "generate"))
        self.save_button.setText(_translate("GenSo", "choose save path"))
        self.ModelName.setItemText(1, _translate("GenSo", "DR"))
        self.ModelName.setItemText(2, _translate("GenSo", "USS"))
        self.ModelName.setItemText(3, _translate("GenSo", "SIF"))
        self.ModelName.setItemText(4, _translate("GenSo", "AEB"))
        self.ModelName.setItemText(5, _translate("GenSo", "PLD"))
        self.choose_button.setText(_translate("GenSo", "choose file path"))
        self.show_result.setText(_translate("GenSo", "State:           Ready"))
