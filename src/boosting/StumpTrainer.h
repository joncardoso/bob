#ifndef _TORCH5SPRO_STUMP_TRAINER_H_
#define _TORCH5SPRO_STUMP_TRAINER_H_

#include "WeakLearner.h"
#include "StumpMachine.h"
#include "measurer.h"

namespace Torch
{

    class StumpTrainer : public WeakLearner
    {
    public:
    	///
        StumpTrainer(StumpMachine *stump_machine_, int n_features_, spCore **features_ = NULL);

	///
        virtual bool train();

	///
        virtual ~StumpTrainer();
	
    private:

	//
	float *features_values;
	int n_bins;
	float **histogram;
	float **cumulative_histogram;

	//
	StumpMachine *m_stump_machine;
    };

}

#endif
