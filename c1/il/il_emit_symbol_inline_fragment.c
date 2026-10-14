void __cdecl
il_emit_symbol_inline_fragment
          (c1_symbol *sym,fe_il_buffer *buf,char fdef_mode,c1_type *type,c1_type *derived_type,
          uint *stored_record,c1_type *base_type,ushort basic_code,int is_array,char *codes,
          uint elem_flag_bits,uint rec_word0,uint rec_word1,ushort rec_fflags,ushort rec_fflags_high
          ,int record_class,c1_symbol *sym_arg)

{
  PB *ppuVar1;
  c1_type *pcVar2;
  fe_name *name;
  fe_pragma_comment *pfVar3;
  fe_file_record *sym_keys;
  fe_pragma_comment *pfVar4;
  c1_u32 cVar5;
  int iVar6;
  fe_pragma_comment *pfVar7;
  uchar uVar8;
  byte bVar9;
  char cVar10;
  c1_u8 cVar11;
  ushort uVar12;
  c1_symbol_cell *value;
  uint *src;
  c1_type *pcVar13;
  fe_line_map_row *pfVar14;
  uchar *puVar15;
  int iVar16;
  byte *pbVar17;
  void *pvVar18;
  c1_symbol *pcVar19;
  int iVar20;
  ushort *array;
  uint uVar21;
  PB puVar22;
  byte bVar23;
  uint *puVar24;
  short *psVar25;
  PB puVar26;
  ushort *puVar27;
  ushort uVar28;
  int *piVar29;
  c1_symbol_cell *ref;
  uint uVar30;
  c1_symbol *sym_00;
  short sVar31;
  uchar *puVar32;
  char *pcVar33;
  int in_stack_00000058;
  
  pcVar19 = sym;
  if ((g_inline_level != 0) && ((bVar9 = sym->kind & 0x1f, bVar9 == 7 || (bVar9 == 8)))) {
    ref = ((sym->x28).function)->references;
    if (ref == (c1_symbol_cell *)0x0) {
      iVar20 = il_buffer_reserve(&buf->bytes,4);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if ((bVar9 != 0) &&
         (iVar20 = il_buffer_put_byte7(buf,0), pcVar19 = sym_arg, (char)iVar20 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\0';
        puVar26[1] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar19 = sym;
      }
    }
    else {
      array = (ushort *)symtab_record_new_4();
      do {
        pcVar19 = ref->sym;
        if (((((pcVar19 == (c1_symbol *)0x0) || (bVar9 = pcVar19->kind & 0x1f, bVar9 == 0x10)) ||
             (bVar9 == 7)) || ((bVar9 == 6 || (bVar9 == 0x11)))) || (bVar9 == 8)) {
          array = (ushort *)vector_find_or_add((short *)array,(int)pcVar19);
        }
        ref = ref->next;
      } while (ref != (c1_symbol_cell *)0x0);
      uVar12 = counted_array_count(array);
      iVar20 = il_buffer_reserve(&buf->bytes,4);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        if ((uVar12 & 0xff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar12;
          puVar26 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar27 = (ushort *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar27;
          *puVar27 = uVar12;
          puVar26 = (buf->bytes).pbEnd + 2;
        }
        (buf->bytes).pbEnd = puVar26;
      }
      if (0 < (short)uVar12) {
        vector_iterator_init((c1_vector_iterator *)&stack0x00000050,array);
        cVar10 = vector_iter_next((int *)&stack0x00000050);
        while (cVar10 != '\0') {
          if (in_stack_00000058 == 0) {
            if (g_c9il_mode == '\0') {
              iVar20 = il_buffer_reserve(&buf->bytes,4);
              bVar9 = buf->open & (byte)iVar20 & 1;
              buf->open = bVar9;
              if (bVar9 != 0) {
                *(buf->bytes).pbEnd = 0x80;
                puVar26 = (buf->bytes).pbEnd + 1;
                (buf->bytes).pbEnd = puVar26;
                *puVar26 = '\0';
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
            }
            else {
              il_buffer_put_id(buf,0);
            }
          }
          else {
            uVar21 = *(uint *)(in_stack_00000058 + 0x1c);
            uVar30 = uVar21 & 0xffffff;
            if (g_c9il_mode == '\0') {
              iVar20 = il_buffer_reserve(&buf->bytes,4);
              bVar9 = buf->open & (byte)iVar20 & 1;
              buf->open = bVar9;
              if (bVar9 != 0) {
                if (uVar30 < 0x3fff80) {
                  if (uVar30 < 0x4000) {
                    *(buf->bytes).pbEnd = (byte)uVar21 & 0x3f | 0x80;
                    puVar26 = (buf->bytes).pbEnd + 1;
                    (buf->bytes).pbEnd = puVar26;
                    *puVar26 = (uchar)(uVar30 >> 6);
                    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                  }
                  else {
                    *(buf->bytes).pbEnd = (byte)uVar21 | 0xc0;
                    puVar26 = (buf->bytes).pbEnd + 1;
                    (buf->bytes).pbEnd = puVar26;
                    *puVar26 = (uchar)(uVar30 >> 6);
                    puVar26 = (buf->bytes).pbEnd + 1;
                    (buf->bytes).pbEnd = puVar26;
                    *puVar26 = (uchar)(uVar30 >> 0xe);
                    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                  }
                }
                else {
                  *(buf->bytes).pbEnd = (char)uVar30 + 0x80;
                  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                }
              }
            }
            else {
              cVar11 = il_buffer_reserve_ok(buf,4);
              if (cVar11 != '\0') {
                if (uVar30 < 0x8000) {
                  *(short *)(buf->bytes).pbEnd = (short)uVar30;
                  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
                }
                else {
                  *(uint *)(buf->bytes).pbEnd =
                       (uint)((uint3)(uVar21 >> 8) & 0xffc0 | 0x40) << 9 | uVar21 & 0x7fff;
                  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
                }
              }
            }
          }
          cVar10 = vector_iter_next((int *)&stack0x00000050);
        }
      }
      vector_release((int)array);
      pcVar19 = sym_arg;
    }
  }
switchD_1060184c_caseD_12:
  sym_00 = pcVar19;
  iVar6 = record_class;
  iVar16 = g_function_ex_offset;
  iVar20 = g_function_formal_count;
  puVar15 = (uchar *)g_source_file_ni;
  uVar21 = g_cv_precomp_signature;
  cVar10 = *codes;
  if (cVar10 == '\0') {
    if ((g_c9il_mode == '\0') && (sym_00 != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym_00->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym_00->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (iVar6 == 0xe)) {
        uVar21 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        puVar26 = g_il_gi_fdef.bytes.pbEnd;
        puVar22 = (PB)(uVar21 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar22;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.pbEnd = rec_word0;
          *(uint *)(puVar26 + 4) = rec_word1;
          *(uint *)(puVar26 + 8) = _rec_fflags;
          puVar22 = g_il_gi_fdef.bytes.pbEnd + 0xc;
          g_il_gi_fdef.bytes.pbEnd = puVar22;
        }
        ilstore_put_record(&g_il_gi_fdef,sym_00->key_ref >> 3,
                           CONCAT31((int3)((uint)puVar22 >> 8),(sym_00->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  codes = codes + 1;
  pcVar19 = sym_00;
  switch(cVar10) {
  case '\x01':
    bVar9 = sym_00->kind & 0x1f;
    if (((bVar9 == 7) || (bVar9 == 8)) || (bVar9 == 6)) {
      value = (c1_symbol_cell *)type_size(base_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar9 = sym_00->kind & 0x1f;
        if (bVar9 == 0xb) {
          type_check_size_known(type);
        }
        else if (bVar9 == 0xc) {
          il_emit_symbol_part(type,0,sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,
                              basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,
                              rec_fflags,rec_fflags_high,record_class,sym_arg);
          return;
        }
      }
    }
    if ((((sym_00->flags3 & 4) != 0) && ((type->code & 0x200) != 0)) &&
       ((((type->extra).sym)->flags4 & 1) != 0)) {
      il_emit_symbol_fragment
                ((uint)value,sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,
                 basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,
                 rec_fflags_high,record_class,sym_arg);
      return;
    }
    break;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar9 = sym_00->flags4;
      if (((((bVar9 & 0x80) == 0) || (bVar23 = sym_00->kind & 0x1f, bVar23 == 7)) || (bVar23 == 8))
         || (bVar23 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar23 = sym_00->kind & 0x1f;
      if (((bVar23 == 7) || (bVar23 == 8)) || (bVar23 == 6)) {
        if ((bVar9 & 2) != 0) {
          rec_word0 = rec_word0 | 0x100;
        }
        if ((sym_00->flags22 & 1) != 0) {
          rec_word0 = rec_word0 | 0x400;
        }
        if (((sym_00->x2c).function_flags & 1) != 0) {
          rec_word0 = rec_word0 | 0x80;
        }
      }
      if ((sym_00->key_ref & 3) != 0) {
        if (((bVar23 == 10) || (bVar23 == 0xb)) && ((bVar9 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar23 != 7) && (bVar23 != 8)) && (bVar23 != 6)) {
          rec_word0 = rec_word0 | 0x100;
        }
      }
      if ((sym_00->flags3 & 8) != 0) {
        rec_word0 = rec_word0 | 0x400;
      }
      switch(elem_flag_bits & 7) {
      case 3:
        rec_word0 = rec_word0 | 4;
        break;
      case 4:
        rec_word0 = rec_word0 | 0x18;
        break;
      case 5:
        if (((derived_type == (c1_type *)0x0) || ((derived_type->code & 0x83) != 0x81)) ||
           ((derived_type->flags & 0x8000) == 0)) {
          rec_word0 = rec_word0 | 0x10;
        }
        break;
      case 6:
        rec_word0 = rec_word0 | 0x14;
      }
      if (((bVar23 == 7) || (bVar23 == 8)) || (bVar23 == 6)) {
        if ((sym_00->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((sym_00->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((sym_00->flags22 & 2) != 0) && (bVar23 != 7)) && (bVar23 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar23 == 10) && ((sym_00->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((sym_00->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((sym_00->flags3 & 4) == 0)) {
          pcVar13 = sym_00->type;
          cVar10 = (char)pcVar13->code;
          while (cVar10 < '\0') {
            pcVar13 = pcVar13->base;
            cVar10 = (char)pcVar13->code;
          }
          if ((pcVar13->flags & 0x18) != 0) goto LAB_106016e1;
        }
        if ((sym_00->flags22 & 8) == 0) {
          rec_word0 = rec_word0 | 0x20;
        }
      }
LAB_106016e1:
      il_emit_symbol_reference(buf,sym_00,rec_word0);
    }
    else {
      il_emit_symbol_reference(buf,sym_00,rec_word0);
    }
    goto switchD_1060184c_caseD_12;
  case '\x03':
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = (uchar)record_class;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x04':
    if (is_array == 0) {
      value = (c1_symbol_cell *)0x0;
    }
    else {
      value = (c1_symbol_cell *)sym_element_size(sym_00);
    }
    iVar20 = il_buffer_reserve(&buf->bytes,6);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if ((bVar9 != 0) &&
       (iVar20 = il_buffer_put_byte7(buf,(uint)value), pcVar19 = sym_arg, (char)iVar20 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym_00->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(sym_00);
        goto LAB_106018ae;
      }
      uVar21 = sym_00->key_ref >> 3;
    }
    else {
      uVar21 = sym_00->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar21);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      bVar9 = (byte)uVar21;
      if (uVar21 < 0x3fff80) {
        if (uVar21 < 0x4000) {
          *(buf->bytes).pbEnd = bVar9 & 0x3f | 0x80;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar21 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar19 = sym_00;
        }
        else {
          *(buf->bytes).pbEnd = bVar9 | 0xc0;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar21 >> 6);
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar21 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar19 = sym_00;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar9 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar20 = il_buffer_reserve(&buf->bytes,6);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if ((bVar9 != 0) &&
         (iVar20 = il_buffer_put_byte7(buf,0), pcVar19 = sym_arg, (char)iVar20 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\0';
        puVar26[1] = '\0';
        puVar26[2] = '\0';
        puVar26[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar19 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar9 = sym_00->kind & 0x1f;
    if ((((bVar9 != 0) && (bVar9 < 0xf)) && (bVar9 != 5)) &&
       (((sym_00->flags23 & 1) != 0 &&
        (pvVar18 = sym_segment_record(sym_00), *(void **)((int)pvVar18 + 8) == g_name_drectve)))) {
      il_emit_symbol_fragment_2
                (sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array,
                 codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    if ((sym_00->kind & 0x1f) == 4) {
      value = (sym_00->x2c).references;
LAB_10601955:
      if (value != (c1_symbol_cell *)0x0) break;
    }
    else if ((sym_00->type->code & 0x300) != 0) {
      value = (c1_symbol_cell *)((sym_00->type->extra).tag)->debug_index;
      goto LAB_10601955;
    }
    value = (c1_symbol_cell *)type->debug_index;
    break;
  case '\a':
    cVar11 = g_il_block_level;
    if (record_class == 3) {
      cVar11 = (sym_00->x28).bytes.bit_position;
    }
    goto LAB_10601974;
  case '\b':
    bVar9 = sym_00->kind & 0x1f;
    if (bVar9 == 9) {
      bVar9 = *(byte *)&sym_00->detail;
    }
    else if ((sym_00->flags3 & 8) == 0) {
      if ((bVar9 == 10) && ((sym_00->storage & 7) == 3)) {
        bVar9 = 0x24;
      }
      else {
        bVar9 = 0;
      }
    }
    else {
      bVar9 = -((sym_00->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((sym_00->name == (fe_name *)0x0) || (sym_00->name == g_name_unnamed)) goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(sym_00);
    uVar21 = 0xffffffff;
    puVar24 = src;
    do {
      if (uVar21 == 0) break;
      uVar21 = uVar21 - 1;
      uVar30 = *puVar24;
      puVar24 = (uint *)((int)puVar24 + 1);
    } while ((char)uVar30 != '\0');
    cVar11 = il_buffer_reserve_ok(buf,~uVar21);
    pcVar19 = sym_arg;
    if (cVar11 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar21);
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar9 = sym_00->flags4;
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar23 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar23;
    pcVar19 = sym_arg;
    if (bVar23 != 0) {
      *(buf->bytes).pbEnd = ((bVar9 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar9 = sym_00->kind & 0x1f;
    if ((bVar9 == 0xb) || (bVar9 == 0xc)) {
      iVar20 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar9 = sym_00->storage & 7;
    if ((bVar9 != 0) && (bVar9 < 4)) {
      pcVar13 = type;
      if ((type->code & 0x8f) == 0x83) {
        pcVar13 = type_skip_arrays(type->base);
      }
      if (((byte)pcVar13->flags >> 5 & 1) == 0) {
        if (((((sym_00->flags3 & 8) == 0) || ((sym_00->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((sym_00->flags23 & 1) != 0 &&
             (pbVar17 = sym_segment_record(sym_00), (*pbVar17 & 0x1f) == 0xe)) &&
            (pvVar18 = sym_segment_record(sym_00), (*(uint *)((int)pvVar18 + 0x1c) & 0xffffff) != 3)
            ))) {
          iVar20 = il_buffer_reserve(&buf->bytes,2);
          bVar9 = buf->open & (byte)iVar20 & 1;
          buf->open = bVar9;
          pcVar19 = sym_arg;
          if (bVar9 != 0) {
            *(buf->bytes).pbEnd = '\x02';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar19 = sym_00;
          }
          goto switchD_1060184c_caseD_12;
        }
      }
      else if ((sym_00->flags23 & 1) != 0) {
        il_emit_symbol_fragment_3
                  (sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,
                   is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,
                   record_class,sym_arg);
        return;
      }
      iVar20 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\r':
    if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
      uVar12 = base_type->code;
      cVar10 = (char)uVar12;
      if ((cVar10 < '\0') && (base_type != (c1_type *)0x0)) {
        uVar28 = base_type->flags;
      }
      else {
        uVar12 = 0;
        uVar28 = 0;
      }
      uVar21 = 0;
      pcVar13 = base_type;
      while (cVar10 < '\0') {
        pcVar13 = pcVar13->base;
        cVar10 = (char)pcVar13->code;
      }
      basic_code = pcVar13->code;
      pcVar13 = base_type;
    }
    else {
      if (derived_type == (c1_type *)0x0) {
        uVar12 = 0;
        uVar28 = 0;
      }
      else {
        uVar12 = derived_type->code;
        uVar28 = derived_type->flags;
      }
      pcVar13 = type;
      if ((basic_code & 0x200) == 0) {
LAB_10601c71:
        uVar21 = 0;
      }
      else {
        if (basic_code != 0x203) {
          pcVar2 = sym_arg->type;
          cVar10 = (char)pcVar2->code;
          while (cVar10 < '\0') {
            pcVar2 = pcVar2->base;
            cVar10 = (char)pcVar2->code;
          }
          if ((pcVar2->code & 0x300) == 0) {
            pcVar19 = (c1_symbol *)0x0;
          }
          else {
            pcVar19 = (pcVar2->extra).sym;
          }
          if ((pcVar19->tag_alignment & 0x100) == 0) goto LAB_10601c71;
        }
        uVar21 = 0x10;
      }
    }
    if ((uVar28 & 0x100) != 0) {
      uVar21 = uVar21 | 0x4000;
    }
    if ((uVar28 & 0x40) != 0) {
      uVar21 = uVar21 | 0x1000;
    }
    uVar12 = uVar12 & 0x8f;
    if (uVar12 == 0x83) {
      uVar21 = uVar21 | 6;
    }
    else if (((uVar12 == 0x82) || (uVar12 == 0x86)) || (uVar12 == 0x80)) {
      uVar21 = uVar21 | 3;
    }
    else {
      uVar12 = pcVar13->code;
      if ((uVar12 & 0x2000) == 0) {
        if ((((g_ms_extensions == '\0') && ((uVar12 & 0xfff) == 0x11)) && ((uVar12 & 0x1000) == 0))
           && (g_opt_J_unsigned_char != '\0')) {
          il_emit_symbol_fragment_5
                    (uVar21,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,
                     is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,
                     record_class,sym_arg);
          return;
        }
        uVar30 = (uint)basic_code;
        if (uVar30 < 0x104) {
          if (uVar30 != 0x103) {
            switch(uVar30) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
              goto switchD_10601d6d_caseD_11;
            default:
code_r0x10601daf:
              if ((0x18 < uVar30) && (uVar30 < 0x1e)) goto switchD_10601d6d_caseD_11;
              break;
            case 0x26:
            case 0x27:
            case 0x28:
              uVar21 = uVar21 | 5;
              break;
            case 0x40:
              uVar21 = uVar21 | 7;
            }
            goto LAB_10601ca3;
          }
        }
        else {
          if (uVar30 < 0x403) {
            if (uVar30 != 0x402) {
              if ((uVar30 < 0x201) || (0x203 < uVar30)) goto code_r0x10601daf;
              uVar21 = uVar21 | 6;
              goto LAB_10601ca3;
            }
            goto code_r0x10601d74;
          }
          if (uVar30 != 0x1011) {
            il_emit_symbol_record_fragment
                      (uVar30,uVar21,buf,fdef_mode,type,derived_type,stored_record,base_type,
                       basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,
                       rec_fflags_high,record_class,sym_arg);
            return;
          }
        }
switchD_10601d6d_caseD_11:
        uVar21 = uVar21 | 1;
      }
      else {
code_r0x10601d74:
        uVar21 = uVar21 | 2;
      }
    }
LAB_10601ca3:
    if (0x7f < (ushort)uVar21) {
      iVar20 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = (byte)(uVar21 >> 8) | 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0e':
    cVar5 = sym_00->key_ref;
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar5 & 3);
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0f':
    name = sym_00->detail;
    if ((name != (fe_name *)0x0) && (name != g_name_unnamed)) {
      func_report_static_not_defined
                (name,buf,fdef_mode,type,derived_type,(int)stored_record,base_type,basic_code,
                 is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,record_class,sym_arg);
      return;
    }
LAB_10601a0e:
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((sym_00->flags22 & 4) == 0) || (record_class == 7)) {
      if (((sym_00->flags22 & 8) == 0) || (record_class == 7)) {
        if ((sym_00->storage & 0x40) == 0) {
          bVar9 = sym_00->storage & 7;
          if (((bVar9 < 4) || (6 < bVar9)) && (bVar9 != 3)) {
            if ((sym_00->flags3 & 4) == 0) {
              if (bVar9 == 1) goto LAB_10601e86;
              if ((is_array == 0) || (bVar9 = 2, (derived_type->extra).sym != (c1_symbol *)0x0)) {
                bVar9 = 3;
              }
            }
            else {
              bVar9 = 1;
            }
          }
          else {
            bVar9 = 4;
          }
        }
        else {
          bVar9 = (~sym_00->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar9 = 8;
      }
    }
    else if ((sym_00->flags1 & 1) == 0) {
LAB_10601e86:
      bVar9 = 2;
    }
    else {
      bVar9 = (-((sym_00->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar23 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar23;
    pcVar19 = sym_arg;
    if (bVar23 != 0) {
      *(buf->bytes).pbEnd = bVar9;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar9 = sym_00->kind & 0x1f;
    if ((((bVar9 == 7) || (bVar9 == 8)) || (bVar9 == 6)) && ((sym_00->flags1 & 1) != 0)) {
      if ((sym_00->flags22 & 4) == 0) {
        if ((sym_00->flags22 & 8) == 0) {
          if ((sym_00->storage & 0x40) == 0) {
            cVar11 = (-((sym_00->storage & 7) != 3) & 2U) + 3;
          }
          else {
            cVar11 = '\x05';
          }
        }
        else {
          cVar11 = '\n';
        }
      }
      else {
        cVar11 = '\t';
      }
    }
    else {
      bVar9 = sym_00->storage & 7;
      if ((bVar9 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
        diag_error(0x81,sym_00);
        cVar11 = '\x02';
      }
      else {
        if (((sym_00->flags21 & 1) != 0) && (bVar9 != 1)) {
          func_check_inline_definitions
                    (sym_00,buf,fdef_mode,type,derived_type,base_type,basic_code,is_array,codes,
                     elem_flag_bits,rec_word0,rec_word1,rec_fflags,record_class,sym_arg);
          return;
        }
        cVar11 = (-((sym_00->flags22 & 8) != 0) & 6U) + 4;
      }
    }
LAB_10601974:
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = cVar11;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar20 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar20 = (sym_00->x28).value;
    if ((iVar20 < 0x8000) && (-0x8001 < iVar20)) {
      bVar9 = 1;
    }
    else {
      bVar9 = 0;
    }
    sVar31 = (-(ushort)bVar9 & 0xfffe) + 4;
    iVar16 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar16 & 1;
    buf->open = bVar9;
    if ((bVar9 != 0) && (iVar16 = il_buffer_put_byte7(buf,(int)sVar31), (char)iVar16 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar25 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar25;
      *psVar25 = sVar31;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar16 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar16 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar20;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar16 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar16 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar20 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar20) || (pcVar19 = sym_arg, iVar20 < -0x8000)) {
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar20 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar20 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar19 = decl_lookup_file_scope_twin(sym_00);
    if (g_c9il_mode == '\0') {
      if ((pcVar19->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(pcVar19);
        goto LAB_10638f6a;
      }
      uVar21 = pcVar19->key_ref >> 3;
    }
    else {
      uVar21 = pcVar19->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      bVar9 = (byte)uVar21;
      if (uVar21 < 0x3fff80) {
        if (uVar21 < 0x4000) {
          *(buf->bytes).pbEnd = bVar9 & 0x3f | 0x80;
          goto LAB_10638fd8;
        }
        *(buf->bytes).pbEnd = bVar9 | 0xc0;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *puVar26 = (uchar)(uVar21 >> 6);
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *puVar26 = (uchar)(uVar21 >> 0xe);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_arg;
      }
      else {
        *(buf->bytes).pbEnd = bVar9 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_arg;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar19 = sym_segment_record(sym_00);
    if (g_c9il_mode == '\0') {
      if ((pcVar19->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(pcVar19);
        goto LAB_1063904f;
      }
      uVar21 = pcVar19->key_ref >> 3;
LAB_10639060:
      iVar20 = il_buffer_reserve(&buf->bytes,4);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        bVar9 = (byte)uVar21;
        if (uVar21 < 0x3fff80) {
          if (uVar21 < 0x4000) {
            *(buf->bytes).pbEnd = bVar9 & 0x3f | 0x80;
LAB_10638fd8:
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar19 = sym_arg;
          }
          else {
            *(buf->bytes).pbEnd = bVar9 | 0xc0;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 6);
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar19 = sym_arg;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar9 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar19 = sym_arg;
        }
      }
    }
    else {
      uVar21 = pcVar19->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar21);
      pcVar19 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar8 = (sym_00->x28).bytes.bit_position;
    if ((uVar8 != '\0') && (uVar8 != '\x02')) {
      uVar8 = (-(uVar8 != '\x03') & 0xfeU) + 3;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,2);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = uVar8;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    stored_record = (uint *)g_function_ex_offset;
    uVar21 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar20 = il_buffer_reserve(&buf->bytes,6);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        if ((iVar16 & 0xffffff80U) == 0) {
          *(buf->bytes).pbEnd = (uchar)iVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          piVar29 = (int *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)piVar29;
          *piVar29 = iVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
      iVar20 = il_buffer_reserve(&buf->bytes,6);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        if ((uVar21 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar21;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar19 = sym_00;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar24 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar24;
          *puVar24 = uVar21;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar19 = sym_00;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x19':
    if (fdef_mode == '\0') {
      rec_word1 = CONCAT22(rec_word1._2_2_,0xffff);
      if (g_function_tuple_count < 0x10000) {
        rec_word1 = CONCAT22(rec_word1._2_2_,(short)g_function_tuple_count);
      }
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1a':
    if (fdef_mode == '\0') {
      if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
        sVar31 = 0;
      }
      else {
        sVar31 = 0x1000;
      }
      _rec_fflags = (int)(short)(((ushort)(sym_00->flags21 & 8) << 3 | (ushort)(sym_00->flags21 & 1)
                                 ) << 7) | (sym_00->flags4 & 0x80) >> 5 |
                    (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
                    (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                    (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar31;
      uVar12 = *(ushort *)(((uint)sym_00->type & -(uint)((sym_00->type->code & 0x80) != 0)) + 2);
      if (((uVar12 & 0x2000) != 0) && ((uVar12 & 0x4000) == 0)) {
        g_function_not_inlinable = 1;
      }
      if (g_inline_level == 1) {
LAB_10602124:
        if (g_function_not_inlinable == 0) {
LAB_10602128:
          if ((sym_00->type->flags & 0x8000) == 0) {
            if ((sym_00->flags21 & 1) != 0) {
              _rec_fflags = _rec_fflags | 0x40;
            }
            goto LAB_1060213d;
          }
        }
LAB_10602193:
        _rec_fflags = (int)(short)_rec_fflags & 0xffffffbf;
        if ((sym_00->flags21 & 1) != 0) {
          func_emit_inline_candidate
                    (_rec_fflags,sym_00,buf,'\0',type,derived_type,base_type,basic_code,is_array,
                     codes,elem_flag_bits,rec_word0,rec_word1,record_class,sym_arg);
          return;
        }
      }
      else if (g_inline_level == 2) {
        if (g_function_auto_inline == 0) goto LAB_10602124;
        if (g_function_not_inlinable == 0) {
          if ((((sym_00->storage & 7) == 3) && (((byte)sym_00->key_ref & 3) == 1)) ||
             (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
            _rec_fflags = _rec_fflags | 0x40;
          }
          goto LAB_10602128;
        }
        goto LAB_10602193;
      }
LAB_1060213d:
      iVar20 = il_buffer_reserve(&buf->bytes,5);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        if (_rec_fflags < 0x8000) {
          *(short *)(buf->bytes).pbEnd = (short)_rec_fflags;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
        else {
          *(uint *)(buf->bytes).pbEnd = _rec_fflags | 0x8000;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
    }
    else {
      iVar20 = il_buffer_reserve(&buf->bytes,5);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        if ((int)_rec_fflags < 0x8000) {
          *(ushort *)(buf->bytes).pbEnd = rec_fflags;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          pcVar19 = sym_00;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(_rec_fflags >> 8) & 0xffffc0 | 0x40) << 9 | _rec_fflags & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar19 = sym_00;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x1c':
  case '\x1d':
    stored_record = (uint *)0x386;
    iVar20 = il_buffer_reserve(&buf->bytes,3);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      puVar26[0] = 0x86;
      puVar26[1] = '\x03';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar20 = il_buffer_reserve(&buf->bytes,5);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      puVar26[0] = 0x96;
      puVar26[1] = 0xba;
      puVar26[2] = '0';
      puVar26[3] = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case ' ':
    iVar20 = 2;
LAB_10602252:
    iVar20 = il_buffer_reserve(&buf->bytes,iVar20);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar20 = il_buffer_reserve(&buf->bytes,6);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      if ((uVar21 & 0xffffff80) == 0) {
        *(buf->bytes).pbEnd = (uchar)uVar21;
        puVar26 = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = 0x80;
        puVar24 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar24;
        *puVar24 = uVar21;
        puVar26 = (buf->bytes).pbEnd + 4;
      }
      (buf->bytes).pbEnd = puVar26;
    }
    puVar15 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar20 = il_buffer_reserve(&buf->bytes,2);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = '\0';
        puVar26 = (buf->bytes).pbEnd + 1;
LAB_106022da:
        (buf->bytes).pbEnd = puVar26;
      }
    }
    else {
      uVar21 = 0xffffffff;
      pcVar33 = g_il_pch_name;
      do {
        if (uVar21 == 0) break;
        uVar21 = uVar21 - 1;
        cVar10 = *pcVar33;
        pcVar33 = pcVar33 + 1;
      } while (cVar10 != '\0');
      uVar21 = ~uVar21;
      iVar20 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        puVar26 = (buf->bytes).pbEnd;
        for (uVar30 = uVar21 >> 2; uVar30 != 0; uVar30 = uVar30 - 1) {
          *(undefined4 *)puVar26 = *(undefined4 *)puVar15;
          puVar15 = puVar15 + 4;
          puVar26 = puVar26 + 4;
        }
        for (uVar30 = uVar21 & 3; uVar30 != 0; uVar30 = uVar30 - 1) {
          *puVar26 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar26 = puVar26 + 1;
        }
        puVar26 = (buf->bytes).pbEnd + uVar21;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar20 = il_buffer_reserve(&buf->bytes,6);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pcVar19 = sym_arg;
      if (bVar9 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar19 = sym_arg;
      }
    }
    else {
      uVar21 = 0;
      pfVar7 = (fe_pragma_comment *)0x0;
      pfVar4 = g_pragma_comment_list;
      while (g_pragma_comment_list = pfVar7, pfVar4 != (fe_pragma_comment *)0x0) {
        pfVar3 = pfVar4->next;
        pfVar4->next = g_pragma_comment_list;
        uVar21 = uVar21 + 1;
        pfVar7 = pfVar4;
        pfVar4 = pfVar3;
      }
      iVar20 = il_buffer_reserve(&buf->bytes,6);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      pfVar4 = g_pragma_comment_list;
      if (bVar9 != 0) {
        if ((uVar21 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar21;
          puVar26 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar24 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar24;
          *puVar24 = uVar21;
          puVar26 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar26;
        pfVar4 = g_pragma_comment_list;
      }
      for (; pcVar19 = sym_arg, stored_record = (uint *)pfVar4, pfVar4 != (fe_pragma_comment *)0x0;
          pfVar4 = pfVar4->next) {
        puVar15 = (uchar *)pfVar4->text;
        iVar20 = pfVar4->kind;
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar9 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar9;
        if (bVar9 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar20;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar4->kind == 7) {
          if ((uchar)(*puVar15 + '\x01') != '\0') {
            stored_record = (uint *)(int)(char)(*puVar15 + '\x01');
            do {
              uVar8 = *puVar15;
              iVar20 = il_buffer_reserve(&buf->bytes,2);
              bVar9 = buf->open & (byte)iVar20 & 1;
              buf->open = bVar9;
              if (bVar9 != 0) {
                *(buf->bytes).pbEnd = uVar8;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar15 = puVar15 + 1;
              stored_record = (uint *)((int)stored_record + -1);
            } while (stored_record != (uint *)0x0);
          }
        }
        else {
          uVar21 = 0xffffffff;
          puVar32 = puVar15;
          do {
            if (uVar21 == 0) break;
            uVar21 = uVar21 - 1;
            uVar8 = *puVar32;
            puVar32 = puVar32 + 1;
          } while (uVar8 != '\0');
          uVar21 = ~uVar21;
          iVar20 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
          bVar9 = buf->open & (byte)iVar20 & 1;
          buf->open = bVar9;
          if (bVar9 != 0) {
            puVar26 = (buf->bytes).pbEnd;
            for (uVar30 = uVar21 >> 2; uVar30 != 0; uVar30 = uVar30 - 1) {
              *(undefined4 *)puVar26 = *(undefined4 *)puVar15;
              puVar15 = puVar15 + 4;
              puVar26 = puVar26 + 4;
            }
            for (uVar30 = uVar21 & 3; uVar30 != 0; uVar30 = uVar30 - 1) {
              *puVar26 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar26 = puVar26 + 1;
            }
            ppuVar1 = &(buf->bytes).pbEnd;
            *ppuVar1 = *ppuVar1 + uVar21;
          }
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\"':
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar14 = &g_line_map_cached_row;
    }
    else {
      pfVar14 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    sym_keys = pfVar14->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar21 = sym_keys->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym_keys->entity = uVar21 & 0xffffff ^ sym_keys->entity;
    uVar21 = il_symbol_key_2((int)sym_keys);
    if (g_c9il_mode == '\0') {
      iVar20 = il_buffer_reserve(&buf->bytes,4);
      bVar9 = buf->open & (byte)iVar20 & 1;
      buf->open = bVar9;
      if (bVar9 != 0) {
        bVar9 = (byte)uVar21;
        if (uVar21 < 0x3fff80) {
          if (uVar21 < 0x4000) {
            *(buf->bytes).pbEnd = bVar9 & 0x3f | 0x80;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar9 | 0xc0;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 6);
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar9 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar21);
    }
    puVar15 = (uchar *)pp_position_file_name(&g_token_position);
    uVar21 = 0xffffffff;
    puVar32 = puVar15;
    do {
      if (uVar21 == 0) break;
      uVar21 = uVar21 - 1;
      uVar8 = *puVar32;
      puVar32 = puVar32 + 1;
    } while (uVar8 != '\0');
    uVar21 = ~uVar21;
    iVar20 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      for (uVar30 = uVar21 >> 2; uVar30 != 0; uVar30 = uVar30 - 1) {
        *(undefined4 *)puVar26 = *(undefined4 *)puVar15;
        puVar15 = puVar15 + 4;
        puVar26 = puVar26 + 4;
      }
      for (uVar30 = uVar21 & 3; uVar30 != 0; uVar30 = uVar30 - 1) {
        *puVar26 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar26 = puVar26 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar21;
      pcVar19 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '#':
    iVar16 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar16 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      iVar16 = il_buffer_put_byte7(buf,(int)(short)iVar20);
      pcVar19 = sym_arg;
      if ((char)iVar16 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar25 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar25;
        *psVar25 = (short)iVar20;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar19 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar21 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar21 = g_next_entity_id;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,5);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '&':
    uVar21 = 0xffffffff;
    pcVar33 = (char *)g_source_file_ni;
    do {
      if (uVar21 == 0) break;
      uVar21 = uVar21 - 1;
      cVar10 = *pcVar33;
      pcVar33 = pcVar33 + 1;
    } while (cVar10 != '\0');
    uVar21 = ~uVar21;
    iVar20 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      for (uVar30 = uVar21 >> 2; uVar30 != 0; uVar30 = uVar30 - 1) {
        *(undefined4 *)puVar26 = *(undefined4 *)puVar15;
        puVar15 = puVar15 + 4;
        puVar26 = puVar26 + 4;
      }
      for (uVar30 = uVar21 & 3; uVar30 != 0; uVar30 = uVar30 - 1) {
        *puVar26 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar26 = puVar26 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar21;
      pcVar19 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_2
                (sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array,
                 codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_3
                (sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array,
                 codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case '*':
    uVar21 = 2;
    if (g_c9il_mode == '\0') {
      uVar21 = 3;
    }
    if (g_dlp != '\0') {
      uVar21 = uVar21 | 8;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,5);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    if (bVar9 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    if ((bVar9 != 0) && (iVar20 = il_buffer_put_byte7(buf,0xc), (char)iVar20 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar26 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar26;
      puVar26[0] = '\f';
      puVar26[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    if ((bVar9 != 0) && (iVar20 = il_buffer_put_byte7(buf,0), (char)iVar20 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar26 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar26;
      puVar26[0] = '\0';
      puVar26[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar20 = il_buffer_reserve(&buf->bytes,4);
    bVar9 = buf->open & (byte)iVar20 & 1;
    buf->open = bVar9;
    pcVar19 = sym_arg;
    if (bVar9 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
      pcVar19 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    goto switchD_1060184c_caseD_2e;
  }
  iVar20 = il_buffer_reserve(&buf->bytes,6);
  bVar9 = buf->open & (byte)iVar20 & 1;
  buf->open = bVar9;
  pcVar19 = sym_arg;
  if ((bVar9 != 0) &&
     (iVar20 = il_buffer_put_byte7(buf,(uint)value), pcVar19 = sym_arg, (char)iVar20 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar26 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar26;
    *(c1_symbol_cell **)puVar26 = value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    pcVar19 = sym_00;
  }
  goto switchD_1060184c_caseD_12;
switchD_1060184c_caseD_2e:
  if (g_opt_Ct != '\0') {
    il_emit_symbol_inline_fragment
              (sym_00,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array,
               codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
               sym_arg);
    return;
  }
  goto switchD_1060184c_caseD_12;
}

