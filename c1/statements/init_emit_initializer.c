void __cdecl init_emit_initializer(c1_symbol *sym,c1_node *init,fe_il_buffer *buf)

{
  float_const xvalue;
  float_const xvalue_00;
  float_const xvalue_01;
  float_const xvalue_02;
  uchar uVar1;
  fe_il_buffer *buf_00;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  void *pvVar6;
  c1_type *pcVar7;
  c1_type *pcVar8;
  char *text;
  char cVar9;
  uint *puVar10;
  char *format;
  PB puVar11;
  uint id;
  longlong lVar12;
  float_const *out;
  int local_6c;
  uint in_stack_ffffff9c;
  void *addr_offset;
  c1_symbol *addr_symbol;
  c1_symbol *addr_symbol_00;
  int addr_mode;
  float in_stack_ffffffb0;
  void *pvVar13;
  longlong in_stack_ffffffb4;
  void *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  undefined4 in_stack_ffffffc8;
  uint in_stack_ffffffcc;
  uint in_stack_ffffffd0;
  ushort in_stack_ffffffd4;
  ushort in_stack_ffffffd6;
  char acStack_28 [40];
  
  buf_00 = buf;
  addr_mode = 0;
  addr_offset = (void *)0x0;
  addr_symbol = (c1_symbol *)0x0;
  if (init == (c1_node *)0x0) {
    return;
  }
  if ((g_compile_flags_cc & 0x800) != 0) {
    return;
  }
  if ((PTR_1065df70 != (c1_symbol *)0x0) && (buf == &g_il_in)) {
    init_emit_symbol_data(PTR_1065df70,(c1_node *)0x0,&g_il_in);
    g_compile_flags_c4 = g_compile_flags_c4 | 0x40000;
    PTR_1065df70 = (c1_symbol *)0x0;
  }
  if (sym == (c1_symbol *)0x0) {
    local_6c = 8;
  }
  else {
    bVar2 = init->kind & 7;
    if (bVar2 == 5) {
      addr_mode = 1;
      iVar5 = init_is_char_array_string_init(sym,init);
      if (iVar5 == 0) {
        init = expr_string_literal(init);
        iVar5 = init_split_address_constant(init,(void **)&stack0xffffffa4,(int *)&stack0xffffffa0);
        if (iVar5 != 0) {
          local_6c = 2;
        }
      }
      else {
        local_6c = 3;
      }
    }
    else {
      if (bVar2 != 3) {
        iVar5 = init_split_address_constant(init,(void **)&stack0xffffffa4,(int *)&stack0xffffffa0);
        if (iVar5 == 0) goto LAB_1061ee17;
        if (addr_symbol != (c1_symbol *)0x0) {
          local_6c = 2;
          goto LAB_1061ee17;
        }
        init = tree_new_int_constant((int)addr_offset);
      }
      local_6c = 1;
    }
  }
LAB_1061ee17:
  uVar1 = '\0';
  format = g_debug_record_formats[local_6c].codes;
  do {
    if ((format == (char *)0x0) || (cVar9 = *format, cVar9 == '\0')) {
      return;
    }
    format = format + 1;
    switch(cVar9) {
    case 'f':
      pvVar6 = addr_offset;
      goto LAB_1061eef5;
    case 'i':
      iVar5 = il_buffer_reserve(&buf_00->bytes,2);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        *(buf_00->bytes).pbEnd = '\0';
        (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
      }
      break;
    case 'l':
      uVar4 = *(ushort *)&init->right;
      puVar10 = init->left;
      iVar5 = il_buffer_reserve(&buf_00->bytes,uVar4 + 4);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        il_buffer_put_compact_u16_unchecked(buf_00,uVar4);
        il_buffer_put_bytes(buf_00,puVar10,(uint)uVar4);
      }
      break;
    case 'n':
      pvVar6 = init->left;
LAB_1061eef5:
      iVar5 = il_buffer_reserve(&buf_00->bytes,6);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if ((bVar2 != 0) && (iVar5 = il_buffer_put_byte7(buf_00,(uint)pvVar6), (char)iVar5 == '\0')) {
        *(buf_00->bytes).pbEnd = 0x80;
        puVar10 = (uint *)((buf_00->bytes).pbEnd + 1);
        (buf_00->bytes).pbEnd = (PB)puVar10;
        *puVar10 = (uint)pvVar6;
        (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 4;
      }
      break;
    case 'p':
      pcVar8 = sym->type;
      uVar4 = pcVar8->code;
      if ((((char)(byte)uVar4 < '\0') && (((uVar4 & 0x8f) == 0x86 || ((uVar4 & 0x8f) == 0x82)))) ||
         (((byte)uVar4 & 0x8f) == 0x8e)) {
        uVar1 = '\x03';
      }
      else if (((uVar4 & 0x2000) != 0) || (bVar3 = type_is_plain_char_unsigned(pcVar8), bVar3)) {
        uVar1 = '\x02';
      }
      else {
        uVar4 = pcVar8->code;
        if ((uVar4 & 0x110) == 0) {
          if (((byte)uVar4 >> 5 & 1) == 0) {
            if ((uVar4 & 0x400) != 0) {
              uVar1 = '\x02';
            }
          }
          else {
            uVar1 = '\x05';
          }
        }
        else {
          uVar1 = '\x01';
        }
      }
      iVar5 = il_buffer_reserve(&buf_00->bytes,2);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        *(buf_00->bytes).pbEnd = uVar1;
        (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
      }
      break;
    case 's':
      addr_symbol_00 = addr_symbol;
      sym_mark_referenced(addr_symbol);
      if ((addr_symbol->flags3 & 0x40) != 0) {
        addr_symbol = decl_lookup_file_scope_twin(addr_symbol);
        sym_mark_referenced(addr_symbol);
      }
      if (((addr_symbol->flags23 & 1) != 0) &&
         (pvVar6 = sym_segment_record(addr_symbol), (*(uint *)((int)pvVar6 + 0x1c) & 0xffffff) == 5)
         ) {
        xvalue.mantissa_hi = in_stack_ffffffd0;
        xvalue.mantissa_lo = in_stack_ffffffcc;
        xvalue.sign_exponent = in_stack_ffffffd4;
        xvalue.size = in_stack_ffffffd6;
        init_emit_initializer_fragment
                  (addr_symbol,buf_00,init,(uint)addr_offset,addr_symbol_00,addr_mode,format,
                   in_stack_ffffffb0,in_stack_ffffffb4,(uint)in_stack_ffffffbc,
                   (int)in_stack_ffffffc0,(double)CONCAT44(in_stack_ffffffc8,in_stack_ffffffc4),
                   xvalue,sym,init,(char)buf);
        return;
      }
      if (g_c9il_mode == '\0') {
        if ((addr_symbol->key_ref & 0xfffffff8) == 0) {
          id = il_symbol_key_assign(addr_symbol);
          addr_symbol = addr_symbol_00;
          goto LAB_1061efc0;
        }
        id = addr_symbol->key_ref >> 3;
        addr_symbol = addr_symbol_00;
      }
      else {
        id = addr_symbol->entity & 0xffffff;
        addr_symbol = addr_symbol_00;
LAB_1061efc0:
        if (g_c9il_mode != '\0') {
          il_buffer_put_id(buf_00,id);
          break;
        }
      }
      iVar5 = il_buffer_reserve(&buf_00->bytes,4);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        bVar2 = (byte)id;
        if (id < 0x3fff80) {
          if (id < 0x4000) {
            *(buf_00->bytes).pbEnd = bVar2 & 0x3f | 0x80;
            puVar11 = (buf_00->bytes).pbEnd + 1;
            (buf_00->bytes).pbEnd = puVar11;
            *puVar11 = (uchar)(id >> 6);
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
          }
          else {
            *(buf_00->bytes).pbEnd = bVar2 | 0xc0;
            puVar11 = (buf_00->bytes).pbEnd + 1;
            (buf_00->bytes).pbEnd = puVar11;
            *puVar11 = (uchar)(id >> 6);
            puVar11 = (buf_00->bytes).pbEnd + 1;
            (buf_00->bytes).pbEnd = puVar11;
            *puVar11 = (uchar)(id >> 0xe);
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf_00->bytes).pbEnd = bVar2 + 0x80;
          (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
        }
      }
      break;
    case 't':
      iVar5 = il_buffer_reserve(&buf_00->bytes,2);
      bVar2 = buf_00->open & (byte)iVar5 & 1;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        *(buf_00->bytes).pbEnd = (uchar)local_6c;
        (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
      }
      break;
    case 'v':
      pcVar8 = init->type;
      iVar5 = 0;
      cVar9 = (char)pcVar8->code;
      pcVar7 = pcVar8;
      while (cVar9 < '\0') {
        pcVar7 = pcVar7->base;
        cVar9 = (char)pcVar7->code;
      }
      if ((pcVar7->code & 0x10) == 0) {
        if ((char)pcVar8->code < '\0') {
          uVar4 = pcVar8->code & 0x8f;
          if ((uVar4 != 0x86) && (uVar4 != 0x82)) {
            xvalue_00.mantissa_hi = in_stack_ffffffd0;
            xvalue_00.mantissa_lo = in_stack_ffffffcc;
            xvalue_00.sign_exponent = in_stack_ffffffd4;
            xvalue_00.size = in_stack_ffffffd6;
            fold_float_binary(pcVar8,0,buf_00,init,(uint)addr_offset,addr_symbol,addr_mode,format,
                              in_stack_ffffffb0,in_stack_ffffffb4,(uint)in_stack_ffffffbc,
                              (int)in_stack_ffffffc0,
                              (double)CONCAT44(in_stack_ffffffc8,in_stack_ffffffc4),xvalue_00,sym,
                              init,(char)buf);
            return;
          }
          goto LAB_1061f109;
        }
        if ((pcVar8->code & 0x8f) == 0x8a) goto LAB_1061f109;
        cVar9 = (char)pcVar8->code;
        pcVar7 = pcVar8;
        while (cVar9 < '\0') {
          pcVar7 = pcVar7->base;
          cVar9 = (char)pcVar7->code;
        }
        if ((pcVar7->code & 0x100) != 0) goto LAB_1061f109;
        cVar9 = (char)pcVar8->code;
        while (cVar9 < '\0') {
          pcVar8 = pcVar8->base;
          cVar9 = (char)pcVar8->code;
        }
        pvVar6 = in_stack_ffffffbc;
        if ((pcVar8->code & 0x20) != 0) {
          buf._0_1_ = '\0';
          buf = (fe_il_buffer *)0x0;
        }
      }
      else {
LAB_1061f109:
        uVar4 = pcVar8->code;
        buf._0_1_ = '\x01';
        buf = (fe_il_buffer *)0x1;
        if ((uVar4 & 0x2000) == 0) {
          if ((((g_ms_extensions == '\0') && ((uVar4 & 0xfff) == 0x11)) && ((uVar4 & 0x1000) == 0))
             && (g_opt_J_unsigned_char != '\0')) {
            xvalue_02.mantissa_hi = in_stack_ffffffd0;
            xvalue_02.mantissa_lo = in_stack_ffffffcc;
            xvalue_02.sign_exponent = in_stack_ffffffd4;
            xvalue_02.size = in_stack_ffffffd6;
            init_emit_initializer_fragment_2
                      ('\x01',buf_00,init,(uint)addr_offset,addr_symbol,addr_mode,format,
                       in_stack_ffffffb0,in_stack_ffffffb4,(uint)in_stack_ffffffbc,
                       (int)in_stack_ffffffc0,(double)CONCAT44(in_stack_ffffffc8,in_stack_ffffffc4),
                       xvalue_02,sym,init,'\x01');
            return;
          }
          iVar5 = 0;
        }
        else {
          iVar5 = 1;
        }
        in_stack_ffffffc0 = init->right;
        pvVar6 = init->left;
      }
      in_stack_ffffffbc = pvVar6;
      if (uVar1 == '\x05') {
        if ((char)buf == '\0') {
          puVar10 = init->left;
          in_stack_ffffffcc = *puVar10;
          in_stack_ffffffd0 = puVar10[1];
          in_stack_ffffffd4 = (ushort)puVar10[2];
          in_stack_ffffffd6 = (ushort)(puVar10[2] >> 0x10);
        }
        else {
          out = (float_const *)&stack0xffffffcc;
          text = int64_to_string((int *)&stack0xffffffbc,acStack_28,10,iVar5);
          float_const_from_string(text,out);
          in_stack_ffffffbc = pvVar6;
        }
        if (in_stack_ffffff9c == 8) {
          fold_float_to_double_checked((float10 *)&stack0xffffffcc,(double *)&stack0xffffffc4);
          iVar5 = il_buffer_reserve(&buf_00->bytes,9);
          bVar2 = buf_00->open & (byte)iVar5 & 1;
          buf_00->open = bVar2;
          if (bVar2 != 0) {
            puVar11 = (buf_00->bytes).pbEnd;
            *(undefined4 *)puVar11 = in_stack_ffffffc4;
            *(undefined4 *)(puVar11 + 4) = in_stack_ffffffc8;
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 8;
          }
        }
        else if (in_stack_ffffff9c == 4) {
          fpu_store_float_if_in_range((longdouble *)&stack0xffffffcc,(float *)&stack0xffffffb0);
          iVar5 = il_buffer_reserve(&buf_00->bytes,5);
          bVar2 = buf_00->open & (byte)iVar5 & 1;
          buf_00->open = bVar2;
          if (bVar2 != 0) {
            *(float *)(buf_00->bytes).pbEnd = in_stack_ffffffb0;
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 4;
          }
        }
        else {
          iVar5 = il_buffer_reserve(&buf_00->bytes,0xb);
          bVar2 = buf_00->open & (byte)iVar5 & 1;
          buf_00->open = bVar2;
          if (bVar2 != 0) {
            puVar10 = (uint *)(buf_00->bytes).pbEnd;
            *puVar10 = in_stack_ffffffcc;
            puVar10[1] = in_stack_ffffffd0;
            *(ushort *)(puVar10 + 2) = in_stack_ffffffd4;
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 10;
          }
          iVar5 = il_buffer_reserve(&buf_00->bytes,3);
          bVar2 = buf_00->open & (byte)iVar5 & 1;
          buf_00->open = bVar2;
          if (bVar2 != 0) {
            *(ushort *)(buf_00->bytes).pbEnd = in_stack_ffffffd6;
            (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 2;
          }
        }
      }
      else if (in_stack_ffffff9c == 1) {
        if ((char)buf == '\0') {
          iVar5 = fold_float_to_int32_checked(init->left,(int *)&stack0xffffffb4);
          in_stack_ffffffbc = pvVar6;
          if (iVar5 != 0) {
            diag_warning(2,0x38);
            in_stack_ffffffbc = pvVar6;
          }
          pvVar6 = (void *)(uint)(byte)in_stack_ffffffb4;
        }
        iVar5 = il_buffer_reserve(&buf_00->bytes,2);
        bVar2 = buf_00->open & (byte)iVar5 & 1;
        buf_00->open = bVar2;
        if (bVar2 != 0) {
          *(buf_00->bytes).pbEnd = (uchar)pvVar6;
          (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
        }
      }
      else {
        if (in_stack_ffffff9c == 2) {
          pvVar13 = pvVar6;
          if ((char)buf == '\0') {
            iVar5 = fold_float_to_int32_checked(init->left,(int *)&stack0xffffffb4);
            pvVar13 = (void *)in_stack_ffffffb4;
            in_stack_ffffffbc = pvVar6;
            if (iVar5 != 0) {
              diag_warning(2,0x38);
              in_stack_ffffffbc = pvVar6;
            }
          }
          in_stack_ffffffb4 =
               CONCAT44(((int)pvVar13 << 0x10) >> 0x1f,((int)pvVar13 << 0x10) >> 0x10);
          iVar5 = 2;
        }
        else {
          if (in_stack_ffffff9c != 4) {
            if ((g_integral_max_bytes < 8) || (in_stack_ffffff9c != 8)) {
              if ((g_integral_max_bytes < 0x10) || (in_stack_ffffff9c != 0x10)) break;
              if ((char)buf == '\0') {
                iVar5 = fold_float_to_int64_checked(init->left,(longlong *)&stack0xffffffb4);
                if (iVar5 != 0) {
                  diag_warning(2,0x38);
                }
                iVar5 = 0x10;
              }
              else {
                lVar12 = _allshl(0xc0,(uint)pvVar6,(uint)in_stack_ffffffc0);
                in_stack_ffffffb4 = _allshr(0xc0,(int)((ulonglong)lVar12 >> 0x20),(uint)lVar12);
                iVar5 = 0x10;
              }
            }
            else {
              if ((char)buf == '\0') {
                iVar5 = fold_float_to_int64_checked(init->left,(longlong *)&stack0xffffffb4);
                if (iVar5 != 0) {
                  diag_warning(2,0x38);
                }
              }
              else {
                in_stack_ffffffb4 = CONCAT44(in_stack_ffffffc0,pvVar6);
              }
              iVar5 = 8;
            }
            il_buffer_put_int_sized((uint *)&stack0xffffffb4,iVar5,buf_00);
            in_stack_ffffffbc = pvVar6;
            break;
          }
          if ((char)buf == '\0') {
            iVar5 = fold_float_to_int32_checked(init->left,(int *)&stack0xffffffb4);
            pvVar6 = (void *)in_stack_ffffffb4;
            if (iVar5 != 0) {
              diag_warning(2,0x38);
            }
          }
          in_stack_ffffffb4 = (longlong)(int)pvVar6;
          iVar5 = 4;
        }
        il_buffer_put_int_sized((uint *)&stack0xffffffb4,iVar5,buf_00);
      }
      break;
    case 'z':
      pcVar8 = sym->type;
      if ((pcVar8->code & 0x8f) == 0x83) {
        in_stack_ffffff9c = sym_element_size(sym);
      }
      else {
        in_stack_ffffff9c = type_size(pcVar8);
      }
      if ((local_6c == 2) && ((addr_mode == 0 || (in_stack_ffffff9c == 1)))) {
        uVar4 = pcVar8->code;
        cVar9 = -((char)uVar4 >> 7);
        pcVar7 = pcVar8;
        if (cVar9 != '\0') {
          do {
            pcVar7 = pcVar7->base;
          } while ((char)pcVar7->code < '\0');
        }
        if ((pcVar7->code & 0x10) == 0) {
          if (cVar9 != '\0') {
            do {
              pcVar8 = pcVar8->base;
            } while ((char)pcVar8->code < '\0');
          }
          if ((pcVar8->code & 0x400) == 0) {
            if (cVar9 == '\0') {
              if (((uVar4 & 0x8f) != 0x8a) && ((uVar4 & 0x8f) != 0x8e)) {
                diag_error(0x61);
              }
            }
            else if (((uVar4 & 0x8f) != 0x86) && ((uVar4 & 0x8f) != 0x82)) {
              xvalue_01.mantissa_hi = in_stack_ffffffd0;
              xvalue_01.mantissa_lo = in_stack_ffffffcc;
              xvalue_01.sign_exponent = in_stack_ffffffd4;
              xvalue_01.size = in_stack_ffffffd6;
              init_report_illegal(cVar9,uVar4,buf_00,init,in_stack_ffffff9c,(uint)addr_offset,
                                  addr_symbol,addr_mode,format,in_stack_ffffffb0,in_stack_ffffffb4,
                                  (uint)in_stack_ffffffbc,(int)in_stack_ffffffc0,
                                  (double)CONCAT44(in_stack_ffffffc8,in_stack_ffffffc4),xvalue_01,
                                  sym,init,(char)buf);
              return;
            }
          }
        }
      }
      if (((buf_00->bytes).pbStart + (buf_00->bytes).cbAlloc < (buf_00->bytes).pbEnd + 2) &&
         (iVar5 = il_buffer_grow(&buf_00->bytes,2), iVar5 == 0)) {
        bVar2 = 0;
      }
      else {
        bVar2 = 1;
      }
      bVar2 = buf_00->open & bVar2;
      buf_00->open = bVar2;
      if (bVar2 != 0) {
        *(buf_00->bytes).pbEnd = (uchar)in_stack_ffffff9c;
        (buf_00->bytes).pbEnd = (buf_00->bytes).pbEnd + 1;
      }
    }
  } while( true );
}

