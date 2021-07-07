class StockSpanner {
public:
    
    vector <int> prices;
    vector <int> spans;
    int n = 0;
    StockSpanner() {

    }
    
    int next(int price) {
        int result = 1;
        if (n > 0 && price >= prices.back()) {
            for (int i = n - 1; i >= 0 && prices.at(i) <= price; i -= spans.at(i)) {
                result += spans.at(i);
            }
        }
        prices.push_back(price);
        spans.push_back(result);
        n++;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
