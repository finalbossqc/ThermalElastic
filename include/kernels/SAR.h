#pragma once

#include "Kernel.h"

class SAR : public Kernel {
	public:
		SAR(const InputParameters &parameters);
		static InputParameters validParams();

	protected:
		virtual Real computeQpResidual() override;	
		const Function & _function;
        
		const MaterialProperty<Real> & _lambda;
        const MaterialProperty<Real> & _mu;
		const MaterialProperty<Real> & _alpha;
};
