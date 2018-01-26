/*
 *    This file is part of acados.
 *
 *    acados is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    acados is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with acados; if not, write to the Free Software Foundation,
 *    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef ACADOS_C_SIM_SIM_ERK_INTEGRATOR_H_
#define ACADOS_C_SIM_SIM_ERK_INTEGRATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <acados/sim/sim_erk_integrator.h>

//
void *sim_erk_copy_opts(sim_dims *dims, void *raw_memory, void *source_);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // ACADOS_C_SIM_SIM_ERK_INTEGRATOR_H_