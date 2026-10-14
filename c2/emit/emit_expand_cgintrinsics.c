void __fastcall emit_expand_cgintrinsics(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *intrin;
  
  pcVar2 = fn->cfg->first->head;
  while (intrin = pcVar2, intrin != (c2_tuple *)0x0) {
    pcVar2 = intrin->next;
    if (intrin->op == 0x166) {
      uVar1 = intrin->line;
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      emit_expand_interlocked_intrinsic(intrin);
      tuple_unlink_free(intrin);
    }
  }
  return;
}

