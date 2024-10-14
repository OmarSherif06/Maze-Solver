class Position {
    public:
        int x;
        int y;
        
        Position(int x, int y) {
            this->x = x;
            this->y = y;
        }

        Position() {
            this->x = -1;
            this->y = -1;
        }
};