from numpy import genfromtxt
import matplotlib.pyplot as plt
import numpy as np

def get_cmap(n, name='Paired'):
    '''Returns a function that maps each index in 0, 1, ..., n-1 to a distinct 
    RGB color; the keyword argument name must be a standard mpl colormap name.'''
    return plt.cm.get_cmap(name, n)

nTarget = 3
Nmax = 2
nshift = 256
fs = 16000
cmap = get_cmap(10)

max_azi = genfromtxt('max_bfrm_azi.txt', delimiter='\t')	
max_azi = max_azi.T	
x = np.arange(1, max_azi.shape[1]+1, 1, dtype=int)
x = x*nshift/fs
plt.subplot(3, 1, 1)
for t in range(0,nTarget + 1):   #MSVD -> +1
    for n in range(0,Nmax):
        plt.scatter(x, max_azi[t*Nmax+n][range(0,max_azi.shape[1])],s=2, c=cmap(0))
    
plt.ylim([-180, 180])
plt.yticks(list(np.arange(-180,181,20)))
plt.grid(color='gray', linestyle='dashed',which='both')			
plt.title('azimuth before rm close')
plt.xlabel('sec')
plt.ylabel('angle')

max_azi = genfromtxt('max_thr_azi.txt', delimiter='\t')	
max_azi = max_azi.T	
x = np.arange(1, max_azi.shape[1]+1, 1, dtype=int)
x = x*nshift/fs
plt.subplot(3, 1, 2)
for t in range(0,nTarget + 1):   #MSVD -> +1
    for n in range(0,Nmax):
        plt.scatter(x, max_azi[t*Nmax+n][range(0,max_azi.shape[1])],s=2, c=cmap(0))
    
plt.ylim([-180, 180])
plt.yticks(list(np.arange(-180,181,20)))
plt.grid(color='gray', linestyle='dashed',which='both')			
plt.title('azimuth right before Kalman')
plt.xlabel('sec')
plt.ylabel('angle')


max_azi = genfromtxt('track_azi.txt', delimiter='\t')	
max_azi = max_azi.T	
x = np.arange(1, max_azi.shape[1]+1, 1, dtype=int)
x = x*nshift/fs
plt.subplot(3, 1, 3)
for t in range(0,nTarget):    
    plt.scatter(x, max_azi[t][range(0,max_azi.shape[1])],s=2, c=cmap(t*2))
    
plt.ylim([-180, 180])
plt.yticks(list(np.arange(-180,181,20)))
plt.grid(color='gray', linestyle='dashed',which='both')			
plt.title('azimuth right before Kalman')
plt.xlabel('sec')
plt.ylabel('angle')


plt.show()