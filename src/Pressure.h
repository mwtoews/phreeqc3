#if !defined(PRESSURE_H_INCLUDED)
#define PRESSURE_H_INCLUDED

#include <cassert>				// assert
#include <map>					// std::map
#include <string>				// std::string
#include <list>					// std::list
#include <vector>				// std::vector

#include "NumKeyword.h"

class cxxPressure:public cxxNumKeyword
{

  public:
	cxxPressure(PHRQ_io *io=NULL);
	~cxxPressure();

	//void dump_xml(std::ostream& os, unsigned int indent = 0)const;

	void dump_raw(std::ostream & s_oss, unsigned int indent, int *n_out=NULL) const;

	int read(CParser & parser);
	void read_raw(CParser & parser);
	LDBLE Pressure_for_step(int step_number);
	std::vector<LDBLE> & Get_pressures(void) {return pressures;}
	int Get_count(void) const;
	void Set_count(int i) {count = i;}
	bool Get_equalIncrements(void) const {return equalIncrements;}
	void Set_equalIncrements(bool tf) {equalIncrements = tf;}

protected:
	std::vector < LDBLE >pressures;
	int count;
	bool equalIncrements;
	const static std::vector < std::string > vopts;
};

#endif // !defined(PRESSURE_H_INCLUDED)
