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

#ifndef ACADOS_OCP_NLP_OCP_NLP_SQP_RTI_H_
#define ACADOS_OCP_NLP_OCP_NLP_SQP_RTI_H_

#ifdef __cplusplus
extern "C" {
#endif

// acados
#include "acados/ocp_nlp/ocp_nlp_common.h"
#include "acados/sim/sim_common.h"
#include "acados/utils/types.h"



/************************************************
 * options
 ************************************************/

typedef struct
{
    void *qp_solver_opts;
    ocp_nlp_reg_opts *reg_opts;
    void **dynamics;     // dynamics_opts
    void **cost;         // cost_opts
    void **constraints;  // constraints_opts
    int compute_dual_sol;
    int reuse_workspace;
    int num_threads;
} ocp_nlp_sqp_rti_opts;

//
int ocp_nlp_sqp_rti_opts_calculate_size(void *config, void *dims);
//
void *ocp_nlp_sqp_rti_opts_assign(void *config, void *dims, void *raw_memory);
//
void ocp_nlp_sqp_rti_opts_initialize_default(void *config, void *dims, void *opts);
//
void ocp_nlp_sqp_rti_opts_update(void *config, void *dims, void *opts);



/************************************************
 * memory
 ************************************************/

typedef struct
{
    //    ocp_nlp_dims *dims;
    void *qp_solver_mem;
    void *reg_mem;

    void **dynamics;     // dynamics memory
    void **cost;         // cost memory
    void **constraints;  // constraints memory

    // nlp memory
    ocp_nlp_memory *nlp_mem;

    double time_qp_sol;
    double time_lin;
    double time_tot;
} ocp_nlp_sqp_rti_memory;

//
int ocp_nlp_sqp_rti_memory_calculate_size(void *config, void *dims, void *opts_);
//
void *ocp_nlp_sqp_rti_memory_assign(void *config, void *dims, void *opts_, void *raw_memory);



/************************************************
 * workspace
 ************************************************/

typedef struct
{
    // QP solver
    ocp_qp_in *qp_in;
    ocp_qp_out *qp_out;
    void *qp_work;

    void **dynamics;     // dynamics_workspace
    void **cost;         // cost_workspace
    void **constraints;  // constraints_workspace

} ocp_nlp_sqp_rti_work;

//
int ocp_nlp_sqp_rti_workspace_calculate_size(void *config, void *dims, void *opts_);



/************************************************
 * functions
 ************************************************/

//
int ocp_nlp_sqp_rti(void *config, void *dims, void *nlp_in, void *nlp_out,
                void *args, void *mem, void *work_);
//
void ocp_nlp_sqp_rti_config_initialize_default(void *config_);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // ACADOS_OCP_NLP_OCP_NLP_SQP_RTI_H_
