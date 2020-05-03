#include "AgentHot.h"

pair<int, int> Thief::chooseNextPosition(Map &m) 
{
	pair<int, int> position = this->getPosition();
	int startX = (position.first - radius) < 0 ? 0 : position.first-radius;
	int endX = (position.first +radius) >= m.getColumns() ? m.getColumns()-1 : position.first+radius;
	int startY = (position.second -radius) < 0 ? 0 :position.second-radius;
	int endY = (position.second + radius) >= m.getRows() ? m.getRows()-1: position.second+radius; 
	// cout<<endl<<startX<<" "<<startY<<" "<<endX<<" "<<endY;
	for(int i=startY;i<=endY;i++){
		for(int j = startX;j<=endX;j++){
			if(m[i][j]!=NULL ){
				if( m[i][j]->getEntityType()=="Item")
					return{i,j};
			}
			// cout<<m[i][j]<<" ";
		}
	}
	int ok =0;
	while(!ok){
		int nextX = position.first+moves[prefferedMove].first;
		int nextY = position.second+moves[prefferedMove].second;
		if((nextX>0 &&nextX<m.getRows()) &&0+ (nextY>0 && nextY<m.getColumns())){
			return {nextX,nextY};
		}
		prefferedMove++;
		prefferedMove%=moves.size();
	}

	
}

Thief::~Thief() {}