#!/bin/bash

HAO="/home/local/eda06/haoc"
HAO_WORKSPACE="$HAO/workspace"
ANAROUTE_DIR="$HAO/projects/anaroute"
BENCH_DIR="../bench_new"
OUT_DIR="./out"
GDB="gdb --args"
#GDB=""

# Comparator
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/COMPARATOR_PRE_AMP_2018_Modify_test_flow/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/COMPARATOR_PRE_AMP_2018_Modify_test_flow/COMPARATOR_PRE_AMP_2018_Modify_test_flow.wellgen.gds \
           #--symnet $BENCH_DIR/COMPARATOR_PRE_AMP_2018_Modify_test_flow/COMPARATOR_PRE_AMP_2018_Modify_test_flow.symnet \
           #--iopin $BENCH_DIR/COMPARATOR_PRE_AMP_2018_Modify_test_flow/COMPARATOR_PRE_AMP_2018_Modify_test_flow.iopin \
           #--out $OUT_DIR/gds/COMPARATOR_PRE_AMP_2018_Modify_test_flow.route.gds \
           #--out_guide $OUT_DIR/guide/COMPARATOR_PRE_AMP_2018_Modify_test_flow.guide

# OTA_FF_2s_v3_org
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/OTA_FF_2s_v3_org/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/OTA_FF_2s_v3_org/OTA_FF_2s_v3_org.wellgen.gds \
           #--symnet $BENCH_DIR/OTA_FF_2s_v3_org/OTA_FF_2s_v3_org.symnet \
           #--iopin $BENCH_DIR/OTA_FF_2s_v3_org/OTA_FF_2s_v3_org.iopin \
           #--out $OUT_DIR/gds/OTA_FF_2s_v3_org.route.gds \
           #--out_guide $OUT_DIR/guide/OTA_FF_2s_v3_org.guide \


# Telescopic_Three_stage_flow
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/Telescopic_Three_stage_flow/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/Telescopic_Three_stage_flow/Telescopic_Three_stage_flow.wellgen.gds  \
           #--iopin $BENCH_DIR/Telescopic_Three_stage_flow/Telescopic_Three_stage_flow.iopin \
           #--symnet $BENCH_DIR/Telescopic_Three_stage_flow/Telescopic_Three_stage_flow.symnet \
           #--out $OUT_DIR/gds/Telescopic_Three_stage_flow.gds \
           #--out_guide $OUT_DIR/guide/Telescopic_Three_stage_flow.guide \

# Core_test_flow
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/Core_test_flow/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/Core_test_flow/Core_test_flow.wellgen.gds  \
           #--symnet $BENCH_DIR/Core_test_flow/Core_test_flow.symnet \
           #--out $OUT_DIR/gds/Core_test_flow.gds \
           #--iopin $BENCH_DIR/Core_test_flow/Core_test_flow.iopin \
           #--out_guide $OUT_DIR/guide/Core_test_flow.guide \

# Core_hao
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/Core_hao/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/Core_hao/Core_test_flow.wellgen.gds  \
           #--symnet $BENCH_DIR/Core_hao/Core_test_flow.symnet \
           #--out $OUT_DIR/gds/Core_test_flow.gds \
           #--iopin $BENCH_DIR/Core_test_flow/Core_test_flow.iopin \
           #--fuck a \
           #--out_guide $OUT_DIR/guide/Core_test_flow.guide \

# OTA_4
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/OTA_4/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/OTA_4/OTA_4.wellgen.gds  \
           #--symnet $BENCH_DIR/OTA_4/OTA_4.symnet \
           #--out $OUT_DIR/gds/OTA_4.gds \
           #--iopin $BENCH_DIR/OTA_4/OTA_4.iopin \
           #--out_guide $OUT_DIR/guide/OTA_4.guide \

# SW_VCM
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/SW_VCM/ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/SW_VCM/SW_VCM.wellgen.gds  \
           #--symnet $BENCH_DIR/SW_VCM/SW_VCM.symnet \
           #--out $OUT_DIR/gds/SW_VCM.gds \
           #--iopin $BENCH_DIR/SW_VCM/SW_VCM.iopin \
           #--out_guide $OUT_DIR/guide/SW_VCM.guide \

# SR_Latch_LVT
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/SR_Latch_LVT/SR_Latch_LVT.ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/SR_Latch_LVT/SR_Latch_LVT.wellgen.gds  \
           #--symnet $BENCH_DIR/SR_Latch_LVT/SR_Latch_LVT.symnet \
           #--out $OUT_DIR/gds/SR_Latch_LVT.gds \
           #--out_guide $OUT_DIR/guide/SR_Latch_LVT.guide \

# Comparator
#$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           #--tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           #--design_file $BENCH_DIR/COMPARATOR/COMPARATOR_schematic.ROUTING_INPUT.gr \
           #--placement_layout $BENCH_DIR/COMPARATOR/COMPARATOR_schematic.wellgen.gds \
           #--symnet $BENCH_DIR/COMPARATOR/COMPARATOR_schematic.symnet \
           #--out $OUT_DIR/gds/COMPARATOR.route.gds \
           #--out_guide $OUT_DIR/guide/COMPARATOR.guide

# CTDSM
$GDB ./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           --tech_file $HAO_WORKSPACE/packages/tech/tsmc40_techfile \
           --design_file $BENCH_DIR/CTDSM_TOP_hao/CTDSM_TOP.ROUTING_INPUT.gr \
           --placement_layout $BENCH_DIR/CTDSM_TOP_hao/CTDSM_TOP.wellgen.gds \
           --symnet $BENCH_DIR/CTDSM_TOP_hao/CTDSM_TOP.symnet \
           --out $OUT_DIR/gds/CTDSM_TOP.route.gds \
           --out_guide $OUT_DIR/guide/CTDSM_TOP.guide
