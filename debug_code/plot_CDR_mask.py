from numpy import genfromtxt
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np

def plot_image(dirpath,vmin_,vmax_,fignum):
    my_data = genfromtxt(dirpath, delimiter='\t')
    my_data = my_data.T
    plt.figure(fignum)
    plt.imshow(my_data, vmin=vmin_, vmax=vmax_, cmap='jet', aspect='auto', origin='lower')
    plt.colorbar()

i = 0
i = i + 1
plot_image('out_CDR_mask.txt',0,1,i)
i = i + 1
plot_image('out_CDR_mask_0.txt',0,1,i)
i = i + 1
plot_image('out_CDR_mask_1.txt',0,1,i)
i = i + 1
plot_image('out_CDR_mask_2.txt',0,1,i)
i = i + 1
plot_image('out_CDR_mask_3.txt',0,1,i)
plt.show()