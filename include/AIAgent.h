#ifndef AIAGENT_H
#define AIAGENT_H

namespace Chess {
    class Director;

    class AIAgent
    {
        public:
            AIAgent();
            virtual ~AIAgent();
        protected:
        private:
            Director* director;
            char MAX_DEPTH;

            Action alphaBetaSearch(State state);
            Action maxValue(State, Color, char, char, char);
            Action minValue(State, Color, char, char, char);
            char evaluateState(State state);
    }
}

#endif // AIAGENT_H
