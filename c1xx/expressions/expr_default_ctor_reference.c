c1_node * __cdecl expr_default_ctor_reference(c1_type *type,char vector_form)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  c1_symbol *sym2;
  c1_symbol *sym;
  uint uVar4;
  c1_node *pcVar5;
  c1_type *pcVar6;
  
  sym2 = (c1_symbol *)class_find_default_constructor(type);
  cVar1 = (char)type->code;
  while (cVar1 < '\0') {
    type = type->base;
    cVar1 = (char)type->code;
  }
  sym = (c1_symbol *)ovl_make_set_of_two((type->extra).cls,sym2);
  access_check_member(sym);
  if (vector_form == '\0') {
    uVar4 = func_takes_void_parameters(sym2);
    if ((char)uVar4 == '\0') {
      sym2 = symtab_16f4_lookup(sym2);
    }
  }
  else {
    sym2 = symtab_16f8_lookup(sym2);
  }
  special_member_need_definition(sym2);
  pcVar6 = sym2->type;
  bVar2 = *(byte *)(**(int **)((-(uint)((pcVar6->code & 0x80) != 0) & (uint)pcVar6) + 8) + 2);
  bVar3 = *(byte *)(((uint)pcVar6 & -(uint)((pcVar6->code & 0x80) != 0)) + 2);
  pcVar5 = tree_new_symbol_ref(sym2,'\x01');
  pcVar6 = type_record_new_45f0(bVar2 & 0x18,bVar3 & 0x18 | 6);
  pcVar5->type = pcVar6;
  return pcVar5;
}

