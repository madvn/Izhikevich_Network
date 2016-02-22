//********************************************************************
// Generate weighted adjacency matrix
// Author : Madhavun Candadai Vasu

// weights - lognormal
// degree - lognormal
//********************************************************************
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

const int Ne = 8; // number of excitatory neurons
const int Ni = 2; // number of inhibitory neurons
const int N = Ne+Ni;

int main(){

	srand(124578);
	// log-normal distrbution
	std::random_device rd;
    std::mt19937 gen(rd());
    std::lognormal_distribution<> d(5,.1);
	std::lognormal_distribution<> w(1,1);

    double rands[N*2];
    for(int i=0;i<N*N;i++){
    	rands[i] = w(gen);
    }
    int randsInd = 0;

    double conn[N][N];
    for(int i=0; i<N; i++){
    	float degree = round(d(gen));
    	for(int j=0;j<N;j++){
    		if(rand() < (degree/N)*float(RAND_MAX)){
    			conn[i][j] = abs(rands[randsInd]);
    			if(j >= Ne){
    				conn[i][j] = -conn[i][j];
    			}
    			randsInd++;
    		}
    		else{
    			conn[i][j] = 0.;
    		}
    	}
    }

    ofstream weights;
    weights.open("weights_logNorm.csv");
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		weights << conn[i][j] << ',';
    	}
    	weights << '\n';
    }
    weights.close();

/*    ifstream wts("weights_logNorm.csv");
    string value;
    while(wts.good()){
    	getline(wts, value, ',');
    	cout << stod(value)  << endl;
    }
*/
}