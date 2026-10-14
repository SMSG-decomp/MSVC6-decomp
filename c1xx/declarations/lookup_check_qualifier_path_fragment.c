char __cdecl
lookup_check_qualifier_path_fragment
          (c1_keyed_cell *cell,c1_symbol *member,c1_symbol *scope_class,char at_context_class,
          char static_like_member,uint access,c1_symbol *context_class,int friend_result,
          c1_symbol *scope_class_local,uint base_access,c1_symbol *naming_class,int restricted_step,
          uint prev_access,c1_symbol *member_local,c1_symbol *prev_qualifier,int naming_class_friend
          ,int restricted_friend,byte *sym)

{
  uint uVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  byte bVar4;
  c1_symbol *cls;
  c1_symbol *cls_00;
  int iStack0000002c;
  
  if (member != scope_class) {
    sym = (byte *)CONCAT31(sym._1_3_,1);
    if ((member->kind & 0x1f) == 0xf) {
      access = 3;
    }
    else {
      cell = cell->key;
      access = member->flags2 & 0xffffff03;
    }
    iStack0000002c = 1;
    uVar1 = access;
    pcVar2 = (c1_symbol *)sym;
    for (; cell != (c1_keyed_cell *)0x0; cell = cell->key) {
      cls = cell->sym;
      if (((cls->kind & 0x1f) == 10) && ((cls->storage & 7) == 7)) {
        if ((cls->type->code & 0x200) == 0) {
          diag_error(0x28d,0x53,cls);
          return '\0';
        }
        cls = (cls->type->extra).cls;
      }
      bVar3 = cls->kind & 0x1f;
      cls_00 = cls;
      if ((bVar3 != 4) && (bVar3 != 0x19)) {
        if (bVar3 == 0xf) {
          if ((cls->key_ref & 0x20000) != 0) {
            return '\x01';
          }
          cls_00 = g_scope_vector->entries[(short)cls->key_ref];
        }
        else {
          cls_00 = pcVar2;
          if (bVar3 == 0x16) {
            return '\x01';
          }
        }
      }
      if ((cls_00->kind & 0x1f) == 0x19) {
        return '\x01';
      }
      bVar3 = (byte)uVar1;
      if (naming_class == (c1_symbol *)0x0) {
        access_record_inaccessible_member(bVar3,member_local,cls_00);
        naming_class = cls_00;
      }
      if (((static_like_member != '\0') && (cell != (c1_keyed_cell *)0x0)) && (cell == cell->next))
      {
        if (cls_00 == naming_class) {
          return '\x01';
        }
        return 1 < bVar3;
      }
      if (cls_00 == scope_class_local) {
        sym = (byte *)0x1;
      }
      if (((((cls_00->detail).cls)->layout_flags3b & 0x40) != 0) &&
         ((((friend_result = 0, scope_class_local != (c1_symbol *)0x0 &&
            (friend_result = access_is_friend(scope_class_local,cls_00), friend_result != 0)) ||
           ((context_class != (c1_symbol *)0x0 &&
            (friend_result = access_is_friend(context_class,cls_00), friend_result != 0)))) ||
          ((g_current_function != (c1_symbol *)0x0 &&
           (friend_result = access_is_friend(g_current_function,cls_00), friend_result != 0)))))) {
        if (cls_00 == naming_class) {
          naming_class_friend = 1;
        }
        sym = (byte *)0x1;
      }
      if (cls == context_class) {
        sym = (byte *)0x1;
      }
      if (cell->key == (c1_keyed_cell *)0x0) {
        if (naming_class_friend != 0) {
          if (restricted_step == 0) {
            return '\x01';
          }
          if ((iStack0000002c + -1 <= restricted_step) && (restricted_friend == 1)) {
            return '\x01';
          }
        }
        if (at_context_class != '\0') {
          return '\x01' - ((byte)prev_access < 2);
        }
        return '\x01' - (bVar3 < (byte)sym);
      }
      if ((cls->kind & 0x1f) == 0xf) {
        at_context_class = cls_00 == context_class;
        if ((cls->key_ref & 0x10000) == 0) {
          base_access._0_1_ = cls->flags2 & 3;
        }
        else {
          cell = (c1_keyed_cell *)base_path_skip_base_entries((int *)cell);
          base_access._0_1_ =
               class_base_access((int)g_scope_vector->entries[(short)cls->key_ref],cell->key->sym);
          g_access_report_via_virtual_base = 1;
        }
LAB_1041854f:
        if ((((byte)base_access == 1) || ((byte)base_access == 2)) && (restricted_step == 0)) {
          restricted_step = iStack0000002c;
          restricted_friend = friend_result;
        }
      }
      else {
        at_context_class = '\0';
        base_access._0_1_ = cls->flags2 & 3;
        if ((byte)base_access != 0) goto LAB_1041854f;
        base_access._0_1_ = 3;
      }
      bVar4 = access_compose(bVar3,(byte)base_access);
      access = (uint)bVar4;
      if ((bVar4 < bVar3) && (bVar4 < (byte)sym)) {
        if (prev_qualifier == (c1_symbol *)0x0) {
          bVar4 = 0;
        }
        else {
          bVar4 = prev_qualifier->flags2 & 3;
        }
        access_record_inaccessible_via_base(member_local,cls,bVar4,bVar3,prev_qualifier);
      }
      iStack0000002c = iStack0000002c + 1;
      prev_access = uVar1;
      prev_qualifier = cls;
      uVar1 = access;
      pcVar2 = cls_00;
    }
  }
  return '\x01';
}

