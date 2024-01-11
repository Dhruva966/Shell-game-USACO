// Source: https://usaco.guide/general/io
using namespace std;
#include <iostream>
#include <vector>
int main() {

long long N;
long long M;

cin >> N >> M;

vector<long long> cows(N);
vector<pair<long long, long long>> canes(M);

for(long long y = 0; y < N; y++){

cin >> cows[y];

}

for(long long t = 0; t < M; t++){

cin >> canes[t].second;
canes[t].first = 0;

}

for(long long j = 0; j < M; j++){

	for(long long b = 0; b < N; b++){

		if((cows[b] > canes[j].first) && canes[j].second >= cows[b]){
			
			long long f = (cows[b] - canes[j].first);
			canes[j].first += (cows[b] - canes[j].first);
			cows[b] += f;

		if(canes[j].first >= canes[j].second){break;}

		} else if((cows[b] > canes[j].first) && canes[j].second < cows[b]){
			
			cows[b] += (canes[j].second - canes[j].first);
			canes[j].second = 0;
			
		if(canes[j].second == 0){break;}

		}

	}

}

for(long long g = 0; g < N; g++){

cout << cows[g] << "\n";

}

return 0;
}