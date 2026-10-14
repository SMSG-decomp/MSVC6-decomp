void __thiscall decl_parameter_list_end(int *list,c1_symbol *param)

{
  int iVar1;
  void *pvVar2;
  uchar *puVar3;
  fe_name **ppfVar4;
  
  puVar3 = g_arenas[2].cur;
  if (*list == 0) {
    g_arenas[2].cur = g_arenas[2].cur + 0xc;
    if (g_arenas[2].end < g_arenas[2].cur) {
      arena_grow(g_arenas + 2);
    }
    if (puVar3 == (uchar *)0x0) {
      puVar3 = (uchar *)0x0;
    }
    else {
      puVar3[0] = '\x02';
      puVar3[1] = '\0';
      puVar3[2] = '\0';
      puVar3[3] = '\0';
      puVar3[4] = '\0';
      puVar3[5] = '\0';
      puVar3[6] = '\0';
      puVar3[7] = '\0';
      puVar3[8] = '\0';
      puVar3[9] = '\0';
      puVar3[10] = '\0';
      puVar3[0xb] = '\0';
    }
    *list = (int)puVar3;
  }
  iVar1 = *list;
  ppfVar4 = &param->name;
  if (ppfVar4 == (fe_name **)0x0) {
    ppfVar4 = (fe_name **)0x0;
  }
  else {
    pvVar2 = *(void **)(iVar1 + 8);
    *ppfVar4 = *ppfVar4;
    param->next = (c1_sym_link *)0x0;
    param->detail = pvVar2;
  }
  if (*(int *)(iVar1 + 8) != 0) {
    if (g_empty_list_sentinel == (c1_symbol *)0x0) {
      g_empty_list_sentinel = sym_new_kind12();
    }
    if ((c1_symbol *)(*(int *)(iVar1 + 8) + -8) != g_empty_list_sentinel) {
      *(fe_name ***)(*(int *)(iVar1 + 8) + 4) = ppfVar4;
      *(fe_name ***)(iVar1 + 8) = ppfVar4;
      return;
    }
    *(fe_name ***)(iVar1 + 4) = ppfVar4;
    *(fe_name ***)(iVar1 + 8) = ppfVar4;
    return;
  }
  *(fe_name ***)(iVar1 + 4) = ppfVar4;
  *(fe_name ***)(iVar1 + 8) = ppfVar4;
  return;
}

