class plantilla{
private:
    int x,y;
public:
	void imp(char);
	void mover(char);
	virtual void colision(navep&)=0;
	int X();
	int Y();
	friend class asteroide;
	friend class extralife;
};
