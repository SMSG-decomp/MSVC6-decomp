void __cdecl
il_emit_tuple_symbol_operand
          (char *shape,c1_symbol *sym,c1_node *cur_node,char *shape_cursor,int op,c1_node *node)

{
  char cVar1;
  ushort uVar2;
  c1_symbol *sym_00;
  c1_type *pcVar3;
  uint *src;
  c1_u8 cVar4;
  c1_type *type;
  void *pvVar5;
  int iVar6;
  byte bVar7;
  char *pcVar8;
  c1_type *type_2;
  
  if ((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags21 & 1) == 0)) {
    g_function_has_body = 1;
    g_function_auto_inline = 0;
  }
LAB_1061813f:
  if (g_c9il_mode == '\0') {
    if ((sym->key_ref & 0xfffffff8) == 0) {
      pvVar5 = (void *)il_symbol_key_assign(sym);
      pcVar8 = shape;
    }
    else {
      pvVar5 = (void *)(sym->key_ref >> 3);
      pcVar8 = shape;
    }
  }
  else {
    pvVar5 = (void *)(sym->entity & 0xffffff);
    pcVar8 = shape;
  }
switchD_106180c0_caseD_27:
  if (g_c9il_mode == '\0') goto LAB_1063991b;
  il_buffer_put_id(&g_il_ex,(uint)pvVar5);
  shape_cursor = pcVar8;
switchD_10617f29_caseD_4:
  sym = PTR_106692dc;
  cVar1 = *shape_cursor;
  if (cVar1 == '\0') {
    return;
  }
  shape_cursor = shape_cursor + 1;
  switch(cVar1) {
  case '\x01':
    bVar7 = *(byte *)cur_node->left;
    iVar6 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (bVar7 & 0x1f) == 0xb;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
    goto switchD_10617f29_caseD_4;
  case '\x02':
    pvVar5 = cur_node->left;
    iVar6 = il_buffer_reserve(&g_il_ex.bytes,6);
    g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
    if ((g_il_ex.open == 0) ||
       (iVar6 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar5), (char)iVar6 != '\0'))
    goto switchD_10617f29_caseD_4;
    *g_il_ex.bytes.pbEnd = 0x80;
    break;
  case '\x03':
    type_2 = *(c1_type **)((int)cur_node->left + 4);
    g_function_has_body = 1;
    type = (c1_type *)((uint)type_2 & -(uint)((type_2->code & 0x80) != 0));
    switch((byte)type->flags & 7) {
    case 1:
      node = (c1_node *)0x0;
      break;
    case 2:
      node = (c1_node *)0x8;
      break;
    case 3:
      node = (c1_node *)0x4;
      break;
    case 4:
      node = (c1_node *)0x18;
      break;
    case 5:
      if ((type->code & 0x83) != 0x81) {
        type = (c1_type *)((uint)type->base & -(uint)((type->base->code & 0x80) != 0));
      }
      node = (c1_node *)(((byte)~(byte)(type->flags >> 0xf) & 1) << 4);
      break;
    case 6:
      node = (c1_node *)0x14;
    }
    iVar6 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (uchar)node;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
  default:
    goto switchD_10617f29_caseD_4;
  case '\x06':
    il_emit_type_descriptor(op,cur_node,2);
    goto switchD_10617f29_caseD_4;
  case '\a':
  case '\r':
  case '\x0e':
    cVar4 = il_buffer_reserve_ok(&g_il_ex,1);
    if (cVar4 != '\0') {
      *g_il_ex.bytes.pbEnd = '\0';
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
    goto switchD_10617f29_caseD_4;
  case '\b':
    pvVar5 = (void *)0x0;
    pcVar8 = shape_cursor;
    switch(op) {
    case 0x26:
      sym = cur_node->left;
      iVar6 = il_key_is_global_helper_function(sym->key_ref >> 3);
      if ((char)iVar6 != '\0') {
        (*g_idb->vtbl->idb_note_helper_call)(g_idb);
      }
      break;
    case 0x27:
    case 0x28:
      goto switchD_106180c0_caseD_27;
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2d:
      sym_00 = cur_node->left;
      if (g_c9il_mode != '\0') {
        pvVar5 = (void *)(sym_00->entity & 0xffffff);
        goto switchD_106180c0_caseD_27;
      }
      if ((sym_00->key_ref & 0xfffffff8) != 0) {
        pvVar5 = (void *)(sym_00->key_ref >> 3);
LAB_1063991b:
        iVar6 = il_buffer_reserve(&g_il_ex.bytes,4);
        g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
        if (g_il_ex.open != 0) {
          bVar7 = (byte)pvVar5;
          shape_cursor = pcVar8;
          if (pvVar5 < (void *)0x3fff80) {
            if (pvVar5 < (void *)0x4000) {
              *g_il_ex.bytes.pbEnd = bVar7 & 0x3f | 0x80;
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar5 >> 6);
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            }
            else {
              *g_il_ex.bytes.pbEnd = bVar7 | 0xc0;
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar5 >> 6);
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar5 >> 0xe);
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            }
          }
          else {
            *g_il_ex.bytes.pbEnd = bVar7 + 0x80;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          }
        }
        goto switchD_10617f29_caseD_4;
      }
      pvVar5 = (void *)il_symbol_key_assign(sym_00);
      goto switchD_106180c0_caseD_27;
    default:
      sym = cur_node->left;
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
      sym = cur_node->left;
      sym_set_nesting_depth(sym);
      break;
    case 0x3b:
    case 0x3c:
      sym_mark_referenced(PTR_106692dc);
      sym_set_nesting_depth(sym);
      break;
    case 0x3d:
      pvVar5 = cur_node->left;
      goto switchD_106180c0_caseD_27;
    }
    if (sym == (c1_symbol *)0x0) goto switchD_106180c0_caseD_27;
    sym_mark_referenced(sym);
    if ((sym->flags3 & 0x40) != 0) {
      sym = decl_lookup_file_scope_twin(sym);
      sym_mark_referenced(sym);
    }
    shape = shape_cursor;
    if (((sym->flags23 & 1) != 0) &&
       (pvVar5 = sym_segment_record(sym), (*(uint *)((int)pvVar5 + 0x1c) & 0xffffff) == 5)) {
      il_emit_tuple_symbol_operand(shape_cursor,sym,cur_node,shape_cursor,op,node);
      return;
    }
    goto LAB_1061813f;
  case '\v':
    il_emit_type_descriptor(op,cur_node,1);
    pcVar3 = cur_node->type;
    if (-1 < (char)pcVar3->code) {
      cVar1 = (char)pcVar3->code;
      while (cVar1 < '\0') {
        pcVar3 = pcVar3->base;
        cVar1 = (char)pcVar3->code;
      }
      uVar2 = pcVar3->code;
      if (((uVar2 & 0x10) != 0) || ((uVar2 & 0x100) != 0)) {
        il_emit_integer_constant
                  ((uint)cur_node->left,(int)cur_node->right,
                   (int)(char)(&g_type_rank_table)[uVar2 & 0xf]);
        goto switchD_10617f29_caseD_4;
      }
      if ((uVar2 & 0x20) != 0) {
        src = cur_node->left;
        iVar6 = il_buffer_reserve(&g_il_ex.bytes,0xb);
        g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,src,10);
        }
        pvVar5 = cur_node->left;
        iVar6 = il_buffer_reserve(&g_il_ex.bytes,3);
        g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar5 + 10),2);
        }
        goto switchD_10617f29_caseD_4;
      }
      if ((uVar2 & 0x40) == 0) goto switchD_10617f29_caseD_4;
    }
    pvVar5 = cur_node->left;
    iVar6 = il_buffer_reserve(&g_il_ex.bytes,6);
    g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
    if ((g_il_ex.open == 0) ||
       (iVar6 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar5), (char)iVar6 != '\0'))
    goto switchD_10617f29_caseD_4;
    *g_il_ex.bytes.pbEnd = 0x80;
    break;
  case '\x1b':
    if (g_dlp != '\0') {
      il_emit_tuple_fragment(cur_node,shape_cursor,op,node);
      return;
    }
    goto switchD_10617f29_caseD_4;
  }
  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  *(void **)g_il_ex.bytes.pbEnd = pvVar5;
  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
  goto switchD_10617f29_caseD_4;
}

