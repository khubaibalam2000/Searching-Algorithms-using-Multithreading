import matplotlib.pyplot as plt
import numpy as np

def PlotGraph(minmax, x, y1,y2,y3, title, fileName):
#	plt.style.use('fivethirtyeight')
	mina = np.min(minmax)
	maxa = np.max(minmax)
	plt.plot(x, y1, color='green', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='1 thread')
	plt.plot(x, y2, color='blue', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='2 thread')
	plt.plot(x, y3, color='red', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='4 thread')
	plt.ylim(mina,maxa)
	plt.xlim(16,100000000)
	plt.xlabel('Array size')
	plt.ylabel('Times in nanoseconds')
	plt.title(title)
	plt.grid(True)
	plt.legend()
	plt.savefig(fileName)
	plt.show()

def PlotGraphCompares(point1, point2, point3, title, fileName):
	x = [0,100000000]
	y1 = [0, point1]
	y2 = [0, point2]
	y3 = [0, point3]
	plt.plot(x, y1, color='green', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='Sequential Programming')
	plt.plot(x, y2, color='blue', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='Pthreads')
	plt.plot(x, y3, color='red', linewidth = 1.5, marker='o', markerfacecolor='blue', markersize=6, label='OMP')
	plt.xlabel("Array Size")
	plt.ylabel("Times in Seconds")
	plt.title(title)
	plt.grid(True)
	plt.legend()
	plt.savefig(fileName)
	plt.show()
	
	

file_handle = open('extended.txt', 'r')
lines_list = file_handle.readlines()
my_data = [[float(val) for val in line.split()] for line in lines_list[0:]]
# x - axis values
x = [16,256,4096,65536,1048576,16777216,67108864,100000000]


# LS_OP
PlotGraph(np.array([my_data[0],my_data[1],my_data[2]]), x, my_data[0],my_data[1],my_data[2], "Linear Search on Pthreads at different # of threads", "LinearSearchPthreads.png")

# BS_OP
PlotGraph(np.array([my_data[3],my_data[4],my_data[5]]), x, my_data[3],my_data[4],my_data[5], "Binary Search on Pthreads at different # of threads", "BinarySearchPthreads.png")

# TS_OP
PlotGraph(np.array([my_data[6],my_data[7],my_data[8]]), x, my_data[6],my_data[7],my_data[8], "Ternary Search on Pthreads at different # of threads", "TernarySearchPthreads.png")

# JS_OP
PlotGraph(np.array([my_data[9],my_data[10],my_data[11]]), x, my_data[9],my_data[10],my_data[11], "Jump Search on Pthreads at different # of threads", "JumpSearchPthreads.png")

# IS_OP
PlotGraph(np.array([my_data[12],my_data[13],my_data[14]]), x, my_data[12],my_data[13],my_data[14], "Interpolation Search on Pthreads at different # of threads", "InterpolationSearchPthreads.png")




# BS_OMP
PlotGraph(np.array([my_data[15],my_data[16],my_data[17]]), x, my_data[15],my_data[16],my_data[17], "Binary Search on OMP at different # of threads", "BinarySearchOMP.png")

# TS_OMP
PlotGraph(np.array([my_data[18],my_data[19],my_data[20]]), x, my_data[18],my_data[19],my_data[20], "Ternary Search on OMP at different # of threads", "TernarySearchOMP.png")

# JS_OMP
PlotGraph(np.array([my_data[21],my_data[22],my_data[23]]), x, my_data[21],my_data[22],my_data[23], "Jump Search on OMP at different # of threads", "JumpSearchOMP.png")

# IS_OMP
PlotGraph(np.array([my_data[24],my_data[25],my_data[26]]), x, my_data[24],my_data[25],my_data[26], "Interpolation Search on OMP at different # of threads", "InterpolationSearchOMP.png")



file_handle2 = open('ComparedTimes.txt', 'r')
lines_list = file_handle2.readlines()
my_data2 = [[float(val) for val in line.split()] for line in lines_list[0:]]

#LS
PlotGraphCompares(my_data2[0][0],my_data2[5][0],my_data2[10][0],"Linear Search Comparison among 3 methods","LinearSearchComparison.png")

#BS
PlotGraphCompares(my_data2[1][0],my_data2[6][0],my_data2[11][0],"Binary Search Comparison among 3 methods","BinarySearchComparison.png")

#TS
PlotGraphCompares(my_data2[2][0],my_data2[7][0],my_data2[12][0],"Ternary Search Comparison among 3 methods","TernarySearchComparison.png")

#JS
PlotGraphCompares(my_data2[3][0],my_data2[8][0],my_data2[13][0],"Jump Search Comparison among 3 methods","JumpSearchComparison.png")

#IS
PlotGraphCompares(my_data2[4][0],my_data2[9][0],my_data2[14][0],"Interpolation Search Comparison among 3 methods","InterpolationSearchComparison.png")
