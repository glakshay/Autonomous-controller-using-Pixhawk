/* Include files */

#include "getData_from_xplane10_sfun.h"
#include "c1_getData_from_xplane10.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "getData_from_xplane10_sfun_debug_macros.h"
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
static const char * c1_debug_family_names[13] = { "dataLen", "Npackets",
  "maxNPackets", "Nvalues", "Bytecounter", "i", "j", "indx", "nargin", "nargout",
  "u", "msgLen", "Data" };

/* Function Declarations */
static void initialize_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void initialize_params_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void enable_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void disable_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void set_sim_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void sf_gateway_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void mdl_start_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void initSimStructsc1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_Data, const char_T *c1_identifier,
  real32_T c1_y[240]);
static void c1_b_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[240]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint32_T c1_d_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint16_T c1_e_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_check_forloop_overflow_error
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance, boolean_T
   c1_overflow);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_getData_from_xplane10, const
  char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_getData_from_xplane10(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_getData_from_xplane10 = 0U;
}

static void initialize_params_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_Data, 1, 0U, 1U,
    0U, 2, 30, 8), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_getData_from_xplane10;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  real32_T c1_fv0[240];
  int32_T c1_i0;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Data", c1_b_u, 0)),
                      "Data", c1_fv0);
  for (c1_i0 = 0; c1_i0 < 240; c1_i0++) {
    (*chartInstance->c1_Data)[c1_i0] = c1_fv0[c1_i0];
  }

  chartInstance->c1_is_active_c1_getData_from_xplane10 = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c1_getData_from_xplane10", c1_b_u, 1)),
     "is_active_c1_getData_from_xplane10");
  sf_mex_destroy(&c1_b_u);
  c1_update_debugger_state_c1_getData_from_xplane10(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  int32_T c1_i1;
  uint16_T c1_hoistedGlobal;
  int32_T c1_i2;
  uint16_T c1_b_msgLen;
  uint8_T c1_b_u[7300];
  uint32_T c1_debug_family_var_map[13];
  uint16_T c1_dataLen;
  uint16_T c1_Npackets;
  real_T c1_maxNPackets;
  real_T c1_Nvalues;
  real_T c1_Bytecounter;
  uint16_T c1_i;
  uint16_T c1_j;
  uint32_T c1_indx;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real32_T c1_b_Data[240];
  uint32_T c1_q0;
  uint32_T c1_qY;
  uint32_T c1_u0;
  uint16_T c1_A;
  uint16_T c1_x;
  uint16_T c1_b_x;
  uint16_T c1_c_x;
  uint16_T c1_d_x;
  real_T c1_xk;
  real_T c1_d0;
  uint16_T c1_u1;
  int32_T c1_i3;
  uint16_T c1_c_msgLen;
  uint16_T c1_b;
  uint16_T c1_b_b;
  boolean_T c1_overflow;
  uint16_T c1_b_i;
  uint8_T c1_varargin_1;
  int32_T c1_i4;
  uint8_T c1_e_x;
  uint8_T c1_f_x;
  char_T c1_c0;
  uint32_T c1_u2;
  int32_T c1_i5;
  uint8_T c1_b_varargin_1;
  uint8_T c1_g_x;
  uint8_T c1_h_x;
  char_T c1_c1;
  uint16_T c1_b_Npackets;
  uint16_T c1_c_b;
  uint16_T c1_d_b;
  boolean_T c1_b_overflow;
  uint16_T c1_b_j;
  int32_T c1_i6;
  uint8_T c1_i_x[4];
  int32_T c1_i7;
  real32_T c1_y;
  int32_T c1_i8;
  real32_T c1_b_y;
  int32_T c1_i9;
  real32_T c1_c_y;
  int32_T c1_i10;
  real32_T c1_d_y;
  int32_T c1_i11;
  real32_T c1_e_y;
  int32_T c1_i12;
  real32_T c1_f_y;
  int32_T c1_i13;
  real32_T c1_g_y;
  int32_T c1_i14;
  real32_T c1_h_y;
  int32_T exitg1;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_msgLen, 1U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  for (c1_i1 = 0; c1_i1 < 7300; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_u)[c1_i1], 0U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_msgLen;
  for (c1_i2 = 0; c1_i2 < 7300; c1_i2++) {
    c1_b_u[c1_i2] = (*chartInstance->c1_u)[c1_i2];
  }

  c1_b_msgLen = c1_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_dataLen, 0U, c1_b_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Npackets, 1U, c1_b_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_maxNPackets, 2U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Nvalues, 3U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Bytecounter, 4U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 5U, c1_b_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j, 6U, c1_b_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_indx, 7U, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_u, 10U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_msgLen, 11U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_Data, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_q0 = c1_b_msgLen;
  c1_qY = c1_q0 - 5U;
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c1_qY > c1_q0)) {
    c1_qY = 0U;
  }

  c1_u0 = c1_qY;
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c1_u0 > 65535U)) {
    c1_u0 = 65535U;
  }

  c1_dataLen = (uint16_T)c1_u0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_A = c1_dataLen;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_d_x = c1_c_x;
  c1_xk = (real_T)c1_d_x;
  c1_d0 = muDoubleScalarRound(c1_xk / 36.0);
  if (c1_d0 < 65536.0) {
    if (CV_SATURATION_EVAL(4, 0, 2, 1, c1_d0 >= 0.0)) {
      c1_u1 = (uint16_T)c1_d0;
    } else {
      c1_u1 = 0U;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 2, 0, c1_d0 >= 65536.0)) {
    c1_u1 = MAX_uint16_T;
  } else {
    c1_u1 = 0U;
  }

  c1_Npackets = c1_u1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_maxNPackets = 30.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_Nvalues = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  for (c1_i3 = 0; c1_i3 < 240; c1_i3++) {
    c1_b_Data[c1_i3] = 0.0F;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_Bytecounter = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_c_msgLen = c1_b_msgLen;
  c1_b = c1_c_msgLen;
  c1_b_b = c1_b;
  c1_overflow = ((!(1 > c1_b_b)) && (c1_b_b > 65534));
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, c1_overflow);
  }

  c1_i = 1U;
  c1_b_i = 1U;
  do {
    exitg1 = 0;
    if (c1_b_i <= c1_c_msgLen) {
      c1_i = c1_b_i;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      c1_varargin_1 = c1_b_u[(uint16_T)sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 389, 4, MAX_uint32_T,
         (int32_T)(uint16_T)sf_integer_check(chartInstance->S, 1U, 389U, 4U,
          (real_T)c1_i), 1, 7300) - 1];
      c1_e_x = c1_varargin_1;
      c1_f_x = c1_e_x;
      c1_c0 = (char_T)(int8_T)c1_f_x;
      guard1 = false;
      if (CV_EML_COND(0, 1, 0, c1_c0 == 'D')) {
        c1_u2 = (uint32_T)c1_i + 1U;
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c1_u2 > 65535U)) {
          c1_u2 = 65535U;
        }

        c1_b_varargin_1 = c1_b_u[(uint16_T)sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 408, 6,
           MAX_uint32_T, (int32_T)(uint16_T)sf_integer_check(chartInstance->S,
            1U, 408U, 6U, (real_T)(uint16_T)c1_u2), 1, 7300) - 1];
        c1_g_x = c1_b_varargin_1;
        c1_h_x = c1_g_x;
        c1_c1 = (char_T)(int8_T)c1_h_x;
        if (CV_EML_COND(0, 1, 1, c1_c1 == 'A')) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 0, true);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
          c1_b_Npackets = c1_Npackets;
          c1_c_b = c1_b_Npackets;
          c1_d_b = c1_c_b;
          c1_b_overflow = ((!(1 > c1_d_b)) && (c1_d_b > 65534));
          if (c1_b_overflow) {
            c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
          }

          c1_j = 1U;
          c1_b_j = 1U;
          while (c1_b_j <= c1_b_Npackets) {
            c1_j = c1_b_j;
            CV_EML_FOR(0, 1, 1, 1);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
            for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
              c1_i_x[c1_i6] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 507, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  507U, 28U, c1_Bytecounter + (real_T)c1_i6), 1, 7300) - 1];
            }

            memcpy(&c1_indx, &c1_i_x[0], (size_t)1 * sizeof(uint32_T));
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
            for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
              c1_i_x[c1_i7] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 726, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  726U, 28U, c1_Bytecounter + (real_T)c1_i7), 1, 7300) - 1];
            }

            memcpy(&c1_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 709, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 709U, 4U, (real_T)c1_indx),
              1, 30) - 1] = c1_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
            for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
              c1_i_x[c1_i8] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 884, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  884U, 28U, c1_Bytecounter + (real_T)c1_i8), 1, 7300) - 1];
            }

            memcpy(&c1_b_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 867, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 867U, 4U, (real_T)c1_indx),
              1, 30) + 29] = c1_b_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
            for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
              c1_i_x[c1_i9] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1042, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1042U, 28U, c1_Bytecounter + (real_T)c1_i9), 1, 7300) - 1];
            }

            memcpy(&c1_c_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1025, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1025U, 4U, (real_T)c1_indx),
              1, 30) + 59] = c1_c_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
            for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
              c1_i_x[c1_i10] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1200, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1200U, 28U, c1_Bytecounter + (real_T)c1_i10), 1, 7300) - 1];
            }

            memcpy(&c1_d_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1183, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1183U, 4U, (real_T)c1_indx),
              1, 30) + 89] = c1_d_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
            for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
              c1_i_x[c1_i11] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1358, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1358U, 28U, c1_Bytecounter + (real_T)c1_i11), 1, 7300) - 1];
            }

            memcpy(&c1_e_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1341, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1341U, 4U, (real_T)c1_indx),
              1, 30) + 119] = c1_e_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
            for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
              c1_i_x[c1_i12] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1516, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1516U, 28U, c1_Bytecounter + (real_T)c1_i12), 1, 7300) - 1];
            }

            memcpy(&c1_f_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1499, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1499U, 4U, (real_T)c1_indx),
              1, 30) + 149] = c1_f_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
            for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
              c1_i_x[c1_i13] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1674, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1674U, 28U, c1_Bytecounter + (real_T)c1_i13), 1, 7300) - 1];
            }

            memcpy(&c1_g_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1657, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1657U, 4U, (real_T)c1_indx),
              1, 30) + 179] = c1_g_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
            c1_Bytecounter += 4.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
            for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
              c1_i_x[c1_i14] = c1_b_u[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1832, 28,
                 MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U,
                  1832U, 28U, c1_Bytecounter + (real_T)c1_i14), 1, 7300) - 1];
            }

            memcpy(&c1_h_y, &c1_i_x[0], (size_t)1 * sizeof(real32_T));
            c1_b_Data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 1815, 4, MAX_uint32_T, (int32_T)(uint32_T)
              sf_integer_check(chartInstance->S, 1U, 1815U, 4U, (real_T)c1_indx),
              1, 30) + 209] = c1_h_y;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
            c1_Bytecounter += 4.0;
            c1_b_j = (uint16_T)((uint32_T)c1_b_j + 1U);
            _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
          }

          CV_EML_FOR(0, 1, 1, 0);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
          exitg1 = 1;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 0, false);
        c1_b_i = (uint16_T)((uint32_T)c1_b_i + 1U);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i4 = 0; c1_i4 < 240; c1_i4++) {
    (*chartInstance->c1_Data)[c1_i4] = c1_b_Data[c1_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_getData_from_xplane10MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i5 = 0; c1_i5 < 240; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_Data)[c1_i5], 2U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }
}

static void mdl_start_c1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc1_getData_from_xplane10
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i15;
  int32_T c1_i16;
  const mxArray *c1_y = NULL;
  int32_T c1_i17;
  real32_T c1_b_u[240];
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i15 = 0;
  for (c1_i16 = 0; c1_i16 < 8; c1_i16++) {
    for (c1_i17 = 0; c1_i17 < 30; c1_i17++) {
      c1_b_u[c1_i17 + c1_i15] = (*(real32_T (*)[240])c1_inData)[c1_i17 + c1_i15];
    }

    c1_i15 += 30;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u, 1, 0U, 1U, 0U, 2, 30, 8),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_Data, const char_T *c1_identifier,
  real32_T c1_y[240])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Data), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Data);
}

static void c1_b_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[240])
{
  real32_T c1_fv1[240];
  int32_T c1_i18;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_fv1, 1, 1, 0U, 1, 0U, 2, 30,
                8);
  for (c1_i18 = 0; c1_i18 < 240; c1_i18++) {
    c1_y[c1_i18] = c1_fv1[c1_i18];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Data;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[240];
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_b_Data = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Data), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Data);
  c1_i19 = 0;
  for (c1_i20 = 0; c1_i20 < 8; c1_i20++) {
    for (c1_i21 = 0; c1_i21 < 30; c1_i21++) {
      (*(real32_T (*)[240])c1_outData)[c1_i21 + c1_i19] = c1_y[c1_i21 + c1_i19];
    }

    c1_i19 += 30;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint16_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(uint16_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i22;
  const mxArray *c1_y = NULL;
  uint8_T c1_b_u[7300];
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i22 = 0; c1_i22 < 7300; c1_i22++) {
    c1_b_u[c1_i22] = (*(uint8_T (*)[7300])c1_inData)[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u, 3, 0U, 1U, 0U, 2, 7300, 1),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint32_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(uint32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint32_T c1_d_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u3, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u3;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_indx;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_indx = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_indx), &c1_thisId);
  sf_mex_destroy(&c1_indx);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint16_T c1_e_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint16_T c1_y;
  uint16_T c1_u4;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u4, 1, 5, 0U, 0, 0U, 0);
  c1_y = c1_u4;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_j;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint16_T c1_y;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_j = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_j), &c1_thisId);
  sf_mex_destroy(&c1_j);
  *(uint16_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_getData_from_xplane10_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_check_forloop_overflow_error
  (SFc1_getData_from_xplane10InstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_cv1[6] = { 'u', 'i', 'n', 't', '1', '6' };

  (void)chartInstance;
  if (!c1_overflow) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_y, 14, c1_b_y));
  }
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i23;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i23, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i23;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_getData_from_xplane10, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_getData_from_xplane10), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_getData_from_xplane10);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u5;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u5, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u5;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_getData_from_xplane10InstanceStruct
  *chartInstance)
{
  chartInstance->c1_u = (uint8_T (*)[7300])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_Data = (real32_T (*)[240])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_msgLen = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c1_getData_from_xplane10_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(164442609U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2284968984U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3250152407U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2227903969U);
}

mxArray* sf_c1_getData_from_xplane10_get_post_codegen_info(void);
mxArray *sf_c1_getData_from_xplane10_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y8LrVoU4mQ11piD9bUX7wG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7300);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(30);
      pr[1] = (double)(8);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_getData_from_xplane10_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_getData_from_xplane10_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_getData_from_xplane10_jit_fallback_info(void)
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

mxArray *sf_c1_getData_from_xplane10_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_getData_from_xplane10_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_getData_from_xplane10(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Data\",},{M[8],M[0],T\"is_active_c1_getData_from_xplane10\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_getData_from_xplane10_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_getData_from_xplane10InstanceStruct *chartInstance =
      (SFc1_getData_from_xplane10InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _getData_from_xplane10MachineNumber_,
           1,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_getData_from_xplane10MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_getData_from_xplane10MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _getData_from_xplane10MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"msgLen");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Data");
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
        _SFD_CV_INIT_EML(0,1,1,0,1,0,3,0,2,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2007);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,410,-1,413);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,75,-1,83);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,94,-1,104);
        _SFD_CV_INIT_EML_IF(0,1,0,381,420,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,357,372,1994);
        _SFD_CV_INIT_EML_FOR(0,1,1,460,477,1968);

        {
          static int condStart[] = { 384, 403 };

          static int condEnd[] = { 399, 420 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,384,420,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 7300U;
          dimVector[1]= 1U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 30U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _getData_from_xplane10MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_getData_from_xplane10InstanceStruct *chartInstance =
      (SFc1_getData_from_xplane10InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c1_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c1_Data);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_msgLen);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sx8nufOzaizSvpbkfPr8dG";
}

static void sf_opaque_initialize_c1_getData_from_xplane10(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_getData_from_xplane10InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_getData_from_xplane10
    ((SFc1_getData_from_xplane10InstanceStruct*) chartInstanceVar);
  initialize_c1_getData_from_xplane10((SFc1_getData_from_xplane10InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_getData_from_xplane10(void *chartInstanceVar)
{
  enable_c1_getData_from_xplane10((SFc1_getData_from_xplane10InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_getData_from_xplane10(void *chartInstanceVar)
{
  disable_c1_getData_from_xplane10((SFc1_getData_from_xplane10InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_getData_from_xplane10(void *chartInstanceVar)
{
  sf_gateway_c1_getData_from_xplane10((SFc1_getData_from_xplane10InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_getData_from_xplane10(SimStruct*
  S)
{
  return get_sim_state_c1_getData_from_xplane10
    ((SFc1_getData_from_xplane10InstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_getData_from_xplane10(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_getData_from_xplane10
    ((SFc1_getData_from_xplane10InstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_getData_from_xplane10(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_getData_from_xplane10InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_getData_from_xplane10_optimization_info();
    }

    finalize_c1_getData_from_xplane10((SFc1_getData_from_xplane10InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_getData_from_xplane10
    ((SFc1_getData_from_xplane10InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_getData_from_xplane10(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_getData_from_xplane10
      ((SFc1_getData_from_xplane10InstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_getData_from_xplane10(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_getData_from_xplane10_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(135554174U));
  ssSetChecksum1(S,(349936051U));
  ssSetChecksum2(S,(3016979132U));
  ssSetChecksum3(S,(34432589U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_getData_from_xplane10(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_getData_from_xplane10(SimStruct *S)
{
  SFc1_getData_from_xplane10InstanceStruct *chartInstance;
  chartInstance = (SFc1_getData_from_xplane10InstanceStruct *)utMalloc(sizeof
    (SFc1_getData_from_xplane10InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_getData_from_xplane10InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_getData_from_xplane10;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_getData_from_xplane10;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_getData_from_xplane10;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_getData_from_xplane10;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_getData_from_xplane10;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_getData_from_xplane10;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_getData_from_xplane10;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_getData_from_xplane10;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_getData_from_xplane10;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_getData_from_xplane10;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_getData_from_xplane10;
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
  mdl_start_c1_getData_from_xplane10(chartInstance);
}

void c1_getData_from_xplane10_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_getData_from_xplane10(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_getData_from_xplane10(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_getData_from_xplane10(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_getData_from_xplane10_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
