void __fastcall pass_narrow_byte_lanes(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  
  pcVar2 = fn->cfg->first->head;
  for (t = fn->cfg->last->end; t != pcVar2; t = t->prev) {
    uVar1 = t->line;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    narrow_byte_lane_tuple(t);
  }
  return;
}

