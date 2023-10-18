
#ifndef timer_h
#define timer_h 

class timer
{
    private:
    //The clock time when the timer started
    int startTicks;
    
    //The ticks stored when the timer was paused
    int pausedTicks;

	int jumpTicks;
    
    //The timer status
    bool paused;
    bool started;
    
    public:
    //Initializes variables
    timer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    int get_ticks();
	int getJumpTicks();
    
    //Checks the status of the timer
    bool is_started();
    bool is_paused();    
};
#endif