void __cdecl init_process_initializer(c1_node *value,int no_dynamic)

{
  byte bVar1;
  c1_symbol *pcVar2;
  ushort uVar3;
  c1_node *pcVar4;
  c1_node *value_00;
  int iVar5;
  c1_type *pcVar6;
  uint level_word;
  c1_type *type;
  uint uVar7;
  c1_conversion *conv;
  uint level_word_2;
  longlong lVar8;
  c1_type local_10;
  
  if (((value == (c1_node *)0x0) || (g_init_brace_depth < 0)) || ((g_init_level->flags & 0x20) != 0)
     ) {
    return;
  }
  pcVar4 = fold_static_const_member(value);
  value_00 = tree_strip_casts_and_segment_bases(pcVar4);
  value = value_00;
  iVar5 = init_aggregate_members(value_00);
  conv = (c1_conversion *)g_arenas[5].cur;
  if (iVar5 == 0) {
    if (g_init_too_many_reported != 0) {
      return;
    }
    g_init_too_many_reported = 1;
    diag_error(0x4e);
    return;
  }
  if (((g_init_level->flags & 0x10) == 0) || (g_ms_extensions == '\0')) {
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv == (c1_conversion *)0x0) goto LAB_10475950;
    bVar1 = g_init_level->sym->kind;
    level_word_2 = (uint)g_init_level->sym->type;
    conv->op = 't';
    *(c1_u8 *)((int)conv + 1) = '\x02';
    *(c1_node **)((int)conv + 4) = pcVar4;
    *(byte *)((int)conv + 2) = ((bVar1 & 0x1f) != 2) - 1U & 0x10 | 4;
    if (pcVar4 != (c1_node *)0x0) {
      *(c1_type **)((int)conv + 8) = pcVar4->type;
      *(uint *)((int)conv + 0xc) = level_word_2;
      conv_compute_conversion(conv);
      goto LAB_104487df;
    }
  }
  else {
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv == (c1_conversion *)0x0) {
LAB_10475950:
      conv = (c1_conversion *)0x0;
      goto LAB_104487df;
    }
    level_word_2 = (uint)g_init_level->sym->type;
    conv->op = 't';
    *(c1_u8 *)((int)conv + 1) = '\x01';
    *(c1_u8 *)((int)conv + 2) = '\x02';
    *(c1_node **)((int)conv + 4) = pcVar4;
    if (pcVar4 != (c1_node *)0x0) {
      *(c1_type **)((int)conv + 8) = pcVar4->type;
      *(uint *)((int)conv + 0xc) = level_word_2;
      conv_compute_conversion(conv);
      goto LAB_104487df;
    }
  }
  local_10.code = 0x80f;
  local_10.flags = 0;
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = (c1_type *)0x0;
  pcVar6 = type_intern(&local_10);
  *(c1_type **)((int)conv + 8) = pcVar6;
  *(uint *)((int)conv + 0xc) = level_word_2;
  conv_compute_conversion(conv);
LAB_104487df:
  value = pcVar4;
  if ((((g_compile_flags_c4 & 0x100000) == 0) &&
      (iVar5 = init_aggregate_element(g_init_level->sym,(int *)&value,(int)conv), iVar5 == 0)) &&
     ((char)no_dynamic == '\0')) {
    if ((g_init_symbol->flags22 & 2) != 0) {
      diag_error(0x1e2);
      return;
    }
    init_begin_dynamic_initializer(g_init_symbol);
    g_init_dynamic_offset = g_init_offset;
    g_init_turned_dynamic = 1;
  }
  iVar5 = init_is_char_array_string_init(g_init_level->sym,value_00);
  if (((iVar5 == 0) && ((g_init_level->flags & 0x50) != 0x50)) && ((conv->flags4e & 1) == 0)) {
    conv_report_cannot_convert(conv,'\x01');
    return;
  }
  pcVar2 = g_init_level->sym;
  if ((pcVar2->kind & 0x1f) == 2) {
    value = conv_apply_conversion(conv,(c1_node *)0x0);
    if (g_init_bitfield_unit_open == 0) {
      g_init_bitfield_unit_open = 1;
      g_init_bitfield_value = 0;
      g_init_bitfield_value_high = 0;
      g_init_bitfield_unit_offset = (g_init_level->sym->detail).value;
    }
    uVar3 = value->type->code;
    if ((uVar3 & 0x130) == 0) {
      diag_error(0x4d,g_init_level->sym);
      init_advance_member();
      return;
    }
    if ((value->kind & 7) == 3) {
      if (((byte)uVar3 >> 5 & 1) != 0) {
        iVar5 = fold_float_to_int32_checked(value->left,&no_dynamic);
        if (iVar5 != 0) {
          diag_warning(2,0x38);
        }
        value->left = (void *)no_dynamic;
        value->right = (void *)(no_dynamic >> 0x1f);
      }
      pcVar4 = value;
      pcVar2 = g_init_level->sym;
      lVar8 = _allshl((pcVar2->x28).bytes.depth,1,0);
      lVar8 = _allshl((pcVar2->x28).bytes.bit_position,(int)lVar8 - 1U & (uint)pcVar4->left,
                      (int)((ulonglong)lVar8 >> 0x20) - (uint)((int)lVar8 == 0) &
                      (uint)pcVar4->right);
      g_init_bitfield_value = g_init_bitfield_value | (uint)lVar8;
      g_init_bitfield_value_high = g_init_bitfield_value_high | (uint)((ulonglong)lVar8 >> 0x20);
      init_advance_member();
      return;
    }
    if (((g_compile_flags_c4 & 0x100000) != 0) &&
       ((g_init_turned_dynamic != 0 || (g_ms_extensions != '\0')))) {
      func_static_guard_variable(pcVar4);
      init_advance_member();
      return;
    }
  }
  else {
    if ((g_init_level->flags & 0x10) != 0) {
      if ((g_init_level->flags & 0x40) == 0) {
        level_word = (uint)pcVar2->type;
        if ((-1 < (char)((c1_type *)level_word)->code) || ((c1_type *)level_word == (c1_type *)0x0))
        {
          if ((((c1_type *)level_word)->flags & 0x60) != 0) {
            uVar7._0_2_ = ((c1_type *)level_word)->code;
            uVar7._2_2_ = ((c1_type *)level_word)->flags;
            local_10.base = ((c1_type *)level_word)->base;
            local_10.extra = ((c1_type *)level_word)->extra;
            local_10._0_4_ = uVar7 & 0xff9fffff;
            local_10.debug_index = ((c1_type *)level_word)->debug_index;
            level_word = (uint)type_intern(&local_10);
          }
          g_init_level->sym->type = (c1_type *)level_word;
        }
        local_10.debug_index = 0;
        pcVar6 = g_init_level->sym->type;
        local_10.code = 0x82;
        uVar3 = decl_apply_default_calling_convention(0x82,0);
        local_10.flags = uVar3;
        local_10.extra.cls = (c1_symbol *)0x0;
        local_10.base = pcVar6;
        type = type_intern(&local_10);
        pcVar2 = g_init_level->sym;
        conv->target_kind = 0;
        conv->target_symbol = pcVar2;
        pcVar4 = init_element_lvalue(type);
        pcVar4 = conv_apply_conversion(conv,pcVar4);
        pcVar4 = expr_full_expression_guarded(pcVar4,2);
        stmt_emit_expression(pcVar4);
        iVar5 = type_size(pcVar6);
        g_init_offset = g_init_offset + iVar5;
      }
      g_init_level->flags = g_init_level->flags | 2;
      init_advance_member();
      return;
    }
    if (iVar5 != 0) {
      uVar3 = init_check_array_bounds(pcVar2,value_00);
      *(ushort *)&value->right = uVar3;
    }
    if ((g_compile_flags_c4 & 0x100000) == 0) {
      if (iVar5 == 0) {
        pcVar4 = conv_apply_conversion(conv,(c1_node *)0x0);
        value_00 = tree_strip_casts_and_segment_bases(pcVar4);
      }
      value_00 = init_record_constant_value(g_init_level->sym,value_00);
      init_emit_initializer(g_init_level->sym,value_00,&g_il_in);
    }
    else {
      pcVar4 = init_record_constant_value(g_init_level->sym,pcVar4);
      init_emit_element_store(g_init_level->sym,pcVar4,&conv->op);
    }
    if (iVar5 == 0) {
      if ((g_compile_flags_c4 & 0x100000) == 0) {
        iVar5 = type_size(g_init_level->sym->type);
        g_init_offset = g_init_offset + iVar5;
      }
    }
    else {
      if (g_init_level->count != 0) {
        if ((g_init_level->string_seen == '\0') && (g_ms_extensions != '\0')) {
          diag_warning(4,0xcf);
        }
        else if (g_init_too_many_reported == 0) {
          g_init_too_many_reported = 1;
          diag_error(0x4e);
        }
      }
      uVar7 = 2;
      if (((uint)value_00->right & 0x10000) == 0) {
        uVar7 = 1;
      }
      g_init_level->count = g_init_level->count + *(ushort *)&value_00->right / uVar7;
      g_init_level->string_seen = '\x01';
      pcVar6 = g_init_level->sym->type;
      uVar7 = *(uint *)(((uint)pcVar6 & -(uint)((pcVar6->code & 0x80) != 0)) + 8);
      if (uVar7 != 0) {
        if ((uint)g_init_level->count < uVar7) {
          iVar5 = 2;
          if (((uint)value_00->right & 0x10000) == 0) {
            iVar5 = 1;
          }
          g_constant_value = (uVar7 - g_init_level->count) * iVar5;
          g_constant_value_high = g_constant_value >> 0x1f;
          init_emit_data((c1_symbol *)0x0);
          g_init_level->count = uVar7;
        }
        else {
          g_init_level->flags = g_init_level->flags | 2;
          if ((uVar7 < (uint)g_init_level->count) && (g_init_too_many_reported == 0)) {
            g_init_too_many_reported = 1;
            diag_error(0x4e);
          }
        }
      }
      if ((g_compile_flags_c4 & 0x100000) == 0) {
        g_init_offset = g_init_offset + (uint)*(ushort *)&value_00->right;
        init_advance_member();
        return;
      }
    }
  }
  init_advance_member();
  return;
}

