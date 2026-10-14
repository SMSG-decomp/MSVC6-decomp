uint32_t __fastcall select_cost_within_threshold(c2_tuple *sel)

{
  ushort uVar1;
  int iVar2;
  uint local_8;
  uint local_4;
  
  if (((((1 << (byte)(sel->type >> 0xc) & 0xeU) != 0) && ((sel->type & 0xfff) < 5)) &&
      (uVar1 = sel->src->sym->def->type, (1 << (byte)(uVar1 >> 0xc) & 0xeU) != 0)) &&
     ((uVar1 & 0xfff) < 5)) {
    lower_select_sbb(sel,0,&local_8);
    lower_select_setcc(sel,0,&local_4);
    if (g_opt_favor_speed == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = g_opt_cpu_target + -4;
    }
    if ((local_8 <= g_select_form_cost_table[4][iVar2]) ||
       (local_4 <= g_select_form_cost_table[4][iVar2])) {
      return 1;
    }
  }
  return 0;
}

