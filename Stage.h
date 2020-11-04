#ifndef STAGE_H
#define STAGE_H

class Stage {

protected:
	Client* User;

public:
	void ChangeStage(int Stage);

	void RunStage();
};

#endif
