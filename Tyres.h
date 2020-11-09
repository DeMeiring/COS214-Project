#ifndef COS214_PROJECT_TYRES_H
#define COS214_PROJECT_TYRES_H


class Tyres {
private:
    int degradation;

public:

    Tyres(int deg) {degradation = deg;}
    virtual ~Tyres(){};

    int getDeg() {return degradation;};

    void setDeg(int deg) {degradation = deg;}

    virtual bool degrade()=0;

};

class Softs : public Tyres {
private:
    int rate = 5;
public:
    Softs(int deg) : Tyres(deg) {}

    virtual bool degrade() {
        setDeg(getDeg()-rate);
        return (getDeg()>0);
    }

    virtual ~Softs(){};
};

class Medium : public Tyres {
private:
    int rate = 5;
public:
    Medium(int deg) : Tyres(deg) {}

    virtual bool degrade() {
        setDeg(getDeg() - rate);
        return (getDeg() > 0);
    };

    virtual ~Medium() {};
};

class Hard : public Tyres {
private:
    int rate = 5;
public:
    Hard(int deg) : Tyres(deg) {}

    virtual bool degrade() {
        setDeg(getDeg()-rate);
        return (getDeg()>0);
    }
    virtual ~Hard(){};
};


#endif //COS214_PROJECT_TYRES_H
