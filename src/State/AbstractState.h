#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#define NO_INPUT -1
class AbstractState {
public:
    AbstractState(int state) {
        input_ = NO_INPUT;
        state_ = state;
        finished_ = false;
    }
    virtual ~AbstractState() {}
    virtual void render() = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    bool is_finished() {return finished_;}
    void finish() {finished_ = true;}
    void set_input(int input) {input_ = input;}
    int get_input() {return input_;}
    int get_state() {return state_;}
    
protected:
    bool finished_;
    int input_;
    int state_;
};

#endif
