#ifndef SCORE_H
#define SCORE_H

class Score {
  int score;
  int hiScore;
  int level;

  static Score *singleton_instance;

  Score();

  public:
    int getScore();
    int getHiScore();
    int getLevel();

    void setScore(int pts);
    void setHiScore(int pts);
    void setLevel(int lvl);

    static Score *instance();
};

#endif
