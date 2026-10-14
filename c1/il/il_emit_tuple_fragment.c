void __cdecl il_emit_tuple_fragment(c1_node *cur_node,char *shape_cursor,int op,c1_node *node)

{
  char cVar1;
  ushort uVar2;
  uint *src;
  c1_type *type;
  uint value;
  c1_node *pcVar3;
  c1_u8 cVar4;
  byte *pbVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  int iVar8;
  byte bVar9;
  void *pvVar10;
  uint uStack00000014;
  c1_type *in_stack_00000018;
  c1_type_x08 in_stack_0000001c;
  c1_u32 in_stack_00000020;
  
  pcVar7 = *(c1_type **)((int)cur_node->left + 4);
  if ((pcVar7->code & 0x8f) == 0x82) {
    pcVar7 = type_base(pcVar7);
  }
  if ((pcVar7->flags & 0x60) != 0) {
    uStack00000014._0_2_ = pcVar7->code;
    uStack00000014._2_2_ = pcVar7->flags;
    in_stack_00000018 = pcVar7->base;
    in_stack_0000001c = pcVar7->extra;
    in_stack_00000020 = pcVar7->debug_index;
    uStack00000014 = uStack00000014 & 0xff9fffff;
    pcVar7 = type_intern((c1_type *)&uStack00000014);
  }
  if (g_opt_Zg == '\0') {
    debug_type_index(pcVar7);
    cVar1 = (char)pcVar7->code;
    type = pcVar7;
    while (cVar1 < '\0') {
      type = type->base;
      cVar1 = (char)type->code;
    }
    iVar8 = type_is_class_or_enum(type);
    if (((((char)iVar8 != '\0') && (pcVar6 = (type->extra).sym, pcVar6 != (c1_symbol *)0x0)) &&
        ((pcVar6->kind & 0x1f) == 4)) && ((pcVar6->x2c).references == (c1_symbol_cell *)0x0)) {
      debug_type_record_struct_complete(pcVar6);
    }
  }
  value = pcVar7->debug_index;
  cVar4 = il_buffer_reserve_ok(&g_il_ex,5);
  if ((cVar4 != '\0') && (iVar8 = il_buffer_put_byte7(&g_il_ex,value), (char)iVar8 == '\0')) {
    *g_il_ex.bytes.pbEnd = 0x80;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    *(uint *)g_il_ex.bytes.pbEnd = value;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
  }
switchD_10617f29_caseD_4:
  pcVar6 = PTR_106692dc;
  cVar1 = *shape_cursor;
  if (cVar1 == '\0') {
    return;
  }
  shape_cursor = shape_cursor + 1;
  switch(cVar1) {
  case '\x01':
    bVar9 = *(byte *)cur_node->left;
    iVar8 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (bVar9 & 0x1f) == 0xb;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
    goto switchD_10617f29_caseD_4;
  case '\x02':
    pvVar10 = cur_node->left;
    iVar8 = il_buffer_reserve(&g_il_ex.bytes,6);
    g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
    if ((g_il_ex.open == 0) ||
       (iVar8 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar10), (char)iVar8 != '\0'))
    goto switchD_10617f29_caseD_4;
    *g_il_ex.bytes.pbEnd = 0x80;
    break;
  case '\x03':
    pbVar5 = *(byte **)((int)cur_node->left + 4);
    g_function_has_body = 1;
    pbVar5 = (byte *)((uint)pbVar5 & -(uint)((*pbVar5 & 0x80) != 0));
    switch(pbVar5[2] & 7) {
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
      if ((*pbVar5 & 0x83) != 0x81) {
        pbVar5 = (byte *)((uint)*(byte **)(pbVar5 + 4) &
                         -(uint)((**(byte **)(pbVar5 + 4) & 0x80) != 0));
      }
      node = (c1_node *)(((byte)~(byte)((ushort)*(undefined2 *)(pbVar5 + 2) >> 0xf) & 1) << 4);
      break;
    case 6:
      node = (c1_node *)0x14;
    }
    pcVar3 = node;
    iVar8 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (uchar)pcVar3;
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
    pvVar10 = (void *)0x0;
    switch(op) {
    case 0x26:
      pcVar6 = cur_node->left;
      iVar8 = il_key_is_global_helper_function(pcVar6->key_ref >> 3);
      if ((char)iVar8 != '\0') {
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
      pcVar6 = cur_node->left;
      if (g_c9il_mode != '\0') {
        pvVar10 = (void *)(pcVar6->entity & 0xffffff);
        goto switchD_106180c0_caseD_27;
      }
      if ((pcVar6->key_ref & 0xfffffff8) == 0) {
        pvVar10 = (void *)il_symbol_key_assign(pcVar6);
        goto switchD_106180c0_caseD_27;
      }
      pvVar10 = (void *)(pcVar6->key_ref >> 3);
      goto LAB_1063991b;
    default:
      pcVar6 = cur_node->left;
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
      pcVar6 = cur_node->left;
      sym_set_nesting_depth(pcVar6);
      break;
    case 0x3b:
    case 0x3c:
      sym_mark_referenced(PTR_106692dc);
      sym_set_nesting_depth(pcVar6);
      break;
    case 0x3d:
      pvVar10 = cur_node->left;
      goto switchD_106180c0_caseD_27;
    }
    if (pcVar6 != (c1_symbol *)0x0) {
      sym_mark_referenced(pcVar6);
      if ((pcVar6->flags3 & 0x40) != 0) {
        pcVar6 = decl_lookup_file_scope_twin(pcVar6);
        sym_mark_referenced(pcVar6);
      }
      if (((pcVar6->flags23 & 1) != 0) &&
         (pvVar10 = sym_segment_record(pcVar6), (*(uint *)((int)pvVar10 + 0x1c) & 0xffffff) == 5)) {
        il_emit_tuple_symbol_operand(shape_cursor,pcVar6,cur_node,shape_cursor,op,node);
        return;
      }
      if (g_c9il_mode == '\0') {
        if ((pcVar6->key_ref & 0xfffffff8) == 0) {
          pvVar10 = (void *)il_symbol_key_assign(pcVar6);
        }
        else {
          pvVar10 = (void *)(pcVar6->key_ref >> 3);
        }
      }
      else {
        pvVar10 = (void *)(pcVar6->entity & 0xffffff);
      }
    }
switchD_106180c0_caseD_27:
    if (g_c9il_mode == '\0') {
LAB_1063991b:
      iVar8 = il_buffer_reserve(&g_il_ex.bytes,4);
      g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
      if (g_il_ex.open != 0) {
        bVar9 = (byte)pvVar10;
        if (pvVar10 < (void *)0x3fff80) {
          if (pvVar10 < (void *)0x4000) {
            *g_il_ex.bytes.pbEnd = bVar9 & 0x3f | 0x80;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar10 >> 6);
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          }
          else {
            *g_il_ex.bytes.pbEnd = bVar9 | 0xc0;
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar10 >> 6);
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
            *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar10 >> 0xe);
            g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          }
        }
        else {
          *g_il_ex.bytes.pbEnd = bVar9 + 0x80;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
        }
      }
    }
    else {
      il_buffer_put_id(&g_il_ex,(uint)pvVar10);
    }
    goto switchD_10617f29_caseD_4;
  case '\v':
    il_emit_type_descriptor(op,cur_node,1);
    pcVar7 = cur_node->type;
    if (-1 < (char)pcVar7->code) {
      cVar1 = (char)pcVar7->code;
      while (cVar1 < '\0') {
        pcVar7 = pcVar7->base;
        cVar1 = (char)pcVar7->code;
      }
      uVar2 = pcVar7->code;
      if (((uVar2 & 0x10) != 0) || ((uVar2 & 0x100) != 0)) {
        il_emit_integer_constant
                  ((uint)cur_node->left,(int)cur_node->right,
                   (int)(char)(&g_type_rank_table)[uVar2 & 0xf]);
        goto switchD_10617f29_caseD_4;
      }
      if ((uVar2 & 0x20) != 0) {
        src = cur_node->left;
        iVar8 = il_buffer_reserve(&g_il_ex.bytes,0xb);
        g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,src,10);
        }
        pvVar10 = cur_node->left;
        iVar8 = il_buffer_reserve(&g_il_ex.bytes,3);
        g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar10 + 10),2);
        }
        goto switchD_10617f29_caseD_4;
      }
      if ((uVar2 & 0x40) == 0) goto switchD_10617f29_caseD_4;
    }
    pvVar10 = cur_node->left;
    iVar8 = il_buffer_reserve(&g_il_ex.bytes,6);
    g_il_ex.open = g_il_ex.open & (byte)iVar8 & 1;
    if ((g_il_ex.open == 0) ||
       (iVar8 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar10), (char)iVar8 != '\0'))
    goto switchD_10617f29_caseD_4;
    *g_il_ex.bytes.pbEnd = 0x80;
    break;
  case '\x1b':
    goto switchD_10617f29_caseD_1b;
  }
  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  *(void **)g_il_ex.bytes.pbEnd = pvVar10;
  g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
  goto switchD_10617f29_caseD_4;
switchD_10617f29_caseD_1b:
  if (g_dlp != '\0') {
    il_emit_tuple_fragment(cur_node,shape_cursor,op,node);
    return;
  }
  goto switchD_10617f29_caseD_4;
}

