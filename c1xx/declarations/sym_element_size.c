int __cdecl sym_element_size(int sym)

{
  ushort uVar1;
  c1_type *t;
  char cVar2;
  ushort uVar3;
  int iVar4;
  c1_symbol *cls;
  
  t = *(c1_type **)(sym + 0x14);
  uVar1 = t->code;
  cVar2 = (char)uVar1;
  while (((cVar2 < '\0' && ((uVar1 & 0x8f) != 0x86)) && ((uVar1 & 0x8f) != 0x82))) {
    t = t->base;
    uVar1 = t->code;
    cVar2 = (char)uVar1;
  }
  if ((char)t->code < '\0') {
    return 4;
  }
  uVar1 = t->code;
  while( true ) {
    if ((uVar1 & 0x530) != 0) {
      return (int)(char)(&g_type_rank_table)[(byte)t->code & 0xf];
    }
    uVar3 = uVar1 & 0x8f;
    if (((uVar3 == 0x83) || (uVar3 == 0x82)) ||
       ((uVar3 == 0x86 || (((char)uVar1 < '\0' && (uVar3 == 0x80)))))) {
      return 4;
    }
    if ((uVar1 >> 9 & 1) != 0) {
      if ((t->code & 0x200) == 0) {
        cls = (c1_symbol *)0x0;
      }
      else {
        cls = (t->extra).cls;
      }
      if ((cls->kind & 0x1f) != 4) {
        if ((cls->type->code & 0x200) == 0) {
          return *piRam00000024;
        }
        return ((((cls->type->extra).cls)->detail).cls)->size;
      }
      if ((cls->flags2 & 4) == 0) {
        tmpl_instantiate_if_needed(cls);
      }
      if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
        mre_note_class_layout_use(g_minimal_rebuild_tracker,cls);
      }
      return ((cls->detail).cls)->size;
    }
    if (uVar3 == 0x8a) {
      iVar4 = type_data_member_pointer_size(t);
      return iVar4;
    }
    if (uVar3 == 0x8e) break;
    if (((uVar1 >> 0xb & 1) == 0) ||
       (((uVar1 & 0xfff) != 0x802 && (((char)uVar1 < '\0' || ((uVar1 & 0xfff) != 0x801)))))) {
      return 0;
    }
    uVar1 = g_type_int->code;
    t = g_type_int;
  }
  iVar4 = type_member_pointer_size_kind(t);
  return iVar4;
}

