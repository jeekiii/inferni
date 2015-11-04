#ifndef QUEST_HPP
    #define QUEST_HPP

class Quest
{
	private:
	Map map_;
	std::vector<Object> *objects_;
	std::vector<int> toSaveId_;
	std::vector<int> toPossess_;
	Coord coordToWin_;
	std::vector<int> nextQuest_;
	public:
	Quest(string filename);
	Quest();
	~Quest();
	hasWon();
	hasLost();


};
#endif
