
/*
  Question Link --> https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/
// 
int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int count=0;
        int lastFinish=-1;
        vector<pair<int,int>> meeting;
        int n=start.size();
        for(int i=0;i<n;i++){ //n
            meeting.push_back({end[i],start[i]});
        }
        sort(meeting.begin(),meeting.end());  // nlogn
        
        for(int i=0;i<n;i++){
            if(meeting[i].second>lastFinish){count++;
            lastFinish=meeting[i].first;
                
            }
        }
        return count;
    }
