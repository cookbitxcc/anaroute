/**
 * @file   drcMgr.cpp
 * @brief  Design Rule Checking - Manager
 * @author Hao Chen
 * @date   10/23/2019
 *
 **/

#include "drcMgr.hpp"

PROJECT_NAMESPACE_START

/////////////////////////////////////////
//    Wire level checking              //
/////////////////////////////////////////
// short
bool DrcMgr::checkWireRoutingLayerShort(const UInt_t netIdx, const UInt_t layerIdx, const Box<Int_t>& b) const {
  // check pin
  Vector_t<UInt_t> vPinIndices;
  _cir.querySpatialPin(layerIdx, b, vPinIndices);
  for (const UInt_t pinIdx : vPinIndices) {
    const Pin& pin = _cir.pin(pinIdx);
    if (pin.netIdx() != netIdx)
      return false;
  }
  // check other net's wires
  Vector_t<UInt_t> vNetIndices;
  _cir.querySpatialRoutedWire(layerIdx, b, vNetIndices);
  for (const UInt_t idx : vNetIndices) {
    if (idx != netIdx)
      return false;
  }
  // check blk
  Vector_t<UInt_t> vBlkIndices;
  _cir.querySpatialBlk(layerIdx, b, vBlkIndices);
  for (const UInt_t idx : vBlkIndices) {
    const Blk& blk = _cir.blk(idx);
    if (!blk.bDummy())
      return false;
  }
  return true;
}

bool DrcMgr::checkWireCutLayerShort(const UInt_t netIdx, const UInt_t layerIdx, const Box<Int_t>& b) const {
  // no pin in cut layers
  // check other net's wire (via)
  Vector_t<UInt_t> vNetIndices;
  _cir.querySpatialRoutedWire(layerIdx, b, vNetIndices);
  for (const UInt_t idx : vNetIndices) {
    if (idx != netIdx)
      return false;
  }
  return true;
}

// min area
bool DrcMgr::checkWireMinArea(const UInt_t layerIdx, const Vector_t<Box<Int_t>>& vBoxes) const {
  if (vBoxes.empty()) {
    return true;
  }
  Int_t totalArea = vBoxes[0].area();
  Int_t overlapArea = 0;
  for (Int_t i = 0; i < (Int_t)vBoxes.size() - 1; ++i) {
    const auto& b1 = vBoxes[i];
    const auto& b2 = vBoxes[i + 1];
    totalArea += b2.area();
    overlapArea += Box<Int_t>::overlapArea(b1, b2);
  }
  totalArea -= overlapArea;
  assert(_cir.lef().bRoutingLayer(layerIdx));
  const auto& layerPair = _cir.lef().layerPair(layerIdx);
  const auto& layer = _cir.lef().routingLayer(layerPair.second);
  return totalArea >= layer.minArea();
}

// spacing
bool DrcMgr::checkWireRoutingLayerSpacing(const UInt_t netIdx, const UInt_t layerIdx, const Box<Int_t>& b, const Int_t prl) const {
  assert(_cir.lef().bRoutingLayer(layerIdx));
  const auto& layerPair = _cir.lef().layerPair(layerIdx);
  const auto& layer = _cir.lef().routingLayer(layerPair.second);
  
  Int_t prlSpacing = 0;
  const Int_t wireWidth = std::min(b.width(), b.height());
  if (layer.spacingTable().table.size()) {
    for (Int_t i = 0; i < (Int_t)layer.spacingTable().table.size(); ++i) {
      const auto& table = layer.spacingTable().table[i];
      const auto& width = table.first;
      const auto& vSpacings = table.second;
      if (wireWidth >= width) {
        assert(vSpacings.size() == layer.spacingTable().vParallelRunLength.size());
        for (Int_t j = 0; j < (Int_t)vSpacings.size(); ++j) {
          if (prl >= layer.spacingTable().vParallelRunLength[j]) {
            prlSpacing = vSpacings[j];
            //prlSpacing = vSpacings.back();
            break;
          }
        }
        break;
      }
    }
  }
  else {
    prlSpacing = layer.spacing(0);
  }
  //const Int_t eolSpacing = layer.numEolSpacings() ? layer.eolSpacing(0) : 0;
  //const Int_t eolWithin = layer.numEolSpacings() ? layer.eolWithin(0) : 0;
  
  Box<Int_t> checkBox(b);
  checkBox.expand(prlSpacing - 1);
  
  // check pin
  Vector_t<UInt_t> vPinIndices;
  _cir.querySpatialPin(layerIdx, checkBox, vPinIndices);
  for (const UInt_t pinIdx : vPinIndices) {
    const Pin& pin = _cir.pin(pinIdx);
    if (pin.netIdx() != netIdx)
      return false;
  }
  // check other net's wires
  Vector_t<UInt_t> vNetIndices;
  _cir.querySpatialRoutedWire(layerIdx, checkBox, vNetIndices);
  for (const UInt_t idx : vNetIndices) {
    if (idx != netIdx)
      return false;
  }
  // check blk
  Vector_t<UInt_t> vBlkIndices;
  _cir.querySpatialBlk(layerIdx, checkBox, vBlkIndices);
  for (const UInt_t idx : vBlkIndices) {
    const Blk& blk = _cir.blk(idx);
    //if (!blk.bDummy()) {
      //return false;
    //}
    if (blk.pinIdx() == MAX_UINT)
      return false;
    else if (netIdx != _cir.pin(blk.pinIdx()).netIdx())
      return false;
  }
  return true;
}

bool DrcMgr::checkWireCutLayerSpacing(const UInt_t netIdx, const UInt_t layerIdx, const Box<Int_t>& b) const {
  assert(_cir.lef().bCutLayer(layerIdx));
  const auto& layerPair = _cir.lef().layerPair(layerIdx);
  const auto& layer = _cir.lef().cutLayer(layerPair.second);
  const Int_t spacing = layer.spacing();
  
  Box<Int_t> checkBox(b);
  checkBox.expand(spacing - 1);
  
  // no pin in cut layers
  // check other net's wire (via)
  Vector_t<UInt_t> vNetIndices;
  _cir.querySpatialRoutedWire(layerIdx, checkBox, vNetIndices);
  for (const UInt_t idx : vNetIndices) {
    if (idx != netIdx)
      return false;
  }
  return true;
}

bool DrcMgr::checkWireEolSpacing(const UInt_t netIdx, const UInt_t layerIdx, const Box<Int_t>& b) const {

  return true;
}


bool DrcMgr::checkViaSpacing(const UInt_t netIdx, const Int_t x, const Int_t y, const LefVia& via) const {
  // check bot boxes
  for (auto box : via.vBotBoxes()) {
    box.shift(x, y);
    if (!checkWireRoutingLayerSpacing(netIdx, via.botLayerIdx(), box))
      return false;
  }
  // check cut boxes
  for (auto box : via.vCutBoxes()) {
    box.shift(x, y);
    if (!checkWireCutLayerSpacing(netIdx, via.cutLayerIdx(), box))
      return false;
  }
  // check top boxes
  for (auto box : via.vTopBoxes()) {
    box.shift(x, y);
    if (!checkWireRoutingLayerSpacing(netIdx, via.topLayerIdx(), box))
      return false;
  }
  return true;
}

PROJECT_NAMESPACE_END
