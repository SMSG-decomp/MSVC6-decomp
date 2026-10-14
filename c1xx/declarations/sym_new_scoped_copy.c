c1_symbol * __cdecl sym_new_scoped_copy(c1_symbol *qualified,int arena)

{
  c1_keyed_list *list;
  c1_symbol *pcVar1;
  byte bVar2;
  fe_name *name;
  
  name = qualified->name;
  list = (c1_keyed_list *)list_copy_with_header((int *)qualified->type,arena);
  pcVar1 = (c1_symbol *)sym_new_overload_set_record(list,name,arena);
  bVar2 = (qualified->flags1 ^ pcVar1->flags1) & 0x10 ^ pcVar1->flags1;
  pcVar1->flags1 = bVar2;
  bVar2 = (qualified->flags1 ^ bVar2) & 0x20 ^ bVar2;
  pcVar1->flags1 = bVar2;
  pcVar1->flags1 = (bVar2 ^ qualified->flags1) & 0x7f ^ qualified->flags1;
  pcVar1->flags3 = (qualified->flags3 ^ pcVar1->flags3) & 1 ^ pcVar1->flags3;
  return pcVar1;
}

