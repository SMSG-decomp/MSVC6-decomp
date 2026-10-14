void __cdecl init_emit_initializer(c1_symbol *sym,c1_node *node,c1_il_buffer *buf)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_il_buffer *buf_00;
  byte bVar6;
  int iVar7;
  uint uVar8;
  c1_type *pcVar9;
  c1_node *node_00;
  c1_symbol *pcVar10;
  char *fmt;
  byte bVar11;
  c1_u8 *pcVar12;
  void *value;
  longlong lVar13;
  int local_44;
  int iStack_40;
  void *value_00;
  c1_symbol *addr_sym;
  c1_symbol *pcVar14;
  int is_string;
  float float_value;
  uint type_code;
  longlong int_value;
  uint const_lo;
  int const_hi;
  uint dbl_lo;
  uint dbl_hi;
  uint value0;
  uint value1;
  c1_u16 value2 [2];
  uint *value_words_2;
  uint *value_words_3;
  uint *value_words_4;
  uint *value_words;
  
  buf_00 = buf;
  is_string = 0;
  value_00 = (void *)0x0;
  addr_sym = (c1_symbol *)0x0;
  if ((node != (c1_node *)0x0) && ((g_compile_flags_cc & 0x800) == 0)) {
    if ((g_init_pending_data_symbol != (c1_symbol *)0x0) && (buf == &g_il_in)) {
      init_emit_symbol_data(g_init_pending_data_symbol,(c1_node *)0x0,&g_il_in);
      g_compile_flags_c4 = g_compile_flags_c4 | 0x40000;
      g_init_pending_data_symbol = (c1_symbol *)0x0;
    }
    if (sym == (c1_symbol *)0x0) {
      local_44 = 8;
    }
    else {
      bVar6 = node->kind & 7;
      if (bVar6 == 5) {
        is_string = 1;
        iVar7 = init_is_char_array_string_init(sym,node);
        if (iVar7 == 0) {
          node = expr_string_literal(node);
          iVar7 = init_split_address_constant
                            (node,(void **)&stack0xffffffc8,(int *)&stack0xffffffc4);
          if (iVar7 != 0) {
            local_44 = 2;
          }
        }
        else {
          local_44 = 3;
        }
      }
      else if (bVar6 == 3) {
        local_44 = 1;
      }
      else {
        iVar7 = init_split_address_constant(node,(void **)&stack0xffffffc8,(int *)&stack0xffffffc4);
        if (iVar7 != 0) {
          if (addr_sym == (c1_symbol *)0x0) {
            node_00 = tree_new_int_constant((int)value_00);
            init_emit_item_by_format
                      (1,buf,node_00,(int)value_00,addr_sym,is_string,float_value,type_code,const_lo
                       ,const_hi,dbl_lo,dbl_hi,value0,value1,(c1_x87_tail)value2,sym,node_00,
                       (char)buf);
            return;
          }
          local_44 = 2;
        }
      }
    }
    cVar5 = '\0';
    fmt = (&g_debug_record_formats)[local_44 * 2];
    while ((fmt != (char *)0x0 && (cVar1 = *fmt, cVar1 != '\0'))) {
      fmt = fmt + 1;
      switch(cVar1) {
      case 'f':
        value = value_00;
        goto LAB_1044075b;
      case 'i':
        iVar7 = il_buffer_reserve(&buf_00->bytes,2);
        bVar6 = buf_00->open & (byte)iVar7 & 1;
        buf_00->open = bVar6;
        if (bVar6 != 0) {
          *(buf_00->bytes).cur = '\0';
          (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
        }
        break;
      case 'l':
        uVar2 = *(ushort *)&node->right;
        value_words_2 = node->left;
        iVar7 = il_buffer_reserve(&buf_00->bytes,uVar2 + 4);
        bVar6 = buf_00->open & (byte)iVar7 & 1;
        buf_00->open = bVar6;
        if (bVar6 != 0) {
          il_buffer_put_compact_u16_unchecked(buf_00,uVar2);
          il_buffer_put_bytes(buf_00,value_words_2,(uint)uVar2);
        }
        break;
      case 'n':
        value = node->left;
LAB_1044075b:
        iVar7 = il_buffer_reserve(&buf_00->bytes,6);
        bVar6 = buf_00->open & (byte)iVar7 & 1;
        buf_00->open = bVar6;
        if ((bVar6 != 0) && (iVar7 = il_buffer_put_byte7(buf_00,(uint)value), (char)iVar7 == '\0'))
        {
          il_emit_in_item_fragment
                    ((uint)value,buf_00,node,(int)value_00,addr_sym,is_string,fmt,float_value,
                     type_code,const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,(c1_x87_tail)value2,sym
                     ,node,(char)buf);
          return;
        }
        break;
      case 'p':
        uVar2 = sym->type->code;
        if ((((char)(byte)uVar2 < '\0') && (((uVar2 & 0x8f) == 0x86 || ((uVar2 & 0x8f) == 0x82))))
           || ((uVar2 & 0x8f) == 0x8e)) {
          cVar5 = '\x03';
        }
        else if ((uVar2 & 0x8f) == 0x8a) {
          cVar5 = '\x01';
        }
        else if (((uVar2 & 0x2000) == 0) &&
                ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) ||
                 (g_opt_J_unsigned_char == '\0')))) {
          if ((uVar2 & 0x110) == 0) {
            if (((byte)uVar2 >> 5 & 1) == 0) {
              if ((uVar2 & 0x400) != 0) {
                cVar5 = '\x02';
              }
            }
            else {
              cVar5 = '\x05';
            }
          }
          else {
            cVar5 = '\x01';
          }
        }
        else {
          cVar5 = '\x02';
        }
        iVar7 = il_buffer_reserve(&buf_00->bytes,2);
        bVar6 = buf_00->open & (byte)iVar7 & 1;
        buf_00->open = bVar6;
        if (bVar6 != 0) {
          *(buf_00->bytes).cur = cVar5;
          (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
        }
        break;
      case 's':
        pcVar14 = addr_sym;
        if ((addr_sym->kind & 0x1f) == 8) {
          sym_mark_enclosing_scopes(addr_sym);
        }
        sym_mark_referenced(addr_sym);
        if ((addr_sym->flags4 & 0x40) == 0) {
          bVar6 = addr_sym->kind & 0x1f;
          if ((bVar6 == 7) || (bVar6 == 8)) {
            if ((*(byte *)((int)&addr_sym->tail + 10) & 0x80) != 0) {
              sym_redeclaration_group_add(&g_map_region_queue,addr_sym);
            }
            if ((*(byte *)((int)&addr_sym->tail + 9) & 2) != 0) {
              pcVar10 = class_scalar_deleting_dtor_of(addr_sym);
              goto LAB_1044084b;
            }
          }
        }
        else {
          bVar6 = addr_sym->kind & 0x1f;
          if (bVar6 == 3) {
            pcVar10 = sym_static_member_stand_in(addr_sym);
            addr_sym = pcVar10;
          }
          else if (bVar6 == 10) {
            pcVar10 = sym_inline_instance_of(addr_sym);
            addr_sym = pcVar10;
          }
          else {
            addr_sym = (c1_symbol *)0x0;
            pcVar10 = (c1_symbol *)0x0;
          }
LAB_1044084b:
          sym_mark_referenced(pcVar10);
        }
        if (((((addr_sym->flags23 & 1) != 0) &&
             (pcVar10 = sym_segment_record(addr_sym), (pcVar10->entity & 0xffffff) == 5)) &&
            (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
          g_function_has_body = 1;
          g_function_auto_inline = 0;
        }
        uVar8 = il_symbol_key(&addr_sym->kind);
        if (g_c9il_mode == '\0') {
          iVar7 = il_buffer_reserve(&buf_00->bytes,4);
          bVar6 = buf_00->open & (byte)iVar7 & 1;
          buf_00->open = bVar6;
          addr_sym = pcVar14;
          if (bVar6 != 0) {
            bVar6 = (byte)uVar8;
            if (uVar8 < 0x3fff80) {
              if (uVar8 < 0x4000) {
                *(buf_00->bytes).cur = bVar6 & 0x3f | 0x80;
                pcVar12 = (buf_00->bytes).cur + 1;
                (buf_00->bytes).cur = pcVar12;
                *pcVar12 = (c1_u8)(uVar8 >> 6);
                (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
              }
              else {
                *(buf_00->bytes).cur = bVar6 | 0xc0;
                pcVar12 = (buf_00->bytes).cur + 1;
                (buf_00->bytes).cur = pcVar12;
                *pcVar12 = (c1_u8)(uVar8 >> 6);
                pcVar12 = (buf_00->bytes).cur + 1;
                (buf_00->bytes).cur = pcVar12;
                *pcVar12 = (c1_u8)(uVar8 >> 0xe);
                (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
              }
            }
            else {
              *(buf_00->bytes).cur = bVar6 + 0x80;
              (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
            }
          }
        }
        else {
          il_buffer_put_id(buf_00,uVar8);
          addr_sym = pcVar14;
        }
        break;
      case 't':
        iVar7 = il_buffer_reserve(&buf_00->bytes,2);
        bVar6 = buf_00->open & (byte)iVar7 & 1;
        buf_00->open = bVar6;
        if (bVar6 != 0) {
          *(buf_00->bytes).cur = (c1_u8)local_44;
          (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
        }
        break;
      case 'v':
        pcVar3 = node->type;
        cVar1 = (char)pcVar3->code;
        pcVar9 = pcVar3;
        while (cVar1 < '\0') {
          pcVar9 = pcVar9->base;
          cVar1 = (char)pcVar9->code;
        }
        if ((pcVar9->code & 0x10) == 0) {
          uVar2 = pcVar3->code;
          if ((char)uVar2 < '\0') {
            pcVar9 = (c1_type *)(uVar2 & 0x8f);
            if (((short)pcVar9 != 0x86) && ((short)pcVar9 != 0x82)) {
              init_write_in_record_fields
                        (pcVar3,(uint)pcVar9,buf_00,node,(int)value_00,addr_sym,is_string,fmt,
                         float_value,type_code,const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,
                         (c1_x87_tail)value2,sym,node,(char)buf);
              return;
            }
            goto LAB_10440988;
          }
          pcVar9 = (c1_type *)
                   (CONCAT31((int3)(CONCAT22((short)((uint)pcVar9 >> 0x10),uVar2) >> 8),
                             (char)pcVar3->code) & 0xffffff8f);
          if ((char)pcVar9 == -0x76) goto LAB_10440988;
          cVar1 = (char)pcVar3->code;
          pcVar9 = pcVar3;
          while (cVar1 < '\0') {
            pcVar9 = pcVar9->base;
            cVar1 = (char)pcVar9->code;
          }
          if ((pcVar9->code & 0x100) != 0) goto LAB_10440988;
          cVar1 = (char)pcVar3->code;
          while (cVar1 < '\0') {
            pcVar3 = pcVar3->base;
            cVar1 = (char)pcVar3->code;
          }
          if ((pcVar3->code & 0x20) != 0) {
            buf._0_1_ = '\0';
            buf = (c1_il_buffer *)0x0;
          }
        }
        else {
LAB_10440988:
          type_code = CONCAT22((short)((uint)pcVar9 >> 0x10),pcVar3->code);
          const_hi = (int)node->right;
          const_lo = (uint)node->left;
          buf._0_1_ = '\x01';
          buf = (c1_il_buffer *)0x1;
        }
        if (cVar5 == '\x05') {
          value_words = node->left;
          value0 = *value_words;
          value1 = value_words[1];
          value2 = *(c1_u16 (*) [2])(value_words + 2);
          if (iStack_40 == 8) {
            fold_float_to_double_checked((byte *)&value0,(double *)&dbl_lo);
            iVar7 = il_buffer_reserve(&buf_00->bytes,9);
            bVar6 = buf_00->open & (byte)iVar7 & 1;
            buf_00->open = bVar6;
            if (bVar6 != 0) {
              value_words_4 = (uint *)(buf_00->bytes).cur;
              *value_words_4 = dbl_lo;
              value_words_4[1] = dbl_hi;
              (buf_00->bytes).cur = (buf_00->bytes).cur + 8;
            }
          }
          else if (iStack_40 == 4) {
            fpu_store_float_if_in_range((float10 *)&value0,&float_value);
            iVar7 = il_buffer_reserve(&buf_00->bytes,5);
            bVar6 = buf_00->open & (byte)iVar7 & 1;
            buf_00->open = bVar6;
            if (bVar6 != 0) {
              *(float *)(buf_00->bytes).cur = float_value;
              (buf_00->bytes).cur = (buf_00->bytes).cur + 4;
            }
          }
          else {
            iVar7 = il_buffer_reserve(&buf_00->bytes,0xb);
            bVar6 = buf_00->open & (byte)iVar7 & 1;
            buf_00->open = bVar6;
            if (bVar6 != 0) {
              value_words_3 = (uint *)(buf_00->bytes).cur;
              *value_words_3 = value0;
              value_words_3[1] = value1;
              *(c1_u16 *)(value_words_3 + 2) = value2[0];
              (buf_00->bytes).cur = (buf_00->bytes).cur + 10;
            }
            iVar7 = il_buffer_reserve(&buf_00->bytes,3);
            bVar6 = buf_00->open & (byte)iVar7 & 1;
            buf_00->open = bVar6;
            if (bVar6 != 0) {
              *(c1_u16 *)(buf_00->bytes).cur = value2[1];
              (buf_00->bytes).cur = (buf_00->bytes).cur + 2;
            }
          }
        }
        else if (iStack_40 == 1) {
          if ((char)buf == '\0') {
            iVar7 = fold_float_to_int32_checked(node->left,(int *)&int_value);
            if (iVar7 != 0) {
              diag_warning(2,0x38);
            }
            cVar4 = (c1_u8)int_value;
          }
          else {
            cVar4 = (c1_u8)const_lo;
          }
          iVar7 = il_buffer_reserve(&buf_00->bytes,2);
          bVar6 = buf_00->open & (byte)iVar7 & 1;
          buf_00->open = bVar6;
          if (bVar6 != 0) {
            *(buf_00->bytes).cur = cVar4;
            (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
          }
        }
        else {
          if (iStack_40 == 2) {
            uVar8 = const_lo;
            if ((char)buf == '\0') {
              iVar7 = fold_float_to_int32_checked(node->left,(int *)&int_value);
              if (iVar7 != 0) {
                diag_warning(2,0x38);
              }
              uVar8 = (uint)int_value;
            }
            int_value = CONCAT44((int)(uVar8 << 0x10) >> 0x1f,(int)(uVar8 << 0x10) >> 0x10);
            iVar7 = 2;
          }
          else {
            if (iStack_40 != 4) {
              if ((g_integral_max_bytes < 8) || (iStack_40 != 8)) {
                if ((g_integral_max_bytes < 0x10) || (iStack_40 != 0x10)) break;
                if ((char)buf == '\0') {
                  iVar7 = fold_float_to_int64_checked(node->left,(c1_u32 *)&int_value);
                  if (iVar7 != 0) {
                    diag_warning(2,0x38);
                  }
                  iVar7 = 0x10;
                }
                else {
                  lVar13 = _allshl(0xc0,const_lo,const_hi);
                  int_value = _allshr(0xc0,(int)((ulonglong)lVar13 >> 0x20),(uint)lVar13);
                  iVar7 = 0x10;
                }
              }
              else {
                if ((char)buf == '\0') {
                  iVar7 = fold_float_to_int64_checked(node->left,(c1_u32 *)&int_value);
                  if (iVar7 != 0) {
                    diag_warning(2,0x38);
                  }
                }
                else {
                  int_value = CONCAT44(const_hi,const_lo);
                }
                iVar7 = 8;
              }
              il_buffer_put_int_sized((uint *)&int_value,iVar7,buf_00);
              break;
            }
            uVar8 = const_lo;
            if ((char)buf == '\0') {
              iVar7 = fold_float_to_int32_checked(node->left,(int *)&int_value);
              if (iVar7 != 0) {
                diag_warning(2,0x38);
              }
              uVar8 = (uint)int_value;
            }
            int_value = (longlong)(int)uVar8;
            iVar7 = 4;
          }
          il_buffer_put_int_sized((uint *)&int_value,iVar7,buf_00);
        }
        break;
      case 'z':
        pcVar3 = sym->type;
        if ((pcVar3->code & 0x8f) == 0x83) {
          iStack_40 = sym_element_size((int)sym);
        }
        else {
          iStack_40 = type_size(pcVar3);
        }
        if ((local_44 == 2) && ((is_string == 0 || (iStack_40 == 1)))) {
          uVar2 = pcVar3->code;
          bVar11 = (byte)uVar2;
          pcVar9 = pcVar3;
          bVar6 = bVar11;
          while ((char)bVar6 < '\0') {
            pcVar9 = pcVar9->base;
            bVar6 = (byte)pcVar9->code;
          }
          bVar6 = bVar11;
          if ((pcVar9->code & 0x10) == 0) {
            while ((char)bVar6 < '\0') {
              pcVar3 = pcVar3->base;
              bVar6 = (byte)pcVar3->code;
            }
            if (((pcVar3->code & 0x400) == 0) &&
               (((-1 < (char)bVar11 ||
                 ((((uVar2 & 0x8f) != 0x86 && ((uVar2 & 0x8f) != 0x82)) &&
                  ((-1 < (char)bVar11 || ((bVar11 & 0x8f) != 0x80)))))) &&
                (((uVar2 & 0x8f) != 0x8a && ((uVar2 & 0x8f) != 0x8e)))))) {
              init_check_illegal(buf_00,node,(int)value_00,addr_sym,is_string,fmt,float_value,
                                 type_code,const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,
                                 (c1_x87_tail)value2,sym,node,(char)buf);
              return;
            }
          }
        }
        if (((buf_00->bytes).start + (buf_00->bytes).size < (buf_00->bytes).cur + 2) &&
           (iVar7 = il_buffer_grow(&buf_00->bytes,2), iVar7 == 0)) {
          bVar6 = 0;
        }
        else {
          bVar6 = 1;
        }
        bVar6 = buf_00->open & bVar6;
        buf_00->open = bVar6;
        if (bVar6 != 0) {
          *(buf_00->bytes).cur = (c1_u8)iStack_40;
          (buf_00->bytes).cur = (buf_00->bytes).cur + 1;
        }
      }
    }
  }
  return;
}

