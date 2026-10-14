void __fastcall report_missing_return(c2_function *fn,int must_return)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  char *pcVar3;
  
  pcVar2 = tuple_find_prev_of_kind(fn->cfg->last->end,'\x18');
  uVar1 = pcVar2->line;
  if (uVar1 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar1;
    g_cur_line = uVar1;
  }
  pcVar3 = fe_symbol_name(fn->fsym,0);
  warning(1,0x2cc - (uint)(must_return != 0),pcVar3);
  return;
}

