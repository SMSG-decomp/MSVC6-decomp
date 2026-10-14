int __fastcall type_size_scalar(c1_type *t)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  c1_symbol *cls;
  
  uVar1 = t->code;
  while( true ) {
    if ((uVar1 & 0x530) != 0) {
      return (int)(char)(&g_type_rank_table)[(byte)t->code & 0xf];
    }
    uVar2 = uVar1 & 0x8f;
    if ((((uVar2 == 0x83) || (uVar2 == 0x82)) || (uVar2 == 0x86)) ||
       (((char)uVar1 < '\0' && (uVar2 == 0x80)))) {
      return 4;
    }
    if ((uVar1 >> 9 & 1) != 0) {
      if ((t->code & 0x200) == 0) {
        cls = (c1_symbol *)0x0;
      }
      else {
        cls = (t->extra).cls;
      }
      if ((cls->kind & 0x1f) == 4) {
        if ((cls->flags2 & 4) == 0) {
          tmpl_instantiate_if_needed(cls);
        }
        if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
          mre_note_class_layout_use(g_minimal_rebuild_tracker,cls);
        }
        return ((cls->detail).cls)->size;
      }
      if ((cls->type->code & 0x200) != 0) {
        return ((((cls->type->extra).cls)->detail).cls)->size;
      }
      return *piRam00000024;
    }
    if (uVar2 == 0x8a) {
      iVar3 = type_data_member_pointer_size(t);
      return iVar3;
    }
    if (uVar2 == 0x8e) break;
    if (((uVar1 >> 0xb & 1) == 0) ||
       (((uVar1 & 0xfff) != 0x802 && (((char)uVar1 < '\0' || ((uVar1 & 0xfff) != 0x801)))))) {
      return 0;
    }
    uVar1 = g_type_int->code;
    t = g_type_int;
  }
  iVar3 = type_member_pointer_size_kind(t);
  return iVar3;
}

