void __cdecl
il_emit_tuple_long_value_fragment
          (c1_node *n,uint value,int one,uint pair_key1,uint pair_key2,uint pair_flags,char *shape,
          int op,int n_slot)

{
  char cVar1;
  uint *src;
  uint uVar2;
  byte bVar3;
  c1_u8 cVar4;
  int iVar5;
  c1_node *callee_node;
  c1_type *callee_type;
  int iVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  void *pvVar10;
  ushort uVar11;
  
  *g_il_ex.bytes.cur = 0x80;
LAB_10427572:
  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  *(uint *)g_il_ex.bytes.cur = value;
  g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
switchD_10427227_caseD_4:
  iVar5 = op;
  pcVar7 = PTR_104de3b4;
  cVar1 = *shape;
  if (cVar1 == '\0') {
    return;
  }
  shape = shape + 1;
  switch(cVar1) {
  case '\x01':
    bVar3 = *(byte *)n->left;
    iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (bVar3 & 0x1f) == 0xb;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
    goto switchD_10427227_caseD_4;
  case '\x02':
    pvVar10 = n->left;
    iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
    bVar3 = g_il_ex.open & (byte)iVar5 & 1;
    g_il_ex.open = bVar3;
    break;
  case '\x03':
    callee_node = n->left;
    if ((callee_node != (c1_node *)0x0) && (callee_node->op == '7')) {
      callee_node = callee_node->right;
    }
    callee_type = (c1_type *)
                  ((uint)callee_node->type & -(uint)((callee_node->type->code & 0x80) != 0));
    switch((byte)callee_type->flags & 7) {
    case 1:
      n_slot = 0;
      break;
    case 2:
      n_slot = 8;
      break;
    case 3:
      n_slot = 4;
      break;
    case 4:
      n_slot = 0x18;
      break;
    case 5:
      if ((callee_type->code & 0x83) != 0x81) {
        callee_type = (c1_type *)
                      ((uint)callee_type->base & -(uint)((callee_type->base->code & 0x80) != 0));
      }
      n_slot = ((uint)(byte)~(byte)(CONCAT22((short)((uint)op >> 0x10),callee_type->flags) >> 0xf) &
               one) << 4;
      break;
    case 6:
      n_slot = 0x14;
    }
    iVar5 = n_slot;
    g_function_has_body = one;
    iVar6 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar6 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (c1_u8)iVar5;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
  default:
    goto switchD_10427227_caseD_4;
  case '\x06':
    il_emit_type_descriptor(op,n,2);
    goto switchD_10427227_caseD_4;
  case '\a':
  case '\r':
  case '\x0e':
    iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = '\0';
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
    goto switchD_10427227_caseD_4;
  case '\b':
    pvVar10 = (void *)0x0;
    switch(op) {
    case 0x26:
      pcVar7 = n->left;
      iVar5 = il_key_is_global_helper_function(pcVar7->key_ref >> 3);
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
      pcVar7 = n->left;
      if (g_c9il_mode != '\0') {
        pvVar10 = (void *)(pcVar7->entity & 0xffffff);
        goto switchD_104273cc_caseD_27;
      }
      if ((pcVar7->key_ref & 0xfffffff8) == 0) {
        pvVar10 = (void *)il_symbol_key_assign(pcVar7);
        goto switchD_104273cc_caseD_27;
      }
      pvVar10 = (void *)(pcVar7->key_ref >> 3);
      goto LAB_1047d3f3;
    default:
      pcVar7 = n->left;
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
      pcVar7 = n->left;
      sym_set_nesting_depth(pcVar7);
      break;
    case 0x3b:
    case 0x3c:
      sym_mark_referenced(PTR_104de3b4);
      sym_set_nesting_depth(pcVar7);
      break;
    case 0x3d:
      pvVar10 = n->left;
      goto switchD_104273cc_caseD_27;
    }
    if (pcVar7 != (c1_symbol *)0x0) {
      if ((pcVar7->kind & 0x1f) == 8) {
        sym_mark_enclosing_scopes(pcVar7);
      }
      sym_mark_referenced(pcVar7);
      if ((pcVar7->flags4 & 0x40) == 0) {
        bVar3 = pcVar7->kind & 0x1f;
        if ((bVar3 == 7) || (bVar3 == 8)) {
          if ((*(byte *)((int)&pcVar7->tail + 10) & 0x80) != 0) {
            sym_redeclaration_group_add(&g_map_region_queue,pcVar7);
          }
          if ((*(byte *)((int)&pcVar7->tail + 9) & 2) != 0) {
            il_emit_tuple_aliased_function_fragment
                      (n,pcVar7,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
            return;
          }
        }
      }
      else {
        bVar3 = pcVar7->kind & 0x1f;
        if (bVar3 == 3) {
          pcVar7 = sym_static_member_stand_in(pcVar7);
        }
        else if (bVar3 == 10) {
          pcVar7 = sym_inline_instance_of(pcVar7);
        }
        else {
          pcVar7 = (c1_symbol *)0x0;
        }
        sym_mark_referenced(pcVar7);
      }
      if (((((pcVar7->flags23 & 1) != 0) &&
           (pcVar8 = sym_segment_record(pcVar7), (pcVar8->entity & 0xffffff) == 5)) &&
          (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
        g_function_auto_inline = 0;
        g_function_has_body = one;
      }
      pvVar10 = (void *)il_symbol_key(&pcVar7->kind);
    }
switchD_104273cc_caseD_27:
    if (g_c9il_mode == '\0') {
LAB_1047d3f3:
      iVar5 = il_buffer_reserve(&g_il_ex.bytes,4);
      g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
      if (g_il_ex.open != 0) {
        bVar3 = (byte)pvVar10;
        if (pvVar10 < (void *)0x3fff80) {
          if (pvVar10 < (void *)0x4000) {
            *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar10 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
          else {
            *g_il_ex.bytes.cur = bVar3 | 0xc0;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar10 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar10 >> 0xe);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
        }
        else {
          *g_il_ex.bytes.cur = bVar3 + 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
      }
    }
    else {
LAB_1042747b:
      il_buffer_put_id(&g_il_ex,(uint)pvVar10);
    }
    goto switchD_10427227_caseD_4;
  case '\v':
    if ((n->type->code & 0x8f) == 0x8a) {
      pcVar9 = type_int();
      n->type = pcVar9;
    }
    il_emit_type_descriptor(iVar5,n,one);
    pcVar9 = n->type;
    if ((char)pcVar9->code < '\0') goto LAB_10427531;
    cVar1 = (char)pcVar9->code;
    while (cVar1 < '\0') {
      pcVar9 = pcVar9->base;
      cVar1 = (char)pcVar9->code;
    }
    uVar11 = pcVar9->code;
    if (((uVar11 & 0x10) == 0) && ((uVar11 & 0x100) == 0)) {
      if ((uVar11 & 0x20) == 0) {
        if ((uVar11 & 0x40) != 0) {
          pvVar10 = n->left;
          iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
          g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
          if ((g_il_ex.open != 0) &&
             (iVar5 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar10), (char)iVar5 == '\0')) {
            il_emit_tuple_long_value_fragment
                      (n,(uint)pvVar10,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
            return;
          }
        }
      }
      else {
        src = n->left;
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,0xb);
        g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,src,10);
        }
        pvVar10 = n->left;
        iVar5 = il_buffer_reserve(&g_il_ex.bytes,3);
        g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
        if (g_il_ex.open != 0) {
          il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar10 + 10),2);
        }
      }
    }
    else {
      il_emit_integer_constant
                ((uint)n->left,(int)n->right,(int)(char)(&g_type_rank_table)[uVar11 & 0xf]);
    }
    goto switchD_10427227_caseD_4;
  case '\x11':
    pvVar10 = n->left;
    if (g_c9il_mode == '\0') {
      il_emit_key_fragment((uint)pvVar10,n,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
      return;
    }
    goto LAB_1042747b;
  case '\x14':
    pvVar10 = (void *)(uint)*(ushort *)((int)&n->right + 2);
    bVar3 = il_buffer_reserve_ok(&g_il_ex,5);
    break;
  case '\x15':
    il_symbol_pair_operand_keys(n->left,&pair_key1,&pair_key2,&pair_flags);
    uVar2 = pair_key1;
    if (g_c9il_mode == '\0') {
      cVar4 = il_buffer_reserve_ok(&g_il_ex,3);
      if (cVar4 != '\0') {
        bVar3 = (byte)uVar2;
        if (uVar2 < 0x3fff80) {
          if (uVar2 < 0x4000) {
            *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
          else {
            *g_il_ex.bytes.cur = bVar3 | 0xc0;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 0xe);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
        }
        else {
          *g_il_ex.bytes.cur = bVar3 + 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
      }
    }
    else {
      il_buffer_put_id(&g_il_ex,pair_key1);
    }
    uVar2 = pair_key2;
    if (g_c9il_mode == '\0') {
      cVar4 = il_buffer_reserve_ok(&g_il_ex,3);
      if (cVar4 != '\0') {
        bVar3 = (byte)uVar2;
        uVar11 = (ushort)pair_flags;
        if (uVar2 < 0x3fff80) {
          if (uVar2 < 0x4000) {
            *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            il_buffer_put_compact_u16(&g_il_ex,uVar11);
          }
          else {
            *g_il_ex.bytes.cur = bVar3 | 0xc0;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 0xe);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            il_buffer_put_compact_u16(&g_il_ex,uVar11);
          }
        }
        else {
          *g_il_ex.bytes.cur = bVar3 + 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          il_buffer_put_compact_u16(&g_il_ex,uVar11);
        }
        goto switchD_10427227_caseD_4;
      }
    }
    else {
      il_buffer_put_id(&g_il_ex,pair_key2);
    }
    il_buffer_put_compact_u16(&g_il_ex,(ushort)pair_flags);
    goto switchD_10427227_caseD_4;
  case '\x16':
    il_buffer_put_compact_value(&g_il_ex,*(ushort *)&n->right & 0xfff);
    goto switchD_10427227_caseD_4;
  case '\x1b':
    if (g_dlp != '\0') {
      il_emit_based_symbol_fragment(n,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
      return;
    }
    goto switchD_10427227_caseD_4;
  }
  if ((bVar3 != 0) && (iVar5 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar10), (char)iVar5 == '\0')) {
    *g_il_ex.bytes.cur = 0x80;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    *(void **)g_il_ex.bytes.cur = pvVar10;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
  }
  goto switchD_10427227_caseD_4;
LAB_10427531:
  value = (uint)n->left;
  iVar5 = il_buffer_reserve(&g_il_ex.bytes,6);
  g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
  if ((g_il_ex.open == 0) || (iVar5 = il_buffer_put_byte7(&g_il_ex,value), (char)iVar5 != '\0'))
  goto switchD_10427227_caseD_4;
  *g_il_ex.bytes.cur = 0x80;
  goto LAB_10427572;
}

