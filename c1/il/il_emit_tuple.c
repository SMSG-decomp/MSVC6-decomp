void __cdecl il_emit_tuple(int op,c1_node *node)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  uint *src;
  c1_node *cur_node;
  c1_u8 cVar4;
  c1_type *type;
  c1_symbol *pcVar5;
  int iVar6;
  byte bVar7;
  void *pvVar8;
  char *shape_cursor;
  char *shape_cursor_00;
  c1_type *type_2;
  
  cur_node = node;
  if (op == 0xb9) {
    diag_fatal(1,".\\toil.c",0xfd8);
  }
  il_emit_line_record();
  cVar4 = il_buffer_reserve_ok(&g_il_ex,1);
  if (cVar4 != '\0') {
    *g_il_ex.bytes.pbEnd = (uchar)op;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  shape_cursor_00 = g_il_op_shapes[op].codes;
  g_function_tuple_count = g_function_tuple_count + 1;
  if (shape_cursor_00 != (char *)0x0) {
    cVar1 = *shape_cursor_00;
    pcVar5 = PTR_106692dc;
    while (PTR_106692dc = pcVar5, cVar1 != '\0') {
      shape_cursor = shape_cursor_00 + 1;
      shape_cursor_00 = shape_cursor;
      switch(cVar1) {
      case '\x01':
        bVar7 = *(byte *)cur_node->left;
        iVar6 = il_buffer_reserve(&g_il_ex.bytes,2);
        g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.pbEnd = (bVar7 & 0x1f) == 0xb;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          shape_cursor_00 = shape_cursor;
        }
        break;
      case '\x02':
        pvVar8 = cur_node->left;
        iVar6 = il_buffer_reserve(&g_il_ex.bytes,6);
        g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
        if ((g_il_ex.open != 0) &&
           (iVar6 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar8), (char)iVar6 == '\0')) {
          *g_il_ex.bytes.pbEnd = 0x80;
LAB_10617fba:
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          *(void **)g_il_ex.bytes.pbEnd = pvVar8;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
          shape_cursor_00 = shape_cursor;
        }
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
          shape_cursor_00 = shape_cursor;
        }
        break;
      case '\x06':
        il_emit_type_descriptor(op,cur_node,2);
        break;
      case '\a':
      case '\r':
      case '\x0e':
        cVar4 = il_buffer_reserve_ok(&g_il_ex,1);
        if (cVar4 != '\0') {
          *g_il_ex.bytes.pbEnd = '\0';
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
          shape_cursor_00 = shape_cursor;
        }
        break;
      case '\b':
        pvVar8 = (void *)0x0;
        switch(op) {
        case 0x26:
          pcVar5 = cur_node->left;
          iVar6 = il_key_is_global_helper_function(pcVar5->key_ref >> 3);
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
          pcVar5 = cur_node->left;
          if (g_c9il_mode != '\0') {
            pvVar8 = (void *)(pcVar5->entity & 0xffffff);
            goto switchD_106180c0_caseD_27;
          }
          if ((pcVar5->key_ref & 0xfffffff8) == 0) {
            pvVar8 = (void *)il_symbol_key_assign(pcVar5);
            goto switchD_106180c0_caseD_27;
          }
          pvVar8 = (void *)(pcVar5->key_ref >> 3);
          goto LAB_1063991b;
        default:
          pcVar5 = cur_node->left;
          break;
        case 0x38:
        case 0x39:
        case 0x3a:
          pcVar5 = cur_node->left;
          sym_set_nesting_depth(pcVar5);
          break;
        case 0x3b:
        case 0x3c:
          sym_mark_referenced(pcVar5);
          sym_set_nesting_depth(pcVar5);
          break;
        case 0x3d:
          pvVar8 = cur_node->left;
          goto switchD_106180c0_caseD_27;
        }
        if (pcVar5 != (c1_symbol *)0x0) {
          sym_mark_referenced(pcVar5);
          if ((pcVar5->flags3 & 0x40) != 0) {
            pcVar5 = decl_lookup_file_scope_twin(pcVar5);
            sym_mark_referenced(pcVar5);
          }
          if (((pcVar5->flags23 & 1) != 0) &&
             (pvVar8 = sym_segment_record(pcVar5), (*(uint *)((int)pvVar8 + 0x1c) & 0xffffff) == 5))
          {
            il_emit_tuple_symbol_operand(shape_cursor,pcVar5,cur_node,shape_cursor_00,op,node);
            return;
          }
          if (g_c9il_mode == '\0') {
            if ((pcVar5->key_ref & 0xfffffff8) == 0) {
              pvVar8 = (void *)il_symbol_key_assign(pcVar5);
            }
            else {
              pvVar8 = (void *)(pcVar5->key_ref >> 3);
            }
          }
          else {
            pvVar8 = (void *)(pcVar5->entity & 0xffffff);
          }
        }
switchD_106180c0_caseD_27:
        if (g_c9il_mode == '\0') {
LAB_1063991b:
          iVar6 = il_buffer_reserve(&g_il_ex.bytes,4);
          g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
          if (g_il_ex.open != 0) {
            bVar7 = (byte)pvVar8;
            if (pvVar8 < (void *)0x3fff80) {
              if (pvVar8 < (void *)0x4000) {
                *g_il_ex.bytes.pbEnd = bVar7 & 0x3f | 0x80;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar8 >> 6);
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                shape_cursor_00 = shape_cursor;
              }
              else {
                *g_il_ex.bytes.pbEnd = bVar7 | 0xc0;
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar8 >> 6);
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                *g_il_ex.bytes.pbEnd = (uchar)((uint)pvVar8 >> 0xe);
                g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
                shape_cursor_00 = shape_cursor;
              }
            }
            else {
              *g_il_ex.bytes.pbEnd = bVar7 + 0x80;
              g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
              shape_cursor_00 = shape_cursor;
            }
          }
        }
        else {
          il_buffer_put_id(&g_il_ex,(uint)pvVar8);
          shape_cursor_00 = shape_cursor;
        }
        break;
      case '\v':
        il_emit_type_descriptor(op,cur_node,1);
        pcVar3 = cur_node->type;
        if ((char)pcVar3->code < '\0') {
LAB_10618201:
          pvVar8 = cur_node->left;
          iVar6 = il_buffer_reserve(&g_il_ex.bytes,6);
          g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
          if ((g_il_ex.open != 0) &&
             (iVar6 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar8), (char)iVar6 == '\0')) {
            *g_il_ex.bytes.pbEnd = 0x80;
            goto LAB_10617fba;
          }
        }
        else {
          cVar1 = (char)pcVar3->code;
          while (cVar1 < '\0') {
            pcVar3 = pcVar3->base;
            cVar1 = (char)pcVar3->code;
          }
          uVar2 = pcVar3->code;
          if (((uVar2 & 0x10) == 0) && ((uVar2 & 0x100) == 0)) {
            if ((uVar2 & 0x20) == 0) {
              if ((uVar2 & 0x40) != 0) goto LAB_10618201;
            }
            else {
              src = cur_node->left;
              iVar6 = il_buffer_reserve(&g_il_ex.bytes,0xb);
              g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
              if (g_il_ex.open != 0) {
                il_buffer_put_bytes(&g_il_ex,src,10);
              }
              pvVar8 = cur_node->left;
              iVar6 = il_buffer_reserve(&g_il_ex.bytes,3);
              g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
              if (g_il_ex.open != 0) {
                il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar8 + 10),2);
                shape_cursor_00 = shape_cursor;
              }
            }
          }
          else {
            il_emit_integer_constant
                      ((uint)cur_node->left,(int)cur_node->right,
                       (int)(char)(&g_type_rank_table)[uVar2 & 0xf]);
            shape_cursor_00 = shape_cursor;
          }
        }
        break;
      case '\x1b':
        if (g_dlp != '\0') {
          il_emit_tuple_fragment(cur_node,shape_cursor,op,node);
          return;
        }
      }
      pcVar5 = PTR_106692dc;
      cVar1 = *shape_cursor_00;
    }
  }
  return;
}

