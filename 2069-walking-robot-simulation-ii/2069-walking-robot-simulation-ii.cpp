class Robot {
    int curr_pos;
    int n;
    vector<pair<int,int>>v;
    bool move = false;
    int width, height;
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->curr_pos = 0;
        this->n = width * 2 + height * 2 - 4;
        for(int i = 0; i < width; i++){
            this->v.push_back({i, 0});
        }
        for(int i = 1; i < height; i++){
            this->v.push_back({width - 1, i});
        }
        for(int i = 1; i < width; i++){
            this->v.push_back({width - i - 1, height - 1});
        }
        for(int i = height - 2; i >= 1; i--){
            this->v.push_back({0, i});
        }   
    }
    
    void step(int num) {
        this->move = true;
        this->curr_pos = (this->curr_pos + num) % this->n;
    }
    
    vector<int> getPos() {
        pair<int,int>pos = this->v[this->curr_pos];
        vector<int>res = {pos.first, pos.second};
        return res;
    }
    
    string getDir() {
        if(!(this->move)){
            return "East";
        }

        pair<int,int>pos = this->v[this->curr_pos];
        if(pos.first != 0 && pos.second ==  0){
            return "East";
        }
        if(pos.first == this->width - 1){
            return "North";
        }
        if(pos.second == this->height - 1){
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */