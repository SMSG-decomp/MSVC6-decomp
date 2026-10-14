void __fastcall enable_aligned_double_frame(c2_function *fn)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = fn->flags;
  uVar3 = uVar1 | 0x600000;
  iVar2._0_1_ = g_cur_func_sym->level;
  iVar2._1_1_ = g_cur_func_sym->combine;
  iVar2._2_2_ = g_cur_func_sym->u44;
  fn->flags = uVar3;
  if ((iVar2 != 0) && (g_frame_has_param_double_refs != 0)) {
    fn->flags = CONCAT31((int3)(uVar3 >> 8),(char)uVar1) & 0xffffffef;
  }
  return;
}

