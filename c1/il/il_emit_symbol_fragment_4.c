void __cdecl
il_emit_symbol_fragment_4
          (c1_symbol *sym,int typedef_class,uint saved_esi,uint saved_ebp,char fdef_mode,
          c1_type *type,c1_type *derived_type,uint *stored_record,int frame_20,c1_type *base_type,
          uint basic_code,int is_array,char *codes,uint elem_flag_bits,uint rec_word0,uint rec_word1
          ,uint rec_word2,int record_class,c1_symbol *sym_arg)

{
  PB *ppuVar1;
  uchar uVar2;
  char cVar3;
  ushort uVar4;
  char *name;
  c1_type *pcVar5;
  fe_name *name_00;
  fe_pragma_comment *pfVar6;
  fe_file_record *sym_keys;
  fe_pragma_comment *pfVar7;
  c1_u32 cVar8;
  fe_pragma_comment *pfVar9;
  c1_u8 cVar10;
  c1_symbol_cell *value;
  uint *src;
  c1_type *pcVar11;
  fe_line_map_row *pfVar12;
  uchar *puVar13;
  int iVar14;
  void *pvVar15;
  int iVar16;
  byte *pbVar17;
  c1_symbol *pcVar18;
  uint *puVar19;
  uint uVar20;
  PB puVar21;
  byte bVar22;
  byte bVar23;
  short *psVar24;
  uint uVar25;
  PB puVar26;
  ushort uVar27;
  fe_il_buffer *buf;
  ushort uVar28;
  short sVar29;
  uchar *puVar30;
  char *pcVar31;
  
  if (g_il_block_level == '\0') {
    pvVar15 = sym_segment_record(sym);
    il_emit_global_symbol((int *)((int)pvVar15 + 8));
  }
  iVar14 = record_class;
  if ((record_class == typedef_class) && (g_opt_Zi == '\0')) {
    return;
  }
  pcVar31 = g_il_symbol_record_templates[record_class].codes;
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
  codes = pcVar31;
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
        uVar20 = il_symbol_key_assign(sym);
      }
      else {
        uVar20 = sym->key_ref >> 3;
      }
    }
    else {
      uVar20 = sym->entity & 0xffffff;
    }
    ilstore_query_record(uVar20,5,&stored_record);
    rec_word0 = *stored_record;
    rec_word1 = stored_record[1];
    rec_word2 = stored_record[2];
  }
  cVar3 = *pcVar31;
  uVar20 = g_cv_precomp_signature;
  puVar13 = (uchar *)g_source_file_ni;
  iVar16 = g_function_formal_count;
  uVar25 = rec_word2;
  do {
    g_cv_precomp_signature = uVar20;
    g_source_file_ni = (int)puVar13;
    g_function_formal_count = iVar16;
    rec_word2 = uVar25;
    if (cVar3 == '\0') {
      if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
        if (buf == &g_il_gi_buffer) {
          ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
        }
        else if (buf == &g_il_gl) {
          ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
        }
        if ((fdef_mode == '\0') && (iVar14 == 0xe)) {
          uVar20 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
          puVar26 = g_il_gi_fdef.bytes.pbEnd;
          puVar21 = (PB)(uVar20 & 0xffffff01);
          g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)puVar21;
          if (g_il_gi_fdef.open != 0) {
            *(uint *)g_il_gi_fdef.bytes.pbEnd = rec_word0;
            *(uint *)(puVar26 + 4) = rec_word1;
            *(uint *)(puVar26 + 8) = rec_word2;
            puVar21 = g_il_gi_fdef.bytes.pbEnd + 0xc;
            g_il_gi_fdef.bytes.pbEnd = puVar21;
          }
          ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                             CONCAT31((int3)((uint)puVar21 >> 8),(sym->flags21 & 1) != 0) + 1);
        }
      }
      return;
    }
    codes = codes + 1;
    rec_word2._0_2_ = (ushort)uVar25;
    rec_word2._2_2_ = (ushort)(uVar25 >> 0x10);
    uVar4 = rec_word2._2_2_;
    pcVar18 = sym;
    switch(cVar3) {
    case '\x01':
      bVar23 = sym->kind & 0x1f;
      if (((bVar23 == 7) || (bVar23 == 8)) || (bVar23 == 6)) {
        value = (c1_symbol_cell *)type_size(base_type);
      }
      else {
        value = (c1_symbol_cell *)type_size(type);
        if (value == (c1_symbol_cell *)0x0) {
          bVar23 = sym->kind & 0x1f;
          if (bVar23 == 0xb) {
            type_check_size_known(type);
          }
          else if (bVar23 == 0xc) {
            il_emit_symbol_part(type,0,sym,buf,fdef_mode,type,derived_type,stored_record,base_type,
                                (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1
                                ,(ushort)rec_word2,rec_word2._2_2_,record_class,sym_arg);
            return;
          }
        }
      }
      if ((((sym->flags3 & 4) != 0) && ((type->code & 0x200) != 0)) &&
         ((((type->extra).sym)->flags4 & 1) != 0)) {
        il_emit_symbol_fragment
                  ((uint)value,sym,buf,fdef_mode,type,derived_type,stored_record,base_type,
                   (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,
                   (ushort)rec_word2,rec_word2._2_2_,record_class,sym_arg);
        return;
      }
LAB_10601594:
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if ((bVar23 != 0) &&
         (iVar14 = il_buffer_put_byte7(buf,(uint)value), pcVar18 = sym_arg, uVar25 = rec_word2,
         (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
LAB_10601602:
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *(c1_symbol_cell **)puVar26 = value;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar18 = sym;
        uVar25 = rec_word2;
      }
      break;
    case '\x02':
      if (fdef_mode == '\0') {
        bVar23 = sym->flags4;
        if (((((bVar23 & 0x80) == 0) || (bVar22 = sym->kind & 0x1f, bVar22 == 7)) || (bVar22 == 8))
           || (bVar22 == 6)) {
          uVar20 = 0;
        }
        else {
          uVar20 = 0x80;
        }
        bVar22 = sym->kind & 0x1f;
        if (((bVar22 == 7) || (bVar22 == 8)) || (bVar22 == 6)) {
          if ((bVar23 & 2) != 0) {
            uVar20 = uVar20 | 0x100;
          }
          if ((sym->flags22 & 1) != 0) {
            uVar20 = uVar20 | 0x400;
          }
          if (((sym->x2c).function_flags & 1) != 0) {
            uVar20 = uVar20 | 0x80;
          }
        }
        if ((sym->key_ref & 3) != 0) {
          if (((bVar22 == 10) || (bVar22 == 0xb)) && ((bVar23 & 8) != 0)) {
            uVar20 = uVar20 | 0x2000;
          }
          if (((bVar22 != 7) && (bVar22 != 8)) && (bVar22 != 6)) {
            uVar20 = uVar20 | 0x100;
          }
        }
        if ((sym->flags3 & 8) != 0) {
          uVar20 = uVar20 | 0x400;
        }
        switch(elem_flag_bits & 7) {
        case 3:
          uVar20 = uVar20 | 4;
          break;
        case 4:
          uVar20 = uVar20 | 0x18;
          break;
        case 5:
          if (((derived_type == (c1_type *)0x0) || ((derived_type->code & 0x83) != 0x81)) ||
             ((derived_type->flags & 0x8000) == 0)) {
            uVar20 = uVar20 | 0x10;
          }
          break;
        case 6:
          uVar20 = uVar20 | 0x14;
        }
        if (((bVar22 == 7) || (bVar22 == 8)) || (bVar22 == 6)) {
          if ((sym->flags4 & 0x10) != 0) {
            uVar20 = uVar20 | 0x8000;
          }
          if ((sym->flags4 & 1) != 0) {
            uVar20 = uVar20 | 0x1000;
          }
        }
        if ((((sym->flags22 & 2) != 0) && (bVar22 != 7)) && (bVar22 != 8)) {
          uVar20 = uVar20 | 0x1000;
        }
        if ((bVar22 == 10) && ((sym->flags21 & 0x80) != 0)) {
          uVar20 = uVar20 | 0x40;
        }
        if ((sym->storage & 0x40) != 0) {
          if ((record_class != 0xe) && ((sym->flags3 & 4) == 0)) {
            pcVar11 = sym->type;
            cVar3 = (char)pcVar11->code;
            while (cVar3 < '\0') {
              pcVar11 = pcVar11->base;
              cVar3 = (char)pcVar11->code;
            }
            if ((pcVar11->flags & 0x18) != 0) goto LAB_106016e1;
          }
          if ((sym->flags22 & 8) == 0) {
            uVar20 = uVar20 | 0x20;
          }
        }
LAB_106016e1:
        il_emit_symbol_reference(buf,sym,uVar20);
        rec_word0 = uVar20;
        uVar25 = rec_word2;
      }
      else {
        il_emit_symbol_reference(buf,sym,rec_word0);
        uVar25 = rec_word2;
      }
      break;
    case '\x03':
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = (uchar)record_class;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\x04':
      if (is_array == 0) {
        value = (c1_symbol_cell *)0x0;
      }
      else {
        value = (c1_symbol_cell *)sym_element_size(sym);
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if ((bVar23 != 0) &&
         (iVar14 = il_buffer_put_byte7(buf,(uint)value), pcVar18 = sym_arg, uVar25 = rec_word2,
         (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        goto LAB_10601602;
      }
      break;
    case '\x05':
      if (g_c9il_mode == '\0') {
        if ((sym->key_ref & 0xfffffff8) == 0) {
          uVar20 = il_symbol_key_assign(sym);
          goto LAB_106018ae;
        }
        uVar20 = sym->key_ref >> 3;
      }
      else {
        uVar20 = sym->entity & 0xffffff;
LAB_106018ae:
        if (g_c9il_mode != '\0') {
          il_buffer_put_id(buf,uVar20);
          uVar25 = rec_word2;
          break;
        }
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        bVar23 = (byte)uVar20;
        if (uVar20 < 0x3fff80) {
          if (uVar20 < 0x4000) {
            *(buf->bytes).pbEnd = bVar23 & 0x3f | 0x80;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar20 >> 6);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar18 = sym;
          }
          else {
            *(buf->bytes).pbEnd = bVar23 | 0xc0;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar20 >> 6);
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *puVar26 = (uchar)(uVar20 >> 0xe);
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar18 = sym;
          }
        }
        else {
          *(buf->bytes).pbEnd = bVar23 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar18 = sym;
        }
      }
      break;
    case '\x06':
      if (g_opt_Zi != '\0') {
        bVar23 = sym->kind & 0x1f;
        if ((((bVar23 != 0) && (bVar23 < 0xf)) && (bVar23 != 5)) &&
           (((sym->flags23 & 1) != 0 &&
            (pvVar15 = sym_segment_record(sym), *(void **)((int)pvVar15 + 8) == g_name_drectve)))) {
          il_emit_symbol_fragment_2
                    (sym,buf,fdef_mode,type,derived_type,stored_record,base_type,(ushort)basic_code,
                     is_array,codes,elem_flag_bits,rec_word0,rec_word1,(ushort)rec_word2,
                     rec_word2._2_2_,record_class,sym_arg);
          return;
        }
        if ((sym->kind & 0x1f) == 4) {
          value = (sym->x2c).references;
LAB_10601955:
          if (value != (c1_symbol_cell *)0x0) goto LAB_10601594;
        }
        else if ((sym->type->code & 0x300) != 0) {
          value = (c1_symbol_cell *)((sym->type->extra).tag)->debug_index;
          goto LAB_10601955;
        }
        value = (c1_symbol_cell *)type->debug_index;
        goto LAB_10601594;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if ((bVar23 != 0) &&
         (iVar14 = il_buffer_put_byte7(buf,0), pcVar18 = sym_arg, uVar25 = rec_word2,
         (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\0';
        puVar26[1] = '\0';
        puVar26[2] = '\0';
        puVar26[3] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar18 = sym;
      }
      break;
    case '\a':
      cVar10 = g_il_block_level;
      if (record_class == 3) {
        cVar10 = (sym->x28).bytes.bit_position;
      }
      goto LAB_10601974;
    case '\b':
      bVar23 = sym->kind & 0x1f;
      if (bVar23 == 9) {
        bVar23 = *(byte *)&sym->detail;
      }
      else if ((sym->flags3 & 8) == 0) {
        if ((bVar23 == 10) && ((sym->storage & 7) == 3)) {
          bVar23 = 0x24;
        }
        else {
          bVar23 = 0;
        }
      }
      else {
        bVar23 = -((sym->storage & 7) != 2) & 0x25;
      }
      goto LAB_106019ae;
    case '\t':
      if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) goto LAB_10601a0e;
      src = (uint *)decorate_check_name_length(sym);
      uVar20 = 0xffffffff;
      puVar19 = src;
      do {
        if (uVar20 == 0) break;
        uVar20 = uVar20 - 1;
        uVar25 = *puVar19;
        puVar19 = (uint *)((int)puVar19 + 1);
      } while ((char)uVar25 != '\0');
      cVar10 = il_buffer_reserve_ok(buf,~uVar20);
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (cVar10 != '\0') {
        il_buffer_put_bytes(buf,src,~uVar20);
        pcVar18 = sym;
        uVar25 = rec_word2;
      }
      break;
    case '\n':
      bVar23 = sym->flags4;
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar22 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar22;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar22 != 0) {
        *(buf->bytes).pbEnd = ((bVar23 & 4) != 0) + '\x01';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\v':
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\f':
      bVar23 = sym->kind & 0x1f;
      if ((bVar23 == 0xb) || (bVar23 == 0xc)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = '\x03';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar18 = sym;
        }
      }
      else {
        bVar23 = sym->storage & 7;
        if ((bVar23 == 0) || (3 < bVar23)) {
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar23 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar23;
          pcVar18 = sym_arg;
          uVar25 = rec_word2;
          if (bVar23 != 0) {
            *(buf->bytes).pbEnd = '\x01';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar18 = sym;
          }
        }
        else {
          pcVar11 = type;
          if ((type->code & 0x8f) == 0x83) {
            pcVar11 = type_skip_arrays(type->base);
          }
          if (((byte)pcVar11->flags >> 5 & 1) == 0) {
            if (((((sym->flags3 & 8) == 0) || ((sym->storage & 0x40) == 0)) ||
                (g_string_pooling_readonly == '\0')) ||
               ((((sym->flags23 & 1) != 0 &&
                 (pbVar17 = sym_segment_record(sym), (*pbVar17 & 0x1f) == 0xe)) &&
                (pvVar15 = sym_segment_record(sym), (*(uint *)((int)pvVar15 + 0x1c) & 0xffffff) != 3
                )))) {
              iVar14 = il_buffer_reserve(&buf->bytes,2);
              bVar23 = buf->open & (byte)iVar14 & 1;
              buf->open = bVar23;
              pcVar18 = sym_arg;
              uVar25 = rec_word2;
              if (bVar23 != 0) {
                *(buf->bytes).pbEnd = '\x02';
                (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                pcVar18 = sym;
              }
              break;
            }
          }
          else if ((sym->flags23 & 1) != 0) {
            il_emit_symbol_fragment_3
                      (sym,buf,fdef_mode,type,derived_type,stored_record,base_type,
                       (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,
                       (ushort)rec_word2,rec_word2._2_2_,record_class,sym_arg);
            return;
          }
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar23 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar23;
          pcVar18 = sym_arg;
          uVar25 = rec_word2;
          if (bVar23 != 0) {
            *(buf->bytes).pbEnd = '\x04';
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar18 = sym;
          }
        }
      }
      break;
    case '\r':
      if (((record_class == 4) || (record_class == 0x10)) || (record_class == 0xe)) {
        uVar28 = base_type->code;
        cVar3 = (char)uVar28;
        if ((cVar3 < '\0') && (base_type != (c1_type *)0x0)) {
          uVar27 = base_type->flags;
        }
        else {
          uVar28 = 0;
          uVar27 = 0;
        }
        uVar20 = 0;
        pcVar11 = base_type;
        while (cVar3 < '\0') {
          pcVar11 = pcVar11->base;
          cVar3 = (char)pcVar11->code;
        }
        uVar25 = basic_code >> 0x10;
        basic_code = CONCAT22((short)uVar25,pcVar11->code);
        pcVar11 = base_type;
      }
      else {
        if (derived_type == (c1_type *)0x0) {
          uVar28 = 0;
          uVar27 = 0;
        }
        else {
          uVar28 = derived_type->code;
          uVar27 = derived_type->flags;
        }
        pcVar11 = type;
        if ((basic_code & 0x200) == 0) {
LAB_10601c71:
          uVar20 = 0;
        }
        else {
          if ((ushort)basic_code != 0x203) {
            pcVar5 = sym_arg->type;
            cVar3 = (char)pcVar5->code;
            while (cVar3 < '\0') {
              pcVar5 = pcVar5->base;
              cVar3 = (char)pcVar5->code;
            }
            if ((pcVar5->code & 0x300) == 0) {
              pcVar18 = (c1_symbol *)0x0;
            }
            else {
              pcVar18 = (pcVar5->extra).sym;
            }
            if ((pcVar18->tag_alignment & 0x100) == 0) goto LAB_10601c71;
          }
          uVar20 = 0x10;
        }
      }
      if ((uVar27 & 0x100) != 0) {
        uVar20 = uVar20 | 0x4000;
      }
      if ((uVar27 & 0x40) != 0) {
        uVar20 = uVar20 | 0x1000;
      }
      uVar28 = uVar28 & 0x8f;
      if (uVar28 == 0x83) {
        uVar20 = uVar20 | 6;
      }
      else if (((uVar28 == 0x82) || (uVar28 == 0x86)) || (uVar28 == 0x80)) {
        uVar20 = uVar20 | 3;
      }
      else {
        uVar28 = pcVar11->code;
        if ((uVar28 & 0x2000) == 0) {
          if ((((g_ms_extensions == '\0') && ((uVar28 & 0xfff) == 0x11)) && ((uVar28 & 0x1000) == 0)
              ) && (g_opt_J_unsigned_char != '\0')) {
            uVar28 = (ushort)rec_word2;
            il_emit_symbol_fragment_5
                      (uVar20,buf,fdef_mode,type,derived_type,stored_record,base_type,
                       (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar28,
                       uVar4,record_class,sym_arg);
            return;
          }
          uVar25 = basic_code & 0xffff;
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
                uVar20 = uVar20 | 5;
                break;
              case 0x40:
                uVar20 = uVar20 | 7;
              }
              goto LAB_10601ca3;
            }
          }
          else {
            if (uVar25 < 0x403) {
              if (uVar25 != 0x402) {
                if ((uVar25 < 0x201) || (0x203 < uVar25)) goto code_r0x10601daf;
                uVar20 = uVar20 | 6;
                goto LAB_10601ca3;
              }
              goto code_r0x10601d74;
            }
            if (uVar25 != 0x1011) {
              uVar28 = (ushort)rec_word2;
              il_emit_symbol_record_fragment
                        (uVar25,uVar20,buf,fdef_mode,type,derived_type,stored_record,base_type,
                         (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar28
                         ,uVar4,record_class,sym_arg);
              return;
            }
          }
switchD_10601d6d_caseD_11:
          uVar20 = uVar20 | 1;
        }
        else {
code_r0x10601d74:
          uVar20 = uVar20 | 2;
        }
      }
LAB_10601ca3:
      if (0x7f < (ushort)uVar20) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = (byte)(uVar20 >> 8) | 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = (uchar)uVar20;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      break;
    case '\x0e':
      cVar8 = sym->key_ref;
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(byte)cVar8 & 3);
        pcVar18 = sym;
        uVar25 = rec_word2;
      }
      break;
    case '\x0f':
      name_00 = sym->detail;
      if ((name_00 != (fe_name *)0x0) && (name_00 != g_name_unnamed)) {
        uVar4 = (ushort)rec_word2;
        func_report_static_not_defined
                  (name_00,buf,fdef_mode,type,derived_type,(int)stored_record,base_type,
                   (ushort)basic_code,is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar4,
                   record_class,sym_arg);
        return;
      }
LAB_10601a0e:
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\x10':
      if (((sym->flags22 & 4) == 0) || (record_class == 7)) {
        if (((sym->flags22 & 8) == 0) || (record_class == 7)) {
          if ((sym->storage & 0x40) == 0) {
            bVar23 = sym->storage & 7;
            if (((bVar23 < 4) || (6 < bVar23)) && (bVar23 != 3)) {
              if ((sym->flags3 & 4) == 0) {
                if (bVar23 == 1) goto LAB_10601e86;
                if ((is_array == 0) || (bVar23 = 2, (derived_type->extra).sym != (c1_symbol *)0x0))
                {
                  bVar23 = 3;
                }
              }
              else {
                bVar23 = 1;
              }
            }
            else {
              bVar23 = 4;
            }
          }
          else {
            bVar23 = (~sym->flags3 & 4 | 2) >> 1;
          }
        }
        else {
          bVar23 = 8;
        }
      }
      else if ((sym->flags1 & 1) == 0) {
LAB_10601e86:
        bVar23 = 2;
      }
      else {
        bVar23 = (-((sym->flags3 & 4) != 0) & 0xfeU) + 9;
      }
LAB_106019ae:
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar22 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar22;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar22 != 0) {
        *(buf->bytes).pbEnd = bVar23;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\x11':
      bVar23 = sym->kind & 0x1f;
      if ((((bVar23 == 7) || (bVar23 == 8)) || (bVar23 == 6)) && ((sym->flags1 & 1) != 0)) {
        if ((sym->flags22 & 4) == 0) {
          if ((sym->flags22 & 8) == 0) {
            if ((sym->storage & 0x40) == 0) {
              cVar10 = (-((sym->storage & 7) != 3) & 2U) + 3;
            }
            else {
              cVar10 = '\x05';
            }
          }
          else {
            cVar10 = '\n';
          }
        }
        else {
          cVar10 = '\t';
        }
      }
      else {
        bVar23 = sym->storage & 7;
        if ((bVar23 == 3) && ((g_incremental == '\0' || (g_opt_GI != '\0')))) {
          diag_error(0x81,sym);
          cVar10 = '\x02';
        }
        else {
          if (((sym->flags21 & 1) != 0) && (bVar23 != 1)) {
            uVar4 = (ushort)rec_word2;
            func_check_inline_definitions
                      (sym,buf,fdef_mode,type,derived_type,base_type,(ushort)basic_code,is_array,
                       codes,elem_flag_bits,rec_word0,rec_word1,uVar4,record_class,sym_arg);
            return;
          }
          cVar10 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
        }
      }
LAB_10601974:
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = cVar10;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\x13':
      iVar14 = 6;
      goto LAB_10602252;
    case '\x14':
      iVar14 = (sym->x28).value;
      if ((iVar14 < 0x8000) && (-0x8001 < iVar14)) {
        bVar23 = 1;
      }
      else {
        bVar23 = 0;
      }
      sVar29 = (-(ushort)bVar23 & 0xfffe) + 4;
      iVar16 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar23;
      if ((bVar23 != 0) && (iVar16 = il_buffer_put_byte7(buf,(int)sVar29), (char)iVar16 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        psVar24 = (short *)((buf->bytes).pbEnd + 1);
        (buf->bytes).pbEnd = (PB)psVar24;
        *psVar24 = sVar29;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar23;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = (uchar)iVar14;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      iVar16 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar16 & 1;
      buf->open = bVar23;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = (uchar)((uint)iVar14 >> 8);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      }
      if ((0x7fff < iVar14) || (pcVar18 = sym_arg, uVar25 = rec_word2, iVar14 < -0x8000)) {
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar23 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = (uchar)((uint)iVar14 >> 0x10);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        iVar16 = il_buffer_reserve(&buf->bytes,2);
        bVar23 = buf->open & (byte)iVar16 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = (uchar)((uint)iVar14 >> 0x18);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          pcVar18 = sym;
        }
      }
      break;
    case '\x15':
      pcVar18 = decl_lookup_file_scope_twin(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar18->key_ref & 0xfffffff8) == 0) {
          uVar20 = il_symbol_key_assign(pcVar18);
          goto LAB_10638f6a;
        }
        uVar20 = pcVar18->key_ref >> 3;
      }
      else {
        uVar20 = pcVar18->entity & 0xffffff;
LAB_10638f6a:
        if (g_c9il_mode != '\0') goto LAB_10638f73;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        bVar23 = (byte)uVar20;
        if (uVar20 < 0x3fff80) {
          if (uVar20 < 0x4000) {
            *(buf->bytes).pbEnd = bVar23 & 0x3f | 0x80;
            goto LAB_10638fd8;
          }
          *(buf->bytes).pbEnd = bVar23 | 0xc0;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar20 >> 6);
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar20 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = bVar23 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      break;
    case '\x16':
      pcVar18 = sym_segment_record(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar18->key_ref & 0xfffffff8) == 0) {
          uVar20 = il_symbol_key_assign(pcVar18);
          goto LAB_1063904f;
        }
        uVar20 = pcVar18->key_ref >> 3;
LAB_10639060:
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 == 0) break;
        bVar23 = (byte)uVar20;
        if (0x3fff7f < uVar20) {
          *(buf->bytes).pbEnd = bVar23 + 0x80;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          break;
        }
        if (0x3fff < uVar20) {
          *(buf->bytes).pbEnd = bVar23 | 0xc0;
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar20 >> 6);
          puVar26 = (buf->bytes).pbEnd + 1;
          (buf->bytes).pbEnd = puVar26;
          *puVar26 = (uchar)(uVar20 >> 0xe);
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          break;
        }
        *(buf->bytes).pbEnd = bVar23 & 0x3f | 0x80;
LAB_10638fd8:
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        *puVar26 = (uchar)(uVar20 >> 6);
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
      }
      else {
        uVar20 = pcVar18->entity & 0xffffff;
LAB_1063904f:
        if (g_c9il_mode == '\0') goto LAB_10639060;
LAB_10638f73:
        il_buffer_put_id(buf,uVar20);
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
      }
      break;
    case '\x17':
      cVar10 = (sym->x28).bytes.bit_position;
      if ((cVar10 != '\0') && (cVar10 != '\x02')) {
        cVar10 = (-(cVar10 != '\x03') & 0xfeU) + 3;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = cVar10;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '\x18':
      uVar20 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
      stored_record = (uint *)g_function_ex_offset;
      if (g_c9il_mode != '\0') {
        stored_record = (uint *)g_function_ex_offset;
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          if (((uint)stored_record & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)stored_record;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar26 = (buf->bytes).pbEnd + 1;
            (buf->bytes).pbEnd = puVar26;
            *(uint **)puVar26 = stored_record;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 != 0) {
          if ((uVar20 & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)uVar20;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            pcVar18 = sym;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar19 = (uint *)((buf->bytes).pbEnd + 1);
            (buf->bytes).pbEnd = (PB)puVar19;
            *puVar19 = uVar20;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
            pcVar18 = sym;
          }
        }
      }
      break;
    case '\x19':
      if (fdef_mode == '\0') {
        rec_word1._2_2_ = (undefined2)(rec_word1 >> 0x10);
        rec_word1 = CONCAT22(rec_word1._2_2_,0xffff);
        if (g_function_tuple_count < 0x10000) {
          rec_word1 = CONCAT22(rec_word1._2_2_,(short)g_function_tuple_count);
        }
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(ushort)rec_word1);
        pcVar18 = sym;
        uVar25 = rec_word2;
      }
      break;
    case '\x1a':
      if (fdef_mode == '\0') {
        if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
          sVar29 = 0;
        }
        else {
          sVar29 = 0x1000;
        }
        uVar25 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 | (ushort)(sym->flags21 & 1)) << 7) |
                 (sym->flags4 & 0x80) >> 5 |
                 (int)(short)(-(ushort)(g_compile_function_body != '\0') & 0x20) |
                 (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                 (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar29;
        uVar4 = *(ushort *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 2);
        if (((uVar4 & 0x2000) != 0) && ((uVar4 & 0x4000) == 0)) {
          g_function_not_inlinable = 1;
        }
        if (g_inline_level == 1) {
LAB_10602124:
          if (g_function_not_inlinable == 0) {
LAB_10602128:
            if ((sym->type->flags & 0x8000) == 0) {
              if ((sym->flags21 & 1) != 0) {
                uVar25 = uVar25 | 0x40;
              }
              goto LAB_1060213d;
            }
          }
LAB_10602193:
          uVar25 = (int)(short)uVar25 & 0xffffffbf;
          if ((sym->flags21 & 1) != 0) {
            func_emit_inline_candidate
                      (uVar25,sym,buf,'\0',type,derived_type,base_type,(ushort)basic_code,is_array,
                       codes,elem_flag_bits,rec_word0,rec_word1,record_class,sym_arg);
            return;
          }
        }
        else if (g_inline_level == 2) {
          if (g_function_auto_inline == 0) goto LAB_10602124;
          if (g_function_not_inlinable == 0) {
            if ((((sym->storage & 7) == 3) && (((byte)sym->key_ref & 3) == 1)) ||
               (g_function_tuple_count < (uint)g_autoinline_tuple_limit)) {
              uVar25 = uVar25 | 0x40;
            }
            goto LAB_10602128;
          }
          goto LAB_10602193;
        }
LAB_1060213d:
        iVar14 = il_buffer_reserve(&buf->bytes,5);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          if (uVar25 < 0x8000) {
            *(short *)(buf->bytes).pbEnd = (short)uVar25;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          }
          else {
            *(uint *)(buf->bytes).pbEnd = uVar25 | 0x8000;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
          }
        }
      }
      else {
        iVar14 = il_buffer_reserve(&buf->bytes,5);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 != 0) {
          if ((int)rec_word2 < 0x8000) {
            *(ushort *)(buf->bytes).pbEnd = (ushort)rec_word2;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
            pcVar18 = sym;
          }
          else {
            *(uint *)(buf->bytes).pbEnd =
                 (uint)((uint3)(rec_word2 >> 8) & 0xffffc0 | 0x40) << 9 | rec_word2 & 0x7fff;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
            pcVar18 = sym;
          }
        }
      }
      break;
    case '\x1c':
    case '\x1d':
      stored_record = (uint *)0x386;
      iVar14 = il_buffer_reserve(&buf->bytes,3);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(undefined2 *)(buf->bytes).pbEnd = stored_record._0_2_;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        pcVar18 = sym;
      }
      break;
    case '\x1e':
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        puVar26 = (buf->bytes).pbEnd;
        puVar26[0] = 0x96;
        puVar26[1] = 0xba;
        puVar26[2] = '0';
        puVar26[3] = '\x01';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar18 = sym;
      }
      break;
    case ' ':
      iVar14 = 2;
LAB_10602252:
      iVar14 = il_buffer_reserve(&buf->bytes,iVar14);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(buf->bytes).pbEnd = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        pcVar18 = sym;
      }
      break;
    case '!':
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      if (bVar23 != 0) {
        if ((uVar20 & 0xffffff80) == 0) {
          *(buf->bytes).pbEnd = (uchar)uVar20;
          puVar26 = (buf->bytes).pbEnd + 1;
        }
        else {
          *(buf->bytes).pbEnd = 0x80;
          puVar19 = (uint *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)puVar19;
          *puVar19 = uVar20;
          puVar26 = (buf->bytes).pbEnd + 4;
        }
        (buf->bytes).pbEnd = puVar26;
      }
      puVar13 = (uchar *)g_il_pch_name;
      if (g_il_pch_name == (char *)0x0) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = '\0';
          puVar26 = (buf->bytes).pbEnd + 1;
LAB_106022da:
          (buf->bytes).pbEnd = puVar26;
        }
      }
      else {
        uVar20 = 0xffffffff;
        pcVar31 = g_il_pch_name;
        do {
          if (uVar20 == 0) break;
          uVar20 = uVar20 - 1;
          cVar3 = *pcVar31;
          pcVar31 = pcVar31 + 1;
        } while (cVar3 != '\0');
        uVar20 = ~uVar20;
        iVar14 = il_buffer_reserve(&buf->bytes,uVar20 + 1);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          puVar26 = (buf->bytes).pbEnd;
          for (uVar25 = uVar20 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
            *(undefined4 *)puVar26 = *(undefined4 *)puVar13;
            puVar13 = puVar13 + 4;
            puVar26 = puVar26 + 4;
          }
          for (uVar25 = uVar20 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
            *puVar26 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar26 = puVar26 + 1;
          }
          puVar26 = (buf->bytes).pbEnd + uVar20;
          goto LAB_106022da;
        }
      }
      if (g_pragma_comment_list == (fe_pragma_comment *)0x0) {
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if (bVar23 != 0) {
          *(buf->bytes).pbEnd = '\0';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
      }
      else {
        uVar20 = 0;
        pfVar9 = (fe_pragma_comment *)0x0;
        pfVar7 = g_pragma_comment_list;
        while (g_pragma_comment_list = pfVar9, pfVar7 != (fe_pragma_comment *)0x0) {
          pfVar6 = pfVar7->next;
          pfVar7->next = g_pragma_comment_list;
          uVar20 = uVar20 + 1;
          pfVar9 = pfVar7;
          pfVar7 = pfVar6;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        pfVar7 = g_pragma_comment_list;
        if (bVar23 != 0) {
          if ((uVar20 & 0xffffff80) == 0) {
            *(buf->bytes).pbEnd = (uchar)uVar20;
            puVar26 = (buf->bytes).pbEnd + 1;
          }
          else {
            *(buf->bytes).pbEnd = 0x80;
            puVar19 = (uint *)((buf->bytes).pbEnd + 1);
            (buf->bytes).pbEnd = (PB)puVar19;
            *puVar19 = uVar20;
            puVar26 = (buf->bytes).pbEnd + 4;
          }
          (buf->bytes).pbEnd = puVar26;
          pfVar7 = g_pragma_comment_list;
        }
        while (pcVar18 = sym_arg, stored_record = (uint *)pfVar7, uVar25 = rec_word2,
              pfVar7 != (fe_pragma_comment *)0x0) {
          puVar13 = (uchar *)pfVar7->text;
          iVar14 = pfVar7->kind;
          iVar16 = il_buffer_reserve(&buf->bytes,2);
          bVar23 = buf->open & (byte)iVar16 & 1;
          buf->open = bVar23;
          if (bVar23 != 0) {
            *(buf->bytes).pbEnd = (uchar)iVar14;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
          if (pfVar7->kind == 7) {
            stored_record = (uint *)pfVar7;
            if ((uchar)(*puVar13 + '\x01') != '\0') {
              puVar19 = (uint *)(int)(char)(*puVar13 + '\x01');
              do {
                stored_record = puVar19;
                uVar2 = *puVar13;
                iVar14 = il_buffer_reserve(&buf->bytes,2);
                bVar23 = buf->open & (byte)iVar14 & 1;
                buf->open = bVar23;
                if (bVar23 != 0) {
                  *(buf->bytes).pbEnd = uVar2;
                  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
                }
                puVar13 = puVar13 + 1;
                puVar19 = (uint *)((int)stored_record + -1);
                stored_record = (uint *)pfVar7;
              } while (puVar19 != (uint *)0x0);
            }
          }
          else {
            uVar20 = 0xffffffff;
            puVar30 = puVar13;
            do {
              if (uVar20 == 0) break;
              uVar20 = uVar20 - 1;
              uVar2 = *puVar30;
              puVar30 = puVar30 + 1;
            } while (uVar2 != '\0');
            uVar20 = ~uVar20;
            iVar14 = il_buffer_reserve(&buf->bytes,uVar20 + 1);
            bVar23 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar23;
            if (bVar23 != 0) {
              puVar26 = (buf->bytes).pbEnd;
              for (uVar25 = uVar20 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
                *(undefined4 *)puVar26 = *(undefined4 *)puVar13;
                puVar13 = puVar13 + 4;
                puVar26 = puVar26 + 4;
              }
              for (uVar25 = uVar20 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
                *puVar26 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar26 = puVar26 + 1;
              }
              ppuVar1 = &(buf->bytes).pbEnd;
              *ppuVar1 = *ppuVar1 + uVar20;
            }
          }
          pfVar7 = ((fe_pragma_comment *)stored_record)->next;
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
      uVar20 = sym_keys->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      sym_keys->entity = uVar20 & 0xffffff ^ sym_keys->entity;
      uVar20 = il_symbol_key_2((int)sym_keys);
      if (g_c9il_mode == '\0') {
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar23 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar23;
        if (bVar23 != 0) {
          bVar23 = (byte)uVar20;
          if (uVar20 < 0x3fff80) {
            if (uVar20 < 0x4000) {
              *(buf->bytes).pbEnd = bVar23 & 0x3f | 0x80;
              puVar26 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar26;
              *puVar26 = (uchar)(uVar20 >> 6);
              (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            }
            else {
              *(buf->bytes).pbEnd = bVar23 | 0xc0;
              puVar26 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar26;
              *puVar26 = (uchar)(uVar20 >> 6);
              puVar26 = (buf->bytes).pbEnd + 1;
              (buf->bytes).pbEnd = puVar26;
              *puVar26 = (uchar)(uVar20 >> 0xe);
              (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
            }
          }
          else {
            *(buf->bytes).pbEnd = bVar23 + 0x80;
            (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
          }
        }
      }
      else {
        il_buffer_put_id(buf,uVar20);
      }
      puVar13 = (uchar *)pp_position_file_name(&g_token_position);
      uVar20 = 0xffffffff;
      puVar30 = puVar13;
      do {
        if (uVar20 == 0) break;
        uVar20 = uVar20 - 1;
        uVar2 = *puVar30;
        puVar30 = puVar30 + 1;
      } while (uVar2 != '\0');
      uVar20 = ~uVar20;
      iVar14 = il_buffer_reserve(&buf->bytes,uVar20 + 1);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        puVar26 = (buf->bytes).pbEnd;
        for (uVar25 = uVar20 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
          *(undefined4 *)puVar26 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar26 = puVar26 + 4;
        }
        for (uVar25 = uVar20 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
          *puVar26 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar26 = puVar26 + 1;
        }
        ppuVar1 = &(buf->bytes).pbEnd;
        *ppuVar1 = *ppuVar1 + uVar20;
        uVar25 = rec_word2;
      }
      break;
    case '#':
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        iVar14 = il_buffer_put_byte7(buf,(int)(short)iVar16);
        pcVar18 = sym_arg;
        uVar25 = rec_word2;
        if ((char)iVar14 == '\0') {
          *(buf->bytes).pbEnd = 0x80;
          psVar24 = (short *)((buf->bytes).pbEnd + 1);
          (buf->bytes).pbEnd = (PB)psVar24;
          *psVar24 = (short)iVar16;
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
          pcVar18 = sym;
        }
      }
      break;
    case '%':
      uVar20 = 0x400000;
      if (g_c9il_mode != '\0') {
        uVar20 = g_next_entity_id;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        *(uint *)(buf->bytes).pbEnd = uVar20;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
        pcVar18 = sym;
      }
      break;
    case '&':
      uVar20 = 0xffffffff;
      puVar30 = puVar13;
      do {
        if (uVar20 == 0) break;
        uVar20 = uVar20 - 1;
        uVar2 = *puVar30;
        puVar30 = puVar30 + 1;
      } while (uVar2 != '\0');
      uVar20 = ~uVar20;
      iVar14 = il_buffer_reserve(&buf->bytes,uVar20 + 1);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        puVar26 = (buf->bytes).pbEnd;
        for (uVar25 = uVar20 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
          *(undefined4 *)puVar26 = *(undefined4 *)puVar13;
          puVar13 = puVar13 + 4;
          puVar26 = puVar26 + 4;
        }
        for (uVar25 = uVar20 & 3; uVar25 != 0; uVar25 = uVar25 - 1) {
          *puVar26 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar26 = puVar26 + 1;
        }
        ppuVar1 = &(buf->bytes).pbEnd;
        *ppuVar1 = *ppuVar1 + uVar20;
        uVar25 = rec_word2;
      }
      break;
    case '(':
      if (g_c9il_mode == '\0') {
        uVar28 = (ushort)rec_word2;
        il_emit_symbol_record_fragment_2
                  (sym,buf,fdef_mode,type,derived_type,stored_record,base_type,(ushort)basic_code,
                   is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar28,uVar4,record_class,
                   sym_arg);
        return;
      }
      break;
    case ')':
      if (g_c9il_mode == '\0') {
        uVar28 = (ushort)rec_word2;
        il_emit_symbol_record_fragment_3
                  (sym,buf,fdef_mode,type,derived_type,stored_record,base_type,(ushort)basic_code,
                   is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar28,uVar4,record_class,
                   sym_arg);
        return;
      }
      break;
    case '*':
      uVar20 = 2;
      if (g_c9il_mode == '\0') {
        uVar20 = 3;
      }
      if (g_dlp != '\0') {
        uVar20 = uVar20 | 8;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      if (bVar23 != 0) {
        *(uint *)(buf->bytes).pbEnd = uVar20;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      if ((bVar23 != 0) && (iVar14 = il_buffer_put_byte7(buf,0xc), (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\f';
        puVar26[1] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      if ((bVar23 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
        *(buf->bytes).pbEnd = 0x80;
        puVar26 = (buf->bytes).pbEnd + 1;
        (buf->bytes).pbEnd = puVar26;
        puVar26[0] = '\0';
        puVar26[1] = '\0';
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar23 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar23;
      pcVar18 = sym_arg;
      uVar25 = rec_word2;
      if (bVar23 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,0x1fe8);
        pcVar18 = sym;
        uVar25 = rec_word2;
      }
      break;
    case '.':
      if (g_opt_Ct != '\0') {
        uVar28 = (ushort)rec_word2;
        il_emit_symbol_inline_fragment
                  (sym,buf,fdef_mode,type,derived_type,stored_record,base_type,(ushort)basic_code,
                   is_array,codes,elem_flag_bits,rec_word0,rec_word1,uVar28,uVar4,record_class,
                   sym_arg);
        return;
      }
    }
    rec_word2 = uVar25;
    cVar3 = *codes;
    sym = pcVar18;
    uVar20 = g_cv_precomp_signature;
    puVar13 = (uchar *)g_source_file_ni;
    iVar16 = g_function_formal_count;
    uVar25 = rec_word2;
    iVar14 = record_class;
  } while( true );
}

