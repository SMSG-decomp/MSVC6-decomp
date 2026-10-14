void __cdecl
func_report_static_not_defined
          (void *name,fe_il_buffer *buf,char fdef_mode,c1_type *sym_type,c1_type *derived_type,
          int part,c1_type *elem_type,ushort base_code,int is_array,char *format,uint storage_bits,
          uint rec_word0,uint rec_word1,ushort rec_word2,int record_class,c1_symbol *record_sym)

{
  PB *ppuVar1;
  char cVar2;
  c1_type *pcVar3;
  fe_name *name_00;
  fe_pragma_comment *pfVar4;
  fe_file_record *sym_keys;
  fe_pragma_comment *pfVar5;
  c1_u32 cVar6;
  fe_pragma_comment *pfVar7;
  c1_u8 cVar8;
  uchar uVar9;
  c1_symbol_cell *value;
  uint *src;
  c1_type *pcVar10;
  fe_line_map_row *pfVar11;
  uchar *puVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  void *pvVar16;
  c1_symbol *pcVar17;
  PB puVar18;
  byte bVar19;
  byte bVar20;
  uint uVar21;
  uint uVar22;
  uint *puVar23;
  short *psVar24;
  uint uVar25;
  PB puVar26;
  ushort uVar27;
  int *piVar28;
  ushort uVar29;
  short sVar30;
  uchar *puVar31;
  char *pcVar32;
  ushort in_stack_00000042;
  
  puVar12 = *(uchar **)((int)name + 4);
LAB_10602472:
  uVar21 = 0xffffffff;
  puVar31 = puVar12;
  do {
    if (uVar21 == 0) break;
    uVar21 = uVar21 - 1;
    uVar9 = *puVar31;
    puVar31 = puVar31 + 1;
  } while (uVar9 != '\0');
  uVar21 = ~uVar21;
  iVar13 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
  bVar20 = buf->open & (byte)iVar13 & 1;
  buf->open = bVar20;
  uVar22 = _rec_word2;
  if (bVar20 != 0) {
    puVar26 = (buf->bytes).pbEnd;
    for (uVar22 = uVar21 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
      *(undefined4 *)puVar26 = *(undefined4 *)puVar12;
      puVar12 = puVar12 + 4;
      puVar26 = puVar26 + 4;
    }
    for (uVar22 = uVar21 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
      *puVar26 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar26 = puVar26 + 1;
    }
    ppuVar1 = &(buf->bytes).pbEnd;
    *ppuVar1 = *ppuVar1 + uVar21;
    uVar22 = _rec_word2;
  }
switchD_1060184c_caseD_12:
  _rec_word2 = uVar22;
  uVar22 = _rec_word2;
  iVar14 = g_function_ex_offset;
  iVar13 = g_function_formal_count;
  puVar12 = (uchar *)g_source_file_ni;
  uVar21 = g_cv_precomp_signature;
  cVar2 = *format;
  if (cVar2 == '\0') {
    if ((g_c9il_mode == '\0') && (record_sym != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,record_sym->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,record_sym->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (record_class == 0xe)) {
        uVar21 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        puVar26 = g_il_gi_fdef.bytes.pbEnd;
        puVar18 = (PB)(uVar21 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar18;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.pbEnd = rec_word0;
          *(uint *)(puVar26 + 4) = rec_word1;
          *(uint *)(puVar26 + 8) = _rec_word2;
          puVar18 = g_il_gi_fdef.bytes.pbEnd + 0xc;
          g_il_gi_fdef.bytes.pbEnd = puVar18;
        }
        ilstore_put_record(&g_il_gi_fdef,record_sym->key_ref >> 3,
                           CONCAT31((int3)((uint)puVar18 >> 8),(record_sym->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  format = format + 1;
  in_stack_00000042 = (ushort)(_rec_word2 >> 0x10);
  switch(cVar2) {
  case '\x01':
    bVar20 = record_sym->kind & 0x1f;
    if (((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) {
      value = (c1_symbol_cell *)type_size(elem_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(sym_type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar20 = record_sym->kind & 0x1f;
        if (bVar20 == 0xb) {
          type_check_size_known(sym_type);
        }
        else if (bVar20 == 0xc) {
          il_emit_symbol_part(sym_type,0,record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part
                              ,elem_type,base_code,is_array,format,storage_bits,rec_word0,rec_word1,
                              rec_word2,in_stack_00000042,record_class,record_sym);
          return;
        }
      }
    }
    if ((((record_sym->flags3 & 4) != 0) && ((sym_type->code & 0x200) != 0)) &&
       ((((sym_type->extra).sym)->flags4 & 1) != 0)) {
      il_emit_symbol_fragment
                ((uint)value,record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,
                 base_code,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,
                 in_stack_00000042,record_class,record_sym);
      return;
    }
    break;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar20 = record_sym->flags4;
      if (((((bVar20 & 0x80) == 0) || (bVar19 = record_sym->kind & 0x1f, bVar19 == 7)) ||
          (bVar19 == 8)) || (bVar19 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar19 = record_sym->kind & 0x1f;
      if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
        if ((bVar20 & 2) != 0) {
          rec_word0 = rec_word0 | 0x100;
        }
        if ((record_sym->flags22 & 1) != 0) {
          rec_word0 = rec_word0 | 0x400;
        }
        if (((record_sym->x2c).function_flags & 1) != 0) {
          rec_word0 = rec_word0 | 0x80;
        }
      }
      if ((record_sym->key_ref & 3) != 0) {
        if (((bVar19 == 10) || (bVar19 == 0xb)) && ((bVar20 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar19 != 7) && (bVar19 != 8)) && (bVar19 != 6)) {
          rec_word0 = rec_word0 | 0x100;
        }
      }
      if ((record_sym->flags3 & 8) != 0) {
        rec_word0 = rec_word0 | 0x400;
      }
      switch(storage_bits & 7) {
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
      if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
        if ((record_sym->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((record_sym->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((record_sym->flags22 & 2) != 0) && (bVar19 != 7)) && (bVar19 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar19 == 10) && ((record_sym->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((record_sym->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((record_sym->flags3 & 4) == 0)) {
          pcVar10 = record_sym->type;
          cVar2 = (char)pcVar10->code;
          while (cVar2 < '\0') {
            pcVar10 = pcVar10->base;
            cVar2 = (char)pcVar10->code;
          }
          if ((pcVar10->flags & 0x18) != 0) goto LAB_106016e1;
        }
        if ((record_sym->flags22 & 8) == 0) {
          rec_word0 = rec_word0 | 0x20;
        }
      }
LAB_106016e1:
      il_emit_symbol_reference(buf,record_sym,rec_word0);
    }
    else {
      il_emit_symbol_reference(buf,record_sym,rec_word0);
    }
    goto switchD_1060184c_caseD_12;
  case '\x03':
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = (uchar)record_class;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x04':
    if (is_array == 0) {
      value = (c1_symbol_cell *)0x0;
    }
    else {
      value = (c1_symbol_cell *)sym_element_size(record_sym);
    }
    iVar13 = il_buffer_reserve(&buf->bytes,6);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if ((bVar20 != 0) && (iVar13 = il_buffer_put_byte7(buf,(uint)value), (char)iVar13 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((record_sym->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(record_sym);
        goto LAB_106018ae;
      }
      uVar21 = record_sym->key_ref >> 3;
    }
    else {
      uVar21 = record_sym->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar21);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      bVar20 = (byte)uVar21;
      if (uVar21 < 0x3fff80) {
        if (uVar21 < 0x4000) {
          *(buf->bytes).pbEnd = bVar20 & 0x3f | 0x80;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar21 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar20 | 0xc0;
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
        *(buf->bytes).pbEnd = bVar20 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar13 = il_buffer_reserve(&buf->bytes,6);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if ((bVar20 != 0) && (iVar13 = il_buffer_put_byte7(buf,0), (char)iVar13 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\0';
        puVar26[1] = '\0';
        puVar26[2] = '\0';
        puVar26[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar20 = record_sym->kind & 0x1f;
    if ((((bVar20 != 0) && (bVar20 < 0xf)) && (bVar20 != 5)) &&
       (((record_sym->flags23 & 1) != 0 &&
        (pvVar16 = sym_segment_record(record_sym), *(void **)((int)pvVar16 + 8) == g_name_drectve)))
       ) {
      il_emit_symbol_fragment_2
                (record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    if ((record_sym->kind & 0x1f) == 4) {
      value = (record_sym->x2c).references;
LAB_10601955:
      if (value != (c1_symbol_cell *)0x0) break;
    }
    else if ((record_sym->type->code & 0x300) != 0) {
      value = (c1_symbol_cell *)((record_sym->type->extra).tag)->debug_index;
      goto LAB_10601955;
    }
    value = (c1_symbol_cell *)sym_type->debug_index;
    break;
  case '\a':
    cVar8 = g_il_block_level;
    if (record_class == 3) {
      cVar8 = (record_sym->x28).bytes.bit_position;
    }
    goto LAB_10601974;
  case '\b':
    bVar20 = record_sym->kind & 0x1f;
    if (bVar20 == 9) {
      bVar20 = *(byte *)&record_sym->detail;
    }
    else if ((record_sym->flags3 & 8) == 0) {
      if ((bVar20 == 10) && ((record_sym->storage & 7) == 3)) {
        bVar20 = 0x24;
      }
      else {
        bVar20 = 0;
      }
    }
    else {
      bVar20 = -((record_sym->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((record_sym->name == (fe_name *)0x0) || (record_sym->name == g_name_unnamed))
    goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(record_sym);
    uVar21 = 0xffffffff;
    puVar23 = src;
    do {
      if (uVar21 == 0) break;
      uVar21 = uVar21 - 1;
      uVar25 = *puVar23;
      puVar23 = (uint *)((int)puVar23 + 1);
    } while ((char)uVar25 != '\0');
    cVar8 = il_buffer_reserve_ok(buf,~uVar21);
    if (cVar8 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar21);
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar20 = record_sym->flags4;
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = ((bVar20 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar20 = record_sym->kind & 0x1f;
    if ((bVar20 == 0xb) || (bVar20 == 0xc)) {
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar20 = record_sym->storage & 7;
    if ((bVar20 != 0) && (bVar20 < 4)) {
      pcVar10 = sym_type;
      if ((sym_type->code & 0x8f) == 0x83) {
        pcVar10 = type_skip_arrays(sym_type->base);
      }
      if (((byte)pcVar10->flags >> 5 & 1) == 0) {
        if (((((record_sym->flags3 & 8) == 0) || ((record_sym->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((record_sym->flags23 & 1) != 0 &&
             (pbVar15 = sym_segment_record(record_sym), (*pbVar15 & 0x1f) == 0xe)) &&
            (pvVar16 = sym_segment_record(record_sym),
            (*(uint *)((int)pvVar16 + 0x1c) & 0xffffff) != 3)))) {
          iVar13 = il_buffer_reserve(&buf->bytes,2);
          bVar20 = buf->open & (byte)iVar13 & 1;
          buf->open = bVar20;
          if (bVar20 != 0) {
            *(buf->bytes).pbEnd = '\x02';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          goto switchD_1060184c_caseD_12;
        }
      }
      else if ((record_sym->flags23 & 1) != 0) {
        il_emit_symbol_fragment_3
                  (record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                   is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                   record_class,record_sym);
        return;
      }
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\r':
    if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
      uVar29 = elem_type->code;
      cVar2 = (char)uVar29;
      if ((cVar2 < '\0') && (elem_type != (c1_type *)0x0)) {
        uVar27 = elem_type->flags;
      }
      else {
        uVar29 = 0;
        uVar27 = 0;
      }
      uVar21 = 0;
      pcVar10 = elem_type;
      while (cVar2 < '\0') {
        pcVar10 = pcVar10->base;
        cVar2 = (char)pcVar10->code;
      }
      base_code = pcVar10->code;
      pcVar10 = elem_type;
    }
    else {
      if (derived_type == (c1_type *)0x0) {
        uVar29 = 0;
        uVar27 = 0;
      }
      else {
        uVar29 = derived_type->code;
        uVar27 = derived_type->flags;
      }
      pcVar10 = sym_type;
      if ((base_code & 0x200) == 0) {
LAB_10601c71:
        uVar21 = 0;
      }
      else {
        if (base_code != 0x203) {
          pcVar3 = record_sym->type;
          cVar2 = (char)pcVar3->code;
          while (cVar2 < '\0') {
            pcVar3 = pcVar3->base;
            cVar2 = (char)pcVar3->code;
          }
          if ((pcVar3->code & 0x300) == 0) {
            pcVar17 = (c1_symbol *)0x0;
          }
          else {
            pcVar17 = (pcVar3->extra).sym;
          }
          if ((pcVar17->tag_alignment & 0x100) == 0) goto LAB_10601c71;
        }
        uVar21 = 0x10;
      }
    }
    if ((uVar27 & 0x100) != 0) {
      uVar21 = uVar21 | 0x4000;
    }
    if ((uVar27 & 0x40) != 0) {
      uVar21 = uVar21 | 0x1000;
    }
    uVar29 = uVar29 & 0x8f;
    if (uVar29 == 0x83) {
      uVar21 = uVar21 | 6;
    }
    else if (((uVar29 == 0x82) || (uVar29 == 0x86)) || (uVar29 == 0x80)) {
      uVar21 = uVar21 | 3;
    }
    else {
      uVar29 = pcVar10->code;
      if ((uVar29 & 0x2000) == 0) {
        if ((((g_ms_extensions == '\0') && ((uVar29 & 0xfff) == 0x11)) && ((uVar29 & 0x1000) == 0))
           && (g_opt_J_unsigned_char != '\0')) {
          il_emit_symbol_fragment_5
                    (uVar21,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                     is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                     record_class,record_sym);
          return;
        }
        uVar25 = (uint)base_code;
        if (uVar25 < 0x104) {
          if (uVar25 != 0x103) {
            switch(uVar25) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
              goto switchD_10601d6d_caseD_11;
            default:
code_r0x10601daf:
              if ((0x18 < uVar25) && (uVar25 < 0x1e)) goto switchD_10601d6d_caseD_11;
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
          if (uVar25 < 0x403) {
            if (uVar25 != 0x402) {
              if ((uVar25 < 0x201) || (0x203 < uVar25)) goto code_r0x10601daf;
              uVar21 = uVar21 | 6;
              goto LAB_10601ca3;
            }
            goto code_r0x10601d74;
          }
          if (uVar25 != 0x1011) {
            il_emit_symbol_record_fragment
                      (uVar25,uVar21,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,
                       base_code,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,
                       in_stack_00000042,record_class,record_sym);
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
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = (byte)(uVar21 >> 8) | 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0e':
    cVar6 = record_sym->key_ref;
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar6 & 3);
    }
    goto switchD_1060184c_caseD_12;
  case '\x0f':
    name_00 = record_sym->detail;
    if ((name_00 != (fe_name *)0x0) && (name_00 != g_name_unnamed)) {
      func_report_static_not_defined
                (name_00,buf,fdef_mode,sym_type,derived_type,part,elem_type,base_code,is_array,
                 format,storage_bits,rec_word0,rec_word1,rec_word2,record_class,record_sym);
      return;
    }
LAB_10601a0e:
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((record_sym->flags22 & 4) == 0) || (record_class == 7)) {
      if (((record_sym->flags22 & 8) == 0) || (record_class == 7)) {
        if ((record_sym->storage & 0x40) == 0) {
          bVar20 = record_sym->storage & 7;
          if (((bVar20 < 4) || (6 < bVar20)) && (bVar20 != 3)) {
            if ((record_sym->flags3 & 4) == 0) {
              if (bVar20 == 1) goto LAB_10601e86;
              if ((is_array == 0) || (bVar20 = 2, (derived_type->extra).sym != (c1_symbol *)0x0)) {
                bVar20 = 3;
              }
            }
            else {
              bVar20 = 1;
            }
          }
          else {
            bVar20 = 4;
          }
        }
        else {
          bVar20 = (~record_sym->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar20 = 8;
      }
    }
    else if ((record_sym->flags1 & 1) == 0) {
LAB_10601e86:
      bVar20 = 2;
    }
    else {
      bVar20 = (-((record_sym->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = bVar20;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar20 = record_sym->kind & 0x1f;
    if ((((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) && ((record_sym->flags1 & 1) != 0)) {
      if ((record_sym->flags22 & 4) == 0) {
        if ((record_sym->flags22 & 8) == 0) {
          if ((record_sym->storage & 0x40) == 0) {
            cVar8 = (-((record_sym->storage & 7) != 3) & 2U) + 3;
          }
          else {
            cVar8 = '\x05';
          }
        }
        else {
          cVar8 = '\n';
        }
      }
      else {
        cVar8 = '\t';
      }
    }
    else {
      bVar20 = record_sym->storage & 7;
      if ((bVar20 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
        diag_error(0x81,record_sym);
        cVar8 = '\x02';
      }
      else {
        if (((record_sym->flags21 & 1) != 0) && (bVar20 != 1)) {
          func_check_inline_definitions
                    (record_sym,buf,fdef_mode,sym_type,derived_type,elem_type,base_code,is_array,
                     format,storage_bits,rec_word0,rec_word1,rec_word2,record_class,record_sym);
          return;
        }
        cVar8 = (-((record_sym->flags22 & 8) != 0) & 6U) + 4;
      }
    }
LAB_10601974:
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = cVar8;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar13 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar13 = (record_sym->x28).value;
    if ((iVar13 < 0x8000) && (-0x8001 < iVar13)) {
      bVar20 = 1;
    }
    else {
      bVar20 = 0;
    }
    sVar30 = (-(ushort)bVar20 & 0xfffe) + 4;
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar20;
    if ((bVar20 != 0) && (iVar14 = il_buffer_put_byte7(buf,(int)sVar30), (char)iVar14 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar24 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar24;
      *psVar24 = sVar30;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar13;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar13 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar13) || (iVar13 < -0x8000)) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar13 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar13 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar17 = decl_lookup_file_scope_twin(record_sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar17->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(pcVar17);
        goto LAB_10638f6a;
      }
      uVar21 = pcVar17->key_ref >> 3;
    }
    else {
      uVar21 = pcVar17->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      bVar20 = (byte)uVar21;
      if (uVar21 < 0x3fff80) {
        if (uVar21 < 0x4000) {
          *(buf->bytes).pbEnd = bVar20 & 0x3f | 0x80;
          goto LAB_10638fd8;
        }
        *(buf->bytes).pbEnd = bVar20 | 0xc0;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *puVar26 = (uchar)(uVar21 >> 6);
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *puVar26 = (uchar)(uVar21 >> 0xe);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = bVar20 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar17 = sym_segment_record(record_sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar17->key_ref & 0xfffffff8) == 0) {
        uVar21 = il_symbol_key_assign(pcVar17);
        goto LAB_1063904f;
      }
      uVar21 = pcVar17->key_ref >> 3;
LAB_10639060:
      iVar13 = il_buffer_reserve(&buf->bytes,4);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        bVar20 = (byte)uVar21;
        if (uVar21 < 0x3fff80) {
          if (uVar21 < 0x4000) {
            *(buf->bytes).pbEnd = bVar20 & 0x3f | 0x80;
LAB_10638fd8:
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar21 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar20 | 0xc0;
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
          *(buf->bytes).pbEnd = bVar20 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      uVar21 = pcVar17->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar21);
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar9 = (record_sym->x28).bytes.bit_position;
    if ((uVar9 != '\0') && (uVar9 != '\x02')) {
      uVar9 = (-(uVar9 != '\x03') & 0xfeU) + 3;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = uVar9;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    part = g_function_ex_offset;
    uVar21 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar13 = il_buffer_reserve(&buf->bytes,6);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        if ((iVar14 & 0xffffff80U) == 0) {
          *(buf->bytes).pbEnd = (uchar)iVar14;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          piVar28 = (int *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)piVar28;
          *piVar28 = iVar14;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
      iVar13 = il_buffer_reserve(&buf->bytes,6);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        if ((uVar21 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar21;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar23 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar23;
          *puVar23 = uVar21;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
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
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
    }
    goto switchD_1060184c_caseD_12;
  case '\x1a':
    if (fdef_mode == '\0') {
      if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
        sVar30 = 0;
      }
      else {
        sVar30 = 0x1000;
      }
      uVar22 = (int)(short)(((ushort)(record_sym->flags21 & 8) << 3 |
                            (ushort)(record_sym->flags21 & 1)) << 7) |
               (record_sym->flags4 & 0x80) >> 5 |
               (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
               (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
               (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar30;
      uVar29 = *(ushort *)
                (((uint)record_sym->type & -(uint)((record_sym->type->code & 0x80) != 0)) + 2);
      if (((uVar29 & 0x2000) != 0) && ((uVar29 & 0x4000) == 0)) {
        g_function_not_inlinable = 1;
      }
      if (g_inline_level == 1) {
LAB_10602124:
        if (g_function_not_inlinable == 0) {
LAB_10602128:
          if ((record_sym->type->flags & 0x8000) == 0) {
            if ((record_sym->flags21 & 1) != 0) {
              uVar22 = uVar22 | 0x40;
            }
            goto LAB_1060213d;
          }
        }
LAB_10602193:
        uVar22 = (int)(short)uVar22 & 0xffffffbf;
        if ((record_sym->flags21 & 1) != 0) {
          func_emit_inline_candidate
                    (uVar22,record_sym,buf,'\0',sym_type,derived_type,elem_type,base_code,is_array,
                     format,storage_bits,rec_word0,rec_word1,record_class,record_sym);
          return;
        }
      }
      else if (g_inline_level == 2) {
        if (g_function_auto_inline == 0) goto LAB_10602124;
        if (g_function_not_inlinable == 0) {
          if ((((record_sym->storage & 7) == 3) && (((byte)record_sym->key_ref & 3) == 1)) ||
             (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
            uVar22 = uVar22 | 0x40;
          }
          goto LAB_10602128;
        }
        goto LAB_10602193;
      }
LAB_1060213d:
      iVar13 = il_buffer_reserve(&buf->bytes,5);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        if (uVar22 < 0x8000) {
          *(short *)(buf->bytes).pbEnd = (short)uVar22;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
        else {
          *(uint *)(buf->bytes).pbEnd = uVar22 | 0x8000;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
    }
    else {
      iVar13 = il_buffer_reserve(&buf->bytes,5);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        if ((int)uVar22 < 0x8000) {
          *(ushort *)(buf->bytes).pbEnd = rec_word2;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(uVar22 >> 8) & 0xffffc0 | 0x40) << 9 | uVar22 & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x1c':
  case '\x1d':
    part = 0x386;
    iVar13 = il_buffer_reserve(&buf->bytes,3);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      puVar26[0] = 0x86;
      puVar26[1] = '\x03';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar13 = il_buffer_reserve(&buf->bytes,5);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      puVar26[0] = 0x96;
      puVar26[1] = 0xba;
      puVar26[2] = '0';
      puVar26[3] = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    goto switchD_1060184c_caseD_12;
  case ' ':
    iVar13 = 2;
LAB_10602252:
    iVar13 = il_buffer_reserve(&buf->bytes,iVar13);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar13 = il_buffer_reserve(&buf->bytes,6);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      if ((uVar21 & 0xffffff80) == 0) {
        *(buf->bytes).pbEnd = (uchar)uVar21;
        puVar26 = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = 0x80;
        puVar23 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar23;
        *puVar23 = uVar21;
        puVar26 = (buf->bytes).pbEnd + 4;
      }
      (buf->bytes).pbEnd = puVar26;
    }
    puVar12 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = '\0';
        puVar26 = (buf->bytes).pbEnd + 1;
LAB_106022da:
        (buf->bytes).pbEnd = puVar26;
      }
    }
    else {
      uVar21 = 0xffffffff;
      pcVar32 = g_il_pch_name;
      do {
        if (uVar21 == 0) break;
        uVar21 = uVar21 - 1;
        cVar2 = *pcVar32;
        pcVar32 = pcVar32 + 1;
      } while (cVar2 != '\0');
      uVar21 = ~uVar21;
      iVar13 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        puVar26 = (buf->bytes).pbEnd;
        for (uVar25 = uVar21 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
          *(undefined4 *)puVar26 = *(undefined4 *)puVar12;
          puVar12 = puVar12 + 4;
          puVar26 = puVar26 + 4;
        }
        for (uVar25 = uVar21 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
          *puVar26 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar26 = puVar26 + 1;
        }
        puVar26 = (buf->bytes).pbEnd + uVar21;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar13 = il_buffer_reserve(&buf->bytes,6);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      if (bVar20 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    else {
      uVar21 = 0;
      pfVar7 = (fe_pragma_comment *)0x0;
      pfVar5 = g_pragma_comment_list;
      while (g_pragma_comment_list = pfVar7, pfVar5 != (fe_pragma_comment *)0x0) {
        pfVar4 = pfVar5->next;
        pfVar5->next = g_pragma_comment_list;
        uVar21 = uVar21 + 1;
        pfVar7 = pfVar5;
        pfVar5 = pfVar4;
      }
      iVar13 = il_buffer_reserve(&buf->bytes,6);
      bVar20 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar20;
      pfVar5 = g_pragma_comment_list;
      if (bVar20 != 0) {
        if ((uVar21 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar21;
          puVar26 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar23 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar23;
          *puVar23 = uVar21;
          puVar26 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar26;
        pfVar5 = g_pragma_comment_list;
      }
      for (; part = (int)pfVar5, pfVar5 != (fe_pragma_comment *)0x0; pfVar5 = pfVar5->next) {
        puVar12 = (uchar *)pfVar5->text;
        iVar13 = pfVar5->kind;
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar20 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar20;
        if (bVar20 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar13;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar5->kind == 7) {
          if ((uchar)(*puVar12 + '\x01') != '\0') {
            part = (int)(char)(*puVar12 + '\x01');
            do {
              uVar9 = *puVar12;
              iVar13 = il_buffer_reserve(&buf->bytes,2);
              bVar20 = buf->open & (byte)iVar13 & 1;
              buf->open = bVar20;
              if (bVar20 != 0) {
                *(buf->bytes).pbEnd = uVar9;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar12 = puVar12 + 1;
              part = part + -1;
            } while (part != 0);
          }
        }
        else {
          uVar21 = 0xffffffff;
          puVar31 = puVar12;
          do {
            if (uVar21 == 0) break;
            uVar21 = uVar21 - 1;
            uVar9 = *puVar31;
            puVar31 = puVar31 + 1;
          } while (uVar9 != '\0');
          uVar21 = ~uVar21;
          iVar13 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
          bVar20 = buf->open & (byte)iVar13 & 1;
          buf->open = bVar20;
          if (bVar20 != 0) {
            puVar26 = (buf->bytes).pbEnd;
            for (uVar25 = uVar21 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
              *(undefined4 *)puVar26 = *(undefined4 *)puVar12;
              puVar12 = puVar12 + 4;
              puVar26 = puVar26 + 4;
            }
            for (uVar25 = uVar21 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
              *puVar26 = *puVar12;
              puVar12 = puVar12 + 1;
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
    goto switchD_1060184c_caseD_22;
  case '#':
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      iVar14 = il_buffer_put_byte7(buf,(int)(short)iVar13);
      if ((char)iVar14 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar24 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar24;
        *psVar24 = (short)iVar13;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar21 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar21 = g_next_entity_id;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,5);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    goto switchD_1060184c_caseD_12;
  case '&':
    uVar21 = 0xffffffff;
    pcVar32 = (char *)g_source_file_ni;
    do {
      if (uVar21 == 0) break;
      uVar21 = uVar21 - 1;
      cVar2 = *pcVar32;
      pcVar32 = pcVar32 + 1;
    } while (cVar2 != '\0');
    uVar21 = ~uVar21;
    iVar13 = il_buffer_reserve(&buf->bytes,uVar21 + 1);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      puVar26 = (buf->bytes).pbEnd;
      for (uVar25 = uVar21 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
        *(undefined4 *)puVar26 = *(undefined4 *)puVar12;
        puVar12 = puVar12 + 4;
        puVar26 = puVar26 + 4;
      }
      for (uVar25 = uVar21 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
        *puVar26 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar26 = puVar26 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar21;
    }
    goto switchD_1060184c_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_2
                (record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_3
                (record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
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
    iVar13 = il_buffer_reserve(&buf->bytes,5);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if ((bVar20 != 0) && (iVar13 = il_buffer_put_byte7(buf,0xc), (char)iVar13 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar26 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar26;
      puVar26[0] = '\f';
      puVar26[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if ((bVar20 != 0) && (iVar13 = il_buffer_put_byte7(buf,0), (char)iVar13 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar26 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar26;
      puVar26[0] = '\0';
      puVar26[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    if (g_opt_Ct != '\0') {
      il_emit_symbol_inline_fragment
                (record_sym,buf,fdef_mode,sym_type,derived_type,(uint *)part,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  }
  iVar13 = il_buffer_reserve(&buf->bytes,6);
  bVar20 = buf->open & (byte)iVar13 & 1;
  buf->open = bVar20;
  if ((bVar20 != 0) && (iVar13 = il_buffer_put_byte7(buf,(uint)value), (char)iVar13 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar23 = (uint *)((buf->bytes).pbEnd + 1);
    (buf->bytes).pbEnd = (PB)puVar23;
    *puVar23 = (uint)value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
  }
  goto switchD_1060184c_caseD_12;
switchD_1060184c_caseD_22:
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar11 = &g_line_map_cached_row;
  }
  else {
    pfVar11 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  sym_keys = pfVar11->file;
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar21 = sym_keys->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  sym_keys->entity = uVar21 & 0xffffff ^ sym_keys->entity;
  uVar21 = il_symbol_key_2((int)sym_keys);
  if (g_c9il_mode == '\0') {
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar20 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      bVar20 = (byte)uVar21;
      if (uVar21 < 0x3fff80) {
        if (uVar21 < 0x4000) {
          *(buf->bytes).pbEnd = bVar20 & 0x3f | 0x80;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar21 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar20 | 0xc0;
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
        *(buf->bytes).pbEnd = bVar20 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
  }
  else {
    il_buffer_put_id(buf,uVar21);
  }
  puVar12 = (uchar *)pp_position_file_name(&g_token_position);
  _rec_word2 = uVar22;
  goto LAB_10602472;
}

