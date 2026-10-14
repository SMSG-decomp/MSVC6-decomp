void __fastcall enc_layout_frame_reusing_locals(c2_function *fn)

{
  int iVar1;
  c2_pdb_func_syms *func_syms;
  
  func_syms = (c2_pdb_func_syms *)fn;
  iVar1 = FuncSymsGet(fn->fsym->name,g_enc_funcsyms,&func_syms);
  if (iVar1 == 0) {
    assign_temp_homes_in_reference_order(fn);
    reserve_enc_frame_padding(fn,0x40);
    return;
  }
  zi_preallocate_eh_records();
  enc_restore_local_offsets(func_syms);
  zi_home_remaining_locals();
  assign_temp_homes_in_reference_order(fn);
  enc_finish_frame_padding(func_syms,fn);
  FSRelease(func_syms);
  return;
}

