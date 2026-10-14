char __cdecl access_check_member_path(c1_symbol *sym)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  c1_keyed_cell *cell;
  int iVar5;
  c1_symbol *pcVar6;
  c1_symbol *cls;
  char cVar7;
  char cVar8;
  uint access;
  c1_symbol *context_class;
  int friend_result;
  c1_symbol *pcVar9;
  c1_symbol *pcVar10;
  uint base_access;
  c1_symbol *naming_class;
  int local_1c;
  int restricted_step;
  uint prev_access;
  c1_symbol *pcVar11;
  c1_symbol *prev_qualifier;
  int naming_class_friend;
  int restricted_friend;
  
  if ((sym->flags3 & 1) == 0) {
    if (g_current_scope->current->kind < 0xfb) {
      pcVar9 = (c1_symbol *)0x0;
    }
    else {
      if (g_current_scope->current->kind < 0xfb) {
        diag_fatal(1,"symtable.inl",0xbb9);
      }
      pcVar9 = (g_current_scope->current->body).cls;
    }
    naming_class = (c1_symbol *)0x0;
    prev_qualifier = (c1_symbol *)0x0;
    naming_class_friend = 0;
    restricted_step = 0;
    restricted_friend = 0;
    friend_result = 0;
    cVar8 = '\0';
    cVar7 = '\0';
    pcVar10 = pcVar9;
    if (g_class_depth < 0) {
      if ((g_current_function == (c1_symbol *)0x0) || ((g_current_function->kind & 0x1f) != 8)) {
        if ((g_current_scope->current->kind == '\x01') &&
           (iVar5 = scope_parent_skipping_kind_fa(g_current_scope), 0xfa < *(byte *)(iVar5 + 8))) {
          iVar5 = scope_parent_skipping_kind_fa(g_current_scope);
          context_class = *(c1_symbol **)(iVar5 + 0x14);
        }
        else {
          context_class = (c1_symbol *)0x0;
        }
      }
      else {
        context_class = g_scope_vector->entries[(short)g_current_function->scope_index];
      }
    }
    else {
      context_class = class_current_definition();
    }
    cell = *(c1_keyed_cell **)sym->type;
    access_clear_report_context();
    pcVar6 = cell->sym;
    if (((pcVar9 == (c1_symbol *)0x0) || (sym != g_pending_access_check[g_paren_depth])) ||
       ((pcVar6 != pcVar9 && ((sym != g_pending_access_check[g_paren_depth] || (pcVar6 != pcVar9))))
       )) {
      pcVar11 = pcVar6;
      if ((sym->flags1 & 0x80) == 0) {
        cVar2 = access_get_special_member_context();
        sym._0_1_ = '\x03' - (cVar2 != '\0');
      }
      else {
        if (((((pcVar6->storage & 7) == 3) || ((pcVar6->kind & 0x1f) == 5)) ||
            ((pcVar6->flags2 & 0x10) != 0)) && (cVar8 = '\x01', (pcVar6->kind & 0x1f) == 4)) {
          cVar7 = lookup_check_qualifier_path_fragment
                            (cell,pcVar6,pcVar9,cVar7,'\x01',access,context_class,friend_result,
                             pcVar10,base_access,naming_class,restricted_step,prev_access,pcVar6,
                             prev_qualifier,naming_class_friend,restricted_friend,&sym->kind);
          return cVar7;
        }
        sym._0_1_ = '\x01';
      }
      if ((pcVar6->kind & 0x1f) == 0xf) {
        access = 3;
      }
      else {
        cell = cell->key;
        access = pcVar6->flags2 & 0xffffff03;
      }
      local_1c = 1;
      pcVar9 = sym;
      for (; uVar1 = access, cell != (c1_keyed_cell *)0x0; cell = cell->key) {
        pcVar6 = cell->sym;
        if (((pcVar6->kind & 0x1f) == 10) && ((pcVar6->storage & 7) == 7)) {
          if ((pcVar6->type->code & 0x200) == 0) {
            diag_error(0x28d,0x53,pcVar6);
            return '\0';
          }
          pcVar6 = (pcVar6->type->extra).cls;
        }
        bVar3 = pcVar6->kind & 0x1f;
        cls = pcVar6;
        if ((bVar3 != 4) && (bVar3 != 0x19)) {
          if (bVar3 == 0xf) {
            if ((pcVar6->key_ref & 0x20000) != 0) {
              return '\x01';
            }
            cls = g_scope_vector->entries[(short)pcVar6->key_ref];
          }
          else {
            cls = pcVar9;
            if (bVar3 == 0x16) {
              return '\x01';
            }
          }
        }
        if ((cls->kind & 0x1f) == 0x19) {
          return '\x01';
        }
        bVar3 = (byte)uVar1;
        if (naming_class == (c1_symbol *)0x0) {
          naming_class = cls;
          access_record_inaccessible_member(bVar3,pcVar11,cls);
        }
        if (((cVar8 != '\0') && (cell != (c1_keyed_cell *)0x0)) && (cell == cell->next)) {
          if (cls == naming_class) {
            return '\x01';
          }
          return 1 < bVar3;
        }
        if (cls == pcVar10) {
          sym = (c1_symbol *)0x1;
        }
        if (((((cls->detail).cls)->layout_flags3b & 0x40) != 0) &&
           ((((friend_result = 0, pcVar10 != (c1_symbol *)0x0 &&
              (friend_result = access_is_friend(pcVar10,cls), friend_result != 0)) ||
             ((context_class != (c1_symbol *)0x0 &&
              (friend_result = access_is_friend(context_class,cls), friend_result != 0)))) ||
            ((g_current_function != (c1_symbol *)0x0 &&
             (friend_result = access_is_friend(g_current_function,cls), friend_result != 0)))))) {
          if (cls == naming_class) {
            naming_class_friend = 1;
          }
          sym = (c1_symbol *)0x1;
        }
        if (pcVar6 == context_class) {
          sym = (c1_symbol *)0x1;
        }
        if (cell->key == (c1_keyed_cell *)0x0) {
          if (naming_class_friend != 0) {
            if (restricted_step == 0) {
              return '\x01';
            }
            if ((local_1c + -1 <= restricted_step) && (restricted_friend == 1)) {
              return '\x01';
            }
          }
          if (cVar7 != '\0') {
            return '\x01' - ((byte)prev_access < 2);
          }
          return '\x01' - (bVar3 < (byte)sym);
        }
        if ((pcVar6->kind & 0x1f) == 0xf) {
          cVar7 = cls == context_class;
          if ((pcVar6->key_ref & 0x10000) == 0) {
            base_access._0_1_ = pcVar6->flags2 & 3;
          }
          else {
            cell = (c1_keyed_cell *)base_path_skip_base_entries((int *)cell);
            base_access._0_1_ =
                 class_base_access((int)g_scope_vector->entries[(short)pcVar6->key_ref],
                                   cell->key->sym);
            g_access_report_via_virtual_base = 1;
          }
LAB_1041854f:
          if ((((byte)base_access == 1) || ((byte)base_access == 2)) && (restricted_step == 0)) {
            restricted_step = local_1c;
            restricted_friend = friend_result;
          }
        }
        else {
          cVar7 = '\0';
          base_access._0_1_ = pcVar6->flags2 & 3;
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
          access_record_inaccessible_via_base(pcVar11,pcVar6,bVar4,bVar3,prev_qualifier);
        }
        local_1c = local_1c + 1;
        pcVar9 = cls;
        prev_qualifier = pcVar6;
        prev_access = uVar1;
      }
    }
  }
  return '\x01';
}

