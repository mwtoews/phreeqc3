#if !defined(SSASSEMBLAGE_H_INCLUDED)
#define SSASSEMBLAGE_H_INCLUDED

#include "NumKeyword.h"
#define EXTERNAL extern
#include "global.h"
#include <cassert> // assert
#include <map>     // std::map
#include <string>  // std::string
#include <list>    // std::list
#include <vector>  // std::vector

#include "char_star.h"
#include "SSassemblageSS.h"
#include "cxxMix.h"

class cxxSSassemblage : public cxxNumKeyword
{

public:
        cxxSSassemblage();
        cxxSSassemblage(struct s_s_assemblage *);
	cxxSSassemblage(const std::map<int, cxxSSassemblage> &entity_map, cxxMix &mx, int n_user);
        ~cxxSSassemblage();

        struct s_s_assemblage *cxxSSassemblage2s_s_assemblage();

        struct s_s *cxxSSassemblageComp2s_s();

        //void dump_xml(std::ostream& os, unsigned int indent = 0)const;

        void dump_raw(std::ostream& s_oss, unsigned int indent)const;

        void read_raw(CParser& parser);

#ifdef USE_MPI
	void mpi_pack(std::vector<int>& ints, std::vector<double>& doubles);
	void mpi_unpack(int *ints, int *ii, double *doubles, int *dd);
#endif
	void totalize();

	const cxxNameDouble& get_totals()const
	{
	  return this->totals;
	};


private:
	void add(const cxxSSassemblage &addee, double extensive);

protected:
        std::list<cxxSSassemblageSS> ssAssemblageSSs;
	cxxNameDouble totals;

public:
        //static std::map<int, cxxSSassemblage>& map;

};

#endif // !defined(SSASSEMBLAGE_H_INCLUDED)
