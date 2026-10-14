void __cdecl pragma_pack_pop(int value,int name)

{
  void *pvVar1;
  c1_pack_cell *pcVar2;
  
  pcVar2 = g_pack_stack->top;
  if ((pcVar2->next == (c1_pack_cell *)0x0) || (pcVar2->next->next == (c1_pack_cell *)0x0)) {
    diag_warning(3,0xa1);
    if (value != 0) goto LAB_1045eae3;
    value = g_opt_Zp;
    if (g_opt_Zp == -1) {
      pcVar2->packing = 8;
      return;
    }
  }
  else {
    list_pop_cell((int *)g_pack_stack);
    pvVar1 = pcVar2->ident;
    while (pvVar1 != (void *)name) {
      if (name == 0) {
        diag_warning(3,0x9f,pcVar2->ident);
        break;
      }
      if (pcVar2->next == (c1_pack_cell *)0x0) {
        diag_warning(3,0xa0,name);
        if (value != 0) goto LAB_1045eae3;
        value = g_opt_Zp;
        if (g_opt_Zp == -1) {
          pcVar2->packing = 8;
          return;
        }
        break;
      }
      pcVar2 = g_pack_stack->top;
      list_pop_cell((int *)g_pack_stack);
      pvVar1 = pcVar2->ident;
    }
  }
  if (value == 0) {
    return;
  }
LAB_1045eae3:
  pcVar2->packing = value;
  return;
}

