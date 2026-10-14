void __cdecl
il_emit_symbol_fragment_5
          (uint kind_bits,fe_il_buffer *buf,char fdef_mode,c1_type *type,c1_type *derived_type,
          uint *stored_record,c1_type *base_type,ushort basic_code,int is_array,char *codes,
          uint elem_flag_bits,uint rec_word0,uint rec_word1,ushort rec_fflags,ushort rec_fflags_high
          ,int record_class,c1_symbol *sym_arg)

{
  PB *ppuVar1;
  char cVar2;
  c1_type *pcVar3;
  fe_name *name;
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
  int iVar11;
  fe_line_map_row *pfVar12;
  uchar *puVar13;
  int iVar14;
  byte *pbVar15;
  void *pvVar16;
  c1_symbol *pcVar17;
  uint uVar18;
  PB puVar19;
  byte bVar20;
  byte bVar21;
  uint *puVar22;
  short *psVar23;
  uint uVar24;
  PB puVar25;
  ushort uVar26;
  int *piVar27;
  ushort uVar28;
  short sVar29;
  uchar *puVar30;
  char *pcVar31;
  
code_r0x10601d74:
  kind_bits = kind_bits | 2;
LAB_10601ca3:
  if (0x7f < (ushort)kind_bits) {
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (byte)(kind_bits >> 8) | 0x80;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
  }
  iVar11 = il_buffer_reserve(&buf->bytes,2);
  bVar21 = buf->open & (byte)iVar11 & 1;
  buf->open = bVar21;
  if (bVar21 != 0) {
    *(buf->bytes).pbEnd = (uchar)kind_bits;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  }
switchD_1060184c_caseD_12:
  iVar14 = g_function_ex_offset;
  iVar11 = g_function_formal_count;
  puVar13 = (uchar *)g_source_file_ni;
  uVar18 = g_cv_precomp_signature;
  cVar2 = *codes;
  if (cVar2 == '\0') {
    if ((g_c9il_mode == '\0') && (sym_arg != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym_arg->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym_arg->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (record_class == 0xe)) {
        uVar18 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        puVar25 = g_il_gi_fdef.bytes.pbEnd;
        puVar19 = (PB)(uVar18 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar19;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.pbEnd = rec_word0;
          *(uint *)(puVar25 + 4) = rec_word1;
          *(uint *)(puVar25 + 8) = _rec_fflags;
          puVar19 = g_il_gi_fdef.bytes.pbEnd + 0xc;
          g_il_gi_fdef.bytes.pbEnd = puVar19;
        }
        ilstore_put_record(&g_il_gi_fdef,sym_arg->key_ref >> 3,
                           CONCAT31((int3)((uint)puVar19 >> 8),(sym_arg->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  codes = codes + 1;
  switch(cVar2) {
  case '\x01':
    bVar21 = sym_arg->kind & 0x1f;
    if (((bVar21 == 7) || (bVar21 == 8)) || (bVar21 == 6)) {
      value = (c1_symbol_cell *)type_size(base_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar21 = sym_arg->kind & 0x1f;
        if (bVar21 == 0xb) {
          type_check_size_known(type);
        }
        else if (bVar21 == 0xc) {
          il_emit_symbol_part(type,0,sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type
                              ,basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,
                              rec_fflags,rec_fflags_high,record_class,sym_arg);
          return;
        }
      }
    }
    if ((((sym_arg->flags3 & 4) != 0) && ((type->code & 0x200) != 0)) &&
       ((((type->extra).sym)->flags4 & 1) != 0)) {
      il_emit_symbol_fragment
                ((uint)value,sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,
                 basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,
                 rec_fflags_high,record_class,sym_arg);
      return;
    }
    break;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar21 = sym_arg->flags4;
      if (((((bVar21 & 0x80) == 0) || (bVar20 = sym_arg->kind & 0x1f, bVar20 == 7)) || (bVar20 == 8)
          ) || (bVar20 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar20 = sym_arg->kind & 0x1f;
      if (((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) {
        if ((bVar21 & 2) != 0) {
          rec_word0 = rec_word0 | 0x100;
        }
        if ((sym_arg->flags22 & 1) != 0) {
          rec_word0 = rec_word0 | 0x400;
        }
        if (((sym_arg->x2c).function_flags & 1) != 0) {
          rec_word0 = rec_word0 | 0x80;
        }
      }
      if ((sym_arg->key_ref & 3) != 0) {
        if (((bVar20 == 10) || (bVar20 == 0xb)) && ((bVar21 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar20 != 7) && (bVar20 != 8)) && (bVar20 != 6)) {
          rec_word0 = rec_word0 | 0x100;
        }
      }
      if ((sym_arg->flags3 & 8) != 0) {
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
      if (((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) {
        if ((sym_arg->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((sym_arg->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((sym_arg->flags22 & 2) != 0) && (bVar20 != 7)) && (bVar20 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar20 == 10) && ((sym_arg->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((sym_arg->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((sym_arg->flags3 & 4) == 0)) {
          pcVar10 = sym_arg->type;
          cVar2 = (char)pcVar10->code;
          while (cVar2 < '\0') {
            pcVar10 = pcVar10->base;
            cVar2 = (char)pcVar10->code;
          }
          if ((pcVar10->flags & 0x18) != 0) goto LAB_106016e1;
        }
        if ((sym_arg->flags22 & 8) == 0) {
          rec_word0 = rec_word0 | 0x20;
        }
      }
LAB_106016e1:
      il_emit_symbol_reference(buf,sym_arg,rec_word0);
    }
    else {
      il_emit_symbol_reference(buf,sym_arg,rec_word0);
    }
    goto switchD_1060184c_caseD_12;
  case '\x03':
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)record_class;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x04':
    if (is_array == 0) {
      value = (c1_symbol_cell *)0x0;
    }
    else {
      value = (c1_symbol_cell *)sym_element_size(sym_arg);
    }
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar11 = il_buffer_put_byte7(buf,(uint)value), (char)iVar11 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym_arg->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(sym_arg);
        goto LAB_106018ae;
      }
      uVar18 = sym_arg->key_ref >> 3;
    }
    else {
      uVar18 = sym_arg->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar18);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      bVar21 = (byte)uVar18;
      if (uVar18 < 0x3fff80) {
        if (uVar18 < 0x4000) {
          *(buf->bytes).pbEnd = bVar21 & 0x3f | 0x80;
          puVar25 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar25;
          *puVar25 = (uchar)(uVar18 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar21 | 0xc0;
          puVar25 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar25;
          *puVar25 = (uchar)(uVar18 >> 6);
          puVar25 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar25;
          *puVar25 = (uchar)(uVar18 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar21 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if ((bVar21 != 0) && (iVar11 = il_buffer_put_byte7(buf,0), (char)iVar11 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar25 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar25;
        puVar25[0] = '\0';
        puVar25[1] = '\0';
        puVar25[2] = '\0';
        puVar25[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar21 = sym_arg->kind & 0x1f;
    if ((((bVar21 != 0) && (bVar21 < 0xf)) && (bVar21 != 5)) &&
       (((sym_arg->flags23 & 1) != 0 &&
        (pvVar16 = sym_segment_record(sym_arg), *(void **)((int)pvVar16 + 8) == g_name_drectve)))) {
      il_emit_symbol_fragment_2
                (sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array
                 ,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    if ((sym_arg->kind & 0x1f) == 4) {
      value = (sym_arg->x2c).references;
LAB_10601955:
      if (value != (c1_symbol_cell *)0x0) break;
    }
    else if ((sym_arg->type->code & 0x300) != 0) {
      value = (c1_symbol_cell *)((sym_arg->type->extra).tag)->debug_index;
      goto LAB_10601955;
    }
    value = (c1_symbol_cell *)type->debug_index;
    break;
  case '\a':
    cVar8 = g_il_block_level;
    if (record_class == 3) {
      cVar8 = (sym_arg->x28).bytes.bit_position;
    }
    goto LAB_10601974;
  case '\b':
    bVar21 = sym_arg->kind & 0x1f;
    if (bVar21 == 9) {
      bVar21 = *(byte *)&sym_arg->detail;
    }
    else if ((sym_arg->flags3 & 8) == 0) {
      if ((bVar21 == 10) && ((sym_arg->storage & 7) == 3)) {
        bVar21 = 0x24;
      }
      else {
        bVar21 = 0;
      }
    }
    else {
      bVar21 = -((sym_arg->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((sym_arg->name == (fe_name *)0x0) || (sym_arg->name == g_name_unnamed)) goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(sym_arg);
    uVar18 = 0xffffffff;
    puVar22 = src;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      uVar24 = *puVar22;
      puVar22 = (uint *)((int)puVar22 + 1);
    } while ((char)uVar24 != '\0');
    cVar8 = il_buffer_reserve_ok(buf,~uVar18);
    if (cVar8 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar18);
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar21 = sym_arg->flags4;
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = ((bVar21 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar21 = sym_arg->kind & 0x1f;
    if ((bVar21 == 0xb) || (bVar21 == 0xc)) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar21 = sym_arg->storage & 7;
    if ((bVar21 != 0) && (bVar21 < 4)) {
      pcVar10 = type;
      if ((type->code & 0x8f) == 0x83) {
        pcVar10 = type_skip_arrays(type->base);
      }
      if (((byte)pcVar10->flags >> 5 & 1) == 0) {
        if (((((sym_arg->flags3 & 8) == 0) || ((sym_arg->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((sym_arg->flags23 & 1) != 0 &&
             (pbVar15 = sym_segment_record(sym_arg), (*pbVar15 & 0x1f) == 0xe)) &&
            (pvVar16 = sym_segment_record(sym_arg), (*(uint *)((int)pvVar16 + 0x1c) & 0xffffff) != 3
            )))) {
          iVar11 = il_buffer_reserve(&buf->bytes,2);
          bVar21 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar21;
          if (bVar21 != 0) {
            *(buf->bytes).pbEnd = '\x02';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          goto switchD_1060184c_caseD_12;
        }
      }
      else if ((sym_arg->flags23 & 1) != 0) {
        il_emit_symbol_fragment_3
                  (sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,
                   is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,
                   record_class,sym_arg);
        return;
      }
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\r':
    goto switchD_1060184c_caseD_d;
  case '\x0e':
    cVar6 = sym_arg->key_ref;
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar6 & 3);
    }
    goto switchD_1060184c_caseD_12;
  case '\x0f':
    name = sym_arg->detail;
    if ((name != (fe_name *)0x0) && (name != g_name_unnamed)) {
      func_report_static_not_defined
                (name,buf,fdef_mode,type,derived_type,(int)stored_record,base_type,basic_code,
                 is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,record_class,sym_arg);
      return;
    }
LAB_10601a0e:
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((sym_arg->flags22 & 4) == 0) || (record_class == 7)) {
      if (((sym_arg->flags22 & 8) == 0) || (record_class == 7)) {
        if ((sym_arg->storage & 0x40) == 0) {
          bVar21 = sym_arg->storage & 7;
          if (((bVar21 < 4) || (6 < bVar21)) && (bVar21 != 3)) {
            if ((sym_arg->flags3 & 4) == 0) {
              if (bVar21 == 1) goto LAB_10601e86;
              if ((is_array == 0) || (bVar21 = 2, (derived_type->extra).sym != (c1_symbol *)0x0)) {
                bVar21 = 3;
              }
            }
            else {
              bVar21 = 1;
            }
          }
          else {
            bVar21 = 4;
          }
        }
        else {
          bVar21 = (~sym_arg->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar21 = 8;
      }
    }
    else if ((sym_arg->flags1 & 1) == 0) {
LAB_10601e86:
      bVar21 = 2;
    }
    else {
      bVar21 = (-((sym_arg->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar20;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = bVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar21 = sym_arg->kind & 0x1f;
    if ((((bVar21 == 7) || (bVar21 == 8)) || (bVar21 == 6)) && ((sym_arg->flags1 & 1) != 0)) {
      if ((sym_arg->flags22 & 4) == 0) {
        if ((sym_arg->flags22 & 8) == 0) {
          if ((sym_arg->storage & 0x40) == 0) {
            cVar8 = (-((sym_arg->storage & 7) != 3) & 2U) + 3;
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
      bVar21 = sym_arg->storage & 7;
      if ((bVar21 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
        diag_error(0x81,sym_arg);
        cVar8 = '\x02';
      }
      else {
        if (((sym_arg->flags21 & 1) != 0) && (bVar21 != 1)) {
          func_check_inline_definitions
                    (sym_arg,buf,fdef_mode,type,derived_type,base_type,basic_code,is_array,codes,
                     elem_flag_bits,rec_word0,rec_word1,rec_fflags,record_class,sym_arg);
          return;
        }
        cVar8 = (-((sym_arg->flags22 & 8) != 0) & 6U) + 4;
      }
    }
LAB_10601974:
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = cVar8;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar11 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar11 = (sym_arg->x28).value;
    if ((iVar11 < 0x8000) && (-0x8001 < iVar11)) {
      bVar21 = 1;
    }
    else {
      bVar21 = 0;
    }
    sVar29 = (-(ushort)bVar21 & 0xfffe) + 4;
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar14 = il_buffer_put_byte7(buf,(int)sVar29), (char)iVar14 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar23 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar23;
      *psVar23 = sVar29;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar11;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar11 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar11) || (iVar11 < -0x8000)) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar11 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar11 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar17 = decl_lookup_file_scope_twin(sym_arg);
    if (g_c9il_mode == '\0') {
      if ((pcVar17->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(pcVar17);
        goto LAB_10638f6a;
      }
      uVar18 = pcVar17->key_ref >> 3;
    }
    else {
      uVar18 = pcVar17->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      bVar21 = (byte)uVar18;
      if (uVar18 < 0x3fff80) {
        if (uVar18 < 0x4000) {
          *(buf->bytes).pbEnd = bVar21 & 0x3f | 0x80;
          goto LAB_10638fd8;
        }
        *(buf->bytes).pbEnd = bVar21 | 0xc0;
        puVar25 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar25;
        *puVar25 = (uchar)(uVar18 >> 6);
        puVar25 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar25;
        *puVar25 = (uchar)(uVar18 >> 0xe);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = bVar21 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar17 = sym_segment_record(sym_arg);
    if (g_c9il_mode == '\0') {
      if ((pcVar17->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(pcVar17);
        goto LAB_1063904f;
      }
      uVar18 = pcVar17->key_ref >> 3;
LAB_10639060:
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        bVar21 = (byte)uVar18;
        if (uVar18 < 0x3fff80) {
          if (uVar18 < 0x4000) {
            *(buf->bytes).pbEnd = bVar21 & 0x3f | 0x80;
LAB_10638fd8:
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar21 | 0xc0;
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 6);
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar21 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      uVar18 = pcVar17->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar18);
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar9 = (sym_arg->x28).bytes.bit_position;
    if ((uVar9 != '\0') && (uVar9 != '\x02')) {
      uVar9 = (-(uVar9 != '\x03') & 0xfeU) + 3;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = uVar9;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    stored_record = (uint *)g_function_ex_offset;
    uVar18 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        if ((iVar14 & 0xffffff80U) == 0) {
          *(buf->bytes).pbEnd = (uchar)iVar14;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          piVar27 = (int *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)piVar27;
          *piVar27 = iVar14;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        if ((uVar18 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar18;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar22 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar22;
          *puVar22 = uVar18;
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
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
    }
    goto switchD_1060184c_caseD_12;
  case '\x1a':
    if (fdef_mode == '\0') {
      if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
        sVar29 = 0;
      }
      else {
        sVar29 = 0x1000;
      }
      _rec_fflags = (int)(short)(((ushort)(sym_arg->flags21 & 8) << 3 |
                                 (ushort)(sym_arg->flags21 & 1)) << 7) |
                    (sym_arg->flags4 & 0x80) >> 5 |
                    (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
                    (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                    (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar29;
      uVar28 = *(ushort *)(((uint)sym_arg->type & -(uint)((sym_arg->type->code & 0x80) != 0)) + 2);
      if (((uVar28 & 0x2000) != 0) && ((uVar28 & 0x4000) == 0)) {
        g_function_not_inlinable = 1;
      }
      if (g_inline_level == 1) {
LAB_10602124:
        if (g_function_not_inlinable == 0) {
LAB_10602128:
          if ((sym_arg->type->flags & 0x8000) == 0) {
            if ((sym_arg->flags21 & 1) != 0) {
              _rec_fflags = _rec_fflags | 0x40;
            }
            goto LAB_1060213d;
          }
        }
LAB_10602193:
        _rec_fflags = (int)(short)_rec_fflags & 0xffffffbf;
        if ((sym_arg->flags21 & 1) != 0) {
          func_emit_inline_candidate
                    (_rec_fflags,sym_arg,buf,'\0',type,derived_type,base_type,basic_code,is_array,
                     codes,elem_flag_bits,rec_word0,rec_word1,record_class,sym_arg);
          return;
        }
      }
      else if (g_inline_level == 2) {
        if (g_function_auto_inline == 0) goto LAB_10602124;
        if (g_function_not_inlinable == 0) {
          if ((((sym_arg->storage & 7) == 3) && (((byte)sym_arg->key_ref & 3) == 1)) ||
             (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
            _rec_fflags = _rec_fflags | 0x40;
          }
          goto LAB_10602128;
        }
        goto LAB_10602193;
      }
LAB_1060213d:
      iVar11 = il_buffer_reserve(&buf->bytes,5);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
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
      iVar11 = il_buffer_reserve(&buf->bytes,5);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        if ((int)_rec_fflags < 0x8000) {
          *(ushort *)(buf->bytes).pbEnd = rec_fflags;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(_rec_fflags >> 8) & 0xffffc0 | 0x40) << 9 | _rec_fflags & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x1c':
  case '\x1d':
    stored_record = (uint *)0x386;
    iVar11 = il_buffer_reserve(&buf->bytes,3);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      puVar25[0] = 0x86;
      puVar25[1] = '\x03';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      puVar25[0] = 0x96;
      puVar25[1] = 0xba;
      puVar25[2] = '0';
      puVar25[3] = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    goto switchD_1060184c_caseD_12;
  case ' ':
    iVar11 = 2;
LAB_10602252:
    iVar11 = il_buffer_reserve(&buf->bytes,iVar11);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      if ((uVar18 & 0xffffff80) == 0) {
        *(buf->bytes).pbEnd = (uchar)uVar18;
        puVar25 = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = 0x80;
        puVar22 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar22;
        *puVar22 = uVar18;
        puVar25 = (buf->bytes).pbEnd + 4;
      }
      (buf->bytes).pbEnd = puVar25;
    }
    puVar13 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\0';
        puVar25 = (buf->bytes).pbEnd + 1;
LAB_106022da:
        (buf->bytes).pbEnd = puVar25;
      }
    }
    else {
      uVar18 = 0xffffffff;
      pcVar31 = g_il_pch_name;
      do {
        if (uVar18 == 0) break;
        uVar18 = uVar18 - 1;
        cVar2 = *pcVar31;
        pcVar31 = pcVar31 + 1;
      } while (cVar2 != '\0');
      uVar18 = ~uVar18;
      iVar11 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        puVar25 = (buf->bytes).pbEnd;
        for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
          *(undefined4 *)puVar25 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar25 = puVar25 + 4;
        }
        for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
          *puVar25 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar25 = puVar25 + 1;
        }
        puVar25 = (buf->bytes).pbEnd + uVar18;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    else {
      uVar18 = 0;
      pfVar7 = (fe_pragma_comment *)0x0;
      pfVar5 = g_pragma_comment_list;
      while (g_pragma_comment_list = pfVar7, pfVar5 != (fe_pragma_comment *)0x0) {
        pfVar4 = pfVar5->next;
        pfVar5->next = g_pragma_comment_list;
        uVar18 = uVar18 + 1;
        pfVar7 = pfVar5;
        pfVar5 = pfVar4;
      }
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      pfVar5 = g_pragma_comment_list;
      if (bVar21 != 0) {
        if ((uVar18 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar18;
          puVar25 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar22 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar22;
          *puVar22 = uVar18;
          puVar25 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar25;
        pfVar5 = g_pragma_comment_list;
      }
      for (; stored_record = (uint *)pfVar5, pfVar5 != (fe_pragma_comment *)0x0;
          pfVar5 = pfVar5->next) {
        puVar13 = (uchar *)pfVar5->text;
        iVar11 = pfVar5->kind;
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar21 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar21;
        if (bVar21 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar11;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar5->kind == 7) {
          if ((uchar)(*puVar13 + '\x01') != '\0') {
            stored_record = (uint *)(int)(char)(*puVar13 + '\x01');
            do {
              uVar9 = *puVar13;
              iVar11 = il_buffer_reserve(&buf->bytes,2);
              bVar21 = buf->open & (byte)iVar11 & 1;
              buf->open = bVar21;
              if (bVar21 != 0) {
                *(buf->bytes).pbEnd = uVar9;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar13 = puVar13 + 1;
              stored_record = (uint *)((int)stored_record + -1);
            } while (stored_record != (uint *)0x0);
          }
        }
        else {
          uVar18 = 0xffffffff;
          puVar30 = puVar13;
          do {
            if (uVar18 == 0) break;
            uVar18 = uVar18 - 1;
            uVar9 = *puVar30;
            puVar30 = puVar30 + 1;
          } while (uVar9 != '\0');
          uVar18 = ~uVar18;
          iVar11 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
          bVar21 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar21;
          if (bVar21 != 0) {
            puVar25 = (buf->bytes).pbEnd;
            for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
              *(undefined4 *)puVar25 = *(undefined4 *)puVar13;
              puVar13 = puVar13 + 4;
              puVar25 = puVar25 + 4;
            }
            for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
              *puVar25 = *puVar13;
              puVar13 = puVar13 + 1;
              puVar25 = puVar25 + 1;
            }
            ppuVar1 = &(buf->bytes).pbEnd;
            *ppuVar1 = *ppuVar1 + uVar18;
          }
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\"':
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar12 = &g_line_map_cached_row;
    }
    else {
      pfVar12 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    sym_keys = pfVar12->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar18 = sym_keys->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym_keys->entity = uVar18 & 0xffffff ^ sym_keys->entity;
    uVar18 = il_symbol_key_2((int)sym_keys);
    if (g_c9il_mode == '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar21 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        bVar21 = (byte)uVar18;
        if (uVar18 < 0x3fff80) {
          if (uVar18 < 0x4000) {
            *(buf->bytes).pbEnd = bVar21 & 0x3f | 0x80;
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar21 | 0xc0;
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 6);
            puVar25 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar25;
            *puVar25 = (uchar)(uVar18 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar21 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar18);
    }
    puVar13 = (uchar *)pp_position_file_name(&g_token_position);
    uVar18 = 0xffffffff;
    puVar30 = puVar13;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      uVar9 = *puVar30;
      puVar30 = puVar30 + 1;
    } while (uVar9 != '\0');
    uVar18 = ~uVar18;
    iVar11 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
        *(undefined4 *)puVar25 = *(undefined4 *)puVar13;
        puVar13 = puVar13 + 4;
        puVar25 = puVar25 + 4;
      }
      for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
        *puVar25 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar25 = puVar25 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar18;
    }
    goto switchD_1060184c_caseD_12;
  case '#':
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      iVar14 = il_buffer_put_byte7(buf,(int)(short)iVar11);
      if ((char)iVar14 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar23 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar23;
        *psVar23 = (short)iVar11;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar18 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar18 = g_next_entity_id;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    goto switchD_1060184c_caseD_12;
  case '&':
    uVar18 = 0xffffffff;
    pcVar31 = (char *)g_source_file_ni;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      cVar2 = *pcVar31;
      pcVar31 = pcVar31 + 1;
    } while (cVar2 != '\0');
    uVar18 = ~uVar18;
    iVar11 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
        *(undefined4 *)puVar25 = *(undefined4 *)puVar13;
        puVar13 = puVar13 + 4;
        puVar25 = puVar25 + 4;
      }
      for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
        *puVar25 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar25 = puVar25 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar18;
    }
    goto switchD_1060184c_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_2
                (sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array
                 ,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_3
                (sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array
                 ,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case '*':
    uVar18 = 2;
    if (g_c9il_mode == '\0') {
      uVar18 = 3;
    }
    if (g_dlp != '\0') {
      uVar18 = uVar18 | 8;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar11 = il_buffer_put_byte7(buf,0xc), (char)iVar11 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar25 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar25;
      puVar25[0] = '\f';
      puVar25[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar11 = il_buffer_put_byte7(buf,0), (char)iVar11 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar25 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar25;
      puVar25[0] = '\0';
      puVar25[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    if (g_opt_Ct != '\0') {
      il_emit_symbol_inline_fragment
                (sym_arg,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array
                 ,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
                 sym_arg);
      return;
    }
    goto switchD_1060184c_caseD_12;
  }
  iVar11 = il_buffer_reserve(&buf->bytes,6);
  bVar21 = buf->open & (byte)iVar11 & 1;
  buf->open = bVar21;
  if ((bVar21 != 0) && (iVar11 = il_buffer_put_byte7(buf,(uint)value), (char)iVar11 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar22 = (uint *)((buf->bytes).pbEnd + 1);
    (buf->bytes).pbEnd = (PB)puVar22;
    *puVar22 = (uint)value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
  }
  goto switchD_1060184c_caseD_12;
switchD_1060184c_caseD_d:
  if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
    uVar28 = base_type->code;
    cVar2 = (char)uVar28;
    if ((cVar2 < '\0') && (base_type != (c1_type *)0x0)) {
      uVar26 = base_type->flags;
    }
    else {
      uVar28 = 0;
      uVar26 = 0;
    }
    kind_bits = 0;
    pcVar10 = base_type;
    while (cVar2 < '\0') {
      pcVar10 = pcVar10->base;
      cVar2 = (char)pcVar10->code;
    }
    basic_code = pcVar10->code;
    pcVar10 = base_type;
  }
  else {
    if (derived_type == (c1_type *)0x0) {
      uVar28 = 0;
      uVar26 = 0;
    }
    else {
      uVar28 = derived_type->code;
      uVar26 = derived_type->flags;
    }
    pcVar10 = type;
    if ((basic_code & 0x200) == 0) {
LAB_10601c71:
      kind_bits = 0;
    }
    else {
      if (basic_code != 0x203) {
        pcVar3 = sym_arg->type;
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
      kind_bits = 0x10;
    }
  }
  if ((uVar26 & 0x100) != 0) {
    kind_bits = kind_bits | 0x4000;
  }
  if ((uVar26 & 0x40) != 0) {
    kind_bits = kind_bits | 0x1000;
  }
  uVar28 = uVar28 & 0x8f;
  if (uVar28 == 0x83) {
    kind_bits = kind_bits | 6;
    goto LAB_10601ca3;
  }
  if (((uVar28 == 0x82) || (uVar28 == 0x86)) || (uVar28 == 0x80)) {
    kind_bits = kind_bits | 3;
    goto LAB_10601ca3;
  }
  uVar28 = pcVar10->code;
  if ((uVar28 & 0x2000) != 0) goto code_r0x10601d74;
  if ((((g_ms_extensions == '\0') && ((uVar28 & 0xfff) == 0x11)) && ((uVar28 & 0x1000) == 0)) &&
     (g_opt_J_unsigned_char != '\0')) {
    il_emit_symbol_fragment_5
              (kind_bits,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,is_array
               ,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,record_class,
               sym_arg);
    return;
  }
  uVar18 = (uint)basic_code;
  if (uVar18 < 0x104) {
    if (uVar18 == 0x103) goto switchD_10601d6d_caseD_11;
    switch(uVar18) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
      goto switchD_10601d6d_caseD_11;
    case 0x26:
    case 0x27:
    case 0x28:
      kind_bits = kind_bits | 5;
      goto LAB_10601ca3;
    case 0x40:
      kind_bits = kind_bits | 7;
      goto LAB_10601ca3;
    }
  }
  else {
    if (0x402 < uVar18) {
      if (uVar18 != 0x1011) {
        il_emit_symbol_record_fragment
                  (uVar18,kind_bits,buf,fdef_mode,type,derived_type,stored_record,base_type,
                   basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,
                   rec_fflags_high,record_class,sym_arg);
        return;
      }
      goto switchD_10601d6d_caseD_11;
    }
    if (uVar18 == 0x402) goto code_r0x10601d74;
    if ((0x200 < uVar18) && (uVar18 < 0x204)) {
      kind_bits = kind_bits | 6;
      goto LAB_10601ca3;
    }
  }
  if ((uVar18 < 0x19) || (0x1d < uVar18)) goto LAB_10601ca3;
switchD_10601d6d_caseD_11:
  kind_bits = kind_bits | 1;
  goto LAB_10601ca3;
}

