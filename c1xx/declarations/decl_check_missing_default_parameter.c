void __thiscall decl_check_missing_default_parameter(c1_function_params *params,c1_symbol *sym)

{
  int iVar1;
  int iVar2;
  c1_node *pcVar3;
  uint count;
  
  iVar1 = 0;
  count = (uint)params->default_count;
  pcVar3 = params->defaults;
  iVar2 = params->list->count - count;
  if (count != 0) {
    do {
      pcVar3 = pcVar3->link;
      iVar2 = iVar2 + 1;
      if (pcVar3->left == (void *)0x0) {
        diag_error(0x224,sym,iVar2);
        iVar1 = iVar1 + 1;
      }
      count = count - 1;
    } while (count != 0);
    if (iVar1 != 0) {
      params->default_count = '\0';
      params->defaults = (c1_node *)0x0;
    }
  }
  return;
}

