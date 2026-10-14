void __cdecl
func_check_inline_definitions
          (c1_symbol *sym,fe_il_buffer *buf,char fdef_mode,c1_type *sym_type,c1_type *derived_type,
          c1_type *elem_type,ushort base_code,int is_array,char *format,uint storage_bits,
          uint rec_word0,uint rec_word1,ushort rec_word2,int record_class,c1_symbol *record_sym)

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
  int iVar8;
  uint *src;
  c1_type *pcVar9;
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
  uint uVar29;
  char *pcVar30;
  fe_pragma_comment *pfVar31;
  uint *in_stack_0000001c;
  ushort in_stack_00000042;
  
  diag_warning(1,0x1fa,sym);
  uVar16 = _rec_word2;
LAB_10601edb:
  _rec_word2 = uVar16;
  cVar6 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
LAB_10601974:
  iVar8 = il_buffer_reserve(&buf->bytes,2);
  bVar18 = buf->open & (byte)iVar8 & 1;
  buf->open = bVar18;
  pcVar15 = record_sym;
  uVar16 = _rec_word2;
  if (bVar18 != 0) {
    *(buf->bytes).pbEnd = cVar6;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    pcVar15 = sym;
  }
switchD_1060184c_caseD_12:
  _rec_word2 = uVar16;
  sym = pcVar15;
  uVar16 = _rec_word2;
  iVar8 = g_function_formal_count;
  puVar11 = (uchar *)g_source_file_ni;
  uVar29 = g_cv_precomp_signature;
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
          *(uint *)(puVar23 + 8) = _rec_word2;
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
  in_stack_00000042 = (ushort)(_rec_word2 >> 0x10);
  pcVar15 = sym;
  _rec_word2 = uVar16;
  switch(cVar2) {
  case '\x01':
    bVar18 = sym->kind & 0x1f;
    if (((bVar18 == 7) || (bVar18 == 8)) || (bVar18 == 6)) {
      value = (c1_symbol_cell *)type_size(elem_type);
    }
    else {
      value = (c1_symbol_cell *)type_size(sym_type);
      if (value == (c1_symbol_cell *)0x0) {
        bVar18 = sym->kind & 0x1f;
        if (bVar18 == 0xb) {
          type_check_size_known(sym_type);
        }
        else if (bVar18 == 0xc) {
          il_emit_symbol_part(sym_type,0,sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,
                              elem_type,base_code,is_array,format,storage_bits,rec_word0,rec_word1,
                              rec_word2,in_stack_00000042,record_class,record_sym);
          return;
        }
      }
    }
    if ((((sym->flags3 & 4) != 0) && ((sym_type->code & 0x200) != 0)) &&
       ((((sym_type->extra).sym)->flags4 & 1) != 0)) {
      il_emit_symbol_fragment
                ((uint)value,sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,
                 base_code,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,
                 in_stack_00000042,record_class,record_sym);
      return;
    }
    break;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar18 = sym->flags4;
      if (((((bVar18 & 0x80) == 0) || (bVar19 = sym->kind & 0x1f, bVar19 == 7)) || (bVar19 == 8)) ||
         (bVar19 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar19 = sym->kind & 0x1f;
      if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
        if ((bVar18 & 2) != 0) {
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
        if (((bVar19 == 10) || (bVar19 == 0xb)) && ((bVar18 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if (((bVar19 != 7) && (bVar19 != 8)) && (bVar19 != 6)) {
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
      if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
        if ((sym->flags4 & 0x10) != 0) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((sym->flags4 & 1) != 0) {
          rec_word0 = rec_word0 | 0x1000;
        }
      }
      if ((((sym->flags22 & 2) != 0) && (bVar19 != 7)) && (bVar19 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar19 == 10) && ((sym->flags21 & 0x80) != 0)) {
        rec_word0 = rec_word0 | 0x40;
      }
      if ((sym->storage & 0x40) != 0) {
        if ((record_class != 0xe) && ((sym->flags3 & 4) == 0)) {
          pcVar9 = sym->type;
          cVar2 = (char)pcVar9->code;
          while (cVar2 < '\0') {
            pcVar9 = pcVar9->base;
            cVar2 = (char)pcVar9->code;
          }
          if ((pcVar9->flags & 0x18) != 0) goto LAB_106016e1;
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
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
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
    iVar8 = il_buffer_reserve(&buf->bytes,6);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if ((bVar18 != 0) && (iVar8 = il_buffer_put_byte7(buf,(uint)value), (char)iVar8 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      goto LAB_10601602;
    }
    goto switchD_1060184c_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar29 = il_symbol_key_assign(sym);
        goto LAB_106018ae;
      }
      uVar29 = sym->key_ref >> 3;
    }
    else {
      uVar29 = sym->entity & 0xffffff;
LAB_106018ae:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar29);
        goto switchD_1060184c_caseD_12;
      }
    }
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      bVar18 = (byte)uVar29;
      if (uVar29 < 0x3fff80) {
        if (uVar29 < 0x4000) {
          *(buf->bytes).pbEnd = bVar18 & 0x3f | 0x80;
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar29 >> 6);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
        else {
          *(buf->bytes).pbEnd = bVar18 | 0xc0;
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar29 >> 6);
          puVar23 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar23;
          *puVar23 = (uchar)(uVar29 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
      }
      else {
        *(buf->bytes).pbEnd = bVar18 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar8 = il_buffer_reserve(&buf->bytes,6);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if ((bVar18 != 0) && (iVar8 = il_buffer_put_byte7(buf,0), (char)iVar8 == '\0')) {
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
    bVar18 = sym->kind & 0x1f;
    if ((((bVar18 != 0) && (bVar18 < 0xf)) && (bVar18 != 5)) &&
       (((sym->flags23 & 1) != 0 &&
        (pvVar14 = sym_segment_record(sym), *(void **)((int)pvVar14 + 8) == g_name_drectve)))) {
      il_emit_symbol_fragment_2
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
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
    goto switchD_1060184c_caseD_7;
  case '\b':
    bVar18 = sym->kind & 0x1f;
    if (bVar18 == 9) {
      bVar18 = *(byte *)&sym->detail;
    }
    else if ((sym->flags3 & 8) == 0) {
      if ((bVar18 == 10) && ((sym->storage & 7) == 3)) {
        bVar18 = 0x24;
      }
      else {
        bVar18 = 0;
      }
    }
    else {
      bVar18 = -((sym->storage & 7) != 2) & 0x25;
    }
    goto LAB_106019ae;
  case '\t':
    if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) goto LAB_10601a0e;
    src = (uint *)decorate_check_name_length(sym);
    uVar29 = 0xffffffff;
    puVar20 = src;
    do {
      if (uVar29 == 0) break;
      uVar29 = uVar29 - 1;
      uVar22 = *puVar20;
      puVar20 = (uint *)((int)puVar20 + 1);
    } while ((char)uVar22 != '\0');
    cVar6 = il_buffer_reserve_ok(buf,~uVar29);
    pcVar15 = record_sym;
    if (cVar6 != '\0') {
      il_buffer_put_bytes(buf,src,~uVar29);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\n':
    bVar18 = sym->flags4;
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = ((bVar18 & 4) != 0) + '\x01';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\v':
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\f':
    bVar18 = sym->kind & 0x1f;
    if ((bVar18 == 0xb) || (bVar18 == 0xc)) {
      iVar8 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = '\x03';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
      goto switchD_1060184c_caseD_12;
    }
    bVar18 = sym->storage & 7;
    if ((bVar18 != 0) && (bVar18 < 4)) {
      pcVar9 = sym_type;
      if ((sym_type->code & 0x8f) == 0x83) {
        pcVar9 = type_skip_arrays(sym_type->base);
      }
      if (((byte)pcVar9->flags >> 5 & 1) == 0) {
        if (((((sym->flags3 & 8) == 0) || ((sym->storage & 0x40) == 0)) ||
            (g_string_pooling_readonly == '\0')) ||
           ((((sym->flags23 & 1) != 0 &&
             (pbVar13 = sym_segment_record(sym), (*pbVar13 & 0x1f) == 0xe)) &&
            (pvVar14 = sym_segment_record(sym), (*(uint *)((int)pvVar14 + 0x1c) & 0xffffff) != 3))))
        {
          iVar8 = il_buffer_reserve(&buf->bytes,2);
          bVar18 = buf->open & (byte)iVar8 & 1;
          buf->open = bVar18;
          pcVar15 = record_sym;
          if (bVar18 != 0) {
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
                   is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                   record_class,record_sym);
        return;
      }
      iVar8 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = '\x04';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
      goto switchD_1060184c_caseD_12;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
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
      uVar29 = 0;
      pcVar9 = elem_type;
      while (cVar2 < '\0') {
        pcVar9 = pcVar9->base;
        cVar2 = (char)pcVar9->code;
      }
      base_code = pcVar9->code;
      pcVar9 = elem_type;
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
      pcVar9 = sym_type;
      if ((base_code & 0x200) == 0) {
LAB_10601c71:
        uVar29 = 0;
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
        uVar29 = 0x10;
      }
    }
    if ((uVar24 & 0x100) != 0) {
      uVar29 = uVar29 | 0x4000;
    }
    if ((uVar24 & 0x40) != 0) {
      uVar29 = uVar29 | 0x1000;
    }
    uVar25 = uVar25 & 0x8f;
    if (uVar25 == 0x83) {
      uVar29 = uVar29 | 6;
    }
    else if (((uVar25 == 0x82) || (uVar25 == 0x86)) || (uVar25 == 0x80)) {
      uVar29 = uVar29 | 3;
    }
    else {
      uVar25 = pcVar9->code;
      if ((uVar25 & 0x2000) == 0) {
        if ((((g_ms_extensions == '\0') && ((uVar25 & 0xfff) == 0x11)) && ((uVar25 & 0x1000) == 0))
           && (g_opt_J_unsigned_char != '\0')) {
          il_emit_symbol_fragment_5
                    (uVar29,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,
                     base_code,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,
                     in_stack_00000042,record_class,record_sym);
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
              uVar29 = uVar29 | 5;
              break;
            case 0x40:
              uVar29 = uVar29 | 7;
            }
            goto LAB_10601ca3;
          }
        }
        else {
          if (uVar22 < 0x403) {
            if (uVar22 != 0x402) {
              if ((uVar22 < 0x201) || (0x203 < uVar22)) goto code_r0x10601daf;
              uVar29 = uVar29 | 6;
              goto LAB_10601ca3;
            }
            goto code_r0x10601d74;
          }
          if (uVar22 != 0x1011) {
            il_emit_symbol_record_fragment
                      (uVar22,uVar29,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type
                       ,base_code,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,
                       in_stack_00000042,record_class,record_sym);
            return;
          }
        }
switchD_10601d6d_caseD_11:
        uVar29 = uVar29 | 1;
      }
      else {
code_r0x10601d74:
        uVar29 = uVar29 | 2;
      }
    }
LAB_10601ca3:
    if (0x7f < (ushort)uVar29) {
      iVar8 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = (byte)(uVar29 >> 8) | 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = (uchar)uVar29;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0e':
    cVar5 = sym->key_ref;
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar5 & 3);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x0f':
    name = sym->detail;
    if ((name != (fe_name *)0x0) && (name != g_name_unnamed)) {
      func_report_static_not_defined
                (name,buf,fdef_mode,sym_type,derived_type,(int)in_stack_0000001c,elem_type,base_code
                 ,is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,record_class,record_sym
                );
      return;
    }
LAB_10601a0e:
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x10':
    if (((sym->flags22 & 4) == 0) || (record_class == 7)) {
      if (((sym->flags22 & 8) == 0) || (record_class == 7)) {
        if ((sym->storage & 0x40) == 0) {
          bVar18 = sym->storage & 7;
          if (((bVar18 < 4) || (6 < bVar18)) && (bVar18 != 3)) {
            if ((sym->flags3 & 4) == 0) {
              if (bVar18 == 1) goto LAB_10601e86;
              if ((is_array == 0) || (bVar18 = 2, (derived_type->extra).sym != (c1_symbol *)0x0)) {
                bVar18 = 3;
              }
            }
            else {
              bVar18 = 1;
            }
          }
          else {
            bVar18 = 4;
          }
        }
        else {
          bVar18 = (~sym->flags3 & 4 | 2) >> 1;
        }
      }
      else {
        bVar18 = 8;
      }
    }
    else if ((sym->flags1 & 1) == 0) {
LAB_10601e86:
      bVar18 = 2;
    }
    else {
      bVar18 = (-((sym->flags3 & 4) != 0) & 0xfeU) + 9;
    }
LAB_106019ae:
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar19 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar19;
    pcVar15 = record_sym;
    if (bVar19 != 0) {
      *(buf->bytes).pbEnd = bVar18;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x11':
    bVar18 = sym->kind & 0x1f;
    if ((((bVar18 == 7) || (bVar18 == 8)) || (bVar18 == 6)) && ((sym->flags1 & 1) != 0)) {
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
      goto LAB_10601974;
    }
    bVar18 = sym->storage & 7;
    if ((bVar18 != 3) || ((g_incremental != '\0' && (g_opt_GI == '\0')))) {
      if (((sym->flags21 & 1) != 0) && (bVar18 != 1)) {
        func_check_inline_definitions
                  (sym,buf,fdef_mode,sym_type,derived_type,elem_type,base_code,is_array,format,
                   storage_bits,rec_word0,rec_word1,rec_word2,record_class,record_sym);
        return;
      }
      goto LAB_10601edb;
    }
    diag_error(0x81,sym);
    cVar6 = '\x02';
    goto LAB_10601974;
  default:
    goto switchD_1060184c_caseD_12;
  case '\x13':
    iVar8 = 6;
    goto LAB_10602252;
  case '\x14':
    iVar8 = (sym->x28).value;
    if ((iVar8 < 0x8000) && (-0x8001 < iVar8)) {
      bVar18 = 1;
    }
    else {
      bVar18 = 0;
    }
    sVar26 = (-(ushort)bVar18 & 0xfffe) + 4;
    iVar12 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar18;
    if ((bVar18 != 0) && (iVar12 = il_buffer_put_byte7(buf,(int)sVar26), (char)iVar12 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      psVar21 = (short *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)psVar21;
      *psVar21 = sVar26;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar12 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar18;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = (uchar)iVar8;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    iVar12 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar18;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = (uchar)((uint)iVar8 >> 8);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    }
    if ((0x7fff < iVar8) || (pcVar15 = record_sym, iVar8 < -0x8000)) {
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar8 >> 0x10);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar8 >> 0x18);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x15':
    pcVar15 = decl_lookup_file_scope_twin(sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar15->key_ref & 0xfffffff8) == 0) {
        uVar29 = il_symbol_key_assign(pcVar15);
        goto LAB_10638f6a;
      }
      uVar29 = pcVar15->key_ref >> 3;
    }
    else {
      uVar29 = pcVar15->entity & 0xffffff;
LAB_10638f6a:
      if (g_c9il_mode != '\0') goto LAB_10638f73;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      bVar18 = (byte)uVar29;
      if (uVar29 < 0x3fff80) {
        if (uVar29 < 0x4000) {
          *(buf->bytes).pbEnd = bVar18 & 0x3f | 0x80;
          goto LAB_10638fd8;
        }
        *(buf->bytes).pbEnd = bVar18 | 0xc0;
        puVar23 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar23;
        *puVar23 = (uchar)(uVar29 >> 6);
        puVar23 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar23;
        *puVar23 = (uchar)(uVar29 >> 0xe);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = bVar18 + 0x80;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x16':
    pcVar15 = sym_segment_record(sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar15->key_ref & 0xfffffff8) == 0) {
        uVar29 = il_symbol_key_assign(pcVar15);
        goto LAB_1063904f;
      }
      uVar29 = pcVar15->key_ref >> 3;
LAB_10639060:
      iVar8 = il_buffer_reserve(&buf->bytes,4);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        bVar18 = (byte)uVar29;
        if (uVar29 < 0x3fff80) {
          if (uVar29 < 0x4000) {
            *(buf->bytes).pbEnd = bVar18 & 0x3f | 0x80;
LAB_10638fd8:
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar15 = record_sym;
          }
          else {
            *(buf->bytes).pbEnd = bVar18 | 0xc0;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 6);
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar18 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      uVar29 = pcVar15->entity & 0xffffff;
LAB_1063904f:
      if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
      il_buffer_put_id(buf,uVar29);
      pcVar15 = record_sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x17':
    uVar7 = (sym->x28).bytes.bit_position;
    if ((uVar7 != '\0') && (uVar7 != '\x02')) {
      uVar7 = (-(uVar7 != '\x03') & 0xfeU) + 3;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,2);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = uVar7;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x18':
    uVar29 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    in_stack_0000001c = (uint *)g_function_ex_offset;
    if (g_c9il_mode != '\0') {
      iVar8 = il_buffer_reserve(&buf->bytes,6);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
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
      iVar8 = il_buffer_reserve(&buf->bytes,6);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        if ((uVar29 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar29;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar15 = sym;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar20 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar20;
          *puVar20 = uVar29;
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
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1a':
    if (fdef_mode == '\0') {
      if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
        sVar26 = 0;
      }
      else {
        sVar26 = 0x1000;
      }
      uVar16 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 | (ushort)(sym->flags21 & 1)) << 7) |
               (sym->flags4 & 0x80) >> 5 |
               (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
               (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
               (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar26;
      uVar25 = *(ushort *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 2);
      if (((uVar25 & 0x2000) != 0) && ((uVar25 & 0x4000) == 0)) {
        g_function_not_inlinable = 1;
      }
      if (g_inline_level == 1) {
LAB_10602124:
        if (g_function_not_inlinable == 0) {
LAB_10602128:
          if ((sym->type->flags & 0x8000) == 0) {
            if ((sym->flags21 & 1) != 0) {
              uVar16 = uVar16 | 0x40;
            }
            goto LAB_1060213d;
          }
        }
LAB_10602193:
        uVar16 = (int)(short)uVar16 & 0xffffffbf;
        if ((sym->flags21 & 1) != 0) {
          func_emit_inline_candidate
                    (uVar16,sym,buf,'\0',sym_type,derived_type,elem_type,base_code,is_array,format,
                     storage_bits,rec_word0,rec_word1,record_class,record_sym);
          return;
        }
      }
      else if (g_inline_level == 2) {
        if (g_function_auto_inline == 0) goto LAB_10602124;
        if (g_function_not_inlinable == 0) {
          if ((((sym->storage & 7) == 3) && (((byte)sym->key_ref & 3) == 1)) ||
             (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
            uVar16 = uVar16 | 0x40;
          }
          goto LAB_10602128;
        }
        goto LAB_10602193;
      }
LAB_1060213d:
      iVar8 = il_buffer_reserve(&buf->bytes,5);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        if (uVar16 < 0x8000) {
          *(short *)(buf->bytes).pbEnd = (short)uVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
        else {
          *(uint *)(buf->bytes).pbEnd = uVar16 | 0x8000;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        }
      }
    }
    else {
      iVar8 = il_buffer_reserve(&buf->bytes,5);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        if ((int)uVar16 < 0x8000) {
          *(ushort *)(buf->bytes).pbEnd = rec_word2;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          pcVar15 = sym;
        }
        else {
          *(uint *)(buf->bytes).pbEnd =
               (uint)((uint3)(uVar16 >> 8) & 0xffffc0 | 0x40) << 9 | uVar16 & 0x7fff;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          pcVar15 = sym;
        }
      }
    }
    goto switchD_1060184c_caseD_12;
  case '\x1c':
  case '\x1d':
    in_stack_0000001c = (uint *)0x386;
    iVar8 = il_buffer_reserve(&buf->bytes,3);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(short *)(buf->bytes).pbEnd = (short)in_stack_0000001c;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '\x1e':
    iVar8 = il_buffer_reserve(&buf->bytes,5);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
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
    iVar8 = 2;
LAB_10602252:
    iVar8 = il_buffer_reserve(&buf->bytes,iVar8);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(buf->bytes).pbEnd = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '!':
    iVar8 = il_buffer_reserve(&buf->bytes,6);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    if (bVar18 != 0) {
      if ((uVar29 & 0xffffff80) == 0) {
        *(buf->bytes).pbEnd = (uchar)uVar29;
        puVar23 = (buf->bytes).pbEnd + 1;
      }
      else {
        *(buf->bytes).pbEnd = 0x80;
        puVar20 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar20;
        *puVar20 = uVar29;
        puVar23 = (buf->bytes).pbEnd + 4;
      }
      (buf->bytes).pbEnd = puVar23;
    }
    puVar11 = (uchar *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar8 = il_buffer_reserve(&buf->bytes,2);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = '\0';
        puVar23 = (buf->bytes).pbEnd + 1;
LAB_106022da:
        (buf->bytes).pbEnd = puVar23;
      }
    }
    else {
      uVar29 = 0xffffffff;
      pcVar30 = g_il_pch_name;
      do {
        if (uVar29 == 0) break;
        uVar29 = uVar29 - 1;
        cVar2 = *pcVar30;
        pcVar30 = pcVar30 + 1;
      } while (cVar2 != '\0');
      uVar29 = ~uVar29;
      iVar8 = il_buffer_reserve(&buf->bytes,uVar29 + 1);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        puVar23 = (buf->bytes).pbEnd;
        for (uVar22 = uVar29 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
          *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
          puVar11 = puVar11 + 4;
          puVar23 = puVar23 + 4;
        }
        for (uVar22 = uVar29 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
          *puVar23 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar23 = puVar23 + 1;
        }
        puVar23 = (buf->bytes).pbEnd + uVar29;
        goto LAB_106022da;
      }
    }
    if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
      iVar8 = il_buffer_reserve(&buf->bytes,6);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pcVar15 = record_sym;
      if (bVar18 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
    }
    else {
      uVar29 = 0;
      pfVar31 = (fe_pragma_comment *)0x0;
      pfVar28 = g_pragma_comment_list;
      while (g_pragma_comment_list = pfVar31, pfVar28 != (fe_pragma_comment *)0x0) {
        pfVar4 = pfVar28->next;
        pfVar28->next = g_pragma_comment_list;
        uVar29 = uVar29 + 1;
        pfVar31 = pfVar28;
        pfVar28 = pfVar4;
      }
      iVar8 = il_buffer_reserve(&buf->bytes,6);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      pfVar28 = g_pragma_comment_list;
      if (bVar18 != 0) {
        if ((uVar29 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar29;
          puVar23 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar20 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar20;
          *puVar20 = uVar29;
          puVar23 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar23;
        pfVar28 = g_pragma_comment_list;
      }
      for (; in_stack_0000001c = (uint *)0x0, pcVar15 = record_sym,
          pfVar28 != (fe_pragma_comment *)0x0; pfVar28 = pfVar28->next) {
        puVar11 = (uchar *)pfVar28->text;
        iVar8 = pfVar28->kind;
        pfVar31 = pfVar28;
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar18 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar18;
        if (bVar18 != 0) {
          *(buf->bytes).pbEnd = (uchar)iVar8;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        if (pfVar28->kind == 7) {
          if ((uchar)(*puVar11 + '\x01') != '\0') {
            iVar8 = (int)(char)(*puVar11 + '\x01');
            do {
              uVar7 = *puVar11;
              iVar12 = il_buffer_reserve(&buf->bytes,2);
              bVar18 = buf->open & (byte)iVar12 & 1;
              buf->open = bVar18;
              if (bVar18 != 0) {
                *(buf->bytes).pbEnd = uVar7;
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              puVar11 = puVar11 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        else {
          uVar29 = 0xffffffff;
          puVar27 = puVar11;
          do {
            if (uVar29 == 0) break;
            uVar29 = uVar29 - 1;
            uVar7 = *puVar27;
            puVar27 = puVar27 + 1;
          } while (uVar7 != '\0');
          uVar29 = ~uVar29;
          pfVar28 = pfVar31;
          iVar8 = il_buffer_reserve(&buf->bytes,uVar29 + 1);
          bVar18 = buf->open & (byte)iVar8 & 1;
          buf->open = bVar18;
          if (bVar18 != 0) {
            puVar23 = (buf->bytes).pbEnd;
            for (uVar22 = uVar29 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
              *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
              puVar11 = puVar11 + 4;
              puVar23 = puVar23 + 4;
            }
            for (uVar22 = uVar29 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
              *puVar23 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar23 = puVar23 + 1;
            }
            ppuVar1 = &(buf->bytes).pbEnd;
            *ppuVar1 = *ppuVar1 + uVar29;
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
    uVar29 = sym_keys->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym_keys->entity = uVar29 & 0xffffff ^ sym_keys->entity;
    uVar29 = il_symbol_key_2((int)sym_keys);
    if (g_c9il_mode == '\0') {
      iVar8 = il_buffer_reserve(&buf->bytes,4);
      bVar18 = buf->open & (byte)iVar8 & 1;
      buf->open = bVar18;
      if (bVar18 != 0) {
        bVar18 = (byte)uVar29;
        if (uVar29 < 0x3fff80) {
          if (uVar29 < 0x4000) {
            *(buf->bytes).pbEnd = bVar18 & 0x3f | 0x80;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar18 | 0xc0;
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 6);
            puVar23 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar23;
            *puVar23 = (uchar)(uVar29 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar18 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar29);
    }
    puVar11 = (uchar *)pp_position_file_name(&g_token_position);
    uVar29 = 0xffffffff;
    puVar27 = puVar11;
    do {
      if (uVar29 == 0) break;
      uVar29 = uVar29 - 1;
      uVar7 = *puVar27;
      puVar27 = puVar27 + 1;
    } while (uVar7 != '\0');
    uVar29 = ~uVar29;
    iVar8 = il_buffer_reserve(&buf->bytes,uVar29 + 1);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      puVar23 = (buf->bytes).pbEnd;
      for (uVar22 = uVar29 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
        *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
        puVar11 = puVar11 + 4;
        puVar23 = puVar23 + 4;
      }
      for (uVar22 = uVar29 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
        *puVar23 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar23 = puVar23 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar29;
    }
    goto switchD_1060184c_caseD_12;
  case '#':
    iVar12 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar12 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      iVar12 = il_buffer_put_byte7(buf,(int)(short)iVar8);
      if ((char)iVar12 == '\0') {
        *(buf->bytes).pbEnd = 0x80;
        psVar21 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar21;
        *psVar21 = (short)iVar8;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar15 = sym;
      }
    }
    goto switchD_1060184c_caseD_12;
  case '%':
    uVar29 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar29 = g_next_entity_id;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,5);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar29;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '&':
    uVar29 = 0xffffffff;
    pcVar30 = (char *)g_source_file_ni;
    do {
      if (uVar29 == 0) break;
      uVar29 = uVar29 - 1;
      cVar2 = *pcVar30;
      pcVar30 = pcVar30 + 1;
    } while (cVar2 != '\0');
    uVar29 = ~uVar29;
    iVar8 = il_buffer_reserve(&buf->bytes,uVar29 + 1);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      puVar23 = (buf->bytes).pbEnd;
      for (uVar22 = uVar29 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
        *(undefined4 *)puVar23 = *(undefined4 *)puVar11;
        puVar11 = puVar11 + 4;
        puVar23 = puVar23 + 4;
      }
      for (uVar22 = uVar29 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
        *puVar23 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar23 = puVar23 + 1;
      }
      ppuVar1 = &(buf->bytes).pbEnd;
      *ppuVar1 = *ppuVar1 + uVar29;
    }
    goto switchD_1060184c_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_2
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_record_fragment_3
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  case '*':
    uVar29 = 2;
    if (g_c9il_mode == '\0') {
      uVar29 = 3;
    }
    if (g_dlp != '\0') {
      uVar29 = uVar29 | 8;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,5);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    if (bVar18 != 0) {
      *(uint *)(buf->bytes).pbEnd = uVar29;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    if ((bVar18 != 0) && (iVar8 = il_buffer_put_byte7(buf,0xc), (char)iVar8 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar23 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar23;
      puVar23[0] = '\f';
      puVar23[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    if ((bVar18 != 0) && (iVar8 = il_buffer_put_byte7(buf,0), (char)iVar8 == '\0')) {
      *(buf->bytes).pbEnd = 0x80;
      puVar23 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar23;
      puVar23[0] = '\0';
      puVar23[1] = '\0';
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    }
    iVar8 = il_buffer_reserve(&buf->bytes,4);
    bVar18 = buf->open & (byte)iVar8 & 1;
    buf->open = bVar18;
    pcVar15 = record_sym;
    if (bVar18 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
      pcVar15 = sym;
    }
    goto switchD_1060184c_caseD_12;
  case '.':
    if (g_opt_Ct != '\0') {
      il_emit_symbol_inline_fragment
                (sym,buf,fdef_mode,sym_type,derived_type,in_stack_0000001c,elem_type,base_code,
                 is_array,format,storage_bits,rec_word0,rec_word1,rec_word2,in_stack_00000042,
                 record_class,record_sym);
      return;
    }
    goto switchD_1060184c_caseD_12;
  }
  iVar8 = il_buffer_reserve(&buf->bytes,6);
  bVar18 = buf->open & (byte)iVar8 & 1;
  buf->open = bVar18;
  pcVar15 = record_sym;
  if ((bVar18 != 0) && (iVar8 = il_buffer_put_byte7(buf,(uint)value), (char)iVar8 == '\0')) {
    *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
    puVar23 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar23;
    *(c1_symbol_cell **)puVar23 = value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    pcVar15 = sym;
  }
  goto switchD_1060184c_caseD_12;
switchD_1060184c_caseD_7:
  cVar6 = g_il_block_level;
  if (record_class == 3) {
    cVar6 = (sym->x28).bytes.bit_position;
  }
  goto LAB_10601974;
}

