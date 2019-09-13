/**
 * @file   lefreader.hpp
 * @brief  Lef file parser using Limbo wrapper
 * @author Hao Chen
 * @date   09/09/2019
 *
 **/

#ifndef _LEF_READER_HPP_
#define _LEF_READER_HPP_

#include <limbo/parsers/lef/adapt/LefDriver.h>

#include "src/global/global.hpp"
#include "src/db/dbLef.hpp"

PROJECT_NAMESPACE_START

/**
 * @class LefReader
 * @brief Inherit the Limbo lef wrapper to define functions
 *
 * **/


class LefReader : public LefParser::LefDataBase { // LefParser::LefDataBase (Limbo)
 public:
  LefReader(LefDB& t) : _lef(t) {}
  ~LefReader() {}

  void parse(const String_t& filename) {
    LefParser::read(*this, filename.c_str()); // Limbo defined function
  }
  // Override functions
  void lef_version_cbk(String_t const& v) override;
  void lef_version_cbk(double v) override;
  void lef_dividerchar_cbk(const String_t &v) override;
  //void lef_casesensitive_cbk(int v) override;
  //void lef_nowireextension_cbk(const String_t &v) override;
  void lef_manufacturing_cbk(double v) override;
  //void lef_useminspacing_cbk(lefiUseMinSpacing const &v) override;
  void lef_clearancemeasure_cbk(const String_t &v) override;
  void lef_units_cbk(lefiUnits const &v) override;
  void lef_busbitchars_cbk(const String_t &v) override;
  void lef_layer_cbk(lefiLayer const &v) override;
  //void lef_maxstackvia_cbk(lefiMaxStackVia const &v) override;
  //void lef_via_cbk(lefiVia const &v) override;
  //void lef_viarule_cbk(lefiViaRule const &v) override;
  //void lef_spacing_cbk(lefiSpacing const &v) override;
  //void lef_irdrop_cbk(lefiIRDrop const &v) override;
  //void lef_minfeature_cbk(lefiMinFeature const &v) override;
  //void lef_dielectric_cbk(double v) override;
  //void lef_nondefault_cbk(lefiNonDefault const &v) override;
  //void lef_site_cbk(lefiSite const &v) override;
  //void lef_macrobegin_cbk(String_t const &v) override;
  //void lef_macro_cbk(lefiMacro const &v) override;
  //void lef_pin_cbk(lefiPin const &v) override;
  //void lef_obstruction_cbk(lefiObstruction const &v) override;
  //void lef_density_cbk(lefiDensity const &v) override;
  //void lef_timing_cbk(lefiTiming const &v) override;
  //void lef_array_cbk(lefiArray const &v) override;
  void lef_prop_cbk(lefiProp const &v) override;
  //void lef_noisemargin_cbk(lefiNoiseMargin const &v) override;
  //void lef_edgeratethreshold1_cbk(double v) override;
  //void lef_edgeratethreshold2_cbk(double v) override;
  //void lef_edgeratescalefactor_cbk(double v) override;
  //void lef_noisetable_cbk(lefiNoiseTable const &v) override;
  //void lef_correctiontable_cbk(lefiCorrectionTable const &v) override;
  //void lef_inputantenna_cbk(double v) override;
  //void lef_outputantenna_cbk(double v) override;
  //void lef_inoutantenna_cbk(double v) override;
  //void lef_antennainput_cbk(double v) override;
  //void lef_antennaoutput_cbk(double v) override;
  //void lef_antennainout_cbk(double v) override;
  //void lef_extension_cbk(const String_t &v) override;

 private:
  LefDB& _lef;

  /////////////////////////////////////////
  //    Private functions                //
  /////////////////////////////////////////
  void parseRoutingLayer(const lefiLayer& v);
  /////////////////////////////////////////
  //    Helper functions                 //
  /////////////////////////////////////////
  Int_t to_lef_unit_1d(const Real_t n) const {
    assert(_lef.units().hasDatabase());
    Int_t unitLEF = _lef.units().databaseNumber();
    return std::round(n * unitLEF);
  }
  Int_t to_lef_unit_2d(const Real_t n) const {
    assert(_lef.units().hasDatabase());
    Int_t unitLEF = _lef.units().databaseNumber();
    return std::round(n * unitLEF * unitLEF);
  }
};


PROJECT_NAMESPACE_END

#endif /// _LEF_READER_HPP_