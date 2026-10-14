void __cdecl
il_emit_in_item_fragment
          (uint value,c1_il_buffer *buf,c1_node *node,int addr_offset,c1_symbol *addr_sym,
          int is_string,char *fmt,float float_value,uint type_code,uint const_lo,int const_hi,
          uint dbl_lo,uint dbl_hi,uint value0,uint value1,c1_x87_tail value2,c1_symbol *sym,
          c1_node *node_param,char value_is_integer)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_u8 cVar4;
  uint uVar5;
  c1_type *pcVar6;
  c1_symbol *pcVar7;
  int iVar8;
  byte bVar9;
  uint *puVar10;
  byte bVar11;
  c1_u8 *pcVar12;
  void *value_00;
  c1_symbol *pcVar13;
  longlong lVar14;
  c1_u8 cStack00000010;
  c1_u8 cStack00000014;
  c1_u8 cStack00000018;
  c1_u8 cStack00000034;
  
  *(buf->bytes).cur = 0x80;
  puVar10 = (uint *)((buf->bytes).cur + 1);
  (buf->bytes).cur = (c1_u8 *)puVar10;
  *puVar10 = value;
  (buf->bytes).cur = (buf->bytes).cur + 4;
switchD_104408a9_caseD_67:
  if ((fmt == (char *)0x0) || (cVar1 = *fmt, cVar1 == '\0')) {
    return;
  }
  fmt = fmt + 1;
  switch(cVar1) {
  case 'f':
    value_00 = (void *)addr_offset;
    break;
  default:
    goto switchD_104408a9_caseD_67;
  case 'i':
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  case 'l':
    uVar2 = *(ushort *)&node_param->right;
    puVar10 = node_param->left;
    iVar8 = il_buffer_reserve(&buf->bytes,uVar2 + 4);
    bVar9 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar9;
    node = node_param;
    if (bVar9 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,uVar2);
      il_buffer_put_bytes(buf,puVar10,(uint)uVar2);
    }
    goto switchD_104408a9_caseD_67;
  case 'n':
    value_00 = node->left;
    break;
  case 'p':
    uVar2 = sym->type->code;
    if ((((char)(byte)uVar2 < '\0') && (((uVar2 & 0x8f) == 0x86 || ((uVar2 & 0x8f) == 0x82)))) ||
       ((uVar2 & 0x8f) == 0x8e)) {
      _cStack00000010 = 3;
    }
    else if ((uVar2 & 0x8f) == 0x8a) {
      _cStack00000010 = 1;
    }
    else if (((uVar2 & 0x2000) == 0) &&
            ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) ||
             (g_opt_J_unsigned_char == '\0')))) {
      if ((uVar2 & 0x110) == 0) {
        if (((byte)uVar2 >> 5 & 1) == 0) {
          if ((uVar2 & 0x400) != 0) {
            _cStack00000010 = 2;
          }
        }
        else {
          _cStack00000010 = 5;
        }
      }
      else {
        _cStack00000010 = 1;
      }
    }
    else {
      _cStack00000010 = 2;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).cur = cStack00000010;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  case 's':
    if ((addr_sym->kind & 0x1f) == 8) {
      sym_mark_enclosing_scopes(addr_sym);
    }
    sym_mark_referenced(addr_sym);
    if ((addr_sym->flags4 & 0x40) == 0) {
      bVar9 = addr_sym->kind & 0x1f;
      pcVar13 = addr_sym;
      if ((bVar9 == 7) || (bVar9 == 8)) {
        if ((*(byte *)((int)&addr_sym->tail + 10) & 0x80) != 0) {
          sym_redeclaration_group_add(&g_map_region_queue,addr_sym);
        }
        if ((*(byte *)((int)&addr_sym->tail + 9) & 2) != 0) {
          pcVar7 = class_scalar_deleting_dtor_of(addr_sym);
          goto LAB_1044084b;
        }
      }
    }
    else {
      bVar9 = addr_sym->kind & 0x1f;
      if (bVar9 == 3) {
        pcVar7 = sym_static_member_stand_in(addr_sym);
        pcVar13 = pcVar7;
      }
      else if (bVar9 == 10) {
        pcVar7 = sym_inline_instance_of(addr_sym);
        pcVar13 = pcVar7;
      }
      else {
        pcVar13 = (c1_symbol *)0x0;
        pcVar7 = (c1_symbol *)0x0;
      }
LAB_1044084b:
      sym_mark_referenced(pcVar7);
    }
    if (((((pcVar13->flags23 & 1) != 0) &&
         (pcVar7 = sym_segment_record(pcVar13), (pcVar7->entity & 0xffffff) == 5)) &&
        (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
      g_function_has_body = 1;
      g_function_auto_inline = 0;
    }
    uVar5 = il_symbol_key(&pcVar13->kind);
    if (g_c9il_mode == '\0') {
      iVar8 = il_buffer_reserve(&buf->bytes,4);
      bVar9 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        bVar9 = (byte)uVar5;
        if (uVar5 < 0x3fff80) {
          if (uVar5 < 0x4000) {
            *(buf->bytes).cur = bVar9 & 0x3f | 0x80;
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar5 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = bVar9 | 0xc0;
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar5 >> 6);
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar5 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          *(buf->bytes).cur = bVar9 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar5);
    }
    goto switchD_104408a9_caseD_67;
  case 't':
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).cur = cStack00000014;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  case 'v':
    pcVar3 = node->type;
    cVar1 = (char)pcVar3->code;
    pcVar6 = pcVar3;
    while (cVar1 < '\0') {
      pcVar6 = pcVar6->base;
      cVar1 = (char)pcVar6->code;
    }
    if ((pcVar6->code & 0x10) == 0) {
      uVar2 = pcVar3->code;
      if ((char)uVar2 < '\0') {
        pcVar6 = (c1_type *)(uVar2 & 0x8f);
        if (((short)pcVar6 != 0x86) && ((short)pcVar6 != 0x82)) {
          init_write_in_record_fields
                    (pcVar3,(uint)pcVar6,buf,node,addr_offset,addr_sym,is_string,fmt,float_value,
                     type_code,const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,value2,sym,node_param,
                     value_is_integer);
          return;
        }
        goto LAB_10440988;
      }
      pcVar6 = (c1_type *)
               (CONCAT31((int3)(CONCAT22((short)((uint)pcVar6 >> 0x10),uVar2) >> 8),
                         (char)pcVar3->code) & 0xffffff8f);
      if ((char)pcVar6 == -0x76) goto LAB_10440988;
      cVar1 = (char)pcVar3->code;
      pcVar6 = pcVar3;
      while (cVar1 < '\0') {
        pcVar6 = pcVar6->base;
        cVar1 = (char)pcVar6->code;
      }
      if ((pcVar6->code & 0x100) != 0) goto LAB_10440988;
      cVar1 = (char)pcVar3->code;
      while (cVar1 < '\0') {
        pcVar3 = pcVar3->base;
        cVar1 = (char)pcVar3->code;
      }
      if ((pcVar3->code & 0x20) != 0) {
        value_is_integer = '\0';
      }
    }
    else {
LAB_10440988:
      type_code = CONCAT22((short)((uint)pcVar6 >> 0x10),pcVar3->code);
      const_hi = (int)node->right;
      const_lo = (uint)node->left;
      value_is_integer = '\x01';
    }
    if (_cStack00000010 != 5) {
      if (_cStack00000018 == 1) {
        if (value_is_integer == '\0') {
          iVar8 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar8 != 0) {
            diag_warning(2,0x38);
          }
          cVar4 = cStack00000034;
        }
        else {
          cVar4 = (c1_u8)const_lo;
        }
        iVar8 = il_buffer_reserve(&buf->bytes,2);
        bVar9 = buf->open & (byte)iVar8 & 1;
        buf->open = bVar9;
        if (bVar9 != 0) {
          *(buf->bytes).cur = cVar4;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        goto switchD_104408a9_caseD_67;
      }
      if (_cStack00000018 == 2) {
        uVar5 = const_lo;
        if (value_is_integer == '\0') {
          iVar8 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar8 != 0) {
            diag_warning(2,0x38);
          }
          uVar5 = _cStack00000034;
        }
        _cStack00000034 = CONCAT44((int)(uVar5 << 0x10) >> 0x1f,(int)(uVar5 << 0x10) >> 0x10);
        iVar8 = 2;
      }
      else {
        if (_cStack00000018 != 4) {
          if ((g_integral_max_bytes < 8) || (_cStack00000018 != 8)) {
            if ((g_integral_max_bytes < 0x10) || (_cStack00000018 != 0x10))
            goto switchD_104408a9_caseD_67;
            if (value_is_integer == '\0') {
              iVar8 = fold_float_to_int64_checked(node->left,(c1_u32 *)&stack0x00000034);
              if (iVar8 != 0) {
                diag_warning(2,0x38);
              }
              iVar8 = 0x10;
            }
            else {
              lVar14 = _allshl(0xc0,const_lo,const_hi);
              _cStack00000034 = _allshr(0xc0,(int)((ulonglong)lVar14 >> 0x20),(uint)lVar14);
              iVar8 = 0x10;
            }
          }
          else {
            if (value_is_integer == '\0') {
              iVar8 = fold_float_to_int64_checked(node->left,(c1_u32 *)&stack0x00000034);
              if (iVar8 != 0) {
                diag_warning(2,0x38);
              }
            }
            else {
              _cStack00000034 = CONCAT44(const_hi,const_lo);
            }
            iVar8 = 8;
          }
          il_buffer_put_int_sized((uint *)&stack0x00000034,iVar8,buf);
          goto switchD_104408a9_caseD_67;
        }
        uVar5 = const_lo;
        if (value_is_integer == '\0') {
          iVar8 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar8 != 0) {
            diag_warning(2,0x38);
          }
          uVar5 = _cStack00000034;
        }
        _cStack00000034 = (longlong)(int)uVar5;
        iVar8 = 4;
      }
      il_buffer_put_int_sized((uint *)&stack0x00000034,iVar8,buf);
      goto switchD_104408a9_caseD_67;
    }
    puVar10 = node->left;
    value0 = *puVar10;
    value1 = puVar10[1];
    value2 = *(c1_x87_tail *)(puVar10 + 2);
    if (_cStack00000018 == 8) {
      fold_float_to_double_checked((byte *)&value0,(double *)&dbl_lo);
      iVar8 = il_buffer_reserve(&buf->bytes,9);
      bVar9 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        puVar10 = (uint *)(buf->bytes).cur;
        *puVar10 = dbl_lo;
        puVar10[1] = dbl_hi;
        (buf->bytes).cur = (buf->bytes).cur + 8;
      }
    }
    else if (_cStack00000018 == 4) {
      fpu_store_float_if_in_range((float10 *)&value0,&float_value);
      iVar8 = il_buffer_reserve(&buf->bytes,5);
      bVar9 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        *(float *)(buf->bytes).cur = float_value;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
    }
    else {
      iVar8 = il_buffer_reserve(&buf->bytes,0xb);
      bVar9 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        puVar10 = (uint *)(buf->bytes).cur;
        *puVar10 = value0;
        puVar10[1] = value1;
        *(c1_u16 *)(puVar10 + 2) = value2.sign_exponent;
        (buf->bytes).cur = (buf->bytes).cur + 10;
      }
      iVar8 = il_buffer_reserve(&buf->bytes,3);
      bVar9 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        *(c1_u16 *)(buf->bytes).cur = value2.pad;
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
    }
    goto switchD_104408a9_caseD_67;
  case 'z':
    pcVar3 = sym->type;
    if ((pcVar3->code & 0x8f) == 0x83) {
      _cStack00000018 = sym_element_size((int)sym);
    }
    else {
      _cStack00000018 = type_size(pcVar3);
    }
    if ((_cStack00000014 == 2) && ((is_string == 0 || (_cStack00000018 == 1)))) {
      uVar2 = pcVar3->code;
      bVar11 = (byte)uVar2;
      pcVar6 = pcVar3;
      bVar9 = bVar11;
      while ((char)bVar9 < '\0') {
        pcVar6 = pcVar6->base;
        bVar9 = (byte)pcVar6->code;
      }
      bVar9 = bVar11;
      if ((pcVar6->code & 0x10) == 0) {
        while ((char)bVar9 < '\0') {
          pcVar3 = pcVar3->base;
          bVar9 = (byte)pcVar3->code;
        }
        if (((pcVar3->code & 0x400) == 0) &&
           (((-1 < (char)bVar11 ||
             ((((uVar2 & 0x8f) != 0x86 && ((uVar2 & 0x8f) != 0x82)) &&
              ((-1 < (char)bVar11 || ((bVar11 & 0x8f) != 0x80)))))) &&
            (((uVar2 & 0x8f) != 0x8a && ((uVar2 & 0x8f) != 0x8e)))))) {
          init_check_illegal(buf,node,addr_offset,addr_sym,is_string,fmt,float_value,type_code,
                             const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,value2,sym,node_param,
                             value_is_integer);
          return;
        }
      }
    }
    if (((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 2) &&
       (iVar8 = il_buffer_grow(&buf->bytes,2), iVar8 == 0)) {
      bVar9 = 0;
    }
    else {
      bVar9 = 1;
    }
    bVar9 = buf->open & bVar9;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).cur = cStack00000018;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  }
  iVar8 = il_buffer_reserve(&buf->bytes,6);
  bVar9 = buf->open & (byte)iVar8 & 1;
  buf->open = bVar9;
  if ((bVar9 != 0) && (iVar8 = il_buffer_put_byte7(buf,(uint)value_00), (char)iVar8 == '\0')) {
    il_emit_in_item_fragment
              ((uint)value_00,buf,node,addr_offset,addr_sym,is_string,fmt,float_value,type_code,
               const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,value2,sym,node_param,value_is_integer)
    ;
    return;
  }
  goto switchD_104408a9_caseD_67;
}

