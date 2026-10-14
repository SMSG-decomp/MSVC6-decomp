void __cdecl class_append_member(c1_symbol *member)

{
  uint *puVar1;
  void *pvVar2;
  fe_name **ppfVar3;
  
  ppfVar3 = &member->name;
  if (*ppfVar3 != (fe_name *)0x0) {
    puVar1 = &(*ppfVar3)->flags;
    *puVar1 = *puVar1 | 0x40000;
  }
  pvVar2 = (g_struct_layouts[g_class_depth].tag)->members;
  member->next = (c1_sym_link *)0x0;
  if (*(int *)((int)pvVar2 + 8) != 0) {
    *(fe_name ***)(*(int *)((int)pvVar2 + 8) + 4) = ppfVar3;
    *(fe_name ***)((int)pvVar2 + 8) = ppfVar3;
    return;
  }
  *(fe_name ***)((int)pvVar2 + 4) = ppfVar3;
  *(fe_name ***)((int)pvVar2 + 8) = ppfVar3;
  return;
}

