void __cdecl pragma_pack_pop(int value,int name)

{
  void *pvVar1;
  fe_pack_cell *pfVar2;
  
  pfVar2 = g_pack_stack->top;
  if ((pfVar2->next == (fe_pack_cell *)0x0) || (pfVar2->next->next == (fe_pack_cell *)0x0)) {
    diag_warning(3,0xa1);
    if (value != 0) goto LAB_1062a8e2;
    value = g_opt_Zp;
    if (g_opt_Zp == -1) {
      pfVar2->packing = 8;
      return;
    }
  }
  else {
    list_pop_cell((int *)g_pack_stack);
    pvVar1 = pfVar2->ident;
    while (pvVar1 != (void *)name) {
      if (name == 0) {
        diag_warning(3,0x9f,pfVar2->ident);
        break;
      }
      if (pfVar2->next == (fe_pack_cell *)0x0) {
        diag_warning(3,0xa0,name);
        if (value != 0) goto LAB_1062a8e2;
        value = g_opt_Zp;
        if (g_opt_Zp == -1) {
          pfVar2->packing = 8;
          return;
        }
        break;
      }
      pfVar2 = g_pack_stack->top;
      list_pop_cell((int *)g_pack_stack);
      pvVar1 = pfVar2->ident;
    }
  }
  if (value == 0) {
    return;
  }
LAB_1062a8e2:
  pfVar2->packing = value;
  return;
}

