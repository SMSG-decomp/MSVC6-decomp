void __cdecl
il_emit_symbol_inline_fragment
          (c1_symbol *sym,c1_il_buffer *buf,char fdef_mode,uint part_scratch,byte is_inline,
          c1_type *sym_type,c1_type *derived_type,c1_type *fn_type,c1_symbol *pair_sym,char *tmpl,
          uint base_code,uint rec_word0,uint rec_word1,uint rec_word2,int is_array,uint type_flags,
          uint *out_cell,c1_symbol *iter_sym,void **ref_cell,void **ref_list,int kind,
          c1_symbol *sym_arg)

{
  c1_u8 **ppcVar1;
  byte sym_flags4;
  c1_type *pcVar2;
  fe_name *pfVar3;
  c1_symbol_x28_bytes cVar4;
  fe_file_record *file;
  byte *value;
  byte bVar5;
  char cVar6;
  c1_u8 cVar7;
  ushort uVar8;
  void *value_00;
  char *pcVar9;
  c1_type *pcVar10;
  c1_symbol *pcVar11;
  c1_line_map_row *pcVar12;
  int iVar13;
  int iVar14;
  c1_symbol_vector *v;
  uint uVar15;
  c1_u8 *pcVar16;
  byte bVar17;
  short sVar18;
  uint *puVar19;
  short *psVar20;
  c1_u8 *pcVar21;
  ushort *puVar22;
  ushort uVar23;
  int *piVar24;
  ushort uVar25;
  c1_u32 cVar26;
  void **ppvVar27;
  uint uVar28;
  short sVar29;
  c1_pragma_comment *comment_cell;
  c1_pragma_comment *comment_rev;
  c1_pragma_comment *comment_next;
  c1_pragma_comment *comment_cell_2;
  
  pcVar11 = sym;
  if (g_inline_level == 0) goto switchD_1040b75e_caseD_12;
  bVar5 = sym->kind & 0x1f;
  if ((bVar5 != 7) && (bVar5 != 8)) goto switchD_1040b75e_caseD_12;
  ppvVar27 = (void **)((sym->tail).fn.record)->unk14;
  if (ppvVar27 != (void **)0x0) {
    v = (c1_symbol_vector *)symtab_record_new_kind4();
    ref_list = ppvVar27;
    do {
      value = *ppvVar27;
      ref_cell = ppvVar27;
      if (((((value == (byte *)0x0) || (bVar5 = *value & 0x1f, bVar5 == 0x10)) || (bVar5 == 7)) ||
          ((bVar5 == 6 || (bVar5 == 0x11)))) || (bVar5 == 8)) {
        v = (c1_symbol_vector *)vector_find_or_add((short *)v,(int)value);
      }
      ppvVar27 = ref_cell[1];
    } while (ppvVar27 != (void **)0x0);
    ref_cell = ppvVar27;
    uVar8 = counted_array_count(&v->count);
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if (bVar5 != 0) {
      if ((uVar8 & 0xff80) == 0) {
        *(buf->bytes).cur = (c1_u8)uVar8;
        pcVar21 = (buf->bytes).cur + 1;
      }
      else {
        *(buf->bytes).cur = 0x80;
        puVar22 = (ushort *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar22;
        *puVar22 = uVar8;
        pcVar21 = (buf->bytes).cur + 2;
      }
      (buf->bytes).cur = pcVar21;
    }
    if (0 < (short)uVar8) {
      vector_iterator_init((c1_symbol_vector_iter *)&stack0x00000050,v);
      cVar6 = vector_iter_next((int *)&stack0x00000050);
      while (cVar6 != '\0') {
        if (iter_sym == (c1_symbol *)0x0) {
          if (g_c9il_mode == '\0') {
            iVar14 = il_buffer_reserve(&buf->bytes,4);
            bVar5 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar5;
            if (bVar5 != 0) {
              *(buf->bytes).cur = 0x80;
              pcVar21 = (buf->bytes).cur + 1;
              (buf->bytes).cur = pcVar21;
              *pcVar21 = '\0';
              (buf->bytes).cur = (buf->bytes).cur + 1;
            }
          }
          else {
            il_buffer_put_id(buf,0);
          }
        }
        else {
          uVar15 = iter_sym->entity;
          uVar28 = uVar15 & 0xffffff;
          if (g_c9il_mode == '\0') {
            iVar14 = il_buffer_reserve(&buf->bytes,4);
            bVar5 = buf->open & (byte)iVar14 & 1;
            buf->open = bVar5;
            if (bVar5 != 0) {
              if (uVar28 < 0x3fff80) {
                if (uVar28 < 0x4000) {
                  *(buf->bytes).cur = (byte)uVar15 & 0x3f | 0x80;
                  pcVar21 = (buf->bytes).cur + 1;
                  (buf->bytes).cur = pcVar21;
                  *pcVar21 = (c1_u8)(uVar28 >> 6);
                  (buf->bytes).cur = (buf->bytes).cur + 1;
                }
                else {
                  *(buf->bytes).cur = (byte)uVar15 | 0xc0;
                  pcVar21 = (buf->bytes).cur + 1;
                  (buf->bytes).cur = pcVar21;
                  *pcVar21 = (c1_u8)(uVar28 >> 6);
                  pcVar21 = (buf->bytes).cur + 1;
                  (buf->bytes).cur = pcVar21;
                  *pcVar21 = (c1_u8)(uVar28 >> 0xe);
                  (buf->bytes).cur = (buf->bytes).cur + 1;
                }
              }
              else {
                *(buf->bytes).cur = (char)uVar28 + 0x80;
                (buf->bytes).cur = (buf->bytes).cur + 1;
              }
            }
          }
          else {
            cVar7 = il_buffer_reserve_ok(buf,4);
            if (cVar7 != '\0') {
              if (uVar28 < 0x8000) {
                *(short *)(buf->bytes).cur = (short)uVar28;
                (buf->bytes).cur = (buf->bytes).cur + 2;
              }
              else {
                *(uint *)(buf->bytes).cur =
                     (uint)((uint3)(uVar15 >> 8) & 0xffc0 | 0x40) << 9 | uVar15 & 0x7fff;
                (buf->bytes).cur = (buf->bytes).cur + 4;
              }
            }
          }
        }
        cVar6 = vector_iter_next((int *)&stack0x00000050);
      }
    }
    vector_release((int)v);
    pcVar11 = sym_arg;
    goto switchD_1040b75e_caseD_12;
  }
LAB_1047cdd6:
  iVar14 = il_buffer_reserve(&buf->bytes,4);
  bVar5 = buf->open & (byte)iVar14 & 1;
  buf->open = bVar5;
  pcVar11 = sym_arg;
  if ((bVar5 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), pcVar11 = sym_arg, (char)iVar14 == '\0')
     ) {
    *(buf->bytes).cur = 0x80;
    pcVar21 = (buf->bytes).cur + 1;
    (buf->bytes).cur = pcVar21;
    pcVar21[0] = '\0';
    pcVar21[1] = '\0';
    (buf->bytes).cur = (buf->bytes).cur + 2;
    pcVar11 = sym;
  }
switchD_1040b75e_caseD_12:
  sym = pcVar11;
  iVar13 = g_function_ex_offset;
  iVar14 = g_function_formal_count;
  pcVar21 = (c1_u8 *)g_source_file_ni;
  uVar15 = g_cv_precomp_signature;
  cVar6 = *tmpl;
  if (cVar6 == '\0') {
    if ((g_c9il_mode == '\0') && (sym != (c1_symbol *)0x0)) {
      if (buf == &g_il_gi_buffer) {
        ilstore_put_record(&g_il_gi_buffer,sym->key_ref >> 3,1);
      }
      else if (buf == &g_il_gl) {
        ilstore_delete_record(&g_il_gi_buffer,sym->key_ref >> 3);
      }
      if ((fdef_mode == '\0') && (kind == 0xe)) {
        uVar15 = il_buffer_reserve(&g_il_gi_fdef.bytes,0xd);
        pcVar21 = g_il_gi_fdef.bytes.cur;
        pcVar16 = (c1_u8 *)(uVar15 & 0xffffff01);
        g_il_gi_fdef.open = g_il_gi_fdef.open & (byte)pcVar16;
        if (g_il_gi_fdef.open != 0) {
          *(uint *)g_il_gi_fdef.bytes.cur = rec_word0;
          *(uint *)(pcVar21 + 4) = rec_word1;
          *(uint *)(pcVar21 + 8) = rec_word2;
          pcVar16 = g_il_gi_fdef.bytes.cur + 0xc;
          g_il_gi_fdef.bytes.cur = pcVar16;
        }
        ilstore_put_record(&g_il_gi_fdef,sym->key_ref >> 3,
                           CONCAT31((int3)((uint)pcVar16 >> 8),(sym->flags21 & 1) != 0) + 1);
      }
    }
    return;
  }
  tmpl = tmpl + 1;
  pcVar11 = sym;
  switch(cVar6) {
  case '\x01':
    bVar5 = sym->kind & 0x1f;
    if (((bVar5 == 7) || (bVar5 == 8)) || (bVar5 == 6)) {
      uVar15 = type_size(fn_type);
    }
    else {
      uVar15 = type_size(sym_type);
      if (uVar15 == 0) {
        bVar5 = sym->kind & 0x1f;
        if (bVar5 == 0xb) {
          type_check_size_known(sym_type);
        }
        else if (bVar5 == 0xc) {
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
                (uVar15,sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                 pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                 iter_sym,ref_cell,ref_list,kind,sym_arg);
      return;
    }
    if ((g_rtti != '\0') && ((sym->flags3 & 0x80) != 0)) {
      uVar15 = uVar15 + 4;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,6);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if ((bVar5 != 0) &&
       (iVar14 = il_buffer_put_byte7(buf,uVar15), pcVar11 = sym_arg, (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      puVar19 = (uint *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)puVar19;
      *puVar19 = uVar15;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x02':
    if (fdef_mode == '\0') {
      bVar5 = sym->flags5;
      if (((((bVar5 & 0x80) == 0) || (bVar17 = sym->kind & 0x1f, bVar17 == 7)) || (bVar17 == 8)) ||
         (bVar17 == 6)) {
        rec_word0 = 0;
      }
      else {
        rec_word0 = 0x80;
      }
      bVar17 = sym->kind & 0x1f;
      if (((bVar17 == 7) || (bVar17 == 8)) || (bVar17 == 6)) {
        if ((bVar5 & 2) != 0) {
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
                    (bVar17,bVar5,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                     derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                     type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
      }
      uVar15 = sym->key_ref & 3;
      if (uVar15 != 0) {
        if (((bVar17 == 10) || (bVar17 == 0xb)) && ((bVar5 & 8) != 0)) {
          rec_word0 = rec_word0 | 0x2000;
        }
        if ((((bVar17 != 7) && (bVar17 != 8)) && (bVar17 != 6)) &&
           ((sym->name != g_name_this || (uVar15 != 1)))) {
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
      if (((bVar17 == 7) || (bVar17 == 8)) || (bVar17 == 6)) {
        if (((bVar5 & 0x10) != 0) && ((*(byte *)((int)&sym->tail + 9) & 0xc) == 0)) {
          rec_word0 = rec_word0 | 0x8000;
        }
        if ((bVar5 & 1) != 0) {
          il_emit_symbol_ref_flag_1000_fragment
                    (bVar17,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                     derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                     type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
      }
      bVar5 = sym->flags22;
      if ((((bVar5 & 2) != 0) && (bVar17 != 7)) && (bVar17 != 8)) {
        rec_word0 = rec_word0 | 0x1000;
      }
      if ((bVar17 == 10) && ((sym->flags21 & 0x80) != 0)) {
        il_emit_symbol_ref_flag_40_fragment
                  (bVar5,sym_flags4,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,
                   derived_type,fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,
                   type_flags,out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if ((sym->storage & 0x40) != 0) {
        if ((kind != 0xe) && ((sym_flags4 & 4) == 0)) {
          il_emit_symbol_ref_base_type_fragment
                    (bVar5,rec_word0,sym,buf,'\0',part_scratch,is_inline,sym_type,derived_type,
                     fn_type,pair_sym,tmpl,base_code,rec_word1,rec_word2,is_array,type_flags,
                     out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
        if (((bVar5 & 8) == 0) && (rec_word0 = rec_word0 | 0x20, g_rtti != '\0')) {
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
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = (c1_u8)kind;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x04':
    if (is_array == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = sym_element_size((int)sym);
    }
    iVar14 = il_buffer_reserve(&buf->bytes,6);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if ((bVar5 != 0) &&
       (iVar14 = il_buffer_put_byte7(buf,uVar15), pcVar11 = sym_arg, (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      puVar19 = (uint *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)puVar19;
      *puVar19 = uVar15;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x05':
    if (g_c9il_mode == '\0') {
      if ((sym->key_ref & 0xfffffff8) == 0) {
        uVar15 = il_symbol_key_assign(sym);
        goto LAB_1040ba62;
      }
      uVar15 = sym->key_ref >> 3;
    }
    else {
      uVar15 = sym->entity & 0xffffff;
LAB_1040ba62:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(buf,uVar15);
        goto switchD_1040b75e_caseD_12;
      }
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      bVar5 = (byte)uVar15;
      if (uVar15 < 0x3fff80) {
        if (uVar15 < 0x4000) {
          *(buf->bytes).cur = bVar5 & 0x3f | 0x80;
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym;
        }
        else {
          *(buf->bytes).cur = bVar5 | 0xc0;
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 6);
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 0xe);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym;
        }
      }
      else {
        *(buf->bytes).cur = bVar5 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x06':
    if (g_opt_Zi == '\0') {
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if ((bVar5 == 0) ||
         (iVar14 = il_buffer_put_byte7(buf,0), pcVar11 = sym_arg, (char)iVar14 != '\0'))
      goto switchD_1040b75e_caseD_12;
      *(buf->bytes).cur = 0x80;
    }
    else {
      bVar5 = sym->kind & 0x1f;
      if (bVar5 != 0x19) {
        if ((((bVar5 != 0) && (bVar5 < 0xf)) && (bVar5 != 5)) &&
           (((sym->flags23 & 1) != 0 &&
            (pcVar11 = sym_segment_record(sym), pcVar11->name == g_name_drectve)))) {
          il_emit_symbol_type_fragment
                    (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym
                     ,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,
                     iter_sym,ref_cell,ref_list,kind,sym_arg);
          return;
        }
        bVar5 = sym->kind & 0x1f;
        if (bVar5 == 4) {
          value_00 = (void *)((sym->detail).cls)->debug_index;
LAB_1040bb45:
          if (value_00 == (void *)0x0) goto LAB_1040bac6;
        }
        else {
          if ((sym->type->code & 0x300) != 0) {
            value_00 = (void *)((((sym->type->extra).cls)->detail).cls)->debug_index;
            goto LAB_1040bb45;
          }
          if ((bVar5 == 8) && ((*(byte *)((int)&sym->tail + 10) & 0x10) != 0)) {
            value_00 = symtab_15ec_lookup_by_id(sym);
            goto LAB_1040bb45;
          }
LAB_1040bac6:
          value_00 = (void *)sym_type->debug_index;
        }
        iVar14 = il_buffer_reserve(&buf->bytes,6);
        bVar5 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar5;
        pcVar11 = sym_arg;
        if ((bVar5 != 0) &&
           (iVar14 = il_buffer_put_byte7(buf,(uint)value_00), pcVar11 = sym_arg,
           (char)iVar14 == '\0')) {
          *(buf->bytes).cur = 0x80;
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *(void **)pcVar21 = value_00;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar11 = sym;
        }
        goto switchD_1040b75e_caseD_12;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if ((bVar5 == 0) ||
         (iVar14 = il_buffer_put_byte7(buf,0), pcVar11 = sym_arg, (char)iVar14 != '\0'))
      goto switchD_1040b75e_caseD_12;
      *(buf->bytes).cur = 0x80;
    }
    pcVar21 = (buf->bytes).cur + 1;
    (buf->bytes).cur = pcVar21;
    pcVar21[0] = '\0';
    pcVar21[1] = '\0';
    pcVar21[2] = '\0';
    pcVar21[3] = '\0';
    (buf->bytes).cur = (buf->bytes).cur + 4;
    pcVar11 = sym;
    goto switchD_1040b75e_caseD_12;
  case '\a':
    bVar5 = g_il_block_level;
    if (kind == 3) {
      bVar5 = (sym->x28).bytes.bit_position;
    }
    break;
  case '\b':
    bVar5 = sym->kind & 0x1f;
    if (bVar5 == 9) {
      bVar5 = *(byte *)&sym->detail;
    }
    else if ((sym->flags4 & 8) == 0) {
      if ((bVar5 == 10) && ((sym->storage & 7) == 3)) {
        bVar5 = 0x24;
      }
      else {
        bVar5 = 0;
      }
    }
    else {
      bVar5 = -((sym->storage & 7) != 2) & 0x25;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar17 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar17;
    pcVar11 = sym_arg;
    if (bVar17 != 0) {
      *(buf->bytes).cur = bVar5;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\t':
    if ((sym->name == (fe_name *)0x0) || (sym->name == g_name_unnamed)) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    else if (((g_c9il_mode == '\0') && (uVar15 = sym->key_ref >> 3, 0x14 < uVar15)) &&
            ((uVar15 < g_next_global_key &&
             ((pcVar9 = sym_namespace_member_dotted_name(sym), pcVar9 == (char *)0x0 &&
              (pcVar9 = (char *)pdb_namemap_symbol_name(sym), pcVar9 != (char *)0x0)))))) {
      il_buffer_put_string(buf,pcVar9);
    }
    else {
      pcVar9 = decorate_name(sym,(c1_symbol *)0x0);
      il_buffer_put_string(buf,pcVar9);
    }
    goto switchD_1040b75e_caseD_12;
  case '\n':
    bVar5 = sym->flags5;
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar17 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar17;
    pcVar11 = sym_arg;
    if (bVar17 != 0) {
      *(buf->bytes).cur = ((bVar5 & 4) != 0) + '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\v':
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\f':
    bVar5 = sym->kind & 0x1f;
    if ((bVar5 == 0xb) || (bVar5 == 0xc)) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        *(buf->bytes).cur = '\x03';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    else {
      bVar5 = sym->storage & 7;
      if ((bVar5 == 0) || (3 < bVar5)) {
        iVar14 = il_buffer_reserve(&buf->bytes,2);
        bVar5 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar5;
        pcVar11 = sym_arg;
        if (bVar5 != 0) {
          *(buf->bytes).cur = '\x01';
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym;
        }
      }
      else {
        pcVar10 = sym_type;
        if ((sym_type->code & 0x8f) == 0x83) {
          pcVar10 = type_skip_arrays(sym_type->base);
        }
        if (((((((byte)pcVar10->flags >> 5 & 1) == 0) ||
              ((((sym->flags23 & 1) != 0 &&
                (pcVar11 = sym_segment_record(sym), (pcVar11->kind & 0x1f) == 0xe)) &&
               (pcVar11 = sym_segment_record(sym), (pcVar11->entity & 0xffffff) != 3)))) ||
             ((sym->flags3 & 0x20) != 0)) ||
            (((-1 < (char)sym_type->code && ((sym_type->code & 0x200) != 0)) &&
             ((((((sym_type->extra).cls)->detail).cls)->flags3f & 0x10) != 0)))) &&
           ((((sym->flags4 & 8) == 0 || ((sym->storage & 0x40) == 0)) ||
            ((g_string_pooling_readonly == '\0' ||
             ((((sym->flags23 & 1) != 0 &&
               (pcVar11 = sym_segment_record(sym), (pcVar11->kind & 0x1f) == 0xe)) &&
              (pcVar11 = sym_segment_record(sym), (pcVar11->entity & 0xffffff) != 3)))))))) {
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar5 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar5;
          pcVar11 = sym_arg;
          if (bVar5 != 0) {
            *(buf->bytes).cur = '\x02';
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar11 = sym;
          }
        }
        else {
          iVar14 = il_buffer_reserve(&buf->bytes,2);
          bVar5 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar5;
          pcVar11 = sym_arg;
          if (bVar5 != 0) {
            *(buf->bytes).cur = '\x04';
            (buf->bytes).cur = (buf->bytes).cur + 1;
            pcVar11 = sym;
          }
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\r':
    if (((kind == 4) || (kind == 0x10)) || (kind == 0xe)) {
      uVar8 = fn_type->code;
      cVar6 = (char)uVar8;
      if ((cVar6 < '\0') && (fn_type != (c1_type *)0x0)) {
        uVar23 = fn_type->flags;
      }
      else {
        uVar8 = 0;
        uVar23 = 0;
      }
      uVar25 = 0;
      pcVar10 = fn_type;
      while (cVar6 < '\0') {
        pcVar10 = pcVar10->base;
        cVar6 = (char)pcVar10->code;
      }
      base_code = CONCAT22(base_code._2_2_,pcVar10->code);
      pcVar10 = fn_type;
    }
    else {
      if (derived_type == (c1_type *)0x0) {
        uVar8 = 0;
        uVar23 = 0;
      }
      else {
        uVar8 = derived_type->code;
        uVar23 = derived_type->flags;
      }
      pcVar10 = sym_type;
      if ((base_code & 0x200) == 0) {
LAB_1040be91:
        uVar25 = 0;
      }
      else {
        if ((short)base_code != 0x203) {
          pcVar2 = sym_arg->type;
          cVar6 = (char)pcVar2->code;
          while (cVar6 < '\0') {
            pcVar2 = pcVar2->base;
            cVar6 = (char)pcVar2->code;
          }
          if ((pcVar2->code & 0x300) == 0) {
            pcVar11 = (c1_symbol *)0x0;
          }
          else {
            pcVar11 = (pcVar2->extra).cls;
          }
          if ((((pcVar11->detail).cls)->layout_flags3b & 1) == 0) goto LAB_1040be91;
        }
        uVar25 = 0x10;
      }
    }
    if ((uVar23 & 0x100) != 0) {
      uVar25 = uVar25 | 0x4000;
    }
    if ((uVar23 & 0x40) != 0) {
      uVar25 = uVar25 | 0x1000;
    }
    uVar8 = uVar8 & 0x8f;
    if (uVar8 == 0x83) {
      uVar25 = uVar25 | 6;
    }
    else if (((uVar8 == 0x8a) || (uVar8 == 0x8e)) &&
            (bVar5 = type_member_pointer_is_aggregate(pcVar10), bVar5 != 0)) {
      uVar25 = uVar25 | 6;
    }
    else {
      if (uVar8 == 0x8a) goto switchD_1040bf4e_caseD_11;
      if ((((uVar8 == 0x8e) || (uVar8 == 0x82)) || (uVar8 == 0x86)) || (uVar8 == 0x80)) {
        uVar25 = uVar25 | 3;
      }
      else {
        uVar8 = pcVar10->code;
        if (((uVar8 & 0x2000) == 0) &&
           ((((uVar8 & 0xfff) != 0x11 || ((uVar8 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')
            ))) {
          uVar15 = base_code & 0xffff;
          if (uVar15 < 0x104) {
            if (uVar15 == 0x103) {
switchD_1040bf4e_caseD_11:
              uVar25 = uVar25 | 1;
            }
            else {
              switch(uVar15) {
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
            if (uVar15 < 0x403) {
              if (uVar15 == 0x402) goto switchD_1040bf4e_caseD_10;
              if ((0x200 < uVar15) && (uVar15 < 0x204)) {
                uVar25 = uVar25 | 6;
                goto LAB_1040c011;
              }
            }
            else if (uVar15 == 0x1011) goto switchD_1040bf4e_caseD_11;
switchD_1040bf4e_caseD_15:
            if ((0x18 < uVar15) && (uVar15 < 0x1e)) {
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
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        *(buf->bytes).cur = (byte)(uVar25 >> 8) | 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = (c1_u8)uVar25;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym_arg;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x0e':
    cVar26 = sym->key_ref;
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      il_buffer_put_compact_u16_unchecked(buf,(byte)cVar26 & 3);
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x0f':
    pfVar3 = (sym->detail).segment_class;
    if ((pfVar3 != (fe_name *)0x0) && (pfVar3 != g_name_unnamed)) {
      pcVar21 = (c1_u8 *)pfVar3->text;
      goto LAB_1040c8c8;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x10':
    if (((sym->flags22 & 4) == 0) || (kind == 7)) {
      if (((sym->flags22 & 8) == 0) || (kind == 7)) {
        if ((sym->storage & 0x40) == 0) {
          bVar5 = sym->storage & 7;
          if (((bVar5 < 4) || (6 < bVar5)) && ((bVar5 != 3 || ((sym->flags1 & 4) != 0)))) {
            if (((sym->flags4 & 4) == 0) && ((sym->flags2 & 4) == 0)) {
              if (bVar5 == 1) {
                bVar5 = 2;
              }
              else if ((is_array == 0) || ((derived_type->extra).cls != (c1_symbol *)0x0)) {
                bVar5 = 3;
              }
              else {
                bVar5 = 2;
              }
            }
            else {
              bVar5 = 1;
            }
          }
          else {
            bVar5 = 4;
          }
        }
        else {
          bVar5 = (~sym->flags4 & 4 | 2) >> 1;
        }
      }
      else {
        bVar5 = 8;
      }
    }
    else {
      bVar5 = (-((sym->flags2 & 4) != 0) & 5U) + 2;
    }
    break;
  case '\x11':
    bVar5 = sym->kind & 0x1f;
    if (((bVar5 != 7) && (bVar5 != 8)) && (bVar5 != 6)) {
      il_emit_symbol_record_body
                (sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,pair_sym,
                 tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,out_cell,iter_sym,
                 ref_cell,ref_list,kind,sym_arg);
      return;
    }
    if ((sym->flags2 & 4) == 0) {
      bVar5 = sym->storage & 7;
      if ((bVar5 == 3) && ((sym->flags1 & 4) == 0)) {
        il_emit_symbol_function_storage_fragment
                  ('\x03',sym,buf,fdef_mode,part_scratch,is_inline,sym_type,derived_type,fn_type,
                   pair_sym,tmpl,base_code,rec_word0,rec_word1,rec_word2,is_array,type_flags,
                   out_cell,iter_sym,ref_cell,ref_list,kind,sym_arg);
        return;
      }
      if (((sym->flags21 & 1) != 0) && (bVar5 != 1)) {
        diag_warning(1,0x1fa,sym);
      }
      cVar7 = (-((sym->flags22 & 8) != 0) & 6U) + 4;
    }
    else if ((sym->flags22 & 4) == 0) {
      if ((sym->flags22 & 8) == 0) {
        if ((((sym->storage & 0x40) == 0) && ((sym->storage & 7) == 3)) && ((sym->flags1 & 4) == 0))
        {
          cVar7 = '\x03';
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
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = cVar7;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
  default:
    goto switchD_1040b75e_caseD_12;
  case '\x13':
    if ((sym->flags5 & 0x10) == 0) {
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    else {
      pair_sym = sym_lookup_pair_local_then_global(sym,(uint *)&out_cell);
      uVar15 = out_cell[9];
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        if ((uVar15 & 0xffffff80) != 0) {
          *(buf->bytes).cur = 0x80;
          goto LAB_1040c3e5;
        }
        *(buf->bytes).cur = (c1_u8)uVar15;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x14':
    cVar4 = (sym->x28).bytes;
    if (((int)cVar4 < 0x8000) && (-0x8001 < (int)cVar4)) {
      bVar5 = 1;
    }
    else {
      bVar5 = 0;
    }
    sVar29 = (-(ushort)bVar5 & 0xfffe) + 4;
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if ((bVar5 != 0) && (iVar14 = il_buffer_put_byte7(buf,(int)sVar29), (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      psVar20 = (short *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)psVar20;
      *psVar20 = sVar29;
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if (bVar5 != 0) {
      *(buf->bytes).cur = cVar4.bit_position;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if (bVar5 != 0) {
      *(buf->bytes).cur = cVar4.depth;
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    if ((0x7fff < (int)cVar4) || (pcVar11 = sym_arg, (int)cVar4 < -0x8000)) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        *(buf->bytes).cur = (c1_u8)cVar4.unk2a;
        (buf->bytes).cur = (buf->bytes).cur + 1;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        *(buf->bytes).cur = cVar4.unk2a._1_1_;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x15':
    if (((sym->flags4 & 0x40) == 0) || ((sym->kind & 0x1f) != 10)) {
      if (((pair_sym->flags4 & 0x40) == 0) || ((pair_sym->kind & 0x1f) != 10)) {
        if (g_c9il_mode == '\0') {
          uVar15 = pair_sym->key_ref;
          if ((uVar15 & 0xfffffff8) != 0) goto LAB_1047c99a;
          uVar15 = il_symbol_key_assign(pair_sym);
          goto LAB_1047c951;
        }
        cVar26 = pair_sym->entity;
        goto LAB_1047c967;
      }
      pcVar11 = sym_inline_instance_of(pair_sym);
      if (g_c9il_mode != '\0') {
        uVar15 = pcVar11->entity & 0xffffff;
LAB_1047c879:
        if (g_c9il_mode == '\0') goto LAB_1047c88b;
        goto LAB_1040c5f6;
      }
      if ((pcVar11->key_ref & 0xfffffff8) == 0) {
        uVar15 = il_symbol_key_assign(pcVar11);
        goto LAB_1047c879;
      }
      uVar15 = pcVar11->key_ref >> 3;
LAB_1047c88b:
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        if (uVar15 < 0x3fff80) goto LAB_1047c8cb;
        *(buf->bytes).cur = (char)uVar15 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym_arg;
      }
    }
    else {
      pcVar11 = sym_inline_instance_of(sym);
      if (g_c9il_mode == '\0') {
        if ((pcVar11->key_ref & 0xfffffff8) == 0) {
          uVar15 = il_symbol_key_assign(pcVar11);
          goto LAB_1040c31c;
        }
        uVar15 = pcVar11->key_ref >> 3;
LAB_1047c7e1:
        iVar14 = il_buffer_reserve(&buf->bytes,4);
        bVar5 = buf->open & (byte)iVar14 & 1;
        buf->open = bVar5;
        pcVar11 = sym_arg;
        if (bVar5 != 0) {
          if (uVar15 < 0x3fff80) goto joined_r0x1047cb40;
          *(buf->bytes).cur = (char)uVar15 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym_arg;
        }
      }
      else {
        uVar15 = pcVar11->entity & 0xffffff;
LAB_1040c31c:
        if (g_c9il_mode == '\0') goto LAB_1047c7e1;
LAB_1040c5f6:
        il_buffer_put_id(buf,uVar15);
        pcVar11 = sym_arg;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x16':
    pcVar11 = sym_segment_record(sym);
    if (g_c9il_mode == '\0') {
      uVar15 = pcVar11->key_ref;
      if ((uVar15 & 0xfffffff8) == 0) {
        uVar15 = il_symbol_key_assign(pcVar11);
        goto LAB_1047c951;
      }
LAB_1047c99a:
      uVar15 = uVar15 >> 3;
    }
    else {
      cVar26 = pcVar11->entity;
LAB_1047c967:
      uVar15 = cVar26 & 0xffffff;
LAB_1047c951:
      if (g_c9il_mode != '\0') goto LAB_1040c5f6;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      if (uVar15 < 0x3fff80) {
LAB_1047c8cb:
        if (uVar15 < 0x4000) {
          *(buf->bytes).cur = (byte)uVar15 & 0x3f | 0x80;
LAB_1047c8de:
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 6);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym_arg;
        }
        else {
          *(buf->bytes).cur = (byte)uVar15 | 0xc0;
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 6);
LAB_1047c912:
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 0xe);
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym_arg;
        }
      }
      else {
        *(buf->bytes).cur = (char)uVar15 + 0x80;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym_arg;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x17':
    bVar5 = (sym->x28).bytes.bit_position;
    if ((bVar5 != 0) && (bVar5 != 2)) {
      bVar5 = (-(bVar5 != 3) & 0xfeU) + 3;
    }
    break;
  case '\x18':
    part_scratch = g_function_ex_offset;
    uVar15 = (-(uint)(g_function_in_pch != '\0') & g_pch_sy_file_offset) + g_function_sy_offset;
    if (g_c9il_mode != '\0') {
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        if ((iVar13 & 0xffffff80U) == 0) {
          *(buf->bytes).cur = (c1_u8)iVar13;
          pcVar21 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          piVar24 = (int *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)piVar24;
          *piVar24 = iVar13;
          pcVar21 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar21;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        if ((uVar15 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar15;
          (buf->bytes).cur = (buf->bytes).cur + 1;
          pcVar11 = sym;
        }
        else {
          *(buf->bytes).cur = 0x80;
LAB_1040c3e5:
          puVar19 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar19;
          *puVar19 = uVar15;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar11 = sym;
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
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      iVar14 = il_buffer_put_byte7(buf,(int)(short)rec_word1);
      pcVar11 = sym_arg;
      if ((char)iVar14 == '\0') {
        *(buf->bytes).cur = 0x80;
        psVar20 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar20;
        *psVar20 = (short)rec_word1;
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar11 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
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
        sVar18 = 0;
      }
      else {
        sVar18 = 0x1000;
      }
      rec_word2 = (int)(short)(((ushort)(sym->flags21 & 8) << 3 |
                               (ushort)(*(byte *)((int)&sym_arg->tail + 10) & 0xe)) << 7) |
                  (sym_arg->flags5 & 0x80) >> 5 |
                  (int)(short)(-(ushort)(g_function_compile_it != '\0') & 0x20) |
                  (int)(short)(-(ushort)(g_function_has_body != 0) & 8) |
                  (int)(short)(ushort)(g_function_in_pch != '\0') | (int)sVar18 | (int)sVar29;
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
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        if (rec_word2 < 0x8000) {
          *(short *)(buf->bytes).cur = (short)rec_word2;
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar11 = sym_arg;
        }
        else {
          *(uint *)(buf->bytes).cur = rec_word2 | 0x8000;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar11 = sym_arg;
        }
      }
    }
    else {
      iVar14 = il_buffer_reserve(&buf->bytes,5);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        if ((int)rec_word2 < 0x8000) {
          *(undefined2 *)(buf->bytes).cur = (undefined2)rec_word2;
          (buf->bytes).cur = (buf->bytes).cur + 2;
          pcVar11 = sym;
        }
        else {
          *(uint *)(buf->bytes).cur =
               (uint)((uint3)(rec_word2 >> 8) & 0xffffc0 | 0x40) << 9 | rec_word2 & 0x7fff;
          (buf->bytes).cur = (buf->bytes).cur + 4;
          pcVar11 = sym;
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\x1c':
    pcVar11 = class_scalar_deleting_dtor_of(sym);
    if (g_c9il_mode == '\0') {
      if ((pcVar11->key_ref & 0xfffffff8) == 0) {
        uVar15 = il_symbol_key_assign(pcVar11);
        goto LAB_1040c5e9;
      }
      uVar15 = pcVar11->key_ref >> 3;
    }
    else {
      uVar15 = pcVar11->entity & 0xffffff;
LAB_1040c5e9:
      if (g_c9il_mode != '\0') goto LAB_1040c5f6;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      if (uVar15 < 0x3fff80) {
joined_r0x1047cb40:
        if (0x3fff < uVar15) {
          *(buf->bytes).cur = (byte)uVar15 | 0xc0;
          pcVar21 = (buf->bytes).cur + 1;
          (buf->bytes).cur = pcVar21;
          *pcVar21 = (c1_u8)(uVar15 >> 6);
          goto LAB_1047c912;
        }
        *(buf->bytes).cur = (byte)uVar15 & 0x3f | 0x80;
        goto LAB_1047c8de;
      }
      *(buf->bytes).cur = (char)uVar15 + 0x80;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym_arg;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x1d':
    part_scratch = 0x386;
    iVar14 = il_buffer_reserve(&buf->bytes,3);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      pcVar21 = (buf->bytes).cur;
      pcVar21[0] = 0x86;
      pcVar21[1] = '\x03';
      (buf->bytes).cur = (buf->bytes).cur + 2;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '\x1e':
    iVar14 = il_buffer_reserve(&buf->bytes,5);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      pcVar21 = (buf->bytes).cur;
      pcVar21[0] = 0x96;
      pcVar21[1] = 0xba;
      pcVar21[2] = '0';
      pcVar21[3] = '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case ' ':
    iVar14 = il_buffer_reserve(&buf->bytes,2);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(buf->bytes).cur = '\x01';
      (buf->bytes).cur = (buf->bytes).cur + 1;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '!':
    iVar14 = il_buffer_reserve(&buf->bytes,6);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if (bVar5 != 0) {
      if ((uVar15 & 0xffffff80) == 0) {
        *(buf->bytes).cur = (c1_u8)uVar15;
        pcVar21 = (buf->bytes).cur + 1;
      }
      else {
        *(buf->bytes).cur = 0x80;
        puVar19 = (uint *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)puVar19;
        *puVar19 = uVar15;
        pcVar21 = (buf->bytes).cur + 4;
      }
      (buf->bytes).cur = pcVar21;
    }
    pcVar21 = (c1_u8 *)g_il_pch_name;
    if (g_il_pch_name == (char *)0x0) {
      iVar14 = il_buffer_reserve(&buf->bytes,2);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        *(buf->bytes).cur = '\0';
        pcVar21 = (buf->bytes).cur + 1;
        goto LAB_1040c758;
      }
    }
    else {
      uVar15 = 0xffffffff;
      pcVar9 = g_il_pch_name;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        cVar6 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar6 != '\0');
      uVar15 = ~uVar15;
      iVar14 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        pcVar16 = (buf->bytes).cur;
        for (uVar28 = uVar15 >> 2; uVar28 != 0; uVar28 = uVar28 - 1) {
          *(undefined4 *)pcVar16 = *(undefined4 *)pcVar21;
          pcVar21 = pcVar21 + 4;
          pcVar16 = pcVar16 + 4;
        }
        for (uVar28 = uVar15 & 3; uVar28 != 0; uVar28 = uVar28 - 1) {
          *pcVar16 = *pcVar21;
          pcVar21 = pcVar21 + 1;
          pcVar16 = pcVar16 + 1;
        }
        pcVar21 = (buf->bytes).cur + uVar15;
LAB_1040c758:
        (buf->bytes).cur = pcVar21;
      }
    }
    if (g_pragma_comment_list == (c1_pragma_comment *)0x0) {
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      pcVar11 = sym_arg;
      if (bVar5 != 0) {
        *(buf->bytes).cur = '\0';
        (buf->bytes).cur = (buf->bytes).cur + 1;
        pcVar11 = sym_arg;
      }
    }
    else {
      uVar15 = 0;
      comment_rev = (c1_pragma_comment *)0x0;
      comment_cell = g_pragma_comment_list;
      while (g_pragma_comment_list = comment_rev, comment_cell != (c1_pragma_comment *)0x0) {
        comment_next = comment_cell->next;
        comment_cell->next = g_pragma_comment_list;
        uVar15 = uVar15 + 1;
        comment_rev = comment_cell;
        comment_cell = comment_next;
      }
      iVar14 = il_buffer_reserve(&buf->bytes,6);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      comment_cell_2 = g_pragma_comment_list;
      if (bVar5 != 0) {
        if ((uVar15 & 0xffffff80) == 0) {
          *(buf->bytes).cur = (c1_u8)uVar15;
          pcVar21 = (buf->bytes).cur + 1;
        }
        else {
          *(buf->bytes).cur = 0x80;
          puVar19 = (uint *)((buf->bytes).cur + 1);
          (buf->bytes).cur = (c1_u8 *)puVar19;
          *puVar19 = uVar15;
          pcVar21 = (buf->bytes).cur + 4;
        }
        (buf->bytes).cur = pcVar21;
        comment_cell_2 = g_pragma_comment_list;
      }
      for (; pcVar11 = sym_arg, part_scratch = (uint)comment_cell_2,
          comment_cell_2 != (c1_pragma_comment *)0x0; comment_cell_2 = comment_cell_2->next) {
        pcVar21 = (c1_u8 *)comment_cell_2->text;
        iVar14 = comment_cell_2->kind;
        iVar13 = il_buffer_reserve(&buf->bytes,2);
        bVar5 = buf->open & (byte)iVar13 & 1;
        buf->open = bVar5;
        if (bVar5 != 0) {
          *(buf->bytes).cur = (c1_u8)iVar14;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        if (comment_cell_2->kind == 7) {
          if ((c1_u8)(*pcVar21 + '\x01') != '\0') {
            part_scratch = (uint)(char)(*pcVar21 + '\x01');
            do {
              cVar7 = *pcVar21;
              iVar14 = il_buffer_reserve(&buf->bytes,2);
              bVar5 = buf->open & (byte)iVar14 & 1;
              buf->open = bVar5;
              if (bVar5 != 0) {
                *(buf->bytes).cur = cVar7;
                (buf->bytes).cur = (buf->bytes).cur + 1;
              }
              pcVar21 = pcVar21 + 1;
              part_scratch = part_scratch - 1;
            } while (part_scratch != 0);
          }
        }
        else {
          uVar15 = 0xffffffff;
          pcVar16 = pcVar21;
          do {
            if (uVar15 == 0) break;
            uVar15 = uVar15 - 1;
            cVar7 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar7 != '\0');
          uVar15 = ~uVar15;
          iVar14 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
          bVar5 = buf->open & (byte)iVar14 & 1;
          buf->open = bVar5;
          if (bVar5 != 0) {
            pcVar16 = (buf->bytes).cur;
            for (uVar28 = uVar15 >> 2; uVar28 != 0; uVar28 = uVar28 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar21;
              pcVar21 = pcVar21 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar28 = uVar15 & 3; uVar28 != 0; uVar28 = uVar28 - 1) {
              *pcVar16 = *pcVar21;
              pcVar21 = pcVar21 + 1;
              pcVar16 = pcVar16 + 1;
            }
            ppcVar1 = &(buf->bytes).cur;
            *ppcVar1 = *ppcVar1 + uVar15;
          }
        }
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '\"':
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar12 = &g_line_map_cached_row;
    }
    else {
      pcVar12 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    file = pcVar12->file;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar15 = g_next_entity_id ^ file->entity;
    g_next_entity_id = g_next_entity_id + 1;
    file->entity = uVar15 & 0xffffff ^ file->entity;
    uVar15 = il_symbol_key_2(file);
    if (g_c9il_mode == '\0') {
      iVar14 = il_buffer_reserve(&buf->bytes,4);
      bVar5 = buf->open & (byte)iVar14 & 1;
      buf->open = bVar5;
      if (bVar5 != 0) {
        bVar5 = (byte)uVar15;
        if (uVar15 < 0x3fff80) {
          if (uVar15 < 0x4000) {
            *(buf->bytes).cur = bVar5 & 0x3f | 0x80;
            pcVar21 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar21;
            *pcVar21 = (c1_u8)(uVar15 >> 6);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
          else {
            *(buf->bytes).cur = bVar5 | 0xc0;
            pcVar21 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar21;
            *pcVar21 = (c1_u8)(uVar15 >> 6);
            pcVar21 = (buf->bytes).cur + 1;
            (buf->bytes).cur = pcVar21;
            *pcVar21 = (c1_u8)(uVar15 >> 0xe);
            (buf->bytes).cur = (buf->bytes).cur + 1;
          }
        }
        else {
          *(buf->bytes).cur = bVar5 + 0x80;
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
      }
    }
    else {
      il_buffer_put_id(buf,uVar15);
    }
    pcVar21 = (c1_u8 *)pp_position_file_name(&g_token_position);
LAB_1040c8c8:
    uVar15 = 0xffffffff;
    pcVar16 = pcVar21;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      cVar7 = *pcVar16;
      pcVar16 = pcVar16 + 1;
    } while (cVar7 != '\0');
    uVar15 = ~uVar15;
    iVar14 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      pcVar16 = (buf->bytes).cur;
      for (uVar28 = uVar15 >> 2; uVar28 != 0; uVar28 = uVar28 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar21;
        pcVar21 = pcVar21 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar28 = uVar15 & 3; uVar28 != 0; uVar28 = uVar28 - 1) {
        *pcVar16 = *pcVar21;
        pcVar21 = pcVar21 + 1;
        pcVar16 = pcVar16 + 1;
      }
      ppcVar1 = &(buf->bytes).cur;
      *ppcVar1 = *ppcVar1 + uVar15;
      pcVar11 = sym_arg;
    }
    goto switchD_1040b75e_caseD_12;
  case '#':
    iVar13 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar13 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      iVar13 = il_buffer_put_byte7(buf,(int)(short)iVar14);
      pcVar11 = sym_arg;
      if ((char)iVar13 == '\0') {
        *(buf->bytes).cur = 0x80;
        psVar20 = (short *)((buf->bytes).cur + 1);
        (buf->bytes).cur = (c1_u8 *)psVar20;
        *psVar20 = (short)iVar14;
        (buf->bytes).cur = (buf->bytes).cur + 2;
        pcVar11 = sym;
      }
    }
    goto switchD_1040b75e_caseD_12;
  case '%':
    uVar15 = 0x400000;
    if (g_c9il_mode != '\0') {
      uVar15 = g_next_entity_id;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,5);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      *(uint *)(buf->bytes).cur = uVar15;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      pcVar11 = sym;
    }
    goto switchD_1040b75e_caseD_12;
  case '&':
    uVar15 = 0xffffffff;
    pcVar9 = (char *)g_source_file_ni;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      cVar6 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar6 != '\0');
    uVar15 = ~uVar15;
    iVar14 = il_buffer_reserve(&buf->bytes,uVar15 + 1);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if (bVar5 != 0) {
      pcVar16 = (buf->bytes).cur;
      for (uVar28 = uVar15 >> 2; uVar28 != 0; uVar28 = uVar28 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar21;
        pcVar21 = pcVar21 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar28 = uVar15 & 3; uVar28 != 0; uVar28 = uVar28 - 1) {
        *pcVar16 = *pcVar21;
        pcVar21 = pcVar21 + 1;
        pcVar16 = pcVar16 + 1;
      }
      ppcVar1 = &(buf->bytes).cur;
      *ppcVar1 = *ppcVar1 + uVar15;
      pcVar11 = sym_arg;
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
    goto switchD_1040b75e_caseD_29;
  case '*':
    uVar15 = 2;
    if (g_c9il_mode == '\0') {
      uVar15 = 3;
    }
    if (g_dlp != '\0') {
      uVar15 = uVar15 | 8;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,5);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if (bVar5 != 0) {
      *(uint *)(buf->bytes).cur = uVar15;
      (buf->bytes).cur = (buf->bytes).cur + 4;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if ((bVar5 != 0) && (iVar14 = il_buffer_put_byte7(buf,0xc), (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar21 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar21;
      pcVar21[0] = '\f';
      pcVar21[1] = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    if ((bVar5 != 0) && (iVar14 = il_buffer_put_byte7(buf,0), (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar21 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar21;
      pcVar21[0] = '\0';
      pcVar21[1] = '\0';
      (buf->bytes).cur = (buf->bytes).cur + 2;
    }
    iVar14 = il_buffer_reserve(&buf->bytes,4);
    bVar5 = buf->open & (byte)iVar14 & 1;
    buf->open = bVar5;
    pcVar11 = sym_arg;
    if ((bVar5 != 0) &&
       (iVar14 = il_buffer_put_byte7(buf,0x1fe8), pcVar11 = sym_arg, (char)iVar14 == '\0')) {
      *(buf->bytes).cur = 0x80;
      pcVar21 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar21;
      pcVar21[0] = 0xe8;
      pcVar21[1] = '\x1f';
      (buf->bytes).cur = (buf->bytes).cur + 2;
      pcVar11 = sym;
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
  iVar14 = il_buffer_reserve(&buf->bytes,2);
  bVar17 = buf->open & (byte)iVar14 & 1;
  buf->open = bVar17;
  pcVar11 = sym_arg;
  if (bVar17 != 0) {
    *(buf->bytes).cur = bVar5;
    (buf->bytes).cur = (buf->bytes).cur + 1;
    pcVar11 = sym;
  }
  goto switchD_1040b75e_caseD_12;
switchD_1040b75e_caseD_29:
  if (g_c9il_mode == '\0') goto LAB_1047cdd6;
  goto switchD_1040b75e_caseD_12;
}

