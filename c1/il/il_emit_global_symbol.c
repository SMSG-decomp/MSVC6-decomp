void __cdecl il_emit_global_symbol(int *sym_link)

{
  byte *pbVar1;
  c1_symbol *pcVar2;
  bool bVar3;
  bool mode;
  int *symref;
  byte bVar4;
  c1_u32 cVar5;
  void *value;
  c1_symbol *pcVar6;
  int iVar7;
  c1_type *pcVar8;
  byte bVar9;
  int n;
  
  symref = sym_link;
  if (0 < g_error_count) {
    return;
  }
  if ((*(byte *)((int)sym_link + -7) & 2) != 0) {
    return;
  }
  pcVar2 = (c1_symbol *)(sym_link + -2);
  if ((*(byte *)(sym_link + -2) & 0x1f) == 0xe) {
    il_emit_symbol(9,pcVar2);
    *(byte *)((int)sym_link + -7) = *(byte *)((int)sym_link + -7) | 2;
    return;
  }
  mode = false;
  if (((g_pch_precomp_types == '\0') || (g_il_block_level != '\0')) ||
     ((iVar7 = sym_kind_is_declared_entity(pcVar2), (char)iVar7 != '\0' &&
      ((*(byte *)((int)sym_link + -5) & 8) != 0)))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  pbVar1 = (byte *)((int)sym_link + -7);
  bVar9 = *pbVar1 & 0x80;
  if ((((bVar9 == 0) || (g_opt_pch_types_in_pdb != '\0')) || (g_use_pch == '\0')) ||
     (sym_link._0_1_ = '\x01', g_pch_create != '\0')) {
    sym_link._0_1_ = '\0';
  }
  bVar4 = pcVar2->kind & 0x1f;
  if (bVar4 == 4) {
    if ((g_opt_Zi != '\0') && ((*pbVar1 & 0x40) == 0)) {
      cVar5 = debug_type_record_struct_complete(pcVar2);
      *(c1_u32 *)(symref[3] + 0xc) = cVar5;
    }
    if ((bVar3) && ((*(byte *)((int)symref + -7) & 1) != 0)) {
      *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 0x80;
      return;
    }
    if ((fe_name *)*symref == (fe_name *)0x0) {
      return;
    }
    if ((fe_name *)*symref == g_name_unnamed) {
      return;
    }
    if ((((g_opt_Zi == '\0') || ((*(byte *)((int)symref + -7) & 1) == 0)) ||
        ((*(byte *)((int)symref + -7) & 0x40) != 0)) || ((char)sym_link != '\0')) goto LAB_106185e7;
    iVar7 = 0xb;
  }
  else if (bVar4 == 5) {
    if (g_opt_Zi == '\0') goto LAB_106185e7;
    free_list_push_124c(pcVar2);
    debug_type_emit_if_needed((c1_type *)symref[3]);
    free_list_pop_124c();
    if (bVar3) {
      *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 0x80;
      return;
    }
    if ((char)sym_link != '\0') goto LAB_106185e7;
    iVar7 = 8;
  }
  else {
    if (bVar3) {
      il_emit_global_symbol_debug_types(symref);
      if ((pcVar2->kind & 0x1f) != 10) {
        return;
      }
      if ((*(byte *)(symref + 6) & 7) != 7) {
        return;
      }
      *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 0x80;
      return;
    }
    if ((((pcVar2->kind & 0x1f) == 10) && ((*(byte *)(symref + 6) & 7) == 7)) && (bVar9 != 0)) {
      il_emit_global_symbol_fragment(pcVar2,(char)sym_link);
      return;
    }
    if (((*(byte *)((int)symref + -5) & 0x40) == 0) || ((pcVar2->kind & 0x1f) != 10)) {
      if ((*(byte *)(symref + 6) & 7) == 1) {
        mode = false;
      }
      else {
        iVar7 = sym_is_data_or_function_2(pcVar2);
        if ((char)iVar7 == '\0') {
          if (((pcVar2->kind & 0x1f) == 10) && ((*(byte *)(symref + 6) & 7) == 7)) {
            mode = false;
          }
          else {
            mode = true;
          }
        }
        else {
          mode = false;
        }
      }
      if ((*(byte *)(symref + 4) & 3) == 0) {
        if (!mode) {
          return;
        }
        pcVar6 = sym_from_list_link((int)symref);
        iVar7 = sym_decl_position(pcVar6);
        diag_begin_global(iVar7);
        bVar9 = pcVar2->kind & 0x1f;
        if (bVar9 != 0xc) {
          if (bVar9 == 0xb) {
            n = 100;
            iVar7 = 4;
          }
          else {
            if (g_il_block_level == '\0') goto LAB_106185b5;
            if ((*(byte *)((int)symref + -5) & 4) == 0) {
              n = 0x65;
              iVar7 = 3;
            }
            else {
              n = 0xbd;
              iVar7 = 4;
            }
          }
          diag_warning(iVar7,n,pcVar2);
        }
LAB_106185b5:
        diag_end_global();
      }
      bVar9 = pcVar2->kind & 0x1f;
      if (((bVar9 == 7) || (bVar9 == 8)) || (bVar9 == 6)) {
        iVar7 = 4;
      }
      else {
        iVar7 = 1;
      }
      if (g_opt_Zi != '\0') {
        il_emit_global_symbol_debug_types(symref);
      }
    }
    else {
      pcVar6 = decl_lookup_file_scope_twin(pcVar2);
      pcVar6->flags3 = (*(byte *)((int)symref + -5) ^ pcVar6->flags3) & 4 ^ pcVar6->flags3;
      pcVar6->flags4 = (*(byte *)(symref + -1) ^ pcVar6->flags4) & 0x7f ^ *(byte *)(symref + -1);
      pcVar6->detail = (void *)symref[7];
      if ((*(byte *)((int)symref + 0x1b) & 1) != 0) {
        value = sym_segment_record(pcVar2);
        if (value == (void *)0x0) {
          pcVar6->flags23 = pcVar6->flags23 & 0xfe;
        }
        else {
          sym_set_segment(pcVar6,value);
        }
      }
      pcVar6->type = (c1_type *)symref[3];
      if (g_opt_Zi == '\0') {
        return;
      }
      sym_mark_referenced(pcVar6);
      free_list_push_124c(pcVar2);
      pcVar8 = (c1_type *)symref[3];
      if (g_opt_Zg == '\0') {
        debug_type_index(pcVar8);
        pcVar8 = type_innermost_base(pcVar8);
        iVar7 = type_is_class_or_enum(pcVar8);
        if ((((char)iVar7 != '\0') && (pcVar2 = (pcVar8->extra).sym, pcVar2 != (c1_symbol *)0x0)) &&
           (((pcVar2->kind & 0x1f) == 4 && ((pcVar2->x2c).references == (c1_symbol_cell *)0x0)))) {
          debug_type_record_struct_complete(pcVar2);
        }
      }
      free_list_pop_124c();
      if ((*(byte *)((int)symref + -7) & 0x40) != 0) {
        return;
      }
      iVar7 = 7;
    }
  }
  il_emit_symbol_with_mode(iVar7,(int)symref,mode);
LAB_106185e7:
  *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 2;
  return;
}

