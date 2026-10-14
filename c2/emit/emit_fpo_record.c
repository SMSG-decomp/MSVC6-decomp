void __fastcall emit_fpo_record(c2_fe_symbol *fsym,int non_fpo_frame,int ebp_allocated)

{
  uint uVar1;
  uint8_t ebp_allocated_00;
  
  if (fsym->dbg_start < 0x100) {
    if ((ebp_allocated == 0) && (non_fpo_frame == 0)) {
      ebp_allocated_00 = '\0';
    }
    else {
      ebp_allocated_00 = '\x01';
    }
    uVar1._0_1_ = fsym->level;
    uVar1._1_1_ = fsym->combine;
    uVar1._2_2_ = fsym->u44;
    emit_fpo_header(fsym,0,fsym->code_size,(fsym->frame_size >> 2) + (uint)(non_fpo_frame != 0),
                    (uint16_t)(uVar1 >> 2),(uint8_t)fsym->dbg_start,
                    (uint8_t)g_cur_function->callee_save_pushes,'\0',non_fpo_frame,ebp_allocated_00)
    ;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",699);
}

