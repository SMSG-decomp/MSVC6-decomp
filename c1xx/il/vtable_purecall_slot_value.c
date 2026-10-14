c1_node * __cdecl vtable_purecall_slot_value(int slot)

{
  c1_symbol *sym;
  c1_node *pcVar1;
  c1_type *pcVar2;
  char use_type;
  uint mode;
  
  mode = 4;
  use_type = '\x01';
  sym = sym_purecall_symbol();
  pcVar1 = tree_new_symbol_ref(sym,use_type);
  pcVar1 = expr_build_address_of(pcVar1,mode);
  pcVar2 = type_member_pointer_checked(*(c1_type **)(slot + 0x14));
  pcVar1->type = pcVar2;
  return pcVar1;
}

