# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 01:03:48 2019

@author: commu
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('50_Startups.csv')
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 1].values

# Splitting the dataset into the Training set and Test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 1/3, random_state = 0)

# Feature Scaling
"""from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)
sc_y = StandardScaler()
y_train = sc_y.fit_transform(y_train)"""
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder
labelencoder=LabelEncoder()
X[:,3] = labelencoder.fit_transform(X[:,3])
onhotencoder = OneHotEncoder(categorical_features=[3])
onehotencoder = OneHotEncoder.fit_transform(X).toarray()



from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor = regressor.fit(X_train,y_train)
y_test = regressor.predict(X_test)

plt.scatter(X_train, y_train,color='red')
plt.plot(X_train,regressor.predict(X_train),color = 'blue')
plt.title('Salary Vs Experience')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()