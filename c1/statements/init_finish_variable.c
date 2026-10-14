void __cdecl init_finish_variable(c1_symbol *sym)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  c1_symbol *sym_00;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  c1_u16 *pcVar6;
  
  sym_00 = sym;
  if (g_opt_Zg != '\0') {
    g_init_symbol = (c1_symbol *)0x0;
    return;
  }
  if (sym == (c1_symbol *)0x0) {
    g_init_symbol = (c1_symbol *)0x0;
    return;
  }
  if (g_init_brace_depth == -1) {
    return;
  }
  if ((g_init_level->flags & 0x20) != 0) {
    if (-1 < g_init_brace_depth) {
      g_init_brace_depth = g_init_brace_depth + -1;
      g_init_level = g_init_levels + g_init_brace_depth;
      return;
    }
    return;
  }
  init_pop_brace_level();
  bVar1 = sym_00->flags4;
  if (((bVar1 & 4) == 0) || ((bVar1 & 1) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  pcVar4 = sym_00->type;
  if ((pcVar4->code & 0x200) != 0) {
    if ((pcVar4->code & 0x200) == 0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = (pcVar4->extra).sym;
    }
    if ((pcVar5->flags4 & 1) != 0) {
      bVar3 = true;
      goto LAB_106215fc;
    }
  }
  bVar3 = false;
LAB_106215fc:
  if (bVar2) {
    sym_00->flags4 = bVar1 & 0xfe;
    sym = (c1_symbol *)init_unsized_array_count();
    pcVar4 = sym_00->type;
    pcVar6 = (c1_u16 *)(-(uint)((pcVar4->code & 0x80) != 0) & (uint)pcVar4);
    pcVar4 = type_intern_from_parts(pcVar4,*pcVar6,pcVar6[1],(c1_u32 *)&sym);
    sym_00->type = pcVar4;
  }
  else if (bVar3) {
    init_finish_variable_fragment(sym_00);
    return;
  }
  init_end_record(sym_00);
  if (g_il_block_level != '\0') {
    sym_00->key_ref = sym_00->key_ref & 0xfffffff8;
  }
  g_init_symbol = (c1_symbol *)0x0;
  return;
}

