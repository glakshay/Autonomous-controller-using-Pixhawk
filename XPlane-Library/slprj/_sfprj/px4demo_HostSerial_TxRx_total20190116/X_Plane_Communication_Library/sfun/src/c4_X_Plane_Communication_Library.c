/* Include files */

#include "X_Plane_Communication_Library_sfun.h"
#include "c4_X_Plane_Communication_Library.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "X_Plane_Communication_Library_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[17] = { "No_Comand", "Surface_header",
  "Trim_header", "Throttle_header", "nargin", "nargout", "elevator", "aileron",
  "rudder", "elevator_trim", "aileron_trim", "rudder_trim", "throttle", "header",
  "surfaces_control_cmd", "trim_control_cmd", "throttle_cmd" };

/* Function Declarations */
static void initialize_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void initialize_params_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void enable_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void disable_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void set_sim_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void sf_gateway_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void mdl_start_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void initSimStructsc4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_X_Plane_Communication_LibraryInstanceStruct
  *chartInstance, const mxArray *c4_b_throttle_cmd, const char_T *c4_identifier,
  real32_T c4_y[18]);
static void c4_b_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real32_T c4_y[18]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real32_T c4_c_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_b_header, const char_T *c4_identifier);
static real32_T c4_d_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_X_Plane_Communication_Library, const char_T
   *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_X_Plane_Communication_Library(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_X_Plane_Communication_Library = 0U;
}

static void initialize_params_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real32_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(5, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_header;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 1, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y",
    *chartInstance->c4_surfaces_control_cmd, 1, 0U, 1U, 0U, 2, 1, 18), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", *chartInstance->c4_throttle_cmd, 1,
    0U, 1U, 0U, 2, 1, 18), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", *chartInstance->c4_trim_control_cmd,
    1, 0U, 1U, 0U, 2, 1, 18), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_b_hoistedGlobal =
    chartInstance->c4_is_active_c4_X_Plane_Communication_Library;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  real32_T c4_fv0[18];
  int32_T c4_i0;
  real32_T c4_fv1[18];
  int32_T c4_i1;
  real32_T c4_fv2[18];
  int32_T c4_i2;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_header = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("header", c4_u, 0)), "header");
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "surfaces_control_cmd", c4_u, 1)), "surfaces_control_cmd", c4_fv0);
  for (c4_i0 = 0; c4_i0 < 18; c4_i0++) {
    (*chartInstance->c4_surfaces_control_cmd)[c4_i0] = c4_fv0[c4_i0];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("throttle_cmd",
    c4_u, 2)), "throttle_cmd", c4_fv1);
  for (c4_i1 = 0; c4_i1 < 18; c4_i1++) {
    (*chartInstance->c4_throttle_cmd)[c4_i1] = c4_fv1[c4_i1];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "trim_control_cmd", c4_u, 3)), "trim_control_cmd", c4_fv2);
  for (c4_i2 = 0; c4_i2 < 18; c4_i2++) {
    (*chartInstance->c4_trim_control_cmd)[c4_i2] = c4_fv2[c4_i2];
  }

  chartInstance->c4_is_active_c4_X_Plane_Communication_Library =
    c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c4_X_Plane_Communication_Library", c4_u, 4)),
    "is_active_c4_X_Plane_Communication_Library");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_X_Plane_Communication_Library(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  real32_T c4_hoistedGlobal;
  real32_T c4_b_hoistedGlobal;
  real32_T c4_c_hoistedGlobal;
  real32_T c4_d_hoistedGlobal;
  real32_T c4_e_hoistedGlobal;
  real32_T c4_f_hoistedGlobal;
  real32_T c4_g_hoistedGlobal;
  real32_T c4_b_elevator;
  real32_T c4_b_aileron;
  real32_T c4_b_rudder;
  real32_T c4_b_elevator_trim;
  real32_T c4_b_aileron_trim;
  real32_T c4_b_rudder_trim;
  real32_T c4_b_throttle;
  uint32_T c4_debug_family_var_map[17];
  real32_T c4_No_Comand;
  real32_T c4_Surface_header;
  real32_T c4_Trim_header;
  real32_T c4_Throttle_header;
  real_T c4_nargin = 7.0;
  real_T c4_nargout = 4.0;
  real32_T c4_b_header;
  real32_T c4_b_surfaces_control_cmd[18];
  real32_T c4_b_trim_control_cmd[18];
  real32_T c4_b_throttle_cmd[18];
  static uint8_T c4_x[4] = { 68U, 65U, 84U, 65U };

  static uint8_T c4_b_x[4] = { 8U, 0U, 0U, 0U };

  static uint8_T c4_c_x[4] = { 13U, 0U, 0U, 0U };

  static uint8_T c4_d_x[4] = { 25U, 0U, 0U, 0U };

  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_throttle, 6U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rudder_trim, 5U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_aileron_trim, 4U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_elevator_trim, 3U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rudder, 2U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_aileron, 1U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_elevator, 0U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *chartInstance->c4_elevator;
  c4_b_hoistedGlobal = *chartInstance->c4_aileron;
  c4_c_hoistedGlobal = *chartInstance->c4_rudder;
  c4_d_hoistedGlobal = *chartInstance->c4_elevator_trim;
  c4_e_hoistedGlobal = *chartInstance->c4_aileron_trim;
  c4_f_hoistedGlobal = *chartInstance->c4_rudder_trim;
  c4_g_hoistedGlobal = *chartInstance->c4_throttle;
  c4_b_elevator = c4_hoistedGlobal;
  c4_b_aileron = c4_b_hoistedGlobal;
  c4_b_rudder = c4_c_hoistedGlobal;
  c4_b_elevator_trim = c4_d_hoistedGlobal;
  c4_b_aileron_trim = c4_e_hoistedGlobal;
  c4_b_rudder_trim = c4_f_hoistedGlobal;
  c4_b_throttle = c4_g_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_No_Comand, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Surface_header, 1U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Trim_header, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Throttle_header, 3U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 5U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_elevator, 6U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_aileron, 7U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_rudder, 8U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_elevator_trim, 9U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_aileron_trim, 10U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_rudder_trim, 11U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_throttle, 12U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_header, 13U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_surfaces_control_cmd, 14U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_trim_control_cmd, 15U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_throttle_cmd, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  memcpy(&c4_b_header, &c4_x[0], (size_t)1 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_No_Comand = -999.0F;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  memcpy(&c4_Surface_header, &c4_b_x[0], (size_t)1 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_b_surfaces_control_cmd[0] = c4_Surface_header;
  c4_b_surfaces_control_cmd[1] = c4_b_elevator;
  c4_b_surfaces_control_cmd[2] = c4_b_aileron;
  c4_b_surfaces_control_cmd[3] = c4_b_rudder;
  c4_b_surfaces_control_cmd[4] = c4_No_Comand;
  c4_b_surfaces_control_cmd[5] = c4_No_Comand;
  c4_b_surfaces_control_cmd[6] = c4_No_Comand;
  c4_b_surfaces_control_cmd[7] = c4_No_Comand;
  c4_b_surfaces_control_cmd[8] = c4_No_Comand;
  c4_b_surfaces_control_cmd[9] = c4_Surface_header;
  c4_b_surfaces_control_cmd[10] = c4_No_Comand;
  c4_b_surfaces_control_cmd[11] = c4_No_Comand;
  c4_b_surfaces_control_cmd[12] = c4_No_Comand;
  c4_b_surfaces_control_cmd[13] = c4_No_Comand;
  c4_b_surfaces_control_cmd[14] = c4_No_Comand;
  c4_b_surfaces_control_cmd[15] = c4_No_Comand;
  c4_b_surfaces_control_cmd[16] = c4_No_Comand;
  c4_b_surfaces_control_cmd[17] = c4_No_Comand;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  memcpy(&c4_Trim_header, &c4_c_x[0], (size_t)1 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_b_trim_control_cmd[0] = c4_Trim_header;
  c4_b_trim_control_cmd[1] = c4_b_elevator_trim;
  c4_b_trim_control_cmd[2] = c4_b_aileron_trim;
  c4_b_trim_control_cmd[3] = c4_b_rudder_trim;
  c4_b_trim_control_cmd[4] = c4_No_Comand;
  c4_b_trim_control_cmd[5] = c4_No_Comand;
  c4_b_trim_control_cmd[6] = c4_No_Comand;
  c4_b_trim_control_cmd[7] = c4_No_Comand;
  c4_b_trim_control_cmd[8] = c4_No_Comand;
  c4_b_trim_control_cmd[9] = c4_Trim_header;
  c4_b_trim_control_cmd[10] = c4_No_Comand;
  c4_b_trim_control_cmd[11] = c4_No_Comand;
  c4_b_trim_control_cmd[12] = c4_No_Comand;
  c4_b_trim_control_cmd[13] = c4_No_Comand;
  c4_b_trim_control_cmd[14] = c4_No_Comand;
  c4_b_trim_control_cmd[15] = c4_No_Comand;
  c4_b_trim_control_cmd[16] = c4_No_Comand;
  c4_b_trim_control_cmd[17] = c4_No_Comand;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  memcpy(&c4_Throttle_header, &c4_d_x[0], (size_t)1 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_b_throttle_cmd[0] = c4_Throttle_header;
  c4_b_throttle_cmd[1] = c4_b_throttle;
  c4_b_throttle_cmd[2] = c4_No_Comand;
  c4_b_throttle_cmd[3] = c4_No_Comand;
  c4_b_throttle_cmd[4] = c4_No_Comand;
  c4_b_throttle_cmd[5] = c4_No_Comand;
  c4_b_throttle_cmd[6] = c4_No_Comand;
  c4_b_throttle_cmd[7] = c4_No_Comand;
  c4_b_throttle_cmd[8] = c4_No_Comand;
  c4_b_throttle_cmd[9] = c4_Throttle_header;
  c4_b_throttle_cmd[10] = c4_No_Comand;
  c4_b_throttle_cmd[11] = c4_No_Comand;
  c4_b_throttle_cmd[12] = c4_No_Comand;
  c4_b_throttle_cmd[13] = c4_No_Comand;
  c4_b_throttle_cmd[14] = c4_No_Comand;
  c4_b_throttle_cmd[15] = c4_No_Comand;
  c4_b_throttle_cmd[16] = c4_No_Comand;
  c4_b_throttle_cmd[17] = c4_No_Comand;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c4_header = c4_b_header;
  for (c4_i3 = 0; c4_i3 < 18; c4_i3++) {
    (*chartInstance->c4_surfaces_control_cmd)[c4_i3] =
      c4_b_surfaces_control_cmd[c4_i3];
  }

  for (c4_i4 = 0; c4_i4 < 18; c4_i4++) {
    (*chartInstance->c4_trim_control_cmd)[c4_i4] = c4_b_trim_control_cmd[c4_i4];
  }

  for (c4_i5 = 0; c4_i5 < 18; c4_i5++) {
    (*chartInstance->c4_throttle_cmd)[c4_i5] = c4_b_throttle_cmd[c4_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_X_Plane_Communication_LibraryMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_header, 7U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  for (c4_i6 = 0; c4_i6 < 18; c4_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_surfaces_control_cmd)
                          [c4_i6], 8U, 1U, 0U, chartInstance->c4_sfEvent, false);
  }

  for (c4_i7 = 0; c4_i7 < 18; c4_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_trim_control_cmd)[c4_i7],
                          9U, 1U, 0U, chartInstance->c4_sfEvent, false);
  }

  for (c4_i8 = 0; c4_i8 < 18; c4_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_throttle_cmd)[c4_i8], 10U,
                          1U, 0U, chartInstance->c4_sfEvent, false);
  }
}

static void mdl_start_c4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc4_X_Plane_Communication_Library
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i9;
  const mxArray *c4_y = NULL;
  real32_T c4_u[18];
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i9 = 0; c4_i9 < 18; c4_i9++) {
    c4_u[c4_i9] = (*(real32_T (*)[18])c4_inData)[c4_i9];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 1, 0U, 1U, 0U, 2, 1, 18), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_X_Plane_Communication_LibraryInstanceStruct
  *chartInstance, const mxArray *c4_b_throttle_cmd, const char_T *c4_identifier,
  real32_T c4_y[18])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_throttle_cmd), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_b_throttle_cmd);
}

static void c4_b_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real32_T c4_y[18])
{
  real32_T c4_fv3[18];
  int32_T c4_i10;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_fv3, 1, 1, 0U, 1, 0U, 2, 1, 18);
  for (c4_i10 = 0; c4_i10 < 18; c4_i10++) {
    c4_y[c4_i10] = c4_fv3[c4_i10];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_throttle_cmd;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y[18];
  int32_T c4_i11;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_b_throttle_cmd = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_throttle_cmd), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_b_throttle_cmd);
  for (c4_i11 = 0; c4_i11 < 18; c4_i11++) {
    (*(real32_T (*)[18])c4_outData)[c4_i11] = c4_y[c4_i11];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real32_T c4_c_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_b_header, const char_T *c4_identifier)
{
  real32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_header),
    &c4_thisId);
  sf_mex_destroy(&c4_b_header);
  return c4_y;
}

static real32_T c4_d_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f0, 1, 1, 0U, 0, 0U, 0);
  c4_y = c4_f0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_header;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_b_header = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_header),
    &c4_thisId);
  sf_mex_destroy(&c4_b_header);
  *(real32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_X_Plane_Communication_Library_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i12;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i12, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i12;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_X_Plane_Communication_Library, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_X_Plane_Communication_Library), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_X_Plane_Communication_Library);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance)
{
  chartInstance->c4_elevator = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_aileron = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_rudder = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_elevator_trim = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_aileron_trim = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_rudder_trim = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c4_throttle = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c4_header = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_surfaces_control_cmd = (real32_T (*)[18])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c4_trim_control_cmd = (real32_T (*)[18])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c4_throttle_cmd = (real32_T (*)[18])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_X_Plane_Communication_Library_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3477494675U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2747355608U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(343837815U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2883397113U);
}

mxArray* sf_c4_X_Plane_Communication_Library_get_post_codegen_info(void);
mxArray *sf_c4_X_Plane_Communication_Library_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AEQRrVcClqqfgMSDCSGyuC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(18);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(18);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(18);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c4_X_Plane_Communication_Library_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_X_Plane_Communication_Library_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_X_Plane_Communication_Library_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("memcpy");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_X_Plane_Communication_Library_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_X_Plane_Communication_Library_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_X_Plane_Communication_Library
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[20],T\"header\",},{M[1],M[21],T\"surfaces_control_cmd\",},{M[1],M[25],T\"throttle_cmd\",},{M[1],M[22],T\"trim_control_cmd\",},{M[8],M[0],T\"is_active_c4_X_Plane_Communication_Library\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_X_Plane_Communication_Library_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance =
      (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _X_Plane_Communication_LibraryMachineNumber_,
           4,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_X_Plane_Communication_LibraryMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _X_Plane_Communication_LibraryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _X_Plane_Communication_LibraryMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"elevator");
          _SFD_SET_DATA_PROPS(1,1,1,0,"aileron");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rudder");
          _SFD_SET_DATA_PROPS(3,1,1,0,"elevator_trim");
          _SFD_SET_DATA_PROPS(4,1,1,0,"aileron_trim");
          _SFD_SET_DATA_PROPS(5,1,1,0,"rudder_trim");
          _SFD_SET_DATA_PROPS(6,1,1,0,"throttle");
          _SFD_SET_DATA_PROPS(7,2,0,1,"header");
          _SFD_SET_DATA_PROPS(8,2,0,1,"surfaces_control_cmd");
          _SFD_SET_DATA_PROPS(9,2,0,1,"trim_control_cmd");
          _SFD_SET_DATA_PROPS(10,2,0,1,"throttle_cmd");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1817);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 18U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 18U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 18U;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _X_Plane_Communication_LibraryMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance =
      (SFc4_X_Plane_Communication_LibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_elevator);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c4_aileron);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_rudder);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c4_elevator_trim);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c4_aileron_trim);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_rudder_trim);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_throttle);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_header);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c4_surfaces_control_cmd);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c4_trim_control_cmd);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c4_throttle_cmd);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s21f0ZECU5t2TcU9oTiVHF";
}

static void sf_opaque_initialize_c4_X_Plane_Communication_Library(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_X_Plane_Communication_LibraryInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
  initialize_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_X_Plane_Communication_Library(void
  *chartInstanceVar)
{
  enable_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_X_Plane_Communication_Library(void
  *chartInstanceVar)
{
  disable_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_X_Plane_Communication_Library(void
  *chartInstanceVar)
{
  sf_gateway_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_X_Plane_Communication_Library
  (SimStruct* S)
{
  return get_sim_state_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_X_Plane_Communication_Library(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_X_Plane_Communication_Library(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_X_Plane_Communication_LibraryInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_X_Plane_Communication_Library_optimization_info();
    }

    finalize_c4_X_Plane_Communication_Library
      ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_X_Plane_Communication_Library
    ((SFc4_X_Plane_Communication_LibraryInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_X_Plane_Communication_Library(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_X_Plane_Communication_Library
      ((SFc4_X_Plane_Communication_LibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_X_Plane_Communication_Library(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_X_Plane_Communication_Library_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(352200780U));
  ssSetChecksum1(S,(3667559071U));
  ssSetChecksum2(S,(2793166455U));
  ssSetChecksum3(S,(341478035U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_X_Plane_Communication_Library(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_X_Plane_Communication_Library(SimStruct *S)
{
  SFc4_X_Plane_Communication_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc4_X_Plane_Communication_LibraryInstanceStruct *)utMalloc
    (sizeof(SFc4_X_Plane_Communication_LibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc4_X_Plane_Communication_LibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_X_Plane_Communication_Library;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_X_Plane_Communication_Library(chartInstance);
}

void c4_X_Plane_Communication_Library_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_X_Plane_Communication_Library(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_X_Plane_Communication_Library(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_X_Plane_Communication_Library(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_X_Plane_Communication_Library_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
