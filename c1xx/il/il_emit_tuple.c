void __cdecl il_emit_tuple(int op,node *n)

{
  char cVar1;
  uint *src;
  node *n_00;
  uint uVar2;
  c1_u8 cVar3;
  byte bVar4;
  int iVar5;
  c1_node *callee_node;
  c1_type *callee_type;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  c1_type *pcVar8;
  char *shape;
  void *pvVar9;
  ushort uVar10;
  uint pair_key1;
  uint pair_key2;
  uint pair_flags;
  
  n_00 = n;
  if (op == 0xb9) {
    diag_fatal(1,".\\toil.c",0xfd8);
  }
  il_emit_line_record();
  cVar3 = il_buffer_reserve_ok(&g_il_ex,1);
  if (cVar3 != '\0') {
    *g_il_ex.bytes.cur = (c1_u8)op;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  g_function_tuple_count = g_function_tuple_count + 1;
  shape = (&g_il_op_shapes)[op * 2];
  if (shape != (char *)0x0) {
    cVar1 = *shape;
    pcVar6 = PTR_104de3b4;
    while (PTR_104de3b4 = pcVar6, cVar1 != '\0') {
      shape = shape + 1;
      switch(cVar1) {
      case '\x01':
        bVar4 = *(byte *)n_00->left;
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
        g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.cur = (bVar4 & 0x1f) == 0xb;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
        break;
      case '\x02':
        pvVar9 = n_00->left;
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
        bVar4 = g_il_ex.open & (byte)iVar5 & 1;
        g_il_ex.open = bVar4;
        goto LAB_10427299;
      case '\x03':
        callee_node = n_00->left;
        if ((callee_node != (c1_node *)0x0) && (callee_node->op == '7')) {
          callee_node = callee_node->right;
        }
        g_function_has_body = 1;
        callee_type = (c1_type *)
                      ((uint)callee_node->type & -(uint)((callee_node->type->code & 0x80) != 0));
        switch((byte)callee_type->flags & 7) {
        case 1:
          n = (node *)0x0;
          break;
        case 2:
          n = (node *)0x8;
          break;
        case 3:
          n = (node *)0x4;
          break;
        case 4:
          n = (node *)0x18;
          break;
        case 5:
          if ((callee_type->code & 0x83) != 0x81) {
            callee_type = (c1_type *)
                          ((uint)callee_type->base & -(uint)((callee_type->base->code & 0x80) != 0))
            ;
          }
          n = (node *)(((byte)~(byte)(callee_type->flags >> 0xf) & 1) << 4);
          break;
        case 6:
          n = (node *)0x14;
        }
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
        g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.cur = (c1_u8)n;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
        break;
      case '\x06':
        il_emit_type_descriptor(op,n_00,2);
        break;
      case '\a':
      case '\r':
      case '\x0e':
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
        g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.cur = '\0';
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
        break;
      case '\b':
        pvVar9 = (void *)0x0;
        switch(op) {
        case 0x26:
          pcVar6 = n_00->left;
          iVar5 = il_key_is_global_helper_function(pcVar6->key_ref >> 3);
          if ((char)iVar5 != '\0') {
            (*g_idb->vtbl->idb_note_helper_call)(g_idb);
          }
          break;
        case 0x27:
        case 0x28:
          goto switchD_104273cc_caseD_27;
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2d:
          pcVar6 = n_00->left;
          if (g_c9il_mode != '\0') {
            pvVar9 = (void *)(pcVar6->entity & 0xffffff);
            goto switchD_104273cc_caseD_27;
          }
          if ((pcVar6->key_ref & 0xfffffff8) == 0) {
            pvVar9 = (void *)il_symbol_key_assign(pcVar6);
            goto switchD_104273cc_caseD_27;
          }
          pvVar9 = (void *)(pcVar6->key_ref >> 3);
          goto LAB_1047d3f3;
        default:
          pcVar6 = n_00->left;
          break;
        case 0x38:
        case 0x39:
        case 0x3a:
          pcVar6 = n_00->left;
          sym_set_nesting_depth(pcVar6);
          break;
        case 0x3b:
        case 0x3c:
          sym_mark_referenced(pcVar6);
          sym_set_nesting_depth(pcVar6);
          break;
        case 0x3d:
          pvVar9 = n_00->left;
          goto switchD_104273cc_caseD_27;
        }
        if (pcVar6 != (c1_symbol *)0x0) {
          if ((pcVar6->kind & 0x1f) == 8) {
            sym_mark_enclosing_scopes(pcVar6);
          }
          sym_mark_referenced(pcVar6);
          if ((pcVar6->flags4 & 0x40) == 0) {
            bVar4 = pcVar6->kind & 0x1f;
            if ((bVar4 == 7) || (bVar4 == 8)) {
              if ((*(byte *)((int)&pcVar6->tail + 10) & 0x80) != 0) {
                sym_redeclaration_group_add(&g_map_region_queue,pcVar6);
              }
              if ((*(byte *)((int)&pcVar6->tail + 9) & 2) != 0) {
                il_emit_tuple_aliased_function_fragment
                          (n_00,pcVar6,1,pair_key1,pair_key2,pair_flags,shape,op,(int)n);
                return;
              }
            }
          }
          else {
            bVar4 = pcVar6->kind & 0x1f;
            if (bVar4 == 3) {
              pcVar6 = sym_static_member_stand_in(pcVar6);
            }
            else if (bVar4 == 10) {
              pcVar6 = sym_inline_instance_of(pcVar6);
            }
            else {
              pcVar6 = (c1_symbol *)0x0;
            }
            sym_mark_referenced(pcVar6);
          }
          if (((((pcVar6->flags23 & 1) != 0) &&
               (pcVar7 = sym_segment_record(pcVar6), (pcVar7->entity & 0xffffff) == 5)) &&
              (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0))
          {
            g_function_has_body = 1;
            g_function_auto_inline = 0;
          }
          pvVar9 = (void *)il_symbol_key(&pcVar6->kind);
        }
switchD_104273cc_caseD_27:
        if (g_c9il_mode == '\0') {
LAB_1047d3f3:
          iVar5 = il_buffer_reserve(&g_il_ex.bytes,4);
          g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
          if (g_il_ex.open != 0) {
            bVar4 = (byte)pvVar9;
            if (pvVar9 < (void *)0x3fff80) {
              if (pvVar9 < (void *)0x4000) {
                *g_il_ex.bytes.cur = bVar4 & 0x3f | 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar9 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
              else {
                *g_il_ex.bytes.cur = bVar4 | 0xc0;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar9 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar9 >> 0xe);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
            }
            else {
              *g_il_ex.bytes.cur = bVar4 + 0x80;
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            }
          }
        }
        else {
LAB_1042747b:
          il_buffer_put_id(&g_il_ex,(uint)pvVar9);
        }
        break;
      case '\v':
        if ((n_00->type->code & 0x8f) == 0x8a) {
          pcVar8 = type_int();
          n_00->type = pcVar8;
        }
        il_emit_type_descriptor(op,n_00,1);
        pcVar8 = n_00->type;
        if ((char)pcVar8->code < '\0') {
          pvVar9 = n_00->left;
          iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
          g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
          if ((g_il_ex.open != 0) &&
             (iVar5 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar9), (char)iVar5 == '\0')) {
            *g_il_ex.bytes.cur = 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *(void **)g_il_ex.bytes.cur = pvVar9;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
          }
        }
        else {
          cVar1 = (char)pcVar8->code;
          while (cVar1 < '\0') {
            pcVar8 = pcVar8->base;
            cVar1 = (char)pcVar8->code;
          }
          uVar10 = pcVar8->code;
          if (((uVar10 & 0x10) == 0) && ((uVar10 & 0x100) == 0)) {
            if ((uVar10 & 0x20) == 0) {
              if ((uVar10 & 0x40) != 0) {
                pvVar9 = n_00->left;
                iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
                g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
                if ((g_il_ex.open != 0) &&
                   (iVar5 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar9), (char)iVar5 == '\0')) {
                  il_emit_tuple_long_value_fragment
                            (n_00,(uint)pvVar9,1,pair_key1,pair_key2,pair_flags,shape,op,(int)n);
                  return;
                }
              }
            }
            else {
              src = n_00->left;
              iVar5 = il_buffer_reserve(&g_il_ex.bytes,0xb);
              g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
              if (g_il_ex.open != 0) {
                il_buffer_put_bytes(&g_il_ex,src,10);
              }
              pvVar9 = n_00->left;
              iVar5 = il_buffer_reserve(&g_il_ex.bytes,3);
              g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
              if (g_il_ex.open != 0) {
                il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar9 + 10),2);
              }
            }
          }
          else {
            il_emit_integer_constant
                      ((uint)n_00->left,(int)n_00->right,
                       (int)(char)(&g_type_rank_table)[uVar10 & 0xf]);
          }
        }
        break;
      case '\x11':
        pvVar9 = n_00->left;
        if (g_c9il_mode == '\0') {
          il_emit_key_fragment((uint)pvVar9,n_00,1,pair_key1,pair_key2,pair_flags,shape,op,(int)n);
          return;
        }
        goto LAB_1042747b;
      case '\x14':
        pvVar9 = (void *)(uint)*(ushort *)((int)&n_00->right + 2);
        bVar4 = il_buffer_reserve_ok(&g_il_ex,5);
LAB_10427299:
        if ((bVar4 != 0) &&
           (iVar5 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar9), (char)iVar5 == '\0')) {
          *g_il_ex.bytes.cur = 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          *(void **)g_il_ex.bytes.cur = pvVar9;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
        }
        break;
      case '\x15':
        il_symbol_pair_operand_keys(n_00->left,&pair_key1,&pair_key2,&pair_flags);
        uVar2 = pair_key1;
        if (g_c9il_mode == '\0') {
          cVar3 = il_buffer_reserve_ok(&g_il_ex,3);
          if (cVar3 != '\0') {
            bVar4 = (byte)uVar2;
            if (uVar2 < 0x3fff80) {
              if (uVar2 < 0x4000) {
                *g_il_ex.bytes.cur = bVar4 & 0x3f | 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
              else {
                *g_il_ex.bytes.cur = bVar4 | 0xc0;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 0xe);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              }
            }
            else {
              *g_il_ex.bytes.cur = bVar4 + 0x80;
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            }
          }
        }
        else {
          il_buffer_put_id(&g_il_ex,pair_key1);
        }
        uVar2 = pair_key2;
        if (g_c9il_mode == '\0') {
          cVar3 = il_buffer_reserve_ok(&g_il_ex,3);
          if (cVar3 != '\0') {
            bVar4 = (byte)uVar2;
            uVar10 = (ushort)pair_flags;
            if (uVar2 < 0x3fff80) {
              if (uVar2 < 0x4000) {
                *g_il_ex.bytes.cur = bVar4 & 0x3f | 0x80;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                il_buffer_put_compact_u16(&g_il_ex,uVar10);
              }
              else {
                *g_il_ex.bytes.cur = bVar4 | 0xc0;
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 0xe);
                g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
                il_buffer_put_compact_u16(&g_il_ex,uVar10);
              }
            }
            else {
              *g_il_ex.bytes.cur = bVar4 + 0x80;
              g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
              il_buffer_put_compact_u16(&g_il_ex,uVar10);
            }
            break;
          }
        }
        else {
          il_buffer_put_id(&g_il_ex,pair_key2);
        }
        il_buffer_put_compact_u16(&g_il_ex,(ushort)pair_flags);
        break;
      case '\x16':
        il_buffer_put_compact_value(&g_il_ex,*(ushort *)&n_00->right & 0xfff);
        break;
      case '\x1b':
        if (g_dlp != '\0') {
          il_emit_based_symbol_fragment(n_00,1,pair_key1,pair_key2,pair_flags,shape,op,(int)n);
          return;
        }
      }
      pcVar6 = PTR_104de3b4;
      cVar1 = *shape;
    }
  }
  return;
}

