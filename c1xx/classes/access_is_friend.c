int __cdecl access_is_friend(c1_symbol *sym,c1_symbol *cls)

{
  c1_symbol *friend_sym;
  int *friend_entry;
  c1_symbol *tmpl;
  c1_symbol *pcVar1;
  c1_symbol *sym_class;
  int iVar2;
  uint local_c [3];
  
  tmpl = (c1_symbol *)0x0;
  iVar2 = 0;
  if ((sym->kind & 0x1f) == 4) {
    pcVar1 = (c1_symbol *)0x0;
    sym_class = sym;
  }
  else {
    if ((*(byte *)((int)&sym->tail + 9) & 0xc0) != 0) {
      tmpl = tmpl_template_of_instance(sym);
    }
    pcVar1 = sym;
    if ((sym->flags1 & 4) == 0) {
      sym_class = (c1_symbol *)0x0;
    }
    else {
      sym_class = g_scope_vector->entries[(short)sym->scope_index];
    }
  }
  local_c[0] = cls->entity & 0xffffff;
  friend_entry = class_friend_table_lookup(local_c);
  do {
    if (friend_entry == (int *)0x0) {
      return iVar2;
    }
    friend_sym = (c1_symbol *)friend_entry[1];
    if ((friend_sym->kind & 0x1f) == 4) {
      if ((sym_class != (c1_symbol *)0x0) && (friend_sym == sym_class)) {
        iVar2 = 1;
      }
    }
    else if (pcVar1 != (c1_symbol *)0x0) {
      if (friend_sym == pcVar1) {
        iVar2 = 2;
      }
      else if (tmpl != (c1_symbol *)0x0) {
        iVar2 = access_is_friend_fragment(friend_sym,friend_entry,tmpl,iVar2,sym_class,pcVar1);
        return iVar2;
      }
    }
    friend_entry = (int *)friend_entry[2];
  } while (iVar2 == 0);
  return iVar2;
}

