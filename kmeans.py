#a generic k-means algorithm
import numpy as np
import random


def function(data, numK):
	#data is required to be a numpy array, and numK an integer
	numOfclusters = numK
	dataLen = data.shape[0]
	numFeatures = data.shape[1] # == 2
	minData = np.amin(data,0)
	maxData = np.amax(data,0)

	#make cluster centroids
	cent = np.zeros((numOfclusters, numFeatures))

	#randomly initialize cluster centroids
	for k in range(numOfclusters):
		for j in range(numFeatures):
			cent[k][j] = random.randrange(int(minData[j]), int(maxData[j]))

	sumMoved = 1000
	#adding cluster number column
	data = np.c_[data,np.zeros((dataLen,1))-1]
	

	while(sumMoved > 0.1):
		for i in range(dataLen):
			currDist = 1000
			for j in range(numOfclusters):
				d = dist(data[i], cent[j])
				if(d < currDist):
					data[i][-1] = j
					currDist = d

		sumMoved = 0
		for j in range(numOfclusters):
			point = np.mean( data[data[:,-1]==j] , axis=0)
			sumMoved += dist(point, cent[j])
			cent[j] = point[:-1]

	#returned is labeled data (distributed into k groups/clusters) 
	return data




def dist(dataPoint, centroid):
    #absolute difference between two points in multi-dimensional space (Xs and Ys and ...)
	#manhattan distance
    diff = 0
    for i in range(centroid.size):
        diff += abs(dataPoint[i]-centroid[i])
        
    return diff
	