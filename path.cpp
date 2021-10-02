#include <bits/stdc++.h>
using namespace std;
 
int findCheapestPrice(int cities,  vector<vector<int> >& flights int src, int dst, int stops)
{
   
    vector<int> dist(cities, INT_MAX);
    dist[src] = 0;
 
    
    for (int i = 0; i <= stops; i++) {
 
        vector<int> intermediate(dist);
 
        for (auto flight : flights) {
 
            if (dist[flight[0]] != INT_MAX) {
                intermediate[flight[1]]
                    = min(intermediate[flight[1]],
                          dist[flight[0]]
                              + flight[2]);
            }
        }
 
       
        dist = intermediate;
    }
 
   
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
 

int main()
{
    
    vector<vector<int> > flights = { { 4, 1, 1 }, { 1, 2, 3 }, { 0, 3, 2 }, { 0, 4, 10 }, { 3, 1, 1 }, { 1, 4, 3 } };
 
   
    int stops = 2;
    int totalCities = 5;
 
    
    int sourceCity = 0;
    int destCity = 4;
 
    
    long ans = findCheapestPrice(
        totalCities, flights, sourceCity,
        destCity, stops);
    cout << ans;
    return 0;
}
