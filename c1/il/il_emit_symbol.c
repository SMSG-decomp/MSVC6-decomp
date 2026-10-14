void __cdecl il_emit_symbol(int record_class,c1_symbol *sym)

{
  PB *ppuVar1;
  char cVar2;
  char *name;
  c1_type *pcVar3;
  fe_name *name_00;
  fe_pragma_comment *pfVar4;
  fe_file_record *sym_keys;
  c1_u32 cVar5;
  byte bVar6;
  c1_u8 cVar7;
  uchar uVar8;
  ushort uVar9;
  byte *pbVar10;
  void *pvVar11;
  c1_symbol_cell *value;
  uint *src;
  fe_line_map_row *pfVar12;
  uchar *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  c1_symbol *pcVar17;
  PB puVar18;
  byte bVar19;
  c1_type *pcVar20;
  uint *puVar21;
  short *psVar22;
  uint uVar23;
  PB puVar24;
  c1_u16 cVar25;
  uint elem_flag_bits;
  uint unaff_EBP;
  fe_il_buffer *buf;
  uint unaff_ESI;
  c1_type *pcVar26;
  c1_u16 cVar27;
  short sVar28;
  char *pcVar29;
  uchar *puVar30;
  fe_pragma_comment *pfVar31;
  char *pcVar32;
  char in_stack_ffffffb7;
  char fdef_mode;
  c1_type *pcVar33;
  uint *in_stack_ffffffc0;
  fe_pragma_comment *pfVar34;
  int in_stack_ffffffc4;
  c1_type *base_type;
  undefined4 in_stack_ffffffcc;
  uint basic_code;
  uint uVar35;
  char *in_stack_ffffffd4;
  uint in_stack_ffffffdc;
  uint in_stack_ffffffe0;
  ushort uVar36;
  uint in_stack_ffffffe4;
  ushort rec_fflags_high;
  ushort high_word;
  ushort high_word_2;
  
  high_word_2 = (ushort)((uint)in_stack_ffffffcc >> 0x10);
  base_type = (c1_type *)0x0;
  uVar35 = 0;
  if (g_abort_requested != 0) {
    c1_abort_if_running();
  }
  if (sym == (c1_symbol *)0x0) {
    pcVar33 = (c1_type *)0x0;
    basic_code = 0;
    elem_flag_bits = 0;
    pcVar20 = (c1_type *)0x0;
LAB_106013fd:
    if (record_class == 0xb) {
LAB_106014a8:
      if (g_opt_Zi == '\0') {
        return;
      }
    }
  }
  else {
    bVar6 = sym->kind & 0x1f;
    if ((((bVar6 != 0) && (bVar6 < 0xf)) && (bVar6 != 5)) && ((sym->flags2 & 1) != 0)) {
      return;
    }
    pcVar26 = sym->type;
    bVar19 = (byte)pcVar26->code;
    pcVar33 = pcVar26;
    bVar6 = bVar19;
    while ((char)bVar6 < '\0') {
      pcVar33 = pcVar33->base;
      bVar6 = (byte)pcVar33->code;
    }
    basic_code = CONCAT22(high_word_2,pcVar33->code);
    pcVar20 = pcVar26;
    pcVar33 = pcVar26;
    if ((bVar19 & 0x8f) == 0x83) {
      pcVar20 = type_skip_arrays(pcVar26->base);
    }
    bVar6 = (byte)pcVar26->code;
    elem_flag_bits = (byte)pcVar20->flags & 0x1f;
    pcVar20 = (c1_type *)(-(uint)((pcVar26->code & 0x80) != 0) & (uint)pcVar26);
    if ((sym->kind & 0x1f) != 5) {
      if ((sym->storage & 7) != 7) {
        uVar35 = (uint)((bVar6 & 0x8f) == 0x83);
        if ((uVar35 != 0) && (record_class == 1)) {
          record_class = 2;
        }
        if ((bVar6 & 0x83) == 0x81) {
          base_type = pcVar26->base;
        }
        if ((((sym->flags23 & 1) != 0) &&
            (pbVar10 = sym_segment_record(sym), (*pbVar10 & 0x1f) == 0xe)) &&
           (pvVar11 = sym_segment_record(sym), (*(byte *)((int)pvVar11 + 1) & 2) == 0)) {
          il_emit_symbol_fragment_4
                    (sym,0xb,unaff_ESI,unaff_EBP,in_stack_ffffffb7,pcVar33,pcVar20,in_stack_ffffffc0
                     ,in_stack_ffffffc4,base_type,basic_code,uVar35,in_stack_ffffffd4,elem_flag_bits
                     ,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4,record_class,sym);
          return;
        }
        goto LAB_106013fd;
      }
      record_class = 0xb;
      goto LAB_106014a8;
    }
  }
  pcVar32 = g_il_symbol_record_templates[record_class].codes;
  if (record_class != 0x12) {
    if (g_il_block_level != '\0') {
      buf = &g_il_sy;
      goto LAB_10601438;
    }
    if (g_c9il_mode == '\0') {
      switch(record_class) {
      case 1:
      case 2:
        if (((sym->key_ref >> 2 & 1) == 0) && ((sym->flags1 & 1) == 0)) {
          buf = &g_il_gi_buffer;
          goto LAB_10601438;
        }
        break;
      case 4:
      case 0x10:
        buf = &g_il_gi_buffer;
        if ((sym->key_ref >> 2 & 1) == 0) goto LAB_10601438;
      }
    }
  }
  buf = &g_il_gl;
LAB_10601438:
  pcVar29 = pcVar32;
  if ((g_function_body_reused == '\0') || (record_class != 0xe)) {
    fdef_mode = '\0';
    if ((((record_class == 0xe) || ((record_class == 1 || (record_class == 2)))) &&
        (buf == &g_il_gl)) &&
       ((((g_il_emit_mode == '\0' && (sym != (c1_symbol *)0x0)) &&
         (name = sym->name->text, name != (char *)0x0)) &&
        ((g_c9il_mode == '\0' && (iVar16 = (*g_idb->vtbl->idb_add_name)(g_idb,name), iVar16 == 0))))
       )) {
      diag_fatal_simple(0x37);
    }
  }
  else {
    fdef_mode = '\x01';
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar15 = il_symbol_key_assign(sym);
      }
      else {
        uVar15 = sym->key_ref >> 3;
      }
    }
    else {
      uVar15 = sym->entity & 0xffffff;
    }
    ilstore_query_record(uVar15,5,&stack0xffffffc0);
    in_stack_ffffffdc = *in_stack_ffffffc0;
    in_stack_ffffffe0 = in_stack_ffffffc0[1];
    in_stack_ffffffe4 = in_stack_ffffffc0[2];
  }
  cVar2 = *pcVar32;
  uVar15 = g_cv_precomp_signature;
  puVar13 = (uchar *)g_source_file_ni;
  iVar16 = g_function_formal_count;
  do {
    g_cv_precomp_signature = uVar15;
    g_source_file_ni = (int)puVar13;
    g_function_formal_count = iVar16;
    if (cVar2 == '\0') {
      if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
        if (buf == &g_il_gi_buffer) {
          ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
        }
        else if (buf == &g_il_gl) {
          ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
        }
        if ((fdef_mode == '\0') && (record_class == 0xe)) {
          uVar35 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
          puVar24 = g_il_gi_fdef.bytes.pbEnd;
          puVar18 = (PB)(uVar35 & 0xffffff01);
          g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar18;
          if (g_il_gi_fdef.open != 0) {
            *(uint *)g_il_gi_fdef.bytes.pbEnd = in_stack_ffffffdc;
            *(uint *)(puVar24 + 4) = in_stack_ffffffe0;
            *(uint *)(puVar24 + 8) = in_stack_ffffffe4;
            puVar18 = g_il_gi_fdef.bytes.pbEnd + 0xc;
            g_il_gi_fdef.bytes.pbEnd = puVar18;
          }
          ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                             CONCAT31((int3)((uint)puVar18 >> 8),(sym->flags21 & 1) != 0) + 1);
        }
      }
      return;
    }
    pcVar29 = pcVar29 + 1;
    uVar9 = (ushort)basic_code;
    uVar36 = (ushort)in_stack_ffffffe4;
    rec_fflags_high = (ushort)(in_stack_ffffffe4 >> 0x10);
    switch(cVar2) {
    case '\x01':
      bVar6 = sym->kind & 0x1f;
      if (((bVar6 == 7) || (bVar6 == 8)) || (bVar6 == 6)) {
        value = (c1_symbol_cell *)type_size(base_type);
        pcVar26 = pcVar33;
      }
      else {
        pcVar26 = pcVar33;
        value = (c1_symbol_cell *)type_size(pcVar33);
        if (value == (c1_symbol_cell *)0x0) {
          bVar6 = sym->kind & 0x1f;
          if (bVar6 == 0xb) {
            type_check_size_known(pcVar33);
          }
          else if (bVar6 == 0xc) {
            il_emit_symbol_part(pcVar33,0,sym,buf,fdef_mode,pcVar26,pcVar20,in_stack_ffffffc0,
                                base_type,(ushort)basic_code,uVar35,pcVar29,elem_flag_bits,
                                in_stack_ffffffdc,in_stack_ffffffe0,(ushort)in_stack_ffffffe4,
                                (ushort)(in_stack_ffffffe4 >> 0x10),record_class,sym);
            return;
          }
        }
      }
      if ((((sym->flags3 & 4) != 0) && ((pcVar33->code & 0x200) != 0)) &&
         ((((pcVar33->extra).sym)->flags4 & 1) != 0)) {
        il_emit_symbol_fragment
                  ((uint)value,sym,buf,fdef_mode,pcVar26,pcVar20,in_stack_ffffffc0,base_type,
                   (ushort)basic_code,uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,
                   in_stack_ffffffe0,(ushort)in_stack_ffffffe4,(ushort)(in_stack_ffffffe4 >> 0x10),
                   record_class,sym);
        return;
      }
LAB_10601594:
      pcVar33 = pcVar26;
      iVar16 = il_buffer_reserve(&buf->bytes,6);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar16 = il_buffer_put_byte7(buf,(uint)value), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
        puVar21 = (uint *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)puVar21;
        *puVar21 = (uint)value;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      break;
    case '\x02':
      if (fdef_mode == '\0') {
        bVar6 = sym->flags4;
        if (((((bVar6 & 0x80) == 0) || (bVar19 = sym->kind & 0x1f, bVar19 == 7)) || (bVar19 == 8))
           || (bVar19 == 6)) {
          in_stack_ffffffdc = 0;
        }
        else {
          in_stack_ffffffdc = 0x80;
        }
        bVar19 = sym->kind & 0x1f;
        if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
          if ((bVar6 & 2) != 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x100;
          }
          if ((sym->flags22 & 1) != 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x400;
          }
          if (((sym->x2c).function_flags & 1) != 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x80;
          }
        }
        if ((sym->key_ref & 3) != 0) {
          if (((bVar19 == 10) || (bVar19 == 0xb)) && ((bVar6 & 8) != 0)) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x2000;
          }
          if (((bVar19 != 7) && (bVar19 != 8)) && (bVar19 != 6)) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x100;
          }
        }
        if ((sym->flags3 & 8) != 0) {
          in_stack_ffffffdc = in_stack_ffffffdc | 0x400;
        }
        switch(elem_flag_bits & 7) {
        case 3:
          in_stack_ffffffdc = in_stack_ffffffdc | 4;
          break;
        case 4:
          in_stack_ffffffdc = in_stack_ffffffdc | 0x18;
          break;
        case 5:
          if (((pcVar20 == (c1_type *)0x0) || ((pcVar20->code & 0x83) != 0x81)) ||
             ((pcVar20->flags & 0x8000) == 0)) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x10;
          }
          break;
        case 6:
          in_stack_ffffffdc = in_stack_ffffffdc | 0x14;
        }
        if (((bVar19 == 7) || (bVar19 == 8)) || (bVar19 == 6)) {
          if ((sym->flags4 & 0x10) != 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x8000;
          }
          if ((sym->flags4 & 1) != 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x1000;
          }
        }
        if ((((sym->flags22 & 2) != 0) && (bVar19 != 7)) && (bVar19 != 8)) {
          in_stack_ffffffdc = in_stack_ffffffdc | 0x1000;
        }
        if ((bVar19 == 10) && ((sym->flags21 & 0x80) != 0)) {
          in_stack_ffffffdc = in_stack_ffffffdc | 0x40;
        }
        if ((sym->storage & 0x40) != 0) {
          if ((record_class != 0xe) && ((sym->flags3 & 4) == 0)) {
            pcVar26 = sym->type;
            cVar2 = (char)pcVar26->code;
            while (cVar2 < '\0') {
              pcVar26 = pcVar26->base;
              cVar2 = (char)pcVar26->code;
            }
            if ((pcVar26->flags & 0x18) != 0) goto LAB_106016e1;
          }
          if ((sym->flags22 & 8) == 0) {
            in_stack_ffffffdc = in_stack_ffffffdc | 0x20;
          }
        }
LAB_106016e1:
        il_emit_symbol_reference(buf,sym,in_stack_ffffffdc);
      }
      else {
        il_emit_symbol_reference(buf,sym,in_stack_ffffffdc);
      }
      break;
    case '\x03':
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = (uchar)record_class;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x04':
      if (uVar35 == 0) {
        value = (c1_symbol_cell *)0x0;
      }
      else {
        value = (c1_symbol_cell *)sym_element_size(sym);
      }
      iVar16 = il_buffer_reserve(&buf->bytes,6);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar16 = il_buffer_put_byte7(buf,(uint)value), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        goto LAB_10601602;
      }
      break;
    case '\x05':
      if (g_c9il_mode == '\0') {
        if ((sym->key_ref & 0xfffffff8) == 0) {
          uVar15 = il_symbol_key_assign(sym);
          goto LAB_106018ae;
        }
        uVar15 = sym->key_ref >> 3;
      }
      else {
        uVar15 = sym->entity & 0xffffff;
LAB_106018ae:
        if (g_c9il_mode != '\0') {
          il_buffer_put_id(buf,uVar15);
          break;
        }
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        bVar6 = (byte)uVar15;
        if (uVar15 < 0x3fff80) {
          if (uVar15 < 0x4000) {
            *(buf->bytes).pbEnd = bVar6 & 0x3f | 0x80;
            puVar24 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar24;
            *puVar24 = (uchar)(uVar15 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = bVar6 | 0xc0;
            puVar24 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar24;
            *puVar24 = (uchar)(uVar15 >> 6);
            puVar24 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar24;
            *puVar24 = (uchar)(uVar15 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar6 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      break;
    case '\x06':
      if (g_opt_Zi != '\0') {
        bVar6 = sym->kind & 0x1f;
        if ((((bVar6 != 0) && (bVar6 < 0xf)) && (bVar6 != 5)) &&
           (((sym->flags23 & 1) != 0 &&
            (pvVar11 = sym_segment_record(sym), *(void **)((int)pvVar11 + 8) == g_name_drectve)))) {
          il_emit_symbol_fragment_2
                    (sym,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,
                     (ushort)basic_code,uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,
                     in_stack_ffffffe0,(ushort)in_stack_ffffffe4,(ushort)(in_stack_ffffffe4 >> 0x10)
                     ,record_class,sym);
          return;
        }
        pcVar26 = pcVar33;
        if ((sym->kind & 0x1f) == 4) {
          value = (sym->x2c).references;
LAB_10601955:
          if (value != (c1_symbol_cell *)0x0) goto LAB_10601594;
        }
        else if ((sym->type->code & 0x300) != 0) {
          value = (c1_symbol_cell *)((sym->type->extra).tag)->debug_index;
          goto LAB_10601955;
        }
        value = (c1_symbol_cell *)pcVar33->debug_index;
        goto LAB_10601594;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,6);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar16 = il_buffer_put_byte7(buf,0), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar24 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar24;
        puVar24[0] = '\0';
        puVar24[1] = '\0';
        puVar24[2] = '\0';
        puVar24[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      break;
    case '\a':
      cVar7 = g_il_block_level;
      if (record_class == 3) {
        cVar7 = (sym->x28).bytes.bit_position;
      }
      goto LAB_10601974;
    case '\b':
      bVar6 = sym->kind & 0x1f;
      if (bVar6 == 9) {
        bVar6 = *(byte *)&sym->detail;
      }
      else if ((sym->flags3 & 8) == 0) {
        if ((bVar6 == 10) && ((sym->storage & 7) == 3)) {
          bVar6 = 0x24;
        }
        else {
          bVar6 = 0;
        }
      }
      else {
        bVar6 = -((sym->storage & 7) != 2) & 0x25;
      }
      goto LAB_106019ae;
    case '\t':
      if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) goto LAB_10601a0e;
      src = (uint *)decorate_check_name_length(sym);
      uVar15 = 0xffffffff;
      puVar21 = src;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        uVar23 = *puVar21;
        puVar21 = (uint *)((int)puVar21 + 1);
      } while ((char)uVar23 != '\0');
      cVar7 = il_buffer_reserve_ok(buf,~uVar15);
      if (cVar7 != '\0') {
        il_buffer_put_bytes(buf,src,~uVar15);
      }
      break;
    case '\n':
      bVar6 = sym->flags4;
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = ((bVar6 & 4) != 0) + '\x01';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\v':
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\f':
      bVar6 = sym->kind & 0x1f;
      if ((bVar6 == 0xb) || (bVar6 == 0xc)) {
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = '\x03';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      else {
        bVar6 = sym->storage & 7;
        if ((bVar6 == 0) || (3 < bVar6)) {
          iVar16 = il_buffer_reserve(&buf->bytes,2);
          bVar6 = buf->open & (byte)iVar16 & 1;
          buf->open = bVar6;
          if (bVar6 != 0) {
            *(buf->bytes).pbEnd = '\x01';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
        else {
          pcVar26 = pcVar33;
          if ((pcVar33->code & 0x8f) == 0x83) {
            pcVar33 = type_skip_arrays(pcVar33->base);
          }
          if (((byte)pcVar33->flags >> 5 & 1) == 0) {
            if (((((sym->flags3 & 8) == 0) || ((sym->storage & 0x40) == 0)) ||
                (g_string_pooling_readonly == '\0')) ||
               ((((sym->flags23 & 1) != 0 &&
                 (pbVar10 = sym_segment_record(sym), (*pbVar10 & 0x1f) == 0xe)) &&
                (pvVar11 = sym_segment_record(sym), (*(uint *)((int)pvVar11 + 0x1c) & 0xffffff) != 3
                )))) {
              iVar16 = il_buffer_reserve(&buf->bytes,2);
              bVar6 = buf->open & (byte)iVar16 & 1;
              buf->open = bVar6;
              pcVar33 = pcVar26;
              if (bVar6 != 0) {
                *(buf->bytes).pbEnd = '\x02';
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
              }
              break;
            }
          }
          else if ((sym->flags23 & 1) != 0) {
            il_emit_symbol_fragment_3
                      (sym,buf,fdef_mode,pcVar26,pcVar20,in_stack_ffffffc0,base_type,
                       (ushort)basic_code,uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,
                       in_stack_ffffffe0,(ushort)in_stack_ffffffe4,
                       (ushort)(in_stack_ffffffe4 >> 0x10),record_class,sym);
            return;
          }
          iVar16 = il_buffer_reserve(&buf->bytes,2);
          bVar6 = buf->open & (byte)iVar16 & 1;
          buf->open = bVar6;
          pcVar33 = pcVar26;
          if (bVar6 != 0) {
            *(buf->bytes).pbEnd = '\x04';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
      }
      break;
    case '\r':
      if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
        cVar27 = base_type->code;
        cVar2 = (char)cVar27;
        if ((cVar2 < '\0') && (base_type != (c1_type *)0x0)) {
          cVar25 = base_type->flags;
        }
        else {
          cVar27 = 0;
          cVar25 = 0;
        }
        uVar15 = 0;
        pcVar26 = base_type;
        while (cVar2 < '\0') {
          pcVar26 = pcVar26->base;
          cVar2 = (char)pcVar26->code;
        }
        basic_code = (uint)pcVar26->code;
        pcVar26 = base_type;
      }
      else {
        if (pcVar20 == (c1_type *)0x0) {
          cVar27 = 0;
          cVar25 = 0;
        }
        else {
          cVar27 = pcVar20->code;
          cVar25 = pcVar20->flags;
        }
        pcVar26 = pcVar33;
        if ((basic_code & 0x200) == 0) {
LAB_10601c71:
          uVar15 = 0;
        }
        else {
          if (uVar9 != 0x203) {
            pcVar3 = sym->type;
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
          uVar15 = 0x10;
        }
      }
      if ((cVar25 & 0x100) != 0) {
        uVar15 = uVar15 | 0x4000;
      }
      if ((cVar25 & 0x40) != 0) {
        uVar15 = uVar15 | 0x1000;
      }
      uVar9 = cVar27 & 0x8f;
      if (uVar9 == 0x83) {
        uVar15 = uVar15 | 6;
      }
      else if (((uVar9 == 0x82) || (uVar9 == 0x86)) || (uVar9 == 0x80)) {
        uVar15 = uVar15 | 3;
      }
      else {
        uVar9 = pcVar26->code;
        if ((uVar9 & 0x2000) == 0) {
          if ((((g_ms_extensions == '\0') && ((uVar9 & 0xfff) == 0x11)) && ((uVar9 & 0x1000) == 0))
             && (g_opt_J_unsigned_char != '\0')) {
            il_emit_symbol_fragment_5
                      (uVar15,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,
                       (ushort)basic_code,uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,
                       in_stack_ffffffe0,uVar36,rec_fflags_high,record_class,sym);
            return;
          }
          uVar23 = basic_code & 0xffff;
          if (uVar23 < 0x104) {
            if (uVar23 != 0x103) {
              switch(uVar23) {
              case 0x11:
              case 0x12:
              case 0x13:
              case 0x14:
                goto switchD_10601d6d_caseD_11;
              default:
code_r0x10601daf:
                if ((0x18 < uVar23) && (uVar23 < 0x1e)) goto switchD_10601d6d_caseD_11;
                break;
              case 0x26:
              case 0x27:
              case 0x28:
                uVar15 = uVar15 | 5;
                break;
              case 0x40:
                uVar15 = uVar15 | 7;
              }
              goto LAB_10601ca3;
            }
          }
          else {
            if (uVar23 < 0x403) {
              if (uVar23 != 0x402) {
                if ((uVar23 < 0x201) || (0x203 < uVar23)) goto code_r0x10601daf;
                uVar15 = uVar15 | 6;
                goto LAB_10601ca3;
              }
              goto code_r0x10601d74;
            }
            if (uVar23 != 0x1011) {
              il_emit_symbol_record_fragment
                        (uVar23,uVar15,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,
                         (ushort)basic_code,uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,
                         in_stack_ffffffe0,uVar36,rec_fflags_high,record_class,sym);
              return;
            }
          }
switchD_10601d6d_caseD_11:
          uVar15 = uVar15 | 1;
        }
        else {
code_r0x10601d74:
          uVar15 = uVar15 | 2;
        }
      }
LAB_10601ca3:
      if (0x7f < (ushort)uVar15) {
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = (byte)(uVar15 >> 8) | 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = (uchar)uVar15;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x0e':
      cVar5 = sym->key_ref;
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(byte)cVar5 & 3);
      }
      break;
    case '\x0f':
      name_00 = sym->detail;
      if ((name_00 != (fe_name *)0x0) && (name_00 != g_name_unnamed)) {
        func_report_static_not_defined
                  (name_00,buf,fdef_mode,pcVar33,pcVar20,(int)in_stack_ffffffc0,base_type,uVar9,
                   uVar35,pcVar29,elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,uVar36,
                   record_class,sym);
        return;
      }
LAB_10601a0e:
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x10':
      if (((sym->flags22 & 4) == 0) || (record_class == 7)) {
        if (((sym->flags22 & 8) == 0) || (record_class == 7)) {
          if ((sym->storage & 0x40) == 0) {
            bVar6 = sym->storage & 7;
            if (((bVar6 < 4) || (6 < bVar6)) && (bVar6 != 3)) {
              if ((sym->flags3 & 4) == 0) {
                if (bVar6 == 1) goto LAB_10601e86;
                if ((uVar35 == 0) || (bVar6 = 2, (pcVar20->extra).sym != (c1_symbol *)0x0)) {
                  bVar6 = 3;
                }
              }
              else {
                bVar6 = 1;
              }
            }
            else {
              bVar6 = 4;
            }
          }
          else {
            bVar6 = (~sym->flags3 & 4 | 2) >> 1;
          }
        }
        else {
          bVar6 = 8;
        }
      }
      else if ((sym->flags1 & 1) == 0) {
LAB_10601e86:
        bVar6 = 2;
      }
      else {
        bVar6 = (-((sym->flags3 & 4) != 0) & 0xfeU) + 9;
      }
LAB_106019ae:
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar19 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar19;
      if (bVar19 != 0) {
        *(buf->bytes).pbEnd = bVar6;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x11':
      bVar6 = sym->kind & 0x1f;
      if ((((bVar6 == 7) || (bVar6 == 8)) || (bVar6 == 6)) && ((sym->flags1 & 1) != 0)) {
        if ((sym->flags22 & 4) == 0) {
          if ((sym->flags22 & 8) == 0) {
            if ((sym->storage & 0x40) == 0) {
              cVar7 = (-((sym->storage & 7) != 3) & 2U) + 3;
            }
            else {
              cVar7 = '\x05';
            }
          }
          else {
            cVar7 = '\n';
          }
        }
        else {
          cVar7 = '\t';
        }
      }
      else {
        bVar6 = sym->storage & 7;
        if ((bVar6 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
          diag_error(0x81,sym);
          cVar7 = '\x02';
        }
        else {
          if (((sym->flags21 & 1) != 0) && (bVar6 != 1)) {
            func_check_inline_definitions
                      (sym,buf,fdef_mode,pcVar33,pcVar20,base_type,uVar9,uVar35,pcVar29,
                       elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,uVar36,record_class,sym);
            return;
          }
          cVar7 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
        }
      }
LAB_10601974:
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = cVar7;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x13':
      iVar16 = 6;
      goto LAB_10602252;
    case '\x14':
      iVar16 = (sym->x28).value;
      if ((iVar16 < 0x8000) && (-0x8001 < iVar16)) {
        bVar6 = 1;
      }
      else {
        bVar6 = 0;
      }
      sVar28 = (-(ushort)bVar6 & 0xfffe) + 4;
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar14 = il_buffer_put_byte7(buf,(int)sVar28), (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        psVar22 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar22;
        *psVar22 = sVar28;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = (uchar)iVar16;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar16 >> 8);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      if ((0x7fff < iVar16) || (iVar16 < -0x8000)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar6 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = (uchar)((uint)iVar16 >> 0x10);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar6 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = (uchar)((uint)iVar16 >> 0x18);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      break;
    case '\x15':
      pcVar17 = decl_lookup_file_scope_twin(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar17->key_ref & 0xfffffff8) == 0) {
          uVar15 = il_symbol_key_assign(pcVar17);
          goto LAB_10638f6a;
        }
        uVar15 = pcVar17->key_ref >> 3;
      }
      else {
        uVar15 = pcVar17->entity & 0xffffff;
LAB_10638f6a:
        if (g_c9il_mode != '\0') goto LAB_10638f73;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        bVar6 = (byte)uVar15;
        if (uVar15 < 0x3fff80) {
          if (uVar15 < 0x4000) {
            *(buf->bytes).pbEnd = bVar6 & 0x3f | 0x80;
            goto LAB_10638fd8;
          }
          *(buf->bytes).pbEnd = bVar6 | 0xc0;
          puVar24 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar24;
          *puVar24 = (uchar)(uVar15 >> 6);
          puVar24 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar24;
          *puVar24 = (uchar)(uVar15 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar6 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      break;
    case '\x16':
      pcVar17 = sym_segment_record(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar17->key_ref & 0xfffffff8) == 0) {
          uVar15 = il_symbol_key_assign(pcVar17);
          goto LAB_1063904f;
        }
        uVar15 = pcVar17->key_ref >> 3;
LAB_10639060:
        iVar16 = il_buffer_reserve(&buf->bytes,4);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 == 0) break;
        bVar6 = (byte)uVar15;
        if (0x3fff7f < uVar15) {
          *(buf->bytes).pbEnd = bVar6 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          break;
        }
        if (0x3fff < uVar15) {
          *(buf->bytes).pbEnd = bVar6 | 0xc0;
          puVar24 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar24;
          *puVar24 = (uchar)(uVar15 >> 6);
          puVar24 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar24;
          *puVar24 = (uchar)(uVar15 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          break;
        }
        *(buf->bytes).pbEnd = bVar6 & 0x3f | 0x80;
LAB_10638fd8:
        puVar24 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar24;
        *puVar24 = (uchar)(uVar15 >> 6);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      else {
        uVar15 = pcVar17->entity & 0xffffff;
LAB_1063904f:
        if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
        il_buffer_put_id(buf,uVar15);
      }
      break;
    case '\x17':
      uVar8 = (sym->x28).bytes.bit_position;
      if ((uVar8 != '\0') && (uVar8 != '\x02')) {
        uVar8 = (-(uVar8 != '\x03') & 0xfeU) + 3;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = uVar8;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x18':
      uVar15 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
      in_stack_ffffffc0 = (uint *)g_function_ex_offset;
      if (g_c9il_mode != '\0') {
        iVar16 = il_buffer_reserve(&buf->bytes,6);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          if (((uint)in_stack_ffffffc0 & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)in_stack_ffffffc0;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar24 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar24;
            *(uint **)puVar24 = in_stack_ffffffc0;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
        iVar16 = il_buffer_reserve(&buf->bytes,6);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          if ((uVar15 & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)uVar15;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar21 = (uint *)((buf->bytes).pbEnd + 1);
            (buf->bytes).pbEnd = (PB)puVar21;
            *puVar21 = uVar15;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
      }
      break;
    case '\x19':
      if (fdef_mode == '\0') {
        high_word = (ushort)(in_stack_ffffffe0 >> 0x10);
        in_stack_ffffffe0 = CONCAT22(high_word,0xffff);
        if (g_function_tuple_count < 0x10000) {
          in_stack_ffffffe0 = CONCAT22(high_word,(short)g_function_tuple_count);
        }
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(ushort)in_stack_ffffffe0);
      }
      break;
    case '\x1a':
      if (fdef_mode == '\0') {
        if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
          sVar28 = 0;
        }
        else {
          sVar28 = 0x1000;
        }
        in_stack_ffffffe4 =
             (int)(short)(((ushort)(sym->flags21 & 8) << 3 | (ushort)(sym->flags21 & 1)) << 7) |
             (sym->flags4 & 0x80) >> 5 |
             (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
             (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
             (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar28;
        uVar36 = *(ushort *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 2);
        if (((uVar36 & 0x2000) != 0) && ((uVar36 & 0x4000) == 0)) {
          g_function_not_inlinable = 1;
        }
        if (g_inline_level == 1) {
LAB_10602124:
          if (g_function_not_inlinable == 0) {
LAB_10602128:
            if ((sym->type->flags & 0x8000) == 0) {
              if ((sym->flags21 & 1) != 0) {
                in_stack_ffffffe4 = in_stack_ffffffe4 | 0x40;
              }
              goto LAB_1060213d;
            }
          }
LAB_10602193:
          in_stack_ffffffe4 = (int)(short)in_stack_ffffffe4 & 0xffffffbf;
          if ((sym->flags21 & 1) != 0) {
            func_emit_inline_candidate
                      (in_stack_ffffffe4,sym,buf,'\0',pcVar33,pcVar20,base_type,uVar9,uVar35,pcVar29
                       ,elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,record_class,sym);
            return;
          }
        }
        else if (g_inline_level == 2) {
          if (g_function_auto_inline == 0) goto LAB_10602124;
          if (g_function_not_inlinable == 0) {
            if ((((sym->storage & 7) == 3) && (((byte)sym->key_ref & 3) == 1)) ||
               (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
              in_stack_ffffffe4 = in_stack_ffffffe4 | 0x40;
            }
            goto LAB_10602128;
          }
          goto LAB_10602193;
        }
LAB_1060213d:
        iVar16 = il_buffer_reserve(&buf->bytes,5);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          if (in_stack_ffffffe4 < 0x8000) {
            *(short *)(buf->bytes).pbEnd = (short)in_stack_ffffffe4;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          }
          else {
            *(uint *)(buf->bytes).pbEnd = in_stack_ffffffe4 | 0x8000;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
      }
      else {
        iVar16 = il_buffer_reserve(&buf->bytes,5);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          if ((int)in_stack_ffffffe4 < 0x8000) {
            *(short *)(buf->bytes).pbEnd = (short)in_stack_ffffffe4;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          }
          else {
            *(uint *)(buf->bytes).pbEnd =
                 (uint)((uint3)(in_stack_ffffffe4 >> 8) & 0xffffc0 | 0x40) << 9 |
                 in_stack_ffffffe4 & 0x7fff;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
      }
      break;
    case '\x1c':
    case '\x1d':
      in_stack_ffffffc0 = (uint *)0x386;
      iVar16 = il_buffer_reserve(&buf->bytes,3);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(short *)(buf->bytes).pbEnd = (short)in_stack_ffffffc0;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      break;
    case '\x1e':
      iVar16 = il_buffer_reserve(&buf->bytes,5);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        puVar24 = (buf->bytes).pbEnd;
        puVar24[0] = 0x96;
        puVar24[1] = 0xba;
        puVar24[2] = '0';
        puVar24[3] = '\x01';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      break;
    case ' ':
      iVar16 = 2;
LAB_10602252:
      iVar16 = il_buffer_reserve(&buf->bytes,iVar16);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '!':
      iVar16 = il_buffer_reserve(&buf->bytes,6);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        if ((uVar15 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar15;
          puVar24 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar21 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar21;
          *puVar21 = uVar15;
          puVar24 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar24;
      }
      puVar13 = (uchar *)g_il_pch_name;
      if (g_il_pch_name == (char *)0x0) {
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = '\0';
          puVar24 = (buf->bytes).pbEnd + 1;
LAB_106022da:
          (buf->bytes).pbEnd = puVar24;
        }
      }
      else {
        uVar15 = 0xffffffff;
        pcVar32 = g_il_pch_name;
        do {
          if (uVar15 == 0) break;
          uVar15 = uVar15 - 1;
          cVar2 = *pcVar32;
          pcVar32 = pcVar32 + 1;
        } while (cVar2 != '\0');
        uVar15 = ~uVar15;
        iVar16 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          puVar24 = (buf->bytes).pbEnd;
          for (uVar23 = uVar15 >> 2; uVar23 != 0; uVar23 = uVar23 - 1) {
            *(undefined4 *)puVar24 = *(undefined4 *)puVar13;
            puVar13 = puVar13 + 4;
            puVar24 = puVar24 + 4;
          }
          for (uVar23 = uVar15 & 3; uVar23 != 0; uVar23 = uVar23 - 1) {
            *puVar24 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar24 = puVar24 + 1;
          }
          puVar24 = (buf->bytes).pbEnd + uVar15;
          goto LAB_106022da;
        }
      }
      if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
        iVar16 = il_buffer_reserve(&buf->bytes,6);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          *(buf->bytes).pbEnd = '\0';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      else {
        uVar15 = 0;
        pfVar34 = (fe_pragma_comment *)0x0;
        pfVar31 = g_pragma_comment_list;
        while (g_pragma_comment_list = pfVar34, pfVar31 != (fe_pragma_comment *)0x0) {
          pfVar4 = pfVar31->next;
          pfVar31->next = g_pragma_comment_list;
          uVar15 = uVar15 + 1;
          pfVar34 = pfVar31;
          pfVar31 = pfVar4;
        }
        iVar16 = il_buffer_reserve(&buf->bytes,6);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        pfVar31 = g_pragma_comment_list;
        if (bVar6 != 0) {
          if ((uVar15 & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)uVar15;
            puVar24 = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar21 = (uint *)((buf->bytes).pbEnd + 1);
            (buf->bytes).pbEnd = (PB)puVar21;
            *puVar21 = uVar15;
            puVar24 = (buf->bytes).pbEnd + 4;
          }
          (buf->bytes).pbEnd = puVar24;
          pfVar31 = g_pragma_comment_list;
        }
        for (; in_stack_ffffffc0 = (uint *)0x0, pfVar31 != (fe_pragma_comment *)0x0;
            pfVar31 = pfVar31->next) {
          puVar13 = (uchar *)pfVar31->text;
          iVar16 = pfVar31->kind;
          pfVar34 = pfVar31;
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar6 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar6;
          if (bVar6 != 0) {
            *(buf->bytes).pbEnd = (uchar)iVar16;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          if (pfVar31->kind == 7) {
            if ((uchar)(*puVar13 + '\x01') != '\0') {
              iVar16 = (int)(char)(*puVar13 + '\x01');
              do {
                uVar8 = *puVar13;
                iVar14 = il_buffer_reserve(&buf->bytes,2);
                bVar6 = buf->open & (byte)iVar14 & 1;
                buf->open = bVar6;
                if (bVar6 != 0) {
                  *(buf->bytes).pbEnd = uVar8;
                  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                }
                puVar13 = puVar13 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
          }
          else {
            uVar15 = 0xffffffff;
            puVar30 = puVar13;
            do {
              if (uVar15 == 0) break;
              uVar15 = uVar15 - 1;
              uVar8 = *puVar30;
              puVar30 = puVar30 + 1;
            } while (uVar8 != '\0');
            uVar15 = ~uVar15;
            pfVar31 = pfVar34;
            iVar16 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
            bVar6 = buf->open & (byte)iVar16 & 1;
            buf->open = bVar6;
            if (bVar6 != 0) {
              puVar24 = (buf->bytes).pbEnd;
              for (uVar23 = uVar15 >> 2; uVar23 != 0; uVar23 = uVar23 - 1) {
                *(undefined4 *)puVar24 = *(undefined4 *)puVar13;
                puVar13 = puVar13 + 4;
                puVar24 = puVar24 + 4;
              }
              for (uVar23 = uVar15 & 3; uVar23 != 0; uVar23 = uVar23 - 1) {
                *puVar24 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar24 = puVar24 + 1;
              }
              ppuVar1 = &(buf->bytes).pbEnd;
              *ppuVar1 = *ppuVar1 + uVar15;
            }
          }
        }
      }
      break;
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
      uVar15 = sym_keys->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      sym_keys->entity = uVar15 & 0xffffff ^ sym_keys->entity;
      uVar15 = il_symbol_key_2((int)sym_keys);
      if (g_c9il_mode == '\0') {
        iVar16 = il_buffer_reserve(&buf->bytes,4);
        bVar6 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar6;
        if (bVar6 != 0) {
          bVar6 = (byte)uVar15;
          if (uVar15 < 0x3fff80) {
            if (uVar15 < 0x4000) {
              *(buf->bytes).pbEnd = bVar6 & 0x3f | 0x80;
              puVar24 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar24;
              *puVar24 = (uchar)(uVar15 >> 6);
              (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            }
            else {
              *(buf->bytes).pbEnd = bVar6 | 0xc0;
              puVar24 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar24;
              *puVar24 = (uchar)(uVar15 >> 6);
              puVar24 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar24;
              *puVar24 = (uchar)(uVar15 >> 0xe);
              (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            }
          }
          else {
            *(buf->bytes).pbEnd = bVar6 + 0x80;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
      }
      else {
        il_buffer_put_id(buf,uVar15);
      }
      puVar13 = (uchar *)pp_position_file_name(&g_token_position);
      uVar15 = 0xffffffff;
      puVar30 = puVar13;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        uVar8 = *puVar30;
        puVar30 = puVar30 + 1;
      } while (uVar8 != '\0');
      uVar15 = ~uVar15;
      iVar16 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        puVar24 = (buf->bytes).pbEnd;
        for (uVar23 = uVar15 >> 2; uVar23 != 0; uVar23 = uVar23 - 1) {
          *(undefined4 *)puVar24 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar24 = puVar24 + 4;
        }
        for (uVar23 = uVar15 & 3; uVar23 != 0; uVar23 = uVar23 - 1) {
          *puVar24 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar24 = puVar24 + 1;
        }
        ppuVar1 = &(buf->bytes).pbEnd;
        *ppuVar1 = *ppuVar1 + uVar15;
      }
      break;
    case '#':
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        iVar14 = il_buffer_put_byte7(buf,(int)(short)iVar16);
        if ((char)iVar14 == '\0') {
          *(buf->bytes).pbEnd = 0x80;
          psVar22 = (short *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)psVar22;
          *psVar22 = (short)iVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        }
      }
      break;
    case '%':
      uVar15 = 0x400000;
      if (g_c9il_mode != '\0') {
        uVar15 = g_next_entity_id;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,5);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(uint *)(buf->bytes).pbEnd = uVar15;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      break;
    case '&':
      uVar15 = 0xffffffff;
      puVar30 = puVar13;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        uVar8 = *puVar30;
        puVar30 = puVar30 + 1;
      } while (uVar8 != '\0');
      uVar15 = ~uVar15;
      iVar16 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        puVar24 = (buf->bytes).pbEnd;
        for (uVar23 = uVar15 >> 2; uVar23 != 0; uVar23 = uVar23 - 1) {
          *(undefined4 *)puVar24 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar24 = puVar24 + 4;
        }
        for (uVar23 = uVar15 & 3; uVar23 != 0; uVar23 = uVar23 - 1) {
          *puVar24 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar24 = puVar24 + 1;
        }
        ppuVar1 = &(buf->bytes).pbEnd;
        *ppuVar1 = *ppuVar1 + uVar15;
      }
      break;
    case '(':
      if (g_c9il_mode == '\0') {
        il_emit_symbol_record_fragment_2
                  (sym,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,uVar9,uVar35,
                   pcVar29,elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,uVar36,rec_fflags_high
                   ,record_class,sym);
        return;
      }
      break;
    case ')':
      if (g_c9il_mode == '\0') {
        il_emit_symbol_record_fragment_3
                  (sym,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,uVar9,uVar35,
                   pcVar29,elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,uVar36,rec_fflags_high
                   ,record_class,sym);
        return;
      }
      break;
    case '*':
      uVar15 = 2;
      if (g_c9il_mode == '\0') {
        uVar15 = 3;
      }
      if (g_dlp != '\0') {
        uVar15 = uVar15 | 8;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,5);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        *(uint *)(buf->bytes).pbEnd = uVar15;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar16 = il_buffer_put_byte7(buf,0xc), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar24 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar24;
        puVar24[0] = '\f';
        puVar24[1] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if ((bVar6 != 0) && (iVar16 = il_buffer_put_byte7(buf,0), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar24 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar24;
        puVar24[0] = '\0';
        puVar24[1] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar6 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar6;
      if (bVar6 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
      }
      break;
    case '.':
      if (g_opt_Ct != '\0') {
        il_emit_symbol_inline_fragment
                  (sym,buf,fdef_mode,pcVar33,pcVar20,in_stack_ffffffc0,base_type,uVar9,uVar35,
                   pcVar29,elem_flag_bits,in_stack_ffffffdc,in_stack_ffffffe0,uVar36,rec_fflags_high
                   ,record_class,sym);
        return;
      }
    }
    cVar2 = *pcVar29;
    uVar15 = g_cv_precomp_signature;
    puVar13 = (uchar *)g_source_file_ni;
    iVar16 = g_function_formal_count;
  } while( true );
}

