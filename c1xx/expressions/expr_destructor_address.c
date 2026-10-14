c1_node * __cdecl expr_destructor_address(c1_type *type)

{
  byte bVar1;
  byte bVar2;
  c1_symbol *sym;
  c1_node *pcVar3;
  c1_type *pcVar4;
  
  sym = (c1_symbol *)class_find_complete_destructor(type);
  sym_mark_referenced(sym);
  special_member_need_definition(sym);
  pcVar4 = sym->type;
  bVar1 = *(byte *)(**(int **)((-(uint)((pcVar4->code & 0x80) != 0) & (uint)pcVar4) + 8) + 2);
  bVar2 = *(byte *)(((uint)pcVar4 & -(uint)((pcVar4->code & 0x80) != 0)) + 2);
  pcVar3 = tree_new_symbol_ref(sym,'\x01');
  pcVar4 = type_record_new_45f0(bVar1 & 0x18,bVar2 & 0x18 | 6);
  pcVar3->type = pcVar4;
  return pcVar3;
}

