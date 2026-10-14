void __cdecl init_process_initializer(c1_node *element)

{
  c1_type *pcVar1;
  c1_symbol *pcVar2;
  void *pvVar3;
  c1_node *pcVar4;
  ushort uVar5;
  c1_node *node;
  int iVar6;
  c1_type *pcVar7;
  uint uVar8;
  longlong lVar9;
  void *local_4;
  
  pcVar4 = element;
  if (((element != (c1_node *)0x0) && (-1 < g_init_brace_depth)) &&
     ((g_init_level->flags & 0x20) == 0)) {
    node = tree_strip_casts_and_segment_bases(element);
    element = node;
    if ((((&g_token_class)[node->op] == -0x7d) && (pvVar3 = node->left, pvVar3 != (void *)0x0)) &&
       ((*(byte *)((int)pvVar3 + 1) & 7) == 3)) {
      element = tree_new_int_constant
                          (*(int *)((int)pvVar3 + 0x10) + *(int *)((int)node->right + 0x10));
    }
    iVar6 = init_descend_to_scalar(element);
    if (iVar6 != 0) {
      if ((g_compile_flags_c4 & 0x100000) == 0) {
        iVar6 = init_is_constant_initializer(g_init_level->cursor,&element);
        if (iVar6 == 0) {
          diag_error(99);
          return;
        }
        init_check_dllimport_address(g_init_level->cursor,element);
      }
      else {
        init_check_automatic_address(g_init_level->cursor,element);
      }
      iVar6 = init_is_char_array_string_init(g_init_level->cursor,node);
      if ((g_init_level->cursor->kind & 0x1f) == 2) {
        if (g_init_bitfield_unit_open == 0) {
          g_init_bitfield_unit_open = 1;
          g_init_bitfield_value = 0;
          g_init_bitfield_value_high = 0;
          g_init_bitfield_unit = (int)g_init_level->cursor->detail;
        }
        uVar5 = element->type->code;
        if ((uVar5 & 0x130) == 0) {
          diag_error(0x4d,g_init_level->cursor);
          init_advance_member();
          return;
        }
        if ((element->kind & 7) == 3) {
          if (((byte)uVar5 >> 5 & 1) != 0) {
            iVar6 = fold_float_to_int32_checked(element->left,(int *)&local_4);
            if (iVar6 != 0) {
              diag_warning(2,0x38);
            }
            element->left = local_4;
            element->right = (void *)((int)local_4 >> 0x1f);
          }
          pcVar4 = element;
          pcVar2 = g_init_level->cursor;
          lVar9 = _allshl((pcVar2->x28).bytes.depth,1,0);
          lVar9 = _allshl((pcVar2->x28).bytes.bit_position,(int)lVar9 - 1U & (uint)pcVar4->left,
                          (int)((ulonglong)lVar9 >> 0x20) - (uint)((int)lVar9 == 0) &
                          (uint)pcVar4->right);
          g_init_bitfield_value = g_init_bitfield_value | (uint)lVar9;
          g_init_bitfield_value_high = g_init_bitfield_value_high | (uint)((ulonglong)lVar9 >> 0x20)
          ;
          init_advance_member();
          return;
        }
        if (((g_compile_flags_c4 & 0x100000) != 0) &&
           ((g_init_runtime_bitfield_allowed != 0 || (g_ms_extensions != '\0')))) {
          func_static_guard_variable(pcVar4);
          init_advance_member();
          return;
        }
      }
      else {
        if (iVar6 != 0) {
          uVar5 = expr_warn_array_bounds_overflow(g_init_level->cursor,node);
          *(ushort *)&element->right = uVar5;
        }
        if ((g_compile_flags_c4 & 0x100000) == 0) {
          init_emit_initializer(g_init_level->cursor,node,&g_il_in);
        }
        else {
          init_emit_runtime_element(g_init_level->cursor,pcVar4);
        }
        if (iVar6 == 0) {
          if ((g_compile_flags_c4 & 0x100000) == 0) {
            pcVar1 = g_init_level->cursor->type;
            if ((pcVar4->type->code & 0x8f) == 0x83) {
              pcVar7 = conv_array_to_pointer_type(pcVar4);
              pcVar4->type = pcVar7;
            }
            conv_check_conversion_to_type('t',pcVar1,pcVar4);
            iVar6 = type_size(pcVar1);
            g_init_offset = g_init_offset + iVar6;
          }
        }
        else {
          if (g_init_level->count != 0) {
            if ((g_init_level->from_string == '\0') && (g_ms_extensions != '\0')) {
              diag_warning(4,0xcf);
            }
            else if (g_init_too_many_reported == 0) {
              g_init_too_many_reported = 1;
              diag_error(0x4e);
            }
          }
          uVar8 = 2;
          if (((uint)node->right & 0x10000) == 0) {
            uVar8 = 1;
          }
          g_init_level->count = g_init_level->count + *(ushort *)&node->right / uVar8;
          g_init_level->from_string = '\x01';
          pcVar1 = g_init_level->cursor->type;
          uVar8 = *(uint *)(((uint)pcVar1 & -(uint)((pcVar1->code & 0x80) != 0)) + 8);
          if (uVar8 != 0) {
            if (g_init_level->count < uVar8) {
              iVar6 = 2;
              if (((uint)node->right & 0x10000) == 0) {
                iVar6 = 1;
              }
              g_constant_value = (uVar8 - g_init_level->count) * iVar6;
              g_constant_value_high = g_constant_value >> 0x1f;
              init_emit_data(0);
              g_init_level->count = uVar8;
            }
            else {
              g_init_level->flags = g_init_level->flags | 2;
              if ((uVar8 < g_init_level->count) && (g_init_too_many_reported == 0)) {
                g_init_too_many_reported = 1;
                diag_error(0x4e);
              }
            }
          }
          if ((g_compile_flags_c4 & 0x100000) == 0) {
            g_init_offset = g_init_offset + (uint)*(ushort *)&node->right;
            init_advance_member();
            return;
          }
        }
      }
      init_advance_member();
      return;
    }
    if (g_init_too_many_reported == 0) {
      g_init_too_many_reported = 1;
      diag_error(0x4e);
    }
  }
  return;
}

