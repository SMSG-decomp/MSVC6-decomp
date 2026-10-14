void __cdecl il_emit_symbol(int kind,c1_symbol *sym)

{
  c1_u8 **ppcVar1;
  char cVar2;
  byte sym_flags4;
  fe_name *pfVar3;
  c1_symbol_x28_bytes cVar4;
  fe_file_record *file;
  c1xx_idb_vtbl *pcVar5;
  c1_pragma_comment *pcVar6;
  byte bVar7;
  c1_symbol *pcVar8;
  void *value;
  c1_type *pcVar9;
  c1_line_map_row *pcVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  c1_u8 *pcVar15;
  byte bVar16;
  short sVar17;
  c1_type *pcVar18;
  c1_u8 *pcVar19;
  uint *puVar20;
  short *psVar21;
  uint uVar22;
  c1_u16 cVar23;
  uint type_flags;
  c1_u8 cVar24;
  ushort uVar25;
  c1_u32 cVar26;
  c1_il_buffer *buf;
  c1_u16 cVar27;
  ushort uVar28;
  short sVar29;
  char *tmpl;
  c1_pragma_comment *comment_cell;
  char fdef_mode;
  uint part_scratch;
  byte is_inline;
  c1_type *pcVar30;
  c1_type *pcVar31;
  c1_type *fn_type;
  c1_symbol *pair_sym;
  uint base_code;
  uint rec_word0;
  uint rec_word1;
  uint rec_word2;
  uint uVar32;
  uint *out_cell;
  c1_symbol *iter_sym;
  void **ref_cell;
  void **ref_list;
  char acStack_400 [1024];
  c1_pragma_comment *comment_rev;
  c1_pragma_comment *comment_rev_2;
  c1_pragma_comment *comment_next;
  c1_pragma_comment *comment_cell_2;
  
  fn_type = (c1_type *)0x0;
  uVar32 = 0;
  if (g_abort_requested != 0) {
    c1xx_abort_if_running();
  }
  if ((sym == (c1_symbol *)0x0) || (bVar7 = sym->kind & 0x1f, bVar7 == 0x19)) {
    pcVar30 = (c1_type *)0x0;
    base_code = 0;
    type_flags = 0;
    pcVar18 = (c1_type *)0x0;
LAB_1040b512:
    if (kind == 0xb) {
LAB_1040b5b3:
      if (g_opt_Zi == '\0') {
        return;
      }
    }
  }
  else {
    if ((((bVar7 != 0) && (bVar7 < 0xf)) && (bVar7 != 5)) && ((sym->flags3 & 4) != 0)) {
      return;
    }
    pcVar9 = sym->type;
    bVar16 = (byte)pcVar9->code;
    pcVar30 = pcVar9;
    bVar7 = bVar16;
    while ((char)bVar7 < '\0') {
      pcVar30 = pcVar30->base;
      bVar7 = (byte)pcVar30->code;
    }
    base_code = CONCAT22(base_code._2_2_,pcVar30->code);
    pcVar18 = pcVar9;
    pcVar30 = pcVar9;
    if ((bVar16 & 0x8f) == 0x83) {
      pcVar18 = type_skip_arrays(pcVar9->base);
    }
    bVar7 = (byte)pcVar9->code;
    type_flags = (byte)pcVar18->flags & 0x1f;
    pcVar18 = (c1_type *)(-(uint)((pcVar9->code & 0x80) != 0) & (uint)pcVar9);
    if ((sym->kind & 0x1f) != 5) {
      if ((sym->storage & 7) != 7) {
        uVar32 = (uint)((bVar7 & 0x8f) == 0x83);
        if ((uVar32 != 0) && (kind == 1)) {
          kind = 2;
        }
        if ((bVar7 & 0x83) == 0x81) {
          fn_type = pcVar9->base;
          if ((*(byte *)((int)&sym->tail + 9) & 1) == 0) {
            if ((sym->flags1 & 0x10) == 0x10) {
              fn_type = (c1_type *)
                        **(int **)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
            }
          }
          else if ((fn_type->code >> 9 & 1) == 0) {
            fn_type = type_this_pointer((c1_symbol *)0x0,0,0);
          }
          else {
            fn_type = type_this_pointer((fn_type->extra).cls,0,0);
          }
        }
        if ((((sym->flags23 & 1) != 0) &&
            (pcVar8 = sym_segment_record(sym), (pcVar8->kind & 0x1f) == 0xe)) &&
           (pcVar8 = sym_segment_record(sym), (pcVar8->flags2 & 8) == 0)) {
          il_emit_symbol_fragment
                    (sym,0xb,0,part_scratch,is_inline,pcVar30,pcVar18,fn_type,pair_sym,base_code,
                     rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,iter_sym,ref_cell,
                     ref_list,kind,sym);
          return;
        }
        goto LAB_1040b512;
      }
      kind = 0xb;
      goto LAB_1040b5b3;
    }
  }
  tmpl = g_il_symbol_record_templates[kind].codes;
  if (kind != 0x12) {
    if (g_il_block_level != '\0') {
      buf = &g_il_sy;
      goto LAB_1040b54c;
    }
    if (g_c9il_mode == '\0') {
      switch(kind) {
      case 1:
      case 2:
        if (((sym->key_ref >> 2 & 1) == 0) &&
           (((sym->flags2 & 4) == 0 ||
            (((sym->storage & 7) == 3 &&
             (pcVar9 = type_skip_arrays_and_functions(sym->type),
             ((byte)pcVar9->flags >> 5 & 1) != 0)))))) {
          buf = &g_il_gi_buffer;
          goto LAB_1040b54c;
        }
        break;
      case 4:
      case 0x10:
        buf = &g_il_gi_buffer;
        if ((sym->key_ref >> 2 & 1) == 0) goto LAB_1040b54c;
      }
    }
  }
  buf = &g_il_gl;
LAB_1040b54c:
  if ((g_function_il_reused == '\0') || (kind != 0xe)) {
    fdef_mode = '\0';
    if ((((kind == 0xe) || ((kind == 1 || (kind == 2)))) && (buf == &g_il_gl)) &&
       ((((g_il_emit_mode == '\0' && (sym != (c1_symbol *)0x0)) && (sym->name->text != (char *)0x0))
        && (g_c9il_mode == '\0')))) {
      pcVar5 = g_idb->vtbl;
      pcVar13 = sym_format_qualified_function_name(sym,acStack_400,0x400);
      iVar14 = (*pcVar5->idb_add_name)(g_idb,pcVar13);
      if (iVar14 == 0) {
        diag_fatal_simple(0x37);
      }
    }
  }
  else {
    fdef_mode = '\x01';
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar12 = il_symbol_key_assign(sym);
      }
      else {
        uVar12 = sym->key_ref >> 3;
      }
    }
    else {
      uVar12 = sym->entity & 0xffffff;
    }
    ilstore_query_record(uVar12,5,&out_cell);
    rec_word0 = *out_cell;
    rec_word1 = out_cell[1];
    rec_word2 = out_cell[2];
  }
  cVar2 = *tmpl;
  uVar12 = g_cv_precomp_signature;
  pcVar19 = (c1_u8 *)g_source_file_ni;
  iVar14 = g_function_formal_count;
  uVar22 = g_function_ex_offset;
  do {
    g_cv_precomp_signature = uVar12;
    g_source_file_ni = (int)pcVar19;
    g_function_formal_count = iVar14;
    g_function_ex_offset = uVar22;
    if (cVar2 == '\0') {
      if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
        if (buf == &g_il_gi_buffer) {
          ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
        }
        else if (buf == &g_il_gl) {
          ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
        }
        if ((fdef_mode == '\0') && (kind == 0xe)) {
          uVar32 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
          pcVar19 = g_il_gi_fdef.bytes.cur;
          pcVar15 = (c1_u8 *)(uVar32 & 0xffffff01);
          g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)pcVar15;
          if (g_il_gi_fdef.open != 0) {
            *(uint *)g_il_gi_fdef.bytes.cur = rec_word0;
            *(uint *)(pcVar19 + 4) = rec_word1;
            *(uint *)(pcVar19 + 8) = rec_word2;
            pcVar15 = g_il_gi_fdef.bytes.cur + 0xc;
            g_il_gi_fdef.bytes.cur = pcVar15;
          }
          ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                             CONCAT31((int3)((uint)pcVar15 >> 8),(sym->flags21 & 1) != 0) + 1);
        }
      }
      return;
    }
    tmpl = tmpl + 1;
    switch(cVar2) {
    case '\x01':
      bVar7 = sym->kind & 0x1f;
      if (((bVar7 == 7) || (bVar7 == 8)) || (bVar7 == 6)) {
        uVar12 = type_size(fn_type);
        pcVar9 = pcVar30;
      }
      else {
        pcVar9 = pcVar30;
        uVar12 = type_size(pcVar30);
        if (uVar12 == 0) {
          bVar7 = sym->kind & 0x1f;
          if (bVar7 == 0xb) {
            type_check_size_known(pcVar30);
          }
          else if (bVar7 == 0xc) {
            il_emit_symbol_part(pcVar30,0,sym,buf,fdef_mode,part_scratch,is_inline,pcVar9,pcVar18,
                                fn_type,pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,uVar32
                                ,type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
        }
      }
      if ((((sym->flags4 & 4) != 0) && ((pcVar30->code & 0x200) != 0)) &&
         ((((pcVar30->extra).cls)->flags5 & 1) != 0)) {
        il_emit_symbol_size_fragment
                  (uVar12,sym,buf,fdef_mode,part_scratch,is_inline,pcVar9,pcVar18,fn_type,pair_sym,
                   tmpl,base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,iter_sym,
                   ref_cell,ref_list,kind,sym);
        return;
      }
      if ((g_rtti != '\0') && ((sym->flags3 & 0x80) != 0)) {
        uVar12 = uVar12 + 4;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      pcVar30 = pcVar9;
      if ((bVar7 != 0) &&
         (iVar14 = il_buffer_put_byte7(buf,uVar12), pcVar30 = pcVar9, (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        puVar20 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar20;
        *puVar20 = uVar12;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      break;
    case '\x02':
      if (fdef_mode == '\0') {
        bVar7 = sym->flags5;
        if (((((bVar7 & 0x80) == 0) || (bVar16 = sym->kind & 0x1f, bVar16 == 7)) || (bVar16 == 8))
           || (bVar16 == 6)) {
          rec_word0 = 0;
        }
        else {
          rec_word0 = 0x80;
        }
        bVar16 = sym->kind & 0x1f;
        if (((bVar16 == 7) || (bVar16 == 8)) || (bVar16 == 6)) {
          if ((bVar7 & 2) != 0) {
            rec_word0 = rec_word0 | 0x100;
          }
          if ((*(byte *)((int)&sym->tail + 9) & 0xc) != 0) {
            rec_word0 = rec_word0 | 0x400;
          }
          if ((sym->flags22 & 1) != 0) {
            rec_word0 = rec_word0 | 0x400;
          }
          if ((sym->flags23 & 0x10) != 0) {
            rec_word0 = rec_word0 | 0x800;
          }
          if ((*(byte *)((int)&sym->tail + 0xb) & 1) != 0) {
            il_emit_symbol_ref_flag_80_fragment
                      (bVar16,bVar7,rec_word0,sym,buf,'\0',part_scratch,is_inline,pcVar30,pcVar18,
                       fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,uVar32,type_flags,
                       out_cell,iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
        }
        uVar12 = sym->key_ref & 3;
        if (uVar12 != 0) {
          if (((bVar16 == 10) || (bVar16 == 0xb)) && ((bVar7 & 8) != 0)) {
            rec_word0 = rec_word0 | 0x2000;
          }
          if ((((bVar16 != 7) && (bVar16 != 8)) && (bVar16 != 6)) &&
             ((sym->name != g_name_this || (uVar12 != 1)))) {
            rec_word0 = rec_word0 | 0x100;
          }
        }
        sym_flags4 = sym->flags4;
        if ((sym_flags4 & 8) != 0) {
          rec_word0 = rec_word0 | 0x400;
        }
        switch(type_flags & 7) {
        case 3:
          rec_word0 = rec_word0 | 4;
          break;
        case 4:
          rec_word0 = rec_word0 | 0x18;
          break;
        case 5:
          if (((pcVar18 == (c1_type *)0x0) || ((pcVar18->code & 0x83) != 0x81)) ||
             ((pcVar18->flags & 0x8000) == 0)) {
            rec_word0 = rec_word0 | 0x10;
          }
          break;
        case 6:
          rec_word0 = rec_word0 | 0x14;
        }
        if (((bVar16 == 7) || (bVar16 == 8)) || (bVar16 == 6)) {
          if (((bVar7 & 0x10) != 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
            rec_word0 = rec_word0 | 0x8000;
          }
          if ((bVar7 & 1) != 0) {
            il_emit_symbol_ref_flag_1000_fragment
                      (bVar16,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,pcVar30,
                       pcVar18,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,uVar32,type_flags
                       ,out_cell,iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
        }
        bVar7 = sym->flags22;
        if ((((bVar7 & 2) != 0) && (bVar16 != 7)) && (bVar16 != 8)) {
          rec_word0 = rec_word0 | 0x1000;
        }
        if ((bVar16 == 10) && ((sym->flags21 & 0x80) != 0)) {
          il_emit_symbol_ref_flag_40_fragment
                    (bVar7,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,pcVar30,pcVar18,
                     fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,uVar32,type_flags,out_cell,
                     iter_sym,ref_cell,ref_list,kind,sym);
          return;
        }
        if ((sym->storage & 0x40) != 0) {
          if ((kind != 0xe) && ((sym_flags4 & 4) == 0)) {
            il_emit_symbol_ref_base_type_fragment
                      (bVar7,rec_word0,sym,buf,'\0',part_scratch,is_inline,pcVar30,pcVar18,fn_type,
                       pair_sym,tmpl,base_code,rec_word1,rec_word2,uVar32,type_flags,out_cell,
                       iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
          if (((bVar7 & 8) == 0) && (rec_word0 = rec_word0 | 0x20, g_rtti != '\0')) {
            il_emit_symbol_storage_fragment
                      (rec_word0,sym,buf,'\0',part_scratch,is_inline,pcVar30,pcVar18,fn_type,
                       pair_sym,tmpl,base_code,rec_word1,rec_word2,uVar32,type_flags,out_cell,
                       iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
        }
        il_emit_symbol_reference(buf,sym,rec_word0);
      }
      else {
        il_emit_symbol_reference(buf,sym,rec_word0);
      }
      break;
    case '\x03':
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = (c1_u8)kind;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x04':
      if (uVar32 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = sym_element_size((int)sym);
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,uVar12), (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        puVar20 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar20;
        *puVar20 = uVar12;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      break;
    case '\x05':
      if (g_c9il_mode == '\0') {
        if ((sym->key_ref & 0xfffffff8) == 0) {
          uVar12 = il_symbol_key_assign(sym);
          goto LAB_1040ba62;
        }
        uVar12 = sym->key_ref >> 3;
      }
      else {
        uVar12 = sym->entity & 0xffffff;
LAB_1040ba62:
        if (g_c9il_mode != '\0') {
          il_buffer_put_id(buf,uVar12);
          break;
        }
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        bVar7 = (byte)uVar12;
        if (uVar12 < 0x3fff80) {
          if (uVar12 < 0x4000) {
            *(buf->bytes).cur = bVar7 & 0x3f | 0x80;
            pcVar19 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar19;
            *pcVar19 = (c1_u8)(uVar12 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = bVar7 | 0xc0;
            pcVar19 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar19;
            *pcVar19 = (c1_u8)(uVar12 >> 6);
            pcVar19 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar19;
            *pcVar19 = (c1_u8)(uVar12 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          *(buf->bytes).cur = bVar7 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      break;
    case '\x06':
      if (g_opt_Zi == '\0') {
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
          *(buf->bytes).cur = 0x80;
LAB_1047c50f:
          pcVar19 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar19;
          pcVar19[0] = '\0';
          pcVar19[1] = '\0';
          pcVar19[2] = '\0';
          pcVar19[3] = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 4;
        }
      }
      else {
        bVar7 = sym->kind & 0x1f;
        if (bVar7 == 0x19) {
          iVar14 = il_buffer_reserve(&buf->bytes,6);
          bVar7 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar7;
          if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
            *(buf->bytes).cur = 0x80;
            goto LAB_1047c50f;
          }
        }
        else {
          if ((((bVar7 != 0) && (bVar7 < 0xf)) && (bVar7 != 5)) &&
             (((sym->flags23 & 1) != 0 &&
              (pcVar8 = sym_segment_record(sym), pcVar8->name == g_name_drectve)))) {
            il_emit_symbol_type_fragment
                      (sym,buf,fdef_mode,part_scratch,is_inline,pcVar30,pcVar18,fn_type,pair_sym,
                       tmpl,base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,
                       iter_sym,ref_cell,ref_list,kind,sym);
            return;
          }
          bVar7 = sym->kind & 0x1f;
          if (bVar7 == 4) {
            value = (void *)((sym->detail).cls)->debug_index;
LAB_1040bb45:
            if (value == (void *)0x0) goto LAB_1040bac6;
          }
          else {
            if ((sym->type->code & 0x300) != 0) {
              value = (void *)((((sym->type->extra).cls)->detail).cls)->debug_index;
              goto LAB_1040bb45;
            }
            if ((bVar7 == 8) && ((*(byte *)((int)&sym->tail + 10) & 0x10) != 0)) {
              value = symtab_15ec_lookup_by_id(sym);
              goto LAB_1040bb45;
            }
LAB_1040bac6:
            value = (void *)pcVar30->debug_index;
          }
          iVar14 = il_buffer_reserve(&buf->bytes,6);
          bVar7 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar7;
          if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,(uint)value), (char)iVar14 == '\0'))
          {
            *(buf->bytes).cur = 0x80;
            pcVar19 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar19;
            *(void **)pcVar19 = value;
            (buf->bytes).cur = (buf->bytes).cur + 4;
          }
        }
      }
      break;
    case '\a':
      bVar7 = g_il_block_level;
      if (kind == 3) {
        bVar7 = (sym->x28).bytes.bit_position;
      }
      goto LAB_1040bb79;
    case '\b':
      bVar7 = sym->kind & 0x1f;
      if (bVar7 == 9) {
        bVar7 = *(byte *)&sym->detail;
      }
      else if ((sym->flags4 & 8) == 0) {
        if ((bVar7 == 10) && ((sym->storage & 7) == 3)) {
          bVar7 = 0x24;
        }
        else {
          bVar7 = 0;
        }
      }
      else {
        bVar7 = -((sym->storage & 7) != 2) & 0x25;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(buf->bytes).cur = bVar7;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\t':
      if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else if (((g_c9il_mode == '\0') && (uVar12 = sym->key_ref >> 3, 0x14 < uVar12)) &&
              ((uVar12 < g_next_global_key &&
               ((pcVar13 = sym_namespace_member_dotted_name(sym), pcVar13 == (char *)0x0 &&
                (pcVar13 = (char *)pdb_namemap_symbol_name(sym), pcVar13 != (char *)0x0)))))) {
        il_buffer_put_string(buf,pcVar13);
      }
      else {
        pcVar13 = decorate_name(sym,(c1_symbol *)0x0);
        il_buffer_put_string(buf,pcVar13);
      }
      break;
    case '\n':
      bVar7 = sym->flags5;
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(buf->bytes).cur = ((bVar7 & 4) != 0) + '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\v':
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\f':
      bVar7 = sym->kind & 0x1f;
      if ((bVar7 == 0xb) || (bVar7 == 0xc)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = '\x03';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else {
        bVar7 = sym->storage & 7;
        if ((bVar7 == 0) || (3 < bVar7)) {
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar7 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar7;
          if (bVar7 != 0) {
            *(buf->bytes).cur = '\x01';
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          pcVar9 = pcVar30;
          pcVar31 = pcVar30;
          if ((pcVar30->code & 0x8f) == 0x83) {
            pcVar9 = type_skip_arrays(pcVar30->base);
          }
          if (((((((byte)pcVar9->flags >> 5 & 1) == 0) ||
                ((((sym->flags23 & 1) != 0 &&
                  (pcVar8 = sym_segment_record(sym), (pcVar8->kind & 0x1f) == 0xe)) &&
                 (pcVar8 = sym_segment_record(sym), (pcVar8->entity & 0xffffff) != 3)))) ||
               ((sym->flags3 & 0x20) != 0)) ||
              (((-1 < (char)pcVar30->code && ((pcVar30->code & 0x200) != 0)) &&
               ((((((pcVar30->extra).cls)->detail).cls)->flags3f & 0x10) != 0)))) &&
             ((((sym->flags4 & 8) == 0 || ((sym->storage & 0x40) == 0)) ||
              ((g_string_pooling_readonly == '\0' ||
               ((((sym->flags23 & 1) != 0 &&
                 (pcVar8 = sym_segment_record(sym), (pcVar8->kind & 0x1f) == 0xe)) &&
                (pcVar8 = sym_segment_record(sym), (pcVar8->entity & 0xffffff) != 3)))))))) {
            iVar14 = il_buffer_reserve(&buf->bytes,2);
            bVar7 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar7;
            pcVar30 = pcVar31;
            if (bVar7 != 0) {
              *(buf->bytes).cur = '\x02';
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
          }
          else {
            iVar14 = il_buffer_reserve(&buf->bytes,2);
            bVar7 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar7;
            pcVar30 = pcVar31;
            if (bVar7 != 0) {
              *(buf->bytes).cur = '\x04';
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
          }
        }
      }
      break;
    case '\r':
      if (((kind == 4) || (kind == 0x10)) || (kind == 0xe)) {
        cVar27 = fn_type->code;
        cVar2 = (char)cVar27;
        if ((cVar2 < '\0') && (fn_type != (c1_type *)0x0)) {
          cVar23 = fn_type->flags;
        }
        else {
          cVar27 = 0;
          cVar23 = 0;
        }
        uVar25 = 0;
        pcVar9 = fn_type;
        while (cVar2 < '\0') {
          pcVar9 = pcVar9->base;
          cVar2 = (char)pcVar9->code;
        }
        base_code._2_2_ = (undefined2)(base_code >> 0x10);
        base_code = CONCAT22(base_code._2_2_,pcVar9->code);
        pcVar9 = fn_type;
      }
      else {
        if (pcVar18 == (c1_type *)0x0) {
          cVar27 = 0;
          cVar23 = 0;
        }
        else {
          cVar27 = pcVar18->code;
          cVar23 = pcVar18->flags;
        }
        pcVar9 = pcVar30;
        if ((base_code & 0x200) == 0) {
LAB_1040be91:
          uVar25 = 0;
        }
        else {
          if ((short)base_code != 0x203) {
            pcVar31 = sym->type;
            cVar2 = (char)pcVar31->code;
            while (cVar2 < '\0') {
              pcVar31 = pcVar31->base;
              cVar2 = (char)pcVar31->code;
            }
            if ((pcVar31->code & 0x300) == 0) {
              pcVar8 = (c1_symbol *)0x0;
            }
            else {
              pcVar8 = (pcVar31->extra).cls;
            }
            if ((((pcVar8->detail).cls)->layout_flags3b & 1) == 0) goto LAB_1040be91;
          }
          uVar25 = 0x10;
        }
      }
      if ((cVar23 & 0x100) != 0) {
        uVar25 = uVar25 | 0x4000;
      }
      if ((cVar23 & 0x40) != 0) {
        uVar25 = uVar25 | 0x1000;
      }
      uVar28 = cVar27 & 0x8f;
      if (uVar28 == 0x83) {
        uVar25 = uVar25 | 6;
      }
      else if (((uVar28 == 0x8a) || (uVar28 == 0x8e)) &&
              (bVar7 = type_member_pointer_is_aggregate(pcVar9), bVar7 != 0)) {
        uVar25 = uVar25 | 6;
      }
      else {
        if (uVar28 == 0x8a) goto switchD_1040bf4e_caseD_11;
        if ((((uVar28 == 0x8e) || (uVar28 == 0x82)) || (uVar28 == 0x86)) || (uVar28 == 0x80)) {
          uVar25 = uVar25 | 3;
        }
        else {
          uVar28 = pcVar9->code;
          if (((uVar28 & 0x2000) == 0) &&
             ((((uVar28 & 0xfff) != 0x11 || ((uVar28 & 0x1000) != 0)) ||
              (g_opt_J_unsigned_char == '\0')))) {
            uVar12 = base_code & 0xffff;
            if (uVar12 < 0x104) {
              if (uVar12 == 0x103) {
switchD_1040bf4e_caseD_11:
                uVar25 = uVar25 | 1;
              }
              else {
                switch(uVar12) {
                case 0x10:
                  goto switchD_1040bf4e_caseD_10;
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                  goto switchD_1040bf4e_caseD_11;
                default:
                  goto switchD_1040bf4e_caseD_15;
                case 0x26:
                case 0x27:
                case 0x28:
                  uVar25 = uVar25 | 5;
                  break;
                case 0x40:
                  uVar25 = uVar25 | 7;
                }
              }
            }
            else {
              if (uVar12 < 0x403) {
                if (uVar12 == 0x402) goto switchD_1040bf4e_caseD_10;
                if ((0x200 < uVar12) && (uVar12 < 0x204)) {
                  uVar25 = uVar25 | 6;
                  goto LAB_1040c011;
                }
              }
              else if (uVar12 == 0x1011) goto switchD_1040bf4e_caseD_11;
switchD_1040bf4e_caseD_15:
              if ((0x18 < uVar12) && (uVar12 < 0x1e)) {
                uVar25 = uVar25 | 1;
              }
            }
          }
          else {
switchD_1040bf4e_caseD_10:
            uVar25 = uVar25 | 2;
          }
        }
      }
LAB_1040c011:
      if (0x7f < uVar25) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = (byte)(uVar25 >> 8) | 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = (c1_u8)uVar25;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x0e':
      cVar26 = sym->key_ref;
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(byte)cVar26 & 3);
      }
      break;
    case '\x0f':
      pfVar3 = (sym->detail).segment_class;
      if ((pfVar3 != (fe_name *)0x0) && (pfVar3 != g_name_unnamed)) {
        pcVar19 = (c1_u8 *)pfVar3->text;
        goto LAB_1040c8c8;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x10':
      if (((sym->flags22 & 4) == 0) || (kind == 7)) {
        if (((sym->flags22 & 8) == 0) || (kind == 7)) {
          if ((sym->storage & 0x40) == 0) {
            bVar7 = sym->storage & 7;
            if (((bVar7 < 4) || (6 < bVar7)) && ((bVar7 != 3 || ((sym->flags1 & 4) != 0)))) {
              if (((sym->flags4 & 4) == 0) && ((sym->flags2 & 4) == 0)) {
                if (bVar7 == 1) {
                  bVar7 = 2;
                }
                else if ((uVar32 == 0) || ((pcVar18->extra).cls != (c1_symbol *)0x0)) {
                  bVar7 = 3;
                }
                else {
                  bVar7 = 2;
                }
              }
              else {
                bVar7 = 1;
              }
            }
            else {
              bVar7 = 4;
            }
          }
          else {
            bVar7 = (~sym->flags4 & 4 | 2) >> 1;
          }
        }
        else {
          bVar7 = 8;
        }
      }
      else {
        bVar7 = (-((sym->flags2 & 4) != 0) & 5U) + 2;
      }
      goto LAB_1040bb79;
    case '\x11':
      bVar7 = sym->kind & 0x1f;
      if (((bVar7 != 7) && (bVar7 != 8)) && (bVar7 != 6)) {
        il_emit_symbol_record_body
                  (sym,buf,fdef_mode,part_scratch,is_inline,pcVar30,pcVar18,fn_type,pair_sym,tmpl,
                   base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,iter_sym,
                   ref_cell,ref_list,kind,sym);
        return;
      }
      if ((sym->flags2 & 4) == 0) {
        bVar7 = sym->storage & 7;
        if ((bVar7 == 3) && ((sym->flags1 & 4) == 0)) {
          il_emit_symbol_function_storage_fragment
                    ('\x03',sym,buf,fdef_mode,part_scratch,is_inline,pcVar30,pcVar18,fn_type,
                     pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,
                     out_cell,iter_sym,ref_cell,ref_list,kind,sym);
          return;
        }
        if (((sym->flags21 & 1) != 0) && (bVar7 != 1)) {
          diag_warning(1,0x1fa,sym);
        }
        cVar24 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
      }
      else if ((sym->flags22 & 4) == 0) {
        if ((sym->flags22 & 8) == 0) {
          if ((((sym->storage & 0x40) == 0) && ((sym->storage & 7) == 3)) &&
             ((sym->flags1 & 4) == 0)) {
            cVar24 = '\x03';
          }
          else {
            cVar24 = '\x05';
          }
        }
        else {
          cVar24 = '\n';
        }
      }
      else {
        cVar24 = '\t';
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = cVar24;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x13':
      if ((sym->flags5 & 0x10) == 0) {
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else {
        pair_sym = sym_lookup_pair_local_then_global(sym,(uint *)&out_cell);
        uVar12 = out_cell[9];
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          if ((uVar12 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar12;
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = 0x80;
LAB_1040c3e5:
            puVar20 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar20;
            *puVar20 = uVar12;
            (buf->bytes).cur = (buf->bytes).cur + 4;
          }
        }
      }
      break;
    case '\x14':
      cVar4 = (sym->x28).bytes;
      if (((int)cVar4 < 0x8000) && (-0x8001 < (int)cVar4)) {
        bVar7 = 1;
      }
      else {
        bVar7 = 0;
      }
      sVar29 = (-(ushort)bVar7 & 0xfffe) + 4;
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,(int)sVar29), (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        psVar21 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar21;
        *psVar21 = sVar29;
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = cVar4.bit_position;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = cVar4.depth;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      if ((0x7fff < (int)cVar4) || ((int)cVar4 < -0x8000)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = (c1_u8)cVar4.unk2a;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = cVar4.unk2a._1_1_;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      break;
    case '\x15':
      if (((sym->flags4 & 0x40) == 0) || ((sym->kind & 0x1f) != 10)) {
        if (((pair_sym->flags4 & 0x40) == 0) || ((pair_sym->kind & 0x1f) != 10)) {
          if (g_c9il_mode == '\0') {
            uVar12 = pair_sym->key_ref;
            if ((uVar12 & 0xfffffff8) != 0) goto LAB_1047c99a;
            uVar12 = il_symbol_key_assign(pair_sym);
            goto LAB_1047c951;
          }
          cVar26 = pair_sym->entity;
          goto LAB_1047c967;
        }
        pcVar8 = sym_inline_instance_of(pair_sym);
        if (g_c9il_mode != '\0') {
          uVar12 = pcVar8->entity & 0xffffff;
LAB_1047c879:
          if (g_c9il_mode == '\0') goto LAB_1047c88b;
          goto LAB_1040c5f6;
        }
        if ((pcVar8->key_ref & 0xfffffff8) == 0) {
          uVar12 = il_symbol_key_assign(pcVar8);
          goto LAB_1047c879;
        }
        uVar12 = pcVar8->key_ref >> 3;
LAB_1047c88b:
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 == 0) break;
        if (0x3fff7f < uVar12) {
          *(buf->bytes).cur = (char)uVar12 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          break;
        }
LAB_1047c8cb:
        if (uVar12 < 0x4000) {
          *(buf->bytes).cur = (byte)uVar12 & 0x3f | 0x80;
          goto LAB_1047c8de;
        }
        *(buf->bytes).cur = (byte)uVar12 | 0xc0;
        pcVar19 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar19;
        *pcVar19 = (c1_u8)(uVar12 >> 6);
LAB_1047c912:
        pcVar19 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar19;
        *pcVar19 = (c1_u8)(uVar12 >> 0xe);
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      else {
        pcVar8 = sym_inline_instance_of(sym);
        if (g_c9il_mode == '\0') {
          if ((pcVar8->key_ref & 0xfffffff8) == 0) {
            uVar12 = il_symbol_key_assign(pcVar8);
            goto LAB_1040c31c;
          }
          uVar12 = pcVar8->key_ref >> 3;
LAB_1047c7e1:
          iVar14 = il_buffer_reserve(&buf->bytes,4);
          bVar7 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar7;
          if (bVar7 == 0) break;
          if (0x3fff7f < uVar12) {
            *(buf->bytes).cur = (char)uVar12 + 0x80;
            (buf->bytes).cur = (buf->bytes).cur + 1;
            break;
          }
          if (0x3fff < uVar12) goto LAB_1047cb46;
LAB_1047c822:
          *(buf->bytes).cur = (byte)uVar12 & 0x3f | 0x80;
LAB_1047c8de:
          pcVar19 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar19;
          *pcVar19 = (c1_u8)(uVar12 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        else {
          uVar12 = pcVar8->entity & 0xffffff;
LAB_1040c31c:
          if (g_c9il_mode == '\0') goto LAB_1047c7e1;
LAB_1040c5f6:
          il_buffer_put_id(buf,uVar12);
        }
      }
      break;
    case '\x16':
      pcVar8 = sym_segment_record(sym);
      if (g_c9il_mode == '\0') {
        uVar12 = pcVar8->key_ref;
        if ((uVar12 & 0xfffffff8) == 0) {
          uVar12 = il_symbol_key_assign(pcVar8);
          goto LAB_1047c951;
        }
LAB_1047c99a:
        uVar12 = uVar12 >> 3;
      }
      else {
        cVar26 = pcVar8->entity;
LAB_1047c967:
        uVar12 = cVar26 & 0xffffff;
LAB_1047c951:
        if (g_c9il_mode != '\0') goto LAB_1040c5f6;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        if (uVar12 < 0x3fff80) goto LAB_1047c8cb;
        *(buf->bytes).cur = (char)uVar12 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x17':
      bVar7 = (sym->x28).bytes.bit_position;
      if ((bVar7 != 0) && (bVar7 != 2)) {
        bVar7 = (-(bVar7 != 3) & 0xfeU) + 3;
      }
LAB_1040bb79:
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(buf->bytes).cur = bVar7;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x18':
      uVar12 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
      part_scratch = uVar22;
      if (g_c9il_mode != '\0') {
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          if ((uVar22 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar22;
            pcVar19 = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = 0x80;
            puVar20 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar20;
            *puVar20 = uVar22;
            pcVar19 = (buf->bytes).cur + 4;
          }
          (buf->bytes).cur = pcVar19;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          if ((uVar12 & 0xffffff80) != 0) {
            *(buf->bytes).cur = 0x80;
            goto LAB_1040c3e5;
          }
          *(buf->bytes).cur = (c1_u8)uVar12;
          (buf->bytes).cur = (buf->bytes).cur + 1;
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
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        iVar14 = il_buffer_put_byte7(buf,(int)(short)rec_word1);
        if ((char)iVar14 == '\0') {
          *(buf->bytes).cur = 0x80;
          psVar21 = (short *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)psVar21;
          *psVar21 = (short)rec_word1;
          (buf->bytes).cur = (buf->bytes).cur + 2;
        }
      }
      break;
    case '\x1a':
      if (fdef_mode == '\0') {
        is_inline = sym->flags21 & 1;
        if ((is_inline == 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
          sVar29 = 0;
        }
        else {
          sVar29 = 0x80;
        }
        if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
          sVar17 = 0;
        }
        else {
          sVar17 = 0x1000;
        }
        rec_word2 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 |
                                 (ushort)(*(byte *)((int)&sym->tail + 10) & 0xe)) << 7) |
                    (sym->flags5 & 0x80) >> 5 |
                    (int)(short)(-(ushort)(g_function_compile_it != '\0') & 0x20) |
                    (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                    (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar17 | (int)sVar29;
        if (g_inline_level == 1) {
LAB_1040c538:
          if (g_function_not_inlinable == 0) {
LAB_1040c541:
            if ((sym->type->flags & 0x8000) == 0) {
              if (is_inline != 0) {
                rec_word2 = rec_word2 | 0x40;
              }
              goto LAB_1040c55b;
            }
          }
LAB_1040c5a9:
          rec_word2 = (int)(short)rec_word2 & 0xffffffbf;
          if (is_inline != 0) {
            diag_warning(4,0x2c6,sym);
          }
        }
        else if (g_inline_level == 2) {
          if (g_function_auto_inline == 0) goto LAB_1040c538;
          if (g_function_not_inlinable == 0) {
            if (((((sym->storage & 7) == 3) && ((sym->flags1 & 4) == 0)) &&
                (((byte)sym->key_ref & 3) == 1)) ||
               (g_function_tuple_count < g_autoinline_tuple_limit)) {
              rec_word2 = rec_word2 | 0x40;
            }
            goto LAB_1040c541;
          }
          goto LAB_1040c5a9;
        }
LAB_1040c55b:
        iVar14 = il_buffer_reserve(&buf->bytes,5);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          if (rec_word2 < 0x8000) {
            *(short *)(buf->bytes).cur = (short)rec_word2;
            (buf->bytes).cur = (buf->bytes).cur + 2;
          }
          else {
            *(uint *)(buf->bytes).cur = rec_word2 | 0x8000;
            (buf->bytes).cur = (buf->bytes).cur + 4;
          }
        }
      }
      else {
        iVar14 = il_buffer_reserve(&buf->bytes,5);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          if ((int)rec_word2 < 0x8000) {
            *(undefined2 *)(buf->bytes).cur = (undefined2)rec_word2;
            (buf->bytes).cur = (buf->bytes).cur + 2;
          }
          else {
            *(uint *)(buf->bytes).cur =
                 (uint)((uint3)(rec_word2 >> 8) & 0xffffc0 | 0x40) << 9 | rec_word2 & 0x7fff;
            (buf->bytes).cur = (buf->bytes).cur + 4;
          }
        }
      }
      break;
    case '\x1c':
      pcVar8 = class_scalar_deleting_dtor_of(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar8->key_ref & 0xfffffff8) == 0) {
          uVar12 = il_symbol_key_assign(pcVar8);
          goto LAB_1040c5e9;
        }
        uVar12 = pcVar8->key_ref >> 3;
      }
      else {
        uVar12 = pcVar8->entity & 0xffffff;
LAB_1040c5e9:
        if (g_c9il_mode != '\0') goto LAB_1040c5f6;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        if (uVar12 < 0x3fff80) {
          if (uVar12 < 0x4000) goto LAB_1047c822;
LAB_1047cb46:
          *(buf->bytes).cur = (byte)uVar12 | 0xc0;
          pcVar19 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar19;
          *pcVar19 = (c1_u8)(uVar12 >> 6);
          goto LAB_1047c912;
        }
        *(buf->bytes).cur = (char)uVar12 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x1d':
      part_scratch = 0x386;
      iVar14 = il_buffer_reserve(&buf->bytes,3);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        pcVar19 = (buf->bytes).cur;
        pcVar19[0] = 0x86;
        pcVar19[1] = '\x03';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      break;
    case '\x1e':
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        pcVar19 = (buf->bytes).cur;
        pcVar19[0] = 0x96;
        pcVar19[1] = 0xba;
        pcVar19[2] = '0';
        pcVar19[3] = '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      break;
    case ' ':
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(buf->bytes).cur = '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '!':
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        if ((uVar12 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar12;
          pcVar19 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          puVar20 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar20;
          *puVar20 = uVar12;
          pcVar19 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar19;
      }
      pcVar19 = (c1_u8 *)g_il_pch_name;
      if (g_il_pch_name == (char *)0x0) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = '\0';
          pcVar19 = (buf->bytes).cur + 1;
          goto LAB_1040c758;
        }
      }
      else {
        uVar12 = 0xffffffff;
        pcVar13 = g_il_pch_name;
        do {
          if (uVar12 == 0) break;
          uVar12 = uVar12 - 1;
          cVar2 = *pcVar13;
          pcVar13 = pcVar13 + 1;
        } while (cVar2 != '\0');
        uVar12 = ~uVar12;
        iVar14 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          pcVar15 = (buf->bytes).cur;
          for (uVar22 = uVar12 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar19;
            pcVar19 = pcVar19 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar22 = uVar12 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
            *pcVar15 = *pcVar19;
            pcVar19 = pcVar19 + 1;
            pcVar15 = pcVar15 + 1;
          }
          pcVar19 = (buf->bytes).cur + uVar12;
LAB_1040c758:
          (buf->bytes).cur = pcVar19;
        }
      }
      if (g_pragma_comment_list == (c1_pragma_comment *)0x0) {
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else {
        uVar12 = 0;
        comment_rev = (c1_pragma_comment *)0x0;
        comment_cell_2 = g_pragma_comment_list;
        while (g_pragma_comment_list = comment_rev, comment_cell_2 != (c1_pragma_comment *)0x0) {
          comment_next = comment_cell_2->next;
          comment_cell_2->next = g_pragma_comment_list;
          uVar12 = uVar12 + 1;
          comment_rev = comment_cell_2;
          comment_cell_2 = comment_next;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        pcVar6 = g_pragma_comment_list;
        if (bVar7 != 0) {
          if ((uVar12 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar12;
            pcVar19 = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = 0x80;
            puVar20 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar20;
            *puVar20 = uVar12;
            pcVar19 = (buf->bytes).cur + 4;
          }
          (buf->bytes).cur = pcVar19;
          pcVar6 = g_pragma_comment_list;
        }
        for (; part_scratch = (uint)pcVar6, pcVar6 != (c1_pragma_comment *)0x0;
            pcVar6 = pcVar6->next) {
          pcVar19 = (c1_u8 *)pcVar6->text;
          iVar14 = pcVar6->kind;
          iVar11 = il_buffer_reserve(&buf->bytes,2);
          bVar7 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar7;
          if (bVar7 != 0) {
            *(buf->bytes).cur = (c1_u8)iVar14;
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          if (pcVar6->kind == 7) {
            if ((c1_u8)(*pcVar19 + '\x01') != '\0') {
              part_scratch = (uint)(char)(*pcVar19 + '\x01');
              do {
                cVar24 = *pcVar19;
                iVar14 = il_buffer_reserve(&buf->bytes,2);
                bVar7 = buf->open & (byte)iVar14 & 1;
                buf->open = bVar7;
                if (bVar7 != 0) {
                  *(buf->bytes).cur = cVar24;
                  (buf->bytes).cur = (buf->bytes).cur + 1;
                }
                pcVar19 = pcVar19 + 1;
                part_scratch = part_scratch - 1;
              } while (part_scratch != 0);
            }
          }
          else {
            uVar12 = 0xffffffff;
            pcVar15 = pcVar19;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar24 = *pcVar15;
              pcVar15 = pcVar15 + 1;
            } while (cVar24 != '\0');
            uVar12 = ~uVar12;
            iVar14 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
            bVar7 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar7;
            if (bVar7 != 0) {
              pcVar15 = (buf->bytes).cur;
              for (uVar22 = uVar12 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
                *(undefined4 *)pcVar15 = *(undefined4 *)pcVar19;
                pcVar19 = pcVar19 + 4;
                pcVar15 = pcVar15 + 4;
              }
              for (uVar22 = uVar12 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
                *pcVar15 = *pcVar19;
                pcVar19 = pcVar19 + 1;
                pcVar15 = pcVar15 + 1;
              }
              ppcVar1 = &(buf->bytes).cur;
              *ppcVar1 = *ppcVar1 + uVar12;
            }
          }
        }
      }
      break;
    case '\"':
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar10 = &g_line_map_cached_row;
      }
      else {
        pcVar10 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      file = pcVar10->file;
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar12 = g_next_entity_id ^ file->entity;
      g_next_entity_id = g_next_entity_id + 1;
      file->entity = uVar12 & 0xffffff ^ file->entity;
      uVar12 = il_symbol_key_2(file);
      if (g_c9il_mode == '\0') {
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if (bVar7 != 0) {
          bVar7 = (byte)uVar12;
          if (uVar12 < 0x3fff80) {
            if (uVar12 < 0x4000) {
              *(buf->bytes).cur = bVar7 & 0x3f | 0x80;
              pcVar19 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar19;
              *pcVar19 = (c1_u8)(uVar12 >> 6);
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
            else {
              *(buf->bytes).cur = bVar7 | 0xc0;
              pcVar19 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar19;
              *pcVar19 = (c1_u8)(uVar12 >> 6);
              pcVar19 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar19;
              *pcVar19 = (c1_u8)(uVar12 >> 0xe);
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
          }
          else {
            *(buf->bytes).cur = bVar7 + 0x80;
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
      }
      else {
        il_buffer_put_id(buf,uVar12);
      }
      pcVar19 = (c1_u8 *)pp_position_file_name(&g_token_position);
LAB_1040c8c8:
      uVar12 = 0xffffffff;
      pcVar15 = pcVar19;
      do {
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        cVar24 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar24 != '\0');
      uVar12 = ~uVar12;
      iVar14 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        pcVar15 = (buf->bytes).cur;
        for (uVar22 = uVar12 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar19;
          pcVar19 = pcVar19 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar22 = uVar12 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
          *pcVar15 = *pcVar19;
          pcVar19 = pcVar19 + 1;
          pcVar15 = pcVar15 + 1;
        }
        ppcVar1 = &(buf->bytes).cur;
        *ppcVar1 = *ppcVar1 + uVar12;
      }
      break;
    case '#':
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        iVar11 = il_buffer_put_byte7(buf,(int)(short)iVar14);
        if ((char)iVar11 == '\0') {
          *(buf->bytes).cur = 0x80;
          psVar21 = (short *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)psVar21;
          *psVar21 = (short)iVar14;
          (buf->bytes).cur = (buf->bytes).cur + 2;
        }
      }
      break;
    case '%':
      uVar12 = 0x400000;
      if (g_c9il_mode != '\0') {
        uVar12 = g_next_entity_id;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(uint *)(buf->bytes).cur = uVar12;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      break;
    case '&':
      uVar12 = 0xffffffff;
      pcVar15 = pcVar19;
      do {
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        cVar24 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar24 != '\0');
      uVar12 = ~uVar12;
      iVar14 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        pcVar15 = (buf->bytes).cur;
        for (uVar22 = uVar12 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar19;
          pcVar19 = pcVar19 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar22 = uVar12 & 3; uVar22 != 0; uVar22 = uVar22 - 1) {
          *pcVar15 = *pcVar19;
          pcVar19 = pcVar19 + 1;
          pcVar15 = pcVar15 + 1;
        }
        ppcVar1 = &(buf->bytes).cur;
        *ppcVar1 = *ppcVar1 + uVar12;
      }
      break;
    case '(':
      if (g_c9il_mode == '\0') {
        il_emit_symbol_function_line_fragment
                  (sym,buf,fdef_mode,part_scratch,is_inline,pcVar30,pcVar18,fn_type,pair_sym,tmpl,
                   base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,iter_sym,
                   ref_cell,ref_list,kind,sym);
        return;
      }
      break;
    case ')':
      if (g_c9il_mode == '\0') {
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar7 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar7;
        if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
          *(buf->bytes).cur = 0x80;
          pcVar19 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar19;
          pcVar19[0] = '\0';
          pcVar19[1] = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 2;
        }
      }
      break;
    case '*':
      uVar12 = 2;
      if (g_c9il_mode == '\0') {
        uVar12 = 3;
      }
      if (g_dlp != '\0') {
        uVar12 = uVar12 | 8;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if (bVar7 != 0) {
        *(uint *)(buf->bytes).cur = uVar12;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0xc), (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar19 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar19;
        pcVar19[0] = '\f';
        pcVar19[1] = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar19 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar19;
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar7 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar7;
      if ((bVar7 != 0) && (iVar14 = il_buffer_put_byte7(buf,0x1fe8), (char)iVar14 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar19 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar19;
        pcVar19[0] = 0xe8;
        pcVar19[1] = '\x1f';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      break;
    case '.':
      if (g_opt_Ct != '\0') {
        il_emit_symbol_inline_fragment
                  (sym,buf,fdef_mode,part_scratch,is_inline,pcVar30,pcVar18,fn_type,pair_sym,tmpl,
                   base_code,rec_word0,rec_word1,rec_word2,uVar32,type_flags,out_cell,iter_sym,
                   ref_cell,ref_list,kind,sym);
        return;
      }
    }
    cVar2 = *tmpl;
    uVar12 = g_cv_precomp_signature;
    pcVar19 = (c1_u8 *)g_source_file_ni;
    iVar14 = g_function_formal_count;
    uVar22 = g_function_ex_offset;
  } while( true );
}

