
//TC: O(n*k)
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
        for(int gasStations=1;gasStations<=k;gasStations++){
            double maxSection=-1;
            int maxInd=-1;
            for(int i=0;i<n-1;i++){
                double diff=(stations[i+1]-stations[i]);
                double sectionLength=diff/(double)(howMany[i]+1);
                if(sectionLength>maxSection){
                    maxSection=sectionLength;
                    maxInd=i;
                }
            }
            howMany[maxInd]++;
        }
        double maxAns=-1;
        for(int i=0;i<n-1;i++){
            double diff=(stations[i+1]-stations[i]);
            double sectionLength=diff/(double)(howMany[i]+1);
            maxAns=max(maxAns, sectionLength);
        }
        return maxAns;
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