# izhikevich_network

File descriptions
1. izhi.cpp - recreated from Izhikevich's paper - writes out to izhiSpikes.csv
2. stimIzhi.cpp - 10 neuron izhikevich network for stimulation tests - writes out to izhiSpikes.csv
3. generateWeights.cpp - program that generates logNormal weights to weights_logNorm.cpp
4. pltRaster.m - MATLAB script to visualize raster


Notes on compiling the programs - 
1. generateWeights.cpp
	g++ -std=c++11 -o genWeights generateWeights.cpp
	./genWeights
2. stimIzhi.cpp
	g++ -std=c++11 -o stimIzhi stimIzhi.cpp -L /usr/lib/atlas-base/atlas -lblas
	./stimIzhi