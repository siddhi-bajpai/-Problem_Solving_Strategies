
//TC: (nlogn)+(klogn);
//SC: (n-1)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int gasStations=1;gasStations<=k;gasStations++){
            auto tp=pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            double diff=stations[secInd+1]-stations[secInd];
            double newSecLen=diff/(double)(howMany[secInd]+1);
            pq.push({newSecLen, secInd});
        }
        return pq.top().first;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends