void __thiscall block_scope_insert(void *type2,c1_symbol *sym2)

{
  int iVar1;
  c1_symbol *pcVar2;
  
  pcVar2 = sym_insert_check_alias(sym2);
  if (pcVar2 != (c1_symbol *)0x0) {
    pcVar2->flags3 = pcVar2->flags3 | 8;
    iVar1 = *(int *)((int)type2 + 0x14);
    (**(code **)(*(int *)type2 + 0x28))(pcVar2);
    if (iVar1 == 0) {
      scope_push_block(g_current_scope,type2);
    }
  }
  return;
}

