void __cdecl
il_emit_symbol_type_fragment
          (c1_symbol *sym,c1_il_buffer *buf,char fdef_mode,uint part_scratch,byte is_inline,
          c1_type *sym_type,c1_type *derived_type,c1_type *fn_type,c1_symbol *pair_sym,char *tmpl,
          uint base_code,uint rec_word0,uint rec_word1,uint rec_word2,int is_array,uint type_flags,
          uint *out_cell,c1_symbol *iter_sym,void **ref_cell,void **ref_list,int kind,
          c1_symbol *sym_arg)

{
  c1_u8 **ppcVar1;
  char cVar2;
  byte sym_flags4;
  c1_type *pcVar3;
  fe_name *pfVar4;
  c1_symbol_x28_bytes cVar5;
  fe_file_record *file;
  void *value;
  char *pcVar6;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  c1_line_map_row *pcVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  c1_u8 *pcVar13;
  byte bVar14;
  byte bVar15;
  short sVar16;
  c1_u8 *pcVar17;
  uint *puVar18;
  short *psVar19;
  uint uVar20;
  ushort uVar21;
  int *piVar22;
  c1_u8 cVar23;
  ushort uVar24;
  c1_u32 cVar25;
  ushort uVar26;
  short sVar27;
  c1_pragma_comment *comment_cell;
  c1_pragma_comment *comment_rev;
  c1_pragma_comment *comment_next;
  c1_pragma_comment *comment_cell_2;
  
code_r0x1047c52c:
  iVar11 = il_buffer_reserve(&buf->bytes,6);
  bVar15 = buf->open & (byte)iVar11 & 1;
  buf->open = bVar15;
  pcVar8 = sym_arg;
  if (bVar15 == 0) goto switchD_1040b75e_caseD_12;
  iVar11 = il_buffer_put_byte7(buf,0);
  if ((char)iVar11 != '\0') goto switchD_1040b75e_caseD_12;
  *(buf->bytes).cur = 0x80;
LAB_1047c50f:
  pcVar17 = (buf->bytes).cur + 1;
  (buf->bytes).cur = pcVar17;
  pcVar17[0] = '\0';
  pcVar17[1] = '\0';
  pcVar17[2] = '\0';
  pcVar17[3] = '\0';
  (buf->bytes).cur = (buf->bytes).cur + 4;
  pcVar8 = sym;
switchD_1040b75e_caseD_12:
  sym = pcVar8;
  iVar10 = g_function_ex_offset;
  iVar11 = g_function_formal_count;
  pcVar17 = (c1_u8 *)g_source_file_ni;
  uVar12 = g_cv_precomp_signature;
  cVar2 = *tmpl;
  if (cVar2 == '\0') {
    if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (kind == 0xe)) {
        uVar12 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        pcVar17 = g_il_gi_fdef.bytes.cur;
        pcVar13 = (c1_u8 *)(uVar12 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)pcVar13;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.cur = rec_word0;
          *(uint *)(pcVar17 + 4) = rec_word1;
          *(uint *)(pcVar17 + 8) = rec_word2;
          pcVar13 = g_il_gi_fdef.bytes.cur + 0xc;
          g_il_gi_fdef.bytes.cur = pcVar13;
        }
        ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                           CONCAT31((int3)((uint)pcVar13 >> 8),(sym->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  tmpl = tmpl + 1;
  pcVar8 = sym;
  switch(cVar2) {
  case '\x01':
    bVar15 = sym->kind & 0x1f;
    if (((bVar15 == 7) || (bVar15 == 8)) || (bVar15 == 6)) {
      uVar12 = type_size(fn_type);
    }
    else {
      uVar12 = type_size(sym_type);
      if (uVar12 == 0) {
        bVar15 = sym->kind & 0x1f;
        if (bVar15 == 0xb) {
          type_check_size_known(sym_type);
        }
        else if (bVar15 == 0xc) {
          il_emit_symbol_part(sym_type,0,sym,buf,fdef_mode,part_scratch,is_inline,sym_type,
                              derived_type,fn_type,pair_sym,tmpl,base_code,rec_word0,rec_word1,
                              rec_word2,is_array,type_flags,out_cell,iter_sym,ref_cell,ref_list,kind
                              ,sym_arg);
          return;
        }
      }
    }
    if ((((sym->flags4 & 4) != 0) && ((sym_type->code & 0x200) != 0)) &&
       ((((sym_type->extra).cls)->flags5 & 1) != 0)) {
      il_emit_symbol_size_fragment
                (uVar12,sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                 pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                 iter_sym,ref_cell,ref_list,kind,sym_arg);
      return;
    }
    if ((g_rtti != '\0') && ((sym->flags3 & 0x80) != 0)) {
      uVar12 = uVar12 + 4;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,uVar12), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      puVar18 = (uint *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)puVar18;
      *puVar18 = uVar12;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar15 = sym->flags5;
      if (((((bVar15 & 0x80) == 0) || (bVar14 = sym->kind & 0x1f, bVar14 == 7)) || (bVar14 == 8)) ||
         (bVar14 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar14 = sym->kind & 0x1f;
      if (((bVar14 == 7) || (bVar14 == 8)) || (bVar14 == 6)) {
        if ((bVar15 & 2) != 0) {
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
                    (bVar14,bVar15,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                     derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                     type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
      }
      uVar12 = sym->key_ref & 3;
      if (uVar12 != 0) {
        if (((bVar14 == 10) || (bVar14 == 0xb)) && ((bVar15 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if ((((bVar14 != 7) && (bVar14 != 8)) && (bVar14 != 6)) &&
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
        if (((derived_type == (c1_type *)0x0) || ((derived_type->code & 0x83) != 0x81)) ||
           ((derived_type->flags & 0x8000) == 0)) {
          rec_word0 = rec_word0 | 0x10;
        }
        break;
      case 6:
        rec_word0 = rec_word0 | 0x14;
      }
      if (((bVar14 == 7) || (bVar14 == 8)) || (bVar14 == 6)) {
        if (((bVar15 & 0x10) != 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((bVar15 & 1) != 0) {
          il_emit_symbol_ref_flag_1000_fragment
                    (bVar14,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                     derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                     type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
      }
      bVar15 = sym->flags22;
      if ((((bVar15 & 2) != 0) && (bVar14 != 7)) && (bVar14 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar14 == 10) && ((sym->flags21 & 0x80) != 0)) {
        il_emit_symbol_ref_flag_40_fragment
                  (bVar15,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                   derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                   type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if ((sym->storage & 0x40) != 0) {
        if ((kind != 0xe) && ((sym_flags4 & 4) == 0)) {
          il_emit_symbol_ref_base_type_fragment
                    (bVar15,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,derived_type,
                     fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,type_flags,
                     out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
        if (((bVar15 & 8) == 0) && (rec_word0 = rec_word0 | 0x20, g_rtti != '\0')) {
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
    goto switchD_1040b75e_caseD_12;
  case '\x03':
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = (c1_u8)kind;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x04':
    if (is_array == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = sym_element_size((int)sym);
    }
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,uVar12), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      puVar18 = (uint *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)puVar18;
      *puVar18 = uVar12;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
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
        goto switchD_1040b75e_caseD_12;
      }
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      bVar15 = (byte)uVar12;
      if (uVar12 < 0x3fff80) {
        if (uVar12 < 0x4000) {
          *(buf->bytes).cur = bVar15 & 0x3f | 0x80;
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym;
        }
        else {
          *(buf->bytes).cur = bVar15 | 0xc0;
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 6);
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 0xe);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym;
        }
      }
      else {
        *(buf->bytes).cur = bVar15 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') goto code_r0x1047c52c;
    bVar15 = sym->kind & 0x1f;
    if (bVar15 == 0x19) goto LAB_1047c4df;
    if ((((bVar15 != 0) && (bVar15 < 0xf)) && (bVar15 != 5)) &&
       (((sym->flags23 & 1) != 0 &&
        (pcVar8 = sym_segment_record(sym), pcVar8->name == g_name_drectve)))) {
      il_emit_symbol_type_fragment
                (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                 tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,iter_sym,
                 ref_cell,ref_list,kind,sym_arg);
      return;
    }
    bVar15 = sym->kind & 0x1f;
    if (bVar15 == 4) {
      value = (void *)((sym->detail).cls)->debug_index;
LAB_1040bb45:
      if (value == (void *)0x0) goto LAB_1040bac6;
    }
    else {
      if ((sym->type->code & 0x300) != 0) {
        value = (void *)((((sym->type->extra).cls)->detail).cls)->debug_index;
        goto LAB_1040bb45;
      }
      if ((bVar15 == 8) && ((*(byte *)((int)&sym->tail + 10) & 0x10) != 0)) {
        value = symtab_15ec_lookup_by_id(sym);
        goto LAB_1040bb45;
      }
LAB_1040bac6:
      value = (void *)sym_type->debug_index;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,(uint)value), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar17 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar17;
      *(void **)pcVar17 = value;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\a':
    bVar15 = g_il_block_level;
    if (kind == 3) {
      bVar15 = (sym->x28).bytes.bit_position;
    }
    break;
  case '\b':
    bVar15 = sym->kind & 0x1f;
    if (bVar15 == 9) {
      bVar15 = *(byte *)&sym->detail;
    }
    else if ((sym->flags4 & 8) == 0) {
      if ((bVar15 == 10) && ((sym->storage & 7) == 3)) {
        bVar15 = 0x24;
      }
      else {
        bVar15 = 0;
      }
    }
    else {
      bVar15 = -((sym->storage & 7) != 2) & 0x25;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar14 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar14;
    pcVar8 = sym_arg;
    if (bVar14 != 0) {
      *(buf->bytes).cur = bVar15;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\t':
    if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    else if (((g_c9il_mode == '\0') && (uVar12 = sym->key_ref >> 3, 0x14 < uVar12)) &&
            ((uVar12 < g_next_global_key &&
             ((pcVar6 = sym_namespace_member_dotted_name(sym), pcVar6 == (char *)0x0 &&
              (pcVar6 = (char *)pdb_namemap_symbol_name(sym), pcVar6 != (char *)0x0)))))) {
      il_buffer_put_string(buf,pcVar6);
    }
    else {
      pcVar6 = decorate_name(sym,(c1_symbol *)0x0);
      il_buffer_put_string(buf,pcVar6);
    }
    goto switchD_1040b75e_caseD_12;
  case '\n':
    bVar15 = sym->flags5;
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar14 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar14;
    pcVar8 = sym_arg;
    if (bVar14 != 0) {
      *(buf->bytes).cur = ((bVar15 & 4) != 0) + '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\v':
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\f':
    bVar15 = sym->kind & 0x1f;
    if ((bVar15 == 0xb) || (bVar15 == 0xc)) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = '\x03';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    else {
      bVar15 = sym->storage & 7;
      if ((bVar15 == 0) || (3 < bVar15)) {
        iVar11 = il_buffer_reserve(&buf->bytes,2);
        bVar15 = buf->open & (byte)iVar11 & 1;
        buf->open = bVar15;
        pcVar8 = sym_arg;
        if (bVar15 != 0) {
          *(buf->bytes).cur = '\x01';
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym;
        }
      }
      else {
        pcVar7 = sym_type;
        if ((sym_type->code & 0x8f) == 0x83) {
          pcVar7 = type_skip_arrays(sym_type->base);
        }
        if (((((((byte)pcVar7->flags >> 5 & 1) == 0) ||
              ((((sym->flags23 & 1) != 0 &&
                (pcVar8 = sym_segment_record(sym), (pcVar8->kind & 0x1f) == 0xe)) &&
               (pcVar8 = sym_segment_record(sym), (pcVar8->entity & 0xffffff) != 3)))) ||
             ((sym->flags3 & 0x20) != 0)) ||
            (((-1 < (char)sym_type->code && ((sym_type->code & 0x200) != 0)) &&
             ((((((sym_type->extra).cls)->detail).cls)->flags3f & 0x10) != 0)))) &&
           ((((sym->flags4 & 8) == 0 || ((sym->storage & 0x40) == 0)) ||
            ((g_string_pooling_readonly == '\0' ||
             ((((sym->flags23 & 1) != 0 &&
               (pcVar8 = sym_segment_record(sym), (pcVar8->kind & 0x1f) == 0xe)) &&
              (pcVar8 = sym_segment_record(sym), (pcVar8->entity & 0xffffff) != 3)))))))) {
          iVar11 = il_buffer_reserve(&buf->bytes,2);
          bVar15 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar15;
          pcVar8 = sym_arg;
          if (bVar15 != 0) {
            *(buf->bytes).cur = '\x02';
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar8 = sym;
          }
        }
        else {
          iVar11 = il_buffer_reserve(&buf->bytes,2);
          bVar15 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar15;
          pcVar8 = sym_arg;
          if (bVar15 != 0) {
            *(buf->bytes).cur = '\x04';
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar8 = sym;
          }
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\r':
    if (((kind == 4) || (kind == 0x10)) || (kind == 0xe)) {
      uVar26 = fn_type->code;
      cVar2 = (char)uVar26;
      if ((cVar2 < '\0') && (fn_type != (c1_type *)0x0)) {
        uVar21 = fn_type->flags;
      }
      else {
        uVar26 = 0;
        uVar21 = 0;
      }
      uVar24 = 0;
      pcVar7 = fn_type;
      while (cVar2 < '\0') {
        pcVar7 = pcVar7->base;
        cVar2 = (char)pcVar7->code;
      }
      base_code = CONCAT22(base_code._2_2_,pcVar7->code);
      pcVar7 = fn_type;
    }
    else {
      if (derived_type == (c1_type *)0x0) {
        uVar26 = 0;
        uVar21 = 0;
      }
      else {
        uVar26 = derived_type->code;
        uVar21 = derived_type->flags;
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
            pcVar8 = (c1_symbol *)0x0;
          }
          else {
            pcVar8 = (pcVar3->extra).cls;
          }
          if ((((pcVar8->detail).cls)->layout_flags3b & 1) == 0) goto LAB_1040be91;
        }
        uVar24 = 0x10;
      }
    }
    if ((uVar21 & 0x100) != 0) {
      uVar24 = uVar24 | 0x4000;
    }
    if ((uVar21 & 0x40) != 0) {
      uVar24 = uVar24 | 0x1000;
    }
    uVar26 = uVar26 & 0x8f;
    if (uVar26 == 0x83) {
      uVar24 = uVar24 | 6;
    }
    else if (((uVar26 == 0x8a) || (uVar26 == 0x8e)) &&
            (bVar15 = type_member_pointer_is_aggregate(pcVar7), bVar15 != 0)) {
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
          uVar12 = base_code & 0xffff;
          if (uVar12 < 0x104) {
            if (uVar12 == 0x103) {
switchD_1040bf4e_caseD_11:
              uVar24 = uVar24 | 1;
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
                uVar24 = uVar24 | 5;
                break;
              case 0x40:
                uVar24 = uVar24 | 7;
              }
            }
          }
          else {
            if (uVar12 < 0x403) {
              if (uVar12 == 0x402) goto switchD_1040bf4e_caseD_10;
              if ((0x200 < uVar12) && (uVar12 < 0x204)) {
                uVar24 = uVar24 | 6;
                goto LAB_1040c011;
              }
            }
            else if (uVar12 == 0x1011) goto switchD_1040bf4e_caseD_11;
switchD_1040bf4e_caseD_15:
            if ((0x18 < uVar12) && (uVar12 < 0x1e)) {
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
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        *(buf->bytes).cur = (byte)(uVar24 >> 8) | 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = (c1_u8)uVar24;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x0e':
    cVar25 = sym->key_ref;
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar25 & 3);
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x0f':
    pfVar4 = (sym->detail).segment_class;
    if ((pfVar4 != (fe_name *)0x0) && (pfVar4 != g_name_unnamed)) {
      pcVar17 = (c1_u8 *)pfVar4->text;
      goto LAB_1040c8c8;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x10':
    if (((sym->flags22 & 4) == 0) || (kind == 7)) {
      if (((sym->flags22 & 8) == 0) || (kind == 7)) {
        if ((sym->storage & 0x40) == 0) {
          bVar15 = sym->storage & 7;
          if (((bVar15 < 4) || (6 < bVar15)) && ((bVar15 != 3 || ((sym->flags1 & 4) != 0)))) {
            if (((sym->flags4 & 4) == 0) && ((sym->flags2 & 4) == 0)) {
              if (bVar15 == 1) {
                bVar15 = 2;
              }
              else if ((is_array == 0) || ((derived_type->extra).cls != (c1_symbol *)0x0)) {
                bVar15 = 3;
              }
              else {
                bVar15 = 2;
              }
            }
            else {
              bVar15 = 1;
            }
          }
          else {
            bVar15 = 4;
          }
        }
        else {
          bVar15 = (~sym->flags4 & 4 | 2) >> 1;
        }
      }
      else {
        bVar15 = 8;
      }
    }
    else {
      bVar15 = (-((sym->flags2 & 4) != 0) & 5U) + 2;
    }
    break;
  case '\x11':
    bVar15 = sym->kind & 0x1f;
    if (((bVar15 != 7) && (bVar15 != 8)) && (bVar15 != 6)) {
      il_emit_symbol_record_body
                (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                 tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,iter_sym,
                 ref_cell,ref_list,kind,sym_arg);
      return;
    }
    if ((sym->flags2 & 4) == 0) {
      bVar15 = sym->storage & 7;
      if ((bVar15 == 3) && ((sym->flags1 & 4) == 0)) {
        il_emit_symbol_function_storage_fragment
                  ('\x03',sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                   pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,
                   out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if (((sym->flags21 & 1) != 0) && (bVar15 != 1)) {
        diag_warning(1,0x1fa,sym);
      }
      cVar23 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
    }
    else if ((sym->flags22 & 4) == 0) {
      if ((sym->flags22 & 8) == 0) {
        if ((((sym->storage & 0x40) == 0) && ((sym->storage & 7) == 3)) && ((sym->flags1 & 4) == 0))
        {
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
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = cVar23;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
  default:
    goto switchD_1040b75e_caseD_12;
  case '\x13':
    if ((sym->flags5 & 0x10) == 0) {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    else {
      pair_sym = sym_lookup_pair_local_then_global(sym,(uint *)&out_cell);
      uVar12 = out_cell[9];
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        if ((uVar12 & 0xffffff80) != 0) {
          *(buf->bytes).cur = 0x80;
          goto LAB_1040c3e5;
        }
        *(buf->bytes).cur = (c1_u8)uVar12;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x14':
    cVar5 = (sym->x28).bytes;
    if (((int)cVar5 < 0x8000) && (-0x8001 < (int)cVar5)) {
      bVar15 = 1;
    }
    else {
      bVar15 = 0;
    }
    sVar27 = (-(ushort)bVar15 & 0xfffe) + 4;
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,(int)sVar27), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      psVar19 = (short *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)psVar19;
      *psVar19 = sVar27;
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if (bVar15 != 0) {
      *(buf->bytes).cur = cVar5.bit_position;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if (bVar15 != 0) {
      *(buf->bytes).cur = cVar5.depth;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    if ((0x7fff < (int)cVar5) || (pcVar8 = sym_arg, (int)cVar5 < -0x8000)) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        *(buf->bytes).cur = (c1_u8)cVar5.unk2a;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = cVar5.unk2a._1_1_;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x15':
    if (((sym->flags4 & 0x40) == 0) || ((sym->kind & 0x1f) != 10)) {
      if (((pair_sym->flags4 & 0x40) == 0) || ((pair_sym->kind & 0x1f) != 10)) {
        if (g_c9il_mode == '\0') {
          uVar12 = pair_sym->key_ref;
          if ((uVar12 & 0xfffffff8) != 0) goto LAB_1047c99a;
          uVar12 = il_symbol_key_assign(pair_sym);
          goto LAB_1047c951;
        }
        cVar25 = pair_sym->entity;
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
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        if (uVar12 < 0x3fff80) goto LAB_1047c8cb;
        *(buf->bytes).cur = (char)uVar12 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
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
        iVar11 = il_buffer_reserve(&buf->bytes,4);
        bVar15 = buf->open & (byte)iVar11 & 1;
        buf->open = bVar15;
        pcVar8 = sym_arg;
        if (bVar15 != 0) {
          if (uVar12 < 0x3fff80) goto joined_r0x1047cb40;
          *(buf->bytes).cur = (char)uVar12 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
      else {
        uVar12 = pcVar8->entity & 0xffffff;
LAB_1040c31c:
        if (g_c9il_mode == '\0') goto LAB_1047c7e1;
LAB_1040c5f6:
        il_buffer_put_id(buf,uVar12);
        pcVar8 = sym_arg;
      }
    }
    goto switchD_1040b75e_caseD_12;
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
      cVar25 = pcVar8->entity;
LAB_1047c967:
      uVar12 = cVar25 & 0xffffff;
LAB_1047c951:
      if (g_c9il_mode != '\0') goto LAB_1040c5f6;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      if (uVar12 < 0x3fff80) {
LAB_1047c8cb:
        if (uVar12 < 0x4000) {
          *(buf->bytes).cur = (byte)uVar12 & 0x3f | 0x80;
LAB_1047c8de:
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym_arg;
        }
        else {
          *(buf->bytes).cur = (byte)uVar12 | 0xc0;
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 6);
LAB_1047c912:
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 0xe);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym_arg;
        }
      }
      else {
        *(buf->bytes).cur = (char)uVar12 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x17':
    bVar15 = (sym->x28).bytes.bit_position;
    if ((bVar15 != 0) && (bVar15 != 2)) {
      bVar15 = (-(bVar15 != 3) & 0xfeU) + 3;
    }
    break;
  case '\x18':
    part_scratch = g_function_ex_offset;
    uVar12 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        if ((iVar10 & 0xffffff80U) == 0) {
          *(buf->bytes).cur = (c1_u8)iVar10;
          pcVar17 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          piVar22 = (int *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)piVar22;
          *piVar22 = iVar10;
          pcVar17 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar17;
      }
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        if ((uVar12 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar12;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar8 = sym;
        }
        else {
          *(buf->bytes).cur = 0x80;
LAB_1040c3e5:
          puVar18 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar18;
          *puVar18 = uVar12;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar8 = sym;
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x19':
    if (fdef_mode == '\0') {
      rec_word1 = CONCAT22(rec_word1._2_2_,0xffff);
      if (g_function_tuple_count < 0x10000) {
        rec_word1 = CONCAT22(rec_word1._2_2_,(short)g_function_tuple_count);
      }
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      iVar11 = il_buffer_put_byte7(buf,(int)(short)rec_word1);
      if ((char)iVar11 == '\0') {
        *(buf->bytes).cur = 0x80;
        psVar19 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar19;
        *psVar19 = (short)rec_word1;
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
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
        sVar16 = 0;
      }
      else {
        sVar16 = 0x1000;
      }
      rec_word2 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 |
                               (ushort)(*(byte *)((int)&sym_arg->tail + 10) & 0xe)) << 7) |
                  (sym_arg->flags5 & 0x80) >> 5 |
                  (int)(short)(-(ushort)(g_function_compile_it != '\0') & 0x20) |
                  (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                  (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar16 | (int)sVar27;
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
      iVar11 = il_buffer_reserve(&buf->bytes,5);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
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
      iVar11 = il_buffer_reserve(&buf->bytes,5);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        if ((int)rec_word2 < 0x8000) {
          *(undefined2 *)(buf->bytes).cur = (undefined2)rec_word2;
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar8 = sym;
        }
        else {
          *(uint *)(buf->bytes).cur =
               (uint)((uint3)(rec_word2 >> 8) & 0xffffc0 | 0x40) << 9 | rec_word2 & 0x7fff;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar8 = sym;
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
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
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      if (uVar12 < 0x3fff80) {
joined_r0x1047cb40:
        if (0x3fff < uVar12) {
          *(buf->bytes).cur = (byte)uVar12 | 0xc0;
          pcVar17 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar17;
          *pcVar17 = (c1_u8)(uVar12 >> 6);
          goto LAB_1047c912;
        }
        *(buf->bytes).cur = (byte)uVar12 & 0x3f | 0x80;
        goto LAB_1047c8de;
      }
      *(buf->bytes).cur = (char)uVar12 + 0x80;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x1d':
    part_scratch = 0x386;
    iVar11 = il_buffer_reserve(&buf->bytes,3);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      pcVar17 = (buf->bytes).cur;
      pcVar17[0] = 0x86;
      pcVar17[1] = '\x03';
      (buf->bytes).cur = (buf->bytes).cur + 2;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x1e':
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      pcVar17 = (buf->bytes).cur;
      pcVar17[0] = 0x96;
      pcVar17[1] = 0xba;
      pcVar17[2] = '0';
      pcVar17[3] = '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case ' ':
    iVar11 = il_buffer_reserve(&buf->bytes,2);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(buf->bytes).cur = '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '!':
    iVar11 = il_buffer_reserve(&buf->bytes,6);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if (bVar15 != 0) {
      if ((uVar12 & 0xffffff80) == 0) {
        *(buf->bytes).cur = (c1_u8)uVar12;
        pcVar17 = (buf->bytes).cur + 1;
      }
      else {
        *(buf->bytes).cur = 0x80;
        puVar18 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar18;
        *puVar18 = uVar12;
        pcVar17 = (buf->bytes).cur + 4;
      }
      (buf->bytes).cur = pcVar17;
    }
    pcVar17 = (c1_u8 *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar11 = il_buffer_reserve(&buf->bytes,2);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        *(buf->bytes).cur = '\0';
        pcVar17 = (buf->bytes).cur + 1;
        goto LAB_1040c758;
      }
    }
    else {
      uVar12 = 0xffffffff;
      pcVar6 = g_il_pch_name;
      do {
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      uVar12 = ~uVar12;
      iVar11 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        pcVar13 = (buf->bytes).cur;
        for (uVar20 = uVar12 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar13 = pcVar13 + 4;
        }
        for (uVar20 = uVar12 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
          *pcVar13 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar13 = pcVar13 + 1;
        }
        pcVar17 = (buf->bytes).cur + uVar12;
LAB_1040c758:
        (buf->bytes).cur = pcVar17;
      }
    }
    if (g_pragma_comment_list == (c1_pragma_comment *)0x0) {
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if (bVar15 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
    }
    else {
      uVar12 = 0;
      comment_rev = (c1_pragma_comment *)0x0;
      comment_cell = g_pragma_comment_list;
      while (g_pragma_comment_list = comment_rev, comment_cell != (c1_pragma_comment *)0x0) {
        comment_next = comment_cell->next;
        comment_cell->next = g_pragma_comment_list;
        uVar12 = uVar12 + 1;
        comment_rev = comment_cell;
        comment_cell = comment_next;
      }
      iVar11 = il_buffer_reserve(&buf->bytes,6);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      comment_cell_2 = g_pragma_comment_list;
      if (bVar15 != 0) {
        if ((uVar12 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar12;
          pcVar17 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          puVar18 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar18;
          *puVar18 = uVar12;
          pcVar17 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar17;
        comment_cell_2 = g_pragma_comment_list;
      }
      for (; pcVar8 = sym_arg, part_scratch = (uint)comment_cell_2,
          comment_cell_2 != (c1_pragma_comment *)0x0; comment_cell_2 = comment_cell_2->next) {
        pcVar17 = (c1_u8 *)comment_cell_2->text;
        iVar11 = comment_cell_2->kind;
        iVar10 = il_buffer_reserve(&buf->bytes,2);
        bVar15 = buf->open & (byte)iVar10 & 1;
        buf->open = bVar15;
        if (bVar15 != 0) {
          *(buf->bytes).cur = (c1_u8)iVar11;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        if (comment_cell_2->kind == 7) {
          if ((c1_u8)(*pcVar17 + '\x01') != '\0') {
            part_scratch = (uint)(char)(*pcVar17 + '\x01');
            do {
              cVar23 = *pcVar17;
              iVar11 = il_buffer_reserve(&buf->bytes,2);
              bVar15 = buf->open & (byte)iVar11 & 1;
              buf->open = bVar15;
              if (bVar15 != 0) {
                *(buf->bytes).cur = cVar23;
                (buf->bytes).cur = (buf->bytes).cur + 1;
              }
              pcVar17 = pcVar17 + 1;
              part_scratch = part_scratch - 1;
            } while (part_scratch != 0);
          }
        }
        else {
          uVar12 = 0xffffffff;
          pcVar13 = pcVar17;
          do {
            if (uVar12 == 0) break;
            uVar12 = uVar12 - 1;
            cVar23 = *pcVar13;
            pcVar13 = pcVar13 + 1;
          } while (cVar23 != '\0');
          uVar12 = ~uVar12;
          iVar11 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
          bVar15 = buf->open & (byte)iVar11 & 1;
          buf->open = bVar15;
          if (bVar15 != 0) {
            pcVar13 = (buf->bytes).cur;
            for (uVar20 = uVar12 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
              pcVar13 = pcVar13 + 4;
            }
            for (uVar20 = uVar12 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
              *pcVar13 = *pcVar17;
              pcVar17 = pcVar17 + 1;
              pcVar13 = pcVar13 + 1;
            }
            ppcVar1 = &(buf->bytes).cur;
            *ppcVar1 = *ppcVar1 + uVar12;
          }
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\"':
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar9 = &g_line_map_cached_row;
    }
    else {
      pcVar9 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    file = pcVar9->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar12 = g_next_entity_id ^ file->entity;
    g_next_entity_id = g_next_entity_id + 1;
    file->entity = uVar12 & 0xffffff ^ file->entity;
    uVar12 = il_symbol_key_2(file);
    if (g_c9il_mode == '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      if (bVar15 != 0) {
        bVar15 = (byte)uVar12;
        if (uVar12 < 0x3fff80) {
          if (uVar12 < 0x4000) {
            *(buf->bytes).cur = bVar15 & 0x3f | 0x80;
            pcVar17 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar17;
            *pcVar17 = (c1_u8)(uVar12 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = bVar15 | 0xc0;
            pcVar17 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar17;
            *pcVar17 = (c1_u8)(uVar12 >> 6);
            pcVar17 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar17;
            *pcVar17 = (c1_u8)(uVar12 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          *(buf->bytes).cur = bVar15 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar12);
    }
    pcVar17 = (c1_u8 *)pp_position_file_name(&g_token_position);
LAB_1040c8c8:
    uVar12 = 0xffffffff;
    pcVar13 = pcVar17;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar23 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar23 != '\0');
    uVar12 = ~uVar12;
    iVar11 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      pcVar13 = (buf->bytes).cur;
      for (uVar20 = uVar12 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar20 = uVar12 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        *pcVar13 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar13 = pcVar13 + 1;
      }
      ppcVar1 = &(buf->bytes).cur;
      *ppcVar1 = *ppcVar1 + uVar12;
    }
    goto switchD_1040b75e_caseD_12;
  case '#':
    iVar10 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar10 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      iVar10 = il_buffer_put_byte7(buf,(int)(short)iVar11);
      if ((char)iVar10 == '\0') {
        *(buf->bytes).cur = 0x80;
        psVar19 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar19;
        *psVar19 = (short)iVar11;
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '%':
    uVar12 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar12 = g_next_entity_id;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      *(uint *)(buf->bytes).cur = uVar12;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '&':
    uVar12 = 0xffffffff;
    pcVar6 = (char *)g_source_file_ni;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    uVar12 = ~uVar12;
    iVar11 = il_buffer_reserve(&buf->bytes,uVar12 + 1);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if (bVar15 != 0) {
      pcVar13 = (buf->bytes).cur;
      for (uVar20 = uVar12 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar20 = uVar12 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        *pcVar13 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar13 = pcVar13 + 1;
      }
      ppcVar1 = &(buf->bytes).cur;
      *ppcVar1 = *ppcVar1 + uVar12;
    }
    goto switchD_1040b75e_caseD_12;
  case '(':
    if (g_c9il_mode == '\0') {
      il_emit_symbol_function_line_fragment
                (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                 tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,iter_sym,
                 ref_cell,ref_list,kind,sym_arg);
      return;
    }
    goto switchD_1040b75e_caseD_12;
  case ')':
    if (g_c9il_mode == '\0') {
      iVar11 = il_buffer_reserve(&buf->bytes,4);
      bVar15 = buf->open & (byte)iVar11 & 1;
      buf->open = bVar15;
      pcVar8 = sym_arg;
      if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,0), (char)iVar11 == '\0')) {
        *(buf->bytes).cur = 0x80;
        pcVar17 = (buf->bytes).cur + 1;
        (buf->bytes).cur = pcVar17;
        pcVar17[0] = '\0';
        pcVar17[1] = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar8 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '*':
    uVar12 = 2;
    if (g_c9il_mode == '\0') {
      uVar12 = 3;
    }
    if (g_dlp != '\0') {
      uVar12 = uVar12 | 8;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,5);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if (bVar15 != 0) {
      *(uint *)(buf->bytes).cur = uVar12;
      (buf->bytes).cur = (buf->bytes).cur + 4;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,0xc), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar17 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar17;
      pcVar17[0] = '\f';
      pcVar17[1] = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,0), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar17 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar17;
      pcVar17[0] = '\0';
      pcVar17[1] = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar11 = il_buffer_reserve(&buf->bytes,4);
    bVar15 = buf->open & (byte)iVar11 & 1;
    buf->open = bVar15;
    pcVar8 = sym_arg;
    if ((bVar15 != 0) && (iVar11 = il_buffer_put_byte7(buf,0x1fe8), (char)iVar11 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar17 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar17;
      pcVar17[0] = 0xe8;
      pcVar17[1] = '\x1f';
      (buf->bytes).cur = (buf->bytes).cur + 2;
      pcVar8 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '.':
    if (g_opt_Ct != '\0') {
      il_emit_symbol_inline_fragment
                (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                 tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,iter_sym,
                 ref_cell,ref_list,kind,sym_arg);
      return;
    }
    goto switchD_1040b75e_caseD_12;
  }
  iVar11 = il_buffer_reserve(&buf->bytes,2);
  bVar14 = buf->open & (byte)iVar11 & 1;
  buf->open = bVar14;
  pcVar8 = sym_arg;
  if (bVar14 != 0) {
    *(buf->bytes).cur = bVar15;
    (buf->bytes).cur = (buf->bytes).cur + 1;
    pcVar8 = sym;
  }
  goto switchD_1040b75e_caseD_12;
LAB_1047c4df:
  iVar11 = il_buffer_reserve(&buf->bytes,6);
  bVar15 = buf->open & (byte)iVar11 & 1;
  buf->open = bVar15;
  pcVar8 = sym_arg;
  if ((bVar15 == 0) || (iVar11 = il_buffer_put_byte7(buf,0), (char)iVar11 != '\0'))
  goto switchD_1040b75e_caseD_12;
  *(buf->bytes).cur = 0x80;
  goto LAB_1047c50f;
}

