#ifndef __c4_X_Plane_Communication_Library_h__
#define __c4_X_Plane_Communication_Library_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc4_X_Plane_Communication_LibraryInstanceStruct
#define typedef_SFc4_X_Plane_Communication_LibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_X_Plane_Communication_Library;
  real32_T *c4_elevator;
  real32_T *c4_aileron;
  real32_T *c4_rudder;
  real32_T *c4_elevator_trim;
  real32_T *c4_aileron_trim;
  real32_T *c4_rudder_trim;
  real32_T *c4_throttle;
  real32_T *c4_header;
  real32_T (*c4_surfaces_control_cmd)[18];
  real32_T (*c4_trim_control_cmd)[18];
  real32_T (*c4_throttle_cmd)[18];
} SFc4_X_Plane_Communication_LibraryInstanceStruct;

#endif                                 /*typedef_SFc4_X_Plane_Communication_LibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_X_Plane_Communication_Library_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_X_Plane_Communication_Library_get_check_sum(mxArray *plhs[]);
extern void c4_X_Plane_Communication_Library_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
