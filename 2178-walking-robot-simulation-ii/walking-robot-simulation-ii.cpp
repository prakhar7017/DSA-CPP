class Robot {
public:
    int idx = 0;
    vector<vector<int>> grid;
    bool hasMoved=false;
    Robot(int width, int height) {
        // Bottom row (left to right) east(0)
        for (int x = 0; x < width; x++) {
            grid.push_back({x,0,0});
        }

        // Bottom column (bottom to top) north(1)
        for (int y =  1; y < height; y++) {
            grid.push_back({width-1,y,1});
        }

        // Top row (right to left) west(2)
        for (int x = width-2 ; x >= 0; x--) {
            grid.push_back({x,height-1,2});
        }

        // left column (top to bottom) south(3)
        for (int y = height-2 ; y > 0; y--) {
            grid.push_back({0,y,3});
        }

        grid[0][2]=3;
    }

    void step(int num) {
        hasMoved = true;
        idx = (idx+num)%grid.size();
    }

    vector<int> getPos() {
        if(!hasMoved) return {0,0};
        return {grid[idx][0],grid[idx][1]};
    }

    string getDir() {
        if (!hasMoved) return "East";

        int dir = grid[idx][2];
        if(dir == 0) return "East";
        else if (dir == 1) return "North";
        else if (dir == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

// class Robot {
// public:
//     int w,h;
//     int x,y;
//     int dirIdx;
//     vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     vector<string> dirNames{"East", "North", "West", "South"};
//     bool hasMoved=false;

//     bool isSafe (int newX,int newY){
//         if(newX >= 0 && newX < w && newY>=0 && newY < h) return true;
//         return false;
//     }
//     Robot(int width, int height) {
//         w=width;
//         h=height;
//         x=0;
//         y=0;
//         dirIdx = 0;
//     }

//     void step(int num) {
//         if(num > 0) hasMoved = true;
//         for(int i=0;i<num;i++){
//             int newX = x + directions[dirIdx][0];
//             int newY = y + directions[dirIdx][1];
//             if (isSafe(newX,newY)) {
//                 x = newX;
//                 y = newY;
//             }else{
//                 dirIdx = (dirIdx+1)%4;
//                 i--;
//             }
//         }
//     }

//     vector<int> getPos() {
//         return {x,y};
//     }

//     string getDir() {
//         if (x == 0 && y == 0 && hasMoved) {
//             return "South";
//         }
//         return dirNames[dirIdx];
//     }
// };

// /**
//  * Your Robot object will be instantiated and called as such:
//  * Robot* obj = new Robot(width, height);
//  * obj->step(num);
//  * vector<int> param_2 = obj->getPos();
//  * string param_3 = obj->getDir();
//  */