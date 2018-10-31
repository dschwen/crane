import matplotlib.pylab as plt
import numpy as np
import csv

# file = 'zdplaskin_ex2_out.csv'
file = 'temperature_test_out.csv'


data = np.genfromtxt(file, dtype=float, delimiter=',', skip_header=1)

time = data[:,0]
N_Ar = data[:,1]
N_Ari = data[:,3]
N_Ar2i = data[:,4]
N_ArEx = data[:,2]
N_e = data[:,8]
EN = data[:,7]
mu = data[:,6]

plot12, = plt.loglog(time, N_Ari, 'g', label='$Ar^+$')
plot13, = plt.loglog(time, N_Ar2i, 'r', label='$Ar^{2+}$')
plot14, = plt.loglog(time, N_ArEx, 'c', label='$Ar^*$')
plot15, = plt.loglog(time, N_e, 'k', label='$e^-$')
plt.xlabel('Time [s]', fontsize=14)
plt.ylabel('Density [$cm^{-3}$]', fontsize=14)
plt.legend()


plt.show()