void __thiscall lookup_check_symbol_kind(c1_scope_stack *stack,byte *key,int name,char p4)

{
  bool bVar1;
  char cVar2;
  c1xx_class_scope *pcVar3;
  
  bVar1 = false;
  if (key != (byte *)0x0) {
    if ((*key & 0x1f) == 0xf) {
      if ((key[0x1a] & 2) != 0) {
        return;
      }
      bVar1 = true;
      key = &g_scope_vector->entries[*(short *)(key + 0x18)]->kind;
    }
    else {
      cVar2 = lookup_is_type_or_member_of_type((c1_symbol *)key);
      if (cVar2 == '\0') {
        return;
      }
    }
    pcVar3 = lookup_overload_member
                       (stack,(c1_symbol *)key,(-(uint)(p4 != '\0') & 0xfffffffe) + 0xfe);
    if ((pcVar3 != (c1xx_class_scope *)0x0) &&
       ((bVar1 || (((c1_symbol *)key)->name == (fe_name *)name)))) {
      pcVar3->reached = '\x01';
    }
  }
  return;
}

