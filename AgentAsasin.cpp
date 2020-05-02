#include "AgentAsasin.h"
#include "Map.h"
pair<int, int> Asasin::chooseNextPosition(Map &m) const
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
				if( m[i][j]->getEntityType()=="Agent")
					return{i,j};
			}
			// cout<<m[i][j]<<" ";
		}
	}
	return {(position.first+1)%15,(position.second+1)%15};

	
}

Asasin::~Asasin() {}