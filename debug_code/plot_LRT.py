from numpy import genfromtxt
import matplotlib.pyplot as plt
import numpy as np

def get_cmap(n, name='Paired'):
    '''Returns a function that maps each index in 0, 1, ..., n-1 to a distinct 
    RGB color; the keyword argument name must be a standard mpl colormap name.'''
    return plt.cm.get_cmap(name, n)


cmap = get_cmap(10)
nshift = 256
fs = 16000
nTarget = 1

for tch in range(0,nTarget):
    lrt = genfromtxt('../output/LRT_' + str(tch) + '.txt', delimiter='\t')	
    x = np.arange(1, lrt.shape[0]+1, 1, dtype=int)
    x = x*nshift/fs
    plt.figure(tch)
    plt.scatter(x, lrt,s=2, c=cmap(0))        

        
    plt.ylim([-1, 30])
    #plt.yticks(list(np.arange(-180,181,20)))
    plt.grid(color='gray', linestyle='dashed',which='both')			
    plt.title('LRT'+str(tch))
    plt.xlabel('sec')
    plt.ylabel('LRT')



plt.show()