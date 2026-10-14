void __cdecl
func_emit_inline_candidate
          (uint key,c1_symbol *sym,fe_il_buffer *buf,char fdef_mode,c1_type *sym_type,
          c1_type *derived_type,c1_type *elem_type,ushort base_code,int is_array,char *format,
          uint storage_bits,uint rec_word0,uint rec_word1,int record_class,c1_symbol *record_sym)

{
  PB *ppuVar1;
  char cVar2;
  c1_type *pcVar3;
  fe_name *name;
  fe_pragma_comment *pfVar4;
  fe_file_record *sym_keys;
  c1_u32 cVar5;
  c1_u8 cVar6;
  uchar uVar7;
  c1_symbol_cell *value;
  uint *src;
  c1_type *pcVar8;
  int iVar9;
  fe_line_map_row *pfVar10;
  uchar *puVar11;
  int iVar12;
  byte *pbVar13;
  void *pvVar14;
  c1_symbol *pcVar15;
  uint uVar16;
  PB puVar17;
  byte bVar18;
  byte bVar19;
  uint *puVar20;
  short *psVar21;
  uint uVar22;
  PB puVar23;
  ushort uVar24;
  ushort uVar25;
  short sVar26;
  uchar *puVar27;
  fe_pragma_comment *pfVar28;
  char *pcVar29;
  fe_pragma_comment *pfVar30;
  uint *in_stack_0000001c;
  ushort uVar31;
  ushort rec_fflags_high;
  
  diag_warning(4,0x2c6,sym);
LAB_1060213d:
  iVar9 = il_buffer_reserve(&buf->bytes,5);
  bVar19 = buf->open & (byte)iVar9 & 1;
  buf->open = bVar19;
  pcVar15 = sym;
  if (bVar19 != 0) {
    if ((int)key < 0x8000) {
      *(short *)(buf->bytes).pbEnd = (short)key;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    else {
      *(uint *)(buf->bytes).pbEnd = (uint)((uint3)(key >> 8) & 0xffffc0 | 0x40) << 9 | key & 0x7fff;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
  }
switchD_1060184c_caseD_12:
  sym = pcVar15;
  iVar9 = g_function_formal_count;
  puVar11 = (uchar *)g_source_file_ni;
  uVar16 = g_cv_precomp_signature;
  cVar2 = *format;
  if (cVar2 == '\0') {
    if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (record_class == 0xe)) {
        uVar16 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        puVar23 = g_il_gi_fdef.bytes.pbEnd;
        puVar17 = (PB)(uVar16 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar17;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.pbEnd = rec_word0;
          *(uint *)(puVar23 + 4) = rec_word1;
          *(uint *)(puVar23 + 8) = key;
          puVar17 = g_il_gi_fdef.bytes.pbEnd + 0xc;
          g_il_gi_fdef.bytes.pbEnd = puVar17;
        }
        ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                           CONCAT31((int3)((uint)puVar17 >> 8),(sym->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  format = format + 1;
  uVar31 = (ushort)key;
  rec_fflags_high = (ushort)(key >> 0x10);
  pcVar15 = sym;
  switch(cVar2) {
  case '\x01':
    bVar19 = sym->kind & 0x1f;
    if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
      value = (c1_symbol_cell *)type_size(elem_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(sym_type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar19 = sym->kind & 0x1f;
        if (bVar19 == 0xb) {
          type_check_size_known(sym_type);
        }
        else if (bVar19 == 0xc) {
          il_emit_symbol_part(sym_type,0,sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,
                              elem_type,base_code,is_array,format,storage_bits,rec_word0,rec_word1,
                              (ushort)key,(ushort)(key >> 0x10),record_class,record_sym);
          return;
        }
      }
    }
    if ((((sym->flags3 & 4) != 0) && ((sym_type->code & 0x200) != 0)) &&
       ((((sym_type->extra).sym)->flags4 & 1) != 0)) {
      il_emit_symbol_fragment
                ((uint)value,sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,
                 base_code,is_array,format,storage_bits,rec_word0,rec_word1,(ushort)key,
                 (ushort)(key >> 0x10),record_class,record_sym);
      return;
    }
    break;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar19 = sym->flags4;
      if (((((bVar19 & 0x80) == 0) || (bVar18 = sym->kind & 0x1f, bVar18 == 7)) || (bVar18 == 8)) ||
         (bVar18 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar18 = sym->kind & 0x1f;
      if (((bVar18 == 7) || (bVar18 == 8)) || (bVar18 == 6)) {
        if ((bVar19 & 2) != 0) {
          rec_word0 = rec_word0 | 0x100;
        }
        if ((sym->flags22 & 1) != 0) {
          rec_word0 = rec_word0 | 0x400;
        }
        if (((sym->x2c).function_flags & 1) != 0) {
          rec_word0 = rec_word0 | 0x80;
        }
      }
      if ((sym->key_ref & 3) != 0) {
        if (((bVar18 == 10) || (bVar18 == 0xb)) && ((bVar19 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar18 != 7) && (bVar18 != 8)) && (bVar18 != 6)) {
          rec_word0 = rec_word0 | 0x100;
        }
      }
      if ((sym->flags3 & 8) != 0) {
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
      if (((bVar18 == 7) || (bVar18 == 8)) || (bVar18 == 6)) {
        if ((sym->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((sym->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((sym->flags22 & 2) != 0) && (bVar18 != 7)) && (bVar18 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar18 == 10) && ((sym->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((sym->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((sym->flags3 & 4) == 0)) {
          pcVar8 = sym->type;
          cVar2 = (char)pcVar8->code;
          while (cVar2 < '\0') {
            pcVar8 = pcVar8->base;
            cVar2 = (char)pcVar8->code;
          }
          if ((pcVar8->flags & 0x18) != 0) goto LAB_106016e1;
        }
        if ((sym->flags22 & 8) == 0) {
          rec_word0 = rec_word0 | 0x20;
        }
      }
LAB_106016e1:
      il_emit_symbol_reference(buf,sym,rec_word0);
    }
    else {
      il_emit_symbol_reference(buf,sym,rec_word0);
    }
    goto switchD_1060184c_caseD_12;
  case '\x03':
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = (uchar)record_class;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x04':
    if (is_array == 0) {
      value = (c1_symbol_cell *)0x0;
    }
    else {
      value = (c1_symbol_cell *)sym_element_size(sym);
    }
    iVar9 = il_buffer_reserve(&buf->bytes,6);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if ((bVar19 != 0) && (iVar9 = il_buffer_put_byte7(buf,(uint)value), (char)iVar9 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar16 = il_symbol_key_assign(sym);
        goto LAB_106018ae;
      }
      uVar16 = sym->key_ref >> 3;
    }
    else {
      uVar16 = sym->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar16);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      bVar19 = (byte)uVar16;
      if (uVar16 < 0x3fff80) {
        if (uVar16 < 0x4000) {
          *(buf->bytes).pbEnd = bVar19 & 0x3f | 0x80;
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar16 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
        else {
          *(buf->bytes).pbEnd = bVar19 | 0xc0;
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar16 >> 6);
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar16 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar19 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar9 = il_buffer_reserve(&buf->bytes,6);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if ((bVar19 != 0) && (iVar9 = il_buffer_put_byte7(buf,0), (char)iVar9 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar23 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar23;
        puVar23[0] = '\0';
        puVar23[1] = '\0';
        puVar23[2] = '\0';
        puVar23[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar15 = sym;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar19 = sym->kind & 0x1f;
    if ((((bVar19 != 0) && (bVar19 < 0xf)) && (bVar19 != 5)) &&
       (((sym->flags23 & 1) != 0 &&
        (pvVar14 = sym_segment_record(sym), *(void **)((int)pvVar14 + 8) == g_name_drectve)))) {
      il_emit_symbol_fragment_2
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,(ushort)key,(ushort)(key >> 0x10),
                 record_class,record_sym);
      return;
    }
    if ((sym->kind & 0x1f) == 4) {
      value = (sym->x2c).references;
LAB_10601955:
      if (value != (c1_symbol_cell *)0x0) break;
    }
    else if ((sym->type->code & 0x300) != 0) {
      value = (c1_symbol_cell *)((sym->type->extra).tag)->debug_index;
      goto LAB_10601955;
    }
    value = (c1_symbol_cell *)sym_type->debug_index;
    break;
  case '\a':
    cVar6 = g_il_block_level;
    if (record_class == 3) {
      cVar6 = (sym->x28).bytes.bit_position;
    }
    goto LAB_10601974;
  case '\b':
    bVar19 = sym->kind & 0x1f;
    if (bVar19 == 9) {
      bVar19 = *(byte *)&sym->detail;
    }
    else if ((sym->flags3 & 8) == 0) {
      if ((bVar19 == 10) && ((sym->storage & 7) == 3)) {
        bVar19 = 0x24;
      }
      else {
        bVar19 = 0;
      }
    }
    else {
      bVar19 = -((sym->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(sym);
    uVar16 = 0xffffffff;
    puVar20 = src;
    do {
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      uVar22 = *puVar20;
      puVar20 = (uint *)((int)puVar20 + 1);
    } while ((char)uVar22 != '\0');
    cVar6 = il_buffer_reserve_ok(buf,~uVar16);
    pcVar15 = record_sym;
    if (cVar6 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar16);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar19 = sym->flags4;
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = ((bVar19 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar19 = sym->kind & 0x1f;
    if ((bVar19 == 0xb) || (bVar19 == 0xc)) {
      iVar9 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar19 = sym->storage & 7;
    if ((bVar19 != 0) && (bVar19 < 4)) {
      pcVar8 = sym_type;
      if ((sym_type->code & 0x8f) == 0x83) {
        pcVar8 = type_skip_arrays(sym_type->base);
      }
      if (((byte)pcVar8->flags >> 5 & 1) == 0) {
        if (((((sym->flags3 & 8) == 0) || ((sym->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((sym->flags23 & 1) != 0 &&
             (pbVar13 = sym_segment_record(sym), (*pbVar13 & 0x1f) == 0xe)) &&
            (pvVar14 = sym_segment_record(sym), (*(uint *)((int)pvVar14 + 0x1c) & 0xffffff) != 3))))
        {
          iVar9 = il_buffer_reserve(&buf->bytes,2);
          bVar19 = buf->open & (byte)iVar9 & 1;
          buf->open = bVar19;
          pcVar15 = record_sym;
          if (bVar19 != 0) {
            *(buf->bytes).pbEnd = '\x02';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar15 = sym;
          }
          goto switchD_1060184c_caseD_12;
        }
      }
      else if ((sym->flags23 & 1) != 0) {
        il_emit_symbol_fragment_3
                  (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                   is_array,format,storage_bits,rec_word0,rec_word1,(ushort)key,
                   (ushort)(key >> 0x10),record_class,record_sym);
        return;
      }
      iVar9 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\r':
    if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
      uVar25 = elem_type->code;
      cVar2 = (char)uVar25;
      if ((cVar2 < '\0') && (elem_type != (c1_type *)0x0)) {
        uVar24 = elem_type->flags;
      }
      else {
        uVar25 = 0;
        uVar24 = 0;
      }
      uVar16 = 0;
      pcVar8 = elem_type;
      while (cVar2 < '\0') {
        pcVar8 = pcVar8->base;
        cVar2 = (char)pcVar8->code;
      }
      base_code = pcVar8->code;
      pcVar8 = elem_type;
    }
    else {
      if (derived_type == (c1_type *)0x0) {
        uVar25 = 0;
        uVar24 = 0;
      }
      else {
        uVar25 = derived_type->code;
        uVar24 = derived_type->flags;
      }
      pcVar8 = sym_type;
      if ((base_code & 0x200) == 0) {
LAB_10601c71:
        uVar16 = 0;
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
            pcVar15 = (c1_symbol *)0x0;
          }
          else {
            pcVar15 = (pcVar3->extra).sym;
          }
          if ((pcVar15->tag_alignment & 0x100) == 0) goto LAB_10601c71;
        }
        uVar16 = 0x10;
      }
    }
    if ((uVar24 & 0x100) != 0) {
      uVar16 = uVar16 | 0x4000;
    }
    if ((uVar24 & 0x40) != 0) {
      uVar16 = uVar16 | 0x1000;
    }
    uVar25 = uVar25 & 0x8f;
    if (uVar25 == 0x83) {
      uVar16 = uVar16 | 6;
    }
    else if (((uVar25 == 0x82) || (uVar25 == 0x86)) || (uVar25 == 0x80)) {
      uVar16 = uVar16 | 3;
    }
    else {
      uVar25 = pcVar8->code;
      if ((uVar25 & 0x2000) == 0) {
        if ((((g_ms_extensions == '\0') && ((uVar25 & 0xfff) == 0x11)) && ((uVar25 & 0x1000) == 0))
           && (g_opt_J_unsigned_char != '\0')) {
          il_emit_symbol_fragment_5
                    (uVar16,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,
                     base_code,is_array,format,storage_bits,rec_word0,rec_word1,uVar31,
                     rec_fflags_high,record_class,record_sym);
          return;
        }
        uVar22 = (uint)base_code;
        if (uVar22 < 0x104) {
          if (uVar22 != 0x103) {
            switch(uVar22) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
              goto switchD_10601d6d_caseD_11;
            default:
code_r0x10601daf:
              if ((0x18 < uVar22) && (uVar22 < 0x1e)) goto switchD_10601d6d_caseD_11;
              break;
            case 0x26:
            case 0x27:
            case 0x28:
              uVar16 = uVar16 | 5;
              break;
            case 0x40:
              uVar16 = uVar16 | 7;
            }
            goto LAB_10601ca3;
          }
        }
        else {
          if (uVar22 < 0x403) {
            if (uVar22 != 0x402) {
              if ((uVar22 < 0x201) || (0x203 < uVar22)) goto code_r0x10601daf;
              uVar16 = uVar16 | 6;
              goto LAB_10601ca3;
            }
            goto code_r0x10601d74;
          }
          if (uVar22 != 0x1011) {
            il_emit_symbol_record_fragment
                      (uVar22,uVar16,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type
                       ,base_code,is_array,format,storage_bits,rec_word0,rec_word1,uVar31,
                       rec_fflags_high,record_class,record_sym);
            return;
          }
        }
switchD_10601d6d_caseD_11:
        uVar16 = uVar16 | 1;
      }
      else {
code_r0x10601d74:
        uVar16 = uVar16 | 2;
      }
    }
LAB_10601ca3:
    if (0x7f < (ushort)uVar16) {
      iVar9 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = (byte)(uVar16 >> 8) | 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar16;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0e':
    cVar5 = sym->key_ref;
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar5 & 3);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0f':
    name = sym->detail;
    if ((name != (fe_name *)0x0) && (name != g_name_unnamed)) {
      func_report_static_not_defined
                (name,buf,fdef_mode,sym_type,derived_type,(int)in_stack_0000001c,elem_type,base_code
                 ,is_array,format,storage_bits,rec_word0,rec_word1,uVar31,record_class,record_sym);
      return;
    }
LAB_10601a0e:
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((sym->flags22 & 4) == 0) || (record_class == 7)) {
      if (((sym->flags22 & 8) == 0) || (record_class == 7)) {
        if ((sym->storage & 0x40) == 0) {
          bVar19 = sym->storage & 7;
          if (((bVar19 < 4) || (6 < bVar19)) && (bVar19 != 3)) {
            if ((sym->flags3 & 4) == 0) {
              if (bVar19 == 1) goto LAB_10601e86;
              if ((is_array == 0) || (bVar19 = 2, (derived_type->extra).sym != (c1_symbol *)0x0)) {
                bVar19 = 3;
              }
            }
            else {
              bVar19 = 1;
            }
          }
          else {
            bVar19 = 4;
          }
        }
        else {
          bVar19 = (~sym->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar19 = 8;
      }
    }
    else if ((sym->flags1 & 1) == 0) {
LAB_10601e86:
      bVar19 = 2;
    }
    else {
      bVar19 = (-((sym->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = bVar19;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar19 = sym->kind & 0x1f;
    if ((((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) && ((sym->flags1 & 1) != 0)) {
      if ((sym->flags22 & 4) == 0) {
        if ((sym->flags22 & 8) == 0) {
          if ((sym->storage & 0x40) == 0) {
            cVar6 = (-((sym->storage & 7) != 3) & 2U) + 3;
          }
          else {
            cVar6 = '\x05';
          }
        }
        else {
          cVar6 = '\n';
        }
      }
      else {
        cVar6 = '\t';
      }
    }
    else {
      bVar19 = sym->storage & 7;
      if ((bVar19 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
        diag_error(0x81,sym);
        cVar6 = '\x02';
      }
      else {
        if (((sym->flags21 & 1) != 0) && (bVar19 != 1)) {
          func_check_inline_definitions
                    (sym,buf,fdef_mode,sym_type,derived_type,elem_type,base_code,is_array,format,
                     storage_bits,rec_word0,rec_word1,uVar31,record_class,record_sym);
          return;
        }
        cVar6 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
      }
    }
LAB_10601974:
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = cVar6;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar9 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar9 = (sym->x28).value;
    if ((iVar9 < 0x8000) && (-0x8001 < iVar9)) {
      bVar19 = 1;
    }
    else {
      bVar19 = 0;
    }
    sVar26 = (-(ushort)bVar19 & 0xfffe) + 4;
    iVar12 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar19;
    if ((bVar19 != 0) && (iVar12 = il_buffer_put_byte7(buf,(int)sVar26), (char)iVar12 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar21 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar21;
      *psVar21 = sVar26;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar12 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar9;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar12 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar9 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar9) || (pcVar15 = record_sym, iVar9 < -0x8000)) {
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar9 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar9 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar15 = decl_lookup_file_scope_twin(sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar15->key_ref & 0xfffffff8) == 0) {
        uVar16 = il_symbol_key_assign(pcVar15);
        goto LAB_10638f6a;
      }
      uVar16 = pcVar15->key_ref >> 3;
    }
    else {
      uVar16 = pcVar15->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      bVar19 = (byte)uVar16;
      if (uVar16 < 0x3fff80) {
        if (uVar16 < 0x4000) {
          *(buf->bytes).pbEnd = bVar19 & 0x3f | 0x80;
          goto LAB_10638fd8;
        }
        *(buf->bytes).pbEnd = bVar19 | 0xc0;
        puVar23 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar23;
        *puVar23 = (uchar)(uVar16 >> 6);
        puVar23 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar23;
        *puVar23 = (uchar)(uVar16 >> 0xe);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = bVar19 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar15 = sym_segment_record(sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar15->key_ref & 0xfffffff8) == 0) {
        uVar16 = il_symbol_key_assign(pcVar15);
        goto LAB_1063904f;
      }
      uVar16 = pcVar15->key_ref >> 3;
LAB_10639060:
      iVar9 = il_buffer_reserve(&buf->bytes,4);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        bVar19 = (byte)uVar16;
        if (uVar16 < 0x3fff80) {
          if (uVar16 < 0x4000) {
            *(buf->bytes).pbEnd = bVar19 & 0x3f | 0x80;
LAB_10638fd8:
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar15 = record_sym;
          }
          else {
            *(buf->bytes).pbEnd = bVar19 | 0xc0;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 6);
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar19 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      uVar16 = pcVar15->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar16);
      pcVar15 = record_sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar7 = (sym->x28).bytes.bit_position;
    if ((uVar7 != '\0') && (uVar7 != '\x02')) {
      uVar7 = (-(uVar7 != '\x03') & 0xfeU) + 3;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = uVar7;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    uVar16 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    in_stack_0000001c = (uint *)g_function_ex_offset;
    if (g_c9il_mode != '\0') {
      iVar9 = il_buffer_reserve(&buf->bytes,6);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        if (((uint)in_stack_0000001c & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)in_stack_0000001c;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *(uint **)puVar23 = in_stack_0000001c;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
      iVar9 = il_buffer_reserve(&buf->bytes,6);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        if ((uVar16 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar20 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar20;
          *puVar20 = uVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar15 = sym;
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
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1a':
    if (fdef_mode != '\0') {
      iVar9 = il_buffer_reserve(&buf->bytes,5);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        if ((int)key < 0x8000) {
          *(short *)(buf->bytes).pbEnd = (short)key;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          pcVar15 = sym;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(key >> 8) & 0xffffc0 | 0x40) << 9 | key & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar15 = sym;
        }
      }
      goto switchD_1060184c_caseD_12;
    }
    if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
      sVar26 = 0;
    }
    else {
      sVar26 = 0x1000;
    }
    key = (int)(short)(((ushort)(sym->flags21 & 8) << 3 | (ushort)(sym->flags21 & 1)) << 7) |
          (sym->flags4 & 0x80) >> 5 |
          (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
          (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
          (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar26;
    uVar31 = *(ushort *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 2);
    if (((uVar31 & 0x2000) != 0) && ((uVar31 & 0x4000) == 0)) {
      g_function_not_inlinable = 1;
    }
    if (g_inline_level == 1) {
LAB_10602124:
      if (g_function_not_inlinable != 0) goto LAB_10602193;
LAB_10602128:
      if ((sym->type->flags & 0x8000) == 0) {
        if ((sym->flags21 & 1) != 0) {
          key = key | 0x40;
        }
        goto LAB_1060213d;
      }
    }
    else {
      if (g_inline_level != 2) goto LAB_1060213d;
      if (g_function_auto_inline == 0) goto LAB_10602124;
      if (g_function_not_inlinable == 0) {
        if ((((sym->storage & 7) == 3) && (((byte)sym->key_ref & 3) == 1)) ||
           (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
          key = key | 0x40;
        }
        goto LAB_10602128;
      }
    }
LAB_10602193:
    key = (int)(short)key & 0xffffffbf;
    if ((sym->flags21 & 1) != 0) {
      func_emit_inline_candidate
                (key,sym,buf,'\0',sym_type,derived_type,elem_type,base_code,is_array,format,
                 storage_bits,rec_word0,rec_word1,record_class,record_sym);
      return;
    }
    goto LAB_1060213d;
  case '\x1c':
  case '\x1d':
    in_stack_0000001c = (uint *)0x386;
    iVar9 = il_buffer_reserve(&buf->bytes,3);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(short *)(buf->bytes).pbEnd = (short)in_stack_0000001c;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar9 = il_buffer_reserve(&buf->bytes,5);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      puVar23 = (buf->bytes).pbEnd;
      puVar23[0] = 0x96;
      puVar23[1] = 0xba;
      puVar23[2] = '0';
      puVar23[3] = '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case ' ':
    iVar9 = 2;
LAB_10602252:
    iVar9 = il_buffer_reserve(&buf->bytes,iVar9);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar9 = il_buffer_reserve(&buf->bytes,6);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      if ((uVar16 & 0xffffff80) == 0) {
        *(buf->bytes).pbEnd = (uchar)uVar16;
        puVar23 = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = 0x80;
        puVar20 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar20;
        *puVar20 = uVar16;
        puVar23 = (buf->bytes).pbEnd + 4;
      }
      (buf->bytes).pbEnd = puVar23;
    }
    puVar11 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar9 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = '\0';
        puVar23 = (buf->bytes).pbEnd + 1;
LAB_106022da:
        (buf->bytes).pbEnd = puVar23;
      }
    }
    else {
      uVar16 = 0xffffffff;
      pcVar29 = g_il_pch_name;
      do {
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        cVar2 = *pcVar29;
        pcVar29 = pcVar29 + 1;
      } while (cVar2 != '\0');
      uVar16 = ~uVar16;
      iVar9 = il_buffer_reserve(&buf->bytes,uVar16 + 1);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        puVar23 = (buf->bytes).pbEnd;
        for (uVar22 = uVar16 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
          *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
          puVar11 = puVar11 + 4;
          puVar23 = puVar23 + 4;
        }
        for (uVar22 = uVar16 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
          *puVar23 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar23 = puVar23 + 1;
        }
        puVar23 = (buf->bytes).pbEnd + uVar16;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar9 = il_buffer_reserve(&buf->bytes,6);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pcVar15 = record_sym;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    else {
      uVar16 = 0;
      pfVar30 = (fe_pragma_comment *)0x0;
      pfVar28 = g_pragma_comment_list;
      while (g_pragma_comment_list = pfVar30, pfVar28 != (fe_pragma_comment *)0x0) {
        pfVar4 = pfVar28->next;
        pfVar28->next = g_pragma_comment_list;
        uVar16 = uVar16 + 1;
        pfVar30 = pfVar28;
        pfVar28 = pfVar4;
      }
      iVar9 = il_buffer_reserve(&buf->bytes,6);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      pfVar28 = g_pragma_comment_list;
      if (bVar19 != 0) {
        if ((uVar16 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar16;
          puVar23 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar20 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar20;
          *puVar20 = uVar16;
          puVar23 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar23;
        pfVar28 = g_pragma_comment_list;
      }
      for (; in_stack_0000001c = (uint *)0x0, pcVar15 = record_sym,
          pfVar28 != (fe_pragma_comment *)0x0; pfVar28 = pfVar28->next) {
        puVar11 = (uchar *)pfVar28->text;
        iVar9 = pfVar28->kind;
        pfVar30 = pfVar28;
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar19 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar19;
        if (bVar19 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar9;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar28->kind == 7) {
          if ((uchar)(*puVar11 + '\x01') != '\0') {
            iVar9 = (int)(char)(*puVar11 + '\x01');
            do {
              uVar7 = *puVar11;
              iVar12 = il_buffer_reserve(&buf->bytes,2);
              bVar19 = buf->open & (byte)iVar12 & 1;
              buf->open = bVar19;
              if (bVar19 != 0) {
                *(buf->bytes).pbEnd = uVar7;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar11 = puVar11 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else {
          uVar16 = 0xffffffff;
          puVar27 = puVar11;
          do {
            if (uVar16 == 0) break;
            uVar16 = uVar16 - 1;
            uVar7 = *puVar27;
            puVar27 = puVar27 + 1;
          } while (uVar7 != '\0');
          uVar16 = ~uVar16;
          pfVar28 = pfVar30;
          iVar9 = il_buffer_reserve(&buf->bytes,uVar16 + 1);
          bVar19 = buf->open & (byte)iVar9 & 1;
          buf->open = bVar19;
          if (bVar19 != 0) {
            puVar23 = (buf->bytes).pbEnd;
            for (uVar22 = uVar16 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
              *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
              puVar11 = puVar11 + 4;
              puVar23 = puVar23 + 4;
            }
            for (uVar22 = uVar16 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
              *puVar23 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar23 = puVar23 + 1;
            }
            ppuVar1 = &(buf->bytes).pbEnd;
            *ppuVar1 = *ppuVar1 + uVar16;
          }
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\"':
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar10 = &g_line_map_cached_row;
    }
    else {
      pfVar10 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    sym_keys = pfVar10->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar16 = sym_keys->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym_keys->entity = uVar16 & 0xffffff ^ sym_keys->entity;
    uVar16 = il_symbol_key_2((int)sym_keys);
    if (g_c9il_mode == '\0') {
      iVar9 = il_buffer_reserve(&buf->bytes,4);
      bVar19 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        bVar19 = (byte)uVar16;
        if (uVar16 < 0x3fff80) {
          if (uVar16 < 0x4000) {
            *(buf->bytes).pbEnd = bVar19 & 0x3f | 0x80;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar19 | 0xc0;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 6);
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar16 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar19 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar16);
    }
    puVar11 = (uchar *)pp_position_file_name(&g_token_position);
    uVar16 = 0xffffffff;
    puVar27 = puVar11;
    do {
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      uVar7 = *puVar27;
      puVar27 = puVar27 + 1;
    } while (uVar7 != '\0');
    uVar16 = ~uVar16;
    iVar9 = il_buffer_reserve(&buf->bytes,uVar16 + 1);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      puVar23 = (buf->bytes).pbEnd;
      for (uVar22 = uVar16 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
        *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
        puVar11 = puVar11 + 4;
        puVar23 = puVar23 + 4;
      }
      for (uVar22 = uVar16 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
        *puVar23 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar23 = puVar23 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar16;
    }
    goto switchD_1060184c_caseD_12;
  case '#':
    iVar12 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      iVar12 = il_buffer_put_byte7(buf,(int)(short)iVar9);
      if ((char)iVar12 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar21 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar21;
        *psVar21 = (short)iVar9;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar16 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar16 = g_next_entity_id;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,5);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar16;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '&':
    uVar16 = 0xffffffff;
    pcVar29 = (char *)g_source_file_ni;
    do {
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      cVar2 = *pcVar29;
      pcVar29 = pcVar29 + 1;
    } while (cVar2 != '\0');
    uVar16 = ~uVar16;
    iVar9 = il_buffer_reserve(&buf->bytes,uVar16 + 1);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      puVar23 = (buf->bytes).pbEnd;
      for (uVar22 = uVar16 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
        *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
        puVar11 = puVar11 + 4;
        puVar23 = puVar23 + 4;
      }
      for (uVar22 = uVar16 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
        *puVar23 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar23 = puVar23 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar16;
    }
    goto switchD_1060184c_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_2
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,uVar31,rec_fflags_high,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_3
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,uVar31,rec_fflags_high,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case '*':
    uVar16 = 2;
    if (g_c9il_mode == '\0') {
      uVar16 = 3;
    }
    if (g_dlp != '\0') {
      uVar16 = uVar16 | 8;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,5);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    if (bVar19 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar16;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    if ((bVar19 != 0) && (iVar9 = il_buffer_put_byte7(buf,0xc), (char)iVar9 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar23 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar23;
      puVar23[0] = '\f';
      puVar23[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    if ((bVar19 != 0) && (iVar9 = il_buffer_put_byte7(buf,0), (char)iVar9 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar23 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar23;
      puVar23[0] = '\0';
      puVar23[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar9 = il_buffer_reserve(&buf->bytes,4);
    bVar19 = buf->open & (byte)iVar9 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    if (g_opt_Ct != '\0') {
      il_emit_symbol_inline_fragment
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,uVar31,rec_fflags_high,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  }
  iVar9 = il_buffer_reserve(&buf->bytes,6);
  bVar19 = buf->open & (byte)iVar9 & 1;
  buf->open = bVar19;
  pcVar15 = record_sym;
  if ((bVar19 != 0) && (iVar9 = il_buffer_put_byte7(buf,(uint)value), (char)iVar9 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar23 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar23;
    *(c1_symbol_cell **)puVar23 = value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    pcVar15 = sym;
  }
  goto switchD_1060184c_caseD_12;
}

