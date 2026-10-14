void __cdecl
init_emit_initializer_fragment_2
          (char is_unsigned,fe_il_buffer *buf,c1_node *value,uint addr_offset,c1_symbol *addr_symbol
          ,int addr_mode,char *format,float fvalue,longlong value64,uint value_lo,int value_hi,
          double dvalue,float_const xvalue,c1_symbol *init_sym,c1_node *init,char value_is_integral)

{
  uint *puVar1;
  float_const xvalue_00;
  float_const xvalue_01;
  float_const xvalue_02;
  float_const xvalue_03;
  bool bVar2;
  ushort uVar3;
  void *pvVar4;
  int iVar5;
  c1_type *pcVar6;
  c1_type *pcVar7;
  c1_symbol *sym;
  char *text;
  byte bVar8;
  char cVar9;
  PB puVar10;
  uint uVar11;
  longlong lVar12;
  uchar uStack00000010;
  uchar uStack00000014;
  uint in_stack_00000018;
  float_const *out;
  
code_r0x1061f1db:
  iVar5 = 1;
LAB_1061f12d:
  value_lo = (uint)value->left;
  value_hi = (int)value->right;
LAB_1061f142:
  if (_uStack00000014 == 5) {
    if (is_unsigned == '\0') {
      puVar1 = value->left;
      xvalue.mantissa_lo = *puVar1;
      xvalue.mantissa_hi = puVar1[1];
      xvalue.sign_exponent = (ushort)puVar1[2];
      xvalue.size = (ushort)(puVar1[2] >> 0x10);
    }
    else {
      out = &xvalue;
      text = int64_to_string((int *)&value_lo,&stack0x00000054,10,iVar5);
      float_const_from_string(text,out);
    }
    if (in_stack_00000018 == 8) {
      fold_float_to_double_checked((float10 *)&xvalue,&dvalue);
      iVar5 = il_buffer_reserve(&buf->bytes,9);
      bVar8 = buf->open & (byte)iVar5 & 1;
      buf->open = bVar8;
      if (bVar8 != 0) {
        *(double *)(buf->bytes).pbEnd = dvalue;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 8;
      }
    }
    else if (in_stack_00000018 == 4) {
      fpu_store_float_if_in_range((longdouble *)&xvalue,&fvalue);
      iVar5 = il_buffer_reserve(&buf->bytes,5);
      bVar8 = buf->open & (byte)iVar5 & 1;
      buf->open = bVar8;
      if (bVar8 != 0) {
        *(float *)(buf->bytes).pbEnd = fvalue;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
    }
    else {
      iVar5 = il_buffer_reserve(&buf->bytes,0xb);
      bVar8 = buf->open & (byte)iVar5 & 1;
      buf->open = bVar8;
      if (bVar8 != 0) {
        puVar1 = (uint *)(buf->bytes).pbEnd;
        *puVar1 = xvalue.mantissa_lo;
        puVar1[1] = xvalue.mantissa_hi;
        *(ushort *)(puVar1 + 2) = xvalue.sign_exponent;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 10;
      }
      iVar5 = il_buffer_reserve(&buf->bytes,3);
      bVar8 = buf->open & (byte)iVar5 & 1;
      buf->open = bVar8;
      if (bVar8 != 0) {
        *(ushort *)(buf->bytes).pbEnd = xvalue.size;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
    }
  }
  else if (in_stack_00000018 == 1) {
    uVar11 = value_lo;
    if (is_unsigned == '\0') {
      iVar5 = fold_float_to_int32_checked(value->left,(int *)&value64);
      if (iVar5 != 0) {
        diag_warning(2,0x38);
      }
      uVar11 = (uint)(byte)value64;
    }
    iVar5 = il_buffer_reserve(&buf->bytes,2);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    if (bVar8 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar11;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
  }
  else {
    if (in_stack_00000018 == 2) {
      uVar11 = value_lo;
      if (is_unsigned == '\0') {
        iVar5 = fold_float_to_int32_checked(value->left,(int *)&value64);
        if (iVar5 != 0) {
          diag_warning(2,0x38);
        }
        uVar11 = (uint)value64;
      }
      value64 = CONCAT44((int)(uVar11 << 0x10) >> 0x1f,(int)(uVar11 << 0x10) >> 0x10);
      iVar5 = 2;
    }
    else {
      if (in_stack_00000018 != 4) {
        if ((g_integral_max_bytes < 8) || (in_stack_00000018 != 8)) {
          if ((g_integral_max_bytes < 0x10) || (in_stack_00000018 != 0x10))
          goto switchD_1061f049_caseD_67;
          if (value_is_integral == '\0') {
            iVar5 = fold_float_to_int64_checked(value->left,&value64);
            if (iVar5 != 0) {
              diag_warning(2,0x38);
            }
            iVar5 = 0x10;
          }
          else {
            lVar12 = _allshl(0xc0,value_lo,value_hi);
            value64 = _allshr(0xc0,(int)((ulonglong)lVar12 >> 0x20),(uint)lVar12);
            iVar5 = 0x10;
          }
        }
        else {
          if (is_unsigned == '\0') {
            iVar5 = fold_float_to_int64_checked(value->left,&value64);
            if (iVar5 != 0) {
              diag_warning(2,0x38);
            }
          }
          else {
            value64 = CONCAT44(value_hi,value_lo);
          }
          iVar5 = 8;
        }
        il_buffer_put_int_sized((uint *)&value64,iVar5,buf);
        goto switchD_1061f049_caseD_67;
      }
      uVar11 = value_lo;
      if (is_unsigned == '\0') {
        iVar5 = fold_float_to_int32_checked(value->left,(int *)&value64);
        if (iVar5 != 0) {
          diag_warning(2,0x38);
        }
        uVar11 = (uint)value64;
      }
      value64 = (longlong)(int)uVar11;
      iVar5 = 4;
    }
    il_buffer_put_int_sized((uint *)&value64,iVar5,buf);
  }
switchD_1061f049_caseD_67:
  if ((format == (char *)0x0) || (cVar9 = *format, cVar9 == '\0')) {
    return;
  }
  format = format + 1;
  switch(cVar9) {
  case 'f':
    pvVar4 = (void *)addr_offset;
    break;
  default:
    goto switchD_1061f049_caseD_67;
  case 'i':
    iVar5 = il_buffer_reserve(&buf->bytes,2);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    if (bVar8 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1061f049_caseD_67;
  case 'l':
    uVar3 = *(ushort *)&init->right;
    puVar1 = init->left;
    iVar5 = il_buffer_reserve(&buf->bytes,uVar3 + 4);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    value = init;
    if (bVar8 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,uVar3);
      il_buffer_put_bytes(buf,puVar1,(uint)uVar3);
      value = init;
    }
    goto switchD_1061f049_caseD_67;
  case 'n':
    pvVar4 = value->left;
    break;
  case 'p':
    pcVar7 = init_sym->type;
    uVar3 = pcVar7->code;
    if ((((char)(byte)uVar3 < '\0') && (((uVar3 & 0x8f) == 0x86 || ((uVar3 & 0x8f) == 0x82)))) ||
       (((byte)uVar3 & 0x8f) == 0x8e)) {
      _uStack00000014 = 3;
    }
    else {
      if ((uVar3 & 0x2000) == 0) {
        bVar2 = type_is_plain_char_unsigned(pcVar7);
        if (!bVar2) {
          uVar3 = pcVar7->code;
          if ((uVar3 & 0x110) == 0) {
            if (((byte)uVar3 >> 5 & 1) == 0) {
              if ((uVar3 & 0x400) != 0) {
                _uStack00000014 = 2;
              }
            }
            else {
              _uStack00000014 = 5;
            }
          }
          else {
            _uStack00000014 = 1;
          }
          goto LAB_1061f07e;
        }
      }
      _uStack00000014 = 2;
    }
LAB_1061f07e:
    iVar5 = il_buffer_reserve(&buf->bytes,2);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    if (bVar8 != 0) {
      *(buf->bytes).pbEnd = uStack00000014;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1061f049_caseD_67;
  case 's':
    sym_mark_referenced(addr_symbol);
    sym = addr_symbol;
    if ((addr_symbol->flags3 & 0x40) != 0) {
      sym = decl_lookup_file_scope_twin(addr_symbol);
      sym_mark_referenced(sym);
    }
    if ((sym->flags23 & 1) != 0) {
      pvVar4 = sym_segment_record(sym);
      if ((*(uint *)((int)pvVar4 + 0x1c) & 0xffffff) == 5) {
        xvalue_00.mantissa_hi = xvalue.mantissa_hi;
        xvalue_00.mantissa_lo = xvalue.mantissa_lo;
        xvalue_00.sign_exponent = xvalue.sign_exponent;
        xvalue_00.size = xvalue.size;
        init_emit_initializer_fragment
                  (sym,buf,value,addr_offset,addr_symbol,addr_mode,format,fvalue,value64,value_lo,
                   value_hi,dvalue,xvalue_00,init_sym,init,value_is_integral);
        return;
      }
    }
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar11 = il_symbol_key_assign(sym);
        goto LAB_1061efc0;
      }
      uVar11 = sym->key_ref >> 3;
    }
    else {
      uVar11 = sym->entity & 0xffffff;
LAB_1061efc0:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar11);
        goto switchD_1061f049_caseD_67;
      }
    }
    iVar5 = il_buffer_reserve(&buf->bytes,4);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    if (bVar8 != 0) {
      bVar8 = (byte)uVar11;
      if (uVar11 < 0x3fff80) {
        if (uVar11 < 0x4000) {
          *(buf->bytes).pbEnd = bVar8 & 0x3f | 0x80;
          puVar10 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar10;
          *puVar10 = (uchar)(uVar11 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar8 | 0xc0;
          puVar10 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar10;
          *puVar10 = (uchar)(uVar11 >> 6);
          puVar10 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar10;
          *puVar10 = (uchar)(uVar11 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar8 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1061f049_caseD_67;
  case 't':
    iVar5 = il_buffer_reserve(&buf->bytes,2);
    bVar8 = buf->open & (byte)iVar5 & 1;
    buf->open = bVar8;
    if (bVar8 != 0) {
      *(buf->bytes).pbEnd = uStack00000010;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1061f049_caseD_67;
  case 'v':
    goto switchD_1061f049_caseD_76;
  case 'z':
    pcVar7 = init_sym->type;
    if ((pcVar7->code & 0x8f) == 0x83) {
      in_stack_00000018 = sym_element_size(init_sym);
    }
    else {
      in_stack_00000018 = type_size(pcVar7);
    }
    if ((_uStack00000010 == 2) && ((addr_mode == 0 || (in_stack_00000018 == 1)))) {
      uVar3 = pcVar7->code;
      cVar9 = -((char)uVar3 >> 7);
      pcVar6 = pcVar7;
      if (cVar9 != '\0') {
        do {
          pcVar6 = pcVar6->base;
        } while ((char)pcVar6->code < '\0');
      }
      if ((pcVar6->code & 0x10) == 0) {
        if (cVar9 != '\0') {
          do {
            pcVar7 = pcVar7->base;
          } while ((char)pcVar7->code < '\0');
        }
        if ((pcVar7->code & 0x400) == 0) {
          if (cVar9 == '\0') {
            if (((uVar3 & 0x8f) != 0x8a) && ((uVar3 & 0x8f) != 0x8e)) {
              diag_error(0x61);
            }
          }
          else if (((uVar3 & 0x8f) != 0x86) && ((uVar3 & 0x8f) != 0x82)) {
            xvalue_02.mantissa_hi = xvalue.mantissa_hi;
            xvalue_02.mantissa_lo = xvalue.mantissa_lo;
            xvalue_02.sign_exponent = xvalue.sign_exponent;
            xvalue_02.size = xvalue.size;
            init_report_illegal(cVar9,uVar3,buf,value,in_stack_00000018,addr_offset,addr_symbol,
                                addr_mode,format,fvalue,value64,value_lo,value_hi,dvalue,xvalue_02,
                                init_sym,init,value_is_integral);
            return;
          }
        }
      }
    }
    if ((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 2) {
      iVar5 = il_buffer_grow(&buf->bytes,2);
      if (iVar5 != 0) goto LAB_1061f27d;
      bVar8 = 0;
    }
    else {
LAB_1061f27d:
      bVar8 = 1;
    }
    bVar8 = buf->open & bVar8;
    buf->open = bVar8;
    if (bVar8 != 0) {
      *(buf->bytes).pbEnd = (uchar)in_stack_00000018;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1061f049_caseD_67;
  }
  iVar5 = il_buffer_reserve(&buf->bytes,6);
  bVar8 = buf->open & (byte)iVar5 & 1;
  buf->open = bVar8;
  if (bVar8 != 0) {
    iVar5 = il_buffer_put_byte7(buf,(uint)pvVar4);
    if ((char)iVar5 == '\0') {
      *(buf->bytes).pbEnd = 0x80;
      puVar10 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar10;
      *(void **)puVar10 = pvVar4;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
  }
  goto switchD_1061f049_caseD_67;
switchD_1061f049_caseD_76:
  pcVar7 = value->type;
  iVar5 = 0;
  cVar9 = (char)pcVar7->code;
  pcVar6 = pcVar7;
  while (cVar9 < '\0') {
    pcVar6 = pcVar6->base;
    cVar9 = (char)pcVar6->code;
  }
  if ((pcVar6->code & 0x10) != 0) goto LAB_1061f109;
  if (-1 < (char)pcVar7->code) {
    if ((pcVar7->code & 0x8f) == 0x8a) goto LAB_1061f109;
    cVar9 = (char)pcVar7->code;
    pcVar6 = pcVar7;
    while (cVar9 < '\0') {
      pcVar6 = pcVar6->base;
      cVar9 = (char)pcVar6->code;
    }
    if ((pcVar6->code & 0x100) != 0) goto LAB_1061f109;
    cVar9 = (char)pcVar7->code;
    while (cVar9 < '\0') {
      pcVar7 = pcVar7->base;
      cVar9 = (char)pcVar7->code;
    }
    is_unsigned = value_is_integral;
    if ((pcVar7->code & 0x20) != 0) {
      value_is_integral = '\0';
      is_unsigned = value_is_integral;
    }
    goto LAB_1061f142;
  }
  uVar3 = pcVar7->code & 0x8f;
  if ((uVar3 != 0x86) && (uVar3 != 0x82)) {
    xvalue_01.mantissa_hi = xvalue.mantissa_hi;
    xvalue_01.mantissa_lo = xvalue.mantissa_lo;
    xvalue_01.sign_exponent = xvalue.sign_exponent;
    xvalue_01.size = xvalue.size;
    fold_float_binary(pcVar7,0,buf,value,addr_offset,addr_symbol,addr_mode,format,fvalue,value64,
                      value_lo,value_hi,dvalue,xvalue_01,init_sym,init,value_is_integral);
    return;
  }
LAB_1061f109:
  uVar3 = pcVar7->code;
  is_unsigned = '\x01';
  value_is_integral = '\x01';
  if ((uVar3 & 0x2000) != 0) goto code_r0x1061f1db;
  if ((((g_ms_extensions == '\0') && ((uVar3 & 0xfff) == 0x11)) && ((uVar3 & 0x1000) == 0)) &&
     (g_opt_J_unsigned_char != '\0')) {
    xvalue_03.mantissa_hi = xvalue.mantissa_hi;
    xvalue_03.mantissa_lo = xvalue.mantissa_lo;
    xvalue_03.sign_exponent = xvalue.sign_exponent;
    xvalue_03.size = xvalue.size;
    init_emit_initializer_fragment_2
              ('\x01',buf,value,addr_offset,addr_symbol,addr_mode,format,fvalue,value64,value_lo,
               value_hi,dvalue,xvalue_03,init_sym,init,'\x01');
    return;
  }
  iVar5 = 0;
  goto LAB_1061f12d;
}

