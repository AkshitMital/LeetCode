class UndergroundSystem {
private:
    unordered_map<int, pair<string,int>> checkInMap; // id -> {entrystation, entrytime}
    unordered_map<string, pair<int,int>> checkOutMap; // route -> {totaltime, count}
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkInMap[id].first;
        int entryTime = checkInMap[id].second;

        string route = startStation + "_" + stationName;
        int totalTime = t - entryTime;

        checkOutMap[route].first += totalTime;
        checkOutMap[route].second++;
        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        return (double)checkOutMap[route].first/checkOutMap[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */