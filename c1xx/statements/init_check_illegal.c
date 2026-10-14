void __cdecl
init_check_illegal(c1_il_buffer *buf,c1_node *node,int addr_offset,c1_symbol *addr_sym,int is_string
                  ,char *fmt,float float_value,uint type_code,uint const_lo,int const_hi,uint dbl_lo
                  ,uint dbl_hi,uint value0,uint value1,c1_x87_tail value2,c1_symbol *sym,
                  c1_node *node_param,char value_is_integer)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  uint *puVar4;
  c1_u8 cVar5;
  uint uVar6;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  c1_u8 *pcVar12;
  void *value;
  c1_symbol *pcVar13;
  longlong lVar14;
  c1_u8 cStack00000010;
  c1_u8 cStack00000014;
  c1_u8 cStack00000018;
  c1_u8 cStack00000034;
  
  diag_error(0x61);
LAB_10440aea:
  if (((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 2) &&
     (iVar9 = il_buffer_grow(&buf->bytes,2), iVar9 == 0)) {
    bVar10 = 0;
  }
  else {
    bVar10 = 1;
  }
  bVar10 = buf->open & bVar10;
  buf->open = bVar10;
  if (bVar10 != 0) {
    *(buf->bytes).cur = cStack00000018;
    (buf->bytes).cur = (buf->bytes).cur + 1;
  }
switchD_104408a9_caseD_67:
  if ((fmt == (char *)0x0) || (cVar1 = *fmt, cVar1 == '\0')) {
    return;
  }
  fmt = fmt + 1;
  switch(cVar1) {
  case 'f':
    value = (void *)addr_offset;
    break;
  default:
    goto switchD_104408a9_caseD_67;
  case 'i':
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar10 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar10;
    if (bVar10 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  case 'l':
    uVar2 = *(ushort *)&node_param->right;
    puVar4 = node_param->left;
    iVar9 = il_buffer_reserve(&buf->bytes,uVar2 + 4);
    bVar10 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar10;
    node = node_param;
    if (bVar10 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,uVar2);
      il_buffer_put_bytes(buf,puVar4,(uint)uVar2);
    }
    goto switchD_104408a9_caseD_67;
  case 'n':
    value = node->left;
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
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar10 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar10;
    if (bVar10 != 0) {
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
      bVar10 = addr_sym->kind & 0x1f;
      pcVar13 = addr_sym;
      if ((bVar10 == 7) || (bVar10 == 8)) {
        if ((*(byte *)((int)&addr_sym->tail + 10) & 0x80) != 0) {
          sym_redeclaration_group_add(&g_map_region_queue,addr_sym);
        }
        if ((*(byte *)((int)&addr_sym->tail + 9) & 2) != 0) {
          pcVar8 = class_scalar_deleting_dtor_of(addr_sym);
          goto LAB_1044084b;
        }
      }
    }
    else {
      bVar10 = addr_sym->kind & 0x1f;
      if (bVar10 == 3) {
        pcVar8 = sym_static_member_stand_in(addr_sym);
        pcVar13 = pcVar8;
      }
      else if (bVar10 == 10) {
        pcVar8 = sym_inline_instance_of(addr_sym);
        pcVar13 = pcVar8;
      }
      else {
        pcVar13 = (c1_symbol *)0x0;
        pcVar8 = (c1_symbol *)0x0;
      }
LAB_1044084b:
      sym_mark_referenced(pcVar8);
    }
    if (((((pcVar13->flags23 & 1) != 0) &&
         (pcVar8 = sym_segment_record(pcVar13), (pcVar8->entity & 0xffffff) == 5)) &&
        (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
      g_function_has_body = 1;
      g_function_auto_inline = 0;
    }
    uVar6 = il_symbol_key(&pcVar13->kind);
    if (g_c9il_mode == '\0') {
      iVar9 = il_buffer_reserve(&buf->bytes,4);
      bVar10 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar10;
      if (bVar10 != 0) {
        bVar10 = (byte)uVar6;
        if (uVar6 < 0x3fff80) {
          if (uVar6 < 0x4000) {
            *(buf->bytes).cur = bVar10 & 0x3f | 0x80;
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar6 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = bVar10 | 0xc0;
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar6 >> 6);
            pcVar12 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar12;
            *pcVar12 = (c1_u8)(uVar6 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          *(buf->bytes).cur = bVar10 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar6);
    }
    goto switchD_104408a9_caseD_67;
  case 't':
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar10 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar10;
    if (bVar10 != 0) {
      *(buf->bytes).cur = cStack00000014;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_104408a9_caseD_67;
  case 'v':
    pcVar3 = node->type;
    cVar1 = (char)pcVar3->code;
    pcVar7 = pcVar3;
    while (cVar1 < '\0') {
      pcVar7 = pcVar7->base;
      cVar1 = (char)pcVar7->code;
    }
    if ((pcVar7->code & 0x10) == 0) {
      uVar2 = pcVar3->code;
      if ((char)uVar2 < '\0') {
        pcVar7 = (c1_type *)(uVar2 & 0x8f);
        if (((short)pcVar7 != 0x86) && ((short)pcVar7 != 0x82)) {
          init_write_in_record_fields
                    (pcVar3,(uint)pcVar7,buf,node,addr_offset,addr_sym,is_string,fmt,float_value,
                     type_code,const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,value2,sym,node_param,
                     value_is_integer);
          return;
        }
        goto LAB_10440988;
      }
      pcVar7 = (c1_type *)
               (CONCAT31((int3)(CONCAT22((short)((uint)pcVar7 >> 0x10),uVar2) >> 8),
                         (char)pcVar3->code) & 0xffffff8f);
      if ((char)pcVar7 == -0x76) goto LAB_10440988;
      cVar1 = (char)pcVar3->code;
      pcVar7 = pcVar3;
      while (cVar1 < '\0') {
        pcVar7 = pcVar7->base;
        cVar1 = (char)pcVar7->code;
      }
      if ((pcVar7->code & 0x100) != 0) goto LAB_10440988;
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
      type_code = CONCAT22((short)((uint)pcVar7 >> 0x10),pcVar3->code);
      const_hi = (int)node->right;
      const_lo = (uint)node->left;
      value_is_integer = '\x01';
    }
    if (_cStack00000010 != 5) {
      if (_cStack00000018 == 1) {
        if (value_is_integer == '\0') {
          iVar9 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar9 != 0) {
            diag_warning(2,0x38);
          }
          cVar5 = cStack00000034;
        }
        else {
          cVar5 = (c1_u8)const_lo;
        }
        iVar9 = il_buffer_reserve(&buf->bytes,2);
        bVar10 = buf->open & (byte)iVar9 & 1;
        buf->open = bVar10;
        if (bVar10 != 0) {
          *(buf->bytes).cur = cVar5;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        goto switchD_104408a9_caseD_67;
      }
      if (_cStack00000018 == 2) {
        uVar6 = const_lo;
        if (value_is_integer == '\0') {
          iVar9 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar9 != 0) {
            diag_warning(2,0x38);
          }
          uVar6 = _cStack00000034;
        }
        _cStack00000034 = CONCAT44((int)(uVar6 << 0x10) >> 0x1f,(int)(uVar6 << 0x10) >> 0x10);
        iVar9 = 2;
      }
      else {
        if (_cStack00000018 != 4) {
          if ((g_integral_max_bytes < 8) || (_cStack00000018 != 8)) {
            if ((g_integral_max_bytes < 0x10) || (_cStack00000018 != 0x10))
            goto switchD_104408a9_caseD_67;
            if (value_is_integer == '\0') {
              iVar9 = fold_float_to_int64_checked(node->left,(c1_u32 *)&stack0x00000034);
              if (iVar9 != 0) {
                diag_warning(2,0x38);
              }
              iVar9 = 0x10;
            }
            else {
              lVar14 = _allshl(0xc0,const_lo,const_hi);
              _cStack00000034 = _allshr(0xc0,(int)((ulonglong)lVar14 >> 0x20),(uint)lVar14);
              iVar9 = 0x10;
            }
          }
          else {
            if (value_is_integer == '\0') {
              iVar9 = fold_float_to_int64_checked(node->left,(c1_u32 *)&stack0x00000034);
              if (iVar9 != 0) {
                diag_warning(2,0x38);
              }
            }
            else {
              _cStack00000034 = CONCAT44(const_hi,const_lo);
            }
            iVar9 = 8;
          }
          il_buffer_put_int_sized((uint *)&stack0x00000034,iVar9,buf);
          goto switchD_104408a9_caseD_67;
        }
        uVar6 = const_lo;
        if (value_is_integer == '\0') {
          iVar9 = fold_float_to_int32_checked(node->left,(int *)&stack0x00000034);
          if (iVar9 != 0) {
            diag_warning(2,0x38);
          }
          uVar6 = _cStack00000034;
        }
        _cStack00000034 = (longlong)(int)uVar6;
        iVar9 = 4;
      }
      il_buffer_put_int_sized((uint *)&stack0x00000034,iVar9,buf);
      goto switchD_104408a9_caseD_67;
    }
    puVar4 = node->left;
    value0 = *puVar4;
    value1 = puVar4[1];
    value2 = *(c1_x87_tail *)(puVar4 + 2);
    if (_cStack00000018 == 8) {
      fold_float_to_double_checked((byte *)&value0,(double *)&dbl_lo);
      iVar9 = il_buffer_reserve(&buf->bytes,9);
      bVar10 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar10;
      if (bVar10 != 0) {
        puVar4 = (uint *)(buf->bytes).cur;
        *puVar4 = dbl_lo;
        puVar4[1] = dbl_hi;
        (buf->bytes).cur = (buf->bytes).cur + 8;
      }
    }
    else if (_cStack00000018 == 4) {
      fpu_store_float_if_in_range((float10 *)&value0,&float_value);
      iVar9 = il_buffer_reserve(&buf->bytes,5);
      bVar10 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar10;
      if (bVar10 != 0) {
        *(float *)(buf->bytes).cur = float_value;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
    }
    else {
      iVar9 = il_buffer_reserve(&buf->bytes,0xb);
      bVar10 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar10;
      if (bVar10 != 0) {
        puVar4 = (uint *)(buf->bytes).cur;
        *puVar4 = value0;
        puVar4[1] = value1;
        *(c1_u16 *)(puVar4 + 2) = value2.sign_exponent;
        (buf->bytes).cur = (buf->bytes).cur + 10;
      }
      iVar9 = il_buffer_reserve(&buf->bytes,3);
      bVar10 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar10;
      if (bVar10 != 0) {
        *(c1_u16 *)(buf->bytes).cur = value2.pad;
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
    }
    goto switchD_104408a9_caseD_67;
  case 'z':
    goto switchD_104408a9_caseD_7a;
  }
  iVar9 = il_buffer_reserve(&buf->bytes,6);
  bVar10 = buf->open & (byte)iVar9 & 1;
  buf->open = bVar10;
  if ((bVar10 != 0) && (iVar9 = il_buffer_put_byte7(buf,(uint)value), (char)iVar9 == '\0')) {
    il_emit_in_item_fragment
              ((uint)value,buf,node,addr_offset,addr_sym,is_string,fmt,float_value,type_code,
               const_lo,const_hi,dbl_lo,dbl_hi,value0,value1,value2,sym,node_param,value_is_integer)
    ;
    return;
  }
  goto switchD_104408a9_caseD_67;
switchD_104408a9_caseD_7a:
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
    pcVar7 = pcVar3;
    bVar10 = bVar11;
    while ((char)bVar10 < '\0') {
      pcVar7 = pcVar7->base;
      bVar10 = (byte)pcVar7->code;
    }
    bVar10 = bVar11;
    if ((pcVar7->code & 0x10) == 0) {
      while ((char)bVar10 < '\0') {
        pcVar3 = pcVar3->base;
        bVar10 = (byte)pcVar3->code;
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
  goto LAB_10440aea;
}

