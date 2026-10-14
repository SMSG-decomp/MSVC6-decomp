c1_keyed_list * __cdecl class_member_lookup_record(c1_keyed_list *path,c1_member_lookup_ctx *ctx)

{
  c1_symbol *sym;
  c1_type *pcVar1;
  c1_vbase_vector *pcVar2;
  fe_name *pfVar3;
  c1_member_lookup_ctx *pcVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  c1_symtab *pcVar8;
  c1_symbol *pcVar9;
  c1_keyed_list *pcVar10;
  c1_member_lookup_ctx *pcVar11;
  void *pvVar12;
  c1_sym_link *first;
  int *piVar13;
  c1_vbase_vector *pcVar14;
  char local_34 [4];
  int *local_30;
  int *local_2c;
  int *local_28;
  fe_name **local_24;
  int rec_kind;
  c1_vbase_vector *local_1c;
  short local_18;
  int *local_14;
  char local_8;
  fe_name *local_4;
  
  pcVar4 = ctx;
  pcVar9 = path->head->sym;
  if ((pcVar9->flags2 & 0x10) != 0) {
    pcVar1 = pcVar9->type;
    cVar6 = (char)pcVar1->code;
    while (cVar6 < '\0') {
      pcVar1 = pcVar1->base;
      cVar6 = (char)pcVar1->code;
    }
    if ((pcVar1->code & 0x100) != 0) {
      pcVar9 = symtab_lookup((pcVar9->x28).enumerators,ctx->name);
      if (pcVar9 == (c1_symbol *)0x0) {
        return (c1_keyed_list *)0x0;
      }
      pcVar10 = tree_new_list_cell((c1_keyed_list *)0x0,(int)path->head,pcVar9);
      return pcVar10;
    }
  }
  bVar5 = pcVar9->kind & 0x1f;
  if ((bVar5 != 4) && (bVar5 != 0x19)) {
    if ((pcVar9->key_ref & 0x20000) != 0) {
      return (c1_keyed_list *)0x0;
    }
    pcVar9 = g_scope_vector->entries[(short)pcVar9->key_ref];
  }
  if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
    mre_note_member_use(g_minimal_rebuild_tracker,pcVar9,ctx->name);
  }
  if (((pcVar9->detail).cls)->sorted_members == (void **)0x0) {
    pfVar3 = ctx->name;
    class_member_iter_init((c1_member_iter *)&local_1c,&pcVar9->name,0);
    local_4 = pfVar3;
    cVar6 = class_member_iter_next((c1_member_iter *)&local_1c);
    while (cVar6 != '\0') {
      if ((fe_name *)*local_14 == local_4) goto LAB_10413d62;
      cVar6 = class_member_iter_next((c1_member_iter *)&local_1c);
    }
  }
  else {
    local_14 = (int *)class_member_table_find(&((pcVar9->detail).cls)->member_count,(uint)ctx->name)
    ;
LAB_10413d62:
    if (local_14 != (int *)0x0) {
      sym = (c1_symbol *)(local_14 + -2);
      uVar7 = sym_kind_in_lookup_mask((c1_u8 *)local_14,ctx->flags);
      if (((char)uVar7 != '\0') &&
         (cVar6 = class_lookup_is_new_result((byte *)sym,ctx->found), cVar6 != '\0')) {
        vector_push(ctx->found,sym);
        pcVar2 = ((pcVar9->detail).cls)->vbases;
        local_8 = pcVar2 != (c1_vbase_vector *)0x0;
        pcVar14 = local_1c;
        if ((bool)local_8) {
          pcVar14 = pcVar2;
          local_18 = 0;
        }
        while (((local_8 != '\0' && (pcVar14 != (c1_vbase_vector *)0x0)) &&
               ((int)local_18 < (int)(uint)pcVar14->count))) {
          pcVar9 = pcVar14->data[local_18]->base;
          if (ctx->visited == (c1_symtab *)0x0) {
            pcVar8 = symtab_new(4,5,0,0,'\x01','\x01');
            ctx->visited = pcVar8;
            pcVar8 = symtab_new(4,5,0,0,'\x01','\x01');
            ctx->hidden = pcVar8;
          }
          symtab_insert(ctx->visited,pcVar9,(void *)0x1);
          symtab_insert(ctx->hidden,pcVar9,(void *)0x1);
          local_18 = local_18 + 1;
        }
        pcVar9 = expr_resolve_overload_set_member(sym,(c1_symbol *)0x0);
        pcVar10 = tree_new_list_cell((c1_keyed_list *)0x0,(int)path->head,pcVar9);
        return pcVar10;
      }
    }
  }
  if (ctx->name == g_name_operator_assign) {
    return (c1_keyed_list *)0x0;
  }
  if (((pcVar9->flags2 & 4) == 0) && (((byte)g_compile_flags_c4 & 2) != 0)) {
    return (c1_keyed_list *)0x0;
  }
  ctx = (c1_member_lookup_ctx *)0x0;
  if ((pcVar9->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((pcVar9->x28).members)->head;
  }
  list_cursor_init(local_34,first);
  rec_kind = 4;
  local_28 = (int *)0x0;
  piVar13 = local_30;
  local_24 = &pcVar9->name;
  if (local_34[0] != '\0') {
    local_28 = local_30;
  }
LAB_10413f35:
  do {
    while( true ) {
      local_2c = local_28;
      if (local_2c == (int *)0x0) {
        return (c1_keyed_list *)ctx;
      }
      if ((piVar13 == (int *)0x0) ||
         (local_28 = (int *)piVar13[1], piVar13 = local_28, local_30 = local_28,
         local_28 == (int *)0x0)) {
        local_28 = (int *)0x0;
      }
      if ((*(byte *)(local_2c + -2) & 0x1f) != 3) break;
      if (((void *)*local_2c != g_name_vbptr) && ((void *)*local_2c != g_name_vfptr)) {
        return (c1_keyed_list *)ctx;
      }
    }
  } while ((((g_compile_flags_cc._2_1_ & 0x10) != 0) && ((*(byte *)(local_2c + -2) & 0x1f) == 0xf))
          && ((*(byte *)((int)local_2c + 0x12) & 2) != 0));
  if ((*(byte *)(local_2c + -2) & 0x1f) != 0xf) {
    return (c1_keyed_list *)ctx;
  }
  if ((*(byte *)((int)local_2c + 0x12) & 1) != 0) {
    if ((pcVar4->flags & 4) != 0) goto LAB_10413f35;
    if (pcVar4->visited == (c1_symtab *)0x0) {
      pcVar8 = symtab_new(4,5,0,0,'\x01','\x01');
      pcVar4->visited = pcVar8;
      pcVar8 = symtab_new(4,5,0,0,'\x01','\x01');
      pcVar4->hidden = pcVar8;
    }
    if ((*(byte *)((int)local_2c + 0x12) & 2) == 0) {
      pcVar9 = g_scope_vector->entries[(short)local_2c[4]];
    }
    else {
      pcVar9 = (c1_symbol *)0x0;
    }
    pvVar12 = symtab_lookup(pcVar4->visited,pcVar9);
    local_28 = local_28;
    piVar13 = local_30;
    if (pvVar12 == (void *)0x1) goto LAB_10413f35;
    if ((*(byte *)((int)local_2c + 0x12) & 2) == 0) {
      pcVar9 = g_scope_vector->entries[(short)local_2c[4]];
    }
    else {
      pcVar9 = (c1_symbol *)0x0;
    }
    symtab_insert(pcVar4->visited,pcVar9,(void *)0x1);
  }
  pcVar11 = pcVar4;
  pcVar10 = tree_new_list_cell((c1_keyed_list *)0x0,(int)path->head,(c1_symbol *)(local_2c + -2));
  pcVar11 = (c1_member_lookup_ctx *)class_member_lookup_record(pcVar10,pcVar11);
  local_28 = local_28;
  piVar13 = local_30;
  if (pcVar11 != (c1_member_lookup_ctx *)0x0) {
    if (ctx != (c1_member_lookup_ctx *)0x0) {
      *(fe_name **)(ctx->flags + 4) = pcVar11->name;
      ctx->flags = (c1_u32)pcVar11->flags;
      pcVar11 = ctx;
    }
    ctx = pcVar11;
    local_28 = local_28;
    if ((pcVar4->flags & 8) != 0) {
      return (c1_keyed_list *)ctx;
    }
  }
  goto LAB_10413f35;
}

