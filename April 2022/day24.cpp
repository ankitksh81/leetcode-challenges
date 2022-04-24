/*
	Design Underground System
	https://leetcode.com/problems/design-underground-system/
*/

// Solution: Hashmaps

class UndergroundSystem {
    
    unordered_map<int, pair<string, int>> checkInTime;
    unordered_map<string, unordered_map<string, int>> totalTime, travellers;

public:
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        
        checkInTime[id] = {stationName, t};
    
    }
    
    void checkOut(int id, string stationName, int t) {
        
        pair<string, int> details = checkInTime[id];
        string startStation = details.first;
        int startTime = details.second;
        int timeTaken = t - startTime;
        
        checkInTime.erase(id);
        
        totalTime[startStation][stationName] += timeTaken;
        travellers[startStation][stationName]++;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        int totalTravellers = travellers[startStation][endStation];
        int totalTimeTaken = totalTime[startStation][endStation];
        
        return ((double)totalTimeTaken / (double)totalTravellers);
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */