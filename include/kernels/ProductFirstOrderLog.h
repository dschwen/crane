/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef PRODUCTFIRSTORDERLOG_H
#define PRODUCTFIRSTORDERLOG_H

#include "Kernel.h"

// Forward Declaration
class ProductFirstOrderLog;

template <>
InputParameters validParams<ProductFirstOrderLog>();

class ProductFirstOrderLog : public Kernel
{
public:
  ProductFirstOrderLog(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const VariableValue & _v;
  unsigned int _v_id;
  // const MaterialProperty<Real> & _n_gas;

  // The reaction coefficient
  const MaterialProperty<Real> & _reaction_coeff;
  Real _stoichiometric_coeff;
  bool _v_eq_u;
};
#endif // PRODUCTFIRSTORDERLOG_H
