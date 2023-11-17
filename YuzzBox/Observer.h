// Observer design pattern interface 
#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
    virtual void update(Subject* subject);
};
#endif // OBSERVER_H