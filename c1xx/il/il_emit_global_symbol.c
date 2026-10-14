void __cdecl il_emit_global_symbol(int *symref)

{
  c1_symbol *sym;
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  c1_symbol *sym_00;
  uint uVar6;
  void *pvVar7;
  c1_symbol *value;
  c1_node *pcVar8;
  byte bVar9;
  char cVar10;
  c1_member_iter local_40;
  uint member_iter [2];
  c1_u8 *local_20;
  uint overload_iter [2];
  c1_sym_link *local_8;
  int mode;
  
  if (0 < g_error_count) {
    return;
  }
  if ((*(byte *)((int)symref + -6) & 8) != 0) {
    return;
  }
  sym = (c1_symbol *)(symref + -2);
  iVar5 = sym_kind_is_alias_or_using(sym);
  if ((char)iVar5 != '\0') {
    return;
  }
  if ((sym->kind & 0x1f) == 0xe) {
    il_emit_symbol(9,sym);
    *(byte *)((int)symref + -6) = *(byte *)((int)symref + -6) | 8;
    return;
  }
  mode = 0;
  if (((g_pch_precomp_types == 0) || (g_il_block_level != '\0')) ||
     ((iVar5 = sym_kind_is_declared_entity(sym), (char)iVar5 != '\0' &&
      ((*(byte *)(symref + -1) & 8) != 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  cVar4 = (char)mode;
  bVar9 = *(byte *)((int)symref + -5) & 2;
  if ((((bVar9 == 0) || (g_opt_pch_types_in_pdb != '\0')) || (g_use_pch == '\0')) ||
     (bVar2 = true, g_pch_create != '\0')) {
    bVar2 = false;
  }
  bVar3 = sym->kind & 0x1f;
  if (bVar3 == 0x19) {
    if (bVar1) {
      *(byte *)((int)symref + -5) = *(byte *)((int)symref + -5) | 2;
      return;
    }
    if ((g_opt_Zi == '\0') || (bVar2)) goto LAB_10427e5c;
    iVar5 = 0xb;
  }
  else if (bVar3 == 4) {
    if (((g_opt_Zi != '\0') && ((*(byte *)((int)symref + -5) & 1) == 0)) &&
       ((iVar5 = class_debug_type_in_pdb(sym), (char)iVar5 == '\0' &&
        (*(int *)(symref[7] + 0x34) == 0)))) {
      iVar5 = debug_emit_class_type(sym);
      *(int *)(symref[3] + 0xc) = iVar5;
    }
    cVar4 = (char)mode;
    if ((bVar1) && ((*(byte *)((int)symref + -6) & 4) != 0)) {
      *(byte *)((int)symref + -5) = *(byte *)((int)symref + -5) | 2;
      return;
    }
    if ((*(ushort *)symref[3] & 0x200) != 0) {
      if ((g_compile_flags_c4 & 0x20000) == 0) {
        class_member_iter_init((c1_member_iter *)member_iter,symref,2);
        ovl_set_iter_init((c1xx_ovl_set_iter *)overload_iter,(void *)0x0);
        while( true ) {
          while (cVar4 = sym_overload_iter_next((c1xx_ovl_set_iter *)overload_iter), cVar4 != '\0')
          {
            il_emit_global_symbol((int *)local_8);
          }
          cVar4 = class_member_iter_next((c1_member_iter *)member_iter);
          if (cVar4 == '\0') break;
          sym_overload_iter_init((c1xx_ovl_set_iter *)overload_iter,local_20);
        }
      }
      class_member_iter_init(&local_40,symref,3);
      while( true ) {
        cVar4 = (char)mode;
        local_40.current = local_40.next;
        if (local_40.next == (int *)0x0) break;
        iVar5 = class_member_iter_step(&local_40.cursor);
        local_40.next = (void *)(-(uint)((char)iVar5 != '\0') & (uint)local_40.cursor.current);
        uVar6 = class_member_iter_matches(&local_40);
        if ((char)uVar6 != '\0') {
          il_emit_global_symbol(local_40.current);
        }
      }
    }
    if ((((g_opt_Zi == '\0') || ((*(byte *)((int)symref + -6) & 4) == 0)) ||
        ((*(byte *)((int)symref + -5) & 1) != 0)) ||
       ((bVar2 || ((g_debug_types_in_pdb != '\0' && ((*(byte *)(symref[7] + 0x3f) & 8) != 0))))))
    goto LAB_10427e5c;
    iVar5 = 0xb;
  }
  else if (bVar3 == 5) {
    if (g_opt_Zi == '\0') goto LAB_10427e5c;
    free_list_push_124c(sym);
    debug_type_emit_if_needed((c1_type *)symref[3]);
    free_list_pop_124c();
    if (bVar1) {
      *(byte *)((int)symref + -5) = *(byte *)((int)symref + -5) | 2;
      return;
    }
    if (bVar2) goto LAB_10427e5c;
    iVar5 = 8;
  }
  else {
    if (bVar1) {
      il_emit_symbol_if_needed(symref);
      if ((sym->kind & 0x1f) != 10) {
        return;
      }
      if ((*(byte *)(symref + 6) & 7) != 7) {
        return;
      }
      *(byte *)((int)symref + -5) = *(byte *)((int)symref + -5) | 2;
      return;
    }
    if ((((sym->kind & 0x1f) == 10) && ((*(byte *)(symref + 6) & 7) == 7)) && (bVar9 != 0)) {
      if (!bVar2) {
        il_emit_symbol(0xb,sym);
        *(byte *)((int)symref + -6) = *(byte *)((int)symref + -6) | 8;
        return;
      }
      goto LAB_10427e5c;
    }
    if (((*(byte *)(symref + -1) & 0x40) == 0) || ((sym->kind & 0x1f) != 10)) {
      if ((bVar3 == 10) && ((*(byte *)((int)symref + -3) & 0x10) != 0)) {
        il_emit_global_symbol_debug_fragment(sym,symref,cVar4);
        return;
      }
      if ((*(byte *)(symref + 6) & 7) != 1) {
        iVar5 = sym_is_data_or_function_2(sym);
        if ((char)iVar5 != '\0') {
          il_emit_global_symbol_tail('\0',sym,symref);
          return;
        }
        if ((*(byte *)(symref + 6) & 7) == 3) {
          uVar6 = type_calling_convention_bits((ushort *)symref[3]);
          if ((uVar6 >> 5 & 1) != 0) {
            il_emit_global_symbol_tail((byte)(uVar6 >> 5) & 7,sym,symref);
            return;
          }
        }
        if (((sym->kind & 0x1f) == 10) && ((*(byte *)(symref + 6) & 7) == 7)) {
          il_emit_global_symbol_tail('\0',sym,symref);
          return;
        }
        il_emit_global_symbol_tail('\x01',sym,symref);
        return;
      }
      cVar10 = '\0';
      cVar4 = '\0';
      if ((*(byte *)(symref + 4) & 3) == 0) {
        return;
      }
      bVar9 = sym->kind & 0x1f;
      if (((bVar9 == 7) || (bVar9 == 8)) || (bVar9 == 6)) {
        bVar9 = sym->kind & 0x1f;
        if (((bVar9 == 7) || (bVar9 == 8)) && ((*(byte *)((int)symref + 0x2d) & 2) != 0)) {
          cVar4 = '\0';
          pvVar7 = class_scalar_deleting_dtor_of(sym);
          if ((*(byte *)((int)pvVar7 + 2) & 8) == 0) {
            il_emit_global_symbol((int *)((int)pvVar7 + 8));
          }
          iVar5 = 0x10;
        }
        else {
          iVar5 = 4;
        }
      }
      else {
        bVar9 = sym->kind & 0x1f;
        cVar4 = '\0';
        if (((bVar9 == 0xb) || (bVar9 == 0xc)) && ((*(byte *)((int)symref + -3) & 4) != 0)) {
          pcVar8 = tree_new_symbol_ref(sym,'\0');
          symref[3] = (int)pcVar8->type;
          cVar4 = cVar10;
        }
        iVar5 = 1;
      }
      if (g_opt_Zi != '\0') {
        il_emit_symbol_if_needed(symref);
      }
    }
    else {
      sym_00 = sym_inline_instance_of(sym);
      sym_00->flags4 = (*(byte *)(symref + -1) ^ sym_00->flags4) & 4 ^ sym_00->flags4;
      sym_00->flags5 =
           (*(byte *)((int)symref + -3) ^ sym_00->flags5) & 0x7f ^ *(byte *)((int)symref + -3);
      (sym_00->tail).data.value_lo = symref[9];
      if ((*(byte *)((int)symref + 0x1b) & 1) != 0) {
        value = sym_segment_record(sym);
        if (value == (c1_symbol *)0x0) {
          sym_00->flags23 = sym_00->flags23 & 0xfe;
        }
        else {
          sym_set_segment(sym_00,value);
        }
      }
      sym_00->type = (c1_type *)symref[3];
      if (g_opt_Zi == '\0') {
        return;
      }
      sym_mark_referenced(sym_00);
      free_list_push_124c(sym);
      debug_type_emit_if_needed((c1_type *)symref[3]);
      free_list_pop_124c();
      if ((*(byte *)((int)symref + -5) & 1) != 0) {
        return;
      }
      iVar5 = 7;
    }
  }
  il_emit_symbol_with_mode(iVar5,(int)symref,cVar4);
LAB_10427e5c:
  *(byte *)((int)symref + -6) = *(byte *)((int)symref + -6) | 8;
  return;
}

