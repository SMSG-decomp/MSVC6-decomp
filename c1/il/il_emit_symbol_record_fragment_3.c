void __cdecl
il_emit_symbol_record_fragment_3
          (c1_symbol *sym,fe_il_buffer *buf,char fdef_mode,c1_type *type,c1_type *derived_type,
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
  fe_line_map_row *pfVar11;
  uchar *puVar12;
  int iVar13;
  byte *pbVar14;
  void *pvVar15;
  c1_symbol *pcVar16;
  int iVar17;
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
  c1_symbol *sym_00;
  ushort uVar28;
  short sVar29;
  uchar *puVar30;
  char *pcVar31;
  
  iVar17 = il_buffer_reserve(&buf->bytes,4);
  bVar21 = buf->open & (byte)iVar17 & 1;
  buf->open = bVar21;
  pcVar16 = sym_arg;
  if ((bVar21 != 0) &&
     (iVar17 = il_buffer_put_byte7(buf,0), pcVar16 = sym_arg, (char)iVar17 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
    puVar25 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar25;
    puVar25[0] = '\0';
    puVar25[1] = '\0';
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    pcVar16 = sym;
  }
switchD_1060184c_caseD_12:
  sym_00 = pcVar16;
  iVar13 = g_function_ex_offset;
  iVar17 = g_function_formal_count;
  puVar12 = (uchar *)g_source_file_ni;
  uVar18 = g_cv_precomp_signature;
  cVar2 = *codes;
  if (cVar2 == '\0') {
    if ((g_c9il_mode == '\0') && (sym_00 != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym_00->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym_00->key_ref >> 3);
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
        ilstore_put_record(&g_il_gi_fdef,sym_00->key_ref >> 3,
                           CONCAT31((int3)((uint)puVar19 >> 8),(sym_00->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  codes = codes + 1;
  pcVar16 = sym_00;
  switch(cVar2) {
  case '\x01':
    bVar21 = sym_00->kind & 0x1f;
    if (((bVar21 == 7) || (bVar21 == 8)) || (bVar21 == 6)) {
      value = (c1_symbol_cell *)type_size(base_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar21 = sym_00->kind & 0x1f;
        if (bVar21 == 0xb) {
          type_check_size_known(type);
        }
        else if (bVar21 == 0xc) {
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
      bVar21 = sym_00->flags4;
      if (((((bVar21 & 0x80) == 0) || (bVar20 = sym_00->kind & 0x1f, bVar20 == 7)) || (bVar20 == 8))
         || (bVar20 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar20 = sym_00->kind & 0x1f;
      if (((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) {
        if ((bVar21 & 2) != 0) {
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
        if (((bVar20 == 10) || (bVar20 == 0xb)) && ((bVar21 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar20 != 7) && (bVar20 != 8)) && (bVar20 != 6)) {
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
      if (((bVar20 == 7) || (bVar20 == 8)) || (bVar20 == 6)) {
        if ((sym_00->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((sym_00->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((sym_00->flags22 & 2) != 0) && (bVar20 != 7)) && (bVar20 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar20 == 10) && ((sym_00->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((sym_00->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((sym_00->flags3 & 4) == 0)) {
          pcVar10 = sym_00->type;
          cVar2 = (char)pcVar10->code;
          while (cVar2 < '\0') {
            pcVar10 = pcVar10->base;
            cVar2 = (char)pcVar10->code;
          }
          if ((pcVar10->flags & 0x18) != 0) goto LAB_106016e1;
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
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)record_class;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x04':
    if (is_array == 0) {
      value = (c1_symbol_cell *)0x0;
    }
    else {
      value = (c1_symbol_cell *)sym_element_size(sym_00);
    }
    iVar17 = il_buffer_reserve(&buf->bytes,6);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if ((bVar21 != 0) &&
       (iVar17 = il_buffer_put_byte7(buf,(uint)value), pcVar16 = sym_arg, (char)iVar17 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym_00->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(sym_00);
        goto LAB_106018ae;
      }
      uVar18 = sym_00->key_ref >> 3;
    }
    else {
      uVar18 = sym_00->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar18);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      bVar21 = (byte)uVar18;
      if (uVar18 < 0x3fff80) {
        if (uVar18 < 0x4000) {
          *(buf->bytes).pbEnd = bVar21 & 0x3f | 0x80;
          puVar25 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar25;
          *puVar25 = (uchar)(uVar18 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar16 = sym_00;
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
          pcVar16 = sym_00;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar21 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar17 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if ((bVar21 != 0) &&
         (iVar17 = il_buffer_put_byte7(buf,0), pcVar16 = sym_arg, (char)iVar17 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar25 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar25;
        puVar25[0] = '\0';
        puVar25[1] = '\0';
        puVar25[2] = '\0';
        puVar25[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar16 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar21 = sym_00->kind & 0x1f;
    if ((((bVar21 != 0) && (bVar21 < 0xf)) && (bVar21 != 5)) &&
       (((sym_00->flags23 & 1) != 0 &&
        (pvVar15 = sym_segment_record(sym_00), *(void **)((int)pvVar15 + 8) == g_name_drectve)))) {
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
    cVar8 = g_il_block_level;
    if (record_class == 3) {
      cVar8 = (sym_00->x28).bytes.bit_position;
    }
    goto LAB_10601974;
  case '\b':
    bVar21 = sym_00->kind & 0x1f;
    if (bVar21 == 9) {
      bVar21 = *(byte *)&sym_00->detail;
    }
    else if ((sym_00->flags3 & 8) == 0) {
      if ((bVar21 == 10) && ((sym_00->storage & 7) == 3)) {
        bVar21 = 0x24;
      }
      else {
        bVar21 = 0;
      }
    }
    else {
      bVar21 = -((sym_00->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((sym_00->name == (fe_name *)0x0) || (sym_00->name == g_name_unnamed)) goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(sym_00);
    uVar18 = 0xffffffff;
    puVar22 = src;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      uVar24 = *puVar22;
      puVar22 = (uint *)((int)puVar22 + 1);
    } while ((char)uVar24 != '\0');
    cVar8 = il_buffer_reserve_ok(buf,~uVar18);
    pcVar16 = sym_arg;
    if (cVar8 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar18);
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar21 = sym_00->flags4;
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar20;
    pcVar16 = sym_arg;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = ((bVar21 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar21 = sym_00->kind & 0x1f;
    if ((bVar21 == 0xb) || (bVar21 == 0xc)) {
      iVar17 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar21 = sym_00->storage & 7;
    if ((bVar21 != 0) && (bVar21 < 4)) {
      pcVar10 = type;
      if ((type->code & 0x8f) == 0x83) {
        pcVar10 = type_skip_arrays(type->base);
      }
      if (((byte)pcVar10->flags >> 5 & 1) == 0) {
        if (((((sym_00->flags3 & 8) == 0) || ((sym_00->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((sym_00->flags23 & 1) != 0 &&
             (pbVar14 = sym_segment_record(sym_00), (*pbVar14 & 0x1f) == 0xe)) &&
            (pvVar15 = sym_segment_record(sym_00), (*(uint *)((int)pvVar15 + 0x1c) & 0xffffff) != 3)
            ))) {
          iVar17 = il_buffer_reserve(&buf->bytes,2);
          bVar21 = buf->open & (byte)iVar17 & 1;
          buf->open = bVar21;
          pcVar16 = sym_arg;
          if (bVar21 != 0) {
            *(buf->bytes).pbEnd = '\x02';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar16 = sym_00;
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
      iVar17 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_00;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\r':
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
      uVar18 = 0;
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
        uVar18 = 0;
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
            pcVar16 = (c1_symbol *)0x0;
          }
          else {
            pcVar16 = (pcVar3->extra).sym;
          }
          if ((pcVar16->tag_alignment & 0x100) == 0) goto LAB_10601c71;
        }
        uVar18 = 0x10;
      }
    }
    if ((uVar26 & 0x100) != 0) {
      uVar18 = uVar18 | 0x4000;
    }
    if ((uVar26 & 0x40) != 0) {
      uVar18 = uVar18 | 0x1000;
    }
    uVar28 = uVar28 & 0x8f;
    if (uVar28 == 0x83) {
      uVar18 = uVar18 | 6;
    }
    else if (((uVar28 == 0x82) || (uVar28 == 0x86)) || (uVar28 == 0x80)) {
      uVar18 = uVar18 | 3;
    }
    else {
      uVar28 = pcVar10->code;
      if ((uVar28 & 0x2000) == 0) {
        if ((((g_ms_extensions == '\0') && ((uVar28 & 0xfff) == 0x11)) && ((uVar28 & 0x1000) == 0))
           && (g_opt_J_unsigned_char != '\0')) {
          il_emit_symbol_fragment_5
                    (uVar18,buf,fdef_mode,type,derived_type,stored_record,base_type,basic_code,
                     is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,rec_fflags_high,
                     record_class,sym_arg);
          return;
        }
        uVar24 = (uint)basic_code;
        if (uVar24 < 0x104) {
          if (uVar24 != 0x103) {
            switch(uVar24) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
              goto switchD_10601d6d_caseD_11;
            default:
code_r0x10601daf:
              if ((0x18 < uVar24) && (uVar24 < 0x1e)) goto switchD_10601d6d_caseD_11;
              break;
            case 0x26:
            case 0x27:
            case 0x28:
              uVar18 = uVar18 | 5;
              break;
            case 0x40:
              uVar18 = uVar18 | 7;
            }
            goto LAB_10601ca3;
          }
        }
        else {
          if (uVar24 < 0x403) {
            if (uVar24 != 0x402) {
              if ((uVar24 < 0x201) || (0x203 < uVar24)) goto code_r0x10601daf;
              uVar18 = uVar18 | 6;
              goto LAB_10601ca3;
            }
            goto code_r0x10601d74;
          }
          if (uVar24 != 0x1011) {
            il_emit_symbol_record_fragment
                      (uVar24,uVar18,buf,fdef_mode,type,derived_type,stored_record,base_type,
                       basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,rec_fflags,
                       rec_fflags_high,record_class,sym_arg);
            return;
          }
        }
switchD_10601d6d_caseD_11:
        uVar18 = uVar18 | 1;
      }
      else {
code_r0x10601d74:
        uVar18 = uVar18 | 2;
      }
    }
LAB_10601ca3:
    if (0x7f < (ushort)uVar18) {
      iVar17 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = (byte)(uVar18 >> 8) | 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0e':
    cVar6 = sym_00->key_ref;
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar6 & 3);
      pcVar16 = sym_00;
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
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((sym_00->flags22 & 4) == 0) || (record_class == 7)) {
      if (((sym_00->flags22 & 8) == 0) || (record_class == 7)) {
        if ((sym_00->storage & 0x40) == 0) {
          bVar21 = sym_00->storage & 7;
          if (((bVar21 < 4) || (6 < bVar21)) && (bVar21 != 3)) {
            if ((sym_00->flags3 & 4) == 0) {
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
          bVar21 = (~sym_00->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar21 = 8;
      }
    }
    else if ((sym_00->flags1 & 1) == 0) {
LAB_10601e86:
      bVar21 = 2;
    }
    else {
      bVar21 = (-((sym_00->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar20 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar20;
    pcVar16 = sym_arg;
    if (bVar20 != 0) {
      *(buf->bytes).pbEnd = bVar21;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar21 = sym_00->kind & 0x1f;
    if ((((bVar21 == 7) || (bVar21 == 8)) || (bVar21 == 6)) && ((sym_00->flags1 & 1) != 0)) {
      if ((sym_00->flags22 & 4) == 0) {
        if ((sym_00->flags22 & 8) == 0) {
          if ((sym_00->storage & 0x40) == 0) {
            cVar8 = (-((sym_00->storage & 7) != 3) & 2U) + 3;
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
      bVar21 = sym_00->storage & 7;
      if ((bVar21 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
        diag_error(0x81,sym_00);
        cVar8 = '\x02';
      }
      else {
        if (((sym_00->flags21 & 1) != 0) && (bVar21 != 1)) {
          func_check_inline_definitions
                    (sym_00,buf,fdef_mode,type,derived_type,base_type,basic_code,is_array,codes,
                     elem_flag_bits,rec_word0,rec_word1,rec_fflags,record_class,sym_arg);
          return;
        }
        cVar8 = (-((sym_00->flags22 & 8) != 0) & 6U) + 4;
      }
    }
LAB_10601974:
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = cVar8;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar17 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar17 = (sym_00->x28).value;
    if ((iVar17 < 0x8000) && (-0x8001 < iVar17)) {
      bVar21 = 1;
    }
    else {
      bVar21 = 0;
    }
    sVar29 = (-(ushort)bVar21 & 0xfffe) + 4;
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar13 = il_buffer_put_byte7(buf,(int)sVar29), (char)iVar13 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar23 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar23;
      *psVar23 = sVar29;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar17;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar13 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar17 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar17) || (pcVar16 = sym_arg, iVar17 < -0x8000)) {
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar17 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar13 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar13 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar17 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar16 = decl_lookup_file_scope_twin(sym_00);
    if (g_c9il_mode == '\0') {
      if ((pcVar16->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(pcVar16);
        goto LAB_10638f6a;
      }
      uVar18 = pcVar16->key_ref >> 3;
    }
    else {
      uVar18 = pcVar16->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
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
        pcVar16 = sym_arg;
      }
      else {
        *(buf->bytes).pbEnd = bVar21 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_arg;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar16 = sym_segment_record(sym_00);
    if (g_c9il_mode == '\0') {
      if ((pcVar16->key_ref & 0xfffffff8) == 0) {
        uVar18 = il_symbol_key_assign(pcVar16);
        goto LAB_1063904f;
      }
      uVar18 = pcVar16->key_ref >> 3;
LAB_10639060:
      iVar17 = il_buffer_reserve(&buf->bytes,4);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
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
            pcVar16 = sym_arg;
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
            pcVar16 = sym_arg;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar21 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar16 = sym_arg;
        }
      }
    }
    else {
      uVar18 = pcVar16->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar18);
      pcVar16 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar9 = (sym_00->x28).bytes.bit_position;
    if ((uVar9 != '\0') && (uVar9 != '\x02')) {
      uVar9 = (-(uVar9 != '\x03') & 0xfeU) + 3;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,2);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = uVar9;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    stored_record = (uint *)g_function_ex_offset;
    uVar18 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar17 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        if ((iVar13 & 0xffffff80U) == 0) {
          *(buf->bytes).pbEnd = (uchar)iVar13;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          piVar27 = (int *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)piVar27;
          *piVar27 = iVar13;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
      iVar17 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        if ((uVar18 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar18;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar16 = sym_00;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar22 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar22;
          *puVar22 = uVar18;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar16 = sym_00;
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
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
      pcVar16 = sym_00;
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
      _rec_fflags = (int)(short)(((ushort)(sym_00->flags21 & 8) << 3 | (ushort)(sym_00->flags21 & 1)
                                 ) << 7) | (sym_00->flags4 & 0x80) >> 5 |
                    (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
                    (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                    (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar29;
      uVar28 = *(ushort *)(((uint)sym_00->type & -(uint)((sym_00->type->code & 0x80) != 0)) + 2);
      if (((uVar28 & 0x2000) != 0) && ((uVar28 & 0x4000) == 0)) {
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
      iVar17 = il_buffer_reserve(&buf->bytes,5);
      bVar21 = buf->open & (byte)iVar17 & 1;
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
      iVar17 = il_buffer_reserve(&buf->bytes,5);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        if ((int)_rec_fflags < 0x8000) {
          *(ushort *)(buf->bytes).pbEnd = rec_fflags;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          pcVar16 = sym_00;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(_rec_fflags >> 8) & 0xffffc0 | 0x40) << 9 | _rec_fflags & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar16 = sym_00;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x1c':
  case '\x1d':
    stored_record = (uint *)0x386;
    iVar17 = il_buffer_reserve(&buf->bytes,3);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      puVar25[0] = 0x86;
      puVar25[1] = '\x03';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar17 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      puVar25[0] = 0x96;
      puVar25[1] = 0xba;
      puVar25[2] = '0';
      puVar25[3] = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case ' ':
    iVar17 = 2;
LAB_10602252:
    iVar17 = il_buffer_reserve(&buf->bytes,iVar17);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar17 = il_buffer_reserve(&buf->bytes,6);
    bVar21 = buf->open & (byte)iVar17 & 1;
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
    puVar12 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar17 = il_buffer_reserve(&buf->bytes,2);
      bVar21 = buf->open & (byte)iVar17 & 1;
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
      iVar17 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      if (bVar21 != 0) {
        puVar25 = (buf->bytes).pbEnd;
        for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
          *(undefined4 *)puVar25 = *(undefined4 *)puVar12;
          puVar12 = puVar12 + 4;
          puVar25 = puVar25 + 4;
        }
        for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
          *puVar25 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar25 = puVar25 + 1;
        }
        puVar25 = (buf->bytes).pbEnd + uVar18;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar17 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar17 & 1;
      buf->open = bVar21;
      pcVar16 = sym_arg;
      if (bVar21 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar16 = sym_arg;
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
      iVar17 = il_buffer_reserve(&buf->bytes,6);
      bVar21 = buf->open & (byte)iVar17 & 1;
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
      for (; pcVar16 = sym_arg, stored_record = (uint *)pfVar5, pfVar5 != (fe_pragma_comment *)0x0;
          pfVar5 = pfVar5->next) {
        puVar12 = (uchar *)pfVar5->text;
        iVar17 = pfVar5->kind;
        iVar13 = il_buffer_reserve(&buf->bytes,2);
        bVar21 = buf->open & (byte)iVar13 & 1;
        buf->open = bVar21;
        if (bVar21 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar17;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar5->kind == 7) {
          if ((uchar)(*puVar12 + '\x01') != '\0') {
            stored_record = (uint *)(int)(char)(*puVar12 + '\x01');
            do {
              uVar9 = *puVar12;
              iVar17 = il_buffer_reserve(&buf->bytes,2);
              bVar21 = buf->open & (byte)iVar17 & 1;
              buf->open = bVar21;
              if (bVar21 != 0) {
                *(buf->bytes).pbEnd = uVar9;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar12 = puVar12 + 1;
              stored_record = (uint *)((int)stored_record + -1);
            } while (stored_record != (uint *)0x0);
          }
        }
        else {
          uVar18 = 0xffffffff;
          puVar30 = puVar12;
          do {
            if (uVar18 == 0) break;
            uVar18 = uVar18 - 1;
            uVar9 = *puVar30;
            puVar30 = puVar30 + 1;
          } while (uVar9 != '\0');
          uVar18 = ~uVar18;
          iVar17 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
          bVar21 = buf->open & (byte)iVar17 & 1;
          buf->open = bVar21;
          if (bVar21 != 0) {
            puVar25 = (buf->bytes).pbEnd;
            for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
              *(undefined4 *)puVar25 = *(undefined4 *)puVar12;
              puVar12 = puVar12 + 4;
              puVar25 = puVar25 + 4;
            }
            for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
              *puVar25 = *puVar12;
              puVar12 = puVar12 + 1;
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
      pfVar11 = &g_line_map_cached_row;
    }
    else {
      pfVar11 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    sym_keys = pfVar11->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar18 = sym_keys->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym_keys->entity = uVar18 & 0xffffff ^ sym_keys->entity;
    uVar18 = il_symbol_key_2((int)sym_keys);
    if (g_c9il_mode == '\0') {
      iVar17 = il_buffer_reserve(&buf->bytes,4);
      bVar21 = buf->open & (byte)iVar17 & 1;
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
    puVar12 = (uchar *)pp_position_file_name(&g_token_position);
    uVar18 = 0xffffffff;
    puVar30 = puVar12;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      uVar9 = *puVar30;
      puVar30 = puVar30 + 1;
    } while (uVar9 != '\0');
    uVar18 = ~uVar18;
    iVar17 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
        *(undefined4 *)puVar25 = *(undefined4 *)puVar12;
        puVar12 = puVar12 + 4;
        puVar25 = puVar25 + 4;
      }
      for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
        *puVar25 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar25 = puVar25 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar18;
      pcVar16 = sym_arg;
    }
    goto switchD_1060184c_caseD_12;
  case '#':
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      iVar13 = il_buffer_put_byte7(buf,(int)(short)iVar17);
      pcVar16 = sym_arg;
      if ((char)iVar13 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar23 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar23;
        *psVar23 = (short)iVar17;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar16 = sym_00;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar18 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar18 = g_next_entity_id;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar16 = sym_00;
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
    iVar17 = il_buffer_reserve(&buf->bytes,uVar18 + 1);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      puVar25 = (buf->bytes).pbEnd;
      for (uVar24 = uVar18 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
        *(undefined4 *)puVar25 = *(undefined4 *)puVar12;
        puVar12 = puVar12 + 4;
        puVar25 = puVar25 + 4;
      }
      for (uVar24 = uVar18 & 3; uVar24 != 0; uVar24 = uVar24 - 1) {
        *puVar25 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar25 = puVar25 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar18;
      pcVar16 = sym_arg;
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
    uVar18 = 2;
    if (g_c9il_mode == '\0') {
      uVar18 = 3;
    }
    if (g_dlp != '\0') {
      uVar18 = uVar18 | 8;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,5);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    if (bVar21 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar17 = il_buffer_put_byte7(buf,0xc), (char)iVar17 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar25 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar25;
      puVar25[0] = '\f';
      puVar25[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    if ((bVar21 != 0) && (iVar17 = il_buffer_put_byte7(buf,0), (char)iVar17 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar25 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar25;
      puVar25[0] = '\0';
      puVar25[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar17 = il_buffer_reserve(&buf->bytes,4);
    bVar21 = buf->open & (byte)iVar17 & 1;
    buf->open = bVar21;
    pcVar16 = sym_arg;
    if (bVar21 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
      pcVar16 = sym_00;
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    goto switchD_1060184c_caseD_2e;
  }
  iVar17 = il_buffer_reserve(&buf->bytes,6);
  bVar21 = buf->open & (byte)iVar17 & 1;
  buf->open = bVar21;
  pcVar16 = sym_arg;
  if ((bVar21 != 0) &&
     (iVar17 = il_buffer_put_byte7(buf,(uint)value), pcVar16 = sym_arg, (char)iVar17 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar25 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar25;
    *(c1_symbol_cell **)puVar25 = value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    pcVar16 = sym_00;
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

