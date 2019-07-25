#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int optimal_weight(int W, vector<int> &w) {
	int n = w.size() + 1;
  	int wt = W + 1;
  	std::vector<int> vec(n * wt);
	sort(w.begin()+1 ,w.end());
	//int D[w.size()][W+1];
	for(int i = 0 ; i < w.size() ; i++){
	vec[(i)  * wt + (0)];
	}
	for(int j = 0 ; j < W+1 ; j++){
		vec[(0)  * wt + (j)];
	}
	for(int i = 1 ; i < w.size() ; i++){
		for(int j = 1 ; j < W+1 ; j++){
			vec[i * wt + j]= vec[(i-1) * wt + j];
			if(w[i] <= j){
				int val = vec[(i-1)  * wt + (j - w[i])] + w[i];
				if(val > vec[(i)  * wt + (j )]){ 
					vec[(i)  * wt + (j )] = val;
				}
			}
							
		}
	}
	int x = w.size()-1;
	int y = W;
	int ans = 0;
	while( x!= 0 && y != 0){
		if(vec[(x)  * wt + (y)] == vec[(x-1)  * wt + (y)]){
			y=y;
		}
		else{
			y = y-w[x];
			ans = ans + w[x];
		}
		x = x-1;
	}
	return ans;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w;
  w.push_back(0);
  for (int i = 0; i < n; i++) {
  	int k;
    std::cin >> k;
    w.push_back(k);
  }
  std::cout << optimal_weight(W, w) << '\n'; 
}
