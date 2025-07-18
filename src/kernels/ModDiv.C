#include "ModDiv.h"

registerMooseObject("ThermalApp", ModDiv);

InputParameters ModDiv::validParams() {
	InputParameters params = Kernel::validParams();
	params.addRequiredCoupledVar("vx", "The component of the velocity in the x direction");
	params.addRequiredCoupledVar("vy", "The component of the velocity in the y direction");
	params.addRequiredCoupledVar("vz", "The component of the velocity in the z direction");
	return params;
}

ModDiv::ModDiv(const InputParameters &parameters): Kernel(parameters),
	_grad_vx(coupledGradient("vx")),
	_grad_vy(coupledGradient("vy")),
	_grad_vz(coupledGradient("vz")),
	_mu(getMaterialProperty<Real>("mu")),
	_lambda(getMaterialProperty<Real>("lambda"))
{}

Real ModDiv::computeQpResidual() {
	return -_lambda[_qp] * ( _grad_vx[_qp](0) + _grad_vy[_qp](1) + _grad_vz[_qp](2) ) * _test[_i][_qp];
}
