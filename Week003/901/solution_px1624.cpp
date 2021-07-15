#define MAX_PRICE_COUNT 10000
typedef struct {
    int *prices;
    int *span;
    int index;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = malloc(sizeof(StockSpanner));
    obj->prices = malloc(sizeof(int) * MAX_PRICE_COUNT);
    obj->span = malloc(sizeof(int) * MAX_PRICE_COUNT);

    obj->index = 0;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    // add today's price to price list
    obj->prices[obj->index] = price;
    
    for(int i=obj->index-1; i>=0; i -= obj->span[i]){
        if(obj->prices[i] <= price)
            span += obj->span[i];
        else
            break;
    }
    
    obj->span[obj->index] = span;
    obj->index++;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->span);

    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/