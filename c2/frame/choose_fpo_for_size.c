void __fastcall choose_fpo_for_size(c2_function *fn,int nlocals)

{
  int iVar1;
  
  if ((((fn->flags & 0x10) != 0) && ((g_reg_symbols[6].flags5 & 0x10) == 0)) &&
     (g_opt_favor_speed == 0)) {
    iVar1 = fpo_frame_reference_count_ok(fn,nlocals);
    if (iVar1 == 0) {
      fn->flags = fn->flags & 0xffffffef;
    }
  }
  return;
}

