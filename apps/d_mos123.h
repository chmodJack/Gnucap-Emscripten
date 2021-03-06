/* $Id: d_mos123.model,v 26.133 2009/11/26 04:58:04 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
 * Author: Albert Davis <aldavis@gnu.org>
 *
 * This file is part of "Gnucap", the Gnu Circuit Analysis Package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *------------------------------------------------------------------
 * MOS model - base for levels 1,2,3,6
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS123_H_INCLUDED
#define D_MOS123_H_INCLUDED

#include "d_mos_base.h"
  enum gate_t {gtSAME = -1, gtMETAL = 0, gtOPP = 1};
  const double NI = 1.45e16;	/* intrinsic carrier concentration */
#include "u_sdp.h"
#include "e_node.h"
#include "e_subckt.h"
#include "e_model.h"
/*--------------------------------------------------------------------------*/
class SDP_BUILT_IN_MOS123
  :public SDP_BUILT_IN_MOS_BASE{
public:
  explicit SDP_BUILT_IN_MOS123(const COMMON_COMPONENT* c) : SDP_BUILT_IN_MOS_BASE(c) {init(c);}
  void init(const COMMON_COMPONENT*);
public:
};
/*--------------------------------------------------------------------------*/
class DEV_BUILT_IN_MOS;
class TDP_BUILT_IN_MOS123
  :public TDP_BUILT_IN_MOS_BASE{
public:
  explicit TDP_BUILT_IN_MOS123(const DEV_BUILT_IN_MOS*);
public:
};
/*--------------------------------------------------------------------------*/
class MODEL_BUILT_IN_MOS123
  :public MODEL_BUILT_IN_MOS_BASE{
protected:
  explicit MODEL_BUILT_IN_MOS123(const MODEL_BUILT_IN_MOS123& p);
public:
  explicit MODEL_BUILT_IN_MOS123(const BASE_SUBCKT*);
  ~MODEL_BUILT_IN_MOS123() {--_count;}
public: // override virtual
  std::string dev_type()const;
  void      set_dev_type(const std::string& nt);
  CARD*     clone()const {return new MODEL_BUILT_IN_MOS123(*this);}
  void      precalc_first();
  void      precalc_last();
  SDP_CARD* new_sdp(COMMON_COMPONENT* c)const;
  void      set_param_by_index(int, std::string&, int);
  bool      param_is_printable(int)const;
  std::string param_name(int)const;
  std::string param_name(int,int)const;
  std::string param_value(int)const;
  int param_count()const {return (15 + MODEL_BUILT_IN_MOS_BASE::param_count());}
  bool      is_valid(const COMPONENT*)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  PARAMETER<double> vto_raw;	// zero-bias threshold voltage
  PARAMETER<double> gamma;	// bulk threshold parameter
  PARAMETER<double> phi;	// surface potential
  PARAMETER<double> lambda;	// channel-length modulation
  PARAMETER<double> tox;	// oxide thickness
  PARAMETER<double> nsub_cm;	// substrate doping
  PARAMETER<double> nss_cm;	// surface state density
  PARAMETER<double> xj;	// metallurgical junction depth
  PARAMETER<double> uo_cm;	// surface mobility
  PARAMETER<int> tpg;	// type of gate material - really gate_t
public: // calculated parameters
  double nsub;	// 
  double nss;	// 
  double uo;	// 
  double vto;	// 
  double cox;	// oxide capacitance (E_OX / tox)
  bool calc_vto;	// 
  bool calc_gamma;	// 
  bool calc_phi;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
