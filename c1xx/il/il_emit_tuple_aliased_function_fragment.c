void __cdecl
il_emit_tuple_aliased_function_fragment
          (c1_node *n,c1_symbol *sym,int one,uint pair_key1,uint pair_key2,uint pair_flags,
          char *shape,int op,int n_slot)

{
  char cVar1;
  uint *src;
  uint uVar2;
  byte bVar3;
  c1_u8 cVar4;
  c1_node *callee_node;
  c1_type *callee_type;
  int iVar5;
  void *pvVar6;
  int iVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  ushort uVar10;
  
  pcVar8 = class_scalar_deleting_dtor_of(sym);
LAB_104274b5:
  sym_mark_referenced(pcVar8);
LAB_10427459:
  if (((((sym->flags23 & 1) != 0) &&
       (pcVar8 = sym_segment_record(sym), (pcVar8->entity & 0xffffff) == 5)) &&
      (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
    g_function_auto_inline = 0;
    g_function_has_body = one;
  }
  pvVar6 = (void *)il_symbol_key(&sym->kind);
switchD_104273cc_caseD_27:
  if (g_c9il_mode == '\0') goto LAB_1047d3f3;
LAB_1042747b:
  il_buffer_put_id(&g_il_ex,(uint)pvVar6);
switchD_10427227_caseD_4:
  iVar7 = op;
  sym = PTR_104de3b4;
  cVar1 = *shape;
  if (cVar1 == '\0') {
    return;
  }
  shape = shape + 1;
  switch(cVar1) {
  case '\x01':
    bVar3 = *(byte *)n->left;
    iVar7 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (bVar3 & 0x1f) == 0xb;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
    goto switchD_10427227_caseD_4;
  case '\x02':
    pvVar6 = n->left;
    iVar7 = il_buffer_reserve(&g_il_ex.bytes,6);
    bVar3 = g_il_ex.open & (byte)iVar7 & 1;
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
    iVar7 = n_slot;
    g_function_has_body = one;
    iVar5 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar5 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = (c1_u8)iVar7;
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
    iVar7 = il_buffer_reserve(&g_il_ex.bytes,2);
    g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.cur = '\0';
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    }
    goto switchD_10427227_caseD_4;
  case '\b':
    pvVar6 = (void *)0x0;
    switch(op) {
    case 0x26:
      sym = n->left;
      iVar7 = il_key_is_global_helper_function(sym->key_ref >> 3);
      if ((char)iVar7 != '\0') {
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
      pcVar8 = n->left;
      if (g_c9il_mode != '\0') {
        pvVar6 = (void *)(pcVar8->entity & 0xffffff);
        goto switchD_104273cc_caseD_27;
      }
      if ((pcVar8->key_ref & 0xfffffff8) == 0) {
        pvVar6 = (void *)il_symbol_key_assign(pcVar8);
        goto switchD_104273cc_caseD_27;
      }
      pvVar6 = (void *)(pcVar8->key_ref >> 3);
LAB_1047d3f3:
      iVar7 = il_buffer_reserve(&g_il_ex.bytes,4);
      g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
      if (g_il_ex.open != 0) {
        bVar3 = (byte)pvVar6;
        if (pvVar6 < (void *)0x3fff80) {
          if (pvVar6 < (void *)0x4000) {
            *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar6 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
          else {
            *g_il_ex.bytes.cur = bVar3 | 0xc0;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar6 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)((uint)pvVar6 >> 0xe);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
        }
        else {
          *g_il_ex.bytes.cur = bVar3 + 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
      }
      goto switchD_10427227_caseD_4;
    default:
      sym = n->left;
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
      sym = n->left;
      sym_set_nesting_depth(sym);
      break;
    case 0x3b:
    case 0x3c:
      sym_mark_referenced(PTR_104de3b4);
      sym_set_nesting_depth(sym);
      break;
    case 0x3d:
      pvVar6 = n->left;
      goto switchD_104273cc_caseD_27;
    }
    if (sym == (c1_symbol *)0x0) goto switchD_104273cc_caseD_27;
    if ((sym->kind & 0x1f) == 8) {
      sym_mark_enclosing_scopes(sym);
    }
    sym_mark_referenced(sym);
    if ((sym->flags4 & 0x40) != 0) {
      bVar3 = sym->kind & 0x1f;
      if (bVar3 == 3) {
        pcVar8 = sym_static_member_stand_in(sym);
        sym = pcVar8;
      }
      else if (bVar3 == 10) {
        pcVar8 = sym_inline_instance_of(sym);
        sym = pcVar8;
      }
      else {
        pcVar8 = (c1_symbol *)0x0;
        sym = (c1_symbol *)0x0;
      }
      goto LAB_104274b5;
    }
    bVar3 = sym->kind & 0x1f;
    if ((bVar3 == 7) || (bVar3 == 8)) {
      if ((*(byte *)((int)&sym->tail + 10) & 0x80) != 0) {
        sym_redeclaration_group_add(&g_map_region_queue,sym);
      }
      if ((*(byte *)((int)&sym->tail + 9) & 2) != 0) {
        il_emit_tuple_aliased_function_fragment
                  (n,sym,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
        return;
      }
    }
    goto LAB_10427459;
  case '\v':
    if ((n->type->code & 0x8f) == 0x8a) {
      pcVar9 = type_int();
      n->type = pcVar9;
    }
    il_emit_type_descriptor(iVar7,n,one);
    pcVar9 = n->type;
    if ((char)pcVar9->code < '\0') {
      pvVar6 = n->left;
      iVar7 = il_buffer_reserve(&g_il_ex.bytes,6);
      g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
      if ((g_il_ex.open != 0) &&
         (iVar7 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar6), (char)iVar7 == '\0')) {
        *g_il_ex.bytes.cur = 0x80;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        *(void **)g_il_ex.bytes.cur = pvVar6;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
      }
    }
    else {
      cVar1 = (char)pcVar9->code;
      while (cVar1 < '\0') {
        pcVar9 = pcVar9->base;
        cVar1 = (char)pcVar9->code;
      }
      uVar10 = pcVar9->code;
      if (((uVar10 & 0x10) == 0) && ((uVar10 & 0x100) == 0)) {
        if ((uVar10 & 0x20) == 0) {
          if ((uVar10 & 0x40) != 0) {
            pvVar6 = n->left;
            iVar7 = il_buffer_reserve(&g_il_ex.bytes,6);
            g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
            if ((g_il_ex.open != 0) &&
               (iVar7 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar6), (char)iVar7 == '\0')) {
              il_emit_tuple_long_value_fragment
                        (n,(uint)pvVar6,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
              return;
            }
          }
        }
        else {
          src = n->left;
          iVar7 = il_buffer_reserve(&g_il_ex.bytes,0xb);
          g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
          if (g_il_ex.open != 0) {
            il_buffer_put_bytes(&g_il_ex,src,10);
          }
          pvVar6 = n->left;
          iVar7 = il_buffer_reserve(&g_il_ex.bytes,3);
          g_il_ex.open = g_il_ex.open & (byte)iVar7 & 1;
          if (g_il_ex.open != 0) {
            il_buffer_put_bytes(&g_il_ex,(uint *)((int)pvVar6 + 10),2);
          }
        }
      }
      else {
        il_emit_integer_constant
                  ((uint)n->left,(int)n->right,(int)(char)(&g_type_rank_table)[uVar10 & 0xf]);
      }
    }
    goto switchD_10427227_caseD_4;
  case '\x11':
    goto switchD_10427227_caseD_11;
  case '\x14':
    pvVar6 = (void *)(uint)*(ushort *)((int)&n->right + 2);
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
        uVar10 = (ushort)pair_flags;
        if (uVar2 < 0x3fff80) {
          if (uVar2 < 0x4000) {
            *g_il_ex.bytes.cur = bVar3 & 0x3f | 0x80;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            il_buffer_put_compact_u16(&g_il_ex,uVar10);
          }
          else {
            *g_il_ex.bytes.cur = bVar3 | 0xc0;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 6);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            *g_il_ex.bytes.cur = (c1_u8)(uVar2 >> 0xe);
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
            il_buffer_put_compact_u16(&g_il_ex,uVar10);
          }
        }
        else {
          *g_il_ex.bytes.cur = bVar3 + 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          il_buffer_put_compact_u16(&g_il_ex,uVar10);
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
  if ((bVar3 != 0) && (iVar7 = il_buffer_put_byte7(&g_il_ex,(uint)pvVar6), (char)iVar7 == '\0')) {
    *g_il_ex.bytes.cur = 0x80;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    *(void **)g_il_ex.bytes.cur = pvVar6;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 4;
  }
  goto switchD_10427227_caseD_4;
switchD_10427227_caseD_11:
  pvVar6 = n->left;
  if (g_c9il_mode == '\0') {
    il_emit_key_fragment((uint)pvVar6,n,one,pair_key1,pair_key2,pair_flags,shape,op,n_slot);
    return;
  }
  goto LAB_1042747b;
}

