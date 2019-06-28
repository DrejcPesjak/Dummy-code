#k-means algorithm for data with 2 features
import numpy as np
import random


def kmeans(data, numK):
    numOfclusters = numK
    dataLen = data.shape[0]
    numFeatures = data.shape[1] # == 2
    #make cluster centroids
    cent = np.zeros((numOfclusters, numFeatures))

    for k in range(numOfclusters):
        #randomly initialize cluster centroids
        cent[k] = (random.randrange(100),random.randrange(100))


    sumMoved = 1000
    #adding cluster number column
    data = np.c_[data,np.zeros((dataLen,1))-1]

    while(sumMoved > 0.1):
        for i in range(dataLen):
            currDist = 1000
            for j in range(numOfclusters):
                if(dist(data[i], cent[j]) < currDist):
                    data[i][2] = j

        sumMoved = 0
        for j in range(numOfclusters):
            x,y = mean( data[data[:,2]==j] )
            sumMoved += abs(cent[j][0]-x + cent[j][1]-y)
            cent[j][0] = x
            cent[j][1] = y

    return data




def dist(dataPoint, centroid):
    #absolute difference between Xs and Ys and ...
    diff = 0
    for i in range(centroid.size):
        diff += dataPoint[i]-centroid[i]
        
    return abs(diff)
