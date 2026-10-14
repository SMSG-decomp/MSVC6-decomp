void __cdecl
il_emit_symbol_fragment
          (c1_symbol *sym,int kind_b,int zero,uint part_scratch,byte is_inline,c1_type *sym_type,
          c1_type *derived_type,c1_type *fn_type,c1_symbol *pair_sym,uint base_code,uint rec_word0,
          uint rec_word1,uint rec_word2,int is_array,uint type_flags,uint *out_cell,
          c1_symbol *iter_sym,void **ref_cell,void **ref_list,int kind,c1_symbol *sym_arg)

{
  c1_u8 **ppcVar1;
  char cVar2;
  byte sym_flags4;
  c1_type *pcVar3;
  fe_name *pfVar4;
  c1_symbol_x28_bytes cVar5;
  fe_file_record *file;
  c1xx_idb_vtbl *pcVar6;
  void *value;
  c1_type *pcVar7;
  c1_line_map_row *pcVar8;
  int iVar9;
  c1_symbol *pcVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  c1_u8 *pcVar14;
  byte bVar15;
  byte bVar16;
  short sVar17;
  c1_u8 *pcVar18;
  uint *puVar19;
  short *psVar20;
  uint uVar21;
  ushort uVar22;
  c1_u8 cVar23;
  ushort uVar24;
  c1_u32 cVar25;
  c1_il_buffer *buf;
  ushort uVar26;
  short sVar27;
  char *tmpl;
  char fdef_mode;
  c1_pragma_comment *comment_cell;
  c1_pragma_comment *comment_rev;
  c1_pragma_comment *comment_next;
  c1_pragma_comment *comment_cell_2;
  
  if (g_il_block_level == '\0') {
    pcVar10 = sym_segment_record(sym);
    il_emit_global_symbol((int *)&pcVar10->name);
  }
  if ((kind == kind_b) && (g_opt_Zi == '\0')) {
    return;
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
             (pcVar7 = type_skip_arrays_and_functions(sym->type),
             ((byte)pcVar7->flags >> 5 & 1) != 0)))))) {
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
       ((((g_il_emit_mode == '\0' && (sym != (c1_symbol *)zero)) &&
         (sym->name->text != (char *)zero)) && (g_c9il_mode == '\0')))) {
      pcVar6 = g_idb->vtbl;
      pcVar11 = sym_format_qualified_function_name(sym,&stack0x00000068,0x400);
      iVar12 = (*pcVar6->idb_add_name)(g_idb,pcVar11);
      if (iVar12 == 0) {
        diag_fatal_simple(0x37);
      }
    }
  }
  else {
    fdef_mode = '\x01';
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar13 = il_symbol_key_assign(sym);
      }
      else {
        uVar13 = sym->key_ref >> 3;
      }
    }
    else {
      uVar13 = sym->entity & 0xffffff;
    }
    ilstore_query_record(uVar13,5,&out_cell);
    rec_word0 = *out_cell;
    rec_word1 = out_cell[1];
    rec_word2 = out_cell[2];
  }
  cVar2 = *tmpl;
  uVar13 = g_cv_precomp_signature;
  pcVar18 = (c1_u8 *)g_source_file_ni;
  iVar12 = g_function_formal_count;
  uVar21 = g_function_ex_offset;
  do {
    g_cv_precomp_signature = uVar13;
    g_source_file_ni = (int)pcVar18;
    g_function_formal_count = iVar12;
    g_function_ex_offset = uVar21;
    if (cVar2 == '\0') {
      if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
        if (buf == &g_il_gi_buffer) {
          ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
        }
        else if (buf == &g_il_gl) {
          ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
        }
        if ((fdef_mode == '\0') && (kind == 0xe)) {
          uVar13 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
          pcVar18 = g_il_gi_fdef.bytes.cur;
          pcVar14 = (c1_u8 *)(uVar13 & 0xffffff01);
          g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)pcVar14;
          if (g_il_gi_fdef.open != 0) {
            *(uint *)g_il_gi_fdef.bytes.cur = rec_word0;
            *(uint *)(pcVar18 + 4) = rec_word1;
            *(uint *)(pcVar18 + 8) = rec_word2;
            pcVar14 = g_il_gi_fdef.bytes.cur + 0xc;
            g_il_gi_fdef.bytes.cur = pcVar14;
          }
          ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                             CONCAT31((int3)((uint)pcVar14 >> 8),(sym->flags21 & 1) != 0) + 1);
        }
      }
      return;
    }
    tmpl = tmpl + 1;
    pcVar10 = sym;
    switch(cVar2) {
    case '\x01':
      bVar16 = sym->kind & 0x1f;
      if (((bVar16 == 7) || (bVar16 == 8)) || (bVar16 == 6)) {
        uVar13 = type_size(fn_type);
      }
      else {
        uVar13 = type_size(sym_type);
        if (uVar13 == 0) {
          bVar16 = sym->kind & 0x1f;
          if (bVar16 == 0xb) {
            type_check_size_known(sym_type);
          }
          else if (bVar16 == 0xc) {
            il_emit_symbol_part(sym_type,0,sym,buf,fdef_mode,part_scratch,is_inline,sym_type,
                                derived_type,fn_type,pair_sym,tmpl,base_code,rec_word0,rec_word1,
                                rec_word2,is_array,type_flags,out_cell,iter_sym,ref_cell,ref_list,
                                kind,sym_arg);
            return;
          }
        }
      }
      if ((((sym->flags4 & 4) != 0) && ((sym_type->code & 0x200) != 0)) &&
         ((((sym_type->extra).cls)->flags5 & 1) != 0)) {
        il_emit_symbol_size_fragment
                  (uVar13,sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                   pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,
                   out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if ((g_rtti != '\0') && ((sym->flags3 & 0x80) != 0)) {
        uVar13 = uVar13 + 4;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,6);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,uVar13), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        puVar19 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar19;
        *puVar19 = uVar13;
        (buf->bytes).cur = (buf->bytes).cur + 4;
        pcVar10 = sym;
      }
      break;
    case '\x02':
      if (fdef_mode == '\0') {
        bVar16 = sym->flags5;
        if (((((bVar16 & 0x80) == 0) || (bVar15 = sym->kind & 0x1f, bVar15 == 7)) || (bVar15 == 8))
           || (bVar15 == 6)) {
          rec_word0 = 0;
        }
        else {
          rec_word0 = 0x80;
        }
        bVar15 = sym->kind & 0x1f;
        if (((bVar15 == 7) || (bVar15 == 8)) || (bVar15 == 6)) {
          if ((bVar16 & 2) != 0) {
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
                      (bVar15,bVar16,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                       derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                       type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
            return;
          }
        }
        uVar13 = sym->key_ref & 3;
        if (uVar13 != 0) {
          if (((bVar15 == 10) || (bVar15 == 0xb)) && ((bVar16 & 8) != 0)) {
            rec_word0 = rec_word0 | 0x2000;
          }
          if ((((bVar15 != 7) && (bVar15 != 8)) && (bVar15 != 6)) &&
             ((sym->name != g_name_this || (uVar13 != 1)))) {
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
          if (((derived_type == (c1_type *)0x0) || ((derived_type->code & 0x83) != 0x81)) ||
             ((derived_type->flags & 0x8000) == 0)) {
            rec_word0 = rec_word0 | 0x10;
          }
          break;
        case 6:
          rec_word0 = rec_word0 | 0x14;
        }
        if (((bVar15 == 7) || (bVar15 == 8)) || (bVar15 == 6)) {
          if (((bVar16 & 0x10) != 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
            rec_word0 = rec_word0 | 0x8000;
          }
          if ((bVar16 & 1) != 0) {
            il_emit_symbol_ref_flag_1000_fragment
                      (bVar15,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                       derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                       type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
            return;
          }
        }
        bVar16 = sym->flags22;
        if ((((bVar16 & 2) != 0) && (bVar15 != 7)) && (bVar15 != 8)) {
          rec_word0 = rec_word0 | 0x1000;
        }
        if ((bVar15 == 10) && ((sym->flags21 & 0x80) != 0)) {
          il_emit_symbol_ref_flag_40_fragment
                    (bVar16,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                     derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                     type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
        if ((sym->storage & 0x40) != 0) {
          if ((kind != 0xe) && ((sym_flags4 & 4) == 0)) {
            il_emit_symbol_ref_base_type_fragment
                      (bVar16,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,derived_type,
                       fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,type_flags,
                       out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
            return;
          }
          if (((bVar16 & 8) == 0) && (rec_word0 = rec_word0 | 0x20, g_rtti != '\0')) {
            il_emit_symbol_storage_fragment
                      (rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,derived_type,fn_type,
                       pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,type_flags,out_cell,
                       iter_sym,ref_cell,ref_list,kind,sym_arg);
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
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = (c1_u8)kind;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\x04':
      if (is_array == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = sym_element_size((int)sym);
      }
      iVar12 = il_buffer_reserve(&buf->bytes,6);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,uVar13), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        puVar19 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar19;
        *puVar19 = uVar13;
        (buf->bytes).cur = (buf->bytes).cur + 4;
        pcVar10 = sym;
      }
      break;
    case '\x05':
      if (g_c9il_mode == '\0') {
        if ((sym->key_ref & 0xfffffff8) == 0) {
          uVar13 = il_symbol_key_assign(sym);
          goto LAB_1040ba62;
        }
        uVar13 = sym->key_ref >> 3;
      }
      else {
        uVar13 = sym->entity & 0xffffff;
LAB_1040ba62:
        if (g_c9il_mode != '\0') {
          il_buffer_put_id(buf,uVar13);
          break;
        }
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        bVar16 = (byte)uVar13;
        if (uVar13 < 0x3fff80) {
          if (uVar13 < 0x4000) {
            *(buf->bytes).cur = bVar16 & 0x3f | 0x80;
            pcVar18 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar18;
            *pcVar18 = (c1_u8)(uVar13 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar10 = sym;
          }
          else {
            *(buf->bytes).cur = bVar16 | 0xc0;
            pcVar18 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar18;
            *pcVar18 = (c1_u8)(uVar13 >> 6);
            pcVar18 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar18;
            *pcVar18 = (c1_u8)(uVar13 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar10 = sym;
          }
        }
        else {
          *(buf->bytes).cur = bVar16 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
        }
      }
      break;
    case '\x06':
      if (g_opt_Zi == '\0') {
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0), (char)iVar12 == '\0')) {
          *(buf->bytes).cur = 0x80;
LAB_1047c50f:
          pcVar18 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar18;
          pcVar18[0] = '\0';
          pcVar18[1] = '\0';
          pcVar18[2] = '\0';
          pcVar18[3] = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar10 = sym;
        }
      }
      else {
        bVar16 = sym->kind & 0x1f;
        if (bVar16 == 0x19) {
          iVar12 = il_buffer_reserve(&buf->bytes,6);
          bVar16 = buf->open & (byte)iVar12 & 1;
          buf->open = bVar16;
          pcVar10 = sym_arg;
          if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0), (char)iVar12 == '\0')) {
            *(buf->bytes).cur = 0x80;
            goto LAB_1047c50f;
          }
        }
        else {
          if ((((bVar16 != 0) && (bVar16 < 0xf)) && (bVar16 != 5)) &&
             (((sym->flags23 & 1) != 0 &&
              (pcVar10 = sym_segment_record(sym), pcVar10->name == g_name_drectve)))) {
            il_emit_symbol_type_fragment
                      (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                       pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,
                       out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
            return;
          }
          bVar16 = sym->kind & 0x1f;
          if (bVar16 == 4) {
            value = (void *)((sym->detail).cls)->debug_index;
LAB_1040bb45:
            if (value == (void *)0x0) goto LAB_1040bac6;
          }
          else {
            if ((sym->type->code & 0x300) != 0) {
              value = (void *)((((sym->type->extra).cls)->detail).cls)->debug_index;
              goto LAB_1040bb45;
            }
            if ((bVar16 == 8) && ((*(byte *)((int)&sym->tail + 10) & 0x10) != 0)) {
              value = symtab_15ec_lookup_by_id(sym);
              goto LAB_1040bb45;
            }
LAB_1040bac6:
            value = (void *)sym_type->debug_index;
          }
          iVar12 = il_buffer_reserve(&buf->bytes,6);
          bVar16 = buf->open & (byte)iVar12 & 1;
          buf->open = bVar16;
          pcVar10 = sym_arg;
          if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,(uint)value), (char)iVar12 == '\0')
             ) {
            *(buf->bytes).cur = 0x80;
            pcVar18 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar18;
            *(void **)pcVar18 = value;
            (buf->bytes).cur = (buf->bytes).cur + 4;
            pcVar10 = sym;
          }
        }
      }
      break;
    case '\a':
      bVar16 = g_il_block_level;
      if (kind == 3) {
        bVar16 = (sym->x28).bytes.bit_position;
      }
      goto LAB_1040bb79;
    case '\b':
      bVar16 = sym->kind & 0x1f;
      if (bVar16 == 9) {
        bVar16 = *(byte *)&sym->detail;
      }
      else if ((sym->flags4 & 8) == 0) {
        if ((bVar16 == 10) && ((sym->storage & 7) == 3)) {
          bVar16 = 0x24;
        }
        else {
          bVar16 = 0;
        }
      }
      else {
        bVar16 = -((sym->storage & 7) != 2) & 0x25;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar15;
      pcVar10 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = bVar16;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\t':
      if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) {
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
        }
      }
      else if (((g_c9il_mode == '\0') && (uVar13 = sym->key_ref >> 3, 0x14 < uVar13)) &&
              ((uVar13 < g_next_global_key &&
               ((pcVar11 = sym_namespace_member_dotted_name(sym), pcVar11 == (char *)0x0 &&
                (pcVar11 = (char *)pdb_namemap_symbol_name(sym), pcVar11 != (char *)0x0)))))) {
        il_buffer_put_string(buf,pcVar11);
      }
      else {
        pcVar11 = decorate_name(sym,(c1_symbol *)0x0);
        il_buffer_put_string(buf,pcVar11);
      }
      break;
    case '\n':
      bVar16 = sym->flags5;
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar15;
      pcVar10 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = ((bVar16 & 4) != 0) + '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\v':
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\f':
      bVar16 = sym->kind & 0x1f;
      if ((bVar16 == 0xb) || (bVar16 == 0xc)) {
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          *(buf->bytes).cur = '\x03';
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
        }
      }
      else {
        bVar16 = sym->storage & 7;
        if ((bVar16 == 0) || (3 < bVar16)) {
          iVar12 = il_buffer_reserve(&buf->bytes,2);
          bVar16 = buf->open & (byte)iVar12 & 1;
          buf->open = bVar16;
          pcVar10 = sym_arg;
          if (bVar16 != 0) {
            *(buf->bytes).cur = '\x01';
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar10 = sym;
          }
        }
        else {
          pcVar7 = sym_type;
          if ((sym_type->code & 0x8f) == 0x83) {
            pcVar7 = type_skip_arrays(sym_type->base);
          }
          if (((((((byte)pcVar7->flags >> 5 & 1) == 0) ||
                ((((sym->flags23 & 1) != 0 &&
                  (pcVar10 = sym_segment_record(sym), (pcVar10->kind & 0x1f) == 0xe)) &&
                 (pcVar10 = sym_segment_record(sym), (pcVar10->entity & 0xffffff) != 3)))) ||
               ((sym->flags3 & 0x20) != 0)) ||
              (((-1 < (char)sym_type->code && ((sym_type->code & 0x200) != 0)) &&
               ((((((sym_type->extra).cls)->detail).cls)->flags3f & 0x10) != 0)))) &&
             ((((sym->flags4 & 8) == 0 || ((sym->storage & 0x40) == 0)) ||
              ((g_string_pooling_readonly == '\0' ||
               ((((sym->flags23 & 1) != 0 &&
                 (pcVar10 = sym_segment_record(sym), (pcVar10->kind & 0x1f) == 0xe)) &&
                (pcVar10 = sym_segment_record(sym), (pcVar10->entity & 0xffffff) != 3)))))))) {
            iVar12 = il_buffer_reserve(&buf->bytes,2);
            bVar16 = buf->open & (byte)iVar12 & 1;
            buf->open = bVar16;
            pcVar10 = sym_arg;
            if (bVar16 != 0) {
              *(buf->bytes).cur = '\x02';
              (buf->bytes).cur = (buf->bytes).cur + 1;
              pcVar10 = sym;
            }
          }
          else {
            iVar12 = il_buffer_reserve(&buf->bytes,2);
            bVar16 = buf->open & (byte)iVar12 & 1;
            buf->open = bVar16;
            pcVar10 = sym_arg;
            if (bVar16 != 0) {
              *(buf->bytes).cur = '\x04';
              (buf->bytes).cur = (buf->bytes).cur + 1;
              pcVar10 = sym;
            }
          }
        }
      }
      break;
    case '\r':
      if (((kind == 4) || (kind == 0x10)) || (kind == 0xe)) {
        uVar26 = fn_type->code;
        cVar2 = (char)uVar26;
        if ((cVar2 < '\0') && (fn_type != (c1_type *)0x0)) {
          uVar22 = fn_type->flags;
        }
        else {
          uVar26 = 0;
          uVar22 = 0;
        }
        uVar24 = 0;
        pcVar7 = fn_type;
        while (cVar2 < '\0') {
          pcVar7 = pcVar7->base;
          cVar2 = (char)pcVar7->code;
        }
        uVar13 = base_code >> 0x10;
        base_code = CONCAT22((short)uVar13,pcVar7->code);
        pcVar7 = fn_type;
      }
      else {
        if (derived_type == (c1_type *)0x0) {
          uVar26 = 0;
          uVar22 = 0;
        }
        else {
          uVar26 = derived_type->code;
          uVar22 = derived_type->flags;
        }
        pcVar7 = sym_type;
        if ((base_code & 0x200) == 0) {
LAB_1040be91:
          uVar24 = 0;
        }
        else {
          if ((short)base_code != 0x203) {
            pcVar3 = sym_arg->type;
            cVar2 = (char)pcVar3->code;
            while (cVar2 < '\0') {
              pcVar3 = pcVar3->base;
              cVar2 = (char)pcVar3->code;
            }
            if ((pcVar3->code & 0x300) == 0) {
              pcVar10 = (c1_symbol *)0x0;
            }
            else {
              pcVar10 = (pcVar3->extra).cls;
            }
            if ((((pcVar10->detail).cls)->layout_flags3b & 1) == 0) goto LAB_1040be91;
          }
          uVar24 = 0x10;
        }
      }
      if ((uVar22 & 0x100) != 0) {
        uVar24 = uVar24 | 0x4000;
      }
      if ((uVar22 & 0x40) != 0) {
        uVar24 = uVar24 | 0x1000;
      }
      uVar26 = uVar26 & 0x8f;
      if (uVar26 == 0x83) {
        uVar24 = uVar24 | 6;
      }
      else if (((uVar26 == 0x8a) || (uVar26 == 0x8e)) &&
              (bVar16 = type_member_pointer_is_aggregate(pcVar7), bVar16 != 0)) {
        uVar24 = uVar24 | 6;
      }
      else {
        if (uVar26 == 0x8a) goto switchD_1040bf4e_caseD_11;
        if ((((uVar26 == 0x8e) || (uVar26 == 0x82)) || (uVar26 == 0x86)) || (uVar26 == 0x80)) {
          uVar24 = uVar24 | 3;
        }
        else {
          uVar26 = pcVar7->code;
          if (((uVar26 & 0x2000) == 0) &&
             ((((uVar26 & 0xfff) != 0x11 || ((uVar26 & 0x1000) != 0)) ||
              (g_opt_J_unsigned_char == '\0')))) {
            uVar13 = base_code & 0xffff;
            if (uVar13 < 0x104) {
              if (uVar13 == 0x103) {
switchD_1040bf4e_caseD_11:
                uVar24 = uVar24 | 1;
              }
              else {
                switch(uVar13) {
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
                  uVar24 = uVar24 | 5;
                  break;
                case 0x40:
                  uVar24 = uVar24 | 7;
                }
              }
            }
            else {
              if (uVar13 < 0x403) {
                if (uVar13 == 0x402) goto switchD_1040bf4e_caseD_10;
                if ((0x200 < uVar13) && (uVar13 < 0x204)) {
                  uVar24 = uVar24 | 6;
                  goto LAB_1040c011;
                }
              }
              else if (uVar13 == 0x1011) goto switchD_1040bf4e_caseD_11;
switchD_1040bf4e_caseD_15:
              if ((0x18 < uVar13) && (uVar13 < 0x1e)) {
                uVar24 = uVar24 | 1;
              }
            }
          }
          else {
switchD_1040bf4e_caseD_10:
            uVar24 = uVar24 | 2;
          }
        }
      }
LAB_1040c011:
      if (0x7f < uVar24) {
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          *(buf->bytes).cur = (byte)(uVar24 >> 8) | 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = (c1_u8)uVar24;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x0e':
      cVar25 = sym->key_ref;
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        il_buffer_put_compact_u16_unchecked(buf,(byte)cVar25 & 3);
        pcVar10 = sym;
      }
      break;
    case '\x0f':
      pfVar4 = (sym->detail).segment_class;
      if ((pfVar4 != (fe_name *)0x0) && (pfVar4 != g_name_unnamed)) {
        pcVar18 = (c1_u8 *)pfVar4->text;
        goto LAB_1040c8c8;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\x10':
      if (((sym->flags22 & 4) == 0) || (kind == 7)) {
        if (((sym->flags22 & 8) == 0) || (kind == 7)) {
          if ((sym->storage & 0x40) == 0) {
            bVar16 = sym->storage & 7;
            if (((bVar16 < 4) || (6 < bVar16)) && ((bVar16 != 3 || ((sym->flags1 & 4) != 0)))) {
              if (((sym->flags4 & 4) == 0) && ((sym->flags2 & 4) == 0)) {
                if (bVar16 == 1) {
                  bVar16 = 2;
                }
                else if ((is_array == 0) || ((derived_type->extra).cls != (c1_symbol *)0x0)) {
                  bVar16 = 3;
                }
                else {
                  bVar16 = 2;
                }
              }
              else {
                bVar16 = 1;
              }
            }
            else {
              bVar16 = 4;
            }
          }
          else {
            bVar16 = (~sym->flags4 & 4 | 2) >> 1;
          }
        }
        else {
          bVar16 = 8;
        }
      }
      else {
        bVar16 = (-((sym->flags2 & 4) != 0) & 5U) + 2;
      }
      goto LAB_1040bb79;
    case '\x11':
      bVar16 = sym->kind & 0x1f;
      if (((bVar16 != 7) && (bVar16 != 8)) && (bVar16 != 6)) {
        il_emit_symbol_record_body
                  (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                   tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                   iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if ((sym->flags2 & 4) == 0) {
        bVar16 = sym->storage & 7;
        if ((bVar16 == 3) && ((sym->flags1 & 4) == 0)) {
          il_emit_symbol_function_storage_fragment
                    ('\x03',sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                     pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,
                     out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
        if (((sym->flags21 & 1) != 0) && (bVar16 != 1)) {
          diag_warning(1,0x1fa,sym);
        }
        cVar23 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
      }
      else if ((sym->flags22 & 4) == 0) {
        if ((sym->flags22 & 8) == 0) {
          if ((((sym->storage & 0x40) == 0) && ((sym->storage & 7) == 3)) &&
             ((sym->flags1 & 4) == 0)) {
            cVar23 = '\x03';
          }
          else {
            cVar23 = '\x05';
          }
        }
        else {
          cVar23 = '\n';
        }
      }
      else {
        cVar23 = '\t';
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = cVar23;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\x13':
      if ((sym->flags5 & 0x10) == 0) {
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
        }
      }
      else {
        pair_sym = sym_lookup_pair_local_then_global(sym,(uint *)&out_cell);
        uVar13 = out_cell[9];
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          if ((uVar13 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar13;
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar10 = sym;
          }
          else {
            *(buf->bytes).cur = 0x80;
LAB_1040c3e5:
            puVar19 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar19;
            *puVar19 = uVar13;
            (buf->bytes).cur = (buf->bytes).cur + 4;
            pcVar10 = sym;
          }
        }
      }
      break;
    case '\x14':
      cVar5 = (sym->x28).bytes;
      if (((int)cVar5 < 0x8000) && (-0x8001 < (int)cVar5)) {
        bVar16 = 1;
      }
      else {
        bVar16 = 0;
      }
      sVar27 = (-(ushort)bVar16 & 0xfffe) + 4;
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,(int)sVar27), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        psVar20 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar20;
        *psVar20 = sVar27;
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(buf->bytes).cur = cVar5.bit_position;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(buf->bytes).cur = cVar5.depth;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      if ((0x7fff < (int)cVar5) || (pcVar10 = sym_arg, (int)cVar5 < -0x8000)) {
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          *(buf->bytes).cur = (c1_u8)cVar5.unk2a;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          *(buf->bytes).cur = cVar5.unk2a._1_1_;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
        }
      }
      break;
    case '\x15':
      if (((sym->flags4 & 0x40) == 0) || ((sym->kind & 0x1f) != 10)) {
        if (((pair_sym->flags4 & 0x40) == 0) || ((pair_sym->kind & 0x1f) != 10)) {
          if (g_c9il_mode == '\0') {
            uVar13 = pair_sym->key_ref;
            if ((uVar13 & 0xfffffff8) != 0) goto LAB_1047c99a;
            uVar13 = il_symbol_key_assign(pair_sym);
            goto LAB_1047c951;
          }
          cVar25 = pair_sym->entity;
          goto LAB_1047c967;
        }
        pcVar10 = sym_inline_instance_of(pair_sym);
        if (g_c9il_mode != '\0') {
          uVar13 = pcVar10->entity & 0xffffff;
LAB_1047c879:
          if (g_c9il_mode == '\0') goto LAB_1047c88b;
          goto LAB_1040c5f6;
        }
        if ((pcVar10->key_ref & 0xfffffff8) == 0) {
          uVar13 = il_symbol_key_assign(pcVar10);
          goto LAB_1047c879;
        }
        uVar13 = pcVar10->key_ref >> 3;
LAB_1047c88b:
        iVar12 = il_buffer_reserve(&buf->bytes,4);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 == 0) break;
        if (0x3fff7f < uVar13) {
          *(buf->bytes).cur = (char)uVar13 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          break;
        }
LAB_1047c8cb:
        if (uVar13 < 0x4000) {
          *(buf->bytes).cur = (byte)uVar13 & 0x3f | 0x80;
          goto LAB_1047c8de;
        }
        *(buf->bytes).cur = (byte)uVar13 | 0xc0;
        pcVar18 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar18;
        *pcVar18 = (c1_u8)(uVar13 >> 6);
LAB_1047c912:
        pcVar18 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar18;
        *pcVar18 = (c1_u8)(uVar13 >> 0xe);
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym_arg;
      }
      else {
        pcVar10 = sym_inline_instance_of(sym);
        if (g_c9il_mode == '\0') {
          if ((pcVar10->key_ref & 0xfffffff8) == 0) {
            uVar13 = il_symbol_key_assign(pcVar10);
            goto LAB_1040c31c;
          }
          uVar13 = pcVar10->key_ref >> 3;
LAB_1047c7e1:
          iVar12 = il_buffer_reserve(&buf->bytes,4);
          bVar16 = buf->open & (byte)iVar12 & 1;
          buf->open = bVar16;
          pcVar10 = sym_arg;
          if (bVar16 == 0) break;
          if (0x3fff7f < uVar13) {
            *(buf->bytes).cur = (char)uVar13 + 0x80;
            (buf->bytes).cur = (buf->bytes).cur + 1;
            break;
          }
          if (0x3fff < uVar13) goto LAB_1047cb46;
LAB_1047c822:
          *(buf->bytes).cur = (byte)uVar13 & 0x3f | 0x80;
LAB_1047c8de:
          pcVar18 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar18;
          *pcVar18 = (c1_u8)(uVar13 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym_arg;
        }
        else {
          uVar13 = pcVar10->entity & 0xffffff;
LAB_1040c31c:
          if (g_c9il_mode == '\0') goto LAB_1047c7e1;
LAB_1040c5f6:
          il_buffer_put_id(buf,uVar13);
          pcVar10 = sym_arg;
        }
      }
      break;
    case '\x16':
      pcVar10 = sym_segment_record(sym);
      if (g_c9il_mode == '\0') {
        uVar13 = pcVar10->key_ref;
        if ((uVar13 & 0xfffffff8) == 0) {
          uVar13 = il_symbol_key_assign(pcVar10);
          goto LAB_1047c951;
        }
LAB_1047c99a:
        uVar13 = uVar13 >> 3;
      }
      else {
        cVar25 = pcVar10->entity;
LAB_1047c967:
        uVar13 = cVar25 & 0xffffff;
LAB_1047c951:
        if (g_c9il_mode != '\0') goto LAB_1040c5f6;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        if (uVar13 < 0x3fff80) goto LAB_1047c8cb;
        *(buf->bytes).cur = (char)uVar13 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x17':
      bVar16 = (sym->x28).bytes.bit_position;
      if ((bVar16 != 0) && (bVar16 != 2)) {
        bVar16 = (-(bVar16 != 3) & 0xfeU) + 3;
      }
LAB_1040bb79:
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar15;
      pcVar10 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = bVar16;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '\x18':
      uVar13 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
      part_scratch = uVar21;
      if (g_c9il_mode != '\0') {
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          if ((uVar21 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar21;
            pcVar18 = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = 0x80;
            puVar19 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar19;
            *puVar19 = uVar21;
            pcVar18 = (buf->bytes).cur + 4;
          }
          (buf->bytes).cur = pcVar18;
        }
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          if ((uVar13 & 0xffffff80) != 0) {
            *(buf->bytes).cur = 0x80;
            goto LAB_1040c3e5;
          }
          *(buf->bytes).cur = (c1_u8)uVar13;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar10 = sym;
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
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        iVar12 = il_buffer_put_byte7(buf,(int)(short)rec_word1);
        if ((char)iVar12 == '\0') {
          *(buf->bytes).cur = 0x80;
          psVar20 = (short *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)psVar20;
          *psVar20 = (short)rec_word1;
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar10 = sym;
        }
      }
      break;
    case '\x1a':
      if (fdef_mode == '\0') {
        is_inline = sym->flags21 & 1;
        if ((is_inline == 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
          sVar27 = 0;
        }
        else {
          sVar27 = 0x80;
        }
        if ((g_opt_Ct == '\0') || (g_inline_level == 0)) {
          sVar17 = 0;
        }
        else {
          sVar17 = 0x1000;
        }
        rec_word2 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 |
                                 (ushort)(*(byte *)((int)&sym_arg->tail + 10) & 0xe)) << 7) |
                    (sym_arg->flags5 & 0x80) >> 5 |
                    (int)(short)(-(ushort)(g_function_compile_it != '\0') & 0x20) |
                    (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                    (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar17 | (int)sVar27;
        if (g_inline_level == 1) {
LAB_1040c538:
          if (g_function_not_inlinable == 0) {
LAB_1040c541:
            if ((sym_arg->type->flags & 0x8000) == 0) {
              if (is_inline != 0) {
                rec_word2 = rec_word2 | 0x40;
              }
              goto LAB_1040c55b;
            }
          }
LAB_1040c5a9:
          rec_word2 = (int)(short)rec_word2 & 0xffffffbf;
          if (is_inline != 0) {
            diag_warning(4,0x2c6,sym_arg);
          }
        }
        else if (g_inline_level == 2) {
          if (g_function_auto_inline == 0) goto LAB_1040c538;
          if (g_function_not_inlinable == 0) {
            if (((((sym_arg->storage & 7) == 3) && ((sym_arg->flags1 & 4) == 0)) &&
                (((byte)sym_arg->key_ref & 3) == 1)) ||
               (g_function_tuple_count < g_autoinline_tuple_limit)) {
              rec_word2 = rec_word2 | 0x40;
            }
            goto LAB_1040c541;
          }
          goto LAB_1040c5a9;
        }
LAB_1040c55b:
        iVar12 = il_buffer_reserve(&buf->bytes,5);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
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
        iVar12 = il_buffer_reserve(&buf->bytes,5);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          if ((int)rec_word2 < 0x8000) {
            *(undefined2 *)(buf->bytes).cur = (undefined2)rec_word2;
            (buf->bytes).cur = (buf->bytes).cur + 2;
            pcVar10 = sym;
          }
          else {
            *(uint *)(buf->bytes).cur =
                 (uint)((uint3)(rec_word2 >> 8) & 0xffffc0 | 0x40) << 9 | rec_word2 & 0x7fff;
            (buf->bytes).cur = (buf->bytes).cur + 4;
            pcVar10 = sym;
          }
        }
      }
      break;
    case '\x1c':
      pcVar10 = class_scalar_deleting_dtor_of(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar10->key_ref & 0xfffffff8) == 0) {
          uVar13 = il_symbol_key_assign(pcVar10);
          goto LAB_1040c5e9;
        }
        uVar13 = pcVar10->key_ref >> 3;
      }
      else {
        uVar13 = pcVar10->entity & 0xffffff;
LAB_1040c5e9:
        if (g_c9il_mode != '\0') goto LAB_1040c5f6;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        if (uVar13 < 0x3fff80) {
          if (uVar13 < 0x4000) goto LAB_1047c822;
LAB_1047cb46:
          *(buf->bytes).cur = (byte)uVar13 | 0xc0;
          pcVar18 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar18;
          *pcVar18 = (c1_u8)(uVar13 >> 6);
          goto LAB_1047c912;
        }
        *(buf->bytes).cur = (char)uVar13 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      break;
    case '\x1d':
      part_scratch = 0x386;
      iVar12 = il_buffer_reserve(&buf->bytes,3);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        pcVar18 = (buf->bytes).cur;
        pcVar18[0] = 0x86;
        pcVar18[1] = '\x03';
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar10 = sym;
      }
      break;
    case '\x1e':
      iVar12 = il_buffer_reserve(&buf->bytes,5);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        pcVar18 = (buf->bytes).cur;
        pcVar18[0] = 0x96;
        pcVar18[1] = 0xba;
        pcVar18[2] = '0';
        pcVar18[3] = '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 4;
        pcVar10 = sym;
      }
      break;
    case ' ':
      iVar12 = il_buffer_reserve(&buf->bytes,2);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(buf->bytes).cur = '\x01';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar10 = sym;
      }
      break;
    case '!':
      iVar12 = il_buffer_reserve(&buf->bytes,6);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        if ((uVar13 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar13;
          pcVar18 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          puVar19 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar19;
          *puVar19 = uVar13;
          pcVar18 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar18;
      }
      pcVar18 = (c1_u8 *)g_il_pch_name;
      if (g_il_pch_name == (char *)0x0) {
        iVar12 = il_buffer_reserve(&buf->bytes,2);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          *(buf->bytes).cur = '\0';
          pcVar18 = (buf->bytes).cur + 1;
          goto LAB_1040c758;
        }
      }
      else {
        uVar13 = 0xffffffff;
        pcVar11 = g_il_pch_name;
        do {
          if (uVar13 == 0) break;
          uVar13 = uVar13 - 1;
          cVar2 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar2 != '\0');
        uVar13 = ~uVar13;
        iVar12 = il_buffer_reserve(&buf->bytes,uVar13 + 1);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          pcVar14 = (buf->bytes).cur;
          for (uVar21 = uVar13 >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar18;
            pcVar18 = pcVar18 + 4;
            pcVar14 = pcVar14 + 4;
          }
          for (uVar21 = uVar13 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
            *pcVar14 = *pcVar18;
            pcVar18 = pcVar18 + 1;
            pcVar14 = pcVar14 + 1;
          }
          pcVar18 = (buf->bytes).cur + uVar13;
LAB_1040c758:
          (buf->bytes).cur = pcVar18;
        }
      }
      if (g_pragma_comment_list == (c1_pragma_comment *)0x0) {
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if (bVar16 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else {
        uVar13 = 0;
        comment_rev = (c1_pragma_comment *)0x0;
        comment_cell = g_pragma_comment_list;
        while (g_pragma_comment_list = comment_rev, comment_cell != (c1_pragma_comment *)0x0) {
          comment_next = comment_cell->next;
          comment_cell->next = g_pragma_comment_list;
          uVar13 = uVar13 + 1;
          comment_rev = comment_cell;
          comment_cell = comment_next;
        }
        iVar12 = il_buffer_reserve(&buf->bytes,6);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        comment_cell_2 = g_pragma_comment_list;
        if (bVar16 != 0) {
          if ((uVar13 & 0xffffff80) == 0) {
            *(buf->bytes).cur = (c1_u8)uVar13;
            pcVar18 = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = 0x80;
            puVar19 = (uint *)((buf->bytes).cur + 1);
            (buf->bytes).cur = (c1_u8 *)puVar19;
            *puVar19 = uVar13;
            pcVar18 = (buf->bytes).cur + 4;
          }
          (buf->bytes).cur = pcVar18;
          comment_cell_2 = g_pragma_comment_list;
        }
        for (; pcVar10 = sym_arg, part_scratch = (uint)comment_cell_2,
            comment_cell_2 != (c1_pragma_comment *)0x0; comment_cell_2 = comment_cell_2->next) {
          pcVar18 = (c1_u8 *)comment_cell_2->text;
          iVar12 = comment_cell_2->kind;
          iVar9 = il_buffer_reserve(&buf->bytes,2);
          bVar16 = buf->open & (byte)iVar9 & 1;
          buf->open = bVar16;
          if (bVar16 != 0) {
            *(buf->bytes).cur = (c1_u8)iVar12;
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          if (comment_cell_2->kind == 7) {
            if ((c1_u8)(*pcVar18 + '\x01') != '\0') {
              part_scratch = (uint)(char)(*pcVar18 + '\x01');
              do {
                cVar23 = *pcVar18;
                iVar12 = il_buffer_reserve(&buf->bytes,2);
                bVar16 = buf->open & (byte)iVar12 & 1;
                buf->open = bVar16;
                if (bVar16 != 0) {
                  *(buf->bytes).cur = cVar23;
                  (buf->bytes).cur = (buf->bytes).cur + 1;
                }
                pcVar18 = pcVar18 + 1;
                part_scratch = part_scratch - 1;
              } while (part_scratch != 0);
            }
          }
          else {
            uVar13 = 0xffffffff;
            pcVar14 = pcVar18;
            do {
              if (uVar13 == 0) break;
              uVar13 = uVar13 - 1;
              cVar23 = *pcVar14;
              pcVar14 = pcVar14 + 1;
            } while (cVar23 != '\0');
            uVar13 = ~uVar13;
            iVar12 = il_buffer_reserve(&buf->bytes,uVar13 + 1);
            bVar16 = buf->open & (byte)iVar12 & 1;
            buf->open = bVar16;
            if (bVar16 != 0) {
              pcVar14 = (buf->bytes).cur;
              for (uVar21 = uVar13 >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
                *(undefined4 *)pcVar14 = *(undefined4 *)pcVar18;
                pcVar18 = pcVar18 + 4;
                pcVar14 = pcVar14 + 4;
              }
              for (uVar21 = uVar13 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
                *pcVar14 = *pcVar18;
                pcVar18 = pcVar18 + 1;
                pcVar14 = pcVar14 + 1;
              }
              ppcVar1 = &(buf->bytes).cur;
              *ppcVar1 = *ppcVar1 + uVar13;
            }
          }
        }
      }
      break;
    case '\"':
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar8 = &g_line_map_cached_row;
      }
      else {
        pcVar8 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      file = pcVar8->file;
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar13 = g_next_entity_id ^ file->entity;
      g_next_entity_id = g_next_entity_id + 1;
      file->entity = uVar13 & 0xffffff ^ file->entity;
      uVar13 = il_symbol_key_2(file);
      if (g_c9il_mode == '\0') {
        iVar12 = il_buffer_reserve(&buf->bytes,4);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        if (bVar16 != 0) {
          bVar16 = (byte)uVar13;
          if (uVar13 < 0x3fff80) {
            if (uVar13 < 0x4000) {
              *(buf->bytes).cur = bVar16 & 0x3f | 0x80;
              pcVar18 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar18;
              *pcVar18 = (c1_u8)(uVar13 >> 6);
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
            else {
              *(buf->bytes).cur = bVar16 | 0xc0;
              pcVar18 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar18;
              *pcVar18 = (c1_u8)(uVar13 >> 6);
              pcVar18 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar18;
              *pcVar18 = (c1_u8)(uVar13 >> 0xe);
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
          }
          else {
            *(buf->bytes).cur = bVar16 + 0x80;
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
      }
      else {
        il_buffer_put_id(buf,uVar13);
      }
      pcVar18 = (c1_u8 *)pp_position_file_name(&g_token_position);
LAB_1040c8c8:
      uVar13 = 0xffffffff;
      pcVar14 = pcVar18;
      do {
        if (uVar13 == 0) break;
        uVar13 = uVar13 - 1;
        cVar23 = *pcVar14;
        pcVar14 = pcVar14 + 1;
      } while (cVar23 != '\0');
      uVar13 = ~uVar13;
      iVar12 = il_buffer_reserve(&buf->bytes,uVar13 + 1);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        pcVar14 = (buf->bytes).cur;
        for (uVar21 = uVar13 >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar18;
          pcVar18 = pcVar18 + 4;
          pcVar14 = pcVar14 + 4;
        }
        for (uVar21 = uVar13 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
          *pcVar14 = *pcVar18;
          pcVar18 = pcVar18 + 1;
          pcVar14 = pcVar14 + 1;
        }
        ppcVar1 = &(buf->bytes).cur;
        *ppcVar1 = *ppcVar1 + uVar13;
      }
      break;
    case '#':
      iVar9 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar9 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        iVar9 = il_buffer_put_byte7(buf,(int)(short)iVar12);
        if ((char)iVar9 == '\0') {
          *(buf->bytes).cur = 0x80;
          psVar20 = (short *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)psVar20;
          *psVar20 = (short)iVar12;
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar10 = sym;
        }
      }
      break;
    case '%':
      uVar13 = 0x400000;
      if (g_c9il_mode != '\0') {
        uVar13 = g_next_entity_id;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,5);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        *(uint *)(buf->bytes).cur = uVar13;
        (buf->bytes).cur = (buf->bytes).cur + 4;
        pcVar10 = sym;
      }
      break;
    case '&':
      uVar13 = 0xffffffff;
      pcVar14 = pcVar18;
      do {
        if (uVar13 == 0) break;
        uVar13 = uVar13 - 1;
        cVar23 = *pcVar14;
        pcVar14 = pcVar14 + 1;
      } while (cVar23 != '\0');
      uVar13 = ~uVar13;
      iVar12 = il_buffer_reserve(&buf->bytes,uVar13 + 1);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if (bVar16 != 0) {
        pcVar14 = (buf->bytes).cur;
        for (uVar21 = uVar13 >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar18;
          pcVar18 = pcVar18 + 4;
          pcVar14 = pcVar14 + 4;
        }
        for (uVar21 = uVar13 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
          *pcVar14 = *pcVar18;
          pcVar18 = pcVar18 + 1;
          pcVar14 = pcVar14 + 1;
        }
        ppcVar1 = &(buf->bytes).cur;
        *ppcVar1 = *ppcVar1 + uVar13;
      }
      break;
    case '(':
      if (g_c9il_mode == '\0') {
        il_emit_symbol_function_line_fragment
                  (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                   tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                   iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      break;
    case ')':
      if (g_c9il_mode == '\0') {
        iVar12 = il_buffer_reserve(&buf->bytes,4);
        bVar16 = buf->open & (byte)iVar12 & 1;
        buf->open = bVar16;
        pcVar10 = sym_arg;
        if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0), (char)iVar12 == '\0')) {
          *(buf->bytes).cur = 0x80;
          pcVar18 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar18;
          pcVar18[0] = '\0';
          pcVar18[1] = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar10 = sym;
        }
      }
      break;
    case '*':
      uVar13 = 2;
      if (g_c9il_mode == '\0') {
        uVar13 = 3;
      }
      if (g_dlp != '\0') {
        uVar13 = uVar13 | 8;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,5);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if (bVar16 != 0) {
        *(uint *)(buf->bytes).cur = uVar13;
        (buf->bytes).cur = (buf->bytes).cur + 4;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0xc), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar18 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar18;
        pcVar18[0] = '\f';
        pcVar18[1] = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar18 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar18;
        pcVar18[0] = '\0';
        pcVar18[1] = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 2;
      }
      iVar12 = il_buffer_reserve(&buf->bytes,4);
      bVar16 = buf->open & (byte)iVar12 & 1;
      buf->open = bVar16;
      pcVar10 = sym_arg;
      if ((bVar16 != 0) && (iVar12 = il_buffer_put_byte7(buf,0x1fe8), (char)iVar12 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar18 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar18;
        pcVar18[0] = 0xe8;
        pcVar18[1] = '\x1f';
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar10 = sym;
      }
      break;
    case '.':
      if (g_opt_Ct != '\0') {
        il_emit_symbol_inline_fragment
                  (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                   tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                   iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
    }
    cVar2 = *tmpl;
    sym = pcVar10;
    uVar13 = g_cv_precomp_signature;
    pcVar18 = (c1_u8 *)g_source_file_ni;
    iVar12 = g_function_formal_count;
    uVar21 = g_function_ex_offset;
  } while( true );
}

